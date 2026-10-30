/* Function: putchar @ 00009a40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putchar(int __c)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_putchar_00035f2c)(__c);
  return iVar1;
}



/* Function: strcpy @ 00009a4c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcpy_00035f30)(__dest);
  return pcVar1;
}



/* Function: log @ 00009a58 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double log(double __x)

{
  undefined4 uVar1;
  undefined4 extraout_s1;
  
  uVar1 = (*(code *)PTR_log_00035f34)(SUB84(__x,0));
  return (double)CONCAT44(extraout_s1,uVar1);
}



/* Function: printf @ 00009a64 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00035f38)(__format);
  return iVar1;
}



/* Function: strerror @ 00009a70 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strerror_00035f3c)(__errnum);
  return pcVar1;
}



/* Function: inet_pton @ 00009a7c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int inet_pton(int __af,char *__cp,void *__buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_inet_pton_00035f40)(__af);
  return iVar1;
}



/* Function: getopt_long @ 00009a88 */

void getopt_long(void)

{
  (*(code *)PTR_getopt_long_00035f44)();
  return;
}



/* Function: snprintf @ 00009a94 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_00035f48)(__s);
  return iVar1;
}



/* Function: __errno @ 00009aa0 */

void __errno(void)

{
  (*(code *)PTR___errno_00035f4c)();
  return;
}



/* Function: getgrgid @ 00009aac */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

group * getgrgid(__gid_t __gid)

{
  group *pgVar1;
  
  pgVar1 = (group *)(*(code *)PTR_getgrgid_00035f50)(__gid);
  return pgVar1;
}



/* Function: getprotobynumber @ 00009ab8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

protoent * getprotobynumber(int __proto)

{
  protoent *ppVar1;
  
  ppVar1 = (protoent *)(*(code *)PTR_getprotobynumber_00035f54)(__proto);
  return ppVar1;
}



/* Function: getenv @ 00009ac4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_getenv_00035f58)(__name);
  return pcVar1;
}



/* Function: getprotobyname @ 00009ad0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

protoent * getprotobyname(char *__name)

{
  protoent *ppVar1;
  
  ppVar1 = (protoent *)(*(code *)PTR_getprotobyname_00035f5c)(__name);
  return ppVar1;
}



/* Function: fgets @ 00009adc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_00035f60)(__s);
  return pcVar1;
}



/* Function: memcpy @ 00009ae8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00035f64)(__dest);
  return pvVar1;
}



/* Function: perror @ 00009af4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void perror(char *__s)

{
  (*(code *)PTR_perror_00035f68)(__s);
  return;
}



/* Function: __aeabi_uldivmod @ 00009b00 */

void __aeabi_uldivmod(void)

{
  (*(code *)PTR___aeabi_uldivmod_00035f6c)();
  return;
}



/* Function: puts @ 00009b0c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_puts_00035f70)(__s);
  return iVar1;
}



/* Function: malloc @ 00009b18 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_00035f74)(__size);
  return pvVar1;
}



/* Function: strtoul @ 00009b24 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  
  uVar1 = (*(code *)PTR_strtoul_00035f78)(__nptr);
  return uVar1;
}



/* Function: __aeabi_ui2d @ 00009b30 */

void __aeabi_ui2d(void)

{
  (*(code *)PTR___aeabi_ui2d_00035f7c)();
  return;
}



/* Function: gethostbyaddr @ 00009b3c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * gethostbyaddr(void *__addr,__socklen_t __len,int __type)

{
  hostent *phVar1;
  
  phVar1 = (hostent *)(*(code *)PTR_gethostbyaddr_00035f80)(__addr);
  return phVar1;
}



/* Function: socket @ 00009b48 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_00035f84)(__domain);
  return iVar1;
}



/* Function: __aeabi_dcmplt @ 00009b54 */

void __aeabi_dcmplt(void)

{
  (*(code *)PTR___aeabi_dcmplt_00035f88)();
  return;
}



/* Function: fflush @ 00009b60 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fflush_00035f8c)(__stream);
  return iVar1;
}



/* Function: __aeabi_ddiv @ 00009b6c */

void __aeabi_ddiv(void)

{
  (*(code *)PTR___aeabi_ddiv_00035f90)();
  return;
}



/* Function: __aeabi_dmul @ 00009b78 */

void __aeabi_dmul(void)

{
  (*(code *)PTR___aeabi_dmul_00035f94)();
  return;
}



/* Function: strncasecmp @ 00009b84 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncasecmp_00035f98)(__s1);
  return iVar1;
}



/* Function: freeaddrinfo @ 00009b90 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void freeaddrinfo(addrinfo *__ai)

{
  (*(code *)PTR_freeaddrinfo_00035f9c)(__ai);
  return;
}



/* Function: abort @ 00009b9c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_00035fa0)();
  return;
}



/* Function: __stack_chk_fail @ 00009ba8 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00035fa4)();
  return;
}



/* Function: getnameinfo @ 00009bb4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getnameinfo(sockaddr *__sa,socklen_t __salen,char *__host,socklen_t __hostlen,char *__serv,
               socklen_t __servlen,uint __flags)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getnameinfo_00035fa8)(__sa);
  return iVar1;
}



/* Function: strtol @ 00009bc0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_strtol_00035fac)(__nptr);
  return lVar1;
}



/* Function: strnlen @ 00009bcc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strnlen_00035fb0)(__string);
  return sVar1;
}



/* Function: getnetbyaddr @ 00009bd8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

netent * getnetbyaddr(uint32_t __net,int __type)

{
  netent *pnVar1;
  
  pnVar1 = (netent *)(*(code *)PTR_getnetbyaddr_00035fb4)(__net);
  return pnVar1;
}



/* Function: uname @ 00009be4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int uname(utsname *__name)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_uname_00035fb8)(__name);
  return iVar1;
}



/* Function: strrchr @ 00009bfc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strrchr(char *__s,int __c)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strrchr_00035fc0)(__s);
  return pcVar1;
}



/* Function: calloc @ 00009c08 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_calloc_00035fc4)(__nmemb);
  return pvVar1;
}



/* Function: strtod @ 00009c14 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double strtod(char *__nptr,char **__endptr)

{
  undefined4 uVar1;
  undefined4 extraout_s1;
  
  uVar1 = (*(code *)PTR_strtod_00035fc8)(__nptr);
  return (double)CONCAT44(extraout_s1,uVar1);
}



/* Function: fprintf @ 00009c20 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fprintf_00035fcc)(__stream);
  return iVar1;
}



/* Function: __aeabi_dadd @ 00009c2c */

void __aeabi_dadd(void)

{
  (*(code *)PTR___aeabi_dadd_00035fd0)();
  return;
}



/* Function: strcat @ 00009c38 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcat(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcat_00035fd4)(__dest);
  return pcVar1;
}



/* Function: setsockopt @ 00009c44 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t __optlen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_setsockopt_00035fd8)(__fd);
  return iVar1;
}



/* Function: __aeabi_dcmpgt @ 00009c50 */

void __aeabi_dcmpgt(void)

{
  (*(code *)PTR___aeabi_dcmpgt_00035fdc)();
  return;
}



/* Function: wait @ 00009c5c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t wait(void *__stat_loc)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_wait_00035fe0)(__stat_loc);
  return _Var1;
}



/* Function: __aeabi_dcmpge @ 00009c68 */

void __aeabi_dcmpge(void)

{
  (*(code *)PTR___aeabi_dcmpge_00035fe4)();
  return;
}



/* Function: mktime @ 00009c74 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t mktime(tm *__tp)

{
  time_t tVar1;
  
  tVar1 = (*(code *)PTR_mktime_00035fe8)(__tp);
  return tVar1;
}



/* Function: read @ 00009c80 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_00035fec)(__fd);
  return sVar1;
}



/* Function: strncmp @ 00009c8c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncmp_00035ff0)(__s1);
  return iVar1;
}



/* Function: strncpy @ 00009c98 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strncpy_00035ff4)(__dest);
  return pcVar1;
}



/* Function: strcasecmp @ 00009ca4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcasecmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcasecmp_00035ff8)(__s1);
  return iVar1;
}



/* Function: realloc @ 00009cb0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_realloc_00035ffc)(__ptr);
  return pvVar1;
}



/* Function: __aeabi_i2d @ 00009cbc */

void __aeabi_i2d(void)

{
  (*(code *)PTR___aeabi_i2d_00036000)();
  return;
}



/* Function: strtok @ 00009cc8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strtok_00036004)(__s);
  return pcVar1;
}



/* Function: memcmp @ 00009cd4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_00036008)(__s1);
  return iVar1;
}



/* Function: sscanf @ 00009ce0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sscanf_0003600c)(__s);
  return iVar1;
}



/* Function: execv @ 00009cec */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int execv(char *__path,char **__argv)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_execv_00036010)(__path);
  return iVar1;
}



/* Function: strdup @ 00009cf8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strdup(char *__s)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strdup_00036014)(__s);
  return pcVar1;
}



/* Function: strtoull @ 00009d04 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulonglong strtoull(char *__nptr,char **__endptr,int __base)

{
  ulonglong uVar1;
  
  uVar1 = (*(code *)PTR_strtoull_00036018)(__nptr);
  return uVar1;
}



/* Function: fopen @ 00009d10 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_0003601c)(__filename);
  return pFVar1;
}



/* Function: localtime @ 00009d1c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime(time_t *__timer)

{
  tm *ptVar1;
  
  ptVar1 = (tm *)(*(code *)PTR_localtime_00036020)(__timer);
  return ptVar1;
}



/* Function: memset @ 00009d28 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_00036024)(__s);
  return pvVar1;
}



/* Function: __swbuf @ 00009d34 */

void __swbuf(void)

{
  (*(code *)PTR___swbuf_00036028)();
  return;
}



/* Function: __aeabi_uidiv @ 00009d40 */

void __aeabi_uidiv(void)

{
  (*(code *)PTR___aeabi_uidiv_0003602c)();
  return;
}



/* Function: fclose @ 00009d4c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_00036030)(__stream);
  return iVar1;
}



/* Function: getservbyport @ 00009d58 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

servent * getservbyport(int __port,char *__proto)

{
  servent *psVar1;
  
  psVar1 = (servent *)(*(code *)PTR_getservbyport_00036034)(__port);
  return psVar1;
}



/* Function: putc @ 00009d64 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putc(int __c,FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_putc_00036038)(__c);
  return iVar1;
}



/* Function: strcmp @ 00009d70 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_0003603c)(__s1);
  return iVar1;
}



/* Function: getpwuid @ 00009d7c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

passwd * getpwuid(__uid_t __uid)

{
  passwd *ppVar1;
  
  ppVar1 = (passwd *)(*(code *)PTR_getpwuid_00036040)(__uid);
  return ppVar1;
}



/* Function: gethostbyname @ 00009d88 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * gethostbyname(char *__name)

{
  hostent *phVar1;
  
  phVar1 = (hostent *)(*(code *)PTR_gethostbyname_00036044)(__name);
  return phVar1;
}



/* Function: getpwnam @ 00009d94 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

passwd * getpwnam(char *__name)

{
  passwd *ppVar1;
  
  ppVar1 = (passwd *)(*(code *)PTR_getpwnam_00036048)(__name);
  return ppVar1;
}



/* Function: getservbyname @ 00009da0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

servent * getservbyname(char *__name,char *__proto)

{
  servent *psVar1;
  
  psVar1 = (servent *)(*(code *)PTR_getservbyname_0003604c)(__name);
  return psVar1;
}



/* Function: sprintf @ 00009dac */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sprintf_00036050)(__s);
  return iVar1;
}



/* Function: strcspn @ 00009db8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strcspn(char *__s,char *__reject)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strcspn_00036054)(__s);
  return sVar1;
}



/* Function: vfork @ 00009dc4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t vfork(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_vfork_00036058)();
  return _Var1;
}



/* Function: fputc @ 00009dd0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fputc(int __c,FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fputc_0003605c)(__c);
  return iVar1;
}



/* Function: __aeabi_d2uiz @ 00009ddc */

void __aeabi_d2uiz(void)

{
  (*(code *)PTR___aeabi_d2uiz_00036060)();
  return;
}



/* Function: getsockopt @ 00009de8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t *__optlen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getsockopt_00036064)(__fd);
  return iVar1;
}



/* Function: getaddrinfo @ 00009df4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getaddrinfo(char *__name,char *__service,addrinfo *__req,addrinfo **__pai)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getaddrinfo_00036068)(__name);
  return iVar1;
}



/* Function: __aeabi_uidivmod @ 00009e00 */

void __aeabi_uidivmod(void)

{
  (*(code *)PTR___aeabi_uidivmod_0003606c)();
  return;
}



/* Function: fwrite @ 00009e0c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fwrite_00036070)(__ptr);
  return sVar1;
}



/* Function: getnetbyname @ 00009e18 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

netent * getnetbyname(char *__name)

{
  netent *pnVar1;
  
  pnVar1 = (netent *)(*(code *)PTR_getnetbyname_00036074)(__name);
  return pnVar1;
}



/* Function: exit @ 00009e24 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
  (*(code *)PTR_exit_00036078)(__status);
  return;
}



/* Function: inet_ntop @ 00009e30 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * inet_ntop(int __af,void *__cp,char *__buf,socklen_t __len)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_inet_ntop_0003607c)(__af);
  return pcVar1;
}



/* Function: getgrnam @ 00009e3c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

group * getgrnam(char *__name)

{
  group *pgVar1;
  
  pgVar1 = (group *)(*(code *)PTR_getgrnam_00036080)(__name);
  return pgVar1;
}



/* Function: atoi @ 00009e48 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_atoi_00036084)(__nptr);
  return iVar1;
}



/* Function: strlen @ 00009e54 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00036088)(__s);
  return sVar1;
}



/* Function: open @ 00009e60 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open_0003608c)(__file);
  return iVar1;
}



/* Function: strchr @ 00009e6c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strchr_00036090)(__s);
  return pcVar1;
}



/* Function: fputs @ 00009e78 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fputs(char *__s,FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fputs_00036094)(__s);
  return iVar1;
}



/* Function: close @ 00009e84 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_00036098)(__fd);
  return iVar1;
}



/* Function: vfprintf @ 00009e90 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vfprintf(FILE *__s,char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_vfprintf_0003609c)(__s);
  return iVar1;
}



/* Function: strpbrk @ 00009e9c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strpbrk_000360a0)(__s);
  return pcVar1;
}



/* Function: free @ 00009ea8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_000360a4)(__ptr);
  return;
}



/* Function: entry @ 00009ec0 */

void processEntry entry(void)

{
  (*(code *)PTR___libc_init_00035fbc)();
  return;
}



/* Function: FUN_0000a018 @ 0000a018 */

void FUN_0000a018(uint param_1,int param_2,int param_3)

{
  longlong lVar1;
  char *pcVar2;
  ulonglong uVar3;
  
  uVar3 = CONCAT44(param_2,param_1);
  if (param_3 << 0x1d < 0) {
    if ((param_2 == 0) && (param_1 <= DAT_0000a118)) {
      if (param_3 << 0x1b < 0) {
        pcVar2 = (char *)(DAT_0000a138 + 0xa0d0);
      }
      else {
        pcVar2 = (char *)(DAT_0000a11c + 0xa038);
      }
      printf(pcVar2,param_3 << 0x1d,param_1,0);
      return;
    }
    uVar3 = __aeabi_uldivmod(DAT_0000a110 + param_1,
                             DAT_0000a114 + param_2 + (uint)CARRY4(DAT_0000a110,param_1),
                             DAT_0000a108,DAT_0000a10c);
    if (((int)(uVar3 >> 0x20) == 0) && ((uint)uVar3 <= DAT_0000a128)) {
      if (param_3 << 0x1b < 0) {
        pcVar2 = (char *)(DAT_0000a144 + 0xa0fa);
        uVar3 = uVar3 & 0xffffffff;
      }
      else {
        pcVar2 = (char *)(DAT_0000a130 + 0xa0c0);
        uVar3 = uVar3 & 0xffffffff;
      }
    }
    else {
      lVar1 = uVar3 + CONCAT44(DAT_0000a114,DAT_0000a110);
      uVar3 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),DAT_0000a108,DAT_0000a10c)
      ;
      if (((int)(uVar3 >> 0x20) == 0) && ((uint)uVar3 <= DAT_0000a128)) {
        if (param_3 << 0x1b < 0) {
          pcVar2 = (char *)(DAT_0000a140 + 0xa0f4);
          uVar3 = uVar3 & 0xffffffff;
        }
        else {
          pcVar2 = (char *)(DAT_0000a134 + 0xa0ca);
          uVar3 = uVar3 & 0xffffffff;
        }
      }
      else {
        lVar1 = uVar3 + CONCAT44(DAT_0000a114,DAT_0000a110);
        uVar3 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),DAT_0000a108,
                                 DAT_0000a10c);
        if (((int)(uVar3 >> 0x20) == 0) && ((uint)uVar3 <= DAT_0000a128)) {
          if (param_3 << 0x1b < 0) {
            pcVar2 = &UNK_0000a106 + DAT_0000a14c;
            uVar3 = uVar3 & 0xffffffff;
          }
          else {
            pcVar2 = (char *)(DAT_0000a12c + 0xa0b0);
            uVar3 = uVar3 & 0xffffffff;
          }
        }
        else {
          lVar1 = uVar3 + CONCAT44(DAT_0000a114,DAT_0000a110);
          uVar3 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),DAT_0000a108,
                                   DAT_0000a10c);
          if (param_3 << 0x1b < 0) {
            pcVar2 = (char *)(DAT_0000a148 + 0xa100);
          }
          else {
            pcVar2 = (char *)(DAT_0000a13c + 0xa0ee);
          }
        }
      }
    }
  }
  else if (param_3 << 0x1b < 0) {
    pcVar2 = (char *)(DAT_0000a124 + 0xa058);
  }
  else {
    pcVar2 = (char *)(DAT_0000a120 + 0xa04a);
    uVar3 = CONCAT44(param_2,param_1);
  }
  printf(pcVar2,param_3 << 0x1b,(int)uVar3,(int)(uVar3 >> 0x20));
  return;
}



/* Function: FUN_0000a150 @ 0000a150 */

void FUN_0000a150(undefined4 param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  if (param_4 == 0) {
    if ((param_3 == 0) && (param_2 == 0)) {
      return;
    }
    iVar2 = DAT_0000a234 + 0xa1f8;
  }
  else {
    iVar2 = DAT_0000a228 + 0xa16a;
  }
  uVar1 = param_2 >> 0x18;
  uVar6 = (param_2 & 0xff00) >> 8;
  uVar7 = (param_2 & 0xff0000) >> 0x10;
  printf((char *)(DAT_0000a22c + 0xa1a4),iVar2,param_1,param_2 & 0xff,uVar6,uVar7,uVar1);
  if (param_3 == 0xffffffff) {
    printf((char *)(DAT_0000a23c + 0xa21e));
  }
  else {
    uVar3 = param_3 >> 0x18 | param_3 << 0x18;
    uVar4 = (param_3 & 0xff00) << 8;
    uVar5 = uVar3 | uVar4 | (param_3 & 0xff0000) >> 8;
    if (uVar5 == 0xfffffffe) {
      iVar2 = 0x1f;
    }
    else {
      iVar2 = 0x1e;
      for (uVar4 = 0xfffffffc; uVar5 != uVar4; uVar4 = uVar4 << 1) {
        bVar8 = iVar2 == 0;
        iVar2 = iVar2 + -1;
        if (bVar8) {
          printf((char *)(DAT_0000a238 + 0xa212),param_3 & 0xff,(param_3 & 0xff00) >> 8,
                 (param_3 & 0xff0000) >> 0x10,param_3 >> 0x18,uVar7,uVar1);
          return;
        }
      }
    }
    printf((char *)(DAT_0000a230 + 0xa1e0),iVar2,uVar3,uVar4,uVar6,uVar7,uVar1);
  }
  return;
}



/* Function: FUN_0000a240 @ 0000a240 */

byte * FUN_0000a240(byte *param_1)

{
  int iVar1;
  size_t sVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 unaff_r6;
  int unaff_lr;
  undefined4 uVar10;
  
  uVar6 = (uint)*param_1;
  iVar9 = iRam0000a2ac + 0xa24c;
  if (uVar6 != 0) {
    sVar2 = strlen((char *)param_1);
    if (sVar2 < 0x1d) {
      pbVar3 = param_1;
      while ((*(byte *)(**(int **)(iVar9 + iRam0000a2b0) + uVar6 + 1) & 8) == 0) {
        pbVar3 = pbVar3 + 1;
        uVar6 = (uint)*pbVar3;
        if (uVar6 == 0) {
          return param_1;
        }
      }
      (**(code **)(**(int **)(iVar9 + iRam0000a2b4) + 0x14))(2,iRam0000a2b8 + 0xa280,param_1);
    }
    (**(code **)(**(int **)(iVar9 + iRam0000a2b4) + 0x14))(2,iRam0000a2bc + 0xa292,param_1,0x1c);
  }
  (**(code **)(**(int **)(iVar9 + iRam0000a2b4) + 0x14))(2,iRam0000a2c0 + 0xa2a6);
  iVar1 = DAT_0000a310;
  iVar7 = iVar9 * 0x100;
  uVar10 = 0xa2ab;
  iVar8 = DAT_0000a308 + 0xa2d0;
  iVar4 = **(int **)(iVar8 + DAT_0000a30c) + 1;
  if (iVar4 != 0) {
    fprintf((FILE *)(*(int *)(iVar8 + DAT_0000a310) + 0xa8),(char *)(DAT_0000a314 + 0xa2e0),
            **(int **)(iVar8 + DAT_0000a30c),iVar4,iVar7,iVar9,unaff_r6,0xa2ab);
  }
  uVar5 = *(undefined4 *)(*(int *)(iVar8 + DAT_0000a318) + 4);
  fprintf((FILE *)(*(int *)(iVar8 + iVar1) + 0xa8),(char *)(DAT_0000a31c + 0xa2f2),uVar5,uVar5,iVar7
          ,iVar9,unaff_r6,uVar10);
  FUN_00021f14(1);
                    /* WARNING: Subroutine does not return */
  exit(unaff_lr << 8);
}



/* Function: FUN_0000a2c4 @ 0000a2c4 */

void FUN_0000a2c4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0000a310;
  iVar2 = DAT_0000a308 + 0xa2d0;
  if (**(int **)(iVar2 + DAT_0000a30c) != -1) {
    fprintf((FILE *)(*(int *)(iVar2 + DAT_0000a310) + 0xa8),(char *)(DAT_0000a314 + 0xa2e0));
  }
  fprintf((FILE *)(*(int *)(iVar2 + iVar1) + 0xa8),(char *)(DAT_0000a31c + 0xa2f2),
          *(undefined4 *)(*(int *)(iVar2 + DAT_0000a318) + 4));
  FUN_00021f14(1);
                    /* WARNING: Subroutine does not return */
  exit(param_1);
}



/* Function: FUN_0000a320 @ 0000a320 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0000a320(undefined4 param_1)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = FUN_000224cc(param_1,0,&local_c,1,DAT_0000a354);
  if (iVar1 != 0) {
    return local_c;
  }
  (**(code **)(**(int **)(DAT_0000a358 + 0xa348) + 0x14))(2,DAT_0000a35c + 0xa34c,param_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: FUN_0000a360 @ 0000a360 */

char * FUN_0000a360(uint param_1,int param_2)

{
  byte bVar1;
  char *pcVar2;
  protoent *ppVar3;
  int *piVar4;
  
  if (((param_2 == 0) && (param_1 != 0)) &&
     (ppVar3 = getprotobynumber(param_1), ppVar3 != (protoent *)0x0)) {
    pcVar2 = ppVar3->p_name;
  }
  else {
    piVar4 = *(int **)(DAT_0000a3a0 + 0xa36e);
    pcVar2 = (char *)*piVar4;
    if (pcVar2 != (char *)0x0) {
      bVar1 = *(byte *)(piVar4 + 1);
      while (bVar1 != param_1) {
        pcVar2 = (char *)piVar4[2];
        if (pcVar2 == (char *)0x0) {
          return (char *)0x0;
        }
        bVar1 = *(byte *)(piVar4 + 3);
        piVar4 = piVar4 + 2;
      }
    }
  }
  return pcVar2;
}



/* Function: FUN_0000a3a4 @ 0000a3a4 */

undefined4 FUN_0000a3a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint local_1c [2];
  
  iVar1 = FUN_000224cc(param_1,0,local_1c,0,0xff);
  if (iVar1 == 0) {
    uVar2 = FUN_00022fc4(param_1,param_2,param_4);
  }
  else {
    iVar1 = FUN_0000a360(local_1c[0] & 0xff,param_3);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_00022fc4(iVar1,param_2,param_4);
    }
  }
  return uVar2;
}



/* Function: FUN_0000a3f0 @ 0000a3f0 */

void FUN_0000a3f0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  size_t sVar9;
  uint uVar10;
  undefined4 *puVar11;
  code *pcVar12;
  ushort *puVar13;
  FILE *__stream;
  uint uVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  int *piVar21;
  int *piVar22;
  int *piVar23;
  
  iVar3 = DAT_0000a710;
  piVar16 = (int *)(&stack0xffffffdc + DAT_0000a710);
  piVar17 = (int *)(&stack0xffffffdc + DAT_0000a710);
  piVar18 = (int *)(&stack0xffffffdc + DAT_0000a710);
  piVar19 = (int *)(&stack0xffffffdc + DAT_0000a710);
  piVar20 = (int *)(&stack0xffffffdc + DAT_0000a710);
  piVar21 = (int *)(&stack0xffffffdc + DAT_0000a710);
  piVar22 = (int *)(&stack0xffffffdc + DAT_0000a710);
  piVar23 = (int *)(&stack0xffffffdc + DAT_0000a710);
  iVar15 = DAT_0000a718 + 42000;
  puVar11 = *(undefined4 **)(iVar15 + DAT_0000a714);
  *(int *)(&stack0xffffffe8 + DAT_0000a710) = DAT_0000a714;
  *(undefined4 *)(&stack0xffffffdc + DAT_0000a71c + DAT_0000a710) = *puVar11;
  iVar4 = iptc_is_chain(param_2,*(undefined4 *)(&stack0x00000434 + DAT_0000a710));
  if (iVar4 == 0) {
    uVar8 = FUN_00021d00(param_2,2);
    *(undefined4 *)(&stack0xffffffec + iVar3) = uVar8;
  }
  else {
    uVar8 = FUN_00021d00(DAT_0000a744 + 0xa5fc,3);
    *(undefined4 *)(&stack0xffffffec + iVar3) = uVar8;
  }
  *(uint *)(&stack0xfffffff0 + iVar3) = param_1 + (uint)*(ushort *)(param_1 + 0x58);
  bVar1 = *(byte *)(param_1 + 0x52);
  if ((int)(param_4 << 0x17) < 0) {
    if ((param_4 & 0x10) == 0) {
      pcVar7 = (char *)(DAT_0000a740 + 0xa5d2);
    }
    else {
      pcVar7 = (char *)(DAT_0000a750 + 0xa614);
    }
    printf(pcVar7,param_3);
  }
  if (-1 < (int)(param_4 << 0x1e)) {
    FUN_0000a018(*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 100),param_4);
    FUN_0000a018(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),param_4);
  }
  uVar14 = param_4 & 0x10;
  if (-1 < (int)(param_4 << 0x1a)) {
    if (uVar14 == 0) {
      pcVar7 = (char *)(DAT_0000a720 + 0xa472);
    }
    else {
      pcVar7 = (char *)(DAT_0000a74c + 0xa60e);
    }
    printf(pcVar7,param_2);
  }
  bVar2 = *(byte *)(param_1 + 0x53);
  iVar4 = *(int *)(iVar15 + DAT_0000a724);
  *piVar16 = DAT_0000a724;
  fputc(0x20 - ((int)((uint)bVar2 << 0x19) >> 0x1f),(FILE *)(iVar4 + 0x54));
  uVar10 = param_4 & 1;
  uVar5 = FUN_0000a360(*(undefined1 *)(param_1 + 0x50));
  if (uVar5 == 0) {
    if (uVar14 == 0) {
      pcVar7 = (char *)(DAT_0000a934 + 0xa8d6);
    }
    else {
      pcVar7 = (char *)(DAT_0000a940 + 0xa90c);
    }
    uVar5 = (uint)*(ushort *)(param_1 + 0x50);
  }
  else if (uVar14 == 0) {
    pcVar7 = (char *)(DAT_0000a728 + 0xa4b0);
  }
  else {
    pcVar7 = (char *)(DAT_0000a748 + 0xa608);
  }
  printf(pcVar7,uVar5);
  if ((int)(param_4 << 0x1c) < 0) {
    if (uVar14 != 0) {
      fwrite((void *)(DAT_0000a93c + 0xa902),1,4,(FILE *)(*(int *)(iVar15 + *piVar23) + 0x54));
    }
    iVar4 = 0x21;
    if (-1 < (int)((uint)*(byte *)(param_1 + 0x53) << 0x1a)) {
      iVar4 = 0x2d;
    }
    fputc(iVar4,(FILE *)(*(int *)(iVar15 + *piVar17) + 0x54));
    iVar4 = 0x66;
    if (-1 < (int)((uint)bVar1 << 0x1f)) {
      iVar4 = 0x2d;
    }
    __stream = (FILE *)(*(int *)(iVar15 + *piVar18) + 0x54);
    fputc(iVar4,__stream);
    fputc(0x20,__stream);
  }
  if ((int)(param_4 << 0x19) < 0) {
    if ((*(byte *)(param_1 + 0x53) & 1) == 0) {
      (&stack0x000003f4)[iVar3] = *(byte *)(param_1 + 0x53) & 1;
      if (*(char *)(param_1 + 0x10) != '\0') goto LAB_0000a854;
LAB_0000a51e:
      pcVar7 = &stack0x000003f4 + iVar3;
      if (uVar10 == 0) {
        sVar9 = strlen(pcVar7);
        memcpy(pcVar7 + sVar9,(void *)(DAT_0000a72c + 0xa536),4);
      }
      else {
        sVar9 = strlen(pcVar7);
        pcVar7[sVar9] = '*';
        (pcVar7 + sVar9)[1] = '\0';
      }
      if (uVar14 == 0) goto LAB_0000a53e;
LAB_0000a864:
      printf((char *)(DAT_0000a920 + 0xa86c),&stack0x000003f4 + iVar3);
      bVar1 = *(byte *)(param_1 + 0x53);
      if ((bVar1 & 2) == 0) goto LAB_0000a87a;
LAB_0000a554:
      (&stack0x000003f4)[iVar3] = 0x21;
      (&stack0x000003f5)[iVar3] = 0;
      if (*(char *)(param_1 + 0x20) == '\0') goto LAB_0000a566;
LAB_0000a886:
      pcVar7 = &stack0x000003f4 + iVar3;
      strcat(pcVar7,(char *)(param_1 + 0x20));
      if (uVar14 == 0) goto LAB_0000a896;
LAB_0000a582:
      pcVar6 = (char *)(DAT_0000a734 + 0xa588);
    }
    else {
      (&stack0x000003f4)[iVar3] = 0x21;
      (&stack0x000003f5)[iVar3] = 0;
      if (*(char *)(param_1 + 0x10) == '\0') goto LAB_0000a51e;
LAB_0000a854:
      strcat(&stack0x000003f4 + iVar3,(char *)(param_1 + 0x10));
      if (uVar14 != 0) goto LAB_0000a864;
LAB_0000a53e:
      printf((char *)(DAT_0000a730 + 0xa546),&stack0x000003f4 + iVar3);
      bVar1 = *(byte *)(param_1 + 0x53);
      if ((bVar1 & 2) != 0) goto LAB_0000a554;
LAB_0000a87a:
      (&stack0x000003f4)[iVar3] = bVar1 & 2;
      if (*(char *)(param_1 + 0x20) != '\0') goto LAB_0000a886;
LAB_0000a566:
      pcVar7 = &stack0x000003f4 + iVar3;
      if (uVar10 == 0) {
        sVar9 = strlen(pcVar7);
        memcpy(pcVar7 + sVar9,(void *)(DAT_0000a930 + 0xa8c8),4);
      }
      else {
        sVar9 = strlen(pcVar7);
        pcVar7[sVar9] = '*';
        (pcVar7 + sVar9)[1] = '\0';
      }
      if (uVar14 != 0) goto LAB_0000a582;
LAB_0000a896:
      pcVar7 = &stack0x000003f4 + iVar3;
      pcVar6 = (char *)(DAT_0000a924 + 0xa89c);
    }
    printf(pcVar6,pcVar7);
  }
  fputc(0x20 - ((int)((uint)*(byte *)(param_1 + 0x53) << 0x1c) >> 0x1f),
        (FILE *)(*(int *)(iVar15 + *piVar19) + 0x54));
  if (*(int *)(param_1 + 8) == 0) {
    if (uVar10 != 0) {
LAB_0000a832:
      pcVar6 = (char *)FUN_00021f64(param_1);
      pcVar7 = &stack0xfffffff4 + iVar3;
      strcpy(pcVar7,pcVar6);
      goto LAB_0000a62c;
    }
    if (uVar14 == 0) {
      pcVar7 = (char *)(DAT_0000a738 + 0xa5bc);
    }
    else {
      pcVar7 = (char *)(DAT_0000a92c + 0xa8b8);
    }
    printf(pcVar7,DAT_0000a73c + 0xa5c0);
  }
  else {
    if (uVar10 != 0) goto LAB_0000a832;
    pcVar6 = (char *)FUN_00022194(param_1);
    pcVar7 = &stack0xfffffff4 + iVar3;
    strcpy(pcVar7,pcVar6);
LAB_0000a62c:
    pcVar6 = (char *)FUN_00021f94(param_1 + 8);
    strcat(pcVar7,pcVar6);
    if (uVar14 == 0) {
      pcVar6 = (char *)(DAT_0000a754 + 0xa648);
    }
    else {
      pcVar6 = (char *)(DAT_0000a918 + 0xa81a);
    }
    printf(pcVar6,pcVar7);
  }
  fputc(0x20 - ((int)((uint)*(byte *)(param_1 + 0x53) << 0x1b) >> 0x1f),
        (FILE *)(*(int *)(iVar15 + *piVar20) + 0x54));
  if (*(int *)(param_1 + 0xc) == 0) {
    if (uVar10 == 0) {
      if (uVar14 == 0) {
        pcVar7 = (char *)(DAT_0000a758 + 0xa67c);
      }
      else {
        pcVar7 = (char *)(DAT_0000a928 + 0xa8b2);
      }
      printf(pcVar7,DAT_0000a75c + 0xa680);
      goto joined_r0x0000a6e6;
    }
LAB_0000a81a:
    pcVar6 = (char *)FUN_00021f64(param_1 + 4);
    pcVar7 = &stack0xfffffff4 + iVar3;
    strcpy(pcVar7,pcVar6);
  }
  else {
    if (uVar10 != 0) goto LAB_0000a81a;
    pcVar6 = (char *)FUN_00022194(param_1 + 4);
    pcVar7 = &stack0xfffffff4 + iVar3;
    strcpy(pcVar7,pcVar6);
  }
  pcVar6 = (char *)FUN_00021f94(param_1 + 0xc);
  strcat(pcVar7,pcVar6);
  if (uVar14 == 0) {
    pcVar6 = (char *)(DAT_0000a768 + 0xa6e0);
  }
  else {
    pcVar6 = (char *)(DAT_0000a91c + 0xa832);
  }
  printf(pcVar6,pcVar7);
joined_r0x0000a6e6:
  if (uVar14 == 0) {
    bVar1 = *(byte *)(param_1 + 0x52);
  }
  else {
    fwrite((void *)(DAT_0000a760 + 0xa694),1,2,(FILE *)(*(int *)(iVar15 + *piVar21) + 0x54));
    bVar1 = *(byte *)(param_1 + 0x52);
  }
  if ((int)((uint)bVar1 << 0x1e) < 0) {
    printf((char *)(DAT_0000a764 + 0xa6a8));
  }
  if (0x70 < *(ushort *)(param_1 + 0x58)) {
    uVar14 = 0x70;
    *(int *)(&stack0xffffffe4 + iVar3) = DAT_0000a76c + 0xa702;
    *(int *)(&stack0xffffffe0 + iVar3) = DAT_0000a770 + 0xa704;
    do {
      while( true ) {
        puVar13 = (ushort *)(param_1 + uVar14);
        iVar4 = FUN_00022fc4(puVar13 + 1,2,0);
        if (iVar4 == 0) break;
        if (*(code **)(iVar4 + 0x28) == (code *)0x0) {
          printf(*(char **)(&stack0xffffffe0 + iVar3),*(undefined4 *)(iVar4 + 8));
        }
        else {
          (**(code **)(iVar4 + 0x28))(param_1,puVar13,uVar10);
        }
LAB_0000a782:
        uVar14 = uVar14 + *puVar13;
        if (*(ushort *)(param_1 + 0x58) <= uVar14) goto LAB_0000a7bc;
      }
      if ((char)puVar13[1] == '\0') goto LAB_0000a782;
      printf(*(char **)(&stack0xffffffe4 + iVar3),puVar13 + 1);
      uVar14 = uVar14 + *puVar13;
    } while (uVar14 < *(ushort *)(param_1 + 0x58));
  }
LAB_0000a7bc:
  if (*(int *)(&stack0xffffffec + iVar3) == 0) {
    if (**(ushort **)(&stack0xfffffff0 + iVar3) != 0x20) {
      printf((char *)(DAT_0000a938 + 0xa8ec),**(ushort **)(&stack0xfffffff0 + iVar3) - 0x20);
    }
  }
  else {
    pcVar12 = *(code **)(*(int *)(&stack0xffffffec + iVar3) + 0x28);
    if (pcVar12 != (code *)0x0) {
      (*pcVar12)(param_1,*(undefined4 *)(&stack0xfffffff0 + iVar3),uVar10);
    }
  }
  if (-1 < (int)(param_4 << 0x18)) {
    fputc(10,(FILE *)(*(int *)(iVar15 + *piVar22) + 0x54));
  }
  if (*(int *)(&stack0xffffffdc + DAT_0000a910 + iVar3) ==
      **(int **)(iVar15 + *(int *)(&stack0xffffffe8 + iVar3))) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_0000a944 @ 0000a944 */

void FUN_0000a944(undefined4 param_1,int param_2,char *param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  if (*param_3 != '\0') {
    if (param_4 == 0) {
      iVar2 = DAT_0000a9a4 + 0xa95c;
    }
    else {
      iVar2 = DAT_0000a9ac + 0xa992;
    }
    iVar3 = 0;
    printf((char *)(DAT_0000a9a8 + 0xa964),iVar2,param_1);
    do {
      while( true ) {
        if (param_3[iVar3] == '\0') {
          if (*(char *)(param_2 + iVar3 + -1) != '\0') {
            putchar(0x2b);
          }
          goto LAB_0000a984;
        }
        pbVar1 = (byte *)(param_2 + iVar3);
        if (*pbVar1 == 0) break;
        iVar3 = iVar3 + 1;
        putchar((uint)*pbVar1);
        if (iVar3 == 0x10) goto LAB_0000a984;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x10);
LAB_0000a984:
    putchar(0x20);
  }
  return;
}



/* Function: FUN_0000a9b0 @ 0000a9b0 */

void FUN_0000a9b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte *pbVar1;
  protoent *ppVar2;
  undefined4 uVar3;
  ushort *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  short *psVar8;
  int iVar9;
  uint uVar10;
  short *psVar11;
  ushort *puVar12;
  char *pcVar13;
  int iVar14;
  
  iVar14 = DAT_0000abf8 + 0xa9c8;
  if (0 < param_4) {
    printf((char *)(DAT_0000abfc + 0xa9de),param_2,param_1[0x18],param_1[0x19],param_1[0x1a],
           param_1[0x1b]);
  }
  printf((char *)(DAT_0000ac00 + 0xa9ee),param_3);
  FUN_0000a150(DAT_0000ac04 + 0xa9fc,*param_1,param_1[2],*(byte *)((int)param_1 + 0x53) & 8);
  FUN_0000a150(DAT_0000ac08 + 0xaa0e,param_1[1],param_1[3],*(byte *)((int)param_1 + 0x53) & 0x10);
  FUN_0000a944(0x69,param_1 + 4,param_1 + 0xc,*(byte *)((int)param_1 + 0x53) & 1);
  FUN_0000a944(0x6f,param_1 + 8,param_1 + 0x10,*(byte *)((int)param_1 + 0x53) & 2);
  uVar10 = (uint)*(ushort *)(param_1 + 0x14);
  if (uVar10 != 0) {
    if ((int)((uint)*(byte *)((int)param_1 + 0x53) << 0x19) < 0) {
      iVar9 = DAT_0000ac30 + 0xab6a;
      ppVar2 = getprotobynumber(uVar10);
    }
    else {
      iVar9 = DAT_0000ac0c + 0xaa54;
      ppVar2 = getprotobynumber(uVar10);
    }
    if (ppVar2 == (protoent *)0x0) {
      piVar6 = *(int **)(iVar14 + DAT_0000ac34);
      iVar5 = *piVar6;
      while (iVar5 != 0) {
        pbVar1 = (byte *)(piVar6 + 1);
        piVar6 = piVar6 + 2;
        if (uVar10 == *pbVar1) {
          printf((char *)(DAT_0000ac38 + 0xab96),iVar9);
          goto LAB_0000aa6a;
        }
        iVar5 = *piVar6;
      }
      printf((char *)(DAT_0000ac44 + 0xabdc),iVar9,uVar10);
    }
    else {
      printf((char *)(DAT_0000ac10 + 0xaa66),iVar9,ppVar2->p_name);
    }
  }
LAB_0000aa6a:
  if ((int)((uint)*(byte *)((int)param_1 + 0x52) << 0x1f) < 0) {
    if ((int)((uint)*(byte *)((int)param_1 + 0x53) << 0x1a) < 0) {
      iVar9 = DAT_0000ac2c + 0xab62;
    }
    else {
      iVar9 = DAT_0000ac14 + 0xaa82;
    }
    printf((char *)(DAT_0000ac18 + 0xaa86),iVar9);
  }
  if ((*(ushort *)(param_1 + 0x16) != 0) && (0x70 < *(ushort *)(param_1 + 0x16))) {
    uVar10 = 0x70;
    pcVar13 = (char *)(DAT_0000ac1c + 0xaaa0);
    do {
      puVar12 = (ushort *)((int)param_1 + uVar10);
      puVar4 = puVar12 + 1;
      iVar9 = FUN_00022fc4(puVar4,2,0);
      if (iVar9 == 0) {
        uVar7 = 0;
        if (*puVar12 != 0) {
          fprintf((FILE *)(*(int *)(iVar14 + DAT_0000ac20) + 0xa8),(char *)(DAT_0000ac24 + 0xaaec),
                  puVar4);
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
      }
      else {
        printf(pcVar13,puVar4);
        if (*(code **)(iVar9 + 0x2c) == (code *)0x0) {
          uVar7 = (uint)*puVar12;
        }
        else {
          (**(code **)(iVar9 + 0x2c))(param_1,puVar12);
          uVar7 = (uint)*puVar12;
        }
      }
      uVar10 = uVar10 + uVar7;
    } while (uVar10 < *(ushort *)(param_1 + 0x16));
  }
  if (param_4 < 0) {
    printf((char *)(DAT_0000ac40 + 0xabca));
  }
  pcVar13 = (char *)iptc_get_target(param_1,param_2);
  if ((pcVar13 != (char *)0x0) && (*pcVar13 != '\0')) {
    uVar3 = 0x67;
    if (-1 < (int)((uint)*(byte *)((int)param_1 + 0x52) << 0x1e)) {
      uVar3 = 0x6a;
    }
    printf((char *)(DAT_0000ac28 + 0xab20),uVar3);
  }
  psVar8 = (short *)((int)param_1 + (uint)*(ushort *)(param_1 + 0x16));
  if ((char)psVar8[1] != '\0') {
    psVar11 = psVar8 + 1;
    iVar9 = FUN_00021d00(psVar11,2);
    if (iVar9 == 0) {
      fprintf((FILE *)(*(int *)(iVar14 + DAT_0000ac20) + 0xa8),(char *)(DAT_0000ac48 + 0xabee),
              psVar11);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (*(code **)(iVar9 + 0x2c) == (code *)0x0) {
      if (*psVar8 != 0x20) {
        fprintf((FILE *)(*(int *)(iVar14 + DAT_0000ac20) + 0xa8),(char *)(DAT_0000ac3c + 0xabae),
                psVar11);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
    }
    else {
      (**(code **)(iVar9 + 0x2c))(param_1,psVar8);
    }
  }
  putchar(10);
  return;
}



/* Function: FUN_0000ac4c @ 0000ac4c */

uint FUN_0000ac4c(code *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  char *__ptr;
  char *__src;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = iptc_first_chain(param_4);
  iVar5 = 0;
  iVar3 = 0;
  if (iVar1 != 0) {
    do {
      iVar5 = iVar5 + 1;
      iVar1 = iptc_next_chain(param_4);
    } while (iVar1 != 0);
    iVar3 = iVar5 * 0x20;
  }
  __ptr = (char *)FUN_00022ddc(iVar3);
  __src = (char *)iptc_first_chain(param_4);
  pcVar4 = __ptr;
  while (__src != (char *)0x0) {
    strcpy(pcVar4,__src);
    __src = (char *)iptc_next_chain(param_4);
    pcVar4 = pcVar4 + 0x20;
  }
  uVar6 = 1;
  if (iVar5 != 0) {
    iVar1 = 0;
    pcVar4 = __ptr;
    do {
      if ((param_3 != 0) || (iVar3 = iptc_builtin(pcVar4,param_4), iVar3 != 1)) {
        uVar2 = (*param_1)(pcVar4,param_2,param_4);
        uVar6 = uVar6 & uVar2;
      }
      iVar1 = iVar1 + 1;
      pcVar4 = pcVar4 + 0x20;
    } while (iVar1 != iVar5);
  }
  free(__ptr);
  return uVar6;
}



/* Function: FUN_0000acf0 @ 0000acf0 */

void FUN_0000acf0(int param_1,int param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    FUN_0000ac4c(DAT_0000ad38 + 0xad28,param_2,1,param_3);
  }
  else {
    if (param_2 != 0) {
      fprintf((FILE *)(*(int *)(DAT_0000ad2c + 0xacfc + DAT_0000ad30) + 0x54),
              (char *)(DAT_0000ad34 + 0xad18),param_1);
    }
    iptc_zero_entries(param_1,param_3);
  }
  return;
}



/* Function: FUN_0000ad3c @ 0000ad3c */

void FUN_0000ad3c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_1c;
  int local_18;
  int local_14 [2];
  
  iVar1 = DAT_0000ada4;
  iVar3 = DAT_0000ada8 + 0xad4e;
  local_14[0] = 0;
  local_18 = 0;
  local_1c = 0;
  iVar2 = uname((utsname *)(DAT_0000ada4 + 0xad48));
  if (iVar2 != -1) {
    sscanf((char *)(iVar1 + 0xadca),(char *)(DAT_0000adac + 0xad6a),local_14,&local_18,&local_1c);
    **(int **)(iVar3 + DAT_0000adb0) = (local_14[0] * 0x100 + local_18) * 0x100 + local_1c;
    return;
  }
  fwrite((void *)(DAT_0000adb8 + 0xad94),1,0x23,(FILE *)(*(int *)(iVar3 + DAT_0000adb4) + 0xa8));
  FUN_00021f14(1);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



/* Function: delete_chain @ 0000adbc */

void delete_chain(int param_1,int param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    FUN_0000ac4c(*(undefined4 *)(DAT_0000adf8 + 0xadc8 + DAT_0000ae04),param_2,0,param_3);
  }
  else {
    if (param_2 != 0) {
      fprintf((FILE *)(*(int *)(DAT_0000adf8 + 0xadc8 + DAT_0000adfc) + 0x54),
              (char *)(DAT_0000ae00 + 0xade4),param_1);
    }
    iptc_delete_chain(param_1,param_3);
  }
  return;
}



/* Function: flush_entries @ 0000ae08 */

void flush_entries(int param_1,int param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    FUN_0000ac4c(*(undefined4 *)(DAT_0000ae44 + 0xae14 + DAT_0000ae50),param_2,1,param_3);
  }
  else {
    if (param_2 != 0) {
      fprintf((FILE *)(*(int *)(DAT_0000ae44 + 0xae14 + DAT_0000ae48) + 0x54),
              (char *)(DAT_0000ae4c + 0xae30),param_1);
    }
    iptc_flush_entries(param_1,param_3);
  }
  return;
}



/* Function: FUN_0000ae54 @ 0000ae54 */

/* WARNING: Removing unreachable block (ram,0x0000af32) */
/* WARNING: Removing unreachable block (ram,0x0000af38) */
/* WARNING: Removing unreachable block (ram,0x0000af54) */

void FUN_0000ae54(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *local_c8;
  undefined4 local_c4;
  uint local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [116];
  undefined4 local_2c;
  
  iVar12 = DAT_0000b1a0 + 0xae6c;
  local_2c = **(undefined4 **)(iVar12 + DAT_0000b1a4);
  local_a4 = 0;
  local_a8 = 0;
  local_ac = 0;
  local_b0 = 0;
  local_b4 = 0;
  local_b8 = 0;
  local_bc = 0;
  local_c0 = 0;
  local_c4 = 0;
  local_c8 = (int *)0x0;
  memset(auStack_a0,0,0x70);
  iVar6 = DAT_0000b1a8;
  **(undefined4 **)(iVar12 + DAT_0000b1a8) = 0;
  for (iVar10 = **(int **)(iVar12 + DAT_0000b1ac); iVar10 != 0; iVar10 = *(int *)(iVar10 + 4)) {
    *(undefined4 *)(iVar10 + 0x3c) = 0;
  }
  iVar2 = DAT_0000b1bc;
  iVar3 = DAT_0000b1c4;
  iVar4 = DAT_0000b1c8;
  for (iVar10 = **(int **)(iVar12 + DAT_0000b1b0); DAT_0000b1bc = iVar2, DAT_0000b1c4 = iVar3,
      DAT_0000b1c8 = iVar4, iVar10 != 0; iVar10 = *(int *)(iVar10 + 4)) {
    *(undefined4 *)(iVar10 + 0x3c) = 0;
    *(undefined4 *)(iVar10 + 0x40) = 0;
    iVar2 = DAT_0000b1bc;
    iVar3 = DAT_0000b1c4;
    iVar4 = DAT_0000b1c8;
  }
  **(undefined4 **)(iVar12 + DAT_0000b1b4) = 0;
  bVar1 = false;
  while( true ) {
    uVar7 = getopt_long(param_1,param_2,iVar4 + 0xaf12,
                        *(undefined4 *)(*(int *)(iVar12 + iVar3) + 0x10),0);
    if (uVar7 == 0xffffffff) {
      FUN_0000b71a();
    }
    piVar5 = local_c8;
    if (uVar7 < 0x79) break;
    for (; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
      if (*(char *)(piVar5 + 2) == '\0') {
        iVar10 = piVar5[1];
        if ((*(code **)(iVar10 + 0x20) != (code *)0x0) &&
           (iVar10 = (**(code **)(iVar10 + 0x20))
                               (uVar7 - *(int *)(iVar10 + 0x34),param_2,local_a4,iVar10 + 0x3c,
                                auStack_a0,iVar10 + 0x38), iVar10 != 0)) {
          FUN_0000b97c();
        }
      }
    }
    uVar8 = FUN_0000b992();
    iVar10 = FUN_0000a3a4(uVar8,0,local_c0 & 1,0);
    if (iVar10 != 0) {
      iVar10 = FUN_0000a3a4(0,0,local_c0 & 1,0);
      if (iVar10 == 0) {
        FUN_0000b992();
      }
      if (bVar1) {
        FUN_0000b992();
      }
    }
    iVar10 = FUN_0000a3a4(0,2,local_c0 & 1,&local_c8);
    if (iVar10 == 0) {
      FUN_0000b99a();
    }
    iVar11 = *(int *)(iVar10 + 0x10) + 0x20;
    puVar9 = (undefined2 *)FUN_00023304(1,iVar11);
    *(undefined2 **)(iVar10 + 0x38) = puVar9;
    *puVar9 = (short)iVar11;
    strcpy((char *)(*(int *)(iVar10 + 0x38) + 2),*(char **)(iVar10 + 8));
    *(undefined1 *)(*(int *)(iVar10 + 0x38) + 0x1f) = *(undefined1 *)(iVar10 + 0xc);
    if (*(code **)(iVar10 + 0x1c) != (code *)0x0) {
      (**(code **)(iVar10 + 0x1c))(*(undefined4 *)(iVar10 + 0x38));
    }
    iVar11 = *(int *)(iVar12 + iVar3);
    iVar10 = FUN_0002287c(*(undefined4 *)(iVar11 + 0x10),*(undefined4 *)(iVar10 + 0x30),
                          iVar10 + 0x34);
    *(int *)(iVar11 + 0x10) = iVar10;
    if (iVar10 == 0) {
      FUN_0000c810();
    }
    **(int **)(iVar12 + iVar6) = **(int **)(iVar12 + iVar6) + -1;
    bVar1 = true;
  }
                    /* WARNING: Could not emulate address calculation at 0x0000b05a */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(uVar7 * 4 + iVar2 + 0xaf06) + iVar2 + 0xaf06))();
  return;
}



/* Function: FUN_0000afa8 @ 0000afa8 */

void FUN_0000afa8(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  int unaff_r5;
  int unaff_r6;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  int unaff_r10;
  int in_stack_0000002c;
  int in_stack_00000030;
  int in_stack_00000038;
  int in_stack_00000044;
  int in_stack_00000074;
  int *in_stack_00000098;
  uint in_stack_000000a0;
  undefined4 in_stack_000000bc;
  
  while( true ) {
    iVar3 = in_stack_00000044;
    if (in_stack_00000044 == 0) {
      iVar3 = FUN_0000b992();
    }
    iVar3 = FUN_0000a3a4(iVar3,0,in_stack_000000a0 & 1,0);
    if (iVar3 != 0) {
      iVar3 = FUN_0000a3a4(in_stack_00000044,0,in_stack_000000a0 & 1,0);
      if (iVar3 == 0) {
        FUN_0000b992();
      }
      if (in_stack_00000074 != 0) {
        FUN_0000b992();
      }
    }
    iVar3 = FUN_0000a3a4(in_stack_00000044,2,in_stack_000000a0 & 1,&stack0x00000098);
    if (iVar3 == 0) {
      FUN_0000b99a();
    }
    iVar5 = *(int *)(iVar3 + 0x10) + 0x20;
    puVar4 = (undefined2 *)FUN_00023304(1,iVar5);
    *(undefined2 **)(iVar3 + 0x38) = puVar4;
    *puVar4 = (short)iVar5;
    strcpy((char *)(*(int *)(iVar3 + 0x38) + 2),*(char **)(iVar3 + 8));
    *(undefined1 *)(*(int *)(iVar3 + 0x38) + 0x1f) = *(undefined1 *)(iVar3 + 0xc);
    if (*(code **)(iVar3 + 0x1c) != (code *)0x0) {
      (**(code **)(iVar3 + 0x1c))(*(undefined4 *)(iVar3 + 0x38));
    }
    iVar5 = *(int *)(unaff_r5 + in_stack_0000002c);
    iVar3 = FUN_0002287c(*(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar3 + 0x30),iVar3 + 0x34);
    *(int *)(iVar5 + 0x10) = iVar3;
    if (iVar3 == 0) {
      FUN_0000c810();
    }
    **(int **)(unaff_r5 + in_stack_00000030) = **(int **)(unaff_r5 + in_stack_00000030) + -1;
    in_stack_00000074 = 1;
    uVar2 = getopt_long(unaff_r9,unaff_r8,unaff_r6 + 0xaf12,
                        *(undefined4 *)(*(int *)(unaff_r5 + in_stack_0000002c) + 0x10));
    if (uVar2 == 0xffffffff) {
      FUN_0000b71a();
    }
    if (uVar2 < 0x79) break;
    piVar1 = in_stack_00000098;
    if (((in_stack_00000038 != 0) && (*(code **)(in_stack_00000038 + 0x20) != (code *)0x0)) &&
       (iVar3 = (**(code **)(in_stack_00000038 + 0x20))
                          (uVar2 - *(int *)(in_stack_00000038 + 0x34),unaff_r8,in_stack_000000bc,
                           in_stack_00000038 + 0x3c), piVar1 = in_stack_00000098, iVar3 != 0)) {
      FUN_0000b0f8();
      return;
    }
    for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (*(char *)(piVar1 + 2) == '\0') {
        iVar3 = piVar1[1];
        if ((*(code **)(iVar3 + 0x20) != (code *)0x0) &&
           (iVar3 = (**(code **)(iVar3 + 0x20))
                              (uVar2 - *(int *)(iVar3 + 0x34),unaff_r8,in_stack_000000bc,
                               iVar3 + 0x3c), iVar3 != 0)) {
          FUN_0000b97c();
        }
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0000b05e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(uVar2 * 4 + unaff_r10) + unaff_r10))();
  return;
}



/* Function: FUN_0000b0f8 @ 0000b0f8 */

void FUN_0000b0f8(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  int unaff_r5;
  int unaff_r6;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  int unaff_r10;
  undefined4 uStack00000000;
  int in_stack_0000002c;
  int in_stack_00000030;
  undefined4 in_stack_00000034;
  int in_stack_00000038;
  int in_stack_00000044;
  int in_stack_00000074;
  int *in_stack_00000098;
  uint in_stack_000000a0;
  undefined4 uStack000000bc;
  
  uStack000000bc = 0;
  while( true ) {
    uStack00000000 = 0;
    uVar2 = getopt_long(unaff_r9,unaff_r8,unaff_r6 + 0xaf12,
                        *(undefined4 *)(*(int *)(unaff_r5 + in_stack_0000002c) + 0x10));
    if (uVar2 == 0xffffffff) {
      FUN_0000b71a();
    }
    if (uVar2 < 0x79) break;
    piVar1 = in_stack_00000098;
    if ((in_stack_00000038 != 0) && (*(code **)(in_stack_00000038 + 0x20) != (code *)0x0)) {
      uStack00000000 = in_stack_00000034;
      iVar3 = (**(code **)(in_stack_00000038 + 0x20))
                        (uVar2 - *(int *)(in_stack_00000038 + 0x34),unaff_r8,uStack000000bc,
                         in_stack_00000038 + 0x3c);
      piVar1 = in_stack_00000098;
      if (iVar3 != 0) {
        FUN_0000b0f8();
        return;
      }
    }
    for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (*(char *)(piVar1 + 2) == '\0') {
        iVar3 = piVar1[1];
        if (*(code **)(iVar3 + 0x20) != (code *)0x0) {
          uStack00000000 = in_stack_00000034;
          iVar3 = (**(code **)(iVar3 + 0x20))
                            (uVar2 - *(int *)(iVar3 + 0x34),unaff_r8,uStack000000bc,iVar3 + 0x3c);
          if (iVar3 != 0) {
            FUN_0000b97c();
          }
        }
      }
    }
    iVar3 = in_stack_00000044;
    if (in_stack_00000044 == 0) {
      iVar3 = FUN_0000b992();
    }
    iVar3 = FUN_0000a3a4(iVar3,0,in_stack_000000a0 & 1,0);
    if (iVar3 != 0) {
      iVar3 = FUN_0000a3a4(in_stack_00000044,0,in_stack_000000a0 & 1,0);
      if (iVar3 == 0) {
        FUN_0000b992();
      }
      if (in_stack_00000074 != 0) {
        FUN_0000b992();
      }
    }
    iVar3 = FUN_0000a3a4(in_stack_00000044,2,in_stack_000000a0 & 1,&stack0x00000098);
    if (iVar3 == 0) {
      FUN_0000b99a();
    }
    iVar5 = *(int *)(iVar3 + 0x10) + 0x20;
    puVar4 = (undefined2 *)FUN_00023304(1,iVar5);
    *(undefined2 **)(iVar3 + 0x38) = puVar4;
    *puVar4 = (short)iVar5;
    strcpy((char *)(*(int *)(iVar3 + 0x38) + 2),*(char **)(iVar3 + 8));
    *(undefined1 *)(*(int *)(iVar3 + 0x38) + 0x1f) = *(undefined1 *)(iVar3 + 0xc);
    if (*(code **)(iVar3 + 0x1c) != (code *)0x0) {
      (**(code **)(iVar3 + 0x1c))(*(undefined4 *)(iVar3 + 0x38));
    }
    iVar5 = *(int *)(unaff_r5 + in_stack_0000002c);
    iVar3 = FUN_0002287c(*(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar3 + 0x30),iVar3 + 0x34);
    *(int *)(iVar5 + 0x10) = iVar3;
    if (iVar3 == 0) {
      FUN_0000c810();
    }
    **(int **)(unaff_r5 + in_stack_00000030) = **(int **)(unaff_r5 + in_stack_00000030) + -1;
    in_stack_00000074 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0000b05e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(uVar2 * 4 + unaff_r10) + unaff_r10))();
  return;
}



/* Function: FUN_0000b116 @ 0000b116 */

void FUN_0000b116(void)

{
                    /* WARNING: Subroutine does not return */
  exit(0);
}



/* Function: FUN_0000b71a @ 0000b71a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b71a(void)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  size_t sVar6;
  uint uVar7;
  undefined2 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 *puVar12;
  char *pcVar13;
  char *extraout_r2;
  code *pcVar14;
  undefined4 *extraout_r3;
  undefined4 *extraout_r3_00;
  uint extraout_r3_01;
  uint uVar15;
  uint extraout_r3_02;
  ushort *__src;
  int *piVar16;
  undefined4 *extraout_r3_03;
  void *pvVar17;
  uint extraout_r3_04;
  uint uVar18;
  ushort *unaff_r5;
  uint uVar19;
  undefined4 *puVar20;
  FILE *pFVar21;
  int *piVar22;
  undefined4 uVar23;
  undefined4 *puVar24;
  int iVar25;
  undefined4 *puVar26;
  uint uVar27;
  uint uVar28;
  int unaff_r9;
  char *unaff_r10;
  undefined4 *puVar29;
  char *unaff_r11;
  ushort *extraout_r12;
  ushort *extraout_r12_00;
  undefined8 uVar30;
  void *in_stack_0000002c;
  uint in_stack_00000030;
  undefined4 *in_stack_00000034;
  char *in_stack_00000038;
  char *in_stack_0000003c;
  uint in_stack_00000040;
  uint in_stack_00000048;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  uint in_stack_00000058;
  char *in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000068;
  undefined4 *in_stack_0000006c;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  int *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  ushort *in_stack_000000a0;
  undefined4 *in_stack_000000a4;
  undefined4 *in_stack_000000a8;
  undefined4 *in_stack_000000ac;
  undefined4 *in_stack_000000b0;
  uint in_stack_000000b4;
  uint in_stack_000000b8;
  int in_stack_000000bc;
  int in_stack_00000134;
  
  iVar4 = strcmp((char *)*in_stack_0000006c,(char *)(DAT_0000b830 + 0xb724));
  piVar22 = in_stack_00000098;
  if (iVar4 == 0) {
    if ((in_stack_0000005c != (char *)0x0) &&
       (iVar4 = strcmp(in_stack_0000005c,(char *)(DAT_0000b834 + 0xb738)), iVar4 == 0)) {
      FUN_0000c6a6();
    }
    piVar22 = in_stack_00000098;
    if ((in_stack_0000003c != (char *)0x0) &&
       (iVar4 = strcmp(in_stack_0000003c,(char *)(DAT_0000b838 + 0xb750)),
       piVar22 = in_stack_00000098, iVar4 == 0)) {
      FUN_0000c6a6();
      piVar22 = in_stack_00000098;
    }
  }
  for (; piVar22 != (int *)0x0; piVar22 = (int *)*piVar22) {
    pcVar14 = *(code **)(piVar22[1] + 0x24);
    if (pcVar14 != (code *)0x0) {
      (*pcVar14)(*(undefined4 *)(piVar22[1] + 0x3c));
    }
  }
  if ((in_stack_00000038 != (char *)0x0) && (*(code **)(in_stack_00000038 + 0x24) != (code *)0x0)) {
    (**(code **)(in_stack_00000038 + 0x24))(*(undefined4 *)(in_stack_00000038 + 0x3c));
  }
  if (**(int **)((int)unaff_r5 + in_stack_00000030) < unaff_r9) {
    FUN_0000c86a();
  }
  puVar29 = in_stack_0000009c;
  if (in_stack_0000009c == (undefined4 *)0x0) {
    FUN_0000c84a();
    puVar29 = extraout_r3;
  }
  if (in_stack_000000bc != 0) {
    FUN_0000c85a();
    puVar29 = extraout_r3_00;
  }
  if (((uint)puVar29 & 0x1b) == 0) {
LAB_0000b7ac:
    uVar5 = 0;
    if (in_stack_00000068 != 0) goto LAB_0000b7b2;
  }
  else {
    if (-1 < (int)in_stack_000000a0 << 0x1d) {
      in_stack_00000060 = _LAB_0000bce8 + 0xb9ec;
    }
    if ((int)in_stack_000000a0 << 0x1e < 0) goto LAB_0000b7ac;
    in_stack_00000068 = _LAB_0000bcec + 0xb9f8;
LAB_0000b7b2:
    uVar5 = FUN_0002353c(in_stack_00000068,&stack0x000000b0,&stack0x000000ac,&stack0x000000b8);
  }
  if (in_stack_00000060 != 0) {
    uVar5 = FUN_0002353c(in_stack_00000060,&stack0x000000a8,&stack0x000000a4,&stack0x000000b4);
  }
  uVar19 = in_stack_000000b8;
  if (1 < in_stack_000000b8) goto LAB_0000b7d8;
  while( true ) {
    if (1 < in_stack_000000b4) {
LAB_0000b7d8:
      if ((*(byte *)((int)in_stack_00000034 + 0x53) & 0x18) != 0) {
        FUN_0000c652(uVar5);
        uVar19 = extraout_r3_01;
      }
    }
    __src = in_stack_000000a0;
    puVar29 = in_stack_0000009c;
    if ((in_stack_0000009c != (undefined4 *)0x8) || ((uVar19 == 1 && (in_stack_000000b4 == 1))))
    break;
    (**(code **)(**(int **)((int)unaff_r5 + _LAB_0000bcdc) + 0x14))(2,_LAB_0000bd00 + 0xbcd4);
    uVar5 = (uint)*(ushort *)(extraout_r3_04 + 0x3a);
    uVar19 = extraout_r3_04;
    in_stack_00000040 = extraout_r3_04;
    in_stack_00000048 = extraout_r3_04;
    in_stack_00000058 = extraout_r3_04;
  }
  iVar4 = DAT_0000b83c + 0xb846;
  uVar19 = 0;
  uVar5 = 1;
  do {
    uVar18 = (int)__src >> (uVar19 & 0xff) & uVar5;
    pcVar13 = (char *)(iVar4 + uVar19);
    iVar25 = 0;
    uVar15 = 0;
LAB_0000b852:
    do {
      if (((int)puVar29 >> (uVar15 & 0xff) & uVar5) != 0) {
        if (uVar18 == 0) {
          if (*pcVar13 == '+') {
            uVar5 = FUN_0000c5ee();
            pcVar13 = extraout_r2;
            uVar15 = extraout_r3_02;
            unaff_r5 = extraout_r12;
          }
        }
        else {
          if (*pcVar13 != 'x') {
            uVar15 = uVar15 + 1;
            iVar25 = 1;
            pcVar13 = pcVar13 + 0xc;
            if (uVar15 == 0xf) break;
            goto LAB_0000b852;
          }
          if (iVar25 == 0) {
            iVar25 = -1;
          }
        }
      }
      uVar15 = uVar15 + 1;
      pcVar13 = pcVar13 + 0xc;
    } while (uVar15 != 0xf);
    if (iVar25 == -1) {
      uVar5 = FUN_0000c834();
      unaff_r5 = extraout_r12_00;
    }
    uVar19 = uVar19 + 1;
  } while (uVar19 != 0xc);
  if ((unaff_r11 != (char *)0x0) && (sVar6 = strlen(unaff_r11), 0x1c < sVar6)) {
    FUN_0000c820();
  }
  puVar26 = (undefined4 *)*in_stack_00000050;
  if (puVar26 == (undefined4 *)0x0) {
    puVar26 = (undefined4 *)iptc_init(*in_stack_0000006c);
    *in_stack_00000050 = puVar26;
    puVar29 = in_stack_0000009c;
    if (puVar26 == (undefined4 *)0x0) {
      iVar4 = FUN_00022a4c(**(undefined4 **)((int)unaff_r5 + DAT_0000bfb4),0);
      if (iVar4 != -1) {
        uVar9 = iptc_init(*in_stack_0000006c);
        *in_stack_00000050 = uVar9;
      }
      puVar26 = (undefined4 *)*in_stack_00000050;
      puVar29 = in_stack_0000009c;
      if (puVar26 == (undefined4 *)0x0) {
        FUN_0000c71a();
        puVar29 = in_stack_0000009c;
      }
    }
  }
  if ((((puVar29 == (undefined4 *)0x2) || (puVar29 == (undefined4 *)0x10)) ||
      (puVar29 == (undefined4 *)0x1)) || (pcVar13 = (char *)0x0, puVar29 == (undefined4 *)0x8)) {
    iVar4 = strcmp(unaff_r11,(char *)(_LAB_0000bcf0 + 0xba0e));
    if (((iVar4 == 0) || (iVar4 = strcmp(unaff_r11,(char *)(_LAB_0000bcf4 + 0xba1c)), iVar4 == 0))
       && ((int)in_stack_000000a0 << 0x17 < 0)) {
      FUN_0000c6da();
    }
    iVar4 = strcmp(unaff_r11,(char *)(_LAB_0000bcf8 + 0xba34));
    if (((iVar4 == 0) || (iVar4 = strcmp(unaff_r11,(char *)(_LAB_0000bcfc + 0xba42)), iVar4 == 0))
       && ((int)in_stack_000000a0 << 0x18 < 0)) {
      FUN_0000c6b6();
    }
    if (in_stack_00000038 == (char *)0x0) {
LAB_0000bec2:
      if ((*in_stack_0000003c != '\0') &&
         (iVar4 = iptc_is_chain(in_stack_0000003c,*in_stack_00000050), iVar4 == 0)) {
        if ((int)((uint)*(byte *)((int)in_stack_00000034 + 0x52) << 0x1e) < 0) {
          func_0x0000c740();
        }
        FUN_00021d00(in_stack_0000003c,3);
        in_stack_00000038 = (char *)0x0;
        pcVar13 = (char *)0x0;
        puVar29 = in_stack_0000009c;
        puVar26 = in_stack_00000050;
        goto LAB_0000b8b8;
      }
      in_stack_00000038 = (char *)FUN_00021d00(DAT_0000bfb0 + 0xbee0,3);
      iVar4 = *(int *)(in_stack_00000038 + 0x10);
      puVar8 = (undefined2 *)FUN_00023304(1,iVar4 + 0x20);
      *(undefined2 **)(in_stack_00000038 + 0x38) = puVar8;
      *puVar8 = (short)(iVar4 + 0x20);
      strcpy((char *)(*(int *)(in_stack_00000038 + 0x38) + 2),in_stack_0000003c);
      iVar4 = iptc_is_chain(in_stack_0000003c,*in_stack_00000050);
      if (iVar4 == 0) {
        *(char *)(*(int *)(in_stack_00000038 + 0x38) + 0x1f) = in_stack_00000038[0xc];
      }
      if (*(code **)(in_stack_00000038 + 0x1c) != (code *)0x0) {
        (**(code **)(in_stack_00000038 + 0x1c))(*(undefined4 *)(in_stack_00000038 + 0x38));
      }
    }
    else {
      iVar4 = iptc_is_chain(in_stack_0000003c,puVar26);
      if (iVar4 != 0) {
        fprintf((FILE *)(*(int *)((int)unaff_r5 + DAT_0000bfa8) + 0xa8),
                (char *)(DAT_0000bfac + 0xbeb2),in_stack_0000003c);
        if (*(void **)(in_stack_00000038 + 0x38) != (void *)0x0) {
          free(*(void **)(in_stack_00000038 + 0x38));
        }
        goto LAB_0000bec2;
      }
    }
    piVar22 = in_stack_00000098;
    __src = *(ushort **)(in_stack_00000038 + 0x38);
    if (in_stack_00000098 == (int *)0x0) {
      FUN_0000c48a();
    }
    iVar4 = 0x70;
    piVar16 = piVar22;
    do {
      piVar1 = piVar16 + 1;
      piVar16 = (int *)*piVar16;
      iVar4 = iVar4 + (uint)**(ushort **)(*piVar1 + 0x38);
    } while (piVar16 != (int *)0x0);
    pcVar13 = (char *)FUN_00022ddc(iVar4 + (uint)*__src);
    memcpy(pcVar13,in_stack_00000034,0x70);
    *(short *)(pcVar13 + 0x58) = (short)iVar4;
    *(ushort *)(pcVar13 + 0x5a) = (short)iVar4 + *__src;
    puVar26 = (undefined4 *)0x0;
    do {
      memcpy(pcVar13 + 0x70 + (int)puVar26,*(ushort **)(piVar22[1] + 0x38),
             (uint)**(ushort **)(piVar22[1] + 0x38));
      piVar16 = piVar22 + 1;
      piVar22 = (int *)*piVar22;
      puVar26 = (undefined4 *)((int)puVar26 + (uint)**(ushort **)(*piVar16 + 0x38));
    } while (piVar22 != (int *)0x0);
    memcpy(pcVar13 + 0x70 + (int)puVar26,__src,(uint)*__src);
    free(*(void **)(in_stack_00000038 + 0x38));
    puVar29 = in_stack_0000009c;
  }
LAB_0000b8b8:
  if (puVar29 == (undefined4 *)0xa0) {
LAB_0000bfbc:
    puVar26 = (undefined4 *)*in_stack_00000050;
    puVar29 = (undefined4 *)0x48;
    if (-1 < (int)in_stack_000000a0 << 0x1a) {
      puVar29 = (undefined4 *)0xa;
    }
    if (((uint)in_stack_000000a0 & 1) != 0) {
      puVar29 = (undefined4 *)((uint)puVar29 | 1);
    }
    if (((uint)in_stack_000000a0 & 0x40) == 0) {
      puVar29 = (undefined4 *)((uint)puVar29 | 4);
    }
    if (((uint)in_stack_000000a0 & 0x400) != 0) {
      puVar29 = (undefined4 *)((uint)puVar29 | 0x100);
    }
    pcVar10 = (char *)iptc_first_chain(puVar26);
    if (pcVar10 != (char *)0x0) {
      in_stack_0000002c = (void *)(uint)(in_stack_00000048 == 0);
      in_stack_00000040 = (uint)puVar29 & 0x100;
      in_stack_00000038 = (char *)(DAT_0000c340 + 0xc028);
      iVar4 = 0;
      do {
        if ((unaff_r11 == (char *)0x0) || (iVar25 = strcmp(unaff_r11,pcVar10), iVar25 == 0)) {
          if (iVar4 != 0) {
            putchar(10);
          }
          if (in_stack_00000048 == 0) {
            iVar4 = iptc_get_policy(pcVar10,&stack0x00000078,puVar26);
            printf(in_stack_00000038,pcVar10);
            if (iVar4 == 0) {
              iVar4 = iptc_get_references(&stack0x00000094,pcVar10,puVar26);
              if (iVar4 == 0) {
                puts((char *)(DAT_0000c76c + 0xc4d4));
                in_stack_00000030 = DAT_0000c770;
              }
              else {
                printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
                in_stack_00000030 = iRam0000c8f4;
              }
            }
            else {
              printf((char *)(DAT_0000c344 + 0xc10c));
              if ((int)puVar29 << 0x1e < 0) {
                in_stack_00000030 = DAT_0000c348;
              }
              else {
                in_stack_00000030 = DAT_0000c770;
                pFVar21 = (FILE *)(*(int *)((int)unaff_r5 + DAT_0000c770) + 0x54);
                fputc(0x20,pFVar21);
                FUN_0000a018(in_stack_00000078,in_stack_0000007c,(uint)puVar29 | 0x10);
                fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar21);
                FUN_0000a018(in_stack_00000080,in_stack_00000084,(uint)puVar29 | 0x10);
                fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar21);
              }
              puts((char *)(DAT_0000c34c + 0xc11e));
            }
            if (in_stack_00000040 != 0) {
              if ((int)puVar29 << 0x1b < 0) {
                pcVar11 = (char *)(DAT_0000c768 + 0xc4be);
              }
              else {
                pcVar11 = (char *)(DAT_0000c350 + 0xc132);
              }
              printf(pcVar11,DAT_0000c354 + 0xc136);
            }
            if (-1 < (int)puVar29 << 0x1e) {
              if ((int)puVar29 << 0x1d < 0) {
                if ((int)puVar29 << 0x1b < 0) {
                  pcVar11 = (char *)(DAT_0000c358 + 0xc150);
                  printf(pcVar11,DAT_0000c35c + 0xc152);
                }
                else {
                  pcVar11 = (char *)(DAT_0000c77c + 0xc530);
                  printf(pcVar11,DAT_0000c780 + 0xc532);
                }
                printf(pcVar11,DAT_0000c360 + 0xc15e);
              }
              else {
                if ((int)puVar29 << 0x1b < 0) {
                  pcVar14 = (code *)(DAT_0000c784 + 0xc546);
                  printf((char *)pcVar14,DAT_0000c788 + 0xc548);
                }
                else {
                  printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
                  pcVar14 = FUN_0000c61e + DAT_0000c7b0;
                }
                printf((char *)pcVar14,DAT_0000c78c + 0xc554);
              }
            }
            if (-1 < (int)puVar29 << 0x1a) {
              if ((int)puVar29 << 0x1b < 0) {
                pcVar11 = (char *)(DAT_0000c75c + 0xc478);
              }
              else {
                pcVar11 = (char *)(DAT_0000c364 + 0xc170);
              }
              printf(pcVar11,DAT_0000c368 + 0xc174);
            }
            pFVar21 = (FILE *)(*(int *)((int)unaff_r5 + in_stack_00000030) + 0x54);
            fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar21);
            if ((int)puVar29 << 0x1c < 0) {
              fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar21);
            }
            if ((int)puVar29 << 0x19 < 0) {
              if ((int)puVar29 << 0x1b < 0) {
                pcVar11 = (char *)(DAT_0000c760 + 0xc480);
                printf(pcVar11,DAT_0000c764 + 0xc482);
              }
              else {
                printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
                pcVar11 = (char *)(DAT_0000c37c + 0xc1ba);
              }
              printf(pcVar11,DAT_0000c380 + 0xc1be);
            }
            if ((int)puVar29 << 0x1b < 0) {
              printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
              pcVar11 = (char *)(DAT_0000c38c + 0xc1d8);
            }
            else {
LAB_0000c410:
              pcVar11 = (char *)(iRam0000c754 + 0xc418);
              printf(pcVar11,DAT_0000c758 + 0xc41a);
            }
            printf(pcVar11,DAT_0000c390 + 0xc1dc);
            putchar(10);
          }
          iVar4 = iptc_first_rule(pcVar10,puVar26);
          if (iVar4 != 0) {
            uVar5 = 0;
            do {
              uVar5 = uVar5 + 1;
              if ((in_stack_00000048 == uVar5) || (in_stack_0000002c != (void *)0x0)) {
                uVar9 = iptc_get_target(iVar4,puVar26);
                FUN_0000a3f0(iVar4,uVar9,uVar5,puVar29);
              }
              iVar4 = iptc_next_rule(iVar4,puVar26);
            } while (iVar4 != 0);
          }
          iVar4 = 1;
        }
        pcVar10 = (char *)iptc_next_chain(puVar26);
      } while (pcVar10 != (char *)0x0);
      uVar30 = __errno();
      *(undefined4 *)uVar30 = 2;
      if (iVar4 != 0) {
joined_r0x0000bc12:
        if (((int)in_stack_0000009c << 0x18 < 0) && (iVar4 = FUN_0000acf0(), iVar4 == 0)) {
          FUN_0000bc28();
          return;
        }
        if ((int)in_stack_0000009c << 0x12 < 0) {
          iVar4 = iptc_zero_counter();
        }
        piVar22 = in_stack_00000098;
        if (1 < in_stack_00000054) {
          dump_entries(*in_stack_00000050);
          piVar22 = in_stack_00000098;
        }
        while (piVar22 != (int *)0x0) {
          pvVar17 = (void *)piVar22[1];
          piVar16 = (int *)*piVar22;
          if (*(void **)((int)pvVar17 + 0x38) != (void *)0x0) {
            free(*(void **)((int)pvVar17 + 0x38));
            *(undefined4 *)(piVar22[1] + 0x38) = 0;
            pvVar17 = (void *)piVar22[1];
          }
          if (pvVar17 == *(void **)((int)pvVar17 + 4)) {
            free(pvVar17);
            piVar22[1] = 0;
          }
          free(piVar22);
          piVar22 = piVar16;
        }
        in_stack_00000098 = (int *)0x0;
        if (pcVar13 != (char *)0x0) {
          free(pcVar13);
        }
        free(in_stack_000000b0);
        free(in_stack_000000ac);
        free(in_stack_000000a8);
        free(in_stack_000000a4);
        FUN_00021f14(1);
        if (in_stack_00000134 == **(int **)((int)unaff_r5 + in_stack_00000058)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(iVar4);
      }
      goto LAB_0000bea0;
    }
  }
  else {
    if (puVar29 < (undefined4 *)0xa1) {
      if (puVar29 == (undefined4 *)0x8) {
        FUN_0000c422();
      }
      uVar19 = in_stack_000000b8;
      uVar5 = in_stack_000000b4;
      puVar12 = in_stack_000000b0;
      puVar3 = in_stack_000000a8;
      puVar26 = in_stack_000000a4;
      piVar22 = in_stack_00000098;
      if (puVar29 < (undefined4 *)0x9) {
        if (puVar29 == (undefined4 *)0x2) {
          uVar15 = (uint)in_stack_000000a0 & 0x20;
          in_stack_0000003c = (char *)in_stack_000000ac;
          if (in_stack_00000098 == (int *)0x0) {
            in_stack_0000002c = (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x90);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar17 = (void *)((int)in_stack_0000002c + 0x70);
          }
          else {
            iVar4 = 0x70;
            piVar16 = in_stack_00000098;
            do {
              piVar1 = piVar16 + 1;
              piVar16 = (int *)*piVar16;
              iVar4 = iVar4 + *(int *)(*piVar1 + 0x10) + 0x20;
            } while (piVar16 != (int *)0x0);
            in_stack_0000002c =
                 (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x20 + iVar4);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar17 = (void *)((int)in_stack_0000002c + 0x70);
            do {
              memset(pvVar17,0xff,*(int *)(piVar22[1] + 0x14) + 0x20);
              piVar16 = piVar22 + 1;
              piVar22 = (int *)*piVar22;
              pvVar17 = (void *)((int)pvVar17 + *(int *)(*piVar16 + 0x10) + 0x20);
            } while (piVar22 != (int *)0x0);
          }
          memset(pvVar17,0xff,*(int *)(in_stack_00000038 + 0x14) + 0x20);
          if (uVar19 != 0) {
            in_stack_00000038 = (char *)puVar12;
            in_stack_00000034 = (undefined4 *)0x0;
            do {
              uVar9 = *(undefined4 *)in_stack_00000038;
              in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
              *(undefined4 *)pcVar13 = uVar9;
              uVar9 = *(undefined4 *)in_stack_0000003c;
              in_stack_0000003c = (char *)((int)in_stack_0000003c + 4);
              *(undefined4 *)(pcVar13 + 8) = uVar9;
              if (uVar5 != 0) {
                uVar18 = 0;
                puVar29 = puVar26;
                puVar12 = puVar3;
                do {
                  uVar9 = *puVar12;
                  puVar12 = puVar12 + 1;
                  *(undefined4 *)(pcVar13 + 4) = uVar9;
                  uVar9 = *puVar29;
                  puVar29 = puVar29 + 1;
                  *(undefined4 *)(pcVar13 + 0xc) = uVar9;
                  if (uVar15 != 0) {
                    FUN_0000a3f0(pcVar13,pcVar13 + *(ushort *)(pcVar13 + 0x58) + 2,0,0x5b);
                  }
                  iptc_delete_entry();
                  uVar18 = uVar18 + 1;
                } while (uVar18 != uVar5);
              }
              in_stack_00000034 = (undefined4 *)((int)in_stack_00000034 + 1);
            } while (in_stack_00000034 != (undefined4 *)uVar19);
          }
          free(in_stack_0000002c);
          FUN_0000bc28();
          return;
        }
        if (puVar29 == (undefined4 *)0x4) {
          iptc_delete_num_entry();
          FUN_0000bc28();
          return;
        }
        if (puVar29 == (undefined4 *)0x1) {
          uVar15 = (uint)in_stack_000000a0 & 0x20;
          puVar29 = (undefined4 *)0x1;
          if (in_stack_000000b8 != 0) {
            in_stack_0000003c = (char *)in_stack_000000b0;
            in_stack_00000038 = (char *)in_stack_000000ac;
            in_stack_00000034 = (undefined4 *)0x0;
            puVar12 = in_stack_000000ac;
            do {
              uVar9 = *(undefined4 *)in_stack_0000003c;
              in_stack_0000003c = (char *)((int)in_stack_0000003c + 4);
              *(undefined4 *)pcVar13 = uVar9;
              uVar9 = *(undefined4 *)in_stack_00000038;
              in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
              *(undefined4 *)(pcVar13 + 8) = uVar9;
              uVar18 = 0;
              if (uVar5 != 0) {
                uVar28 = 0;
                puVar20 = puVar26;
                puVar24 = puVar3;
                puVar12 = puVar29;
                do {
                  uVar9 = *puVar24;
                  puVar24 = puVar24 + 1;
                  *(undefined4 *)(pcVar13 + 4) = uVar9;
                  uVar9 = *puVar20;
                  puVar20 = puVar20 + 1;
                  *(undefined4 *)(pcVar13 + 0xc) = uVar9;
                  if (uVar15 != 0) {
                    FUN_0000a3f0(pcVar13,pcVar13 + *(ushort *)(pcVar13 + 0x58) + 2,0,0x5b);
                  }
                  uVar18 = iptc_insert_entry();
                  puVar12 = (undefined4 *)((uint)puVar12 & uVar18);
                  uVar28 = uVar28 + 1;
                  puVar29 = puVar12;
                } while (uVar28 != uVar5);
              }
              in_stack_00000034 = (undefined4 *)((int)in_stack_00000034 + 1);
            } while (in_stack_00000034 != (undefined4 *)uVar19);
            FUN_0000bc28(uVar18,puVar12);
            return;
          }
          FUN_0000bc28();
          return;
        }
LAB_0000bd98:
                    /* WARNING: Subroutine does not return */
        FUN_0000a2c4(2);
      }
      if (puVar29 != (undefined4 *)0x20) {
        if ((undefined4 *)0x20 < puVar29) {
          FUN_0000c310();
        }
        uVar19 = in_stack_000000b8;
        uVar5 = in_stack_000000b4;
        puVar3 = in_stack_000000a8;
        puVar26 = in_stack_000000a4;
        if (puVar29 == (undefined4 *)0x10) {
          uVar18 = (uint)in_stack_000000a0 & 0x20;
          uVar15 = 1;
          if (in_stack_000000b8 != 0) {
            in_stack_00000034 = in_stack_000000ac;
            in_stack_00000038 = (char *)in_stack_000000b0;
            in_stack_00000030 = 0;
            uVar28 = in_stack_000000b8;
            do {
              uVar9 = *(undefined4 *)in_stack_00000038;
              in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
              *(undefined4 *)pcVar13 = uVar9;
              uVar9 = *in_stack_00000034;
              in_stack_00000034 = in_stack_00000034 + 1;
              *(undefined4 *)(pcVar13 + 8) = uVar9;
              if (uVar5 == 0) {
                uVar7 = 0;
              }
              else {
                uVar27 = 0;
                puVar29 = puVar26;
                puVar12 = puVar3;
                uVar28 = uVar15;
                do {
                  uVar9 = *puVar12;
                  puVar12 = puVar12 + 1;
                  *(undefined4 *)(pcVar13 + 4) = uVar9;
                  uVar9 = *puVar29;
                  puVar29 = puVar29 + 1;
                  *(undefined4 *)(pcVar13 + 0xc) = uVar9;
                  if (uVar18 != 0) {
                    FUN_0000a3f0(pcVar13,pcVar13 + *(ushort *)(pcVar13 + 0x58) + 2,0,0x5b);
                  }
                  uVar7 = iptc_append_entry();
                  uVar28 = uVar28 & uVar7;
                  uVar27 = uVar27 + 1;
                  uVar15 = uVar28;
                } while (uVar27 != uVar5);
              }
              in_stack_00000030 = in_stack_00000030 + 1;
            } while (in_stack_00000030 != uVar19);
            FUN_0000bc28(uVar7,uVar28);
            return;
          }
          FUN_0000bc28();
          return;
        }
        goto LAB_0000bd98;
      }
      goto LAB_0000bfbc;
    }
    if (puVar29 != (undefined4 *)0x1000) {
      if (puVar29 < (undefined4 *)0x1001) {
        if (puVar29 == (undefined4 *)0x200) {
LAB_0000c3b8:
          delete_chain();
          FUN_0000bc28();
          puVar26 = in_stack_00000050;
        }
        else {
          if ((undefined4 *)0x200 < puVar29) {
            if (puVar29 == (undefined4 *)0x400) goto LAB_0000c3f4;
            if (puVar29 != (undefined4 *)0x800) goto LAB_0000bd98;
            iptc_rename_chain();
            FUN_0000bc28();
            goto LAB_0000c3b8;
          }
          if (puVar29 != (undefined4 *)0x100) goto LAB_0000bd98;
        }
        iptc_create_chain();
        FUN_0000bc28();
        flush_entries();
        FUN_0000bc28();
        puVar29 = in_stack_00000050;
LAB_0000c3f4:
        in_stack_00000048 = iptc_set_policy();
        FUN_0000bc28();
        pcVar10 = pcVar13;
        unaff_r5 = __src;
        pcVar13 = unaff_r10;
        goto LAB_0000c410;
      }
      puVar26 = (undefined4 *)0x2000;
      if (puVar29 == (undefined4 *)0x2000) {
        FUN_0000c32e();
        puVar26 = extraout_r3_03;
      }
      if (puVar26 < puVar29) {
        if (puVar29 == DAT_0000bfb8) goto LAB_0000bfbc;
        if (puVar29 != (undefined4 *)0x3000) goto LAB_0000bd98;
      }
      else if (puVar29 != (undefined4 *)0x1080) goto LAB_0000bd98;
    }
    uVar23 = *in_stack_00000050;
    uVar9 = 0;
    if (((uint)in_stack_000000a0 & 0x20) != 0) {
      uVar9 = 0xffffffff;
    }
    if (in_stack_00000048 == 0) {
      FUN_0000c558();
    }
    pcVar10 = (char *)iptc_first_chain(uVar23);
    if (pcVar10 != (char *)0x0) {
      bVar2 = false;
      do {
        if ((unaff_r11 == (char *)0x0) || (iVar4 = strcmp(pcVar10,unaff_r11), iVar4 == 0)) {
          iVar4 = iptc_first_rule(pcVar10,uVar23);
          if (iVar4 != 0) {
            uVar5 = 0;
            do {
              uVar5 = uVar5 + 1;
              if ((in_stack_00000048 == uVar5) || (in_stack_00000048 == 0)) {
                FUN_0000a9b0(iVar4,uVar23,pcVar10,uVar9);
              }
              iVar4 = iptc_next_rule(iVar4,uVar23);
            } while (iVar4 != 0);
          }
          bVar2 = true;
        }
        pcVar10 = (char *)iptc_next_chain(uVar23);
      } while (pcVar10 != (char *)0x0);
      uVar30 = __errno();
      *(undefined4 *)uVar30 = 2;
      if (bVar2) {
        iVar4 = 1;
        goto joined_r0x0000bc12;
      }
      goto LAB_0000bea0;
    }
  }
  uVar30 = __errno();
  *(undefined4 *)uVar30 = 2;
LAB_0000bea0:
  FUN_0000bc28((int)uVar30,(int)((ulonglong)uVar30 >> 0x20),0);
  return;
}



/* Function: FUN_0000b97c @ 0000b97c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b97c(void)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  uint uVar4;
  size_t sVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *extraout_r2;
  uint extraout_r3;
  int iVar12;
  uint uVar13;
  uint extraout_r3_00;
  ushort *__src;
  undefined4 *extraout_r3_01;
  void *pvVar14;
  uint extraout_r3_02;
  uint uVar15;
  int unaff_r4;
  void *pvVar16;
  uint uVar17;
  int unaff_r5;
  undefined4 *puVar18;
  FILE *pFVar19;
  code *__format;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined4 uVar22;
  undefined4 *puVar23;
  int iVar24;
  undefined4 *puVar25;
  uint uVar26;
  int unaff_r7;
  uint uVar27;
  ushort *unaff_r9;
  char *unaff_r10;
  ushort *extraout_r12;
  ushort *extraout_r12_00;
  undefined8 uVar28;
  void *in_stack_0000002c;
  uint in_stack_00000030;
  undefined4 *in_stack_00000034;
  char *in_stack_00000038;
  char *in_stack_0000003c;
  uint in_stack_00000040;
  uint in_stack_00000048;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  uint in_stack_00000058;
  undefined4 in_stack_0000005c;
  int in_stack_00000060;
  undefined4 in_stack_00000064;
  int in_stack_00000068;
  undefined4 *in_stack_0000006c;
  char *in_stack_00000070;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  ushort *in_stack_000000a0;
  undefined4 *in_stack_000000a4;
  undefined4 *in_stack_000000a8;
  undefined4 *in_stack_000000ac;
  undefined4 *in_stack_000000b0;
  uint in_stack_000000b4;
  uint in_stack_000000b8;
  int in_stack_00000134;
  
  if (*(int *)(unaff_r7 + 4) == 0) {
    FUN_0000afa8();
  }
  else {
    FUN_0000b0f8();
  }
  if (unaff_r4 != 0x3f) {
    FUN_0000c63c();
  }
  if (**(int **)((int)unaff_r9 + _LAB_0000bcd8) == 0) {
    FUN_0000c61e();
  }
  (**(code **)(**(int **)((int)unaff_r9 + _LAB_0000bcdc) + 0x14))
            (2,_LAB_0000bce0 + 0xb9c4,
             *(undefined4 *)((**(int **)((int)unaff_r9 + in_stack_00000030) + -1) * 4 + unaff_r5));
  printf((char *)(_LAB_0000bce4 + 0xb9d8),
         *(undefined4 *)(*(int *)((int)unaff_r9 + (int)in_stack_0000002c) + 8));
  FUN_0000b116();
  if (-1 < (int)in_stack_000000a0 << 0x1d) {
    in_stack_00000060 = _LAB_0000bce8 + 0xb9ec;
  }
  if ((int)in_stack_000000a0 << 0x1e < 0) {
    uVar4 = 0;
    if (in_stack_00000068 != 0) goto LAB_0000b7b2;
  }
  else {
    in_stack_00000068 = _LAB_0000bcec + 0xb9f8;
LAB_0000b7b2:
    uVar4 = FUN_0002353c(in_stack_00000068,&stack0x000000b0,&stack0x000000ac,&stack0x000000b8);
  }
  if (in_stack_00000060 != 0) {
    uVar4 = FUN_0002353c(in_stack_00000060,&stack0x000000a8,&stack0x000000a4,&stack0x000000b4);
  }
  uVar17 = in_stack_000000b8;
  if (1 < in_stack_000000b8) goto LAB_0000b7d8;
  while( true ) {
    if (1 < in_stack_000000b4) {
LAB_0000b7d8:
      if ((*(byte *)((int)in_stack_00000034 + 0x53) & 0x18) != 0) {
        FUN_0000c652(uVar4);
        uVar17 = extraout_r3;
      }
    }
    __src = in_stack_000000a0;
    puVar21 = in_stack_0000009c;
    if ((in_stack_0000009c != (undefined4 *)0x8) || ((uVar17 == 1 && (in_stack_000000b4 == 1))))
    break;
    (**(code **)(**(int **)((int)unaff_r9 + _LAB_0000bcdc) + 0x14))(2,_LAB_0000bd00 + 0xbcd4);
    uVar4 = (uint)*(ushort *)(extraout_r3_02 + 0x3a);
    uVar17 = extraout_r3_02;
    in_stack_00000040 = extraout_r3_02;
    in_stack_00000048 = extraout_r3_02;
    in_stack_00000058 = extraout_r3_02;
  }
  iVar12 = DAT_0000b83c + 0xb846;
  uVar17 = 0;
  uVar4 = 1;
  do {
    uVar15 = (int)__src >> (uVar17 & 0xff) & uVar4;
    pcVar11 = (char *)(iVar12 + uVar17);
    iVar24 = 0;
    uVar13 = 0;
LAB_0000b852:
    do {
      if (((int)puVar21 >> (uVar13 & 0xff) & uVar4) != 0) {
        if (uVar15 == 0) {
          if (*pcVar11 == '+') {
            uVar4 = FUN_0000c5ee();
            pcVar11 = extraout_r2;
            uVar13 = extraout_r3_00;
            unaff_r9 = extraout_r12;
          }
        }
        else {
          if (*pcVar11 != 'x') {
            uVar13 = uVar13 + 1;
            iVar24 = 1;
            pcVar11 = pcVar11 + 0xc;
            if (uVar13 == 0xf) break;
            goto LAB_0000b852;
          }
          if (iVar24 == 0) {
            iVar24 = -1;
          }
        }
      }
      uVar13 = uVar13 + 1;
      pcVar11 = pcVar11 + 0xc;
    } while (uVar13 != 0xf);
    if (iVar24 == -1) {
      uVar4 = FUN_0000c834();
      unaff_r9 = extraout_r12_00;
    }
    uVar17 = uVar17 + 1;
  } while (uVar17 != 0xc);
  if ((in_stack_00000070 != (char *)0x0) && (sVar5 = strlen(in_stack_00000070), 0x1c < sVar5)) {
    FUN_0000c820();
  }
  puVar25 = (undefined4 *)*in_stack_00000050;
  if (puVar25 == (undefined4 *)0x0) {
    puVar25 = (undefined4 *)iptc_init(*in_stack_0000006c);
    *in_stack_00000050 = puVar25;
    puVar21 = in_stack_0000009c;
    if (puVar25 == (undefined4 *)0x0) {
      iVar12 = FUN_00022a4c(**(undefined4 **)((int)unaff_r9 + DAT_0000bfb4),0);
      if (iVar12 != -1) {
        uVar8 = iptc_init(*in_stack_0000006c);
        *in_stack_00000050 = uVar8;
      }
      puVar25 = (undefined4 *)*in_stack_00000050;
      puVar21 = in_stack_0000009c;
      if (puVar25 == (undefined4 *)0x0) {
        FUN_0000c71a();
        puVar21 = in_stack_0000009c;
      }
    }
  }
  if ((((puVar21 == (undefined4 *)0x2) || (puVar21 == (undefined4 *)0x10)) ||
      (puVar21 == (undefined4 *)0x1)) || (pcVar11 = (char *)0x0, puVar21 == (undefined4 *)0x8)) {
    iVar12 = strcmp(in_stack_00000070,(char *)(_LAB_0000bcf0 + 0xba0e));
    if (((iVar12 == 0) ||
        (iVar12 = strcmp(in_stack_00000070,(char *)(_LAB_0000bcf4 + 0xba1c)), iVar12 == 0)) &&
       ((int)in_stack_000000a0 << 0x17 < 0)) {
      FUN_0000c6da();
    }
    iVar12 = strcmp(in_stack_00000070,(char *)(_LAB_0000bcf8 + 0xba34));
    if (((iVar12 == 0) ||
        (iVar12 = strcmp(in_stack_00000070,(char *)(_LAB_0000bcfc + 0xba42)), iVar12 == 0)) &&
       ((int)in_stack_000000a0 << 0x18 < 0)) {
      FUN_0000c6b6();
    }
    if (in_stack_00000038 == (char *)0x0) {
LAB_0000bec2:
      if ((*in_stack_0000003c != '\0') &&
         (iVar12 = iptc_is_chain(in_stack_0000003c,*in_stack_00000050), iVar12 == 0)) {
        if ((int)((uint)*(byte *)((int)in_stack_00000034 + 0x52) << 0x1e) < 0) {
          func_0x0000c740();
        }
        FUN_00021d00(in_stack_0000003c,3);
        in_stack_00000038 = (char *)0x0;
        pcVar11 = (char *)0x0;
        puVar21 = in_stack_0000009c;
        puVar25 = in_stack_00000050;
        goto LAB_0000b8b8;
      }
      in_stack_00000038 = (char *)FUN_00021d00(DAT_0000bfb0 + 0xbee0,3);
      iVar12 = *(int *)(in_stack_00000038 + 0x10);
      puVar7 = (undefined2 *)FUN_00023304(1,iVar12 + 0x20);
      *(undefined2 **)(in_stack_00000038 + 0x38) = puVar7;
      *puVar7 = (short)(iVar12 + 0x20);
      strcpy((char *)(*(int *)(in_stack_00000038 + 0x38) + 2),in_stack_0000003c);
      iVar12 = iptc_is_chain(in_stack_0000003c,*in_stack_00000050);
      if (iVar12 == 0) {
        *(char *)(*(int *)(in_stack_00000038 + 0x38) + 0x1f) = in_stack_00000038[0xc];
      }
      if (*(code **)(in_stack_00000038 + 0x1c) != (code *)0x0) {
        (**(code **)(in_stack_00000038 + 0x1c))(*(undefined4 *)(in_stack_00000038 + 0x38));
      }
    }
    else {
      iVar12 = iptc_is_chain(in_stack_0000003c,puVar25);
      if (iVar12 != 0) {
        fprintf((FILE *)(*(int *)((int)unaff_r9 + DAT_0000bfa8) + 0xa8),
                (char *)(DAT_0000bfac + 0xbeb2),in_stack_0000003c);
        if (*(void **)(in_stack_00000038 + 0x38) != (void *)0x0) {
          free(*(void **)(in_stack_00000038 + 0x38));
        }
        goto LAB_0000bec2;
      }
    }
    puVar21 = in_stack_00000098;
    __src = *(ushort **)(in_stack_00000038 + 0x38);
    if (in_stack_00000098 == (undefined4 *)0x0) {
      FUN_0000c48a();
    }
    iVar12 = 0x70;
    puVar25 = puVar21;
    do {
      piVar1 = puVar25 + 1;
      puVar25 = (undefined4 *)*puVar25;
      iVar12 = iVar12 + (uint)**(ushort **)(*piVar1 + 0x38);
    } while (puVar25 != (undefined4 *)0x0);
    pcVar11 = (char *)FUN_00022ddc(iVar12 + (uint)*__src);
    memcpy(pcVar11,in_stack_00000034,0x70);
    *(short *)(pcVar11 + 0x58) = (short)iVar12;
    *(ushort *)(pcVar11 + 0x5a) = (short)iVar12 + *__src;
    puVar25 = (undefined4 *)0x0;
    do {
      memcpy(pcVar11 + 0x70 + (int)puVar25,*(ushort **)(puVar21[1] + 0x38),
             (uint)**(ushort **)(puVar21[1] + 0x38));
      piVar1 = puVar21 + 1;
      puVar21 = (undefined4 *)*puVar21;
      puVar25 = (undefined4 *)((int)puVar25 + (uint)**(ushort **)(*piVar1 + 0x38));
    } while (puVar21 != (undefined4 *)0x0);
    memcpy(pcVar11 + 0x70 + (int)puVar25,__src,(uint)*__src);
    free(*(void **)(in_stack_00000038 + 0x38));
    puVar21 = in_stack_0000009c;
  }
LAB_0000b8b8:
  if (puVar21 == (undefined4 *)0xa0) {
LAB_0000bfbc:
    puVar25 = (undefined4 *)*in_stack_00000050;
    puVar21 = (undefined4 *)0x48;
    if (-1 < (int)in_stack_000000a0 << 0x1a) {
      puVar21 = (undefined4 *)0xa;
    }
    if (((uint)in_stack_000000a0 & 1) != 0) {
      puVar21 = (undefined4 *)((uint)puVar21 | 1);
    }
    if (((uint)in_stack_000000a0 & 0x40) == 0) {
      puVar21 = (undefined4 *)((uint)puVar21 | 4);
    }
    if (((uint)in_stack_000000a0 & 0x400) != 0) {
      puVar21 = (undefined4 *)((uint)puVar21 | 0x100);
    }
    pcVar9 = (char *)iptc_first_chain(puVar25);
    if (pcVar9 != (char *)0x0) {
      in_stack_0000002c = (void *)(uint)(in_stack_00000048 == 0);
      in_stack_00000040 = (uint)puVar21 & 0x100;
      in_stack_00000038 = (char *)(DAT_0000c340 + 0xc028);
      iVar12 = 0;
      uVar4 = in_stack_00000048;
      do {
        if ((in_stack_00000070 == (char *)0x0) ||
           (iVar24 = strcmp(in_stack_00000070,pcVar9), iVar24 == 0)) {
          if (iVar12 != 0) {
            putchar(10);
          }
          if (uVar4 == 0) {
            iVar12 = iptc_get_policy(pcVar9,&stack0x00000078,puVar25);
            printf(in_stack_00000038,pcVar9);
            if (iVar12 == 0) {
              iVar12 = iptc_get_references(&stack0x00000094,pcVar9,puVar25);
              if (iVar12 == 0) {
                puts((char *)(DAT_0000c76c + 0xc4d4));
                in_stack_00000030 = DAT_0000c770;
              }
              else {
                printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
                in_stack_00000030 = iRam0000c8f4;
              }
            }
            else {
              printf((char *)(DAT_0000c344 + 0xc10c));
              if ((int)puVar21 << 0x1e < 0) {
                in_stack_00000030 = DAT_0000c348;
              }
              else {
                in_stack_00000030 = DAT_0000c770;
                pFVar19 = (FILE *)(*(int *)((int)unaff_r9 + DAT_0000c770) + 0x54);
                fputc(0x20,pFVar19);
                FUN_0000a018(in_stack_00000078,in_stack_0000007c,(uint)puVar21 | 0x10);
                fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar19);
                FUN_0000a018(in_stack_00000080,in_stack_00000084,(uint)puVar21 | 0x10);
                fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar19);
              }
              puts((char *)(DAT_0000c34c + 0xc11e));
            }
            if (in_stack_00000040 != 0) {
              if ((int)puVar21 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c768 + 0xc4be);
              }
              else {
                pcVar10 = (char *)(DAT_0000c350 + 0xc132);
              }
              printf(pcVar10,DAT_0000c354 + 0xc136);
            }
            if (-1 < (int)puVar21 << 0x1e) {
              if ((int)puVar21 << 0x1d < 0) {
                if ((int)puVar21 << 0x1b < 0) {
                  pcVar10 = (char *)(DAT_0000c358 + 0xc150);
                  printf(pcVar10,DAT_0000c35c + 0xc152);
                }
                else {
                  pcVar10 = (char *)(DAT_0000c77c + 0xc530);
                  printf(pcVar10,DAT_0000c780 + 0xc532);
                }
                printf(pcVar10,DAT_0000c360 + 0xc15e);
              }
              else {
                if ((int)puVar21 << 0x1b < 0) {
                  __format = (code *)(DAT_0000c784 + 0xc546);
                  printf((char *)__format,DAT_0000c788 + 0xc548);
                }
                else {
                  printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
                  __format = FUN_0000c61e + DAT_0000c7b0;
                }
                printf((char *)__format,DAT_0000c78c + 0xc554);
              }
            }
            if (-1 < (int)puVar21 << 0x1a) {
              if ((int)puVar21 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c75c + 0xc478);
              }
              else {
                pcVar10 = (char *)(DAT_0000c364 + 0xc170);
              }
              printf(pcVar10,DAT_0000c368 + 0xc174);
            }
            pFVar19 = (FILE *)(*(int *)((int)unaff_r9 + in_stack_00000030) + 0x54);
            fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar19);
            if ((int)puVar21 << 0x1c < 0) {
              fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar19);
            }
            if ((int)puVar21 << 0x19 < 0) {
              if ((int)puVar21 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c760 + 0xc480);
                printf(pcVar10,DAT_0000c764 + 0xc482);
              }
              else {
                printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
                pcVar10 = (char *)(DAT_0000c37c + 0xc1ba);
              }
              printf(pcVar10,DAT_0000c380 + 0xc1be);
            }
            if ((int)puVar21 << 0x1b < 0) {
              printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
              pcVar10 = (char *)(DAT_0000c38c + 0xc1d8);
            }
            else {
LAB_0000c410:
              pcVar10 = (char *)(iRam0000c754 + 0xc418);
              printf(pcVar10,DAT_0000c758 + 0xc41a);
            }
            printf(pcVar10,DAT_0000c390 + 0xc1dc);
            putchar(10);
          }
          iVar12 = iptc_first_rule(pcVar9,puVar25);
          if (iVar12 != 0) {
            uVar17 = 0;
            do {
              uVar17 = uVar17 + 1;
              if ((uVar4 == uVar17) || (in_stack_0000002c != (void *)0x0)) {
                uVar8 = iptc_get_target(iVar12,puVar25);
                FUN_0000a3f0(iVar12,uVar8,uVar17,puVar21);
              }
              iVar12 = iptc_next_rule(iVar12,puVar25);
            } while (iVar12 != 0);
          }
          iVar12 = 1;
        }
        pcVar9 = (char *)iptc_next_chain(puVar25);
      } while (pcVar9 != (char *)0x0);
      uVar28 = __errno();
      *(undefined4 *)uVar28 = 2;
      if (iVar12 != 0) {
joined_r0x0000bc12:
        if (((int)in_stack_0000009c << 0x18 < 0) &&
           (iVar12 = FUN_0000acf0(in_stack_00000070,(uint)in_stack_000000a0 & 0x20,
                                  *in_stack_00000050), iVar12 == 0)) {
          FUN_0000bc28();
          return;
        }
        if ((int)in_stack_0000009c << 0x12 < 0) {
          iVar12 = iptc_zero_counter(in_stack_00000070,in_stack_00000048,*in_stack_00000050);
        }
        puVar21 = in_stack_00000098;
        if (1 < in_stack_00000054) {
          dump_entries(*in_stack_00000050);
          puVar21 = in_stack_00000098;
        }
        while (puVar21 != (void *)0x0) {
          pvVar14 = (void *)puVar21[1];
          pvVar16 = (void *)*puVar21;
          if (*(void **)((int)pvVar14 + 0x38) != (void *)0x0) {
            free(*(void **)((int)pvVar14 + 0x38));
            *(undefined4 *)(puVar21[1] + 0x38) = 0;
            pvVar14 = (void *)puVar21[1];
          }
          if (pvVar14 == *(void **)((int)pvVar14 + 4)) {
            free(pvVar14);
            puVar21[1] = 0;
          }
          free(puVar21);
          puVar21 = pvVar16;
        }
        in_stack_00000098 = (undefined4 *)0x0;
        if (pcVar11 != (char *)0x0) {
          free(pcVar11);
        }
        free(in_stack_000000b0);
        free(in_stack_000000ac);
        free(in_stack_000000a8);
        free(in_stack_000000a4);
        FUN_00021f14(1);
        if (in_stack_00000134 == **(int **)((int)unaff_r9 + in_stack_00000058)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(iVar12);
      }
      goto LAB_0000bea0;
    }
  }
  else {
    if (puVar21 < (undefined4 *)0xa1) {
      if (puVar21 == (undefined4 *)0x8) {
        FUN_0000c422();
      }
      uVar17 = in_stack_000000b8;
      uVar4 = in_stack_000000b4;
      puVar18 = in_stack_000000b0;
      puVar20 = in_stack_000000a8;
      puVar3 = in_stack_000000a4;
      puVar25 = in_stack_00000098;
      if (puVar21 < (undefined4 *)0x9) {
        if (puVar21 == (undefined4 *)0x2) {
          uVar13 = (uint)in_stack_000000a0 & 0x20;
          in_stack_0000003c = (char *)in_stack_000000ac;
          uVar8 = *in_stack_00000050;
          if (in_stack_00000098 == (undefined4 *)0x0) {
            in_stack_0000002c = (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x90);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar14 = (void *)((int)in_stack_0000002c + 0x70);
          }
          else {
            iVar12 = 0x70;
            puVar21 = in_stack_00000098;
            do {
              piVar1 = puVar21 + 1;
              puVar21 = (undefined4 *)*puVar21;
              iVar12 = iVar12 + *(int *)(*piVar1 + 0x10) + 0x20;
            } while (puVar21 != (undefined4 *)0x0);
            in_stack_0000002c =
                 (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x20 + iVar12);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar14 = (void *)((int)in_stack_0000002c + 0x70);
            do {
              memset(pvVar14,0xff,*(int *)(puVar25[1] + 0x14) + 0x20);
              piVar1 = puVar25 + 1;
              puVar25 = (undefined4 *)*puVar25;
              pvVar14 = (void *)((int)pvVar14 + *(int *)(*piVar1 + 0x10) + 0x20);
            } while (puVar25 != (undefined4 *)0x0);
          }
          memset(pvVar14,0xff,*(int *)(in_stack_00000038 + 0x14) + 0x20);
          if (uVar17 != 0) {
            in_stack_00000038 = (char *)puVar18;
            in_stack_00000034 = (undefined4 *)0x0;
            do {
              uVar22 = *(undefined4 *)in_stack_00000038;
              in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
              *(undefined4 *)pcVar11 = uVar22;
              uVar22 = *(undefined4 *)in_stack_0000003c;
              in_stack_0000003c = (char *)((int)in_stack_0000003c + 4);
              *(undefined4 *)(pcVar11 + 8) = uVar22;
              if (uVar4 != 0) {
                uVar15 = 0;
                puVar21 = puVar3;
                puVar25 = puVar20;
                do {
                  uVar22 = *puVar25;
                  puVar25 = puVar25 + 1;
                  *(undefined4 *)(pcVar11 + 4) = uVar22;
                  uVar22 = *puVar21;
                  puVar21 = puVar21 + 1;
                  *(undefined4 *)(pcVar11 + 0xc) = uVar22;
                  if (uVar13 != 0) {
                    FUN_0000a3f0(pcVar11,pcVar11 + *(ushort *)(pcVar11 + 0x58) + 2,0,0x5b);
                  }
                  iptc_delete_entry(in_stack_00000070,pcVar11,in_stack_0000002c,uVar8);
                  uVar15 = uVar15 + 1;
                } while (uVar15 != uVar4);
              }
              in_stack_00000034 = (undefined4 *)((int)in_stack_00000034 + 1);
            } while (in_stack_00000034 != (undefined4 *)uVar17);
          }
          free(in_stack_0000002c);
          FUN_0000bc28();
          return;
        }
        if (puVar21 == (undefined4 *)0x4) {
          iptc_delete_num_entry(in_stack_00000070,in_stack_00000048 - 1,*in_stack_00000050);
          FUN_0000bc28();
          return;
        }
        if (puVar21 == (undefined4 *)0x1) {
          uVar13 = (uint)in_stack_000000a0 & 0x20;
          uVar8 = *in_stack_00000050;
          puVar21 = (undefined4 *)0x1;
          if (in_stack_000000b8 != 0) {
            in_stack_0000003c = (char *)in_stack_000000b0;
            in_stack_00000038 = (char *)in_stack_000000ac;
            in_stack_00000034 = (undefined4 *)0x0;
            puVar25 = in_stack_000000ac;
            do {
              uVar22 = *(undefined4 *)in_stack_0000003c;
              in_stack_0000003c = (char *)((int)in_stack_0000003c + 4);
              *(undefined4 *)pcVar11 = uVar22;
              uVar22 = *(undefined4 *)in_stack_00000038;
              in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
              *(undefined4 *)(pcVar11 + 8) = uVar22;
              uVar15 = 0;
              if (uVar4 != 0) {
                uVar27 = 0;
                puVar18 = puVar3;
                puVar23 = puVar20;
                puVar25 = puVar21;
                do {
                  uVar22 = *puVar23;
                  puVar23 = puVar23 + 1;
                  *(undefined4 *)(pcVar11 + 4) = uVar22;
                  uVar22 = *puVar18;
                  puVar18 = puVar18 + 1;
                  *(undefined4 *)(pcVar11 + 0xc) = uVar22;
                  if (uVar13 != 0) {
                    FUN_0000a3f0(pcVar11,pcVar11 + *(ushort *)(pcVar11 + 0x58) + 2,0,0x5b);
                  }
                  uVar15 = iptc_insert_entry(in_stack_00000070,pcVar11,in_stack_00000048 - 1,uVar8);
                  puVar25 = (undefined4 *)((uint)puVar25 & uVar15);
                  uVar27 = uVar27 + 1;
                  puVar21 = puVar25;
                } while (uVar27 != uVar4);
              }
              in_stack_00000034 = (undefined4 *)((int)in_stack_00000034 + 1);
            } while (in_stack_00000034 != (undefined4 *)uVar17);
            FUN_0000bc28(uVar15,puVar25);
            return;
          }
          FUN_0000bc28();
          return;
        }
LAB_0000bd98:
                    /* WARNING: Subroutine does not return */
        FUN_0000a2c4(2);
      }
      if (puVar21 != (undefined4 *)0x20) {
        if ((undefined4 *)0x20 < puVar21) {
          FUN_0000c310();
        }
        uVar17 = in_stack_000000b8;
        uVar4 = in_stack_000000b4;
        puVar3 = in_stack_000000a8;
        puVar25 = in_stack_000000a4;
        if (puVar21 == (undefined4 *)0x10) {
          uVar15 = (uint)in_stack_000000a0 & 0x20;
          uVar8 = *in_stack_00000050;
          uVar13 = 1;
          if (in_stack_000000b8 != 0) {
            in_stack_00000034 = in_stack_000000ac;
            in_stack_00000038 = (char *)in_stack_000000b0;
            in_stack_00000030 = 0;
            uVar27 = in_stack_000000b8;
            do {
              uVar22 = *(undefined4 *)in_stack_00000038;
              in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
              *(undefined4 *)pcVar11 = uVar22;
              uVar22 = *in_stack_00000034;
              in_stack_00000034 = in_stack_00000034 + 1;
              *(undefined4 *)(pcVar11 + 8) = uVar22;
              if (uVar4 == 0) {
                uVar6 = 0;
              }
              else {
                uVar26 = 0;
                puVar21 = puVar25;
                puVar20 = puVar3;
                uVar27 = uVar13;
                do {
                  uVar22 = *puVar20;
                  puVar20 = puVar20 + 1;
                  *(undefined4 *)(pcVar11 + 4) = uVar22;
                  uVar22 = *puVar21;
                  puVar21 = puVar21 + 1;
                  *(undefined4 *)(pcVar11 + 0xc) = uVar22;
                  if (uVar15 != 0) {
                    FUN_0000a3f0(pcVar11,pcVar11 + *(ushort *)(pcVar11 + 0x58) + 2,0,0x5b);
                  }
                  uVar6 = iptc_append_entry(in_stack_00000070,pcVar11,uVar8);
                  uVar27 = uVar27 & uVar6;
                  uVar26 = uVar26 + 1;
                  uVar13 = uVar27;
                } while (uVar26 != uVar4);
              }
              in_stack_00000030 = in_stack_00000030 + 1;
            } while (in_stack_00000030 != uVar17);
            FUN_0000bc28(uVar6,uVar27);
            return;
          }
          FUN_0000bc28();
          return;
        }
        goto LAB_0000bd98;
      }
      goto LAB_0000bfbc;
    }
    if (puVar21 != (undefined4 *)0x1000) {
      if (puVar21 < (undefined4 *)0x1001) {
        if (puVar21 == (undefined4 *)0x200) {
LAB_0000c3b8:
          delete_chain(in_stack_00000070,(uint)in_stack_000000a0 & 0x20,*in_stack_00000050);
          FUN_0000bc28();
          puVar25 = in_stack_00000050;
        }
        else {
          if ((undefined4 *)0x200 < puVar21) {
            if (puVar21 == (undefined4 *)0x400) goto LAB_0000c3f4;
            if (puVar21 != (undefined4 *)0x800) goto LAB_0000bd98;
            iptc_rename_chain(in_stack_00000070,in_stack_00000064,*in_stack_00000050);
            FUN_0000bc28();
            goto LAB_0000c3b8;
          }
          if (puVar21 != (undefined4 *)0x100) goto LAB_0000bd98;
        }
        iptc_create_chain(in_stack_00000070,*in_stack_00000050);
        FUN_0000bc28();
        flush_entries(in_stack_00000070,(uint)in_stack_000000a0 & 0x20,*in_stack_00000050);
        FUN_0000bc28();
        puVar21 = in_stack_00000050;
LAB_0000c3f4:
        uVar4 = iptc_set_policy(in_stack_00000070,in_stack_0000005c,
                                (uint)&stack0x00000120 & ((int)in_stack_000000a0 << 0x14) >> 0x1f,
                                *in_stack_00000050);
        FUN_0000bc28();
        pcVar9 = pcVar11;
        unaff_r9 = __src;
        pcVar11 = unaff_r10;
        goto LAB_0000c410;
      }
      puVar25 = (undefined4 *)0x2000;
      if (puVar21 == (undefined4 *)0x2000) {
        FUN_0000c32e();
        puVar25 = extraout_r3_01;
      }
      if (puVar25 < puVar21) {
        if (puVar21 == DAT_0000bfb8) goto LAB_0000bfbc;
        if (puVar21 != (undefined4 *)0x3000) goto LAB_0000bd98;
      }
      else if (puVar21 != (undefined4 *)0x1080) goto LAB_0000bd98;
    }
    uVar22 = *in_stack_00000050;
    uVar8 = 0;
    if (((uint)in_stack_000000a0 & 0x20) != 0) {
      uVar8 = 0xffffffff;
    }
    if (in_stack_00000048 == 0) {
      FUN_0000c558();
    }
    pcVar9 = (char *)iptc_first_chain(uVar22);
    if (pcVar9 != (char *)0x0) {
      bVar2 = false;
      do {
        if ((in_stack_00000070 == (char *)0x0) ||
           (iVar12 = strcmp(pcVar9,in_stack_00000070), iVar12 == 0)) {
          iVar12 = iptc_first_rule(pcVar9,uVar22);
          if (iVar12 != 0) {
            uVar4 = 0;
            do {
              uVar4 = uVar4 + 1;
              if ((in_stack_00000048 == uVar4) || (in_stack_00000048 == 0)) {
                FUN_0000a9b0(iVar12,uVar22,pcVar9,uVar8);
              }
              iVar12 = iptc_next_rule(iVar12,uVar22);
            } while (iVar12 != 0);
          }
          bVar2 = true;
        }
        pcVar9 = (char *)iptc_next_chain(uVar22);
      } while (pcVar9 != (char *)0x0);
      uVar28 = __errno();
      *(undefined4 *)uVar28 = 2;
      if (bVar2) {
        iVar12 = 1;
        goto joined_r0x0000bc12;
      }
      goto LAB_0000bea0;
    }
  }
  uVar28 = __errno();
  *(undefined4 *)uVar28 = 2;
LAB_0000bea0:
  FUN_0000bc28((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),0);
  return;
}



/* Function: FUN_0000b992 @ 0000b992 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b992(void)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  uint uVar4;
  size_t sVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *extraout_r2;
  uint extraout_r3;
  int iVar12;
  uint uVar13;
  uint extraout_r3_00;
  ushort *__src;
  undefined4 *extraout_r3_01;
  void *pvVar14;
  uint extraout_r3_02;
  uint uVar15;
  int unaff_r4;
  void *pvVar16;
  uint uVar17;
  ushort *unaff_r5;
  undefined4 *puVar18;
  FILE *pFVar19;
  code *__format;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined4 uVar22;
  undefined4 *puVar23;
  int iVar24;
  undefined4 *puVar25;
  uint uVar26;
  int unaff_r7;
  uint uVar27;
  int unaff_r8;
  char *unaff_r10;
  char *unaff_r11;
  ushort *extraout_r12;
  ushort *extraout_r12_00;
  undefined8 uVar28;
  void *in_stack_0000002c;
  uint in_stack_00000030;
  undefined4 *in_stack_00000034;
  char *in_stack_00000038;
  char *in_stack_0000003c;
  uint in_stack_00000040;
  uint in_stack_00000048;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  uint in_stack_00000058;
  int in_stack_00000060;
  int in_stack_00000068;
  undefined4 *in_stack_0000006c;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  ushort *in_stack_000000a0;
  undefined4 *in_stack_000000a4;
  undefined4 *in_stack_000000a8;
  undefined4 *in_stack_000000ac;
  undefined4 *in_stack_000000b0;
  uint in_stack_000000b4;
  uint in_stack_000000b8;
  int in_stack_00000134;
  
  if (unaff_r7 != 0) {
    FUN_0000b0f8();
  }
  if (unaff_r4 != 0x3f) {
    FUN_0000c63c();
  }
  if (**(int **)((int)unaff_r5 + _LAB_0000bcd8) == 0) {
    FUN_0000c61e();
  }
  (**(code **)(**(int **)((int)unaff_r5 + _LAB_0000bcdc) + 0x14))
            (2,_LAB_0000bce0 + 0xb9c4,
             *(undefined4 *)((**(int **)((int)unaff_r5 + in_stack_00000030) + -1) * 4 + unaff_r8));
  printf((char *)(_LAB_0000bce4 + 0xb9d8),
         *(undefined4 *)(*(int *)((int)unaff_r5 + (int)in_stack_0000002c) + 8));
  FUN_0000b116();
  if (-1 < (int)in_stack_000000a0 << 0x1d) {
    in_stack_00000060 = _LAB_0000bce8 + 0xb9ec;
  }
  if ((int)in_stack_000000a0 << 0x1e < 0) {
    uVar4 = 0;
    if (in_stack_00000068 != 0) goto LAB_0000b7b2;
  }
  else {
    in_stack_00000068 = _LAB_0000bcec + 0xb9f8;
LAB_0000b7b2:
    uVar4 = FUN_0002353c(in_stack_00000068,&stack0x000000b0,&stack0x000000ac,&stack0x000000b8);
  }
  if (in_stack_00000060 != 0) {
    uVar4 = FUN_0002353c(in_stack_00000060,&stack0x000000a8,&stack0x000000a4,&stack0x000000b4);
  }
  uVar17 = in_stack_000000b8;
  if (1 < in_stack_000000b8) goto LAB_0000b7d8;
  while( true ) {
    if (1 < in_stack_000000b4) {
LAB_0000b7d8:
      if ((*(byte *)((int)in_stack_00000034 + 0x53) & 0x18) != 0) {
        FUN_0000c652(uVar4);
        uVar17 = extraout_r3;
      }
    }
    __src = in_stack_000000a0;
    puVar21 = in_stack_0000009c;
    if ((in_stack_0000009c != (undefined4 *)0x8) || ((uVar17 == 1 && (in_stack_000000b4 == 1))))
    break;
    (**(code **)(**(int **)((int)unaff_r5 + _LAB_0000bcdc) + 0x14))(2,_LAB_0000bd00 + 0xbcd4);
    uVar4 = (uint)*(ushort *)(extraout_r3_02 + 0x3a);
    uVar17 = extraout_r3_02;
    in_stack_00000040 = extraout_r3_02;
    in_stack_00000048 = extraout_r3_02;
    in_stack_00000058 = extraout_r3_02;
  }
  iVar12 = DAT_0000b83c + 0xb846;
  uVar17 = 0;
  uVar4 = 1;
  do {
    uVar15 = (int)__src >> (uVar17 & 0xff) & uVar4;
    pcVar11 = (char *)(iVar12 + uVar17);
    iVar24 = 0;
    uVar13 = 0;
    do {
      while (((int)puVar21 >> (uVar13 & 0xff) & uVar4) == 0) {
LAB_0000b84a:
        uVar13 = uVar13 + 1;
        pcVar11 = pcVar11 + 0xc;
        if (uVar13 == 0xf) goto LAB_0000b870;
      }
      if (uVar15 == 0) {
        if (*pcVar11 == '+') {
          uVar4 = FUN_0000c5ee();
          pcVar11 = extraout_r2;
          uVar13 = extraout_r3_00;
          unaff_r5 = extraout_r12;
        }
        goto LAB_0000b84a;
      }
      if (*pcVar11 == 'x') {
        if (iVar24 == 0) {
          iVar24 = -1;
        }
        goto LAB_0000b84a;
      }
      uVar13 = uVar13 + 1;
      iVar24 = 1;
      pcVar11 = pcVar11 + 0xc;
    } while (uVar13 != 0xf);
LAB_0000b870:
    if (iVar24 == -1) {
      uVar4 = FUN_0000c834();
      unaff_r5 = extraout_r12_00;
    }
    uVar17 = uVar17 + 1;
  } while (uVar17 != 0xc);
  if ((unaff_r11 != (char *)0x0) && (sVar5 = strlen(unaff_r11), 0x1c < sVar5)) {
    FUN_0000c820();
  }
  puVar25 = (undefined4 *)*in_stack_00000050;
  if (puVar25 == (undefined4 *)0x0) {
    puVar25 = (undefined4 *)iptc_init(*in_stack_0000006c);
    *in_stack_00000050 = puVar25;
    puVar21 = in_stack_0000009c;
    if (puVar25 == (undefined4 *)0x0) {
      iVar12 = FUN_00022a4c(**(undefined4 **)((int)unaff_r5 + DAT_0000bfb4),0);
      if (iVar12 != -1) {
        uVar8 = iptc_init(*in_stack_0000006c);
        *in_stack_00000050 = uVar8;
      }
      puVar25 = (undefined4 *)*in_stack_00000050;
      puVar21 = in_stack_0000009c;
      if (puVar25 == (undefined4 *)0x0) {
        FUN_0000c71a();
        puVar21 = in_stack_0000009c;
      }
    }
  }
  if ((((puVar21 == (undefined4 *)0x2) || (puVar21 == (undefined4 *)0x10)) ||
      (puVar21 == (undefined4 *)0x1)) || (pcVar11 = (char *)0x0, puVar21 == (undefined4 *)0x8)) {
    iVar12 = strcmp(unaff_r11,(char *)(_LAB_0000bcf0 + 0xba0e));
    if (((iVar12 == 0) || (iVar12 = strcmp(unaff_r11,(char *)(_LAB_0000bcf4 + 0xba1c)), iVar12 == 0)
        ) && ((int)in_stack_000000a0 << 0x17 < 0)) {
      FUN_0000c6da();
    }
    iVar12 = strcmp(unaff_r11,(char *)(_LAB_0000bcf8 + 0xba34));
    if (((iVar12 == 0) || (iVar12 = strcmp(unaff_r11,(char *)(_LAB_0000bcfc + 0xba42)), iVar12 == 0)
        ) && ((int)in_stack_000000a0 << 0x18 < 0)) {
      FUN_0000c6b6();
    }
    if (in_stack_00000038 == (char *)0x0) {
LAB_0000bec2:
      if ((*in_stack_0000003c != '\0') &&
         (iVar12 = iptc_is_chain(in_stack_0000003c,*in_stack_00000050), iVar12 == 0)) {
        if ((int)((uint)*(byte *)((int)in_stack_00000034 + 0x52) << 0x1e) < 0) {
          func_0x0000c740();
        }
        FUN_00021d00(in_stack_0000003c,3);
        in_stack_00000038 = (char *)0x0;
        pcVar11 = (char *)0x0;
        puVar21 = in_stack_0000009c;
        puVar25 = in_stack_00000050;
        goto LAB_0000b8b8;
      }
      in_stack_00000038 = (char *)FUN_00021d00(DAT_0000bfb0 + 0xbee0,3);
      iVar12 = *(int *)(in_stack_00000038 + 0x10);
      puVar7 = (undefined2 *)FUN_00023304(1,iVar12 + 0x20);
      *(undefined2 **)(in_stack_00000038 + 0x38) = puVar7;
      *puVar7 = (short)(iVar12 + 0x20);
      strcpy((char *)(*(int *)(in_stack_00000038 + 0x38) + 2),in_stack_0000003c);
      iVar12 = iptc_is_chain(in_stack_0000003c,*in_stack_00000050);
      if (iVar12 == 0) {
        *(char *)(*(int *)(in_stack_00000038 + 0x38) + 0x1f) = in_stack_00000038[0xc];
      }
      if (*(code **)(in_stack_00000038 + 0x1c) != (code *)0x0) {
        (**(code **)(in_stack_00000038 + 0x1c))(*(undefined4 *)(in_stack_00000038 + 0x38));
      }
    }
    else {
      iVar12 = iptc_is_chain(in_stack_0000003c,puVar25);
      if (iVar12 != 0) {
        fprintf((FILE *)(*(int *)((int)unaff_r5 + DAT_0000bfa8) + 0xa8),
                (char *)(DAT_0000bfac + 0xbeb2),in_stack_0000003c);
        if (*(void **)(in_stack_00000038 + 0x38) != (void *)0x0) {
          free(*(void **)(in_stack_00000038 + 0x38));
        }
        goto LAB_0000bec2;
      }
    }
    puVar21 = in_stack_00000098;
    __src = *(ushort **)(in_stack_00000038 + 0x38);
    if (in_stack_00000098 == (undefined4 *)0x0) {
      FUN_0000c48a();
    }
    iVar12 = 0x70;
    puVar25 = puVar21;
    do {
      piVar1 = puVar25 + 1;
      puVar25 = (undefined4 *)*puVar25;
      iVar12 = iVar12 + (uint)**(ushort **)(*piVar1 + 0x38);
    } while (puVar25 != (undefined4 *)0x0);
    pcVar11 = (char *)FUN_00022ddc(iVar12 + (uint)*__src);
    memcpy(pcVar11,in_stack_00000034,0x70);
    *(short *)(pcVar11 + 0x58) = (short)iVar12;
    *(ushort *)(pcVar11 + 0x5a) = (short)iVar12 + *__src;
    puVar25 = (undefined4 *)0x0;
    do {
      memcpy(pcVar11 + 0x70 + (int)puVar25,*(ushort **)(puVar21[1] + 0x38),
             (uint)**(ushort **)(puVar21[1] + 0x38));
      piVar1 = puVar21 + 1;
      puVar21 = (undefined4 *)*puVar21;
      puVar25 = (undefined4 *)((int)puVar25 + (uint)**(ushort **)(*piVar1 + 0x38));
    } while (puVar21 != (undefined4 *)0x0);
    memcpy(pcVar11 + 0x70 + (int)puVar25,__src,(uint)*__src);
    free(*(void **)(in_stack_00000038 + 0x38));
    puVar21 = in_stack_0000009c;
  }
LAB_0000b8b8:
  if (puVar21 == (undefined4 *)0xa0) {
LAB_0000bfbc:
    puVar25 = (undefined4 *)*in_stack_00000050;
    puVar21 = (undefined4 *)0x48;
    if (-1 < (int)in_stack_000000a0 << 0x1a) {
      puVar21 = (undefined4 *)0xa;
    }
    if (((uint)in_stack_000000a0 & 1) != 0) {
      puVar21 = (undefined4 *)((uint)puVar21 | 1);
    }
    if (((uint)in_stack_000000a0 & 0x40) == 0) {
      puVar21 = (undefined4 *)((uint)puVar21 | 4);
    }
    if (((uint)in_stack_000000a0 & 0x400) != 0) {
      puVar21 = (undefined4 *)((uint)puVar21 | 0x100);
    }
    pcVar9 = (char *)iptc_first_chain(puVar25);
    if (pcVar9 != (char *)0x0) {
      in_stack_0000002c = (void *)(uint)(in_stack_00000048 == 0);
      in_stack_00000040 = (uint)puVar21 & 0x100;
      in_stack_00000038 = (char *)(DAT_0000c340 + 0xc028);
      iVar12 = 0;
      do {
        if ((unaff_r11 == (char *)0x0) || (iVar24 = strcmp(unaff_r11,pcVar9), iVar24 == 0)) {
          if (iVar12 != 0) {
            putchar(10);
          }
          if (in_stack_00000048 == 0) {
            iVar12 = iptc_get_policy(pcVar9,&stack0x00000078,puVar25);
            printf(in_stack_00000038,pcVar9);
            if (iVar12 == 0) {
              iVar12 = iptc_get_references(&stack0x00000094,pcVar9,puVar25);
              if (iVar12 == 0) {
                puts((char *)(DAT_0000c76c + 0xc4d4));
                in_stack_00000030 = DAT_0000c770;
              }
              else {
                printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
                in_stack_00000030 = iRam0000c8f4;
              }
            }
            else {
              printf((char *)(DAT_0000c344 + 0xc10c));
              if ((int)puVar21 << 0x1e < 0) {
                in_stack_00000030 = DAT_0000c348;
              }
              else {
                in_stack_00000030 = DAT_0000c770;
                pFVar19 = (FILE *)(*(int *)((int)unaff_r5 + DAT_0000c770) + 0x54);
                fputc(0x20,pFVar19);
                FUN_0000a018(in_stack_00000078,in_stack_0000007c,(uint)puVar21 | 0x10);
                fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar19);
                FUN_0000a018(in_stack_00000080,in_stack_00000084,(uint)puVar21 | 0x10);
                fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar19);
              }
              puts((char *)(DAT_0000c34c + 0xc11e));
            }
            if (in_stack_00000040 != 0) {
              if ((int)puVar21 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c768 + 0xc4be);
              }
              else {
                pcVar10 = (char *)(DAT_0000c350 + 0xc132);
              }
              printf(pcVar10,DAT_0000c354 + 0xc136);
            }
            if (-1 < (int)puVar21 << 0x1e) {
              if ((int)puVar21 << 0x1d < 0) {
                if ((int)puVar21 << 0x1b < 0) {
                  pcVar10 = (char *)(DAT_0000c358 + 0xc150);
                  printf(pcVar10,DAT_0000c35c + 0xc152);
                }
                else {
                  pcVar10 = (char *)(DAT_0000c77c + 0xc530);
                  printf(pcVar10,DAT_0000c780 + 0xc532);
                }
                printf(pcVar10,DAT_0000c360 + 0xc15e);
              }
              else {
                if ((int)puVar21 << 0x1b < 0) {
                  __format = (code *)(DAT_0000c784 + 0xc546);
                  printf((char *)__format,DAT_0000c788 + 0xc548);
                }
                else {
                  printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
                  __format = FUN_0000c61e + DAT_0000c7b0;
                }
                printf((char *)__format,DAT_0000c78c + 0xc554);
              }
            }
            if (-1 < (int)puVar21 << 0x1a) {
              if ((int)puVar21 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c75c + 0xc478);
              }
              else {
                pcVar10 = (char *)(DAT_0000c364 + 0xc170);
              }
              printf(pcVar10,DAT_0000c368 + 0xc174);
            }
            pFVar19 = (FILE *)(*(int *)((int)unaff_r5 + in_stack_00000030) + 0x54);
            fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar19);
            if ((int)puVar21 << 0x1c < 0) {
              fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar19);
            }
            if ((int)puVar21 << 0x19 < 0) {
              if ((int)puVar21 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c760 + 0xc480);
                printf(pcVar10,DAT_0000c764 + 0xc482);
              }
              else {
                printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
                pcVar10 = (char *)(DAT_0000c37c + 0xc1ba);
              }
              printf(pcVar10,DAT_0000c380 + 0xc1be);
            }
            if ((int)puVar21 << 0x1b < 0) {
              printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
              pcVar10 = (char *)(DAT_0000c38c + 0xc1d8);
            }
            else {
LAB_0000c410:
              pcVar10 = (char *)(iRam0000c754 + 0xc418);
              printf(pcVar10,DAT_0000c758 + 0xc41a);
            }
            printf(pcVar10,DAT_0000c390 + 0xc1dc);
            putchar(10);
          }
          iVar12 = iptc_first_rule(pcVar9,puVar25);
          if (iVar12 != 0) {
            uVar4 = 0;
            do {
              uVar4 = uVar4 + 1;
              if ((in_stack_00000048 == uVar4) || (in_stack_0000002c != (void *)0x0)) {
                uVar8 = iptc_get_target(iVar12,puVar25);
                FUN_0000a3f0(iVar12,uVar8,uVar4,puVar21);
              }
              iVar12 = iptc_next_rule(iVar12,puVar25);
            } while (iVar12 != 0);
          }
          iVar12 = 1;
        }
        pcVar9 = (char *)iptc_next_chain(puVar25);
      } while (pcVar9 != (char *)0x0);
      uVar28 = __errno();
      *(undefined4 *)uVar28 = 2;
      if (iVar12 != 0) {
joined_r0x0000bc12:
        if (((int)in_stack_0000009c << 0x18 < 0) && (iVar12 = FUN_0000acf0(), iVar12 == 0)) {
          FUN_0000bc28();
          return;
        }
        if ((int)in_stack_0000009c << 0x12 < 0) {
          iVar12 = iptc_zero_counter();
        }
        puVar21 = in_stack_00000098;
        if (1 < in_stack_00000054) {
          dump_entries(*in_stack_00000050);
          puVar21 = in_stack_00000098;
        }
        while (puVar21 != (void *)0x0) {
          pvVar14 = (void *)puVar21[1];
          pvVar16 = (void *)*puVar21;
          if (*(void **)((int)pvVar14 + 0x38) != (void *)0x0) {
            free(*(void **)((int)pvVar14 + 0x38));
            *(undefined4 *)(puVar21[1] + 0x38) = 0;
            pvVar14 = (void *)puVar21[1];
          }
          if (pvVar14 == *(void **)((int)pvVar14 + 4)) {
            free(pvVar14);
            puVar21[1] = 0;
          }
          free(puVar21);
          puVar21 = pvVar16;
        }
        in_stack_00000098 = (undefined4 *)0x0;
        if (pcVar11 != (char *)0x0) {
          free(pcVar11);
        }
        free(in_stack_000000b0);
        free(in_stack_000000ac);
        free(in_stack_000000a8);
        free(in_stack_000000a4);
        FUN_00021f14(1);
        if (in_stack_00000134 != **(int **)((int)unaff_r5 + in_stack_00000058)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail(iVar12);
        }
        return;
      }
      goto LAB_0000bea0;
    }
  }
  else {
    if (puVar21 < (undefined4 *)0xa1) {
      if (puVar21 == (undefined4 *)0x8) {
        FUN_0000c422();
      }
      uVar17 = in_stack_000000b8;
      uVar4 = in_stack_000000b4;
      puVar18 = in_stack_000000b0;
      puVar20 = in_stack_000000a8;
      puVar3 = in_stack_000000a4;
      puVar25 = in_stack_00000098;
      if (puVar21 < (undefined4 *)0x9) {
        if (puVar21 == (undefined4 *)0x2) {
          uVar13 = (uint)in_stack_000000a0 & 0x20;
          in_stack_0000003c = (char *)in_stack_000000ac;
          if (in_stack_00000098 == (undefined4 *)0x0) {
            in_stack_0000002c = (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x90);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar14 = (void *)((int)in_stack_0000002c + 0x70);
          }
          else {
            iVar12 = 0x70;
            puVar21 = in_stack_00000098;
            do {
              piVar1 = puVar21 + 1;
              puVar21 = (undefined4 *)*puVar21;
              iVar12 = iVar12 + *(int *)(*piVar1 + 0x10) + 0x20;
            } while (puVar21 != (undefined4 *)0x0);
            in_stack_0000002c =
                 (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x20 + iVar12);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar14 = (void *)((int)in_stack_0000002c + 0x70);
            do {
              memset(pvVar14,0xff,*(int *)(puVar25[1] + 0x14) + 0x20);
              piVar1 = puVar25 + 1;
              puVar25 = (undefined4 *)*puVar25;
              pvVar14 = (void *)((int)pvVar14 + *(int *)(*piVar1 + 0x10) + 0x20);
            } while (puVar25 != (undefined4 *)0x0);
          }
          memset(pvVar14,0xff,*(int *)(in_stack_00000038 + 0x14) + 0x20);
          if (uVar17 != 0) {
            in_stack_00000038 = (char *)puVar18;
            in_stack_00000034 = (undefined4 *)0x0;
            do {
              uVar8 = *(undefined4 *)in_stack_00000038;
              in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
              *(undefined4 *)pcVar11 = uVar8;
              uVar8 = *(undefined4 *)in_stack_0000003c;
              in_stack_0000003c = (char *)((int)in_stack_0000003c + 4);
              *(undefined4 *)(pcVar11 + 8) = uVar8;
              if (uVar4 != 0) {
                uVar15 = 0;
                puVar21 = puVar3;
                puVar25 = puVar20;
                do {
                  uVar8 = *puVar25;
                  puVar25 = puVar25 + 1;
                  *(undefined4 *)(pcVar11 + 4) = uVar8;
                  uVar8 = *puVar21;
                  puVar21 = puVar21 + 1;
                  *(undefined4 *)(pcVar11 + 0xc) = uVar8;
                  if (uVar13 != 0) {
                    FUN_0000a3f0(pcVar11,pcVar11 + *(ushort *)(pcVar11 + 0x58) + 2,0,0x5b);
                  }
                  iptc_delete_entry();
                  uVar15 = uVar15 + 1;
                } while (uVar15 != uVar4);
              }
              in_stack_00000034 = (undefined4 *)((int)in_stack_00000034 + 1);
            } while (in_stack_00000034 != (undefined4 *)uVar17);
          }
          free(in_stack_0000002c);
          FUN_0000bc28();
          return;
        }
        if (puVar21 == (undefined4 *)0x4) {
          iptc_delete_num_entry();
          FUN_0000bc28();
          return;
        }
        if (puVar21 == (undefined4 *)0x1) {
          uVar13 = (uint)in_stack_000000a0 & 0x20;
          puVar21 = (undefined4 *)0x1;
          if (in_stack_000000b8 == 0) {
            FUN_0000bc28();
            return;
          }
          in_stack_0000003c = (char *)in_stack_000000b0;
          in_stack_00000038 = (char *)in_stack_000000ac;
          in_stack_00000034 = (undefined4 *)0x0;
          puVar25 = in_stack_000000ac;
          do {
            uVar8 = *(undefined4 *)in_stack_0000003c;
            in_stack_0000003c = (char *)((int)in_stack_0000003c + 4);
            *(undefined4 *)pcVar11 = uVar8;
            uVar8 = *(undefined4 *)in_stack_00000038;
            in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
            *(undefined4 *)(pcVar11 + 8) = uVar8;
            uVar15 = 0;
            if (uVar4 != 0) {
              uVar27 = 0;
              puVar18 = puVar3;
              puVar23 = puVar20;
              puVar25 = puVar21;
              do {
                uVar8 = *puVar23;
                puVar23 = puVar23 + 1;
                *(undefined4 *)(pcVar11 + 4) = uVar8;
                uVar8 = *puVar18;
                puVar18 = puVar18 + 1;
                *(undefined4 *)(pcVar11 + 0xc) = uVar8;
                if (uVar13 != 0) {
                  FUN_0000a3f0(pcVar11,pcVar11 + *(ushort *)(pcVar11 + 0x58) + 2,0,0x5b);
                }
                uVar15 = iptc_insert_entry();
                puVar25 = (undefined4 *)((uint)puVar25 & uVar15);
                uVar27 = uVar27 + 1;
                puVar21 = puVar25;
              } while (uVar27 != uVar4);
            }
            in_stack_00000034 = (undefined4 *)((int)in_stack_00000034 + 1);
          } while (in_stack_00000034 != (undefined4 *)uVar17);
          FUN_0000bc28(uVar15,puVar25);
          return;
        }
LAB_0000bd98:
                    /* WARNING: Subroutine does not return */
        FUN_0000a2c4(2);
      }
      if (puVar21 != (undefined4 *)0x20) {
        if ((undefined4 *)0x20 < puVar21) {
          FUN_0000c310();
        }
        uVar17 = in_stack_000000b8;
        uVar4 = in_stack_000000b4;
        puVar3 = in_stack_000000a8;
        puVar25 = in_stack_000000a4;
        if (puVar21 == (undefined4 *)0x10) {
          uVar15 = (uint)in_stack_000000a0 & 0x20;
          uVar13 = 1;
          if (in_stack_000000b8 == 0) {
            FUN_0000bc28();
            return;
          }
          in_stack_00000034 = in_stack_000000ac;
          in_stack_00000038 = (char *)in_stack_000000b0;
          in_stack_00000030 = 0;
          uVar27 = in_stack_000000b8;
          do {
            uVar8 = *(undefined4 *)in_stack_00000038;
            in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
            *(undefined4 *)pcVar11 = uVar8;
            uVar8 = *in_stack_00000034;
            in_stack_00000034 = in_stack_00000034 + 1;
            *(undefined4 *)(pcVar11 + 8) = uVar8;
            if (uVar4 == 0) {
              uVar6 = 0;
            }
            else {
              uVar26 = 0;
              puVar21 = puVar25;
              puVar20 = puVar3;
              uVar27 = uVar13;
              do {
                uVar8 = *puVar20;
                puVar20 = puVar20 + 1;
                *(undefined4 *)(pcVar11 + 4) = uVar8;
                uVar8 = *puVar21;
                puVar21 = puVar21 + 1;
                *(undefined4 *)(pcVar11 + 0xc) = uVar8;
                if (uVar15 != 0) {
                  FUN_0000a3f0(pcVar11,pcVar11 + *(ushort *)(pcVar11 + 0x58) + 2,0,0x5b);
                }
                uVar6 = iptc_append_entry();
                uVar27 = uVar27 & uVar6;
                uVar26 = uVar26 + 1;
                uVar13 = uVar27;
              } while (uVar26 != uVar4);
            }
            in_stack_00000030 = in_stack_00000030 + 1;
          } while (in_stack_00000030 != uVar17);
          FUN_0000bc28(uVar6,uVar27);
          return;
        }
        goto LAB_0000bd98;
      }
      goto LAB_0000bfbc;
    }
    if (puVar21 != (undefined4 *)0x1000) {
      if (puVar21 < (undefined4 *)0x1001) {
        if (puVar21 == (undefined4 *)0x200) {
LAB_0000c3b8:
          delete_chain();
          FUN_0000bc28();
          puVar25 = in_stack_00000050;
        }
        else {
          if ((undefined4 *)0x200 < puVar21) {
            if (puVar21 == (undefined4 *)0x400) goto LAB_0000c3f4;
            if (puVar21 != (undefined4 *)0x800) goto LAB_0000bd98;
            iptc_rename_chain();
            FUN_0000bc28();
            goto LAB_0000c3b8;
          }
          if (puVar21 != (undefined4 *)0x100) goto LAB_0000bd98;
        }
        iptc_create_chain();
        FUN_0000bc28();
        flush_entries();
        FUN_0000bc28();
        puVar21 = in_stack_00000050;
LAB_0000c3f4:
        in_stack_00000048 = iptc_set_policy();
        FUN_0000bc28();
        pcVar9 = pcVar11;
        unaff_r5 = __src;
        pcVar11 = unaff_r10;
        goto LAB_0000c410;
      }
      puVar25 = (undefined4 *)0x2000;
      if (puVar21 == (undefined4 *)0x2000) {
        FUN_0000c32e();
        puVar25 = extraout_r3_01;
      }
      if (puVar25 < puVar21) {
        if (puVar21 == DAT_0000bfb8) goto LAB_0000bfbc;
        if (puVar21 != (undefined4 *)0x3000) goto LAB_0000bd98;
      }
      else if (puVar21 != (undefined4 *)0x1080) goto LAB_0000bd98;
    }
    uVar22 = *in_stack_00000050;
    uVar8 = 0;
    if (((uint)in_stack_000000a0 & 0x20) != 0) {
      uVar8 = 0xffffffff;
    }
    if (in_stack_00000048 == 0) {
      FUN_0000c558();
    }
    pcVar9 = (char *)iptc_first_chain(uVar22);
    if (pcVar9 != (char *)0x0) {
      bVar2 = false;
      do {
        if ((unaff_r11 == (char *)0x0) || (iVar12 = strcmp(pcVar9,unaff_r11), iVar12 == 0)) {
          iVar12 = iptc_first_rule(pcVar9,uVar22);
          if (iVar12 != 0) {
            uVar4 = 0;
            do {
              uVar4 = uVar4 + 1;
              if ((in_stack_00000048 == uVar4) || (in_stack_00000048 == 0)) {
                FUN_0000a9b0(iVar12,uVar22,pcVar9,uVar8);
              }
              iVar12 = iptc_next_rule(iVar12,uVar22);
            } while (iVar12 != 0);
          }
          bVar2 = true;
        }
        pcVar9 = (char *)iptc_next_chain(uVar22);
      } while (pcVar9 != (char *)0x0);
      uVar28 = __errno();
      *(undefined4 *)uVar28 = 2;
      if (bVar2) {
        iVar12 = 1;
        goto joined_r0x0000bc12;
      }
      goto LAB_0000bea0;
    }
  }
  uVar28 = __errno();
  *(undefined4 *)uVar28 = 2;
LAB_0000bea0:
  FUN_0000bc28((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),0);
  return;
}



/* Function: FUN_0000b99a @ 0000b99a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b99a(void)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  uint uVar4;
  size_t sVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *extraout_r2;
  uint extraout_r3;
  int iVar12;
  uint uVar13;
  uint extraout_r3_00;
  ushort *__src;
  undefined4 *extraout_r3_01;
  void *pvVar14;
  uint extraout_r3_02;
  uint uVar15;
  int unaff_r4;
  void *pvVar16;
  uint uVar17;
  ushort *unaff_r5;
  undefined4 *puVar18;
  FILE *pFVar19;
  code *__format;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined4 uVar22;
  undefined4 *puVar23;
  int iVar24;
  undefined4 *puVar25;
  uint uVar26;
  uint uVar27;
  int unaff_r8;
  char *unaff_r10;
  char *unaff_r11;
  ushort *extraout_r12;
  ushort *extraout_r12_00;
  undefined8 uVar28;
  void *in_stack_0000002c;
  uint in_stack_00000030;
  undefined4 *in_stack_00000034;
  char *in_stack_00000038;
  char *in_stack_0000003c;
  uint in_stack_00000040;
  uint in_stack_00000048;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  uint in_stack_00000058;
  int in_stack_00000060;
  int in_stack_00000068;
  undefined4 *in_stack_0000006c;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  ushort *in_stack_000000a0;
  undefined4 *in_stack_000000a4;
  undefined4 *in_stack_000000a8;
  undefined4 *in_stack_000000ac;
  undefined4 *in_stack_000000b0;
  uint in_stack_000000b4;
  uint in_stack_000000b8;
  int in_stack_00000134;
  
  if (unaff_r4 != 0x3f) {
    FUN_0000c63c();
  }
  if (**(int **)((int)unaff_r5 + _LAB_0000bcd8) == 0) {
    FUN_0000c61e();
  }
  (**(code **)(**(int **)((int)unaff_r5 + _LAB_0000bcdc) + 0x14))
            (2,_LAB_0000bce0 + 0xb9c4,
             *(undefined4 *)((**(int **)((int)unaff_r5 + in_stack_00000030) + -1) * 4 + unaff_r8));
  printf((char *)(_LAB_0000bce4 + 0xb9d8),
         *(undefined4 *)(*(int *)((int)unaff_r5 + (int)in_stack_0000002c) + 8));
  FUN_0000b116();
  if (-1 < (int)in_stack_000000a0 << 0x1d) {
    in_stack_00000060 = _LAB_0000bce8 + 0xb9ec;
  }
  if ((int)in_stack_000000a0 << 0x1e < 0) {
    uVar4 = 0;
    if (in_stack_00000068 != 0) goto LAB_0000b7b2;
  }
  else {
    in_stack_00000068 = _LAB_0000bcec + 0xb9f8;
LAB_0000b7b2:
    uVar4 = FUN_0002353c(in_stack_00000068,&stack0x000000b0,&stack0x000000ac,&stack0x000000b8);
  }
  if (in_stack_00000060 != 0) {
    uVar4 = FUN_0002353c(in_stack_00000060,&stack0x000000a8,&stack0x000000a4,&stack0x000000b4);
  }
  uVar17 = in_stack_000000b8;
  if (1 < in_stack_000000b8) goto LAB_0000b7d8;
  while( true ) {
    if (1 < in_stack_000000b4) {
LAB_0000b7d8:
      if ((*(byte *)((int)in_stack_00000034 + 0x53) & 0x18) != 0) {
        FUN_0000c652(uVar4);
        uVar17 = extraout_r3;
      }
    }
    __src = in_stack_000000a0;
    puVar21 = in_stack_0000009c;
    if ((in_stack_0000009c != (undefined4 *)0x8) || ((uVar17 == 1 && (in_stack_000000b4 == 1))))
    break;
    (**(code **)(**(int **)((int)unaff_r5 + _LAB_0000bcdc) + 0x14))(2,_LAB_0000bd00 + 0xbcd4);
    uVar4 = (uint)*(ushort *)(extraout_r3_02 + 0x3a);
    uVar17 = extraout_r3_02;
    in_stack_00000040 = extraout_r3_02;
    in_stack_00000048 = extraout_r3_02;
    in_stack_00000058 = extraout_r3_02;
  }
  iVar12 = DAT_0000b83c + 0xb846;
  uVar17 = 0;
  uVar4 = 1;
  do {
    uVar15 = (int)__src >> (uVar17 & 0xff) & uVar4;
    pcVar11 = (char *)(iVar12 + uVar17);
    iVar24 = 0;
    uVar13 = 0;
    do {
      while (((int)puVar21 >> (uVar13 & 0xff) & uVar4) == 0) {
LAB_0000b84a:
        uVar13 = uVar13 + 1;
        pcVar11 = pcVar11 + 0xc;
        if (uVar13 == 0xf) goto LAB_0000b870;
      }
      if (uVar15 == 0) {
        if (*pcVar11 == '+') {
          uVar4 = FUN_0000c5ee();
          pcVar11 = extraout_r2;
          uVar13 = extraout_r3_00;
          unaff_r5 = extraout_r12;
        }
        goto LAB_0000b84a;
      }
      if (*pcVar11 == 'x') {
        if (iVar24 == 0) {
          iVar24 = -1;
        }
        goto LAB_0000b84a;
      }
      uVar13 = uVar13 + 1;
      iVar24 = 1;
      pcVar11 = pcVar11 + 0xc;
    } while (uVar13 != 0xf);
LAB_0000b870:
    if (iVar24 == -1) {
      uVar4 = FUN_0000c834();
      unaff_r5 = extraout_r12_00;
    }
    uVar17 = uVar17 + 1;
  } while (uVar17 != 0xc);
  if ((unaff_r11 != (char *)0x0) && (sVar5 = strlen(unaff_r11), 0x1c < sVar5)) {
    FUN_0000c820();
  }
  puVar25 = (undefined4 *)*in_stack_00000050;
  if (puVar25 == (undefined4 *)0x0) {
    puVar25 = (undefined4 *)iptc_init(*in_stack_0000006c);
    *in_stack_00000050 = puVar25;
    puVar21 = in_stack_0000009c;
    if (puVar25 == (undefined4 *)0x0) {
      iVar12 = FUN_00022a4c(**(undefined4 **)((int)unaff_r5 + DAT_0000bfb4),0);
      if (iVar12 != -1) {
        uVar8 = iptc_init(*in_stack_0000006c);
        *in_stack_00000050 = uVar8;
      }
      puVar25 = (undefined4 *)*in_stack_00000050;
      puVar21 = in_stack_0000009c;
      if (puVar25 == (undefined4 *)0x0) {
        FUN_0000c71a();
        puVar21 = in_stack_0000009c;
      }
    }
  }
  if ((((puVar21 == (undefined4 *)0x2) || (puVar21 == (undefined4 *)0x10)) ||
      (puVar21 == (undefined4 *)0x1)) || (pcVar11 = (char *)0x0, puVar21 == (undefined4 *)0x8)) {
    iVar12 = strcmp(unaff_r11,(char *)(_LAB_0000bcf0 + 0xba0e));
    if (((iVar12 == 0) || (iVar12 = strcmp(unaff_r11,(char *)(_LAB_0000bcf4 + 0xba1c)), iVar12 == 0)
        ) && ((int)in_stack_000000a0 << 0x17 < 0)) {
      FUN_0000c6da();
    }
    iVar12 = strcmp(unaff_r11,(char *)(_LAB_0000bcf8 + 0xba34));
    if (((iVar12 == 0) || (iVar12 = strcmp(unaff_r11,(char *)(_LAB_0000bcfc + 0xba42)), iVar12 == 0)
        ) && ((int)in_stack_000000a0 << 0x18 < 0)) {
      FUN_0000c6b6();
    }
    if (in_stack_00000038 == (char *)0x0) {
LAB_0000bec2:
      if ((*in_stack_0000003c != '\0') &&
         (iVar12 = iptc_is_chain(in_stack_0000003c,*in_stack_00000050), iVar12 == 0)) {
        if ((int)((uint)*(byte *)((int)in_stack_00000034 + 0x52) << 0x1e) < 0) {
          func_0x0000c740();
        }
        FUN_00021d00(in_stack_0000003c,3);
        in_stack_00000038 = (char *)0x0;
        pcVar11 = (char *)0x0;
        puVar21 = in_stack_0000009c;
        puVar25 = in_stack_00000050;
        goto LAB_0000b8b8;
      }
      in_stack_00000038 = (char *)FUN_00021d00(DAT_0000bfb0 + 0xbee0,3);
      iVar12 = *(int *)(in_stack_00000038 + 0x10);
      puVar7 = (undefined2 *)FUN_00023304(1,iVar12 + 0x20);
      *(undefined2 **)(in_stack_00000038 + 0x38) = puVar7;
      *puVar7 = (short)(iVar12 + 0x20);
      strcpy((char *)(*(int *)(in_stack_00000038 + 0x38) + 2),in_stack_0000003c);
      iVar12 = iptc_is_chain(in_stack_0000003c,*in_stack_00000050);
      if (iVar12 == 0) {
        *(char *)(*(int *)(in_stack_00000038 + 0x38) + 0x1f) = in_stack_00000038[0xc];
      }
      if (*(code **)(in_stack_00000038 + 0x1c) != (code *)0x0) {
        (**(code **)(in_stack_00000038 + 0x1c))(*(undefined4 *)(in_stack_00000038 + 0x38));
      }
    }
    else {
      iVar12 = iptc_is_chain(in_stack_0000003c,puVar25);
      if (iVar12 != 0) {
        fprintf((FILE *)(*(int *)((int)unaff_r5 + DAT_0000bfa8) + 0xa8),
                (char *)(DAT_0000bfac + 0xbeb2),in_stack_0000003c);
        if (*(void **)(in_stack_00000038 + 0x38) != (void *)0x0) {
          free(*(void **)(in_stack_00000038 + 0x38));
        }
        goto LAB_0000bec2;
      }
    }
    puVar21 = in_stack_00000098;
    __src = *(ushort **)(in_stack_00000038 + 0x38);
    if (in_stack_00000098 == (undefined4 *)0x0) {
      FUN_0000c48a();
    }
    iVar12 = 0x70;
    puVar25 = puVar21;
    do {
      piVar1 = puVar25 + 1;
      puVar25 = (undefined4 *)*puVar25;
      iVar12 = iVar12 + (uint)**(ushort **)(*piVar1 + 0x38);
    } while (puVar25 != (undefined4 *)0x0);
    pcVar11 = (char *)FUN_00022ddc(iVar12 + (uint)*__src);
    memcpy(pcVar11,in_stack_00000034,0x70);
    *(short *)(pcVar11 + 0x58) = (short)iVar12;
    *(ushort *)(pcVar11 + 0x5a) = (short)iVar12 + *__src;
    puVar25 = (undefined4 *)0x0;
    do {
      memcpy(pcVar11 + 0x70 + (int)puVar25,*(ushort **)(puVar21[1] + 0x38),
             (uint)**(ushort **)(puVar21[1] + 0x38));
      piVar1 = puVar21 + 1;
      puVar21 = (undefined4 *)*puVar21;
      puVar25 = (undefined4 *)((int)puVar25 + (uint)**(ushort **)(*piVar1 + 0x38));
    } while (puVar21 != (undefined4 *)0x0);
    memcpy(pcVar11 + 0x70 + (int)puVar25,__src,(uint)*__src);
    free(*(void **)(in_stack_00000038 + 0x38));
    puVar21 = in_stack_0000009c;
  }
LAB_0000b8b8:
  if (puVar21 == (undefined4 *)0xa0) {
LAB_0000bfbc:
    puVar25 = (undefined4 *)*in_stack_00000050;
    puVar21 = (undefined4 *)0x48;
    if (-1 < (int)in_stack_000000a0 << 0x1a) {
      puVar21 = (undefined4 *)0xa;
    }
    if (((uint)in_stack_000000a0 & 1) != 0) {
      puVar21 = (undefined4 *)((uint)puVar21 | 1);
    }
    if (((uint)in_stack_000000a0 & 0x40) == 0) {
      puVar21 = (undefined4 *)((uint)puVar21 | 4);
    }
    if (((uint)in_stack_000000a0 & 0x400) != 0) {
      puVar21 = (undefined4 *)((uint)puVar21 | 0x100);
    }
    pcVar9 = (char *)iptc_first_chain(puVar25);
    if (pcVar9 != (char *)0x0) {
      in_stack_0000002c = (void *)(uint)(in_stack_00000048 == 0);
      in_stack_00000040 = (uint)puVar21 & 0x100;
      in_stack_00000038 = (char *)(DAT_0000c340 + 0xc028);
      iVar12 = 0;
      do {
        if ((unaff_r11 == (char *)0x0) || (iVar24 = strcmp(unaff_r11,pcVar9), iVar24 == 0)) {
          if (iVar12 != 0) {
            putchar(10);
          }
          if (in_stack_00000048 == 0) {
            iVar12 = iptc_get_policy(pcVar9,&stack0x00000078,puVar25);
            printf(in_stack_00000038,pcVar9);
            if (iVar12 == 0) {
              iVar12 = iptc_get_references(&stack0x00000094,pcVar9,puVar25);
              if (iVar12 == 0) {
                puts((char *)(DAT_0000c76c + 0xc4d4));
                in_stack_00000030 = DAT_0000c770;
              }
              else {
                printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
                in_stack_00000030 = iRam0000c8f4;
              }
            }
            else {
              printf((char *)(DAT_0000c344 + 0xc10c));
              if ((int)puVar21 << 0x1e < 0) {
                in_stack_00000030 = DAT_0000c348;
              }
              else {
                in_stack_00000030 = DAT_0000c770;
                pFVar19 = (FILE *)(*(int *)((int)unaff_r5 + DAT_0000c770) + 0x54);
                fputc(0x20,pFVar19);
                FUN_0000a018(in_stack_00000078,in_stack_0000007c,(uint)puVar21 | 0x10);
                fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar19);
                FUN_0000a018(in_stack_00000080,in_stack_00000084,(uint)puVar21 | 0x10);
                fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar19);
              }
              puts((char *)(DAT_0000c34c + 0xc11e));
            }
            if (in_stack_00000040 != 0) {
              if ((int)puVar21 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c768 + 0xc4be);
              }
              else {
                pcVar10 = (char *)(DAT_0000c350 + 0xc132);
              }
              printf(pcVar10,DAT_0000c354 + 0xc136);
            }
            if (-1 < (int)puVar21 << 0x1e) {
              if ((int)puVar21 << 0x1d < 0) {
                if ((int)puVar21 << 0x1b < 0) {
                  pcVar10 = (char *)(DAT_0000c358 + 0xc150);
                  printf(pcVar10,DAT_0000c35c + 0xc152);
                }
                else {
                  pcVar10 = (char *)(DAT_0000c77c + 0xc530);
                  printf(pcVar10,DAT_0000c780 + 0xc532);
                }
                printf(pcVar10,DAT_0000c360 + 0xc15e);
              }
              else {
                if ((int)puVar21 << 0x1b < 0) {
                  __format = (code *)(DAT_0000c784 + 0xc546);
                  printf((char *)__format,DAT_0000c788 + 0xc548);
                }
                else {
                  printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
                  __format = FUN_0000c61e + DAT_0000c7b0;
                }
                printf((char *)__format,DAT_0000c78c + 0xc554);
              }
            }
            if (-1 < (int)puVar21 << 0x1a) {
              if ((int)puVar21 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c75c + 0xc478);
              }
              else {
                pcVar10 = (char *)(DAT_0000c364 + 0xc170);
              }
              printf(pcVar10,DAT_0000c368 + 0xc174);
            }
            pFVar19 = (FILE *)(*(int *)((int)unaff_r5 + in_stack_00000030) + 0x54);
            fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar19);
            if ((int)puVar21 << 0x1c < 0) {
              fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar19);
            }
            if ((int)puVar21 << 0x19 < 0) {
              if ((int)puVar21 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c760 + 0xc480);
                printf(pcVar10,DAT_0000c764 + 0xc482);
              }
              else {
                printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
                pcVar10 = (char *)(DAT_0000c37c + 0xc1ba);
              }
              printf(pcVar10,DAT_0000c380 + 0xc1be);
            }
            if ((int)puVar21 << 0x1b < 0) {
              printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
              pcVar10 = (char *)(DAT_0000c38c + 0xc1d8);
            }
            else {
LAB_0000c410:
              pcVar10 = (char *)(iRam0000c754 + 0xc418);
              printf(pcVar10,DAT_0000c758 + 0xc41a);
            }
            printf(pcVar10,DAT_0000c390 + 0xc1dc);
            putchar(10);
          }
          iVar12 = iptc_first_rule(pcVar9,puVar25);
          if (iVar12 != 0) {
            uVar4 = 0;
            do {
              uVar4 = uVar4 + 1;
              if ((in_stack_00000048 == uVar4) || (in_stack_0000002c != (void *)0x0)) {
                uVar8 = iptc_get_target(iVar12,puVar25);
                FUN_0000a3f0(iVar12,uVar8,uVar4,puVar21);
              }
              iVar12 = iptc_next_rule(iVar12,puVar25);
            } while (iVar12 != 0);
          }
          iVar12 = 1;
        }
        pcVar9 = (char *)iptc_next_chain(puVar25);
      } while (pcVar9 != (char *)0x0);
      uVar28 = __errno();
      *(undefined4 *)uVar28 = 2;
      if (iVar12 != 0) {
joined_r0x0000bc12:
        if (((int)in_stack_0000009c << 0x18 < 0) && (iVar12 = FUN_0000acf0(), iVar12 == 0)) {
          FUN_0000bc28();
          return;
        }
        if ((int)in_stack_0000009c << 0x12 < 0) {
          iVar12 = iptc_zero_counter();
        }
        puVar21 = in_stack_00000098;
        if (1 < in_stack_00000054) {
          dump_entries(*in_stack_00000050);
          puVar21 = in_stack_00000098;
        }
        while (puVar21 != (void *)0x0) {
          pvVar14 = (void *)puVar21[1];
          pvVar16 = (void *)*puVar21;
          if (*(void **)((int)pvVar14 + 0x38) != (void *)0x0) {
            free(*(void **)((int)pvVar14 + 0x38));
            *(undefined4 *)(puVar21[1] + 0x38) = 0;
            pvVar14 = (void *)puVar21[1];
          }
          if (pvVar14 == *(void **)((int)pvVar14 + 4)) {
            free(pvVar14);
            puVar21[1] = 0;
          }
          free(puVar21);
          puVar21 = pvVar16;
        }
        in_stack_00000098 = (undefined4 *)0x0;
        if (pcVar11 != (char *)0x0) {
          free(pcVar11);
        }
        free(in_stack_000000b0);
        free(in_stack_000000ac);
        free(in_stack_000000a8);
        free(in_stack_000000a4);
        FUN_00021f14(1);
        if (in_stack_00000134 != **(int **)((int)unaff_r5 + in_stack_00000058)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail(iVar12);
        }
        return;
      }
      goto LAB_0000bea0;
    }
  }
  else {
    if (puVar21 < (undefined4 *)0xa1) {
      if (puVar21 == (undefined4 *)0x8) {
        FUN_0000c422();
      }
      uVar17 = in_stack_000000b8;
      uVar4 = in_stack_000000b4;
      puVar18 = in_stack_000000b0;
      puVar20 = in_stack_000000a8;
      puVar3 = in_stack_000000a4;
      puVar25 = in_stack_00000098;
      if (puVar21 < (undefined4 *)0x9) {
        if (puVar21 == (undefined4 *)0x2) {
          uVar13 = (uint)in_stack_000000a0 & 0x20;
          in_stack_0000003c = (char *)in_stack_000000ac;
          if (in_stack_00000098 == (undefined4 *)0x0) {
            in_stack_0000002c = (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x90);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar14 = (void *)((int)in_stack_0000002c + 0x70);
          }
          else {
            iVar12 = 0x70;
            puVar21 = in_stack_00000098;
            do {
              piVar1 = puVar21 + 1;
              puVar21 = (undefined4 *)*puVar21;
              iVar12 = iVar12 + *(int *)(*piVar1 + 0x10) + 0x20;
            } while (puVar21 != (undefined4 *)0x0);
            in_stack_0000002c =
                 (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x20 + iVar12);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar14 = (void *)((int)in_stack_0000002c + 0x70);
            do {
              memset(pvVar14,0xff,*(int *)(puVar25[1] + 0x14) + 0x20);
              piVar1 = puVar25 + 1;
              puVar25 = (undefined4 *)*puVar25;
              pvVar14 = (void *)((int)pvVar14 + *(int *)(*piVar1 + 0x10) + 0x20);
            } while (puVar25 != (undefined4 *)0x0);
          }
          memset(pvVar14,0xff,*(int *)(in_stack_00000038 + 0x14) + 0x20);
          if (uVar17 != 0) {
            in_stack_00000038 = (char *)puVar18;
            in_stack_00000034 = (undefined4 *)0x0;
            do {
              uVar8 = *(undefined4 *)in_stack_00000038;
              in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
              *(undefined4 *)pcVar11 = uVar8;
              uVar8 = *(undefined4 *)in_stack_0000003c;
              in_stack_0000003c = (char *)((int)in_stack_0000003c + 4);
              *(undefined4 *)(pcVar11 + 8) = uVar8;
              if (uVar4 != 0) {
                uVar15 = 0;
                puVar21 = puVar3;
                puVar25 = puVar20;
                do {
                  uVar8 = *puVar25;
                  puVar25 = puVar25 + 1;
                  *(undefined4 *)(pcVar11 + 4) = uVar8;
                  uVar8 = *puVar21;
                  puVar21 = puVar21 + 1;
                  *(undefined4 *)(pcVar11 + 0xc) = uVar8;
                  if (uVar13 != 0) {
                    FUN_0000a3f0(pcVar11,pcVar11 + *(ushort *)(pcVar11 + 0x58) + 2,0,0x5b);
                  }
                  iptc_delete_entry();
                  uVar15 = uVar15 + 1;
                } while (uVar15 != uVar4);
              }
              in_stack_00000034 = (undefined4 *)((int)in_stack_00000034 + 1);
            } while (in_stack_00000034 != (undefined4 *)uVar17);
          }
          free(in_stack_0000002c);
          FUN_0000bc28();
          return;
        }
        if (puVar21 == (undefined4 *)0x4) {
          iptc_delete_num_entry();
          FUN_0000bc28();
          return;
        }
        if (puVar21 == (undefined4 *)0x1) {
          uVar13 = (uint)in_stack_000000a0 & 0x20;
          puVar21 = (undefined4 *)0x1;
          if (in_stack_000000b8 == 0) {
            FUN_0000bc28();
            return;
          }
          in_stack_0000003c = (char *)in_stack_000000b0;
          in_stack_00000038 = (char *)in_stack_000000ac;
          in_stack_00000034 = (undefined4 *)0x0;
          puVar25 = in_stack_000000ac;
          do {
            uVar8 = *(undefined4 *)in_stack_0000003c;
            in_stack_0000003c = (char *)((int)in_stack_0000003c + 4);
            *(undefined4 *)pcVar11 = uVar8;
            uVar8 = *(undefined4 *)in_stack_00000038;
            in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
            *(undefined4 *)(pcVar11 + 8) = uVar8;
            uVar15 = 0;
            if (uVar4 != 0) {
              uVar27 = 0;
              puVar18 = puVar3;
              puVar23 = puVar20;
              puVar25 = puVar21;
              do {
                uVar8 = *puVar23;
                puVar23 = puVar23 + 1;
                *(undefined4 *)(pcVar11 + 4) = uVar8;
                uVar8 = *puVar18;
                puVar18 = puVar18 + 1;
                *(undefined4 *)(pcVar11 + 0xc) = uVar8;
                if (uVar13 != 0) {
                  FUN_0000a3f0(pcVar11,pcVar11 + *(ushort *)(pcVar11 + 0x58) + 2,0,0x5b);
                }
                uVar15 = iptc_insert_entry();
                puVar25 = (undefined4 *)((uint)puVar25 & uVar15);
                uVar27 = uVar27 + 1;
                puVar21 = puVar25;
              } while (uVar27 != uVar4);
            }
            in_stack_00000034 = (undefined4 *)((int)in_stack_00000034 + 1);
          } while (in_stack_00000034 != (undefined4 *)uVar17);
          FUN_0000bc28(uVar15,puVar25);
          return;
        }
LAB_0000bd98:
                    /* WARNING: Subroutine does not return */
        FUN_0000a2c4(2);
      }
      if (puVar21 != (undefined4 *)0x20) {
        if ((undefined4 *)0x20 < puVar21) {
          FUN_0000c310();
        }
        uVar17 = in_stack_000000b8;
        uVar4 = in_stack_000000b4;
        puVar3 = in_stack_000000a8;
        puVar25 = in_stack_000000a4;
        if (puVar21 == (undefined4 *)0x10) {
          uVar15 = (uint)in_stack_000000a0 & 0x20;
          uVar13 = 1;
          if (in_stack_000000b8 == 0) {
            FUN_0000bc28();
            return;
          }
          in_stack_00000034 = in_stack_000000ac;
          in_stack_00000038 = (char *)in_stack_000000b0;
          in_stack_00000030 = 0;
          uVar27 = in_stack_000000b8;
          do {
            uVar8 = *(undefined4 *)in_stack_00000038;
            in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
            *(undefined4 *)pcVar11 = uVar8;
            uVar8 = *in_stack_00000034;
            in_stack_00000034 = in_stack_00000034 + 1;
            *(undefined4 *)(pcVar11 + 8) = uVar8;
            if (uVar4 == 0) {
              uVar6 = 0;
            }
            else {
              uVar26 = 0;
              puVar21 = puVar25;
              puVar20 = puVar3;
              uVar27 = uVar13;
              do {
                uVar8 = *puVar20;
                puVar20 = puVar20 + 1;
                *(undefined4 *)(pcVar11 + 4) = uVar8;
                uVar8 = *puVar21;
                puVar21 = puVar21 + 1;
                *(undefined4 *)(pcVar11 + 0xc) = uVar8;
                if (uVar15 != 0) {
                  FUN_0000a3f0(pcVar11,pcVar11 + *(ushort *)(pcVar11 + 0x58) + 2,0,0x5b);
                }
                uVar6 = iptc_append_entry();
                uVar27 = uVar27 & uVar6;
                uVar26 = uVar26 + 1;
                uVar13 = uVar27;
              } while (uVar26 != uVar4);
            }
            in_stack_00000030 = in_stack_00000030 + 1;
          } while (in_stack_00000030 != uVar17);
          FUN_0000bc28(uVar6,uVar27);
          return;
        }
        goto LAB_0000bd98;
      }
      goto LAB_0000bfbc;
    }
    if (puVar21 != (undefined4 *)0x1000) {
      if (puVar21 < (undefined4 *)0x1001) {
        if (puVar21 == (undefined4 *)0x200) {
LAB_0000c3b8:
          delete_chain();
          FUN_0000bc28();
          puVar25 = in_stack_00000050;
        }
        else {
          if ((undefined4 *)0x200 < puVar21) {
            if (puVar21 == (undefined4 *)0x400) goto LAB_0000c3f4;
            if (puVar21 != (undefined4 *)0x800) goto LAB_0000bd98;
            iptc_rename_chain();
            FUN_0000bc28();
            goto LAB_0000c3b8;
          }
          if (puVar21 != (undefined4 *)0x100) goto LAB_0000bd98;
        }
        iptc_create_chain();
        FUN_0000bc28();
        flush_entries();
        FUN_0000bc28();
        puVar21 = in_stack_00000050;
LAB_0000c3f4:
        in_stack_00000048 = iptc_set_policy();
        FUN_0000bc28();
        pcVar9 = pcVar11;
        unaff_r5 = __src;
        pcVar11 = unaff_r10;
        goto LAB_0000c410;
      }
      puVar25 = (undefined4 *)0x2000;
      if (puVar21 == (undefined4 *)0x2000) {
        FUN_0000c32e();
        puVar25 = extraout_r3_01;
      }
      if (puVar25 < puVar21) {
        if (puVar21 == DAT_0000bfb8) goto LAB_0000bfbc;
        if (puVar21 != (undefined4 *)0x3000) goto LAB_0000bd98;
      }
      else if (puVar21 != (undefined4 *)0x1080) goto LAB_0000bd98;
    }
    uVar22 = *in_stack_00000050;
    uVar8 = 0;
    if (((uint)in_stack_000000a0 & 0x20) != 0) {
      uVar8 = 0xffffffff;
    }
    if (in_stack_00000048 == 0) {
      FUN_0000c558();
    }
    pcVar9 = (char *)iptc_first_chain(uVar22);
    if (pcVar9 != (char *)0x0) {
      bVar2 = false;
      do {
        if ((unaff_r11 == (char *)0x0) || (iVar12 = strcmp(pcVar9,unaff_r11), iVar12 == 0)) {
          iVar12 = iptc_first_rule(pcVar9,uVar22);
          if (iVar12 != 0) {
            uVar4 = 0;
            do {
              uVar4 = uVar4 + 1;
              if ((in_stack_00000048 == uVar4) || (in_stack_00000048 == 0)) {
                FUN_0000a9b0(iVar12,uVar22,pcVar9,uVar8);
              }
              iVar12 = iptc_next_rule(iVar12,uVar22);
            } while (iVar12 != 0);
          }
          bVar2 = true;
        }
        pcVar9 = (char *)iptc_next_chain(uVar22);
      } while (pcVar9 != (char *)0x0);
      uVar28 = __errno();
      *(undefined4 *)uVar28 = 2;
      if (bVar2) {
        iVar12 = 1;
        goto joined_r0x0000bc12;
      }
      goto LAB_0000bea0;
    }
  }
  uVar28 = __errno();
  *(undefined4 *)uVar28 = 2;
LAB_0000bea0:
  FUN_0000bc28((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),0);
  return;
}



/* Function: FUN_0000bada @ 0000bada */

void FUN_0000bada(void)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *extraout_r3;
  void *pvVar13;
  uint uVar14;
  char *unaff_r4;
  void *pvVar15;
  ushort *unaff_r5;
  undefined4 *puVar16;
  int iVar17;
  FILE *pFVar18;
  code *__format;
  undefined4 *puVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  undefined4 *unaff_r7;
  int unaff_r8;
  ushort *unaff_r9;
  char *unaff_r10;
  undefined4 *puVar22;
  char *unaff_r11;
  undefined8 uVar23;
  void *in_stack_0000002c;
  uint uStack00000030;
  undefined4 *puStack00000034;
  char *in_stack_00000038;
  undefined4 *puStack0000003c;
  uint in_stack_00000040;
  int in_stack_00000048;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  uint in_stack_000000a0;
  undefined4 *in_stack_000000a4;
  undefined4 *in_stack_000000a8;
  undefined4 *in_stack_000000ac;
  undefined4 *in_stack_000000b0;
  int in_stack_000000b4;
  uint in_stack_000000b8;
  int in_stack_00000134;
  
  memcpy((void *)(unaff_r8 + (int)unaff_r7),unaff_r9,(uint)*unaff_r9);
  free(*(void **)(in_stack_00000038 + 0x38));
  puVar22 = in_stack_0000009c;
  if (in_stack_0000009c == (undefined4 *)0xa0) {
LAB_0000bfbc:
    unaff_r7 = (undefined4 *)*in_stack_00000050;
    puVar22 = (undefined4 *)0x48;
    if (-1 < (int)(in_stack_000000a0 << 0x1a)) {
      puVar22 = (undefined4 *)0xa;
    }
    if ((in_stack_000000a0 & 1) != 0) {
      puVar22 = (undefined4 *)((uint)puVar22 | 1);
    }
    if ((in_stack_000000a0 & 0x40) == 0) {
      puVar22 = (undefined4 *)((uint)puVar22 | 4);
    }
    if ((in_stack_000000a0 & 0x400) != 0) {
      puVar22 = (undefined4 *)((uint)puVar22 | 0x100);
    }
    pcVar7 = (char *)iptc_first_chain(unaff_r7);
    if (pcVar7 != (char *)0x0) {
      in_stack_0000002c = (void *)(uint)(in_stack_00000048 == 0);
      in_stack_00000040 = (uint)puVar22 & 0x100;
      in_stack_00000038 = (char *)(DAT_0000c340 + 0xc028);
      iVar17 = 0;
      do {
        if ((unaff_r11 == (char *)0x0) || (iVar8 = strcmp(unaff_r11,pcVar7), iVar8 == 0)) {
          if (iVar17 != 0) {
            putchar(10);
          }
          if (in_stack_00000048 == 0) {
            iVar17 = iptc_get_policy(pcVar7,&stack0x00000078,unaff_r7);
            printf(in_stack_00000038,pcVar7);
            if (iVar17 == 0) {
              iVar17 = iptc_get_references(&stack0x00000094,pcVar7,unaff_r7);
              if (iVar17 == 0) {
                puts((char *)(DAT_0000c76c + 0xc4d4));
                uStack00000030 = DAT_0000c770;
              }
              else {
                printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
                uStack00000030 = iRam0000c8f4;
              }
            }
            else {
              printf((char *)(DAT_0000c344 + 0xc10c));
              if ((int)puVar22 << 0x1e < 0) {
                uStack00000030 = DAT_0000c348;
              }
              else {
                uStack00000030 = DAT_0000c770;
                pFVar18 = (FILE *)(*(int *)((int)unaff_r5 + DAT_0000c770) + 0x54);
                fputc(0x20,pFVar18);
                FUN_0000a018(in_stack_00000078,in_stack_0000007c,(uint)puVar22 | 0x10);
                fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar18);
                FUN_0000a018(in_stack_00000080,in_stack_00000084,(uint)puVar22 | 0x10);
                fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar18);
              }
              puts((char *)(DAT_0000c34c + 0xc11e));
            }
            if (in_stack_00000040 != 0) {
              if ((int)puVar22 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c768 + 0xc4be);
              }
              else {
                pcVar10 = (char *)(DAT_0000c350 + 0xc132);
              }
              printf(pcVar10,DAT_0000c354 + 0xc136);
            }
            if (-1 < (int)puVar22 << 0x1e) {
              if ((int)puVar22 << 0x1d < 0) {
                if ((int)puVar22 << 0x1b < 0) {
                  pcVar10 = (char *)(DAT_0000c358 + 0xc150);
                  printf(pcVar10,DAT_0000c35c + 0xc152);
                }
                else {
                  pcVar10 = (char *)(DAT_0000c77c + 0xc530);
                  printf(pcVar10,DAT_0000c780 + 0xc532);
                }
                printf(pcVar10,DAT_0000c360 + 0xc15e);
              }
              else {
                if ((int)puVar22 << 0x1b < 0) {
                  __format = (code *)(DAT_0000c784 + 0xc546);
                  printf((char *)__format,DAT_0000c788 + 0xc548);
                }
                else {
                  printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
                  __format = FUN_0000c61e + DAT_0000c7b0;
                }
                printf((char *)__format,DAT_0000c78c + 0xc554);
              }
            }
            if (-1 < (int)puVar22 << 0x1a) {
              if ((int)puVar22 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c75c + 0xc478);
              }
              else {
                pcVar10 = (char *)(DAT_0000c364 + 0xc170);
              }
              printf(pcVar10,DAT_0000c368 + 0xc174);
            }
            pFVar18 = (FILE *)(*(int *)((int)unaff_r5 + uStack00000030) + 0x54);
            fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar18);
            if ((int)puVar22 << 0x1c < 0) {
              fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar18);
            }
            if ((int)puVar22 << 0x19 < 0) {
              if ((int)puVar22 << 0x1b < 0) {
                pcVar10 = (char *)(DAT_0000c760 + 0xc480);
                printf(pcVar10,DAT_0000c764 + 0xc482);
              }
              else {
                printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
                pcVar10 = (char *)(DAT_0000c37c + 0xc1ba);
              }
              printf(pcVar10,DAT_0000c380 + 0xc1be);
            }
            if ((int)puVar22 << 0x1b < 0) {
              printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
              pcVar10 = (char *)(DAT_0000c38c + 0xc1d8);
            }
            else {
LAB_0000c410:
              pcVar10 = (char *)(iRam0000c754 + 0xc418);
              printf(pcVar10,DAT_0000c758 + 0xc41a);
            }
            printf(pcVar10,DAT_0000c390 + 0xc1dc);
            putchar(10);
          }
          iVar17 = iptc_first_rule(pcVar7,unaff_r7);
          if (iVar17 != 0) {
            iVar8 = 0;
            do {
              iVar8 = iVar8 + 1;
              if ((in_stack_00000048 == iVar8) || (in_stack_0000002c != (void *)0x0)) {
                uVar9 = iptc_get_target(iVar17,unaff_r7);
                FUN_0000a3f0(iVar17,uVar9,iVar8,puVar22);
              }
              iVar17 = iptc_next_rule(iVar17,unaff_r7);
            } while (iVar17 != 0);
          }
          iVar17 = 1;
        }
        pcVar7 = (char *)iptc_next_chain(unaff_r7);
      } while (pcVar7 != (char *)0x0);
      uVar23 = __errno();
      *(undefined4 *)uVar23 = 2;
      if (iVar17 != 0) {
joined_r0x0000bc12:
        if (((int)in_stack_0000009c << 0x18 < 0) && (iVar17 = FUN_0000acf0(), iVar17 == 0)) {
          FUN_0000bc28();
          return;
        }
        if ((int)in_stack_0000009c << 0x12 < 0) {
          iVar17 = iptc_zero_counter();
        }
        puVar22 = in_stack_00000098;
        if (1 < in_stack_00000054) {
          dump_entries(*in_stack_00000050);
          puVar22 = in_stack_00000098;
        }
        while (puVar22 != (void *)0x0) {
          pvVar13 = (void *)puVar22[1];
          pvVar15 = (void *)*puVar22;
          if (*(void **)((int)pvVar13 + 0x38) != (void *)0x0) {
            free(*(void **)((int)pvVar13 + 0x38));
            *(undefined4 *)(puVar22[1] + 0x38) = 0;
            pvVar13 = (void *)puVar22[1];
          }
          if (pvVar13 == *(void **)((int)pvVar13 + 4)) {
            free(pvVar13);
            puVar22[1] = 0;
          }
          free(puVar22);
          puVar22 = pvVar15;
        }
        in_stack_00000098 = (undefined4 *)0x0;
        if (unaff_r4 != (char *)0x0) {
          free(unaff_r4);
        }
        free(in_stack_000000b0);
        free(in_stack_000000ac);
        free(in_stack_000000a8);
        free(in_stack_000000a4);
        FUN_00021f14(1);
        if (in_stack_00000134 != **(int **)((int)unaff_r5 + in_stack_00000058)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail(iVar17);
        }
        return;
      }
      goto LAB_0000bea0;
    }
  }
  else {
    if (in_stack_0000009c < (undefined4 *)0xa1) {
      if (in_stack_0000009c == (undefined4 *)0x8) {
        FUN_0000c422();
      }
      uVar4 = in_stack_000000b8;
      iVar17 = in_stack_000000b4;
      puVar16 = in_stack_000000b0;
      puVar19 = in_stack_000000a8;
      puVar3 = in_stack_000000a4;
      puVar12 = in_stack_00000098;
      if (puVar22 < (undefined4 *)0x9) {
        if (puVar22 == (undefined4 *)0x2) {
          uVar14 = in_stack_000000a0 & 0x20;
          puStack0000003c = in_stack_000000ac;
          if (in_stack_00000098 == (undefined4 *)0x0) {
            in_stack_0000002c = (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x90);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar13 = (void *)((int)in_stack_0000002c + 0x70);
          }
          else {
            iVar8 = 0x70;
            puVar22 = in_stack_00000098;
            do {
              piVar1 = puVar22 + 1;
              puVar22 = (undefined4 *)*puVar22;
              iVar8 = iVar8 + *(int *)(*piVar1 + 0x10) + 0x20;
            } while (puVar22 != (undefined4 *)0x0);
            in_stack_0000002c =
                 (void *)FUN_00023304(1,*(int *)(in_stack_00000038 + 0x10) + 0x20 + iVar8);
            memset(in_stack_0000002c,0xff,0x70);
            pvVar13 = (void *)((int)in_stack_0000002c + 0x70);
            do {
              memset(pvVar13,0xff,*(int *)(puVar12[1] + 0x14) + 0x20);
              piVar1 = puVar12 + 1;
              puVar12 = (undefined4 *)*puVar12;
              pvVar13 = (void *)((int)pvVar13 + *(int *)(*piVar1 + 0x10) + 0x20);
            } while (puVar12 != (undefined4 *)0x0);
          }
          memset(pvVar13,0xff,*(int *)(in_stack_00000038 + 0x14) + 0x20);
          if (uVar4 != 0) {
            in_stack_00000038 = (char *)puVar16;
            puStack00000034 = (undefined4 *)0x0;
            do {
              uVar9 = *(undefined4 *)in_stack_00000038;
              in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
              *(undefined4 *)unaff_r4 = uVar9;
              uVar9 = *puStack0000003c;
              puStack0000003c = puStack0000003c + 1;
              *(undefined4 *)(unaff_r4 + 8) = uVar9;
              if (iVar17 != 0) {
                iVar8 = 0;
                puVar22 = puVar3;
                puVar12 = puVar19;
                do {
                  uVar9 = *puVar12;
                  puVar12 = puVar12 + 1;
                  *(undefined4 *)(unaff_r4 + 4) = uVar9;
                  uVar9 = *puVar22;
                  puVar22 = puVar22 + 1;
                  *(undefined4 *)(unaff_r4 + 0xc) = uVar9;
                  if (uVar14 != 0) {
                    FUN_0000a3f0(unaff_r4,unaff_r4 + *(ushort *)(unaff_r4 + 0x58) + 2,0,0x5b);
                  }
                  iptc_delete_entry();
                  iVar8 = iVar8 + 1;
                } while (iVar8 != iVar17);
              }
              puStack00000034 = (undefined4 *)((int)puStack00000034 + 1);
            } while (puStack00000034 != (undefined4 *)uVar4);
          }
          free(in_stack_0000002c);
          FUN_0000bc28();
          return;
        }
        if (puVar22 == (undefined4 *)0x4) {
          iptc_delete_num_entry();
          FUN_0000bc28();
          return;
        }
        if (puVar22 == (undefined4 *)0x1) {
          uVar14 = in_stack_000000a0 & 0x20;
          puVar22 = (undefined4 *)0x1;
          if (in_stack_000000b8 == 0) {
            FUN_0000bc28();
            return;
          }
          puStack0000003c = in_stack_000000b0;
          in_stack_00000038 = (char *)in_stack_000000ac;
          puStack00000034 = (undefined4 *)0x0;
          puVar12 = in_stack_000000ac;
          do {
            uVar9 = *puStack0000003c;
            puStack0000003c = puStack0000003c + 1;
            *(undefined4 *)unaff_r4 = uVar9;
            uVar9 = *(undefined4 *)in_stack_00000038;
            in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
            *(undefined4 *)(unaff_r4 + 8) = uVar9;
            uVar6 = 0;
            if (iVar17 != 0) {
              iVar8 = 0;
              puVar16 = puVar3;
              puVar21 = puVar19;
              puVar12 = puVar22;
              do {
                uVar9 = *puVar21;
                puVar21 = puVar21 + 1;
                *(undefined4 *)(unaff_r4 + 4) = uVar9;
                uVar9 = *puVar16;
                puVar16 = puVar16 + 1;
                *(undefined4 *)(unaff_r4 + 0xc) = uVar9;
                if (uVar14 != 0) {
                  FUN_0000a3f0(unaff_r4,unaff_r4 + *(ushort *)(unaff_r4 + 0x58) + 2,0,0x5b);
                }
                uVar6 = iptc_insert_entry();
                puVar12 = (undefined4 *)((uint)puVar12 & uVar6);
                iVar8 = iVar8 + 1;
                puVar22 = puVar12;
              } while (iVar8 != iVar17);
            }
            puStack00000034 = (undefined4 *)((int)puStack00000034 + 1);
          } while (puStack00000034 != (undefined4 *)uVar4);
          FUN_0000bc28(uVar6,puVar12);
          return;
        }
LAB_0000bd98:
                    /* WARNING: Subroutine does not return */
        FUN_0000a2c4(2);
      }
      if (puVar22 != (undefined4 *)0x20) {
        if ((undefined4 *)0x20 < puVar22) {
          FUN_0000c310();
        }
        uVar4 = in_stack_000000b8;
        iVar17 = in_stack_000000b4;
        puVar3 = in_stack_000000a8;
        puVar12 = in_stack_000000a4;
        if (puVar22 == (undefined4 *)0x10) {
          uVar6 = in_stack_000000a0 & 0x20;
          uVar14 = 1;
          if (in_stack_000000b8 == 0) {
            FUN_0000bc28();
            return;
          }
          puStack00000034 = in_stack_000000ac;
          in_stack_00000038 = (char *)in_stack_000000b0;
          uStack00000030 = 0;
          uVar11 = in_stack_000000b8;
          do {
            uVar9 = *(undefined4 *)in_stack_00000038;
            in_stack_00000038 = (char *)((int)in_stack_00000038 + 4);
            *(undefined4 *)unaff_r4 = uVar9;
            uVar9 = *puStack00000034;
            puStack00000034 = puStack00000034 + 1;
            *(undefined4 *)(unaff_r4 + 8) = uVar9;
            if (iVar17 == 0) {
              uVar5 = 0;
            }
            else {
              iVar8 = 0;
              puVar22 = puVar12;
              puVar19 = puVar3;
              uVar11 = uVar14;
              do {
                uVar9 = *puVar19;
                puVar19 = puVar19 + 1;
                *(undefined4 *)(unaff_r4 + 4) = uVar9;
                uVar9 = *puVar22;
                puVar22 = puVar22 + 1;
                *(undefined4 *)(unaff_r4 + 0xc) = uVar9;
                if (uVar6 != 0) {
                  FUN_0000a3f0(unaff_r4,unaff_r4 + *(ushort *)(unaff_r4 + 0x58) + 2,0,0x5b);
                }
                uVar5 = iptc_append_entry();
                uVar11 = uVar11 & uVar5;
                iVar8 = iVar8 + 1;
                uVar14 = uVar11;
              } while (iVar8 != iVar17);
            }
            uStack00000030 = uStack00000030 + 1;
          } while (uStack00000030 != uVar4);
          FUN_0000bc28(uVar5,uVar11);
          return;
        }
        goto LAB_0000bd98;
      }
      goto LAB_0000bfbc;
    }
    if (in_stack_0000009c != (undefined4 *)0x1000) {
      if (in_stack_0000009c < (undefined4 *)0x1001) {
        if (in_stack_0000009c == (undefined4 *)0x200) {
LAB_0000c3b8:
          delete_chain();
          FUN_0000bc28();
          unaff_r7 = in_stack_00000050;
        }
        else {
          if ((undefined4 *)0x200 < in_stack_0000009c) {
            if (in_stack_0000009c == (undefined4 *)0x400) goto LAB_0000c3f4;
            if (in_stack_0000009c != (undefined4 *)0x800) goto LAB_0000bd98;
            iptc_rename_chain();
            FUN_0000bc28();
            goto LAB_0000c3b8;
          }
          if (in_stack_0000009c != (undefined4 *)0x100) goto LAB_0000bd98;
        }
        iptc_create_chain();
        FUN_0000bc28();
        flush_entries();
        FUN_0000bc28();
        puVar22 = in_stack_00000050;
LAB_0000c3f4:
        in_stack_00000048 = iptc_set_policy();
        FUN_0000bc28();
        pcVar7 = unaff_r4;
        unaff_r5 = unaff_r9;
        unaff_r4 = unaff_r10;
        goto LAB_0000c410;
      }
      puVar12 = (undefined4 *)0x2000;
      if (in_stack_0000009c == (undefined4 *)0x2000) {
        FUN_0000c32e();
        puVar12 = extraout_r3;
      }
      if (puVar12 < puVar22) {
        if (puVar22 == DAT_0000bfb8) goto LAB_0000bfbc;
        if (puVar22 != (undefined4 *)0x3000) goto LAB_0000bd98;
      }
      else if (puVar22 != (undefined4 *)0x1080) goto LAB_0000bd98;
    }
    uVar20 = *in_stack_00000050;
    uVar9 = 0;
    if ((in_stack_000000a0 & 0x20) != 0) {
      uVar9 = 0xffffffff;
    }
    if (in_stack_00000048 == 0) {
      FUN_0000c558();
    }
    pcVar7 = (char *)iptc_first_chain(uVar20);
    if (pcVar7 != (char *)0x0) {
      bVar2 = false;
      do {
        if ((unaff_r11 == (char *)0x0) || (iVar17 = strcmp(pcVar7,unaff_r11), iVar17 == 0)) {
          iVar17 = iptc_first_rule(pcVar7,uVar20);
          if (iVar17 != 0) {
            iVar8 = 0;
            do {
              iVar8 = iVar8 + 1;
              if ((in_stack_00000048 == iVar8) || (in_stack_00000048 == 0)) {
                FUN_0000a9b0(iVar17,uVar20,pcVar7,uVar9);
              }
              iVar17 = iptc_next_rule(iVar17,uVar20);
            } while (iVar17 != 0);
          }
          bVar2 = true;
        }
        pcVar7 = (char *)iptc_next_chain(uVar20);
      } while (pcVar7 != (char *)0x0);
      uVar23 = __errno();
      *(undefined4 *)uVar23 = 2;
      if (bVar2) {
        iVar17 = 1;
        goto joined_r0x0000bc12;
      }
      goto LAB_0000bea0;
    }
  }
  uVar23 = __errno();
  *(undefined4 *)uVar23 = 2;
LAB_0000bea0:
  FUN_0000bc28((int)uVar23,(int)((ulonglong)uVar23 >> 0x20),0);
  return;
}



/* Function: FUN_0000bb8c @ 0000bb8c */

void FUN_0000bb8c(void)

{
  bool bVar1;
  char *__s1;
  int iVar2;
  void *__ptr;
  void *unaff_r4;
  void *pvVar3;
  int unaff_r5;
  int iVar4;
  undefined4 unaff_r8;
  char *unaff_r11;
  undefined8 uVar5;
  int in_stack_00000048;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 *in_stack_00000098;
  int in_stack_0000009c;
  void *in_stack_000000a4;
  void *in_stack_000000a8;
  void *in_stack_000000ac;
  void *in_stack_000000b0;
  int in_stack_00000134;
  
  __s1 = (char *)iptc_first_chain();
  if (__s1 == (char *)0x0) {
    uVar5 = __errno();
    *(undefined4 *)uVar5 = 2;
  }
  else {
    bVar1 = false;
    do {
      if ((unaff_r11 == (char *)0x0) || (iVar2 = strcmp(__s1,unaff_r11), iVar2 == 0)) {
        iVar2 = iptc_first_rule(__s1,unaff_r8);
        if (iVar2 != 0) {
          iVar4 = 0;
          do {
            iVar4 = iVar4 + 1;
            if ((in_stack_00000048 == iVar4) || (in_stack_00000048 == 0)) {
              FUN_0000a9b0(iVar2,unaff_r8,__s1);
            }
            iVar2 = iptc_next_rule(iVar2,unaff_r8);
          } while (iVar2 != 0);
        }
        bVar1 = true;
      }
      __s1 = (char *)iptc_next_chain(unaff_r8);
    } while (__s1 != (char *)0x0);
    uVar5 = __errno();
    *(undefined4 *)uVar5 = 2;
    if (bVar1) {
      iVar2 = 1;
      if ((in_stack_0000009c << 0x18 < 0) && (iVar2 = FUN_0000acf0(), iVar2 == 0)) {
        FUN_0000bc28();
        return;
      }
      if (in_stack_0000009c << 0x12 < 0) {
        iVar2 = iptc_zero_counter();
      }
      if (1 < in_stack_00000054) {
        dump_entries(*in_stack_00000050);
      }
      while (in_stack_00000098 != (void *)0x0) {
        __ptr = (void *)in_stack_00000098[1];
        pvVar3 = (void *)*in_stack_00000098;
        if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
          free(*(void **)((int)__ptr + 0x38));
          *(undefined4 *)(in_stack_00000098[1] + 0x38) = 0;
          __ptr = (void *)in_stack_00000098[1];
        }
        if (__ptr == *(void **)((int)__ptr + 4)) {
          free(__ptr);
          in_stack_00000098[1] = 0;
        }
        free(in_stack_00000098);
        in_stack_00000098 = pvVar3;
      }
      if (unaff_r4 != (void *)0x0) {
        free(unaff_r4);
      }
      free(in_stack_000000b0);
      free(in_stack_000000ac);
      free(in_stack_000000a8);
      free(in_stack_000000a4);
      FUN_00021f14(1);
      if (in_stack_00000134 == **(int **)(unaff_r5 + in_stack_00000058)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(iVar2);
    }
  }
  FUN_0000bc28((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0);
  return;
}



/* Function: FUN_0000bc28 @ 0000bc28 */

void FUN_0000bc28(void)

{
  void *__ptr;
  void *unaff_r4;
  void *pvVar1;
  int unaff_r5;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 *in_stack_00000098;
  void *in_stack_000000a4;
  void *in_stack_000000a8;
  void *in_stack_000000ac;
  void *in_stack_000000b0;
  int in_stack_00000134;
  
  if (1 < in_stack_00000054) {
    dump_entries(*in_stack_00000050);
  }
  while (in_stack_00000098 != (void *)0x0) {
    __ptr = (void *)in_stack_00000098[1];
    pvVar1 = (void *)*in_stack_00000098;
    if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
      free(*(void **)((int)__ptr + 0x38));
      *(undefined4 *)(in_stack_00000098[1] + 0x38) = 0;
      __ptr = (void *)in_stack_00000098[1];
    }
    if (__ptr == *(void **)((int)__ptr + 4)) {
      free(__ptr);
      in_stack_00000098[1] = 0;
    }
    free(in_stack_00000098);
    in_stack_00000098 = pvVar1;
  }
  if (unaff_r4 != (void *)0x0) {
    free(unaff_r4);
  }
  free(in_stack_000000b0);
  free(in_stack_000000ac);
  free(in_stack_000000a8);
  free(in_stack_000000a4);
  FUN_00021f14(1);
  if (in_stack_00000134 == **(int **)(unaff_r5 + in_stack_00000058)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_0000c310 @ 0000c310 */

/* WARNING: Removing unreachable block (ram,0x0000bea0) */

void FUN_0000c310(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  void *__ptr;
  void *pvVar5;
  char *unaff_r4;
  int iVar6;
  FILE *pFVar7;
  char *pcVar8;
  code *__format;
  int unaff_r6;
  undefined4 unaff_r7;
  int unaff_r9;
  void *unaff_r10;
  char *unaff_r11;
  int in_stack_0000002c;
  int iStack00000030;
  char *in_stack_00000038;
  int in_stack_00000040;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  int in_stack_0000009c;
  undefined4 in_stack_000000a0;
  void *in_stack_000000a4;
  void *in_stack_000000a8;
  void *in_stack_000000ac;
  void *in_stack_000000b0;
  int in_stack_00000134;
  
  if (unaff_r6 != 0x40) {
    if (unaff_r6 != 0x80) {
                    /* WARNING: Subroutine does not return */
      FUN_0000a2c4(2);
    }
    FUN_0000acf0();
    FUN_0000bc28();
    return;
  }
  flush_entries();
  FUN_0000bc28();
  iVar4 = iptc_set_policy();
  FUN_0000bc28();
  do {
    pcVar8 = (char *)(iRam0000c754 + 0xc418);
    printf(pcVar8,DAT_0000c758 + 0xc41a);
    while( true ) {
      printf(pcVar8,DAT_0000c390 + 0xc1dc);
      putchar(10);
      do {
        iVar1 = iptc_first_rule(unaff_r4,unaff_r7);
        if (iVar1 != 0) {
          iVar6 = 0;
          do {
            iVar6 = iVar6 + 1;
            if ((iVar4 == iVar6) || (in_stack_0000002c != 0)) {
              uVar2 = iptc_get_target(iVar1,unaff_r7);
              FUN_0000a3f0(iVar1,uVar2,iVar6,in_stack_00000050);
            }
            iVar1 = iptc_next_rule(iVar1,unaff_r7);
          } while (iVar1 != 0);
        }
        iVar1 = 1;
        do {
          unaff_r4 = (char *)iptc_next_chain(unaff_r7);
          if (unaff_r4 == (char *)0x0) {
            puVar3 = (undefined4 *)__errno();
            *puVar3 = 2;
            if ((in_stack_0000009c << 0x18 < 0) && (iVar1 = FUN_0000acf0(), iVar1 == 0)) {
              FUN_0000bc28();
              return;
            }
            if (in_stack_0000009c << 0x12 < 0) {
              iVar1 = iptc_zero_counter();
            }
            puVar3 = in_stack_00000098;
            if (1 < in_stack_00000054) {
              dump_entries(*in_stack_00000050);
              puVar3 = in_stack_00000098;
            }
            while (puVar3 != (void *)0x0) {
              __ptr = (void *)puVar3[1];
              pvVar5 = (void *)*puVar3;
              if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
                free(*(void **)((int)__ptr + 0x38));
                *(undefined4 *)(puVar3[1] + 0x38) = 0;
                __ptr = (void *)puVar3[1];
              }
              if (__ptr == *(void **)((int)__ptr + 4)) {
                free(__ptr);
                puVar3[1] = 0;
              }
              free(puVar3);
              puVar3 = pvVar5;
            }
            in_stack_00000098 = (undefined4 *)0x0;
            if (unaff_r10 != (void *)0x0) {
              free(unaff_r10);
            }
            free(in_stack_000000b0);
            free(in_stack_000000ac);
            free(in_stack_000000a8);
            free(in_stack_000000a4);
            FUN_00021f14(1);
            if (in_stack_00000134 != **(int **)(unaff_r9 + in_stack_00000058)) {
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail(iVar1);
            }
            return;
          }
        } while ((unaff_r11 != (char *)0x0) && (iVar6 = strcmp(unaff_r11,unaff_r4), iVar6 != 0));
        putchar(10);
      } while (iVar4 != 0);
      iVar1 = iptc_get_policy(unaff_r4,&stack0x00000078,unaff_r7);
      printf(in_stack_00000038,unaff_r4);
      if (iVar1 == 0) {
        iVar1 = iptc_get_references(&stack0x00000094,unaff_r4,unaff_r7);
        if (iVar1 == 0) {
          puts((char *)(DAT_0000c76c + 0xc4d4));
          iStack00000030 = DAT_0000c770;
        }
        else {
          printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
          iStack00000030 = iRam0000c8f4;
        }
      }
      else {
        printf((char *)(DAT_0000c344 + 0xc10c));
        if ((int)in_stack_00000050 << 0x1e < 0) {
          iStack00000030 = DAT_0000c348;
        }
        else {
          iStack00000030 = DAT_0000c770;
          pFVar7 = (FILE *)(*(int *)(unaff_r9 + DAT_0000c770) + 0x54);
          fputc(0x20,pFVar7);
          FUN_0000a018(in_stack_00000078,in_stack_0000007c,(uint)in_stack_00000050 | 0x10);
          fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar7);
          FUN_0000a018(in_stack_00000080,in_stack_00000084,(uint)in_stack_00000050 | 0x10);
          fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar7);
        }
        puts((char *)(DAT_0000c34c + 0xc11e));
      }
      if (in_stack_00000040 != 0) {
        if ((int)in_stack_00000050 << 0x1b < 0) {
          pcVar8 = (char *)(DAT_0000c768 + 0xc4be);
        }
        else {
          pcVar8 = (char *)(DAT_0000c350 + 0xc132);
        }
        printf(pcVar8,DAT_0000c354 + 0xc136);
      }
      if (-1 < (int)in_stack_00000050 << 0x1e) {
        if ((int)in_stack_00000050 << 0x1d < 0) {
          if ((int)in_stack_00000050 << 0x1b < 0) {
            pcVar8 = (char *)(DAT_0000c358 + 0xc150);
            printf(pcVar8,DAT_0000c35c + 0xc152);
          }
          else {
            pcVar8 = (char *)(DAT_0000c77c + 0xc530);
            printf(pcVar8,DAT_0000c780 + 0xc532);
          }
          printf(pcVar8,DAT_0000c360 + 0xc15e);
        }
        else {
          if ((int)in_stack_00000050 << 0x1b < 0) {
            __format = (code *)(DAT_0000c784 + 0xc546);
            printf((char *)__format,DAT_0000c788 + 0xc548);
          }
          else {
            printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
            __format = FUN_0000c61e + DAT_0000c7b0;
          }
          printf((char *)__format,DAT_0000c78c + 0xc554);
        }
      }
      if (-1 < (int)in_stack_00000050 << 0x1a) {
        if ((int)in_stack_00000050 << 0x1b < 0) {
          pcVar8 = (char *)(DAT_0000c75c + 0xc478);
        }
        else {
          pcVar8 = (char *)(DAT_0000c364 + 0xc170);
        }
        printf(pcVar8,DAT_0000c368 + 0xc174);
      }
      pFVar7 = (FILE *)(*(int *)(unaff_r9 + iStack00000030) + 0x54);
      fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar7);
      if ((int)in_stack_00000050 << 0x1c < 0) {
        fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar7);
      }
      if ((int)in_stack_00000050 << 0x19 < 0) {
        if ((int)in_stack_00000050 << 0x1b < 0) {
          pcVar8 = (char *)(DAT_0000c760 + 0xc480);
          printf(pcVar8,DAT_0000c764 + 0xc482);
        }
        else {
          printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
          pcVar8 = (char *)(DAT_0000c37c + 0xc1ba);
        }
        printf(pcVar8,DAT_0000c380 + 0xc1be);
      }
      if (-1 < (int)in_stack_00000050 << 0x1b) break;
      printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
      pcVar8 = (char *)(DAT_0000c38c + 0xc1d8);
    }
  } while( true );
}



/* Function: FUN_0000c32e @ 0000c32e */

void FUN_0000c32e(void)

{
  iptc_zero_counter();
  FUN_0000bc28();
  return;
}



/* Function: FUN_0000c422 @ 0000c422 */

/* WARNING: Removing unreachable block (ram,0x0000bea0) */

void FUN_0000c422(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  void *__ptr;
  void *pvVar6;
  char *unaff_r4;
  int iVar7;
  FILE *pFVar8;
  code *__format;
  uint uVar9;
  int unaff_r9;
  void *unaff_r10;
  char *unaff_r11;
  int in_stack_0000002c;
  int in_stack_00000030;
  char *in_stack_00000038;
  int in_stack_00000040;
  int in_stack_00000048;
  uint *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  int in_stack_0000009c;
  int in_stack_000000a0;
  undefined4 *in_stack_000000a4;
  undefined4 *in_stack_000000a8;
  undefined4 *in_stack_000000ac;
  undefined4 *in_stack_000000b0;
  int in_stack_00000134;
  
  uVar9 = *in_stack_00000050;
  in_stack_00000048 = in_stack_00000048 + -1;
  *(undefined4 *)unaff_r4 = *in_stack_000000b0;
  *(undefined4 *)(unaff_r4 + 4) = *in_stack_000000a8;
  *(undefined4 *)(unaff_r4 + 8) = *in_stack_000000ac;
  *(undefined4 *)(unaff_r4 + 0xc) = *in_stack_000000a4;
  if (in_stack_000000a0 << 0x1a < 0) {
    FUN_0000a3f0(unaff_r4,unaff_r4 + *(ushort *)(unaff_r4 + 0x58) + 2,0,0x5b);
  }
  iVar4 = iptc_replace_entry();
  FUN_0000bc28();
  do {
    pcVar5 = (char *)(DAT_0000c75c + 0xc478);
    while( true ) {
      printf(pcVar5,DAT_0000c368 + 0xc174);
      do {
        pFVar8 = (FILE *)(*(int *)(unaff_r9 + in_stack_00000030) + 0x54);
        fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar8);
        if ((int)(uVar9 << 0x1c) < 0) {
          fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar8);
        }
        if ((int)(uVar9 << 0x19) < 0) {
          if ((int)(uVar9 << 0x1b) < 0) {
            pcVar5 = (char *)(DAT_0000c760 + 0xc480);
            printf(pcVar5,DAT_0000c764 + 0xc482);
          }
          else {
            printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
            pcVar5 = (char *)(DAT_0000c37c + 0xc1ba);
          }
          printf(pcVar5,DAT_0000c380 + 0xc1be);
        }
        if ((int)(uVar9 << 0x1b) < 0) {
          printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
          pcVar5 = (char *)(DAT_0000c38c + 0xc1d8);
        }
        else {
          pcVar5 = (char *)(iRam0000c754 + 0xc418);
          printf(pcVar5,DAT_0000c758 + 0xc41a);
        }
        printf(pcVar5,DAT_0000c390 + 0xc1dc);
        putchar(10);
        do {
          iVar1 = iptc_first_rule(unaff_r4,in_stack_00000048);
          if (iVar1 != 0) {
            iVar7 = 0;
            do {
              iVar7 = iVar7 + 1;
              if ((iVar4 == iVar7) || (in_stack_0000002c != 0)) {
                uVar2 = iptc_get_target(iVar1,in_stack_00000048);
                FUN_0000a3f0(iVar1,uVar2,iVar7,uVar9);
              }
              iVar1 = iptc_next_rule(iVar1,in_stack_00000048);
            } while (iVar1 != 0);
          }
          iVar1 = 1;
          do {
            unaff_r4 = (char *)iptc_next_chain(in_stack_00000048);
            if (unaff_r4 == (char *)0x0) {
              puVar3 = (undefined4 *)__errno();
              *puVar3 = 2;
              if ((in_stack_0000009c << 0x18 < 0) && (iVar1 = FUN_0000acf0(), iVar1 == 0)) {
                FUN_0000bc28();
                return;
              }
              if (in_stack_0000009c << 0x12 < 0) {
                iVar1 = iptc_zero_counter();
              }
              puVar3 = in_stack_00000098;
              if (1 < in_stack_00000054) {
                dump_entries(*in_stack_00000050);
                puVar3 = in_stack_00000098;
              }
              while (puVar3 != (void *)0x0) {
                __ptr = (void *)puVar3[1];
                pvVar6 = (void *)*puVar3;
                if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
                  free(*(void **)((int)__ptr + 0x38));
                  *(undefined4 *)(puVar3[1] + 0x38) = 0;
                  __ptr = (void *)puVar3[1];
                }
                if (__ptr == *(void **)((int)__ptr + 4)) {
                  free(__ptr);
                  puVar3[1] = 0;
                }
                free(puVar3);
                puVar3 = pvVar6;
              }
              in_stack_00000098 = (undefined4 *)0x0;
              if (unaff_r10 != (void *)0x0) {
                free(unaff_r10);
              }
              free(in_stack_000000b0);
              free(in_stack_000000ac);
              free(in_stack_000000a8);
              free(in_stack_000000a4);
              FUN_00021f14(1);
              if (in_stack_00000134 == **(int **)(unaff_r9 + in_stack_00000058)) {
                return;
              }
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail(iVar1);
            }
          } while ((unaff_r11 != (char *)0x0) && (iVar7 = strcmp(unaff_r11,unaff_r4), iVar7 != 0));
          putchar(10);
        } while (iVar4 != 0);
        iVar1 = iptc_get_policy(unaff_r4,&stack0x00000078,in_stack_00000048);
        printf(in_stack_00000038,unaff_r4);
        if (iVar1 == 0) {
          iVar1 = iptc_get_references(&stack0x00000094,unaff_r4,in_stack_00000048);
          if (iVar1 == 0) {
            puts((char *)(DAT_0000c76c + 0xc4d4));
            in_stack_00000030 = DAT_0000c770;
          }
          else {
            printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
            in_stack_00000030 = iRam0000c8f4;
          }
        }
        else {
          printf((char *)(DAT_0000c344 + 0xc10c));
          if ((int)(uVar9 << 0x1e) < 0) {
            in_stack_00000030 = DAT_0000c348;
          }
          else {
            in_stack_00000030 = DAT_0000c770;
            pFVar8 = (FILE *)(*(int *)(unaff_r9 + DAT_0000c770) + 0x54);
            fputc(0x20,pFVar8);
            FUN_0000a018(in_stack_00000078,in_stack_0000007c,uVar9 | 0x10);
            fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar8);
            FUN_0000a018(in_stack_00000080,in_stack_00000084,uVar9 | 0x10);
            fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar8);
          }
          puts((char *)(DAT_0000c34c + 0xc11e));
        }
        if (in_stack_00000040 != 0) {
          if ((int)(uVar9 << 0x1b) < 0) {
            pcVar5 = (char *)(DAT_0000c768 + 0xc4be);
          }
          else {
            pcVar5 = (char *)(DAT_0000c350 + 0xc132);
          }
          printf(pcVar5,DAT_0000c354 + 0xc136);
        }
        if (-1 < (int)(uVar9 << 0x1e)) {
          if ((int)(uVar9 << 0x1d) < 0) {
            if ((int)(uVar9 << 0x1b) < 0) {
              pcVar5 = (char *)(DAT_0000c358 + 0xc150);
              printf(pcVar5,DAT_0000c35c + 0xc152);
            }
            else {
              pcVar5 = (char *)(DAT_0000c77c + 0xc530);
              printf(pcVar5,DAT_0000c780 + 0xc532);
            }
            printf(pcVar5,DAT_0000c360 + 0xc15e);
          }
          else {
            if ((int)(uVar9 << 0x1b) < 0) {
              __format = (code *)(DAT_0000c784 + 0xc546);
              printf((char *)__format,DAT_0000c788 + 0xc548);
            }
            else {
              printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
              __format = FUN_0000c61e + DAT_0000c7b0;
            }
            printf((char *)__format,DAT_0000c78c + 0xc554);
          }
        }
      } while ((int)(uVar9 << 0x1a) < 0);
      if ((int)(uVar9 << 0x1b) < 0) break;
      pcVar5 = (char *)(DAT_0000c364 + 0xc170);
    }
  } while( true );
}



/* Function: FUN_0000c48a @ 0000c48a */

/* WARNING: Removing unreachable block (ram,0x0000bea0) */

void FUN_0000c48a(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char *__dest;
  char *pcVar5;
  void *__ptr;
  ushort *in_r3;
  void *pvVar6;
  char *pcVar7;
  FILE *pFVar8;
  code *__format;
  short *unaff_r9;
  void *unaff_r10;
  char *unaff_r11;
  int in_stack_0000002c;
  int in_stack_00000030;
  void *in_stack_00000034;
  char *in_stack_00000038;
  int in_stack_00000040;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  int in_stack_0000009c;
  undefined4 in_stack_000000a0;
  void *in_stack_000000a4;
  void *in_stack_000000a8;
  void *in_stack_000000ac;
  void *in_stack_000000b0;
  int in_stack_00000134;
  
  __dest = (char *)FUN_00022ddc(*in_r3 + 0x70);
  memcpy(__dest,in_stack_00000034,0x70);
  __dest[0x58] = 'p';
  __dest[0x59] = '\0';
  *(short *)(__dest + 0x5a) = *unaff_r9 + 0x70;
  FUN_0000bada();
  pcVar7 = __dest;
  do {
    pcVar5 = (char *)(DAT_0000c768 + 0xc4be);
    while( true ) {
      printf(pcVar5,DAT_0000c354 + 0xc136);
      do {
        if (-1 < (int)unaff_r9 << 0x1e) {
          if ((int)unaff_r9 << 0x1d < 0) {
            if ((int)unaff_r9 << 0x1b < 0) {
              pcVar5 = (char *)(DAT_0000c358 + 0xc150);
              printf(pcVar5,DAT_0000c35c + 0xc152);
            }
            else {
              pcVar5 = (char *)(DAT_0000c77c + 0xc530);
              printf(pcVar5,DAT_0000c780 + 0xc532);
            }
            printf(pcVar5,DAT_0000c360 + 0xc15e);
          }
          else {
            if ((int)unaff_r9 << 0x1b < 0) {
              __format = (code *)(DAT_0000c784 + 0xc546);
              printf((char *)__format,DAT_0000c788 + 0xc548);
            }
            else {
              printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
              __format = FUN_0000c61e + DAT_0000c7b0;
            }
            printf((char *)__format,DAT_0000c78c + 0xc554);
          }
        }
        if (-1 < (int)unaff_r9 << 0x1a) {
          if ((int)unaff_r9 << 0x1b < 0) {
            pcVar5 = (char *)(DAT_0000c75c + 0xc478);
          }
          else {
            pcVar5 = (char *)(DAT_0000c364 + 0xc170);
          }
          printf(pcVar5,DAT_0000c368 + 0xc174);
        }
        pFVar8 = (FILE *)(*(int *)((int)unaff_r9 + in_stack_00000030) + 0x54);
        fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar8);
        if ((int)unaff_r9 << 0x1c < 0) {
          fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar8);
        }
        if ((int)unaff_r9 << 0x19 < 0) {
          if ((int)unaff_r9 << 0x1b < 0) {
            pcVar5 = (char *)(DAT_0000c760 + 0xc480);
            printf(pcVar5,DAT_0000c764 + 0xc482);
          }
          else {
            printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
            pcVar5 = (char *)(DAT_0000c37c + 0xc1ba);
          }
          printf(pcVar5,DAT_0000c380 + 0xc1be);
        }
        if ((int)unaff_r9 << 0x1b < 0) {
          printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
          pcVar5 = (char *)(DAT_0000c38c + 0xc1d8);
        }
        else {
          pcVar5 = (char *)(iRam0000c754 + 0xc418);
          printf(pcVar5,DAT_0000c758 + 0xc41a);
        }
        printf(pcVar5,DAT_0000c390 + 0xc1dc);
        putchar(10);
        do {
          iVar2 = iptc_first_rule(pcVar7,0);
          if (iVar2 != 0) {
            pcVar7 = (char *)0x0;
            do {
              pcVar7 = pcVar7 + 1;
              if ((__dest + 0x70 == pcVar7) || (in_stack_0000002c != 0)) {
                uVar3 = iptc_get_target(iVar2,0);
                FUN_0000a3f0(iVar2,uVar3,pcVar7,unaff_r9);
              }
              iVar2 = iptc_next_rule(iVar2,0);
            } while (iVar2 != 0);
          }
          iVar2 = 1;
          do {
            pcVar7 = (char *)iptc_next_chain(0);
            if (pcVar7 == (char *)0x0) {
              puVar4 = (undefined4 *)__errno();
              *puVar4 = 2;
              if ((in_stack_0000009c << 0x18 < 0) && (iVar2 = FUN_0000acf0(), iVar2 == 0)) {
                FUN_0000bc28();
                return;
              }
              if (in_stack_0000009c << 0x12 < 0) {
                iVar2 = iptc_zero_counter();
              }
              puVar4 = in_stack_00000098;
              if (1 < in_stack_00000054) {
                dump_entries(*in_stack_00000050);
                puVar4 = in_stack_00000098;
              }
              while (puVar4 != (void *)0x0) {
                __ptr = (void *)puVar4[1];
                pvVar6 = (void *)*puVar4;
                if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
                  free(*(void **)((int)__ptr + 0x38));
                  *(undefined4 *)(puVar4[1] + 0x38) = 0;
                  __ptr = (void *)puVar4[1];
                }
                if (__ptr == *(void **)((int)__ptr + 4)) {
                  free(__ptr);
                  puVar4[1] = 0;
                }
                free(puVar4);
                puVar4 = pvVar6;
              }
              in_stack_00000098 = (undefined4 *)0x0;
              if (unaff_r10 != (void *)0x0) {
                free(unaff_r10);
              }
              free(in_stack_000000b0);
              free(in_stack_000000ac);
              free(in_stack_000000a8);
              free(in_stack_000000a4);
              FUN_00021f14(1);
              if (in_stack_00000134 == **(int **)((int)unaff_r9 + in_stack_00000058)) {
                return;
              }
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail(iVar2);
            }
          } while ((unaff_r11 != (char *)0x0) && (iVar1 = strcmp(unaff_r11,pcVar7), iVar1 != 0));
          putchar(10);
        } while (__dest != (char *)0xffffff90);
        iVar2 = iptc_get_policy(pcVar7,&stack0x00000078,0);
        printf(in_stack_00000038,pcVar7);
        if (iVar2 == 0) {
          iVar2 = iptc_get_references(&stack0x00000094,pcVar7,0);
          if (iVar2 == 0) {
            puts((char *)(DAT_0000c76c + 0xc4d4));
            in_stack_00000030 = DAT_0000c770;
          }
          else {
            printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
            in_stack_00000030 = iRam0000c8f4;
          }
        }
        else {
          printf((char *)(DAT_0000c344 + 0xc10c));
          if ((int)unaff_r9 << 0x1e < 0) {
            in_stack_00000030 = DAT_0000c348;
          }
          else {
            in_stack_00000030 = DAT_0000c770;
            pFVar8 = (FILE *)(*(int *)((int)unaff_r9 + DAT_0000c770) + 0x54);
            fputc(0x20,pFVar8);
            FUN_0000a018(in_stack_00000078,in_stack_0000007c,(uint)unaff_r9 | 0x10);
            fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar8);
            FUN_0000a018(in_stack_00000080,in_stack_00000084,(uint)unaff_r9 | 0x10);
            fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar8);
          }
          puts((char *)(DAT_0000c34c + 0xc11e));
        }
      } while (in_stack_00000040 == 0);
      if ((int)unaff_r9 << 0x1b < 0) break;
      pcVar5 = (char *)(DAT_0000c350 + 0xc132);
    }
  } while( true );
}



/* Function: FUN_0000c558 @ 0000c558 */

/* WARNING: Removing unreachable block (ram,0x0000c12a) */
/* WARNING: Removing unreachable block (ram,0x0000c1c6) */
/* WARNING: Removing unreachable block (ram,0x0000c168) */
/* WARNING: Removing unreachable block (ram,0x0000c1a2) */
/* WARNING: Removing unreachable block (ram,0x0000c1a8) */
/* WARNING: Removing unreachable block (ram,0x0000c1a6) */
/* WARNING: Removing unreachable block (ram,0x0000c1b8) */
/* WARNING: Removing unreachable block (ram,0x0000c114) */
/* WARNING: Removing unreachable block (ram,0x0000bea0) */
/* WARNING: Removing unreachable block (ram,0x0000c142) */
/* WARNING: Removing unreachable block (ram,0x0000c148) */
/* WARNING: Removing unreachable block (ram,0x0000c146) */
/* WARNING: Removing unreachable block (ram,0x0000c158) */
/* WARNING: Removing unreachable block (ram,0x0000c190) */
/* WARNING: Removing unreachable block (ram,0x0000c53e) */

void FUN_0000c558(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  void *__ptr;
  FILE *__stream;
  char *__format;
  void *pvVar5;
  char *unaff_r4;
  int iVar6;
  char *__format_00;
  int unaff_r5;
  char *__format_01;
  int unaff_r8;
  void *unaff_r10;
  char *unaff_r11;
  int extraout_r12;
  char *pcStack00000030;
  char *in_stack_00000038;
  int in_stack_00000040;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  int in_stack_0000009c;
  undefined4 in_stack_000000a0;
  void *in_stack_000000a4;
  void *in_stack_000000a8;
  void *in_stack_000000ac;
  void *in_stack_000000b0;
  int in_stack_00000134;
  
  pcVar3 = (char *)iptc_first_chain();
  if (pcVar3 == (char *)0x0) {
    FUN_0000bb8c();
  }
  __format = (char *)(DAT_0000c790 + 0xc572);
  pcStack00000030 = (char *)(DAT_0000c794 + 0xc574);
  __format_01 = (char *)(DAT_0000c798 + 0xc578);
  do {
    if ((unaff_r11 == (char *)0x0) || (iVar4 = strcmp(pcVar3,unaff_r11), iVar4 == 0)) {
      iVar4 = iptc_builtin(pcVar3,unaff_r8);
      if (iVar4 == 0) {
        printf(__format_01,pcVar3);
      }
      else {
        uVar1 = iptc_get_policy(pcVar3,&stack0x00000078,unaff_r8);
        printf(__format,pcVar3,uVar1);
        if (unaff_r10 != (void *)0x0) {
          printf(pcStack00000030,in_stack_00000084,in_stack_00000078,in_stack_0000007c);
        }
        putchar(10);
      }
    }
    pcVar3 = (char *)iptc_next_chain(unaff_r8);
  } while (pcVar3 != (char *)0x0);
  FUN_0000bb8c();
  (**(code **)(**(int **)(extraout_r12 + DAT_0000c79c) + 0x14))
            (2,DAT_0000c7a0 + 0xc5fe,*(undefined1 *)(DAT_0000c7a4 + unaff_r5 + 0xc614));
  pcVar3 = unaff_r4;
  do {
    printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
    printf((char *)(FUN_0000c61e + DAT_0000c7b0),DAT_0000c78c + 0xc554);
    printf((char *)(DAT_0000c364 + 0xc170),DAT_0000c368 + 0xc174);
    fwrite((void *)(DAT_0000c36c + 0xc184),1,6,
           (FILE *)(*(int *)(unaff_r4 + (int)pcStack00000030) + 0x54));
    __format_00 = (char *)(iRam0000c754 + 0xc418);
    printf(__format_00,DAT_0000c758 + 0xc41a);
    printf(__format_00,DAT_0000c390 + 0xc1dc);
    putchar(10);
    do {
      iVar4 = iptc_first_rule(pcVar3,__format_01);
      if (iVar4 != 0) {
        iVar6 = 0;
        do {
          iVar6 = iVar6 + 1;
          if ((unaff_r8 == iVar6) || (__format != (char *)0x0)) {
            uVar1 = iptc_get_target(iVar4,__format_01);
            FUN_0000a3f0(iVar4,uVar1,iVar6,0);
          }
          iVar4 = iptc_next_rule(iVar4,__format_01);
        } while (iVar4 != 0);
      }
      iVar4 = 1;
      do {
        pcVar3 = (char *)iptc_next_chain(__format_01);
        if (pcVar3 == (char *)0x0) {
          puVar2 = (undefined4 *)__errno();
          *puVar2 = 2;
          if ((in_stack_0000009c << 0x18 < 0) && (iVar4 = FUN_0000acf0(), iVar4 == 0)) {
            FUN_0000bc28();
            return;
          }
          if (in_stack_0000009c << 0x12 < 0) {
            iVar4 = iptc_zero_counter();
          }
          puVar2 = in_stack_00000098;
          if (1 < in_stack_00000054) {
            dump_entries(*in_stack_00000050);
            puVar2 = in_stack_00000098;
          }
          while (puVar2 != (void *)0x0) {
            __ptr = (void *)puVar2[1];
            pvVar5 = (void *)*puVar2;
            if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
              free(*(void **)((int)__ptr + 0x38));
              *(undefined4 *)(puVar2[1] + 0x38) = 0;
              __ptr = (void *)puVar2[1];
            }
            if (__ptr == *(void **)((int)__ptr + 4)) {
              free(__ptr);
              puVar2[1] = 0;
            }
            free(puVar2);
            puVar2 = pvVar5;
          }
          in_stack_00000098 = (undefined4 *)0x0;
          if (unaff_r10 != (void *)0x0) {
            free(unaff_r10);
          }
          free(in_stack_000000b0);
          free(in_stack_000000ac);
          free(in_stack_000000a8);
          free(in_stack_000000a4);
          FUN_00021f14(1);
          if (in_stack_00000134 != **(int **)(unaff_r4 + in_stack_00000058)) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail(iVar4);
          }
          return;
        }
      } while ((unaff_r11 != (char *)0x0) && (iVar6 = strcmp(unaff_r11,pcVar3), iVar6 != 0));
      putchar(10);
    } while (unaff_r8 != 0);
    iVar4 = iptc_get_policy(pcVar3,&stack0x00000078,__format_01);
    printf(in_stack_00000038,pcVar3);
    if (iVar4 == 0) {
      iVar4 = iptc_get_references(&stack0x00000094,pcVar3,__format_01);
      if (iVar4 == 0) {
        puts((char *)(DAT_0000c76c + 0xc4d4));
        pcStack00000030 = DAT_0000c770;
      }
      else {
        printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
        pcStack00000030 = pcRam0000c8f4;
      }
    }
    else {
      printf((char *)(DAT_0000c344 + 0xc10c));
      pcStack00000030 = DAT_0000c770;
      __stream = (FILE *)(*(int *)(unaff_r4 + (int)DAT_0000c770) + 0x54);
      fputc(0x20,__stream);
      FUN_0000a018(in_stack_00000078,in_stack_0000007c,0x10);
      fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,__stream);
      FUN_0000a018(in_stack_00000080,in_stack_00000084,0x10);
      fwrite((void *)(DAT_0000c778 + 0xc524),1,5,__stream);
      puts((char *)(DAT_0000c34c + 0xc11e));
    }
    if (in_stack_00000040 != 0) {
      printf((char *)(DAT_0000c350 + 0xc132),DAT_0000c354 + 0xc136);
    }
  } while( true );
}



/* Function: FUN_0000c5ee @ 0000c5ee */

/* WARNING: Removing unreachable block (ram,0x0000bea0) */

void FUN_0000c5ee(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  code *__format;
  void *__ptr;
  void *pvVar5;
  char *unaff_r4;
  int iVar6;
  FILE *pFVar7;
  int unaff_r5;
  uint unaff_r6;
  undefined4 unaff_r7;
  int unaff_r8;
  int unaff_r9;
  void *unaff_r10;
  char *unaff_r11;
  int in_r12;
  int in_stack_0000002c;
  int in_stack_00000030;
  char *in_stack_00000038;
  int in_stack_00000040;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  int in_stack_0000009c;
  undefined4 in_stack_000000a0;
  void *in_stack_000000a4;
  void *in_stack_000000a8;
  void *in_stack_000000ac;
  void *in_stack_000000b0;
  int in_stack_00000134;
  
  (**(code **)(**(int **)(in_r12 + DAT_0000c79c) + 0x14))
            (2,DAT_0000c7a0 + 0xc5fe,*(undefined1 *)(DAT_0000c7a4 + unaff_r5 + 0xc614));
  do {
    printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
    __format = FUN_0000c61e + DAT_0000c7b0;
    while( true ) {
      printf((char *)__format,DAT_0000c78c + 0xc554);
      while( true ) {
        do {
          if (-1 < (int)(unaff_r6 << 0x1a)) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c75c + 0xc478);
            }
            else {
              pcVar4 = (char *)(DAT_0000c364 + 0xc170);
            }
            printf(pcVar4,DAT_0000c368 + 0xc174);
          }
          pFVar7 = (FILE *)(*(int *)(unaff_r9 + in_stack_00000030) + 0x54);
          fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar7);
          if ((int)(unaff_r6 << 0x1c) < 0) {
            fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar7);
          }
          if ((int)(unaff_r6 << 0x19) < 0) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c760 + 0xc480);
              printf(pcVar4,DAT_0000c764 + 0xc482);
            }
            else {
              printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
              pcVar4 = (char *)(DAT_0000c37c + 0xc1ba);
            }
            printf(pcVar4,DAT_0000c380 + 0xc1be);
          }
          if ((int)(unaff_r6 << 0x1b) < 0) {
            printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
            pcVar4 = (char *)(DAT_0000c38c + 0xc1d8);
          }
          else {
            pcVar4 = (char *)(iRam0000c754 + 0xc418);
            printf(pcVar4,DAT_0000c758 + 0xc41a);
          }
          printf(pcVar4,DAT_0000c390 + 0xc1dc);
          putchar(10);
          do {
            iVar1 = iptc_first_rule(unaff_r4,unaff_r7);
            if (iVar1 != 0) {
              iVar6 = 0;
              do {
                iVar6 = iVar6 + 1;
                if ((unaff_r8 == iVar6) || (in_stack_0000002c != 0)) {
                  uVar2 = iptc_get_target(iVar1,unaff_r7);
                  FUN_0000a3f0(iVar1,uVar2,iVar6,unaff_r6);
                }
                iVar1 = iptc_next_rule(iVar1,unaff_r7);
              } while (iVar1 != 0);
            }
            iVar1 = 1;
            do {
              unaff_r4 = (char *)iptc_next_chain(unaff_r7);
              if (unaff_r4 == (char *)0x0) {
                puVar3 = (undefined4 *)__errno();
                *puVar3 = 2;
                if ((in_stack_0000009c << 0x18 < 0) && (iVar1 = FUN_0000acf0(), iVar1 == 0)) {
                  FUN_0000bc28();
                  return;
                }
                if (in_stack_0000009c << 0x12 < 0) {
                  iVar1 = iptc_zero_counter();
                }
                puVar3 = in_stack_00000098;
                if (1 < in_stack_00000054) {
                  dump_entries(*in_stack_00000050);
                  puVar3 = in_stack_00000098;
                }
                while (puVar3 != (void *)0x0) {
                  __ptr = (void *)puVar3[1];
                  pvVar5 = (void *)*puVar3;
                  if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
                    free(*(void **)((int)__ptr + 0x38));
                    *(undefined4 *)(puVar3[1] + 0x38) = 0;
                    __ptr = (void *)puVar3[1];
                  }
                  if (__ptr == *(void **)((int)__ptr + 4)) {
                    free(__ptr);
                    puVar3[1] = 0;
                  }
                  free(puVar3);
                  puVar3 = pvVar5;
                }
                in_stack_00000098 = (undefined4 *)0x0;
                if (unaff_r10 != (void *)0x0) {
                  free(unaff_r10);
                }
                free(in_stack_000000b0);
                free(in_stack_000000ac);
                free(in_stack_000000a8);
                free(in_stack_000000a4);
                FUN_00021f14(1);
                if (in_stack_00000134 == **(int **)(unaff_r9 + in_stack_00000058)) {
                  return;
                }
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail(iVar1);
              }
            } while ((unaff_r11 != (char *)0x0) && (iVar6 = strcmp(unaff_r11,unaff_r4), iVar6 != 0))
            ;
            putchar(10);
          } while (unaff_r8 != 0);
          iVar1 = iptc_get_policy(unaff_r4,&stack0x00000078,unaff_r7);
          printf(in_stack_00000038,unaff_r4);
          if (iVar1 == 0) {
            iVar1 = iptc_get_references(&stack0x00000094,unaff_r4,unaff_r7);
            if (iVar1 == 0) {
              puts((char *)(DAT_0000c76c + 0xc4d4));
              in_stack_00000030 = DAT_0000c770;
            }
            else {
              printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
              in_stack_00000030 = iRam0000c8f4;
            }
          }
          else {
            printf((char *)(DAT_0000c344 + 0xc10c));
            if ((int)(unaff_r6 << 0x1e) < 0) {
              in_stack_00000030 = DAT_0000c348;
            }
            else {
              in_stack_00000030 = DAT_0000c770;
              pFVar7 = (FILE *)(*(int *)(unaff_r9 + DAT_0000c770) + 0x54);
              fputc(0x20,pFVar7);
              FUN_0000a018(in_stack_00000078,in_stack_0000007c,unaff_r6 | 0x10);
              fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar7);
              FUN_0000a018(in_stack_00000080,in_stack_00000084,unaff_r6 | 0x10);
              fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar7);
            }
            puts((char *)(DAT_0000c34c + 0xc11e));
          }
          if (in_stack_00000040 != 0) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c768 + 0xc4be);
            }
            else {
              pcVar4 = (char *)(DAT_0000c350 + 0xc132);
            }
            printf(pcVar4,DAT_0000c354 + 0xc136);
          }
        } while ((int)(unaff_r6 << 0x1e) < 0);
        if (-1 < (int)(unaff_r6 << 0x1d)) break;
        if ((int)(unaff_r6 << 0x1b) < 0) {
          pcVar4 = (char *)(DAT_0000c358 + 0xc150);
          printf(pcVar4,DAT_0000c35c + 0xc152);
        }
        else {
          pcVar4 = (char *)(DAT_0000c77c + 0xc530);
          printf(pcVar4,DAT_0000c780 + 0xc532);
        }
        printf(pcVar4,DAT_0000c360 + 0xc15e);
      }
      if (-1 < (int)(unaff_r6 << 0x1b)) break;
      __format = (code *)(DAT_0000c784 + 0xc546);
      printf((char *)__format,DAT_0000c788 + 0xc548);
    }
  } while( true );
}



/* Function: FUN_0000c61e @ 0000c61e */

void FUN_0000c61e(void)

{
  undefined1 *puVar1;
  int unaff_r5;
  int unaff_r8;
  int in_stack_00000030;
  
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))
            (2,DAT_0000c7b4 + 0xc632,
             *(undefined4 *)((**(int **)(unaff_r5 + in_stack_00000030) + -1) * 4 + unaff_r8));
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))
            (2,DAT_0000c7bc + 0xc64a,**(undefined4 **)(unaff_r5 + DAT_0000c7b8));
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7c0 + 0xc65e);
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7c4 + 0xc66e);
  puVar1 = (undefined1 *)(DAT_0000c7c8 + 0xc67c);
  do {
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined1 *)(DAT_0000c7c8 + 0xc686));
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7cc + 0xc692,*puVar1);
  fprintf((FILE *)(*(int *)(unaff_r5 + DAT_0000c770) + 0xa8),(char *)(DAT_0000c7d0 + 0xc69c));
                    /* WARNING: Subroutine does not return */
  FUN_0000a2c4(2);
}



/* Function: FUN_0000c63c @ 0000c63c */

void FUN_0000c63c(void)

{
  undefined1 *puVar1;
  int unaff_r5;
  
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))
            (2,DAT_0000c7bc + 0xc64a,**(undefined4 **)(unaff_r5 + DAT_0000c7b8));
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7c0 + 0xc65e);
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7c4 + 0xc66e);
  puVar1 = (undefined1 *)(DAT_0000c7c8 + 0xc67c);
  do {
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined1 *)(DAT_0000c7c8 + 0xc686));
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7cc + 0xc692,*puVar1);
  fprintf((FILE *)(*(int *)(unaff_r5 + DAT_0000c770) + 0xa8),(char *)(DAT_0000c7d0 + 0xc69c));
                    /* WARNING: Subroutine does not return */
  FUN_0000a2c4(2);
}



/* Function: FUN_0000c652 @ 0000c652 */

void FUN_0000c652(void)

{
  undefined1 *puVar1;
  int unaff_r5;
  
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7c0 + 0xc65e);
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7c4 + 0xc66e);
  puVar1 = (undefined1 *)(DAT_0000c7c8 + 0xc67c);
  do {
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined1 *)(DAT_0000c7c8 + 0xc686));
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7cc + 0xc692,*puVar1);
  fprintf((FILE *)(*(int *)(unaff_r5 + DAT_0000c770) + 0xa8),(char *)(DAT_0000c7d0 + 0xc69c));
                    /* WARNING: Subroutine does not return */
  FUN_0000a2c4(2);
}



/* Function: FUN_0000c6a6 @ 0000c6a6 */

void FUN_0000c6a6(void)

{
  void *__s;
  undefined4 uVar1;
  code *pcVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int unaff_r5;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *unaff_r9;
  int in_stack_00000030;
  int iStack00000034;
  undefined4 *in_stack_00000038;
  undefined4 *in_stack_0000003c;
  int in_stack_00000040;
  undefined4 *in_stack_00000044;
  undefined4 *in_stack_00000048;
  int in_stack_0000004c;
  
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7d4 + 0xc6b2);
  pcVar2 = (code *)(DAT_0000c7d8 + 0xc6d4);
  do {
    pcVar2 = pcVar2 + 1;
  } while (pcVar2 != FUN_0000c6da + DAT_0000c7d8 + 1);
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7dc + 0xc6d8,*pcVar2);
  pcVar2 = *(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14);
  puVar3 = (undefined1 *)(DAT_0000c7e0 + 0xc6f8);
  do {
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined1 *)(DAT_0000c7e0 + 0xc700));
  (*pcVar2)(2,DAT_0000c7e4 + 0xc6fc,*puVar3);
  __s = (void *)FUN_00023304(1,*(int *)((int)in_stack_00000038 + 0x10) + 0x90);
  memset(__s,0xff,0x70);
  memset((void *)((int)__s + 0x70),0xff,*(int *)((int)in_stack_00000038 + 0x14) + 0x20);
  if (in_stack_00000040 != 0) {
    iStack00000034 = 0;
    in_stack_00000038 = unaff_r9;
    do {
      uVar1 = *in_stack_00000038;
      in_stack_00000038 = in_stack_00000038 + 1;
      *(undefined4 *)pcVar2 = uVar1;
      uVar1 = *in_stack_0000003c;
      in_stack_0000003c = in_stack_0000003c + 1;
      *(undefined4 *)(pcVar2 + 8) = uVar1;
      if (in_stack_0000004c != 0) {
        iVar6 = 0;
        puVar4 = in_stack_00000044;
        puVar5 = in_stack_00000048;
        do {
          uVar1 = *puVar5;
          puVar5 = puVar5 + 1;
          *(undefined4 *)(pcVar2 + 4) = uVar1;
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
          *(undefined4 *)(pcVar2 + 0xc) = uVar1;
          if (in_stack_00000030 != 0) {
            FUN_0000a3f0(pcVar2,pcVar2 + *(ushort *)(pcVar2 + 0x58) + 2,0,0x5b);
          }
          iptc_delete_entry();
          iVar6 = iVar6 + 1;
        } while (iVar6 != in_stack_0000004c);
      }
      iStack00000034 = iStack00000034 + 1;
    } while (iStack00000034 != in_stack_00000040);
  }
  free(__s);
  FUN_0000bc28();
  return;
}



/* Function: FUN_0000c6b6 @ 0000c6b6 */

void FUN_0000c6b6(void)

{
  void *__s;
  undefined4 uVar1;
  code *pcVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int unaff_r5;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *unaff_r9;
  int in_stack_00000030;
  int iStack00000034;
  undefined4 *in_stack_00000038;
  undefined4 *in_stack_0000003c;
  int in_stack_00000040;
  undefined4 *in_stack_00000044;
  undefined4 *in_stack_00000048;
  int in_stack_0000004c;
  
  pcVar2 = (code *)(DAT_0000c7d8 + 0xc6d4);
  do {
    pcVar2 = pcVar2 + 1;
  } while (pcVar2 != FUN_0000c6da + DAT_0000c7d8 + 1);
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))(2,DAT_0000c7dc + 0xc6d8,*pcVar2);
  pcVar2 = *(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14);
  puVar3 = (undefined1 *)(DAT_0000c7e0 + 0xc6f8);
  do {
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined1 *)(DAT_0000c7e0 + 0xc700));
  (*pcVar2)(2,DAT_0000c7e4 + 0xc6fc,*puVar3);
  __s = (void *)FUN_00023304(1,*(int *)((int)in_stack_00000038 + 0x10) + 0x90);
  memset(__s,0xff,0x70);
  memset((void *)((int)__s + 0x70),0xff,*(int *)((int)in_stack_00000038 + 0x14) + 0x20);
  if (in_stack_00000040 != 0) {
    iStack00000034 = 0;
    in_stack_00000038 = unaff_r9;
    do {
      uVar1 = *in_stack_00000038;
      in_stack_00000038 = in_stack_00000038 + 1;
      *(undefined4 *)pcVar2 = uVar1;
      uVar1 = *in_stack_0000003c;
      in_stack_0000003c = in_stack_0000003c + 1;
      *(undefined4 *)(pcVar2 + 8) = uVar1;
      if (in_stack_0000004c != 0) {
        iVar6 = 0;
        puVar4 = in_stack_00000044;
        puVar5 = in_stack_00000048;
        do {
          uVar1 = *puVar5;
          puVar5 = puVar5 + 1;
          *(undefined4 *)(pcVar2 + 4) = uVar1;
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
          *(undefined4 *)(pcVar2 + 0xc) = uVar1;
          if (in_stack_00000030 != 0) {
            FUN_0000a3f0(pcVar2,pcVar2 + *(ushort *)(pcVar2 + 0x58) + 2,0,0x5b);
          }
          iptc_delete_entry();
          iVar6 = iVar6 + 1;
        } while (iVar6 != in_stack_0000004c);
      }
      iStack00000034 = iStack00000034 + 1;
    } while (iStack00000034 != in_stack_00000040);
  }
  free(__s);
  FUN_0000bc28();
  return;
}



/* Function: FUN_0000c6da @ 0000c6da */

void FUN_0000c6da(void)

{
  void *__s;
  undefined4 uVar1;
  undefined1 *puVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int unaff_r5;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *unaff_r9;
  int in_stack_00000030;
  int iStack00000034;
  undefined4 *in_stack_00000038;
  undefined4 *in_stack_0000003c;
  int in_stack_00000040;
  undefined4 *in_stack_00000044;
  undefined4 *in_stack_00000048;
  int in_stack_0000004c;
  
  pcVar3 = *(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14);
  puVar2 = (undefined1 *)(DAT_0000c7e0 + 0xc6f8);
  do {
    puVar2 = puVar2 + 1;
  } while (puVar2 != (undefined1 *)(DAT_0000c7e0 + 0xc700));
  (*pcVar3)(2,DAT_0000c7e4 + 0xc6fc,*puVar2);
  __s = (void *)FUN_00023304(1,*(int *)((int)in_stack_00000038 + 0x10) + 0x90);
  memset(__s,0xff,0x70);
  memset((void *)((int)__s + 0x70),0xff,*(int *)((int)in_stack_00000038 + 0x14) + 0x20);
  if (in_stack_00000040 != 0) {
    iStack00000034 = 0;
    in_stack_00000038 = unaff_r9;
    do {
      uVar1 = *in_stack_00000038;
      in_stack_00000038 = in_stack_00000038 + 1;
      *(undefined4 *)pcVar3 = uVar1;
      uVar1 = *in_stack_0000003c;
      in_stack_0000003c = in_stack_0000003c + 1;
      *(undefined4 *)(pcVar3 + 8) = uVar1;
      if (in_stack_0000004c != 0) {
        iVar6 = 0;
        puVar4 = in_stack_00000044;
        puVar5 = in_stack_00000048;
        do {
          uVar1 = *puVar5;
          puVar5 = puVar5 + 1;
          *(undefined4 *)(pcVar3 + 4) = uVar1;
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
          *(undefined4 *)(pcVar3 + 0xc) = uVar1;
          if (in_stack_00000030 != 0) {
            FUN_0000a3f0(pcVar3,pcVar3 + *(ushort *)(pcVar3 + 0x58) + 2,0,0x5b);
          }
          iptc_delete_entry();
          iVar6 = iVar6 + 1;
        } while (iVar6 != in_stack_0000004c);
      }
      iStack00000034 = iStack00000034 + 1;
    } while (iStack00000034 != in_stack_00000040);
  }
  free(__s);
  FUN_0000bc28();
  return;
}



/* Function: FUN_0000c71a @ 0000c71a */

void FUN_0000c71a(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  int unaff_r5;
  undefined4 uVar4;
  undefined4 *in_stack_0000006c;
  
  uVar4 = *in_stack_0000006c;
  pcVar3 = *(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14);
  puVar1 = (undefined4 *)__errno();
  uVar2 = FUN_0000cc0c(*puVar1);
  (*pcVar3)(3,DAT_0000c7e8 + 0xc73a,uVar4,uVar2);
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: __stack_chk_fail @ 0000c73c */

void __stack_chk_fail(void)

{
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_0000c740 @ 0000c740 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_0000c740(void)

{
  int unaff_r5;
  undefined4 in_stack_0000003c;
  
  (**(code **)(**(int **)(unaff_r5 + DAT_0000c79c) + 0x14))
            (2,DAT_0000c7ec + 0xc74c,in_stack_0000003c);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: FUN_0000c810 @ 0000c810 */

/* WARNING: Removing unreachable block (ram,0x0000bea0) */

void FUN_0000c810(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  code *__format;
  void *__ptr;
  void *pvVar5;
  code *__s2;
  int iVar6;
  FILE *pFVar7;
  int unaff_r5;
  uint unaff_r6;
  undefined4 unaff_r7;
  int unaff_r8;
  int unaff_r9;
  void *unaff_r10;
  char *unaff_r11;
  int extraout_r12;
  int in_stack_0000002c;
  int in_stack_00000030;
  char *in_stack_00000038;
  int in_stack_00000040;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  int in_stack_0000009c;
  undefined4 in_stack_000000a0;
  void *in_stack_000000a4;
  void *in_stack_000000a8;
  void *in_stack_000000ac;
  void *in_stack_000000b0;
  int in_stack_00000134;
  
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(1,iRam0000c900 + 0xc81c);
  __s2 = *(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14);
  (*__s2)(2,iRam0000c904 + 0xc82c);
  (**(code **)(**(int **)(extraout_r12 + iRam0000c8f8) + 0x14))
            (2,iRam0000c908 + 0xc844,FUN_0000c85a[iRam0000c90c + unaff_r5]);
  do {
    printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
    __format = FUN_0000c61e + DAT_0000c7b0;
    while( true ) {
      printf((char *)__format,DAT_0000c78c + 0xc554);
      while( true ) {
        do {
          if (-1 < (int)(unaff_r6 << 0x1a)) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c75c + 0xc478);
            }
            else {
              pcVar4 = (char *)(DAT_0000c364 + 0xc170);
            }
            printf(pcVar4,DAT_0000c368 + 0xc174);
          }
          pFVar7 = (FILE *)(*(int *)(unaff_r9 + in_stack_00000030) + 0x54);
          fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar7);
          if ((int)(unaff_r6 << 0x1c) < 0) {
            fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar7);
          }
          if ((int)(unaff_r6 << 0x19) < 0) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c760 + 0xc480);
              printf(pcVar4,DAT_0000c764 + 0xc482);
            }
            else {
              printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
              pcVar4 = (char *)(DAT_0000c37c + 0xc1ba);
            }
            printf(pcVar4,DAT_0000c380 + 0xc1be);
          }
          if ((int)(unaff_r6 << 0x1b) < 0) {
            printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
            pcVar4 = (char *)(DAT_0000c38c + 0xc1d8);
          }
          else {
            pcVar4 = (char *)(iRam0000c754 + 0xc418);
            printf(pcVar4,DAT_0000c758 + 0xc41a);
          }
          printf(pcVar4,DAT_0000c390 + 0xc1dc);
          putchar(10);
          do {
            iVar1 = iptc_first_rule(__s2,unaff_r7);
            if (iVar1 != 0) {
              iVar6 = 0;
              do {
                iVar6 = iVar6 + 1;
                if ((unaff_r8 == iVar6) || (in_stack_0000002c != 0)) {
                  uVar2 = iptc_get_target(iVar1,unaff_r7);
                  FUN_0000a3f0(iVar1,uVar2,iVar6,unaff_r6);
                }
                iVar1 = iptc_next_rule(iVar1,unaff_r7);
              } while (iVar1 != 0);
            }
            iVar1 = 1;
            do {
              __s2 = (code *)iptc_next_chain(unaff_r7);
              if (__s2 == (code *)0x0) {
                puVar3 = (undefined4 *)__errno();
                *puVar3 = 2;
                if ((in_stack_0000009c << 0x18 < 0) && (iVar1 = FUN_0000acf0(), iVar1 == 0)) {
                  FUN_0000bc28();
                  return;
                }
                if (in_stack_0000009c << 0x12 < 0) {
                  iVar1 = iptc_zero_counter();
                }
                puVar3 = in_stack_00000098;
                if (1 < in_stack_00000054) {
                  dump_entries(*in_stack_00000050);
                  puVar3 = in_stack_00000098;
                }
                while (puVar3 != (void *)0x0) {
                  __ptr = (void *)puVar3[1];
                  pvVar5 = (void *)*puVar3;
                  if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
                    free(*(void **)((int)__ptr + 0x38));
                    *(undefined4 *)(puVar3[1] + 0x38) = 0;
                    __ptr = (void *)puVar3[1];
                  }
                  if (__ptr == *(void **)((int)__ptr + 4)) {
                    free(__ptr);
                    puVar3[1] = 0;
                  }
                  free(puVar3);
                  puVar3 = pvVar5;
                }
                in_stack_00000098 = (undefined4 *)0x0;
                if (unaff_r10 != (void *)0x0) {
                  free(unaff_r10);
                }
                free(in_stack_000000b0);
                free(in_stack_000000ac);
                free(in_stack_000000a8);
                free(in_stack_000000a4);
                FUN_00021f14(1);
                if (in_stack_00000134 == **(int **)(unaff_r9 + in_stack_00000058)) {
                  return;
                }
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail(iVar1);
              }
            } while ((unaff_r11 != (char *)0x0) &&
                    (iVar6 = strcmp(unaff_r11,(char *)__s2), iVar6 != 0));
            putchar(10);
          } while (unaff_r8 != 0);
          iVar1 = iptc_get_policy(__s2,&stack0x00000078,unaff_r7);
          printf(in_stack_00000038,__s2);
          if (iVar1 == 0) {
            iVar1 = iptc_get_references(&stack0x00000094,__s2,unaff_r7);
            if (iVar1 == 0) {
              puts((char *)(DAT_0000c76c + 0xc4d4));
              in_stack_00000030 = DAT_0000c770;
            }
            else {
              printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
              in_stack_00000030 = iRam0000c8f4;
            }
          }
          else {
            printf((char *)(DAT_0000c344 + 0xc10c));
            if ((int)(unaff_r6 << 0x1e) < 0) {
              in_stack_00000030 = DAT_0000c348;
            }
            else {
              in_stack_00000030 = DAT_0000c770;
              pFVar7 = (FILE *)(*(int *)(unaff_r9 + DAT_0000c770) + 0x54);
              fputc(0x20,pFVar7);
              FUN_0000a018(in_stack_00000078,in_stack_0000007c,unaff_r6 | 0x10);
              fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar7);
              FUN_0000a018(in_stack_00000080,in_stack_00000084,unaff_r6 | 0x10);
              fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar7);
            }
            puts((char *)(DAT_0000c34c + 0xc11e));
          }
          if (in_stack_00000040 != 0) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c768 + 0xc4be);
            }
            else {
              pcVar4 = (char *)(DAT_0000c350 + 0xc132);
            }
            printf(pcVar4,DAT_0000c354 + 0xc136);
          }
        } while ((int)(unaff_r6 << 0x1e) < 0);
        if (-1 < (int)(unaff_r6 << 0x1d)) break;
        if ((int)(unaff_r6 << 0x1b) < 0) {
          pcVar4 = (char *)(DAT_0000c358 + 0xc150);
          printf(pcVar4,DAT_0000c35c + 0xc152);
        }
        else {
          pcVar4 = (char *)(DAT_0000c77c + 0xc530);
          printf(pcVar4,DAT_0000c780 + 0xc532);
        }
        printf(pcVar4,DAT_0000c360 + 0xc15e);
      }
      if (-1 < (int)(unaff_r6 << 0x1b)) break;
      __format = (code *)(DAT_0000c784 + 0xc546);
      printf((char *)__format,DAT_0000c788 + 0xc548);
    }
  } while( true );
}



/* Function: FUN_0000c820 @ 0000c820 */

/* WARNING: Removing unreachable block (ram,0x0000bea0) */

void FUN_0000c820(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  code *__format;
  void *__ptr;
  void *pvVar5;
  code *__s2;
  int iVar6;
  FILE *pFVar7;
  int unaff_r5;
  uint unaff_r6;
  undefined4 unaff_r7;
  int unaff_r8;
  int unaff_r9;
  void *unaff_r10;
  char *unaff_r11;
  int extraout_r12;
  int in_stack_0000002c;
  int in_stack_00000030;
  char *in_stack_00000038;
  int in_stack_00000040;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  int in_stack_0000009c;
  undefined4 in_stack_000000a0;
  void *in_stack_000000a4;
  void *in_stack_000000a8;
  void *in_stack_000000ac;
  void *in_stack_000000b0;
  int in_stack_00000134;
  
  __s2 = *(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14);
  (*__s2)(2,iRam0000c904 + 0xc82c);
  (**(code **)(**(int **)(extraout_r12 + iRam0000c8f8) + 0x14))
            (2,iRam0000c908 + 0xc844,FUN_0000c85a[iRam0000c90c + unaff_r5]);
  do {
    printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
    __format = FUN_0000c61e + DAT_0000c7b0;
    while( true ) {
      printf((char *)__format,DAT_0000c78c + 0xc554);
      while( true ) {
        do {
          if (-1 < (int)(unaff_r6 << 0x1a)) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c75c + 0xc478);
            }
            else {
              pcVar4 = (char *)(DAT_0000c364 + 0xc170);
            }
            printf(pcVar4,DAT_0000c368 + 0xc174);
          }
          pFVar7 = (FILE *)(*(int *)(unaff_r9 + in_stack_00000030) + 0x54);
          fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar7);
          if ((int)(unaff_r6 << 0x1c) < 0) {
            fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar7);
          }
          if ((int)(unaff_r6 << 0x19) < 0) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c760 + 0xc480);
              printf(pcVar4,DAT_0000c764 + 0xc482);
            }
            else {
              printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
              pcVar4 = (char *)(DAT_0000c37c + 0xc1ba);
            }
            printf(pcVar4,DAT_0000c380 + 0xc1be);
          }
          if ((int)(unaff_r6 << 0x1b) < 0) {
            printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
            pcVar4 = (char *)(DAT_0000c38c + 0xc1d8);
          }
          else {
            pcVar4 = (char *)(iRam0000c754 + 0xc418);
            printf(pcVar4,DAT_0000c758 + 0xc41a);
          }
          printf(pcVar4,DAT_0000c390 + 0xc1dc);
          putchar(10);
          do {
            iVar1 = iptc_first_rule(__s2,unaff_r7);
            if (iVar1 != 0) {
              iVar6 = 0;
              do {
                iVar6 = iVar6 + 1;
                if ((unaff_r8 == iVar6) || (in_stack_0000002c != 0)) {
                  uVar2 = iptc_get_target(iVar1,unaff_r7);
                  FUN_0000a3f0(iVar1,uVar2,iVar6,unaff_r6);
                }
                iVar1 = iptc_next_rule(iVar1,unaff_r7);
              } while (iVar1 != 0);
            }
            iVar1 = 1;
            do {
              __s2 = (code *)iptc_next_chain(unaff_r7);
              if (__s2 == (code *)0x0) {
                puVar3 = (undefined4 *)__errno();
                *puVar3 = 2;
                if ((in_stack_0000009c << 0x18 < 0) && (iVar1 = FUN_0000acf0(), iVar1 == 0)) {
                  FUN_0000bc28();
                  return;
                }
                if (in_stack_0000009c << 0x12 < 0) {
                  iVar1 = iptc_zero_counter();
                }
                puVar3 = in_stack_00000098;
                if (1 < in_stack_00000054) {
                  dump_entries(*in_stack_00000050);
                  puVar3 = in_stack_00000098;
                }
                while (puVar3 != (void *)0x0) {
                  __ptr = (void *)puVar3[1];
                  pvVar5 = (void *)*puVar3;
                  if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
                    free(*(void **)((int)__ptr + 0x38));
                    *(undefined4 *)(puVar3[1] + 0x38) = 0;
                    __ptr = (void *)puVar3[1];
                  }
                  if (__ptr == *(void **)((int)__ptr + 4)) {
                    free(__ptr);
                    puVar3[1] = 0;
                  }
                  free(puVar3);
                  puVar3 = pvVar5;
                }
                in_stack_00000098 = (undefined4 *)0x0;
                if (unaff_r10 != (void *)0x0) {
                  free(unaff_r10);
                }
                free(in_stack_000000b0);
                free(in_stack_000000ac);
                free(in_stack_000000a8);
                free(in_stack_000000a4);
                FUN_00021f14(1);
                if (in_stack_00000134 == **(int **)(unaff_r9 + in_stack_00000058)) {
                  return;
                }
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail(iVar1);
              }
            } while ((unaff_r11 != (char *)0x0) &&
                    (iVar6 = strcmp(unaff_r11,(char *)__s2), iVar6 != 0));
            putchar(10);
          } while (unaff_r8 != 0);
          iVar1 = iptc_get_policy(__s2,&stack0x00000078,unaff_r7);
          printf(in_stack_00000038,__s2);
          if (iVar1 == 0) {
            iVar1 = iptc_get_references(&stack0x00000094,__s2,unaff_r7);
            if (iVar1 == 0) {
              puts((char *)(DAT_0000c76c + 0xc4d4));
              in_stack_00000030 = DAT_0000c770;
            }
            else {
              printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
              in_stack_00000030 = iRam0000c8f4;
            }
          }
          else {
            printf((char *)(DAT_0000c344 + 0xc10c));
            if ((int)(unaff_r6 << 0x1e) < 0) {
              in_stack_00000030 = DAT_0000c348;
            }
            else {
              in_stack_00000030 = DAT_0000c770;
              pFVar7 = (FILE *)(*(int *)(unaff_r9 + DAT_0000c770) + 0x54);
              fputc(0x20,pFVar7);
              FUN_0000a018(in_stack_00000078,in_stack_0000007c,unaff_r6 | 0x10);
              fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar7);
              FUN_0000a018(in_stack_00000080,in_stack_00000084,unaff_r6 | 0x10);
              fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar7);
            }
            puts((char *)(DAT_0000c34c + 0xc11e));
          }
          if (in_stack_00000040 != 0) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c768 + 0xc4be);
            }
            else {
              pcVar4 = (char *)(DAT_0000c350 + 0xc132);
            }
            printf(pcVar4,DAT_0000c354 + 0xc136);
          }
        } while ((int)(unaff_r6 << 0x1e) < 0);
        if (-1 < (int)(unaff_r6 << 0x1d)) break;
        if ((int)(unaff_r6 << 0x1b) < 0) {
          pcVar4 = (char *)(DAT_0000c358 + 0xc150);
          printf(pcVar4,DAT_0000c35c + 0xc152);
        }
        else {
          pcVar4 = (char *)(DAT_0000c77c + 0xc530);
          printf(pcVar4,DAT_0000c780 + 0xc532);
        }
        printf(pcVar4,DAT_0000c360 + 0xc15e);
      }
      if (-1 < (int)(unaff_r6 << 0x1b)) break;
      __format = (code *)(DAT_0000c784 + 0xc546);
      printf((char *)__format,DAT_0000c788 + 0xc548);
    }
  } while( true );
}



/* Function: FUN_0000c834 @ 0000c834 */

/* WARNING: Removing unreachable block (ram,0x0000bea0) */

void FUN_0000c834(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  code *__format;
  void *__ptr;
  void *pvVar5;
  char *unaff_r4;
  int iVar6;
  FILE *pFVar7;
  int unaff_r5;
  uint unaff_r6;
  undefined4 unaff_r7;
  int unaff_r8;
  int unaff_r9;
  void *unaff_r10;
  char *unaff_r11;
  int in_r12;
  int in_stack_0000002c;
  int in_stack_00000030;
  char *in_stack_00000038;
  int in_stack_00000040;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000094;
  undefined4 *in_stack_00000098;
  int in_stack_0000009c;
  undefined4 in_stack_000000a0;
  void *in_stack_000000a4;
  void *in_stack_000000a8;
  void *in_stack_000000ac;
  void *in_stack_000000b0;
  int in_stack_00000134;
  
  (**(code **)(**(int **)(in_r12 + iRam0000c8f8) + 0x14))
            (2,iRam0000c908 + 0xc844,FUN_0000c85a[iRam0000c90c + unaff_r5]);
  do {
    printf((char *)(DAT_0000c7a8 + 0xc614),DAT_0000c7ac + 0xc616);
    __format = FUN_0000c61e + DAT_0000c7b0;
    while( true ) {
      printf((char *)__format,DAT_0000c78c + 0xc554);
      while( true ) {
        do {
          if (-1 < (int)(unaff_r6 << 0x1a)) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c75c + 0xc478);
            }
            else {
              pcVar4 = (char *)(DAT_0000c364 + 0xc170);
            }
            printf(pcVar4,DAT_0000c368 + 0xc174);
          }
          pFVar7 = (FILE *)(*(int *)(unaff_r9 + in_stack_00000030) + 0x54);
          fwrite((void *)(DAT_0000c36c + 0xc184),1,6,pFVar7);
          if ((int)(unaff_r6 << 0x1c) < 0) {
            fwrite((void *)(DAT_0000c370 + 0xc19a),1,3,pFVar7);
          }
          if ((int)(unaff_r6 << 0x19) < 0) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c760 + 0xc480);
              printf(pcVar4,DAT_0000c764 + 0xc482);
            }
            else {
              printf((char *)(DAT_0000c374 + 0xc1b0),DAT_0000c378 + 0xc1b2);
              pcVar4 = (char *)(DAT_0000c37c + 0xc1ba);
            }
            printf(pcVar4,DAT_0000c380 + 0xc1be);
          }
          if ((int)(unaff_r6 << 0x1b) < 0) {
            printf((char *)(DAT_0000c384 + 0xc1ce),DAT_0000c388 + 0xc1d0);
            pcVar4 = (char *)(DAT_0000c38c + 0xc1d8);
          }
          else {
            pcVar4 = (char *)(iRam0000c754 + 0xc418);
            printf(pcVar4,DAT_0000c758 + 0xc41a);
          }
          printf(pcVar4,DAT_0000c390 + 0xc1dc);
          putchar(10);
          do {
            iVar1 = iptc_first_rule(unaff_r4,unaff_r7);
            if (iVar1 != 0) {
              iVar6 = 0;
              do {
                iVar6 = iVar6 + 1;
                if ((unaff_r8 == iVar6) || (in_stack_0000002c != 0)) {
                  uVar2 = iptc_get_target(iVar1,unaff_r7);
                  FUN_0000a3f0(iVar1,uVar2,iVar6,unaff_r6);
                }
                iVar1 = iptc_next_rule(iVar1,unaff_r7);
              } while (iVar1 != 0);
            }
            iVar1 = 1;
            do {
              unaff_r4 = (char *)iptc_next_chain(unaff_r7);
              if (unaff_r4 == (char *)0x0) {
                puVar3 = (undefined4 *)__errno();
                *puVar3 = 2;
                if ((in_stack_0000009c << 0x18 < 0) && (iVar1 = FUN_0000acf0(), iVar1 == 0)) {
                  FUN_0000bc28();
                  return;
                }
                if (in_stack_0000009c << 0x12 < 0) {
                  iVar1 = iptc_zero_counter();
                }
                puVar3 = in_stack_00000098;
                if (1 < in_stack_00000054) {
                  dump_entries(*in_stack_00000050);
                  puVar3 = in_stack_00000098;
                }
                while (puVar3 != (void *)0x0) {
                  __ptr = (void *)puVar3[1];
                  pvVar5 = (void *)*puVar3;
                  if (*(void **)((int)__ptr + 0x38) != (void *)0x0) {
                    free(*(void **)((int)__ptr + 0x38));
                    *(undefined4 *)(puVar3[1] + 0x38) = 0;
                    __ptr = (void *)puVar3[1];
                  }
                  if (__ptr == *(void **)((int)__ptr + 4)) {
                    free(__ptr);
                    puVar3[1] = 0;
                  }
                  free(puVar3);
                  puVar3 = pvVar5;
                }
                in_stack_00000098 = (undefined4 *)0x0;
                if (unaff_r10 != (void *)0x0) {
                  free(unaff_r10);
                }
                free(in_stack_000000b0);
                free(in_stack_000000ac);
                free(in_stack_000000a8);
                free(in_stack_000000a4);
                FUN_00021f14(1);
                if (in_stack_00000134 == **(int **)(unaff_r9 + in_stack_00000058)) {
                  return;
                }
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail(iVar1);
              }
            } while ((unaff_r11 != (char *)0x0) && (iVar6 = strcmp(unaff_r11,unaff_r4), iVar6 != 0))
            ;
            putchar(10);
          } while (unaff_r8 != 0);
          iVar1 = iptc_get_policy(unaff_r4,&stack0x00000078,unaff_r7);
          printf(in_stack_00000038,unaff_r4);
          if (iVar1 == 0) {
            iVar1 = iptc_get_references(&stack0x00000094,unaff_r4,unaff_r7);
            if (iVar1 == 0) {
              puts((char *)(DAT_0000c76c + 0xc4d4));
              in_stack_00000030 = DAT_0000c770;
            }
            else {
              printf((char *)(iRam0000c8f0 + 0xc7f8),in_stack_00000094);
              in_stack_00000030 = iRam0000c8f4;
            }
          }
          else {
            printf((char *)(DAT_0000c344 + 0xc10c));
            if ((int)(unaff_r6 << 0x1e) < 0) {
              in_stack_00000030 = DAT_0000c348;
            }
            else {
              in_stack_00000030 = DAT_0000c770;
              pFVar7 = (FILE *)(*(int *)(unaff_r9 + DAT_0000c770) + 0x54);
              fputc(0x20,pFVar7);
              FUN_0000a018(in_stack_00000078,in_stack_0000007c,unaff_r6 | 0x10);
              fwrite((void *)(DAT_0000c774 + 0xc50c),1,9,pFVar7);
              FUN_0000a018(in_stack_00000080,in_stack_00000084,unaff_r6 | 0x10);
              fwrite((void *)(DAT_0000c778 + 0xc524),1,5,pFVar7);
            }
            puts((char *)(DAT_0000c34c + 0xc11e));
          }
          if (in_stack_00000040 != 0) {
            if ((int)(unaff_r6 << 0x1b) < 0) {
              pcVar4 = (char *)(DAT_0000c768 + 0xc4be);
            }
            else {
              pcVar4 = (char *)(DAT_0000c350 + 0xc132);
            }
            printf(pcVar4,DAT_0000c354 + 0xc136);
          }
        } while ((int)(unaff_r6 << 0x1e) < 0);
        if (-1 < (int)(unaff_r6 << 0x1d)) break;
        if ((int)(unaff_r6 << 0x1b) < 0) {
          pcVar4 = (char *)(DAT_0000c358 + 0xc150);
          printf(pcVar4,DAT_0000c35c + 0xc152);
        }
        else {
          pcVar4 = (char *)(DAT_0000c77c + 0xc530);
          printf(pcVar4,DAT_0000c780 + 0xc532);
        }
        printf(pcVar4,DAT_0000c360 + 0xc15e);
      }
      if (-1 < (int)(unaff_r6 << 0x1b)) break;
      __format = (code *)(DAT_0000c784 + 0xc546);
      printf((char *)__format,DAT_0000c788 + 0xc548);
    }
  } while( true );
}



/* Function: FUN_0000c84a @ 0000c84a */

void FUN_0000c84a(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  char *__format;
  undefined1 *puVar3;
  int extraout_r2;
  int extraout_r3;
  int iVar4;
  FILE *__stream;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  undefined1 auStack_8 [8];
  
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c910 + 0xc856);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c914 + 0xc866);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c918 + 0xc876);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c91c + 0xc886,0x52);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c920 + 0xc898);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c924 + 0xc8a8);
  puVar3 = (undefined1 *)(iRam0000c928 + 0xc8c6);
  do {
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined1 *)(iRam0000c928 + 0xc8d1));
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c92c + 0xc8ce,*puVar3);
  puVar3 = (undefined1 *)(iRam0000c930 + 0xc8e8);
  do {
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined1 *)(iRam0000c930 + 0xc8f3));
  uVar2 = (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c934 + 0xc8f0,*puVar3)
  ;
  *(undefined2 *)(unaff_r5 + 0x2e) = uVar2;
  iVar4 = unaff_r5 * 0x80;
  __format = (char *)(unaff_r7 * 0x100);
  uVar2 = (undefined2)iVar4;
  *(undefined2 *)(unaff_r7 + 10) = uVar2;
  *(short *)(extraout_r3 + 10) = (short)__format;
  *(undefined2 *)(extraout_r2 + 0x24) = uVar2;
  *(undefined2 *)(extraout_r2 + 0x22) = uVar2;
  __format[8] = (char)extraout_r2;
  uVar1 = (undefined2)extraout_r2;
  *(undefined2 *)(extraout_r2 + 0x1a) = uVar1;
  *(undefined2 *)(extraout_r3 + 0x1a) = uVar1;
  *(undefined2 *)(__format + 0x18) = uVar1;
  *(char *)(unaff_r7 + 0x19) = (char)extraout_r2;
  *(undefined1 *)(unaff_r6 + 0x1a) = 0;
  *(undefined2 *)(__format + 8) = uVar2;
  *(char *)(extraout_r2 + 6) = (char)unaff_r6;
  *(short *)(iVar4 + 10) = (short)unaff_r6;
  *(char *)(unaff_r6 + 5) = (char)iVar4;
  *(undefined2 *)(iVar4 + 8) = uVar2;
  iVar4 = *(int *)(DAT_0000c9a0 + 0xc94e + DAT_0000c9a8);
  __stream = (FILE *)(*(int *)(DAT_0000c9a0 + 0xc94e + DAT_0000c9a4) + 0xa8);
  fprintf(__stream,(char *)(DAT_0000c9ac + 0xc95c),*(undefined4 *)(iVar4 + 4),
          *(undefined4 *)(iVar4 + 8));
  vfprintf(__stream,__format,auStack_8);
  fputc(10,__stream);
  if (__format != (char *)0x2) {
    if (__format == (char *)0x3) {
      fwrite((void *)(DAT_0000c9b0 + 0xc99a),1,0x36,__stream);
    }
    FUN_00021f14(1);
                    /* WARNING: Subroutine does not return */
    exit((int)__format);
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000a2c4(2);
}



/* Function: FUN_0000c85a @ 0000c85a */

void FUN_0000c85a(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  char *__format;
  undefined1 *puVar3;
  int extraout_r2;
  int extraout_r3;
  int iVar4;
  FILE *__stream;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  undefined1 auStack_8 [8];
  
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c914 + 0xc866);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c918 + 0xc876);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c91c + 0xc886,0x52);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c920 + 0xc898);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c924 + 0xc8a8);
  puVar3 = (undefined1 *)(iRam0000c928 + 0xc8c6);
  do {
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined1 *)(iRam0000c928 + 0xc8d1));
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c92c + 0xc8ce,*puVar3);
  puVar3 = (undefined1 *)(iRam0000c930 + 0xc8e8);
  do {
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined1 *)(iRam0000c930 + 0xc8f3));
  uVar2 = (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c934 + 0xc8f0,*puVar3)
  ;
  *(undefined2 *)(unaff_r5 + 0x2e) = uVar2;
  iVar4 = unaff_r5 * 0x80;
  __format = (char *)(unaff_r7 * 0x100);
  uVar2 = (undefined2)iVar4;
  *(undefined2 *)(unaff_r7 + 10) = uVar2;
  *(short *)(extraout_r3 + 10) = (short)__format;
  *(undefined2 *)(extraout_r2 + 0x24) = uVar2;
  *(undefined2 *)(extraout_r2 + 0x22) = uVar2;
  __format[8] = (char)extraout_r2;
  uVar1 = (undefined2)extraout_r2;
  *(undefined2 *)(extraout_r2 + 0x1a) = uVar1;
  *(undefined2 *)(extraout_r3 + 0x1a) = uVar1;
  *(undefined2 *)(__format + 0x18) = uVar1;
  *(char *)(unaff_r7 + 0x19) = (char)extraout_r2;
  *(undefined1 *)(unaff_r6 + 0x1a) = 0;
  *(undefined2 *)(__format + 8) = uVar2;
  *(char *)(extraout_r2 + 6) = (char)unaff_r6;
  *(short *)(iVar4 + 10) = (short)unaff_r6;
  *(char *)(unaff_r6 + 5) = (char)iVar4;
  *(undefined2 *)(iVar4 + 8) = uVar2;
  iVar4 = *(int *)(DAT_0000c9a0 + 0xc94e + DAT_0000c9a8);
  __stream = (FILE *)(*(int *)(DAT_0000c9a0 + 0xc94e + DAT_0000c9a4) + 0xa8);
  fprintf(__stream,(char *)(DAT_0000c9ac + 0xc95c),*(undefined4 *)(iVar4 + 4),
          *(undefined4 *)(iVar4 + 8));
  vfprintf(__stream,__format,auStack_8);
  fputc(10,__stream);
  if (__format != (char *)0x2) {
    if (__format == (char *)0x3) {
      fwrite((void *)(DAT_0000c9b0 + 0xc99a),1,0x36,__stream);
    }
    FUN_00021f14(1);
                    /* WARNING: Subroutine does not return */
    exit((int)__format);
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000a2c4(2);
}



/* Function: FUN_0000c86a @ 0000c86a */

void FUN_0000c86a(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  char *__format;
  undefined1 *puVar3;
  int extraout_r2;
  int extraout_r3;
  int iVar4;
  FILE *__stream;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  undefined1 auStack_8 [8];
  
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c918 + 0xc876);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c91c + 0xc886,0x52);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c920 + 0xc898);
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c924 + 0xc8a8);
  puVar3 = (undefined1 *)(iRam0000c928 + 0xc8c6);
  do {
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined1 *)(iRam0000c928 + 0xc8d1));
  (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c92c + 0xc8ce,*puVar3);
  puVar3 = (undefined1 *)(iRam0000c930 + 0xc8e8);
  do {
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined1 *)(iRam0000c930 + 0xc8f3));
  uVar2 = (**(code **)(**(int **)(unaff_r5 + iRam0000c8f8) + 0x14))(2,iRam0000c934 + 0xc8f0,*puVar3)
  ;
  *(undefined2 *)(unaff_r5 + 0x2e) = uVar2;
  iVar4 = unaff_r5 * 0x80;
  __format = (char *)(unaff_r7 * 0x100);
  uVar2 = (undefined2)iVar4;
  *(undefined2 *)(unaff_r7 + 10) = uVar2;
  *(short *)(extraout_r3 + 10) = (short)__format;
  *(undefined2 *)(extraout_r2 + 0x24) = uVar2;
  *(undefined2 *)(extraout_r2 + 0x22) = uVar2;
  __format[8] = (char)extraout_r2;
  uVar1 = (undefined2)extraout_r2;
  *(undefined2 *)(extraout_r2 + 0x1a) = uVar1;
  *(undefined2 *)(extraout_r3 + 0x1a) = uVar1;
  *(undefined2 *)(__format + 0x18) = uVar1;
  *(char *)(unaff_r7 + 0x19) = (char)extraout_r2;
  *(undefined1 *)(unaff_r6 + 0x1a) = 0;
  *(undefined2 *)(__format + 8) = uVar2;
  *(char *)(extraout_r2 + 6) = (char)unaff_r6;
  *(short *)(iVar4 + 10) = (short)unaff_r6;
  *(char *)(unaff_r6 + 5) = (char)iVar4;
  *(undefined2 *)(iVar4 + 8) = uVar2;
  iVar4 = *(int *)(DAT_0000c9a0 + 0xc94e + DAT_0000c9a8);
  __stream = (FILE *)(*(int *)(DAT_0000c9a0 + 0xc94e + DAT_0000c9a4) + 0xa8);
  fprintf(__stream,(char *)(DAT_0000c9ac + 0xc95c),*(undefined4 *)(iVar4 + 4),
          *(undefined4 *)(iVar4 + 8));
  vfprintf(__stream,__format,auStack_8);
  fputc(10,__stream);
  if (__format != (char *)0x2) {
    if (__format == (char *)0x3) {
      fwrite((void *)(DAT_0000c9b0 + 0xc99a),1,0x36,__stream);
    }
    FUN_00021f14(1);
                    /* WARNING: Subroutine does not return */
    exit((int)__format);
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000a2c4(2);
}



/* Function: FUN_0000ca9c @ 0000ca9c */

void FUN_0000ca9c(int param_1,int *param_2)

{
  code *pcVar1;
  char *pcVar2;
  
  if (param_1 != 0) {
    pcVar2 = (char *)(DAT_0000cb08 + 0xcaac);
    do {
      while (*(int *)(param_1 + 0x40) == 0) {
LAB_0000caac:
        param_1 = *(int *)(param_1 + 4);
        if (param_1 == 0) goto LAB_0000cacc;
      }
      putchar(10);
      if (*(code **)(param_1 + 0x18) == (code *)0x0) {
        printf(pcVar2,*(undefined4 *)(param_1 + 8));
        goto LAB_0000caac;
      }
      (**(code **)(param_1 + 0x18))();
      param_1 = *(int *)(param_1 + 4);
    } while (param_1 != 0);
  }
LAB_0000cacc:
  if (param_2 != (int *)0x0) {
    pcVar2 = (char *)(DAT_0000cb0c + 0xcad6);
    do {
      while( true ) {
        putchar(10);
        pcVar1 = *(code **)(param_2[1] + 0x18);
        if (pcVar1 != (code *)0x0) break;
        printf(pcVar2,*(undefined4 *)(param_2[1] + 8));
        param_2 = (int *)*param_2;
        if (param_2 == (int *)0x0) {
          return;
        }
      }
      (*pcVar1)();
      param_2 = (int *)*param_2;
    } while (param_2 != (int *)0x0);
  }
  return;
}



/* Function: FUN_0000cb10 @ 0000cb10 */

undefined4 FUN_0000cb10(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int extraout_r1;
  int *piVar3;
  int iVar4;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    piVar3 = *(int **)(param_1 + 8);
    if (piVar3 != (int *)(param_1 + 8)) {
      iVar4 = 0;
      do {
        if (piVar3[10] == 0) {
          uVar2 = __aeabi_uidiv(iVar4,0x28);
          if (*(uint *)(param_1 + 0x20) <= uVar2) break;
          __aeabi_uidivmod(iVar4,0x28);
          if (extraout_r1 == 0) {
            *(int **)(uVar2 * 4 + *(int *)(param_1 + 0x1c)) = piVar3;
          }
          iVar4 = iVar4 + 1;
        }
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)(param_1 + 8));
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* Function: iptc_first_chain @ 0000cb68 */

int * iptc_first_chain(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 8);
  *(undefined4 *)(DAT_0000cb9c + 0xcb78) = *(undefined4 *)(DAT_0000cb98 + 0xcb74);
  piVar1 = (int *)0x0;
  if (piVar2 != (int *)(param_1 + 8)) {
    *(int **)(param_1 + 0x10) = piVar2;
    if ((int *)(param_1 + 8) == (int *)*piVar2) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    else {
      *(int **)(param_1 + 0x10) = (int *)*piVar2;
    }
    piVar1 = piVar2 + 2;
  }
  return piVar1;
}



/* Function: iptc_next_chain @ 0000cba0 */

int * iptc_next_chain(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x10);
  *(undefined4 *)(DAT_0000cbd4 + 0xcbae) = *(undefined4 *)(DAT_0000cbd0 + 0xcbaa);
  piVar2 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == param_1 + 8) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    else {
      *(int *)(param_1 + 0x10) = *piVar1;
    }
    piVar2 = piVar1 + 2;
  }
  return piVar2;
}



/* Function: iptc_next_rule @ 0000cbd8 */

int iptc_next_rule(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  *(undefined4 *)(DAT_0000cc08 + 0xcbe6) = *(undefined4 *)(DAT_0000cc04 + 0xcbe2);
  piVar2 = *(int **)(param_2 + 0x14);
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    if (iVar1 == piVar2[2] + 0x54) {
      *(undefined4 *)(param_2 + 0x14) = 0;
      iVar1 = 0;
    }
    else {
      *(int *)(param_2 + 0x14) = iVar1;
      iVar1 = iVar1 + 0x28;
    }
  }
  return iVar1;
}



/* Function: FUN_0000cc0c @ 0000cc0c */

char * FUN_0000cc0c(int param_1)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  int local_118 [2];
  undefined4 local_110 [65];
  
  piVar3 = local_118;
  memcpy(local_118,(void *)(DAT_0000cc5c + 0xcc1c),0x108);
  iVar2 = 0;
  while (((*piVar3 != 0 && (*piVar3 != *(int *)(DAT_0000cc60 + 0xcc2a))) || (piVar3[1] != param_1)))
  {
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 3;
    if (iVar2 == 0x16) {
      pcVar1 = strerror(param_1);
      return pcVar1;
    }
  }
  return (char *)local_110[iVar2 * 3];
}



/* Function: FUN_0000cc64 @ 0000cc64 */

undefined4 FUN_0000cc64(int param_1)

{
  int iVar1;
  void *__s;
  int extraout_r1;
  undefined4 uVar2;
  size_t __size;
  
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  __aeabi_uidivmod(uVar2,0x28);
  iVar1 = __aeabi_uidiv(uVar2,0x28);
  iVar1 = (uint)(extraout_r1 != 0) + iVar1;
  __size = iVar1 * 4;
  __s = malloc(__size);
  *(void **)(param_1 + 0x1c) = __s;
  if ((__s == (void *)0x0) && (__size != 0)) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    uVar2 = 0xfffffff4;
  }
  else {
    memset(__s,0,__size);
    *(int *)(param_1 + 0x20) = iVar1;
    uVar2 = 1;
  }
  return uVar2;
}



/* Function: FUN_0000ccac @ 0000ccac */

void FUN_0000ccac(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = malloc(param_2 + 0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[2] = param_1;
    puVar1[9] = param_2;
  }
  return;
}



/* Function: FUN_0000ccdc @ 0000ccdc */

undefined4 FUN_0000ccdc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  free(*(void **)(param_1 + 0x1c));
  iVar1 = FUN_0000cc64(param_1);
  if (iVar1 < 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    FUN_0000cb10(param_1);
    uVar2 = 1;
  }
  return uVar2;
}



/* Function: FUN_0000cd04 @ 0000cd04 */

void FUN_0000cd04(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1[7] == 3) && (iVar1 = param_1[8], iVar1 != 0)) {
    *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) + -1;
  }
  piVar2 = (int *)param_1[1];
  iVar1 = *param_1;
  *(int **)(iVar1 + 4) = piVar2;
  *piVar2 = iVar1;
  *param_1 = DAT_0000cd30;
  param_1[1] = DAT_0000cd34;
  free(param_1);
  return;
}



/* Function: FUN_0000cd38 @ 0000cd38 */

bool FUN_0000cd38(int param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 *puVar2;
  short *psVar3;
  
  psVar3 = (short *)(param_1 + 0x28 + (uint)*(ushort *)(param_1 + 0x80));
  sVar1 = *psVar3;
  if (sVar1 == 0x28) {
    memset(psVar3 + 1,0,0x1e);
    *(undefined4 *)(psVar3 + 0x10) = param_2;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
  }
  return sVar1 == 0x28;
}



/* Function: iptc_commit @ 0000cd70 */

/* WARNING: Type propagation algorithm not settling */

undefined4 iptc_commit(int *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *__dest;
  void *pvVar4;
  char *__dest_00;
  undefined4 *puVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  size_t __size;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  int local_48;
  
  *(undefined4 *)(DAT_0000d0e0 + 0xcd8a) = *(undefined4 *)(DAT_0000d0dc + 0xcd86);
  if (param_1[1] == 0) {
    return 1;
  }
  piVar15 = (int *)param_1[2];
  if (piVar15 == param_1 + 2) {
    iVar14 = 0xb0;
    local_48 = 1;
  }
  else {
    iVar10 = 0;
    iVar8 = 0;
    do {
      piVar15[0x18] = iVar8;
      if (piVar15[10] == 0) {
        iVar8 = iVar8 + 0xb0;
        iVar10 = iVar10 + 1;
      }
      local_48 = iVar10;
      iVar14 = iVar8;
      for (piVar16 = (int *)piVar15[0x15]; piVar16 != piVar15 + 0x15; piVar16 = (int *)*piVar16) {
        piVar16[6] = iVar14;
        piVar16[5] = local_48;
        local_48 = local_48 + 1;
        iVar14 = iVar14 + piVar16[9];
      }
      piVar15[0x1a] = iVar14;
      piVar15[0x19] = local_48;
      piVar15 = (int *)*piVar15;
      iVar8 = iVar14 + 0x98;
      iVar10 = local_48 + 1;
    } while (piVar15 != param_1 + 2);
    iVar14 = iVar14 + 0x148;
    local_48 = local_48 + 2;
    if (local_48 < 0) goto LAB_0000d0b8;
  }
  __dest = malloc(iVar14 + 0x60U);
  if (__dest != (char *)0x0) {
    memset(__dest,0,iVar14 + 0x60U);
    pvVar4 = malloc(param_1[0x1d] << 4);
    *(void **)(__dest + 0x58) = pvVar4;
    if (pvVar4 == (void *)0x0) {
      puVar5 = (undefined4 *)__errno();
      *puVar5 = 0xc;
    }
    else {
      __size = local_48 * 0x10 + 0x28;
      __dest_00 = malloc(__size);
      if (__dest_00 == (char *)0x0) {
        puVar5 = (undefined4 *)__errno();
        *puVar5 = 0xc;
      }
      else {
        memset(__dest_00,0,__size);
        strcpy(__dest,(char *)(param_1 + 10));
        *(int *)(__dest + 0x28) = iVar14;
        *(int *)(__dest + 0x24) = local_48;
        *(int *)(__dest + 0x54) = param_1[0x1d];
        *(int *)(__dest + 0x20) = param_1[0x12];
        for (piVar16 = (int *)param_1[2]; piVar15 != piVar16; piVar16 = (int *)*piVar16) {
          if (piVar16[10] == 0) {
            iVar10 = piVar16[0x18];
            (__dest + iVar10 + 0xb8)[0] = 'p';
            uVar2 = DAT_0000d0e4;
            (__dest + iVar10 + 0xb8)[1] = '\0';
            (__dest + iVar10 + 0xba)[0] = -0x50;
            uVar3 = DAT_0000d0e8;
            (__dest + iVar10 + 0xba)[1] = '\0';
            *(short *)(__dest + iVar10 + 0xd2) = (short)uVar2;
            *(short *)(__dest + iVar10 + 0xd4) = (short)uVar3;
            (__dest + iVar10 + 0xd6)[0] = 'R';
            (__dest + iVar10 + 0xd6)[1] = '\0';
            (__dest + iVar10 + 0xd0)[0] = '@';
            (__dest + iVar10 + 0xd0)[1] = '\0';
            strcpy(__dest + iVar10 + 0xf0,(char *)(piVar16 + 2));
          }
          else {
            *(int *)(__dest + (piVar16[10] + 9) * 4 + 4) = piVar16[0x18];
            *(int *)(__dest + (piVar16[10] + 0xf) * 4) = piVar16[0x1a];
          }
          for (piVar13 = (int *)piVar16[0x15]; piVar13 != piVar16 + 0x15; piVar13 = (int *)*piVar13)
          {
            if (piVar13[7] == 3) {
              uVar6 = (uint)*(ushort *)(piVar13 + 0x20);
              memset((void *)((int)piVar13 + uVar6 + 0x2a),0,0x1e);
              *(undefined1 *)((int)piVar13 + uVar6 + 0x2a) = 0;
              *(int *)((int)piVar13 + uVar6 + 0x48) = *(int *)(piVar13[8] + 0x60) + 0xb0;
            }
            else if (piVar13[7] == 2) {
              *(int *)((int)piVar13 + *(ushort *)(piVar13 + 0x20) + 0x48) = piVar13[9] + piVar13[6];
            }
            memcpy(__dest + piVar13[6] + 0x60,piVar13 + 10,piVar13[9]);
          }
          iVar10 = piVar16[0x1a];
          (__dest + iVar10 + 0xb8)[0] = 'p';
          (__dest + iVar10 + 0xb8)[1] = '\0';
          (__dest + iVar10 + 0xba)[0] = -0x68;
          (__dest + iVar10 + 0xba)[1] = '\0';
          __dest[iVar10 + 0xd2] = '\0';
          (__dest + iVar10 + 0xd0)[0] = '(';
          (__dest + iVar10 + 0xd0)[1] = '\0';
          if (piVar16[10] == 0) {
            pcVar1 = __dest + iVar10 + 0xf0;
            pcVar1[0] = -5;
            pcVar1[1] = -1;
            pcVar1[2] = -1;
            pcVar1[3] = -1;
          }
          else {
            *(int *)(__dest + iVar10 + 0xf0) = piVar16[0xc];
          }
          memcpy(__dest + iVar10 + 0xc0,piVar16 + 0xe,0x10);
        }
        iVar10 = *(int *)(__dest + 0x28);
        (__dest + iVar10 + 8)[0] = 'p';
        (__dest + iVar10 + 8)[1] = '\0';
        (__dest + iVar10 + 10)[0] = -0x50;
        (__dest + iVar10 + 10)[1] = '\0';
        (__dest + iVar10 + 0x20)[0] = '@';
        (__dest + iVar10 + 0x20)[1] = '\0';
        *(short *)(__dest + iVar10 + 0x22) = (short)DAT_0000d0e4;
        *(short *)(__dest + iVar10 + 0x24) = (short)DAT_0000d0e8;
        (__dest + iVar10 + 0x26)[0] = 'R';
        uVar2 = DAT_0000d0ec;
        (__dest + iVar10 + 0x26)[1] = '\0';
        (__dest + iVar10 + 0x44)[0] = 'R';
        (__dest + iVar10 + 0x44)[1] = '\0';
        *(undefined4 *)(__dest + iVar10 + 0x40) = uVar2;
        iVar10 = setsockopt(*param_1,0,0x40,__dest,*(int *)(__dest + 0x28) + 0x60);
        if (-1 < iVar10) {
          strcpy(__dest_00,(char *)(param_1 + 10));
          *(int *)(__dest_00 + 0x20) = local_48;
          for (piVar16 = (int *)param_1[2]; piVar15 != piVar16; piVar16 = (int *)*piVar16) {
            if (piVar16[10] != 0) {
              iVar10 = piVar16[0x12];
              if (iVar10 == 1) {
                memcpy(__dest_00 + piVar16[0x19] * 0x10 + 0x28,
                       (void *)(*(int *)(__dest + 0x58) + piVar16[0x13] * 0x10),0x10);
              }
              else if (iVar10 == 0) {
                iVar10 = piVar16[0x19];
                pcVar11 = __dest_00 + (iVar10 + 3) * 0x10;
                pcVar1 = __dest_00 + iVar10 * 0x10 + 0x28;
                pcVar1[0] = '\0';
                pcVar1[1] = '\0';
                pcVar1[2] = '\0';
                pcVar1[3] = '\0';
                pcVar1 = __dest_00 + iVar10 * 0x10 + 0x2c;
                pcVar1[0] = '\0';
                pcVar1[1] = '\0';
                pcVar1[2] = '\0';
                pcVar1[3] = '\0';
                pcVar11[0] = '\0';
                pcVar11[1] = '\0';
                pcVar11[2] = '\0';
                pcVar11[3] = '\0';
                pcVar11[4] = '\0';
                pcVar11[5] = '\0';
                pcVar11[6] = '\0';
                pcVar11[7] = '\0';
              }
              else if (iVar10 == 2) {
                iVar10 = piVar16[0x19];
                puVar7 = (uint *)(*(int *)(__dest + 0x58) + piVar16[0x13] * 0x10);
                uVar12 = piVar16[0xe];
                iVar8 = piVar16[0xf];
                uVar6 = *puVar7;
                uVar9 = puVar7[1];
                *(uint *)(__dest_00 + iVar10 * 0x10 + 0x28) = uVar6 - uVar12;
                *(uint *)(__dest_00 + iVar10 * 0x10 + 0x2c) =
                     (uVar9 - iVar8) - (uint)(uVar6 < uVar12);
                uVar6 = puVar7[2];
                uVar9 = puVar7[3];
                uVar12 = piVar16[0x10];
                iVar8 = piVar16[0x11];
                *(uint *)(__dest_00 + (iVar10 + 3) * 0x10) = uVar6 - uVar12;
                *(uint *)((int)(__dest_00 + (iVar10 + 3) * 0x10) + 4) =
                     (uVar9 - iVar8) - (uint)(uVar6 < uVar12);
              }
              else if (iVar10 == 3) {
                memcpy(__dest_00 + piVar16[0x19] * 0x10 + 0x28,piVar16 + 0xe,0x10);
              }
            }
            for (piVar13 = (int *)piVar16[0x15]; piVar13 != piVar16 + 0x15;
                piVar13 = (int *)*piVar13) {
              iVar10 = piVar13[3];
              if (iVar10 == 1) {
                memcpy(__dest_00 + piVar13[5] * 0x10 + 0x28,
                       (void *)(*(int *)(__dest + 0x58) + piVar13[4] * 0x10),0x10);
              }
              else if (iVar10 == 0) {
                iVar10 = piVar13[5];
                pcVar11 = __dest_00 + (iVar10 + 3) * 0x10;
                pcVar1 = __dest_00 + iVar10 * 0x10 + 0x28;
                pcVar1[0] = '\0';
                pcVar1[1] = '\0';
                pcVar1[2] = '\0';
                pcVar1[3] = '\0';
                pcVar1 = __dest_00 + iVar10 * 0x10 + 0x2c;
                pcVar1[0] = '\0';
                pcVar1[1] = '\0';
                pcVar1[2] = '\0';
                pcVar1[3] = '\0';
                pcVar11[0] = '\0';
                pcVar11[1] = '\0';
                pcVar11[2] = '\0';
                pcVar11[3] = '\0';
                pcVar11[4] = '\0';
                pcVar11[5] = '\0';
                pcVar11[6] = '\0';
                pcVar11[7] = '\0';
              }
              else if (iVar10 == 2) {
                iVar10 = piVar13[5];
                puVar7 = (uint *)(*(int *)(__dest + 0x58) + piVar13[4] * 0x10);
                uVar6 = piVar13[0x22];
                iVar8 = piVar13[0x23];
                uVar9 = *puVar7;
                uVar12 = puVar7[1];
                *(uint *)(__dest_00 + iVar10 * 0x10 + 0x28) = uVar9 - uVar6;
                *(uint *)(__dest_00 + iVar10 * 0x10 + 0x2c) =
                     (uVar12 - iVar8) - (uint)(uVar9 < uVar6);
                uVar6 = piVar13[0x24];
                iVar8 = piVar13[0x25];
                uVar9 = puVar7[2];
                uVar12 = puVar7[3];
                *(uint *)(__dest_00 + (iVar10 + 3) * 0x10) = uVar9 - uVar6;
                *(uint *)((int)(__dest_00 + (iVar10 + 3) * 0x10) + 4) =
                     (uVar12 - iVar8) - (uint)(uVar9 < uVar6);
              }
              else if (iVar10 == 3) {
                memcpy(__dest_00 + piVar13[5] * 0x10 + 0x28,piVar13 + 0x22,0x10);
              }
            }
          }
          iVar10 = setsockopt(*param_1,0,0x41,__dest_00,__size);
          if (-1 < iVar10) {
            free(*(void **)(__dest + 0x58));
            free(__dest);
            free(__dest_00);
            return 1;
          }
        }
        free(__dest_00);
      }
      free(*(void **)(__dest + 0x58));
    }
    free(__dest);
    return 0;
  }
LAB_0000d0b8:
  puVar5 = (undefined4 *)__errno();
  *puVar5 = 0xc;
  return 0;
}



/* Function: FUN_0000d1f4 @ 0000d1f4 */

bool FUN_0000d1f4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x58);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + (uint)*(ushort *)(iVar2 + 0x80) + 0x48);
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x48) = 2;
    *(int *)(*(int *)(param_1 + 0x10) + 0x4c) = param_2 + -1;
    memcpy((void *)(*(int *)(param_1 + 0x10) + 0x38),(void *)(iVar2 + 0x88),0x10);
    *(int *)(*(int *)(param_1 + 0x10) + 100) = param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x68) = *(undefined4 *)(iVar2 + 0x18);
    FUN_0000cd04(iVar2);
    *(int *)(*(int *)(param_1 + 0x10) + 0x50) = *(int *)(*(int *)(param_1 + 0x10) + 0x50) + -1;
  }
  return iVar1 != 0;
}



/* Function: FUN_0000d244 @ 0000d244 */

int FUN_0000d244(char *param_1,int param_2,uint *param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar3 = *(uint *)(param_4 + 0x20);
  iVar7 = DAT_0000d330 + 0xd262;
  if (uVar3 != 0) {
    iVar5 = *(int *)(param_4 + 0x1c);
    uVar1 = uVar3 >> 1;
    while (uVar4 = uVar1, iVar6 = *(int *)(iVar5 + uVar4 * 4), iVar6 != 0) {
      if (param_5 == 0) {
        iVar5 = strcmp(param_1,(char *)(iVar6 + 8));
      }
      else {
        if (param_5 != 1) {
          fprintf((FILE *)(*(int *)(iVar7 + DAT_0000d334) + 0xa8),(char *)(DAT_0000d338 + 0xd2c8),
                  param_5);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        iVar5 = param_2 - *(int *)(iVar6 + 0x60);
      }
      *param_3 = uVar4;
      if (iVar5 == 0) {
        return iVar6;
      }
      if (iVar5 < 0) {
        if (uVar4 == 0) {
          return iVar6;
        }
        iVar5 = *(int *)(param_4 + 0x1c);
        uVar1 = uVar4 >> 1;
        uVar3 = uVar4;
      }
      else {
        if (*(int *)(param_4 + 0x20) - 1U == uVar4) {
          return iVar6;
        }
        if (param_5 == 0) {
          iVar5 = *(int *)(param_4 + 0x1c);
          iVar2 = strcmp(param_1,(char *)(*(int *)(iVar5 + (uVar4 + 1) * 4) + 8));
LAB_0000d2e8:
          if (iVar2 < 0) {
            return iVar6;
          }
        }
        else {
          if (param_5 == 1) {
            iVar5 = *(int *)(param_4 + 0x1c);
            iVar2 = param_2 - *(int *)(*(int *)(iVar5 + (uVar4 + 1) * 4) + 0x60);
            goto LAB_0000d2e8;
          }
          iVar5 = *(int *)(param_4 + 0x1c);
        }
        uVar1 = uVar4 + uVar3 >> 1;
      }
    }
    fprintf((FILE *)(*(int *)(iVar7 + DAT_0000d334) + 0xa8),(char *)(DAT_0000d33c + 0xd326),uVar4);
  }
  return param_4 + 8;
}



/* Function: FUN_0000d340 @ 0000d340 */

int * FUN_0000d340(char *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_1c;
  
  local_1c = 0;
  piVar2 = *(int **)(param_2 + 8);
  piVar4 = (int *)(param_2 + 8);
  if (piVar4 != piVar2) {
    do {
      piVar3 = piVar2;
      if (piVar2[10] == 0) break;
      iVar1 = strcmp((char *)(piVar2 + 2),param_1);
      if (iVar1 == 0) {
        return piVar2;
      }
      piVar2 = (int *)*piVar2;
      piVar3 = piVar4;
    } while (piVar4 != piVar2);
    piVar2 = (int *)FUN_0000d244(param_1,0,&local_1c,param_2,0);
    if (piVar4 == piVar2) {
      piVar2 = piVar3;
    }
    if (*(int *)(param_2 + 0x18) != 0) {
      piVar3 = (int *)piVar2[1];
      for (piVar2 = (int *)*piVar3; piVar3 != piVar2; piVar2 = (int *)*piVar2) {
        iVar1 = strcmp((char *)(piVar2 + 2),param_1);
        if (iVar1 == 0) {
          return piVar2;
        }
        if ((0 < iVar1) && (piVar2[10] == 0)) {
          return (int *)0x0;
        }
        if (piVar2 == piVar4) {
          return (int *)0x0;
        }
      }
    }
  }
  return (int *)0x0;
}



/* Function: iptc_set_policy @ 0000d3d8 */

undefined4 iptc_set_policy(undefined4 param_1,char *param_2,void *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = *(undefined4 *)(DAT_0000d460 + 0xd3e6);
  puVar4 = (undefined4 *)(DAT_0000d464 + 0xd3ea);
  *puVar4 = uVar3;
  iVar1 = FUN_0000d340(param_1,param_4,uVar3,puVar4,param_4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x28) != 0)) {
    iVar2 = strcmp(param_2,(char *)(DAT_0000d468 + 0xd404));
    if (iVar2 == 0) {
      *(undefined4 *)(iVar1 + 0x30) = 0xfffffffe;
    }
    else {
      iVar2 = strcmp(param_2,(char *)(DAT_0000d46c + 0xd412));
      if (iVar2 != 0) {
        puVar4 = (undefined4 *)__errno();
        *puVar4 = 0x16;
        return 0;
      }
      *(undefined4 *)(iVar1 + 0x30) = 0xffffffff;
    }
    if (param_3 == (void *)0x0) {
      *(undefined4 *)(iVar1 + 0x48) = 0;
    }
    else {
      memcpy((void *)(iVar1 + 0x38),param_3,0x10);
      *(undefined4 *)(iVar1 + 0x48) = 3;
    }
    *(undefined4 *)(param_4 + 4) = 1;
    return 1;
  }
  puVar4 = (undefined4 *)__errno();
  *puVar4 = 2;
  return 0;
}



/* Function: iptc_get_references @ 0000d470 */

bool iptc_get_references(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(DAT_0000d4a4 + 0xd480) = *(undefined4 *)(DAT_0000d4a0 + 0xd47c);
  iVar1 = FUN_0000d340(param_2,param_3);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
  }
  else {
    *param_1 = *(undefined4 *)(iVar1 + 0x2c);
  }
  return iVar1 != 0;
}



/* Function: iptc_zero_counter @ 0000d4a8 */

undefined4 iptc_zero_counter(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  *(undefined4 *)(DAT_0000d514 + 0xd4ba) = *(undefined4 *)(DAT_0000d510 + 0xd4b6);
  iVar1 = FUN_0000d340(param_1,param_3);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
  }
  else {
    piVar4 = *(int **)(iVar1 + 0x54);
    if (piVar4 != (int *)(iVar1 + 0x54)) {
      iVar3 = 1;
      if (param_2 != 1) {
        do {
          piVar4 = (int *)*piVar4;
          if (piVar4 == (int *)(iVar1 + 0x54)) goto LAB_0000d4e0;
          iVar3 = iVar3 + 1;
        } while (param_2 != iVar3);
      }
      if (piVar4 != (int *)0x0) {
        if (piVar4[3] == 1) {
          piVar4[3] = 2;
        }
        *(undefined4 *)(param_3 + 4) = 1;
        return 1;
      }
    }
LAB_0000d4e0:
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 7;
  }
  return 0;
}



/* Function: iptc_read_counter @ 0000d518 */

int * iptc_read_counter(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  *(undefined4 *)(DAT_0000d574 + 0xd528) = *(undefined4 *)(DAT_0000d570 + 0xd524);
  iVar1 = FUN_0000d340(param_1,param_3);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
  }
  else {
    piVar4 = *(int **)(iVar1 + 0x54);
    piVar2 = (int *)(iVar1 + 0x54);
    if (piVar4 != piVar2) {
      iVar1 = 1;
      if (param_2 != 1) {
        do {
          piVar4 = (int *)*piVar4;
          if (piVar4 == piVar2) goto LAB_0000d54e;
          iVar1 = iVar1 + 1;
        } while (param_2 != iVar1);
      }
      piVar2 = piVar4 + 0x22;
      if (piVar4 != (int *)0x0) {
        return piVar2;
      }
    }
LAB_0000d54e:
    puVar3 = (undefined4 *)__errno(piVar2);
    *puVar3 = 7;
  }
  return (int *)0x0;
}



/* Function: iptc_zero_entries @ 0000d578 */

undefined4 iptc_zero_entries(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  *(undefined4 *)(DAT_0000d5d4 + 0xd588) = *(undefined4 *)(DAT_0000d5d0 + 0xd584);
  iVar1 = FUN_0000d340();
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
    uVar2 = 0;
  }
  else {
    if (*(int *)(iVar1 + 0x48) == 1) {
      *(undefined4 *)(iVar1 + 0x48) = 2;
    }
    for (piVar4 = *(int **)(iVar1 + 0x54); piVar4 != (int *)(iVar1 + 0x54); piVar4 = (int *)*piVar4)
    {
      while (piVar4[3] != 1) {
        piVar4 = (int *)*piVar4;
        if (piVar4 == (int *)(iVar1 + 0x54)) goto LAB_0000d5b6;
      }
      piVar4[3] = 2;
    }
LAB_0000d5b6:
    *(undefined4 *)(param_2 + 4) = 1;
    uVar2 = 1;
  }
  return uVar2;
}



/* Function: iptc_flush_entries @ 0000d5d8 */

undefined4 iptc_flush_entries(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  *(undefined4 *)(DAT_0000d628 + 0xd5e8) = *(undefined4 *)(DAT_0000d624 + 0xd5e4);
  iVar4 = FUN_0000d340();
  if (iVar4 == 0) {
    puVar6 = (undefined4 *)__errno();
    *puVar6 = 2;
    uVar5 = 0;
  }
  else {
    piVar3 = (int *)**(int **)(iVar4 + 0x54);
    piVar2 = *(int **)(iVar4 + 0x54);
    while (piVar1 = piVar3, piVar2 != (int *)(iVar4 + 0x54)) {
      FUN_0000cd04(piVar2);
      piVar3 = (int *)*piVar1;
      piVar2 = piVar1;
    }
    *(undefined4 *)(iVar4 + 0x50) = 0;
    *(undefined4 *)(param_2 + 4) = 1;
    uVar5 = 1;
  }
  return uVar5;
}



/* Function: iptc_delete_num_entry @ 0000d62c */

undefined4 iptc_delete_num_entry(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  *(undefined4 *)(DAT_0000d6d4 + 0xd63e) = *(undefined4 *)(DAT_0000d6d0 + 0xd63a);
  iVar1 = FUN_0000d340(param_1,param_3);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
    return 0;
  }
  uVar7 = *(uint *)(iVar1 + 0x50);
  if (uVar7 <= param_2) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 7;
    return 0;
  }
  uVar3 = param_2 + 1;
  if (uVar7 >> 1 < uVar3) {
    piVar6 = *(int **)(iVar1 + 0x58);
    if (piVar6 != (int *)(iVar1 + 0x54)) {
      iVar5 = 1;
      if (uVar7 - param_2 != 1) {
        do {
          piVar6 = (int *)piVar6[1];
          if (piVar6 == (int *)(iVar1 + 0x54)) goto LAB_0000d674;
          iVar5 = iVar5 + 1;
        } while (uVar7 - param_2 != iVar5);
      }
      goto LAB_0000d676;
    }
  }
  else {
    piVar6 = *(int **)(iVar1 + 0x54);
    if (piVar6 != (int *)(iVar1 + 0x54)) {
      uVar4 = 1;
      if (uVar3 != 1) {
        do {
          piVar6 = (int *)*piVar6;
          if (piVar6 == (int *)(iVar1 + 0x54)) goto LAB_0000d674;
          uVar4 = uVar4 + 1;
        } while (uVar3 != uVar4);
      }
      goto LAB_0000d676;
    }
  }
LAB_0000d674:
  piVar6 = (int *)0x0;
LAB_0000d676:
  if (*(int **)(param_3 + 0x14) == piVar6) {
    *(int *)(param_3 + 0x14) = piVar6[1];
    uVar7 = *(uint *)(iVar1 + 0x50);
  }
  *(uint *)(iVar1 + 0x50) = uVar7 - 1;
  FUN_0000cd04(piVar6);
  *(undefined4 *)(param_3 + 4) = 1;
  return 1;
}



/* Function: iptc_builtin @ 0000d6d8 */

bool iptc_builtin(void)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  *(undefined4 *)(DAT_0000d708 + 0xd6e6) = *(undefined4 *)(DAT_0000d704 + 0xd6e2);
  iVar1 = FUN_0000d340();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
    bVar3 = false;
  }
  else {
    bVar3 = *(int *)(iVar1 + 0x28) != 0;
  }
  return bVar3;
}



/* Function: iptc_first_rule @ 0000d70c */

int iptc_first_rule(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  *(undefined4 *)(DAT_0000d748 + 0xd71c) = *(undefined4 *)(DAT_0000d744 + 0xd718);
  iVar1 = FUN_0000d340();
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
    iVar2 = 0;
  }
  else {
    iVar4 = *(int *)(iVar1 + 0x54);
    iVar2 = 0;
    if (iVar4 != iVar1 + 0x54) {
      *(int *)(param_2 + 0x14) = iVar4;
      iVar2 = iVar4 + 0x28;
    }
  }
  return iVar2;
}



/* Function: iptc_is_chain @ 0000d74c */

bool iptc_is_chain(void)

{
  int iVar1;
  
  *(undefined4 *)(DAT_0000d768 + 0xd75a) = *(undefined4 *)(DAT_0000d764 + 0xd756);
  iVar1 = FUN_0000d340();
  return iVar1 != 0;
}



/* Function: FUN_0000d76c @ 0000d76c */

undefined4 FUN_0000d76c(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int local_20;
  int local_1c [2];
  
  piVar1 = (int *)FUN_0000d244(param_1 + 2,0,local_1c,param_2,0);
  piVar3 = (int *)param_1[1];
  iVar4 = *param_1;
  uVar2 = 0;
  *(int **)(iVar4 + 4) = piVar3;
  *piVar3 = iVar4;
  *param_1 = DAT_0000d7cc;
  param_1[1] = DAT_0000d7d0;
  if (param_1 == piVar1) {
    FUN_0000d244(iVar4 + 8,0,&local_20,param_2,0);
    if (local_1c[0] == local_20) {
      uVar2 = 0;
      *(int *)(local_1c[0] * 4 + *(int *)(param_2 + 0x1c)) = iVar4;
    }
    else {
      uVar2 = FUN_0000ccdc(param_2);
    }
  }
  return uVar2;
}



/* Function: iptc_delete_chain @ 0000d7d4 */

undefined4 iptc_delete_chain(undefined4 param_1,int param_2)

{
  int *__ptr;
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int local_14;
  
  *(undefined4 *)(DAT_0000d884 + 0xd7e4) = *(undefined4 *)(DAT_0000d880 + 0xd7e0);
  __ptr = (int *)FUN_0000d340();
  if (__ptr == (int *)0x0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
    uVar2 = 0;
  }
  else {
    iVar1 = iptc_builtin(param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = iptc_get_references(&local_14,param_1,param_2);
      uVar2 = 0;
      if (iVar1 != 0) {
        if (local_14 == 0) {
          if (__ptr[0x14] == 0) {
            if (__ptr == *(int **)(param_2 + 0x10)) {
              if (*__ptr == param_2 + 8) {
                *(undefined4 *)(param_2 + 0x10) = 0;
              }
              else {
                *(int *)(param_2 + 0x10) = *__ptr;
              }
            }
            *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
            FUN_0000d76c(__ptr,param_2);
            free(__ptr);
            *(undefined4 *)(param_2 + 4) = 1;
            uVar2 = 1;
          }
          else {
            puVar3 = (undefined4 *)__errno(0);
            *puVar3 = 0x27;
            uVar2 = 0;
          }
        }
        else {
          puVar3 = (undefined4 *)__errno(0);
          *puVar3 = 0x1f;
          uVar2 = 0;
        }
      }
    }
    else {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0x16;
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* Function: FUN_0000d888 @ 0000d888 */

void FUN_0000d888(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int local_24 [2];
  
  piVar3 = param_2 + 2;
  local_24[0] = 1;
  iVar1 = FUN_0000d244(piVar3,0,local_24,param_1,0);
  if (local_24[0] == 0) {
    piVar4 = *(int **)(param_1 + 0x1c);
    iVar2 = strcmp((char *)piVar3,(char *)(*piVar4 + 8));
    if (0 < iVar2) goto LAB_0000d8ca;
    *piVar4 = (int)param_2;
    iVar1 = *(int *)(param_1 + 8);
    if (param_1 + 8 != iVar1) goto LAB_0000d8d2;
  }
  else {
LAB_0000d8ca:
    if (param_1 + 8 != iVar1) goto LAB_0000d8d2;
  }
  iVar1 = *(int *)(param_1 + 8);
LAB_0000d8d2:
  if (param_2[10] == 0) {
    piVar5 = *(int **)(iVar1 + 4);
    for (piVar4 = (int *)*piVar5; piVar5 != piVar4; piVar4 = (int *)*piVar4) {
      if ((piVar4[10] == 0) && (iVar1 = strcmp((char *)piVar3,(char *)(piVar4 + 2)), iVar1 < 1)) {
        piVar3 = (int *)piVar4[1];
        iVar1 = *piVar3;
        *(int **)(iVar1 + 4) = param_2;
        *param_2 = iVar1;
        param_2[1] = (int)piVar3;
        *piVar3 = (int)param_2;
        return;
      }
      if ((int *)(param_1 + 8) == piVar4) break;
    }
  }
  piVar3 = *(int **)(param_1 + 0xc);
  *(int **)(param_1 + 0xc) = param_2;
  *param_2 = param_1 + 8;
  param_2[1] = (int)piVar3;
  *piVar3 = (int)param_2;
  return;
}



/* Function: FUN_0000d938 @ 0000d938 */

void FUN_0000d938(int param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  FUN_0000d1f4(param_1,*param_4);
  param_2[0x18] = param_3;
  param_2[0x17] = *param_4;
  if (((param_2[10] == 0) && (iVar1 = strcmp((char *)(param_2 + 2),(char *)(iVar3 + 8)), iVar1 < 1))
     && (*(int *)(iVar3 + 0x28) == 0)) {
    FUN_0000d888(param_1,param_2);
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0xc);
    *(int **)(param_1 + 0xc) = param_2;
    *param_2 = param_1 + 8;
    param_2[1] = (int)piVar2;
    *piVar2 = (int)param_2;
  }
  *(int **)(param_1 + 0x10) = param_2;
  return;
}



/* Function: FUN_0000d994 @ 0000d994 */

undefined * FUN_0000d994(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == -4) {
    puVar1 = (undefined *)(DAT_0000d9f0 + 0xd9d4);
  }
  else if (param_1 < -3) {
    if (param_1 != -5) {
LAB_0000d9b6:
      fprintf((FILE *)(*(int *)(DAT_0000d9dc + 0xd99e + DAT_0000d9e4) + 0xa8),
              (char *)(DAT_0000d9e8 + 0xd9c0),param_1);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    puVar1 = &UNK_0000d9da + DAT_0000d9f4;
  }
  else if (param_1 == -2) {
    puVar1 = (undefined *)(DAT_0000d9ec + 0xd9ce);
  }
  else {
    if (param_1 != -1) goto LAB_0000d9b6;
    puVar1 = (undefined *)(DAT_0000d9e0 + 0xd9b2);
  }
  return puVar1;
}



/* Function: iptc_get_policy @ 0000d9f8 */

undefined4 iptc_get_policy(undefined4 param_1,void *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(DAT_0000da40 + 0xda08) = *(undefined4 *)(DAT_0000da3c + 0xda04);
  iVar1 = FUN_0000d340(param_1,param_3);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (*(int *)(iVar1 + 0x28) != 0) {
      memcpy(param_2,(void *)(iVar1 + 0x38),0x10);
      uVar2 = FUN_0000d994(*(undefined4 *)(iVar1 + 0x30));
    }
  }
  return uVar2;
}



/* Function: iptc_get_target @ 0000da44 */

int iptc_get_target(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(DAT_0000da94 + 0xda54) = *(undefined4 *)(DAT_0000da90 + 0xda50);
  iVar2 = *(int *)(param_1 + -0xc);
  if (iVar2 == 1) {
    iVar1 = param_1 + (uint)*(ushort *)(param_1 + 0x58) + 2;
  }
  else if (iVar2 == 0) {
    iVar1 = FUN_0000d994(*(undefined4 *)(param_1 + (uint)*(ushort *)(param_1 + 0x58) + 0x20));
  }
  else if (iVar2 == 2) {
    iVar1 = DAT_0000da98 + 0xda84;
  }
  else {
    iVar1 = 0;
    if (iVar2 == 3) {
      iVar1 = *(int *)(param_1 + -8) + 8;
    }
  }
  return iVar1;
}



/* Function: FUN_0000da9c @ 0000da9c */

undefined4 FUN_0000da9c(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  size_t sVar3;
  int iVar4;
  char *__s1;
  
  iVar4 = param_2 + 0x28 + (uint)*(ushort *)(param_2 + 0x80);
  __s1 = (char *)(iVar4 + 2);
  if (*(char *)(iVar4 + 2) == '\0') {
    *(undefined4 *)(param_2 + 0x1c) = 2;
    uVar1 = 1;
  }
  else {
    iVar4 = strcmp(__s1,(char *)(DAT_0000db74 + 0xdabc));
    if (iVar4 == 0) {
      uVar1 = FUN_0000cd38(param_2,0xfffffffe);
    }
    else {
      iVar4 = strcmp(__s1,(char *)(DAT_0000db78 + 0xdaca));
      if (iVar4 == 0) {
        uVar1 = FUN_0000cd38(param_2,0xffffffff);
      }
      else {
        iVar4 = strcmp(__s1,(char *)(DAT_0000db7c + 0xdad8));
        if (iVar4 == 0) {
          uVar1 = FUN_0000cd38(param_2,0xfffffffc);
        }
        else {
          iVar4 = strcmp(__s1,(char *)(DAT_0000db80 + 0xdae6));
          if (iVar4 == 0) {
            uVar1 = FUN_0000cd38(param_2,0xfffffffb);
          }
          else {
            iVar4 = iptc_builtin(__s1,param_1);
            if (iVar4 == 0) {
              iVar4 = FUN_0000d340(__s1,param_1);
              if (iVar4 == 0) {
                sVar3 = strlen(__s1);
                memset(__s1 + sVar3,0,0x1d - sVar3);
                *(undefined4 *)(param_2 + 0x1c) = 1;
                uVar1 = 1;
                *(undefined4 *)(param_1 + 4) = 1;
              }
              else {
                *(int *)(param_2 + 0x20) = iVar4;
                *(undefined4 *)(param_2 + 0x1c) = 3;
                *(int *)(iVar4 + 0x2c) = *(int *)(iVar4 + 0x2c) + 1;
                uVar1 = 1;
              }
            }
            else {
              puVar2 = (undefined4 *)__errno();
              *puVar2 = 0x16;
              uVar1 = 0;
            }
          }
        }
      }
    }
  }
  return uVar1;
}



/* Function: iptc_delete_entry @ 0000db84 */

undefined4 iptc_delete_entry(undefined4 param_1,void *param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  void *__ptr;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  void *__dest;
  void *pvVar6;
  ushort *puVar7;
  int *piVar8;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  bool bVar15;
  uint local_48;
  int local_34;
  
  iVar14 = DAT_0000deb8 + 0xdb9a;
  *(undefined4 *)(DAT_0000dec0 + 0xdba4) = *(undefined4 *)(iVar14 + DAT_0000debc);
  iVar2 = FUN_0000d340(param_1,param_4);
  if (iVar2 != 0) {
    __ptr = (void *)FUN_0000ccac(iVar2,*(undefined2 *)((int)param_2 + 0x5a));
    if (__ptr == (void *)0x0) {
      puVar4 = (undefined4 *)__errno();
      *puVar4 = 0xc;
      return 0;
    }
    __dest = (void *)((int)__ptr + 0x28);
    memcpy(__dest,param_2,(uint)*(ushort *)((int)param_2 + 0x5a));
    *(undefined4 *)((int)__ptr + 0xc) = 0;
    iVar3 = FUN_0000da9c(param_4,__ptr);
    if (iVar3 == 0) {
      free(__ptr);
      return 0;
    }
    if ((*(int *)((int)__ptr + 0x1c) == 3) && (iVar3 = *(int *)((int)__ptr + 0x20), iVar3 != 0)) {
      *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + -1;
    }
    piVar13 = *(int **)(iVar2 + 0x54);
    if (piVar13 != (int *)(iVar2 + 0x54)) {
      iVar3 = *(int *)((int)__ptr + 0x28);
      do {
        if ((((piVar13[10] == iVar3) && (*(int *)((int)__ptr + 0x2c) == piVar13[0xb])) &&
            (*(int *)((int)__ptr + 0x30) == piVar13[0xc])) &&
           ((*(int *)((int)__ptr + 0x34) == piVar13[0xd] &&
            (*(int *)((int)__ptr + 0x78) == piVar13[0x1e])))) {
          iVar5 = 0;
          pvVar6 = __dest;
          piVar8 = piVar13 + 10;
          do {
            bVar1 = *(byte *)(piVar8 + 0xc);
            if (((bVar1 != *(byte *)((int)pvVar6 + 0x30)) ||
                ((*(byte *)((int)pvVar6 + 0x10) & bVar1) != (bVar1 & *(byte *)(piVar8 + 4)))) ||
               ((bVar1 = *(byte *)(piVar8 + 0x10), bVar1 != *(byte *)((int)pvVar6 + 0x40) ||
                ((*(byte *)((int)pvVar6 + 0x20) & bVar1) != (bVar1 & *(byte *)(piVar8 + 8))))))
            goto LAB_0000dc16;
            iVar5 = iVar5 + 1;
            pvVar6 = (void *)((int)pvVar6 + 1);
            piVar8 = (int *)((int)piVar8 + 1);
          } while (iVar5 != 0x10);
          if (*(int *)((int)__ptr + 0x80) == piVar13[0x20]) {
            local_34 = param_3 + 0x70;
            for (local_48 = 0x70; local_48 < *(ushort *)((int)__ptr + 0x80);
                local_48 = local_48 + uVar10) {
              puVar7 = (ushort *)((int)__dest + local_48);
              puVar9 = (ushort *)((int)piVar13 + (int)puVar7 + (0x98 - ((int)__ptr + 0x98)));
              uVar10 = (uint)*puVar7;
              if ((*puVar9 != uVar10) ||
                 (iVar5 = strcmp((char *)(puVar7 + 1),(char *)(puVar9 + 1)), iVar5 != 0))
              goto LAB_0000dc16;
              for (uVar11 = 0; uVar11 < uVar10 - 0x20; uVar11 = uVar11 + 1) {
                if (((*(byte *)((int)puVar9 + uVar11 + 0x20) ^
                     *(byte *)((int)puVar7 + uVar11 + 0x20)) & *(byte *)(local_34 + uVar11 + 0x20))
                    != 0) goto LAB_0000dc16;
              }
              local_34 = uVar11 + local_34 + 0x20;
            }
            if (((byte *)(local_34 + 0x20) != (byte *)0x0) &&
               (iVar5 = *(int *)((int)__ptr + 0x1c), iVar5 == piVar13[7])) {
              puVar7 = (ushort *)((int)__dest + (uint)*(ushort *)((int)__ptr + 0x80));
              puVar9 = (ushort *)((int)(piVar13 + 10) + (uint)*(ushort *)(piVar13 + 0x20));
              if (iVar5 == 1) {
                uVar10 = (uint)*puVar9;
                if ((uVar10 == *puVar7) &&
                   (iVar5 = strcmp((char *)(puVar7 + 1),(char *)(puVar9 + 1)), iVar5 == 0)) {
                  if (uVar10 == 0x20) goto LAB_0000ddd4;
                  bVar1 = *(byte *)(local_34 + 0x20) & ((byte)puVar7[0x10] ^ (byte)puVar9[0x10]);
                  uVar11 = 0;
                  while (bVar1 == 0) {
                    uVar12 = uVar11 + 1;
                    if (uVar10 - 0x20 <= uVar12) goto LAB_0000ddd4;
                    bVar1 = (*(byte *)((int)puVar9 + uVar11 + 0x21) ^
                            *(byte *)((int)puVar7 + uVar11 + 0x21)) &
                            *(byte *)(local_34 + uVar12 + 0x20);
                    uVar11 = uVar12;
                  }
                }
              }
              else {
                if (iVar5 == 0) {
                  bVar15 = *(int *)(puVar7 + 0x10) == *(int *)(puVar9 + 0x10);
                }
                else {
                  if (iVar5 == 2) goto LAB_0000ddd4;
                  if (iVar5 != 3) {
                    fprintf((FILE *)(*(int *)(iVar14 + DAT_0000dec4) + 0xa8),
                            (char *)(DAT_0000dec8 + 0xde0c));
                    /* WARNING: Subroutine does not return */
                    abort();
                  }
                  bVar15 = *(int *)((int)__ptr + 0x20) == piVar13[8];
                }
                if (bVar15) {
LAB_0000ddd4:
                  if (*(int **)(param_4 + 0x14) == piVar13) {
                    *(int *)(param_4 + 0x14) = piVar13[1];
                  }
                  *(int *)(iVar2 + 0x50) = *(int *)(iVar2 + 0x50) + -1;
                  FUN_0000cd04(piVar13);
                  *(undefined4 *)(param_4 + 4) = 1;
                  free(__ptr);
                  return 1;
                }
              }
            }
          }
        }
LAB_0000dc16:
        piVar13 = (int *)*piVar13;
      } while (piVar13 != (int *)(iVar2 + 0x54));
    }
    free(__ptr);
  }
  puVar4 = (undefined4 *)__errno();
  *puVar4 = 2;
  return 0;
}



/* Function: iptc_append_entry @ 0000decc */

undefined4 iptc_append_entry(undefined4 param_1,void *param_2,int param_3)

{
  int iVar1;
  int *__ptr;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(DAT_0000df60 + 0xdee2) = *(undefined4 *)(DAT_0000df5c + 0xdede);
  iVar1 = FUN_0000d340(param_1,param_3);
  if (iVar1 == 0) {
    puVar4 = (undefined4 *)__errno();
    *puVar4 = 2;
    uVar3 = 0;
  }
  else {
    __ptr = (int *)FUN_0000ccac(iVar1,*(undefined2 *)((int)param_2 + 0x5a));
    if (__ptr == (int *)0x0) {
      puVar4 = (undefined4 *)__errno();
      *puVar4 = 0xc;
      uVar3 = 0;
    }
    else {
      memcpy(__ptr + 10,param_2,(uint)*(ushort *)((int)param_2 + 0x5a));
      __ptr[3] = 3;
      iVar2 = FUN_0000da9c(param_3,__ptr);
      if (iVar2 == 0) {
        free(__ptr);
        uVar3 = 0;
      }
      else {
        puVar4 = *(undefined4 **)(iVar1 + 0x58);
        *(int **)(iVar1 + 0x58) = __ptr;
        *__ptr = iVar1 + 0x54;
        __ptr[1] = (int)puVar4;
        *puVar4 = __ptr;
        uVar3 = 1;
        *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) + 1;
        *(undefined4 *)(param_3 + 4) = 1;
      }
    }
  }
  return uVar3;
}



/* Function: iptc_replace_entry @ 0000df64 */

undefined4 iptc_replace_entry(undefined4 param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  int *__ptr;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  *(undefined4 *)(DAT_0000e050 + 0xdf7a) = *(undefined4 *)(DAT_0000e04c + 0xdf76);
  iVar1 = FUN_0000d340(param_1,param_4);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
    return 0;
  }
  uVar5 = *(uint *)(iVar1 + 0x50);
  if (uVar5 <= param_3) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 7;
    return 0;
  }
  uVar4 = param_3 + 1;
  if (uVar5 >> 1 < uVar4) {
    piVar7 = *(int **)(iVar1 + 0x58);
    if (piVar7 != (int *)(iVar1 + 0x54)) {
      iVar6 = 1;
      if (uVar5 - param_3 != 1) {
        do {
          piVar7 = (int *)piVar7[1];
          if (piVar7 == (int *)(iVar1 + 0x54)) goto LAB_0000dfb2;
          iVar6 = iVar6 + 1;
        } while (uVar5 - param_3 != iVar6);
      }
      goto LAB_0000dfb4;
    }
  }
  else {
    piVar7 = *(int **)(iVar1 + 0x54);
    if (piVar7 != (int *)(iVar1 + 0x54)) {
      uVar5 = 1;
      if (uVar4 != 1) {
        do {
          piVar7 = (int *)*piVar7;
          if (piVar7 == (int *)(iVar1 + 0x54)) goto LAB_0000dfb2;
          uVar5 = uVar5 + 1;
        } while (uVar4 != uVar5);
      }
      goto LAB_0000dfb4;
    }
  }
LAB_0000dfb2:
  piVar7 = (int *)0x0;
LAB_0000dfb4:
  __ptr = (int *)FUN_0000ccac(iVar1,*(undefined2 *)((int)param_2 + 0x5a));
  if (__ptr == (int *)0x0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0xc;
    uVar2 = 0;
  }
  else {
    memcpy(__ptr + 10,param_2,(uint)*(ushort *)((int)param_2 + 0x5a));
    __ptr[3] = 3;
    iVar1 = FUN_0000da9c(param_4,__ptr);
    if (iVar1 == 0) {
      free(__ptr);
      uVar2 = 0;
    }
    else {
      iVar1 = *piVar7;
      *(int **)(iVar1 + 4) = __ptr;
      *__ptr = iVar1;
      __ptr[1] = (int)piVar7;
      *piVar7 = (int)__ptr;
      FUN_0000cd04(piVar7);
      *(undefined4 *)(param_4 + 4) = 1;
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* Function: iptc_insert_entry @ 0000e054 */

undefined4 iptc_insert_entry(undefined4 param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  
  *(undefined4 *)(DAT_0000e158 + 0xe06c) = *(undefined4 *)(DAT_0000e154 + 0xe068);
  iVar1 = FUN_0000d340(param_1,param_4);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
    return 0;
  }
  uVar6 = *(uint *)(iVar1 + 0x50);
  if (uVar6 < param_3) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 7;
    return 0;
  }
  piVar8 = (int *)(iVar1 + 0x54);
  if (uVar6 != param_3) {
    uVar5 = param_3 + 1;
    if (uVar6 >> 1 < uVar5) {
      piVar8 = *(int **)(iVar1 + 0x58);
      if (piVar8 != (int *)(iVar1 + 0x54)) {
        iVar3 = 1;
        if (uVar6 - param_3 != 1) {
          do {
            piVar8 = (int *)piVar8[1];
            if (piVar8 == (int *)(iVar1 + 0x54)) {
              piVar8 = (int *)0x0;
              break;
            }
            iVar3 = iVar3 + 1;
          } while (uVar6 - param_3 != iVar3);
        }
        goto LAB_0000e0ae;
      }
    }
    else {
      piVar8 = *(int **)(iVar1 + 0x54);
      if (piVar8 != (int *)(iVar1 + 0x54)) {
        uVar6 = 1;
        if (uVar5 != 1) {
          do {
            piVar8 = (int *)*piVar8;
            if (piVar8 == (int *)(iVar1 + 0x54)) goto LAB_0000e0ac;
            uVar6 = uVar6 + 1;
          } while (uVar5 != uVar6);
        }
        goto LAB_0000e0ae;
      }
    }
LAB_0000e0ac:
    piVar8 = (int *)0x0;
  }
LAB_0000e0ae:
  puVar2 = (undefined4 *)FUN_0000ccac(iVar1,*(undefined2 *)((int)param_2 + 0x5a));
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0xc;
    uVar4 = 0;
  }
  else {
    memcpy(puVar2 + 10,param_2,(uint)*(ushort *)((int)param_2 + 0x5a));
    puVar2[3] = 3;
    iVar3 = FUN_0000da9c(param_4,puVar2);
    if (iVar3 == 0) {
      free(puVar2);
      uVar4 = 0;
    }
    else {
      puVar7 = (undefined4 *)piVar8[1];
      piVar8[1] = (int)puVar2;
      *puVar2 = piVar8;
      puVar2[1] = puVar7;
      *puVar7 = puVar2;
      uVar4 = 1;
      *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) + 1;
      *(undefined4 *)(param_4 + 4) = 1;
    }
  }
  return uVar4;
}



/* Function: iptc_rename_chain @ 0000e15c */

undefined4 iptc_rename_chain(undefined4 param_1,char *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  uVar4 = *(undefined4 *)(DAT_0000e220 + 0xe16a);
  puVar5 = (undefined4 *)(DAT_0000e224 + 0xe16e);
  *puVar5 = uVar4;
  iVar1 = FUN_0000d340(param_2,param_3,uVar4,puVar5,param_4);
  if ((((iVar1 == 0) && (iVar1 = strcmp(param_2,(char *)(DAT_0000e228 + 0xe190)), iVar1 != 0)) &&
      (iVar1 = strcmp(param_2,(char *)(DAT_0000e22c + 0xe19e)), iVar1 != 0)) &&
     ((iVar1 = strcmp(param_2,(char *)(DAT_0000e230 + 0xe1ac)), iVar1 != 0 &&
      (iVar1 = strcmp(param_2,(char *)(DAT_0000e234 + 0xe1ba)), iVar1 != 0)))) {
    iVar1 = FUN_0000d340(param_1,param_3);
    if ((iVar1 == 0) || (iVar2 = iptc_builtin(param_1,param_3), iVar2 != 0)) {
      puVar5 = (undefined4 *)__errno();
      *puVar5 = 2;
      uVar4 = 0;
    }
    else {
      sVar3 = strlen(param_2);
      if (sVar3 + 1 < 0x21) {
        FUN_0000d76c(iVar1,param_3);
        strncpy((char *)(iVar1 + 8),param_2,0x20);
        FUN_0000d888(param_3,iVar1);
        *(undefined4 *)(param_3 + 4) = 1;
        uVar4 = 1;
      }
      else {
        puVar5 = (undefined4 *)__errno();
        *puVar5 = 0x16;
        uVar4 = 0;
      }
    }
  }
  else {
    puVar5 = (undefined4 *)__errno();
    *puVar5 = 0x11;
    uVar4 = 0;
  }
  return uVar4;
}



/* Function: FUN_0000e238 @ 0000e238 */

void * FUN_0000e238(char *param_1,undefined4 param_2)

{
  void *__s;
  
  __s = malloc(0x70);
  if (__s != (void *)0x0) {
    memset(__s,0,0x70);
    strncpy((char *)((int)__s + 8),param_1,0x20);
    *(undefined4 *)((int)__s + 0x28) = param_2;
    *(int *)((int)__s + 0x54) = (int)__s + 0x54;
    *(int *)((int)__s + 0x58) = (int)__s + 0x54;
  }
  return __s;
}



/* Function: iptc_create_chain @ 0000e26c */

undefined4 iptc_create_chain(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  size_t sVar5;
  
  iVar1 = DAT_0000e330;
  *(undefined4 *)(DAT_0000e330 + 0xe27c) = *(undefined4 *)(DAT_0000e32c + 0xe278);
  iVar2 = FUN_0000d340();
  if ((((iVar2 == 0) && (iVar2 = strcmp(param_1,(char *)(DAT_0000e334 + 0xe29a)), iVar2 != 0)) &&
      (iVar2 = strcmp(param_1,(char *)(DAT_0000e338 + 0xe2a8)), iVar2 != 0)) &&
     ((iVar2 = strcmp(param_1,(char *)(DAT_0000e33c + 0xe2b6)), iVar2 != 0 &&
      (iVar2 = strcmp(param_1,(char *)(DAT_0000e340 + 0xe2c4)), iVar2 != 0)))) {
    sVar5 = strlen(param_1);
    if (sVar5 + 1 < 0x21) {
      iVar2 = FUN_0000e238(param_1,0);
      *(int *)(iVar1 + 0xe280) = iVar2;
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)__errno(0,0);
        *puVar3 = 0xc;
        uVar4 = 0;
      }
      else {
        *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;
        FUN_0000d888(param_2);
        if (DAT_0000e344 < *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x20) * -0x28) {
          FUN_0000ccdc(param_2);
        }
        *(undefined4 *)(param_2 + 4) = 1;
        uVar4 = 1;
      }
    }
    else {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0x16;
      uVar4 = 0;
    }
  }
  else {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0x11;
    uVar4 = 0;
  }
  return uVar4;
}



/* Function: dump_entries @ 0000e348 */

void dump_entries(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  undefined *puVar15;
  uint *puVar16;
  char *__s2;
  uint uVar17;
  char *pcVar18;
  uint uVar19;
  uint uVar20;
  uint *puVar21;
  char *__format;
  uint uVar22;
  ushort *puVar23;
  char *pcVar24;
  char *__format_00;
  char *local_60;
  
  iVar13 = DAT_0000e678 + 0xe35e;
  *(undefined4 *)(DAT_0000e680 + 0xe366) = *(undefined4 *)(iVar13 + DAT_0000e67c);
  printf((char *)(DAT_0000e684 + 0xe376),DAT_0000e688 + 0xe378,
         *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x20));
  printf((char *)(DAT_0000e68c + 0xe386),param_1 + 0x28);
  printf((char *)(DAT_0000e690 + 0xe39c),*(undefined4 *)(param_1 + 0x4c),
         *(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
         *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c));
  uVar19 = *(uint *)(param_1 + 0x6c);
  uVar20 = *(uint *)(param_1 + 0x70);
  printf((char *)(DAT_0000e694 + 0xe3b2),*(undefined4 *)(param_1 + 0x60),
         *(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x68),uVar19,uVar20);
  iVar10 = DAT_0000e6c0;
  iVar9 = DAT_0000e6bc;
  iVar8 = DAT_0000e6b8;
  iVar7 = DAT_0000e6b4;
  iVar6 = DAT_0000e6b0;
  iVar5 = DAT_0000e6ac;
  iVar4 = DAT_0000e6a8;
  iVar3 = DAT_0000e6a4;
  iVar2 = DAT_0000e6a0;
  iVar1 = DAT_0000e698;
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0x20) != 0) {
    local_60 = (char *)0x0;
    puVar16 = (uint *)(*(int *)(param_1 + 0x7c) + 0x28);
    __format = (char *)(DAT_0000e69c + 0xe3f6);
    __format_00 = (char *)(DAT_0000e6c4 + 0xe406);
    __s2 = (char *)(DAT_0000e6c8 + 0xe408);
    iVar14 = 0;
    pcVar18 = __s2;
    puVar21 = puVar16;
    while( true ) {
      printf(__format,iVar14,(int)puVar21 - (int)puVar16,pcVar18,uVar19,uVar20);
      uVar19 = *puVar21;
      uVar20 = puVar21[2];
      printf((char *)(iVar1 + 0xe45e),uVar19 & 0xff,(uVar19 & 0xff00) >> 8,
             (uVar19 & 0xff0000) >> 0x10,uVar19 >> 0x18,uVar20 & 0xff,(uVar20 & 0xff00) >> 8,
             (uVar20 & 0xff0000) >> 0x10,uVar20 >> 0x18);
      uVar19 = puVar21[1];
      uVar20 = puVar21[3];
      printf((char *)(iVar3 + 0xe4c4),uVar19 & 0xff,(uVar19 & 0xff00) >> 8,
             (uVar19 & 0xff0000) >> 0x10,uVar19 >> 0x18,uVar20 & 0xff,(uVar20 & 0xff00) >> 8,
             (uVar20 & 0xff0000) >> 0x10,uVar20 >> 0x18);
      printf((char *)(iVar2 + 0xe4f2),puVar21 + 4);
      iVar14 = 0;
      do {
        iVar11 = 0x58;
        if (*(char *)((int)puVar21 + iVar14 + 0x30) == '\0') {
          iVar11 = 0x2e;
        }
        iVar14 = iVar14 + 1;
        putchar(iVar11);
      } while (iVar14 != 0x10);
      printf((char *)(iVar5 + 0xe518),puVar21 + 8);
      iVar14 = 0;
      do {
        iVar11 = 0x58;
        if (*(char *)((int)puVar21 + iVar14 + 0x40) == '\0') {
          iVar11 = 0x2e;
        }
        iVar14 = iVar14 + 1;
        putchar(iVar11);
      } while (iVar14 != 0x10);
      printf((char *)(iVar4 + 0xe53e),(uint)(ushort)puVar21[0x14]);
      printf((char *)(iVar7 + 0xe54a),(uint)*(byte *)((int)puVar21 + 0x52));
      printf((char *)(iVar6 + 0xe556),(uint)*(byte *)((int)puVar21 + 0x53));
      uVar19 = puVar21[0x1a];
      uVar20 = puVar21[0x1b];
      printf((char *)(iVar9 + 0xe56a));
      printf((char *)(iVar8 + 0xe576),puVar21[0x15]);
      uVar17 = (uint)(ushort)puVar21[0x16];
      if (0x70 < uVar17) {
        uVar22 = 0x70;
        do {
          printf(__format_00,(ushort *)((int)puVar21 + uVar22) + 1);
          uVar22 = uVar22 + *(ushort *)((int)puVar21 + uVar22);
          uVar17 = (uint)(ushort)puVar21[0x16];
        } while (uVar22 < uVar17);
      }
      puVar23 = (ushort *)((int)puVar21 + uVar17);
      printf((char *)(iVar10 + 0xe5a4),puVar23 + 1,(uint)*puVar23,uVar17,uVar19,uVar20);
      if ((char)puVar23[1] == '\0') {
        iVar14 = *(int *)(puVar23 + 0x10);
        if (iVar14 < 0) {
          if (iVar14 + 2 == 0) {
            puVar15 = (undefined *)(DAT_0000e6e8 + 0xe666);
            iVar11 = 0;
          }
          else {
            iVar11 = iVar14 + 1;
            if (iVar11 == 0) {
              puVar15 = (undefined *)(DAT_0000e6e4 + 0xe660);
            }
            else if (iVar14 == -4) {
              puVar15 = (undefined *)(DAT_0000e6ec + 0xe670);
            }
            else if (iVar14 == -5) {
              puVar15 = &UNK_0000e676 + DAT_0000e6f0;
            }
            else {
              puVar15 = (undefined *)(DAT_0000e6cc + 0xe5cc);
            }
          }
          printf((char *)(DAT_0000e6d0 + 0xe5d0),puVar15,iVar14 + 2,iVar11,uVar19,uVar20);
        }
        else {
          printf((char *)(DAT_0000e6e0 + 0xe648));
        }
      }
      else {
        iVar14 = strcmp((char *)(puVar23 + 1),__s2);
        if (iVar14 == 0) {
          printf((char *)(DAT_0000e6dc + 0xe63e),puVar23 + 0x10);
        }
      }
      putchar(10);
      local_60 = local_60 + *(ushort *)((int)puVar21 + 0x5a);
      pcVar24 = *(char **)(*(int *)(param_1 + 0x7c) + 0x20);
      if (pcVar24 <= local_60) break;
      puVar16 = (uint *)(*(int *)(param_1 + 0x7c) + 0x28);
      puVar21 = (uint *)((int)puVar16 + (int)local_60);
      if (puVar16 == puVar21) {
        iVar14 = 0;
        pcVar18 = param_1;
      }
      else {
        iVar14 = 0;
        pcVar18 = (char *)0x0;
        puVar12 = puVar16;
        do {
          pcVar18 = pcVar18 + *(ushort *)((int)puVar12 + 0x5a);
          if (pcVar24 <= pcVar18) {
            fprintf((FILE *)(*(int *)(iVar13 + DAT_0000e6d4) + 0xa8),(char *)(DAT_0000e6d8 + 0xe620)
                    ,(int)puVar21 - (int)puVar16);
                    /* WARNING: Subroutine does not return */
            abort();
          }
          puVar12 = (uint *)((int)puVar16 + (int)pcVar18);
          iVar14 = iVar14 + 1;
        } while (puVar21 != puVar12);
      }
    }
  }
  return;
}



/* Function: iptc_free @ 0000e6f4 */

void iptc_free(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *__ptr;
  int *piVar3;
  int *piVar4;
  
  *(undefined4 *)(DAT_0000e774 + 0xe70a) = *(undefined4 *)(DAT_0000e770 + 0xe706);
  close(*param_1);
  piVar3 = *(int **)param_1[2];
  __ptr = (int *)param_1[2];
  while (piVar1 = piVar3, __ptr != param_1 + 2) {
    piVar4 = *(int **)__ptr[0x15];
    piVar3 = (int *)__ptr[0x15];
    while (piVar2 = piVar4, piVar3 != __ptr + 0x15) {
      free(piVar3);
      piVar4 = (int *)*piVar2;
      piVar3 = piVar2;
    }
    free(__ptr);
    piVar3 = (int *)*piVar1;
    __ptr = piVar1;
  }
  param_1[8] = 0;
  free((void *)param_1[7]);
  free((void *)param_1[0x1f]);
  free(param_1);
  return;
}



/* Function: iptc_init @ 0000e778 */

void iptc_init(char *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  int __fd;
  int iVar6;
  char *__dest;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  char *__s2;
  uint uVar13;
  short *psVar14;
  int *piVar15;
  int *piVar16;
  void *__src;
  uint uVar17;
  int *piVar18;
  int *local_a4;
  undefined1 auStack_90 [4];
  int local_8c;
  socklen_t local_88;
  socklen_t local_84;
  char acStack_80 [80];
  int local_30;
  int local_2c;
  
  iVar3 = DAT_0000eabc;
  iVar11 = DAT_0000eab8 + 0xe78e;
  local_2c = **(int **)(iVar11 + DAT_0000eabc);
  *(undefined4 *)(DAT_0000eac4 + 0xe7a2) = *(undefined4 *)(iVar11 + DAT_0000eac0);
  sVar4 = strlen(param_1);
  if (sVar4 < 0x20) {
    __fd = socket(2,3,0xff);
    if (-1 < __fd) {
      __s2 = (char *)(DAT_0000eac8 + 0xe7fe);
      do {
        local_88 = 0x54;
        strcpy(acStack_80,param_1);
        iVar6 = getsockopt(__fd,0,0x40,acStack_80,&local_88);
        iVar7 = local_30;
        if (iVar6 < 0) {
          close(__fd);
          local_a4 = (int *)0x0;
          goto LAB_0000e7b6;
        }
        local_a4 = malloc(0x80);
        if (local_a4 == (int *)0x0) {
          puVar5 = (undefined4 *)__errno();
          *puVar5 = 0xc;
LAB_0000eaec:
          close(__fd);
          local_a4 = (int *)0x0;
          goto LAB_0000e7b6;
        }
        memset(local_a4,0,0x80);
        piVar10 = local_a4 + 2;
        local_a4[2] = (int)piVar10;
        local_a4[3] = (int)piVar10;
        strcpy((char *)(local_a4 + 10),acStack_80);
        __dest = malloc(iVar7 + 0x28);
        local_a4[0x1f] = (int)__dest;
        if (__dest == (char *)0x0) {
          free(local_a4);
          goto LAB_0000eaec;
        }
        strcpy(__dest,acStack_80);
        *(int *)(local_a4[0x1f] + 0x20) = iVar7;
        *local_a4 = __fd;
        memcpy(local_a4 + 10,acStack_80,0x54);
        *(int *)(local_a4[0x1f] + 0x20) = local_a4[0x1e];
        local_84 = local_a4[0x1e] + 0x28;
        iVar7 = getsockopt(*local_a4,0,0x41,(void *)local_a4[0x1f],&local_84);
        if (-1 < iVar7) {
          local_8c = 0;
          iVar7 = local_a4[0x1f];
          local_a4[9] = 1;
          uVar13 = *(uint *)(iVar7 + 0x20);
          if (uVar13 != 0) {
            uVar17 = 0;
            iVar6 = DAT_0000eacc + 0xe8ba;
            do {
              iVar7 = iVar7 + 0x28;
              __src = (void *)(iVar7 + uVar17);
              uVar1 = *(ushort *)((int)__src + 0x5a);
              iVar12 = (int)__src - iVar7;
              if (uVar13 == iVar12 + (uint)uVar1) {
                FUN_0000d1f4(local_a4,local_8c);
                local_a4[4] = 0;
              }
              else {
                uVar2 = *(ushort *)((int)__src + 0x58);
                iVar8 = strcmp((char *)((int)__src + uVar2 + 2),__s2);
                if (iVar8 == 0) {
                  iVar7 = FUN_0000e238((int)__src + uVar2 + 0x20,0);
                  if (iVar7 == 0) {
LAB_0000eada:
                    puVar5 = (undefined4 *)__errno();
                    *puVar5 = 0xfffffff4;
                    break;
                  }
                  local_a4[6] = local_a4[6] + 1;
                  FUN_0000d938(local_a4,iVar7,iVar12,&local_8c);
                }
                else {
                  piVar18 = local_a4 + 0x13;
                  uVar13 = 0;
                  do {
                    if (((1 << (uVar13 & 0xff) & local_a4[0x12]) != 0) &&
                       (__src == (void *)(iVar7 + *piVar18))) {
                      iVar7 = uVar13 + 1;
                      if (iVar7 != 0) {
                        iVar8 = FUN_0000e238(*(undefined4 *)(uVar13 * 4 + iVar6),iVar7);
                        if (iVar8 == 0) goto LAB_0000eada;
                        *(int *)(iVar8 + 0x28) = iVar7;
                        FUN_0000d938(local_a4,iVar8,iVar12,&local_8c);
                        piVar18 = (int *)FUN_0000ccac(local_a4[4],*(undefined2 *)((int)__src + 0x5a)
                                                     );
                        if (piVar18 != (int *)0x0) goto LAB_0000e91c;
                        goto LAB_0000eaa8;
                      }
                      break;
                    }
                    uVar13 = uVar13 + 1;
                    piVar18 = piVar18 + 1;
                  } while (uVar13 != 5);
                  piVar18 = (int *)FUN_0000ccac(local_a4[4],(uint)uVar1);
                  if (piVar18 == (int *)0x0) {
LAB_0000eaa8:
                    puVar5 = (undefined4 *)__errno();
                    *puVar5 = 0xc;
                    break;
                  }
LAB_0000e91c:
                  piVar18[5] = local_8c;
                  piVar18[6] = iVar12;
                  memcpy(piVar18 + 10,__src,(uint)*(ushort *)((int)__src + 0x5a));
                  piVar18[3] = 1;
                  piVar18[4] = piVar18[5];
                  psVar14 = (short *)((int)__src + (uint)*(ushort *)((int)__src + 0x58));
                  if ((char)psVar14[1] == '\0') {
                    if (*psVar14 != 0x28) {
                      puVar5 = (undefined4 *)__errno();
                      *puVar5 = 0x16;
                      break;
                    }
                    if (*(int *)(psVar14 + 0x10) < 0) {
                      piVar18[7] = 0;
                    }
                    else if (*(int *)(psVar14 + 0x10) ==
                             (uint)*(ushort *)((int)__src + 0x5a) + piVar18[6]) {
                      piVar18[7] = 2;
                    }
                    else {
                      piVar18[7] = 3;
                    }
                  }
                  else {
                    piVar18[7] = 1;
                  }
                  iVar7 = local_a4[4];
                  puVar5 = *(undefined4 **)(iVar7 + 0x58);
                  *(int **)(iVar7 + 0x58) = piVar18;
                  *piVar18 = iVar7 + 0x54;
                  piVar18[1] = (int)puVar5;
                  *puVar5 = piVar18;
                  *(int *)(local_a4[4] + 0x50) = *(int *)(local_a4[4] + 0x50) + 1;
                }
              }
              local_8c = local_8c + 1;
              iVar7 = local_a4[0x1f];
              uVar17 = uVar17 + *(ushort *)((int)__src + 0x5a);
              uVar13 = *(uint *)(iVar7 + 0x20);
            } while (uVar17 < uVar13);
          }
          iVar7 = FUN_0000cc64(local_a4);
          if (-1 < iVar7) {
            FUN_0000cb10(local_a4);
            for (piVar18 = (int *)local_a4[2]; piVar10 != piVar18; piVar18 = (int *)*piVar18) {
              for (piVar16 = (int *)piVar18[0x15]; piVar16 != piVar18 + 0x15;
                  piVar16 = (int *)*piVar16) {
                if (piVar16[7] == 3) {
                  piVar9 = (int *)local_a4[2];
                  uVar13 = *(uint *)((int)piVar16 + *(ushort *)(piVar16 + 0x20) + 0x48);
                  if (piVar10 == piVar9) goto LAB_0000ea04;
                  if (local_a4[9] != 0) {
                    piVar9 = (int *)FUN_0000d244(0,uVar13,auStack_90,local_a4,1);
                  }
                  piVar15 = *(int **)piVar9[1];
                  while( true ) {
                    if ((int *)piVar9[1] == piVar15) goto LAB_0000ea04;
                    if (((uint)piVar15[0x18] <= uVar13) && (uVar13 <= (uint)piVar15[0x1a])) break;
                    piVar15 = (int *)*piVar15;
                  }
                  piVar16[8] = (int)piVar15;
                  piVar15[0xb] = piVar15[0xb] + 1;
                }
              }
            }
            goto LAB_0000e7b6;
          }
        }
LAB_0000ea04:
        iptc_free(local_a4);
        piVar10 = (int *)__errno();
      } while (*piVar10 == 0xb);
    }
    local_a4 = (int *)0x0;
  }
  else {
    puVar5 = (undefined4 *)__errno();
    *puVar5 = 0x16;
    local_a4 = (int *)0x0;
  }
LAB_0000e7b6:
  if (local_2c != **(int **)(iVar11 + iVar3)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_a4);
  }
  return;
}



/* Function: FUN_0000eb14 @ 0000eb14 */

void FUN_0000eb14(void)

{
  FUN_0000ec9c();
  FUN_0000f264();
  FUN_0000f554();
  FUN_0000fa2c();
  FUN_0000ff64();
  FUN_0001021c();
  FUN_000104ec();
  FUN_000108f4();
  FUN_00010d7c();
  FUN_00010fb8();
  FUN_00010ffc();
  FUN_0001128c();
  FUN_000116bc();
  FUN_00011958();
  FUN_00011b7c();
  FUN_00011f00();
  FUN_00012438();
  FUN_0001269c();
  FUN_0001288c();
  FUN_00012c34();
  FUN_00012c68();
  FUN_00012e10();
  FUN_00013140();
  FUN_0001324c();
  FUN_00013710();
  FUN_00013ad4();
  FUN_00013e34();
  FUN_00014688();
  FUN_00014748();
  FUN_000161e0();
  FUN_00016878();
  FUN_00016a7c();
  FUN_00016c08();
  FUN_00016fb4();
  FUN_00017f6c();
  FUN_0001809c();
  FUN_00018810();
  FUN_00018a1c();
  FUN_00018cf8();
  FUN_00018e90();
  FUN_00019200();
  FUN_00019834();
  FUN_0001a140();
  FUN_0001a3fc();
  FUN_0001a670();
  FUN_0001a6a4();
  FUN_0001a8c8();
  FUN_0001b3e0();
  FUN_0001b7e0();
  FUN_0001bb30();
  FUN_0001c5c4();
  FUN_0001c6d8();
  FUN_0001cfb8();
  FUN_0001d4cc();
  FUN_0001d8e4();
  FUN_0001e32c();
  FUN_0001e468();
  FUN_0001e478();
  FUN_0001e4bc();
  FUN_0001e844();
  FUN_0001ebd8();
  FUN_0001f308();
  FUN_0001fa4c();
  FUN_0001fc54();
  FUN_0001fe28();
  FUN_0002082c();
  FUN_00020c2c();
  FUN_00021150();
  FUN_000213d4();
  FUN_000213e4();
  FUN_00021984();
  return;
}



/* Function: FUN_0000ec34 @ 0000ec34 */

void FUN_0000ec34(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint extraout_r2;
  uint uVar3;
  int unaff_r4;
  int unaff_r6;
  undefined8 uVar4;
  
  if ((param_1 & 3) != 0) {
    return;
  }
  uVar1 = (**(code **)(**(int **)(iRam0000ec50 + 0xec46) + 0x14))(2,iRam0000ec54 + 0xec4a);
  uVar3 = extraout_r2;
  do {
    uVar2 = uVar1;
    *(char *)(uVar3 + 0x14) = (char)uVar3;
    unaff_r6 = *(int *)(unaff_r6 + 0x14);
    if ((uVar2 & 3) == 0) {
      (**(code **)(**(int **)(iRam0000ec8c + 0xec72) + 0x14))(2,iRam0000ec90 + 0xec76);
      break;
    }
    uVar1 = uVar2 & 0xc;
    uVar3 = uVar2;
  } while ((uVar2 & 0xc) != 0xc);
  uVar4 = (**(code **)(**(int **)(iRam0000ec94 + 0xec84) + 0x14))(2,iRam0000ec98 + 0xec88);
  *(char *)(unaff_r4 + 0x13) = (char)unaff_r6;
  *(char *)(*(int *)((int)((ulonglong)uVar4 >> 0x20) + 0x14) + 0x13) = (char)unaff_r4;
  FUN_000232e4(DAT_0000ecac + 0xeca6,2,(int)uVar4);
  return;
}



/* Function: FUN_0000ec9c @ 0000ec9c */

void FUN_0000ec9c(void)

{
  FUN_000232e4(DAT_0000ecac + 0xeca6,2);
  return;
}



/* Function: FUN_0000ecb0 @ 0000ecb0 */

void FUN_0000ecb0(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *__format;
  undefined *puVar5;
  
  puVar2 = PTR_DAT_0000ed10 + 0xecce;
  puVar4 = (undefined4 *)(PTR_s_e_does_not_exist__do_you_need_to_00025368_4_0000ed0c + 0xeccc);
  uVar3 = 0;
  __format = PTR_DAT_0000ed08 + 0xecd8;
  puVar5 = PTR_DAT_0000ed14 + 0xecda;
  puVar1 = PTR_DAT_0000ed18 + 0xecd4;
  do {
    while ((param_1 >> (uVar3 & 0xff) & 1U) != 0) {
      printf(__format,puVar1,puVar2);
      puVar2 = (undefined *)*puVar4;
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 1;
      puVar1 = puVar5;
      if (puVar2 == (undefined *)0x0) goto LAB_0000ecfa;
    }
    puVar2 = (undefined *)*puVar4;
    puVar4 = puVar4 + 1;
    uVar3 = uVar3 + 1;
  } while (puVar2 != (undefined *)0x0);
LAB_0000ecfa:
  putchar(0x20);
  return;
}



/* Function: FUN_0000ee08 @ 0000ee08 */

void FUN_0000ee08(undefined4 param_1,int param_2)

{
  int iVar1;
  
  printf((char *)(DAT_0000ee80 + 0xee14));
  if (*(short *)(param_2 + 0x20) != 0) {
    printf((char *)(DAT_0000ee90 + 0xee60));
    if (*(int *)(param_2 + 0x24) << 0x1f < 0) {
      putchar(0x21);
    }
    FUN_0000ecb0(*(undefined2 *)(param_2 + 0x20));
  }
  if (*(short *)(param_2 + 0x22) != 0) {
    printf((char *)(DAT_0000ee8c + 0xee4a));
    if (*(int *)(param_2 + 0x24) << 0x1e < 0) {
      putchar(0x21);
    }
    FUN_0000ecb0(*(undefined2 *)(param_2 + 0x22));
  }
  iVar1 = *(int *)(param_2 + 0x24);
  if (iVar1 << 0x1d < 0) {
    printf((char *)(DAT_0000ee88 + 0xee3e));
    iVar1 = *(int *)(param_2 + 0x24);
  }
  if (iVar1 << 0x1c < 0) {
    printf((char *)(DAT_0000ee84 + 0xee34));
  }
  return;
}



/* Function: FUN_0000eefc @ 0000eefc */

undefined4 FUN_0000eefc(char *param_1,size_t param_2,ushort *param_3)

{
  int iVar1;
  char *__s2;
  uint uVar2;
  int *piVar3;
  
  __s2 = (char *)(DAT_0000ef4c + 0xef12);
  piVar3 = (int *)(DAT_0000ef48 + 0xef10);
  uVar2 = 0;
  do {
    iVar1 = strncasecmp(param_1,__s2,param_2);
    if (iVar1 == 0) {
      *param_3 = (ushort)(1 << (uVar2 & 0xff)) | *param_3;
      return 1;
    }
    __s2 = (char *)*piVar3;
    piVar3 = piVar3 + 1;
    uVar2 = uVar2 + 1;
  } while (__s2 != (char *)0x0);
  return 0;
}



/* Function: FUN_0000ef50 @ 0000ef50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000ef50(char *param_1,int param_2)

{
  undefined *puVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  undefined1 extraout_r2;
  uint *extraout_r3;
  uint uVar5;
  uint *extraout_r3_00;
  uint *unaff_r5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  int unaff_r7;
  undefined *puVar9;
  int iVar10;
  undefined4 unaff_r8;
  int iStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  int iStack_50;
  uint uStack_4c;
  undefined *puStack_48;
  undefined *puStack_44;
  int iStack_40;
  int *piStack_3c;
  int aiStack_34 [2];
  
  while (pcVar2 = strchr(param_1,0x2c), pcVar2 != (char *)0x0) {
    if ((pcVar2 == param_1) ||
       (iVar4 = FUN_0000eefc(param_1,(int)pcVar2 - (int)param_1,param_2), iVar4 == 0)) {
      (**(code **)(**(int **)(PTR_s_TMAP_000271b8_2_0000efbc + 0xef9e) + 0x14))
                (2,PTR_DAT_0000efc0 + 0xefa2,param_1);
      goto LAB_0000efa8;
    }
    param_1 = pcVar2 + 1;
  }
  if (*param_1 != '\0') {
    sVar3 = strlen(param_1);
    iVar4 = FUN_0000eefc(param_1,sVar3,param_2);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
LAB_0000efa8:
  iStack_40 = (**(code **)(**(int **)(PTR_s_k_address___s__0002719c_0xa_0000efc4 + 0xefb2) + 0x14))
                        (2,PTR_DAT_0000efc8 + 0xefb6,param_1);
  *(undefined1 *)(unaff_r7 + 6) = extraout_r2;
  *(int *)(pcVar2 + 0x70) = param_2;
  param_1[6] = (char)param_2;
  *(int *)(param_2 + 0x70) = iStack_40;
  uVar7 = *unaff_r5;
  puVar9 = &DAT_0000efe4 + _UNK_0000f0f0;
  iVar4 = uVar7 + 0x20;
  aiStack_34[0] = iStack_40;
  if (iStack_40 == 0x32) {
    if ((*extraout_r3 & 2) == 0) {
      puVar8 = *(undefined4 **)(puVar9 + _UNK_0000f0f4);
      FUN_00021dc4(*puVar8,aiStack_34,*(undefined4 *)(puVar9 + _UNK_0000f0f8),0);
      FUN_0000ef50(*puVar8,uVar7 + 0x22);
      if (aiStack_34[0] != 0) {
        *(uint *)(uVar7 + 0x24) = *(uint *)(uVar7 + 0x24) | 2;
      }
      *extraout_r3 = *extraout_r3 | 2;
      return 1;
    }
code_r0x0000f0be:
    (**(code **)(**(int **)(puVar9 + _UNK_0000f0fc) + 0x14))(2,PTR_DAT_0000f104 + 0xf0ca);
code_r0x0000f0ce:
    (**(code **)(**(int **)(puVar9 + _UNK_0000f0fc) + 0x14))(2,PTR_DAT_0000f108 + 0xf0da);
  }
  else {
    if (iStack_40 < 0x33) {
      if (iStack_40 != 0x31) {
        return 0;
      }
      unaff_r8 = 1;
      if ((*extraout_r3 & 1) == 0) {
        puVar8 = *(undefined4 **)(puVar9 + _UNK_0000f0f4);
        FUN_00021dc4(*puVar8,aiStack_34,*(undefined4 *)(puVar9 + _UNK_0000f0f8),0);
        FUN_0000ef50(*puVar8,iVar4);
        if (aiStack_34[0] != 0) {
          *(uint *)(uVar7 + 0x24) = *(uint *)(uVar7 + 0x24) | 1;
        }
        *extraout_r3 = *extraout_r3 | 1;
        return 1;
      }
      goto code_r0x0000f0ce;
    }
    if (iStack_40 == 0x33) {
      uVar5 = 4;
      if ((*extraout_r3 & 4) == 0) goto code_r0x0000f04e;
      (**(code **)(**(int **)(puVar9 + _UNK_0000f0fc) + 0x14))(2,PTR_DAT_0000f100 + 0xf0ba);
      goto code_r0x0000f0be;
    }
    if (iStack_40 != 0x34) {
      return 0;
    }
    uVar5 = 8;
    if ((*extraout_r3 & 8) == 0) {
code_r0x0000f04e:
      *(uint *)(uVar7 + 0x24) = *(uint *)(uVar7 + 0x24) | uVar5;
      *extraout_r3 = uVar5 | *extraout_r3;
      return 1;
    }
  }
  iStack_5c = (**(code **)(**(int **)(puVar9 + _UNK_0000f0fc) + 0x14))(2,PTR_DAT_0000f10c + 0xf0ea);
  iStack_54 = (int)extraout_r3_00 * 0x80;
  *(uint *)(iStack_5c + 0x68) = uVar7;
  extraout_r3_00[0x19] = uVar7;
  *(uint *)(iStack_54 + 0x60) = uVar7;
  *(uint *)(iStack_5c + 0x68) = uVar7;
  puStack_44 = &UNK_0000f0ef;
  iVar6 = *piStack_3c;
  iVar10 = iRam0000f1d4 + 0xf128;
  uStack_58 = unaff_r8;
  iStack_50 = iVar4;
  uStack_4c = uVar7;
  puStack_48 = puVar9;
  if ((int)puVar9 * 0x100 == 0x31) {
    uVar7 = 1;
    if ((*extraout_r3_00 & 1) != 0) {
LAB_0000f1c4:
      (**(code **)(**(int **)(iVar10 + iRam0000f1e0) + 0x14))(2,iRam0000f1e8 + 0xf1d0);
      *(int *)(iVar6 + 0x54) = iVar10 * 0x100;
      *(int *)(uVar7 + 0x50) = iVar10 * 0x100;
      puVar1 = PTR_DAT_0000f21c;
      puVar9 = PTR_s__c__llu__llu_0000f218;
      puts(PTR_DAT_0000f214 + 0xf1f8);
      puVar8 = (undefined4 *)(puVar9 + 0xf204);
      puVar9 = PTR_LAB_0000f220 + 0xf204;
      do {
        printf(puVar1 + 0xf206,puVar9);
        puVar9 = (undefined *)*puVar8;
        puVar8 = puVar8 + 1;
      } while (puVar9 != (undefined *)0x0);
                    /* WARNING: Could not recover jumptable at 0x0000f210. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar4 = (*(code *)0xf1d5)();
      return iVar4;
    }
    puVar8 = *(undefined4 **)(iVar10 + iRam0000f1d8);
    FUN_00021dc4(*puVar8,&iStack_5c,*(undefined4 *)(iVar10 + iRam0000f1dc),0,0x31);
    FUN_0000ef50(*puVar8,iVar6 + 0x20);
    if (iStack_5c != 0) {
      *(undefined4 *)(iVar6 + 0x24) = 1;
    }
    *extraout_r3_00 = *extraout_r3_00 | 1;
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
    if ((int)puVar9 * 0x100 == 0x32) {
      if ((int)(*extraout_r3_00 << 0x1e) < 0) {
        (**(code **)(**(int **)(iVar10 + iRam0000f1e0) + 0x14))(2,iRam0000f1e4 + 0xf1c0);
        goto LAB_0000f1c4;
      }
      puVar8 = *(undefined4 **)(iVar10 + iRam0000f1d8);
      FUN_00021dc4(*puVar8,&iStack_5c,*(undefined4 *)(iVar10 + iRam0000f1dc),0,0x32);
      FUN_0000ef50(*puVar8,iVar6 + 0x22);
      if (iStack_5c != 0) {
        *(undefined4 *)(iVar6 + 0x28) = 1;
      }
      *extraout_r3_00 = *extraout_r3_00 | 2;
      iVar4 = 1;
    }
  }
  return iVar4;
}



/* Function: FUN_0000f110 @ 0000f110 */

undefined4
FUN_0000f110(int param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5,
            int *param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_r6;
  undefined4 *puVar5;
  int iVar6;
  int local_1c;
  
  iVar4 = *param_6;
  iVar6 = iRam0000f1d4 + 0xf128;
  local_1c = param_3;
  if (param_1 == 0x31) {
    unaff_r6 = 1;
    if ((*param_4 & 1) != 0) {
LAB_0000f1c4:
      (**(code **)(**(int **)(iVar6 + iRam0000f1e0) + 0x14))(2,iRam0000f1e8 + 0xf1d0);
      *(int *)(iVar4 + 0x54) = iVar6 * 0x100;
      *(int *)(unaff_r6 + 0x50) = iVar6 * 0x100;
      puVar1 = PTR_DAT_0000f21c;
      puVar2 = PTR_s__c__llu__llu_0000f218;
      puts(PTR_DAT_0000f214 + 0xf1f8);
      puVar5 = (undefined4 *)(puVar2 + 0xf204);
      puVar2 = PTR_LAB_0000f220 + 0xf204;
      do {
        printf(puVar1 + 0xf206,puVar2);
        puVar2 = (undefined *)*puVar5;
        puVar5 = puVar5 + 1;
      } while (puVar2 != (undefined *)0x0);
                    /* WARNING: Could not recover jumptable at 0x0000f210. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*(code *)0xf1d5)();
      return uVar3;
    }
    puVar5 = *(undefined4 **)(iVar6 + iRam0000f1d8);
    FUN_00021dc4(*puVar5,&local_1c,*(undefined4 *)(iVar6 + iRam0000f1dc),0,param_2);
    FUN_0000ef50(*puVar5,iVar4 + 0x20);
    if (local_1c != 0) {
      *(undefined4 *)(iVar4 + 0x24) = 1;
    }
    *param_4 = *param_4 | 1;
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    if (param_1 == 0x32) {
      if ((int)(*param_4 << 0x1e) < 0) {
        (**(code **)(**(int **)(iVar6 + iRam0000f1e0) + 0x14))(2,iRam0000f1e4 + 0xf1c0);
        goto LAB_0000f1c4;
      }
      puVar5 = *(undefined4 **)(iVar6 + iRam0000f1d8);
      FUN_00021dc4(*puVar5,&local_1c,*(undefined4 *)(iVar6 + iRam0000f1dc),0,param_2);
      FUN_0000ef50(*puVar5,iVar4 + 0x22);
      if (local_1c != 0) {
        *(undefined4 *)(iVar4 + 0x28) = 1;
      }
      *param_4 = *param_4 | 2;
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* Function: FUN_0000f264 @ 0000f264 */

void FUN_0000f264(void)

{
  FUN_0002310c(DAT_0000f270 + 0xf26c);
  return;
}



/* Function: FUN_0000f274 @ 0000f274 */

void FUN_0000f274(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_2 + 0x20) != 0) || (*(int *)(param_2 + 0x24) != -1)) {
    if ((int)((uint)*(byte *)(param_2 + 0x28) << 0x1f) < 0) {
      iVar1 = DAT_0000f2c8 + 0xf2b2;
    }
    else {
      iVar1 = DAT_0000f2bc + 0xf294;
    }
    printf((char *)(DAT_0000f2c0 + 0xf298),iVar1);
    if (*(int *)(param_2 + 0x20) == *(int *)(param_2 + 0x24)) {
      printf((char *)(DAT_0000f2cc + 0xf2b8));
    }
    else {
      printf((char *)(DAT_0000f2c4 + 0xf2a8));
    }
  }
  return;
}



/* Function: FUN_0000f444 @ 0000f444 */

void FUN_0000f444(void)

{
  puts((char *)(DAT_0000f450 + 0xf44c));
  return;
}



/* Function: FUN_0000f554 @ 0000f554 */

void FUN_0000f554(void)

{
  FUN_00022bd8(DAT_0000f560 + 0xf55c);
  return;
}



/* Function: FUN_0000f564 @ 0000f564 */

void FUN_0000f564(undefined4 param_1,int param_2)

{
  int iVar1;
  char *__s;
  
  if (*(int *)(param_2 + 0x20) != 0) {
    iVar1 = *(int *)(param_2 + 0x50);
    if (iVar1 == 1) {
      iVar1 = DAT_0000f5e8 + 0xf5ce;
    }
    else if (iVar1 == 0) {
      iVar1 = DAT_0000f5d4 + 0xf582;
    }
    else if (iVar1 == 2) {
      iVar1 = (int)&DAT_0000f5d4 + DAT_0000f5ec;
    }
    else {
      iVar1 = DAT_0000f5e4 + 0xf5c8;
    }
    __s = (char *)(DAT_0000f5d8 + 0xf598);
    sprintf(__s,(char *)(DAT_0000f5dc + 0xf59a),(uint)*(byte *)(param_2 + 0x24),
            (uint)*(byte *)(param_2 + 0x25),(uint)*(byte *)(param_2 + 0x26),
            (uint)*(byte *)(param_2 + 0x27),(uint)*(byte *)(param_2 + 0x28),
            (uint)*(byte *)(param_2 + 0x29));
    printf((char *)(DAT_0000f5e0 + 0xf5b2),iVar1,__s,(uint)*(ushort *)(param_2 + 0x2a),
           (uint)*(ushort *)(param_2 + 0x2e),*(undefined4 *)(param_2 + 0x54));
  }
  return;
}



/* Function: FUN_0000f5f0 @ 0000f5f0 */

void FUN_0000f5f0(undefined4 param_1,int param_2)

{
  int iVar1;
  char *__s;
  undefined *puVar2;
  
  if (*(int *)(param_2 + 0x20) == 0) {
    printf(PTR_DAT_0000f680 + 0xf658);
  }
  else {
    iVar1 = *(int *)(param_2 + 0x50);
    if (iVar1 == 1) {
      puVar2 = PTR_DAT_0000f688 + 0xf66a;
    }
    else if (iVar1 == 0) {
      puVar2 = PTR_DAT_0000f66c + 0xf60e;
    }
    else if (iVar1 == 2) {
      puVar2 = PTR_DAT_0000f684 + 0xf664;
    }
    else {
      puVar2 = PTR_DAT_0000f67c + 0xf652;
    }
    __s = PTR_DAT_0000f670 + 0xf624;
    sprintf(__s,PTR_DAT_0000f674 + 0xf626,(uint)*(byte *)(param_2 + 0x24),
            (uint)*(byte *)(param_2 + 0x25),(uint)*(byte *)(param_2 + 0x26),
            (uint)*(byte *)(param_2 + 0x27),(uint)*(byte *)(param_2 + 0x28),
            (uint)*(byte *)(param_2 + 0x29));
    printf(PTR_DAT_0000f678 + 0xf640,puVar2,__s,(uint)*(ushort *)(param_2 + 0x2a),
           (uint)*(ushort *)(param_2 + 0x2e),*(undefined4 *)(param_2 + 0x54));
  }
  return;
}



/* Function: FUN_0000f68c @ 0000f68c */

undefined4 FUN_0000f68c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_stack_00000004;
  
  if (param_1 - 0x31U < 6) {
    iVar1 = (param_1 - 0x31U) * 4;
    iVar3 = *(int *)(iVar1 + iRam0000f998 + 0xf6bc);
                    /* WARNING: Could not emulate address calculation at 0x0000f6ba */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)(iVar3 + iRam0000f998 + 0xf6bc))(iVar1,iVar3,*in_stack_00000004);
    return uVar2;
  }
  return 0;
}



/* Function: FUN_0000fa2c @ 0000fa2c */

void FUN_0000fa2c(void)

{
  FUN_00022bd8(DAT_0000fa38 + 0xfa34);
  return;
}



/* Function: FUN_0000fa3c @ 0000fa3c */

void FUN_0000fa3c(int *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_14 [2];
  
  iVar3 = *param_1;
  if (iVar3 << 0x1f < 0) {
    local_14[0] = param_1[1];
    uVar2 = FUN_00021f64(local_14);
    printf((char *)(DAT_0000fac4 + 0xfa9a),uVar2);
    if (param_1[2] != param_1[1]) {
      local_14[0] = param_1[2];
      uVar2 = FUN_00021f64(local_14);
      printf((char *)(DAT_0000fac8 + 0xfab4),uVar2);
    }
    iVar3 = *param_1;
  }
  if (iVar3 << 0x1e < 0) {
    putchar(0x3a);
    printf((char *)(DAT_0000fabc + 0xfa66),
           (*(ushort *)(param_1 + 3) & 0xff) << 8 | (uint)(*(ushort *)(param_1 + 3) >> 8));
    uVar1 = *(ushort *)((int)param_1 + 0xe);
    if ((uint)*(ushort *)(param_1 + 3) != (uint)uVar1) {
      printf((char *)(DAT_0000fac0 + 0xfa82),(uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8));
    }
  }
  return;
}



/* Function: FUN_0000fb64 @ 0000fb64 */

void FUN_0000fb64(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  char *__format;
  char *__format_00;
  
  printf(PTR_DAT_0000fbe8 + 0xfb76);
  if (*(int *)(param_2 + 0x20) != 0) {
    uVar1 = 0;
    __format = PTR_DAT_0000fbec + 0xfb92;
    __format_00 = PTR_DAT_0000fbf0 + 0xfb96;
    iVar2 = param_2;
    do {
      while( true ) {
        FUN_0000fa3c(param_2 + (uVar1 + 2) * 0x10 + 4);
        putchar(0x20);
        if ((*(uint *)(iVar2 + 0x24) & 4) == 0) break;
        printf(__format);
        if ((*(uint *)(iVar2 + 0x24) & 8) == 0) goto LAB_0000fb9c;
LAB_0000fbcc:
        printf(__format_00);
        uVar1 = uVar1 + 1;
        iVar2 = iVar2 + 0x10;
        if (*(uint *)(param_2 + 0x20) <= uVar1) {
          return;
        }
      }
      if ((*(uint *)(iVar2 + 0x24) & 8) != 0) goto LAB_0000fbcc;
LAB_0000fb9c:
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x10;
    } while (uVar1 < *(uint *)(param_2 + 0x20));
  }
  return;
}



/* Function: FUN_0000ff64 @ 0000ff64 */

void FUN_0000ff64(void)

{
  FUN_0002310c(DAT_0000ff70 + 0xff6c);
  return;
}



/* Function: FUN_0000ff74 @ 0000ff74 */

void FUN_0000ff74(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)(param_2 + 0x20);
  bVar1 = *pbVar2;
  if ((bVar1 & 0x10) != 0) {
    if ((*(byte *)(param_2 + 0x21) & 0x10) != 0) {
      printf((char *)(DAT_0000fff0 + 0xffd0));
    }
    printf((char *)(DAT_0000ffe0 + 0xff8e));
    bVar1 = *pbVar2;
  }
  if ((bVar1 & 0x20) != 0) {
    if ((*(byte *)(param_2 + 0x21) & 0x20) != 0) {
      printf((char *)(DAT_0000fff4 + 0xffda));
    }
    printf((char *)(DAT_0000ffe4 + 0xffa4));
    bVar1 = *pbVar2;
  }
  if ((bVar1 & 1) != 0) {
    if ((*(byte *)(param_2 + 0x21) & 1) != 0) {
      printf((char *)(DAT_0000ffec + 0xffc6));
    }
    printf((char *)(DAT_0000ffe8 + 0xffbc),(uint)*(byte *)(param_2 + 0x22));
  }
  return;
}



/* Function: FUN_0001021c @ 0001021c */

void FUN_0001021c(void)

{
  FUN_00022bd8(DAT_00010228 + 0x10224);
  return;
}



/* Function: FUN_0001022c @ 0001022c */

void FUN_0001022c(undefined4 param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)(param_2 + 0x20);
  uVar2 = (uint)*pbVar3;
  if (uVar2 == 0x30) {
    bVar1 = *(byte *)(param_2 + 0x22);
    if ((bVar1 & 3) == 0) {
      printf((char *)(DAT_0001029c + 0x10286));
      return;
    }
  }
  else {
    if (-1 < (int)(uVar2 << 0x1b)) goto joined_r0x0001026c;
    bVar1 = *(byte *)(param_2 + 0x22);
  }
  printf((char *)(DAT_00010294 + 0x10264),bVar1 & 1);
  uVar2 = (uint)*pbVar3;
joined_r0x0001026c:
  if ((int)(uVar2 << 0x1a) < 0) {
    printf((char *)(DAT_00010298 + 0x10278),(*(byte *)(param_2 + 0x22) & 3) >> 1);
    uVar2 = (uint)*pbVar3;
  }
  if ((int)(uVar2 << 0x1f) < 0) {
    printf((char *)(DAT_00010290 + 0x1024e),(uint)*(byte *)(param_2 + 0x21));
  }
  return;
}



/* Function: FUN_000102a0 @ 000102a0 */

void FUN_000102a0(undefined4 param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)(param_2 + 0x20);
  printf((char *)(DAT_0001030c + 0x102ac));
  uVar2 = (uint)*pbVar3;
  if (uVar2 == 0x30) {
    bVar1 = *(byte *)(param_2 + 0x22);
    if ((bVar1 & 3) == 0) {
      printf((char *)(DAT_0001031c + 0x10302));
      return;
    }
  }
  else {
    if (-1 < (int)(uVar2 << 0x1b)) goto joined_r0x000102e8;
    bVar1 = *(byte *)(param_2 + 0x22);
  }
  printf((char *)(DAT_00010314 + 0x102e0),bVar1 & 1);
  uVar2 = (uint)*pbVar3;
joined_r0x000102e8:
  if ((int)(uVar2 << 0x1a) < 0) {
    printf((char *)(DAT_00010318 + 0x102f4),(*(byte *)(param_2 + 0x22) & 3) >> 1);
    uVar2 = (uint)*pbVar3;
  }
  if ((int)(uVar2 << 0x1f) < 0) {
    printf((char *)(DAT_00010310 + 0x102ca),(uint)*(byte *)(param_2 + 0x21));
  }
  return;
}



/* Function: FUN_000104ec @ 000104ec */

void FUN_000104ec(void)

{
  FUN_0002310c(DAT_000104f8 + 0x104f4);
  return;
}



/* Function: FUN_000104fc @ 000104fc */

void FUN_000104fc(undefined4 param_1,int param_2)

{
  char cVar1;
  
  if ((int)((uint)*(byte *)(param_2 + 0x23) << 0x1f) < 0) {
    printf((char *)(DAT_00010554 + 0x10538));
    cVar1 = *(char *)(param_2 + 0x20);
  }
  else {
    cVar1 = *(char *)(param_2 + 0x20);
  }
  if (cVar1 == -1) {
    printf((char *)(DAT_00010558 + 0x10546));
  }
  else {
    printf((char *)(DAT_0001054c + 0x10514));
    if ((*(char *)(param_2 + 0x21) != '\0') || (*(char *)(param_2 + 0x22) != -1)) {
      printf((char *)(DAT_00010550 + 0x10528));
    }
    putchar(0x20);
  }
  return;
}



/* Function: FUN_00010854 @ 00010854 */

undefined4 FUN_00010854(void)

{
  undefined4 *unaff_r10;
  
  puts(PTR_LAB_000108d4 + 0x10864);
  return *unaff_r10;
}



/* Function: FUN_000108f4 @ 000108f4 */

void FUN_000108f4(void)

{
  FUN_00022bd8(DAT_00010900 + 0x108fc);
  return;
}



/* Function: FUN_00010904 @ 00010904 */

/* WARNING: Type propagation algorithm not settling */

void FUN_00010904(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  byte *pbVar4;
  
  pbVar4 = (byte *)(param_2 + 0x20);
  printf((char *)(DAT_000109dc + 0x10910));
  if (param_3 == 0) {
    uVar1 = (uint)*pbVar4;
    iVar3 = 0;
    puVar2 = (uint *)(DAT_000109e0 + 0x10926);
    do {
      if (*puVar2 == uVar1) {
        printf((char *)(DAT_000109f4 + 0x10964),*(undefined4 *)(iVar3 * 8 + DAT_000109f0 + 0x10962))
        ;
        if (iVar3 != 9) goto LAB_0001096c;
        uVar1 = (uint)*pbVar4;
        break;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 2;
    } while (iVar3 != 9);
    printf((char *)(DAT_000109e4 + 0x10936),uVar1);
LAB_0001096c:
    uVar1 = (uint)*(byte *)(param_2 + 0x21);
    if ((int)(uVar1 << 0x1f) < 0) {
      printf((char *)(DAT_000109fc + 0x10998));
      uVar1 = (uint)*(byte *)(param_2 + 0x21);
    }
    if ((int)(uVar1 << 0x1e) < 0) {
      printf((char *)(DAT_00010a00 + 0x109a6));
      uVar1 = (uint)*(byte *)(param_2 + 0x21);
    }
    if ((int)(uVar1 << 0x1d) < 0) {
      printf((char *)(DAT_00010a04 + 0x109b4));
      uVar1 = (uint)*(byte *)(param_2 + 0x21);
    }
    if ((int)(uVar1 << 0x1c) < 0) {
      printf((char *)(DAT_00010a08 + 0x109c2));
      uVar1 = (uint)*(byte *)(param_2 + 0x21);
    }
    if ((int)(uVar1 << 0x1a) < 0) {
      printf((char *)(DAT_00010a0c + 0x109d0));
      uVar1 = (uint)*(byte *)(param_2 + 0x21);
    }
    if ((uVar1 & 0xffffffd0) != 0) {
      printf((char *)(DAT_000109f8 + 0x1098e));
    }
  }
  else {
    printf((char *)(DAT_000109e8 + 0x10944),(uint)*(byte *)(param_2 + 0x21),(uint)*pbVar4);
  }
  if (*(char *)(param_2 + 0x22) != '\0') {
    printf((char *)(DAT_000109ec + 0x10954),param_2 + 0x22);
  }
  return;
}



/* Function: FUN_00010a10 @ 00010a10 */

void FUN_00010a10(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  if (*(char *)(param_2 + 0x22) != '\0') {
    printf(PTR_LAB_00010aa8 + 0x10a82);
    FUN_00021e64(param_2 + 0x22);
  }
  if (*(char *)(param_2 + 0x20) != '\x04') {
    printf(PTR_LAB_00010a90 + 0x10a2a);
  }
  uVar1 = (uint)*(byte *)(param_2 + 0x21);
  if ((int)(uVar1 << 0x1f) < 0) {
    printf(PTR_LAB_00010aa4 + 0x10a76);
    uVar1 = (uint)*(byte *)(param_2 + 0x21);
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    printf(PTR_LAB_00010aa0 + 0x10a6a);
    uVar1 = (uint)*(byte *)(param_2 + 0x21);
  }
  if ((int)(uVar1 << 0x1d) < 0) {
    printf(PTR_LAB_00010a9c + 0x10a5e);
    uVar1 = (uint)*(byte *)(param_2 + 0x21);
  }
  if ((int)(uVar1 << 0x1c) < 0) {
    printf(PTR_DAT_00016184_2_00010a98 + 0x10a52);
    uVar1 = (uint)*(byte *)(param_2 + 0x21);
  }
  if ((int)(uVar1 << 0x1a) < 0) {
    printf(PTR_DAT_00010a94 + 0x10a48);
  }
  return;
}



/* Function: FUN_00010aac @ 00010aac */

undefined4 FUN_00010aac(int param_1)

{
  undefined4 uVar1;
  
  if (0x14 < param_1 - 0x21U) {
    return 0;
  }
                    /* WARNING: Could not emulate address calculation at 0x00010ae0 */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(*(int *)((param_1 - 0x21U) * 4 + iRam00010d18 + 0x10ae2) +
                    iRam00010d18 + 0x10ae2))();
  return uVar1;
}



/* Function: FUN_00010d64 @ 00010d64 */

void FUN_00010d64(void)

{
  puts((char *)(DAT_00010d70 + 0x10d6c));
  return;
}



/* Function: FUN_00010d7c @ 00010d7c */

void FUN_00010d7c(void)

{
  FUN_00022bd8(DAT_00010d88 + 0x10d84);
  return;
}



/* Function: FUN_00010d8c @ 00010d8c */

void FUN_00010d8c(undefined4 param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x24);
  if (iVar2 << 0x1e < 0) {
    printf((char *)(DAT_00010de4 + 0x10db6),
           (*(ushort *)(param_2 + 0x30) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 0x30) >> 8));
    uVar1 = *(ushort *)(param_2 + 0x32);
    if ((uint)*(ushort *)(param_2 + 0x30) != (uint)uVar1) {
      printf((char *)(DAT_00010de8 + 0x10dd0),(uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8));
    }
    putchar(0x20);
    iVar2 = *(int *)(param_2 + 0x24);
  }
  if (iVar2 << 0x1d < 0) {
    printf((char *)(DAT_00010de0 + 0x10da2));
  }
  return;
}



/* Function: FUN_00010dec @ 00010dec */

void FUN_00010dec(undefined4 param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x24);
  if (iVar2 << 0x1e < 0) {
    printf((char *)(DAT_00010e4c + 0x10e0c));
    printf((char *)(DAT_00010e50 + 0x10e1e),
           (*(ushort *)(param_2 + 0x30) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 0x30) >> 8));
    uVar1 = *(ushort *)(param_2 + 0x32);
    if ((uint)*(ushort *)(param_2 + 0x30) != (uint)uVar1) {
      printf((char *)(DAT_00010e54 + 0x10e38),(uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8));
    }
    putchar(0x20);
    iVar2 = *(int *)(param_2 + 0x24);
  }
  if (iVar2 << 0x1d < 0) {
    printf((char *)(DAT_00010e48 + 0x10e02));
  }
  return;
}



/* Function: FUN_00010fb8 @ 00010fb8 */

void FUN_00010fb8(void)

{
  FUN_00022bd8(DAT_00010fc4 + 0x10fc0);
  return;
}



/* Function: FUN_00010ffc @ 00010ffc */

void FUN_00010ffc(void)

{
  FUN_00022bd8(DAT_00011008 + 0x11004);
  return;
}



/* Function: FUN_0001100c @ 0001100c */

void FUN_0001100c(void)

{
  printf((char *)(DAT_00011024 + 0x11018),*(undefined4 *)(DAT_00011020 + 0x11016));
  return;
}



/* Function: FUN_00011028 @ 00011028 */

void FUN_00011028(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_14 [2];
  
  local_14[0] = *(uint *)(param_2 + 0x28);
  uVar1 = FUN_00021f64(local_14);
  printf(PTR_LAB_0001109c + 0x11044,uVar1);
  local_14[0] = ~(*(uint *)(param_2 + 0x2c) ^ *(uint *)(param_2 + 0x28));
  iVar2 = 0;
  for (uVar3 = local_14[0] << 0x18 | local_14[0] >> 0x18 | (local_14[0] & 0xff00) << 8 |
               (local_14[0] & 0xff0000) >> 8; (int)uVar3 < 0; uVar3 = uVar3 * 2) {
    iVar2 = iVar2 + 1;
  }
  if (uVar3 == 0) {
    printf(PTR_LAB_000110a4 + 0x11096,iVar2);
  }
  else {
    uVar1 = FUN_00021f64(local_14);
    printf(PTR_LAB_000110a0 + 0x1108a,uVar1);
  }
  return;
}



/* Function: FUN_000110a8 @ 000110a8 */

void FUN_000110a8(undefined4 param_1,undefined4 param_2)

{
  printf((char *)(DAT_000110cc + 0x110b8),*(undefined4 *)(DAT_000110c8 + 0x110b4));
  FUN_00011028(param_1,param_2,0);
  return;
}



/* Function: FUN_0001128c @ 0001128c */

void FUN_0001128c(void)

{
  FUN_0002310c(DAT_00011298 + 0x11294);
  return;
}



/* Function: FUN_0001129c @ 0001129c */

void FUN_0001129c(void)

{
  char *__s;
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  int iVar3;
  ulong uVar4;
  int *piVar5;
  ulong *puVar6;
  int __base;
  char cVar7;
  undefined4 *puVar8;
  uint uVar9;
  byte *pbVar10;
  byte *__src;
  char *__s2;
  int iVar11;
  
  iVar1 = DAT_00011454;
  iVar11 = DAT_0001144c + 0x112b4;
  puVar8 = *(undefined4 **)(iVar11 + DAT_00011450);
  *(int *)(&stack0xffffffe0 + DAT_00011454) = DAT_00011450;
  *(undefined4 *)(&stack0x000001f0 + DAT_00011454) = *puVar8;
  __stream = fopen((char *)(DAT_00011458 + 0x112c4),(char *)(DAT_0001145c + 0x112c6));
  if (__stream == (FILE *)0x0) {
    *(undefined4 *)(DAT_0001146c + 0x11420) = 1;
  }
  else {
    *(undefined4 *)(&stack0xffffffe8 + iVar1) = 0;
    __s = &stack0xfffffff0 + iVar1;
    __s2 = (char *)(DAT_00011460 + 0x112e4);
    *(int *)(&stack0xffffffe4 + iVar1) = DAT_00011464 + 0x112dc;
    while (pcVar2 = fgets(__s,0x200,__stream), pcVar2 != (char *)0x0) {
      cVar7 = *__s;
      pcVar2 = __s;
      if ((cVar7 == ' ') || (cVar7 == '\t')) {
        do {
          do {
            pcVar2 = pcVar2 + 1;
            cVar7 = *pcVar2;
          } while (cVar7 == '\t');
        } while (cVar7 == ' ');
      }
      if (((cVar7 != '\n') && (cVar7 != '#')) && (cVar7 != '\0')) {
        puVar8 = (undefined4 *)__errno();
        *puVar8 = 0;
        iVar3 = strncmp(pcVar2,__s2,2);
        __base = 10;
        if (iVar3 == 0) {
          __base = 0x10;
        }
        uVar4 = strtoul(pcVar2,(char **)(&stack0xffffffec + iVar1),__base);
        if (((*(char **)(&stack0xffffffec + iVar1) != pcVar2) &&
            (piVar5 = (int *)__errno(), *piVar5 == 0)) && (uVar4 < 0x100)) {
          __src = *(byte **)(&stack0xffffffec + iVar1);
          uVar9 = (uint)*__src;
          iVar3 = **(int **)(iVar11 + DAT_00011468);
          if ((*(byte *)(iVar3 + uVar9 + 1) & 8) != 0) {
            if ((uVar9 == 0x20) || (uVar9 == 9)) {
              do {
                do {
                  __src = __src + 1;
                  uVar9 = (uint)*__src;
                } while (uVar9 == 9);
              } while (uVar9 == 0x20);
            }
            if (((uVar9 != 10) && (uVar9 != 0x23)) && (uVar9 != 0)) {
              *(byte **)(&stack0xffffffec + iVar1) = __src;
              uVar9 = (uint)*__src;
              pbVar10 = __src;
              if (uVar9 != 0) {
                do {
                  if ((*(byte *)(iVar3 + uVar9 + 1) & 8) != 0) break;
                  pbVar10 = pbVar10 + 1;
                  *(byte **)(&stack0xffffffec + iVar1) = pbVar10;
                  uVar9 = (uint)*pbVar10;
                } while (uVar9 != 0);
                if (pbVar10 != __src) {
                  puVar6 = malloc(0x10);
                  if (puVar6 == (ulong *)0x0) {
                    perror((char *)(DAT_00011470 + 0x11428));
                    /* WARNING: Subroutine does not return */
                    exit(1);
                  }
                  *puVar6 = uVar4;
                  iVar3 = *(int *)(&stack0xffffffec + iVar1);
                  puVar6[2] = iVar3 - (int)__src;
                  pcVar2 = malloc((iVar3 - (int)__src) + 1);
                  puVar6[1] = (ulong)pcVar2;
                  if (pcVar2 == (char *)0x0) {
                    perror((char *)(DAT_00011474 + 0x11442));
                    /* WARNING: Subroutine does not return */
                    exit(1);
                  }
                  strncpy(pcVar2,(char *)__src,puVar6[2]);
                  *(undefined1 *)(puVar6[1] + puVar6[2]) = 0;
                  puVar6[3] = 0;
                  if (*(int *)(&stack0xffffffe8 + iVar1) == 0) {
                    *(ulong **)(&stack0xffffffe8 + iVar1) = puVar6;
                    *(ulong **)(*(int *)(&stack0xffffffe4 + iVar1) + 4) = puVar6;
                  }
                  else {
                    *(ulong **)(*(int *)(&stack0xffffffe8 + iVar1) + 0xc) = puVar6;
                    *(ulong **)(&stack0xffffffe8 + iVar1) = puVar6;
                  }
                }
              }
            }
          }
        }
      }
    }
    fclose(__stream);
  }
  if (*(int *)(&stack0x000001f0 + iVar1) != **(int **)(iVar11 + *(int *)(&stack0xffffffe0 + iVar1)))
  {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_00011478 @ 00011478 */

void FUN_00011478(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = DAT_000114d8;
  if (param_2 == -1) {
    if (param_3 == 0) {
      piVar2 = *(int **)(DAT_000114d8 + 0x11490);
      if (piVar2 != (int *)0x0) goto LAB_00011498;
      if (*(int *)(DAT_000114d8 + 0x1148c) == 0) {
        FUN_0001129c();
        for (piVar2 = *(int **)(iVar1 + 0x11490); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
LAB_00011498:
          if (param_1 == *piVar2) {
            if (piVar2[1] != 0) {
              printf(PTR_LAB_000114dc + 0x114aa);
              return;
            }
            break;
          }
        }
      }
    }
    printf(PTR_LAB_000114e4 + 0x114d4,param_1);
  }
  else {
    printf(PTR_LAB_000114e0 + 0x114b8,param_1,param_2);
  }
  return;
}



/* Function: FUN_000114e8 @ 000114e8 */

void FUN_000114e8(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x28) != '\0') {
    printf((char *)(DAT_00011514 + 0x114fc));
  }
  printf((char *)(DAT_00011518 + 0x11504));
  FUN_00011478(*(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24),0);
  return;
}



/* Function: FUN_0001151c @ 0001151c */

void FUN_0001151c(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (*(char *)(param_2 + 0x28) != '\0') {
    printf((char *)(DAT_00011548 + 0x11532));
  }
  printf((char *)(DAT_0001154c + 0x1153a));
  FUN_00011478(*(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24),param_3);
  return;
}



/* Function: FUN_00011550 @ 00011550 */

undefined4
FUN_00011550(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined4 param_5,
            int *param_6)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  char *__s1;
  int iVar7;
  int local_34 [2];
  char *local_2c [2];
  
  iVar1 = DAT_0001168c;
  iVar6 = DAT_00011688 + 0x1156a;
  iVar7 = *param_6;
  uVar4 = 0;
  if (param_1 == 0x31) {
    piVar5 = *(int **)(iVar6 + DAT_0001168c);
    local_34[0] = param_3;
    FUN_00021dc4(*piVar5,local_34,*(undefined4 *)(iVar6 + DAT_00011690),0,param_2);
    local_2c[0] = (char *)*piVar5;
    uVar2 = strtoul(local_2c[0],local_2c,0);
    *(ulong *)(iVar7 + 0x20) = uVar2;
    iVar3 = DAT_00011694;
    __s1 = (char *)*piVar5;
    if (local_2c[0] == __s1) {
LAB_000115f6:
      piVar5 = *(int **)(DAT_00011694 + 0x11602);
      if (piVar5 != (int *)0x0) goto LAB_00011634;
      if (*(int *)(DAT_00011694 + 0x115fe) != 0) goto LAB_0001161c;
      FUN_0001129c();
      piVar5 = *(int **)(iVar3 + 0x11602);
      goto joined_r0x00011614;
    }
    if (*local_2c[0] == '\0') {
      *(undefined4 *)(iVar7 + 0x24) = 0xffffffff;
    }
    else {
      if (*local_2c[0] != '/') goto LAB_000115f6;
      uVar2 = strtoul(local_2c[0] + 1,local_2c,0);
      *(ulong *)(iVar7 + 0x24) = uVar2;
    }
    if ((*local_2c[0] != '\0') || (local_2c[0] == (char *)**(undefined4 **)(iVar6 + iVar1))) {
      (**(code **)(**(int **)(iVar6 + DAT_00011698) + 0x14))
                (2,DAT_000116a0 + 0x1167c,**(undefined4 **)(iVar6 + iVar1));
LAB_00011680:
      __s1 = (char *)**(undefined4 **)(iVar6 + iVar1);
LAB_0001161c:
      do {
        (**(code **)(**(int **)(iVar6 + DAT_00011698) + 0x14))(2,DAT_0001169c + 0x11628,__s1);
        while( true ) {
          piVar5 = (int *)piVar5[3];
joined_r0x00011614:
          if (piVar5 == (int *)0x0) break;
LAB_00011634:
          iVar3 = strncmp(__s1,(char *)piVar5[1],piVar5[2] + 1);
          if (iVar3 == 0) {
            if (*piVar5 == -1) goto LAB_00011680;
            *(int *)(iVar7 + 0x20) = *piVar5;
            *(undefined4 *)(iVar7 + 0x24) = 0xffffffff;
            goto LAB_000115e2;
          }
        }
        __s1 = (char *)**(undefined4 **)(iVar6 + iVar1);
      } while( true );
    }
LAB_000115e2:
    if (local_34[0] != 0) {
      *(undefined1 *)(iVar7 + 0x28) = 1;
    }
    uVar4 = 1;
    *param_4 = 1;
  }
  return uVar4;
}



/* Function: FUN_000116bc @ 000116bc */

void FUN_000116bc(void)

{
  FUN_00022bd8(DAT_000116c8 + 0x116c4);
  return;
}



/* Function: FUN_000116cc @ 000116cc */

void FUN_000116cc(undefined4 param_1,int param_2)

{
  ushort uVar1;
  
  if (*(int *)(param_2 + 0x24) << 0x1e < 0) {
    printf((char *)(DAT_00011728 + 0x116e0));
    printf((char *)(DAT_0001172c + 0x116f2),
           (*(ushort *)(param_2 + 0x30) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 0x30) >> 8));
    uVar1 = *(ushort *)(param_2 + 0x32);
    if ((uint)*(ushort *)(param_2 + 0x30) != (uint)uVar1) {
      printf((char *)(DAT_00011730 + 0x1170c),(uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8));
    }
    putchar(0x20);
    if (*(int *)(param_2 + 0x24) << 0x1d < 0) {
      printf((char *)(DAT_00011734 + 0x11722));
    }
  }
  return;
}



/* Function: FUN_00011738 @ 00011738 */

void FUN_00011738(undefined4 param_1,int param_2)

{
  ushort uVar1;
  
  if (*(int *)(param_2 + 0x24) << 0x1e < 0) {
    printf(PTR_LAB_00011794 + 0x1174c);
    printf(PTR_LAB_00011798 + 0x1175e,
           (*(ushort *)(param_2 + 0x30) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 0x30) >> 8));
    uVar1 = *(ushort *)(param_2 + 0x32);
    if ((uint)*(ushort *)(param_2 + 0x30) != (uint)uVar1) {
      printf(PTR_PTR_0001179c + 0x11778,(uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8));
    }
    putchar(0x20);
    if (*(int *)(param_2 + 0x24) << 0x1d < 0) {
      printf(PTR_LAB_000117a0 + 0x1178e);
    }
  }
  return;
}



/* Function: FUN_000117a4 @ 000117a4 */

undefined4
FUN_000117a4(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,int param_5,
            int *param_6)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar9;
  undefined4 local_2c [2];
  uint local_24;
  uint local_20;
  char *local_1c [2];
  
  iVar7 = *param_6;
  sVar1 = *(short *)(param_5 + 0x50);
  iVar6 = iRam00011918 + 0x117be;
  if ((((sVar1 == 0x11) || (sVar1 == 6)) || (sVar1 == 0x84)) || (sVar1 == 0x21)) {
    bVar9 = true;
  }
  else {
    bVar9 = sVar1 == 1;
  }
  if (param_1 != 0x31) {
    uVar4 = 0;
    if (param_1 == 0x32) {
      if ((int)(*param_4 << 0x1f) < 0) {
        *(uint *)(iVar7 + 0x24) = *(uint *)(iVar7 + 0x24) | 4;
        *param_4 = *param_4 | 2;
        uVar4 = 1;
      }
      else {
        *param_4 = *param_4 | 2;
        uVar4 = 1;
      }
    }
    return uVar4;
  }
  local_2c[0] = param_3;
  if (bVar9) {
    puVar8 = *(undefined4 **)(iVar6 + DAT_0001191c);
    iVar3 = FUN_00021dc4(*puVar8,local_2c,0,0,param_2);
    if (iVar3 == 0) {
      uVar4 = *puVar8;
      *(uint *)(iVar7 + 0x24) = *(uint *)(iVar7 + 0x24) | 2;
      iVar6 = FUN_000224cc(uVar4,local_1c,&local_20,0,PTR_LAB_0000fffe_1_00011920);
      if ((iVar6 == 0) && (local_20 = FUN_00022444(uVar4,0), local_20 == 0xffffffff)) {
        FUN_000221e0(7,PTR_LAB_0001192c + 0x118de,PTR_LAB_00011930 + 0x118e0,uVar4);
      }
      if (*local_1c[0] == '\0') {
        uVar2 = (ushort)((local_20 & 0xffff) << 8) | (ushort)(local_20 >> 8) & 0xff;
        *(ushort *)(iVar7 + 0x32) = uVar2;
        *(ushort *)(iVar7 + 0x30) = uVar2;
      }
      else if (((*local_1c[0] == '-') &&
               ((iVar6 = FUN_000224cc(local_1c[0] + 1,0,&local_24,0,PTR_LAB_0000fffe_1_00011920),
                iVar6 != 0 || (local_24 = FUN_00022444(local_1c[0] + 1,0), local_24 != 0xffffffff)))
               ) && (local_20 <= local_24)) {
        *(ushort *)(iVar7 + 0x30) =
             (ushort)(local_20 >> 8) & 0xff | (ushort)((local_20 & 0xffff) << 8);
        *(ushort *)(iVar7 + 0x32) =
             (ushort)(local_24 >> 8) & 0xff | (ushort)((local_24 & 0xffff) << 8);
      }
      else {
        FUN_000221e0(7,PTR_LAB_00011924 + 0x11828,PTR_LAB_00015824_2_00011928 + 0x1182a,uVar4);
      }
      uVar5 = *param_4;
      if ((int)(uVar5 << 0x1e) < 0) {
        *(uint *)(iVar7 + 0x24) = *(uint *)(iVar7 + 0x24) | 4;
        uVar5 = *param_4;
      }
      *param_4 = uVar5 | 1;
      return 1;
    }
  }
  else {
    (**(code **)(**(int **)(iVar6 + DAT_00011934) + 0x14))(2,DAT_00011938 + 0x11904);
  }
  (**(code **)(**(int **)(iVar6 + DAT_00011934) + 0x14))(2,DAT_0001193c + 0x11914);
                    /* WARNING: Could not recover jumptable at 0x00011918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)();
  return uVar4;
}



/* Function: FUN_00011940 @ 00011940 */

void FUN_00011940(void)

{
  puts((char *)(DAT_0001194c + 0x11948));
  return;
}



/* Function: FUN_00011958 @ 00011958 */

void FUN_00011958(void)

{
  FUN_00022bd8(DAT_00011964 + 0x11960);
  return;
}



/* Function: FUN_00011968 @ 00011968 */

void FUN_00011968(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = (int *)(DAT_00011994 + 0x1197c);
  do {
    if (*(int *)(param_2 + 0x20) == *piVar1) break;
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 4;
  } while (iVar2 != 8);
  printf((char *)(DAT_0001199c + 0x1198e),*(undefined4 *)(iVar2 * 0x10 + DAT_00011998 + 0x1198c));
  return;
}



/* Function: FUN_000119a0 @ 000119a0 */

void FUN_000119a0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = (int *)(DAT_000119cc + 0x119b4);
  do {
    if (*(int *)(param_2 + 0x20) == *piVar1) break;
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 4;
  } while (iVar2 != 8);
  printf((char *)(DAT_000119d4 + 0x119c6),*(undefined4 *)(iVar2 * 0x10 + DAT_000119d0 + 0x119c4));
  return;
}



/* Function: FUN_00011b7c @ 00011b7c */

void FUN_00011b7c(void)

{
  FUN_00022bd8(DAT_00011b88 + 0x11b84);
  return;
}



/* Function: FUN_00011b8c @ 00011b8c */

void FUN_00011b8c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  char *__format;
  char *__format_00;
  bool bVar4;
  undefined4 local_2c [2];
  
  bVar4 = false;
  if (*(int *)(param_2 + 0x24) != 0) {
    uVar3 = 0;
    __format = (char *)(DAT_00011c38 + 0x11bbc);
    __format_00 = (char *)(DAT_00011c3c + 0x11bbe);
    pbVar2 = (byte *)(param_2 + 0x20);
    do {
      local_2c[0] = *(undefined4 *)(pbVar2 + 0x14);
      uVar1 = FUN_00021f64(local_2c);
      printf(__format,uVar1);
      local_2c[0] = *(undefined4 *)(pbVar2 + 0x18);
      if (*(int *)(pbVar2 + 0x14) == *(int *)(pbVar2 + 0x18)) {
        putchar(0x20);
      }
      else {
        uVar1 = FUN_00021f64(local_2c);
        printf(__format_00,uVar1);
      }
      if ((*(uint *)(pbVar2 + 0x10) & 4) != 0) {
        bVar4 = true;
      }
      uVar3 = uVar3 + 1;
      pbVar2 = pbVar2 + 0x10;
    } while (uVar3 < *(uint *)(param_2 + 0x24));
  }
  if ((int)((uint)*(byte *)(param_2 + 0x20) << 0x1f) < 0) {
    printf((char *)(DAT_00011c44 + 0x11c32));
  }
  if (bVar4) {
    printf((char *)(DAT_00011c40 + 0x11c1c));
  }
  return;
}



/* Function: FUN_00011ecc @ 00011ecc */

void FUN_00011ecc(void)

{
  puts((char *)(DAT_00011ed8 + 0x11ed4));
  return;
}



/* Function: FUN_00011f00 @ 00011f00 */

void FUN_00011f00(void)

{
  FUN_00022bd8(DAT_00011f0c + 0x11f08);
  return;
}



/* Function: FUN_00011f10 @ 00011f10 */

void FUN_00011f10(int *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_14 [2];
  
  iVar3 = *param_1;
  if (iVar3 << 0x1f < 0) {
    local_14[0] = param_1[1];
    uVar2 = FUN_00021f64(local_14);
    printf((char *)(DAT_00011f98 + 0x11f6e),uVar2);
    if (param_1[2] != param_1[1]) {
      local_14[0] = param_1[2];
      uVar2 = FUN_00021f64(local_14);
      printf((char *)(DAT_00011f9c + 0x11f88),uVar2);
    }
    iVar3 = *param_1;
  }
  if (iVar3 << 0x1e < 0) {
    putchar(0x3a);
    printf((char *)(DAT_00011f90 + 0x11f3a),
           (*(ushort *)(param_1 + 3) & 0xff) << 8 | (uint)(*(ushort *)(param_1 + 3) >> 8));
    uVar1 = *(ushort *)((int)param_1 + 0xe);
    if ((uint)*(ushort *)(param_1 + 3) != (uint)uVar1) {
      printf((char *)(DAT_00011f94 + 0x11f56),(uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8));
    }
  }
  return;
}



/* Function: FUN_00012038 @ 00012038 */

void FUN_00012038(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  char *__format;
  char *__format_00;
  
  printf(PTR_LAB_000120bc + 0x1204a);
  if (*(int *)(param_2 + 0x20) != 0) {
    uVar1 = 0;
    __format = PTR_LAB_000120c0 + 0x12066;
    __format_00 = PTR_LAB_000120c4 + 0x1206a;
    iVar2 = param_2;
    do {
      while( true ) {
        FUN_00011f10(param_2 + (uVar1 + 2) * 0x10 + 4);
        putchar(0x20);
        if ((*(uint *)(iVar2 + 0x24) & 4) == 0) break;
        printf(__format);
        if ((*(uint *)(iVar2 + 0x24) & 8) == 0) goto LAB_00012070;
LAB_000120a0:
        printf(__format_00);
        uVar1 = uVar1 + 1;
        iVar2 = iVar2 + 0x10;
        if (*(uint *)(param_2 + 0x20) <= uVar1) {
          return;
        }
      }
      if ((*(uint *)(iVar2 + 0x24) & 8) != 0) goto LAB_000120a0;
LAB_00012070:
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x10;
    } while (uVar1 < *(uint *)(param_2 + 0x20));
  }
  return;
}



/* Function: FUN_00012438 @ 00012438 */

void FUN_00012438(void)

{
  FUN_0002310c(DAT_00012444 + 0x12440);
  return;
}



/* Function: FUN_00012448 @ 00012448 */

void FUN_00012448(undefined4 param_1,int param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_2 + 0x20);
  if (cVar1 == '\x01') {
    printf((char *)(DAT_000124a0 + 0x12484));
  }
  else if (cVar1 == '\0') {
    printf((char *)(DAT_00012494 + 0x1245e));
  }
  else if (cVar1 == '\x02') {
    printf((char *)(DAT_000124a4 + 0x1248e));
  }
  else if (cVar1 == '\x03') {
    printf((char *)(DAT_0001249c + 0x1247a));
  }
  printf((char *)(DAT_00012498 + 0x12468),(uint)*(byte *)(param_2 + 0x21));
  return;
}



/* Function: FUN_0001269c @ 0001269c */

void FUN_0001269c(void)

{
  FUN_00022bd8(DAT_000126a8 + 0x126a4);
  return;
}



/* Function: FUN_000126ac @ 000126ac */

void FUN_000126ac(undefined4 param_1,int param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_2 + 0x20);
  if (cVar1 == '\x01') {
    printf((char *)(DAT_000126f4 + 0x126e4));
  }
  else if (cVar1 == '\0') {
    printf((char *)(DAT_000126f0 + 0x126da));
  }
  else if (cVar1 == '\x02') {
    printf((char *)(DAT_000126e8 + 0x126c6));
  }
  printf((char *)(DAT_000126ec + 0x126d0),(uint)*(byte *)(param_2 + 0x21));
  return;
}



/* Function: FUN_000126f8 @ 000126f8 */

void FUN_000126f8(undefined4 param_1,int param_2)

{
  char cVar1;
  
  printf(PTR_LAB_0001273c + 0x12704);
  cVar1 = *(char *)(param_2 + 0x20);
  if (cVar1 == '\x01') {
    printf(PTR_LAB_0001274c + 0x12738);
  }
  else if (cVar1 == '\0') {
    printf(PTR_LAB_00012748 + 0x1272e);
  }
  else if (cVar1 == '\x02') {
    printf(PTR_LAB_00012740 + 0x1271a);
  }
  printf(PTR_LAB_00012744 + 0x12724,(uint)*(byte *)(param_2 + 0x21));
  return;
}



/* Function: FUN_0001288c @ 0001288c */

void FUN_0001288c(void)

{
  FUN_00022bd8(DAT_00012898 + 0x12894);
  return;
}



/* Function: FUN_0001289c @ 0001289c */

void FUN_0001289c(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (*(char *)(param_2 + 0x2c) != '\0') {
    fwrite((void *)(DAT_00012940 + 0x12910),1,0xe,
           (FILE *)(*(int *)(DAT_0001292c + 0x128b2 + DAT_0001293c) + 0x54));
    FUN_00021e64(param_2 + 0x2c);
  }
  iVar1 = DAT_00012934;
  if (*(int *)(param_2 + 0x20) != 1) {
    printf((char *)(DAT_00012930 + 0x128c4));
    uVar3 = *(uint *)(param_2 + 0x20);
    uVar2 = 0x1f;
    do {
      while ((1 << (uVar2 & 0xff) & uVar3) != 0) {
        printf((char *)(iVar1 + 0x128ca),uVar2 + 1);
        bVar4 = uVar2 == 0;
        uVar2 = uVar2 - 1;
        if (bVar4) goto LAB_000128e6;
      }
      bVar4 = uVar2 != 0;
      uVar2 = uVar2 - 1;
    } while (bVar4);
  }
LAB_000128e6:
  if (*(int *)(param_2 + 0x24) != 0) {
    printf((char *)(DAT_00012944 + 0x12926));
  }
  if (*(int *)(param_2 + 0x28) != 1) {
    printf((char *)(DAT_00012938 + 0x128fc));
  }
  return;
}



/* Function: FUN_00012948 @ 00012948 */

void FUN_00012948(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  printf(PTR_LAB_000129b4 + 0x12958);
  puVar1 = PTR_LAB_000129bc;
  printf(PTR_LAB_000129b8 + 0x12968,*(undefined4 *)(param_2 + 0x24));
  uVar3 = *(uint *)(param_2 + 0x20);
  uVar2 = 0x1f;
  do {
    while ((1 << (uVar2 & 0xff) & uVar3) != 0) {
      printf(puVar1 + 0x12974,uVar2 + 1);
      bVar4 = uVar2 == 0;
      uVar2 = uVar2 - 1;
      if (bVar4) goto LAB_0001298e;
    }
    bVar4 = uVar2 != 0;
    uVar2 = uVar2 - 1;
  } while (bVar4);
LAB_0001298e:
  if (*(char *)(param_2 + 0x2c) != '\0') {
    printf(PTR_LAB_000129c0 + 0x129a0,param_2 + 0x2c);
  }
  printf(PTR_LAB_000129c4 + 0x129ac,*(undefined4 *)(param_2 + 0x28));
  return;
}



/* Function: FUN_00012c24 @ 00012c24 */

void FUN_00012c24(void)

{
  puts((char *)(DAT_00012c30 + 0x12c2c));
  return;
}



/* Function: FUN_00012c34 @ 00012c34 */

void FUN_00012c34(void)

{
  FUN_0002310c(DAT_00012c40 + 0x12c3c);
  return;
}



/* Function: FUN_00012c68 @ 00012c68 */

void FUN_00012c68(void)

{
  FUN_00022bd8(DAT_00012c74 + 0x12c70);
  return;
}



/* Function: FUN_00012c78 @ 00012c78 */

void FUN_00012c78(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00012c8c + 0x12c86),*(uint *)(param_2 + 0x20) >> 0x10,
         *(uint *)(param_2 + 0x20) & 0xffff);
  return;
}



/* Function: FUN_00012c90 @ 00012c90 */

void FUN_00012c90(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00012cb0 + 0x12c9a));
  printf((char *)(DAT_00012cb4 + 0x12caa),*(uint *)(param_2 + 0x20) >> 0x10,
         *(uint *)(param_2 + 0x20) & 0xffff);
  return;
}



/* Function: FUN_00012cb8 @ 00012cb8 */

undefined4
FUN_00012cb8(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,undefined4 param_5,
            int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined8 uVar6;
  uint local_20;
  int local_1c [2];
  
  iVar3 = iRam00012d24 + 0x12cc6;
  iVar5 = *param_6;
  uVar2 = 0;
  if (param_1 == 0x31) {
    puVar4 = *(undefined4 **)(iVar3 + iRam00012d28);
    iVar1 = sscanf((char *)*puVar4,(char *)(iRam00012d2c + 0x12cde),local_1c,&local_20);
    if (iVar1 != 2) {
      (**(code **)(**(int **)(iVar3 + iRam00012d30) + 0x14))(2,iRam00012d34 + 0x12cf4,*puVar4);
    }
    *(uint *)(iVar5 + 0x20) = local_1c[0] << 0x10 | local_20 & 0xffff;
    if (*param_4 != 0) {
      uVar6 = (**(code **)(**(int **)(iVar3 + iRam00012d30) + 0x14))(2,iRam00012d38 + 0x12d20);
      *(char *)((int)param_4 * 0x40 + (int)((ulonglong)uVar6 >> 0x20)) = (char)uVar6;
      *(char *)((int)uVar6 * 2) = (char)((int)param_4 * 0x40);
      *(undefined1 *)(iVar5 * 0x200) = 0;
      puts((char *)(DAT_00012d48 + 0x12d44));
                    /* WARNING: Could not recover jumptable at 0x00012d46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)0x12d25)();
      return uVar2;
    }
    uVar2 = 1;
    *param_4 = 1;
  }
  return uVar2;
}



/* Function: FUN_00012e10 @ 00012e10 */

void FUN_00012e10(void)

{
  FUN_0002310c(DAT_00012e1c + 0x12e18);
  return;
}



/* Function: FUN_00012e20 @ 00012e20 */

void FUN_00012e20(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x2c) << 0x1f < 0) {
    printf((char *)(DAT_00012e5c + 0x12e4e),*(undefined4 *)(param_2 + 0x24));
  }
  else {
    printf((char *)(DAT_00012e54 + 0x12e36),*(undefined4 *)(param_2 + 0x24));
  }
  printf((char *)(DAT_00012e58 + 0x12e42),*(undefined4 *)(param_2 + 0x20),
         *(undefined4 *)(param_2 + 0x28));
  return;
}



/* Function: FUN_00012e60 @ 00012e60 */

void FUN_00012e60(undefined4 param_1,int param_2)

{
  printf(PTR_LAB_00012e9c + 0x12e6c);
  if (*(int *)(param_2 + 0x2c) << 0x1f < 0) {
    printf(PTR_LAB_00012ea8 + 0x12e96,*(undefined4 *)(param_2 + 0x24));
  }
  else {
    printf(PTR_LAB_00015578_2_00012ea0 + 0x12e7e,*(undefined4 *)(param_2 + 0x24));
  }
  printf(PTR_LAB_00012ea4 + 0x12e8a,*(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x28))
  ;
  return;
}



/* Function: FUN_00013140 @ 00013140 */

void FUN_00013140(void)

{
  FUN_0002310c(DAT_0001314c + 0x13148);
  return;
}



/* Function: FUN_00013150 @ 00013150 */

void FUN_00013150(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_00013164;
  *(undefined1 *)(param_2 + 0x11f) = 0;
  printf((char *)(iVar1 + 0x13160));
  return;
}



/* Function: FUN_00013168 @ 00013168 */

void FUN_00013168(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_00013184;
  *(undefined1 *)(param_2 + 0x11f) = 0;
  printf((char *)(iVar1 + 0x1317a));
  FUN_00021e64(param_2 + 0x20);
  return;
}



/* Function: FUN_00013188 @ 00013188 */

undefined4
FUN_00013188(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined4 param_5,
            int *param_6)

{
  undefined1 uVar1;
  size_t sVar2;
  undefined4 uVar3;
  int extraout_r1;
  int extraout_r3;
  int iVar4;
  char *__s;
  int iVar5;
  int local_1c [2];
  
  iVar4 = iRam00013200 + 0x13198;
  iVar5 = *param_6;
  if (param_1 != 0x31) {
    return 0;
  }
  __s = *(char **)(iVar4 + iRam00013204);
  local_1c[0] = param_3;
  FUN_00021dc4(*(undefined4 *)__s,local_1c,*(undefined4 *)(iVar4 + iRam00013208),0,param_2);
  if (local_1c[0] == 0) {
    __s = *(char **)__s;
    sVar2 = strlen(__s);
    if ((int)sVar2 < 0x100) {
      strcpy((char *)(iVar5 + 0x20),__s);
      *param_4 = 1;
      return 1;
    }
  }
  else {
    (**(code **)(**(int **)(iVar4 + iRam0001320c) + 0x14))(2,iRam00013210 + 0x131e6);
  }
  uVar1 = (**(code **)(**(int **)(iVar4 + iRam0001320c) + 0x14))(2,iRam00013214 + 0x131f6,0x100);
  *(undefined1 *)(extraout_r1 + (int)param_4) = uVar1;
  *(char *)(param_4 + extraout_r3 * 0x20) = (char)__s;
  puts((char *)(DAT_00013224 + 0x13220));
                    /* WARNING: Could not recover jumptable at 0x00013222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)0x131ff)();
  return uVar3;
}



/* Function: FUN_0001324c @ 0001324c */

void FUN_0001324c(void)

{
  FUN_0002310c(DAT_00013258 + 0x13254);
  return;
}



/* Function: FUN_0001325c @ 0001325c */

void FUN_0001325c(int param_1)

{
  char cVar1;
  void *__ptr;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 0x10);
  iVar2 = DAT_000132b4 + 0x13266;
  if (cVar1 == '\x01') {
    fwrite((void *)(DAT_000132c4 + 0x13296),1,6,(FILE *)(*(int *)(iVar2 + DAT_000132bc) + 0x54));
  }
  else {
    if (cVar1 == '\0') {
      __ptr = (void *)(DAT_000132c0 + 0x1328a);
    }
    else {
      if (cVar1 == '\x02') {
        fwrite((void *)(DAT_000132c8 + 0x132aa),1,7,(FILE *)(*(int *)(iVar2 + DAT_000132bc) + 0x54))
        ;
        return;
      }
      __ptr = (void *)(DAT_000132b8 + 0x13276);
    }
    fwrite(__ptr,1,8,(FILE *)(*(int *)(iVar2 + DAT_000132bc) + 0x54));
  }
  return;
}



/* Function: FUN_000132cc @ 000132cc */

void FUN_000132cc(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 0x11);
  iVar2 = DAT_00013330 + 0x132d6;
  if (cVar1 == '\x01') {
    fwrite(PTR_LAB_00013340 + 0x13314,1,6,(FILE *)(*(int *)(iVar2 + DAT_00013334) + 0x54));
  }
  else if (cVar1 == '\0') {
    fwrite(PTR_LAB_0001333c + 0x13300,1,9,(FILE *)(*(int *)(iVar2 + DAT_00013334) + 0x54));
  }
  else if (cVar1 == '\x02') {
    fwrite(PTR_LAB_00013344 + 0x13328,1,5,(FILE *)(*(int *)(iVar2 + DAT_00013334) + 0x54));
  }
  else {
    fwrite(PTR_LAB_00015556_2_00013338 + 0x132ec,1,8,(FILE *)(*(int *)(iVar2 + DAT_00013334) + 0x54)
          );
  }
  return;
}



/* Function: FUN_00013348 @ 00013348 */

void FUN_00013348(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  FILE *__s;
  
  uVar2 = *(uint *)(param_2 + 0x24);
  uVar1 = *(uint *)(param_2 + 0x2c);
  iVar3 = DAT_000133bc + 0x1335a;
  if ((uVar1 < uVar2) ||
     ((uVar2 == uVar1 && (*(uint *)(param_2 + 0x28) < *(uint *)(param_2 + 0x20))))) {
    printf((char *)(DAT_000133c0 + 0x1336a),uVar1,*(uint *)(param_2 + 0x28),uVar1,
           *(uint *)(param_2 + 0x20),uVar2);
  }
  else {
    printf(PTR_LAB_000133d0 + 0x133b2);
  }
  __s = (FILE *)(*(int *)(iVar3 + DAT_000133c4) + 0x54);
  fwrite(PTR_LAB_000133c8 + 0x1337e,1,0x11,__s);
  FUN_0001325c(param_2 + 0x20);
  fwrite(PTR_LAB_000133cc + 0x13398,1,0x10,__s);
  FUN_000132cc(param_2 + 0x20);
  return;
}



/* Function: FUN_000133d4 @ 000133d4 */

void FUN_000133d4(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  FILE *__s;
  
  uVar2 = *(uint *)(param_2 + 0x24);
  uVar1 = *(uint *)(param_2 + 0x2c);
  iVar3 = DAT_00013448 + 0x133e6;
  if ((uVar1 < uVar2) ||
     ((uVar2 == uVar1 && (*(uint *)(param_2 + 0x28) < *(uint *)(param_2 + 0x20))))) {
    printf((char *)(DAT_0001344c + 0x133f6),uVar1,*(uint *)(param_2 + 0x28),uVar1,
           *(uint *)(param_2 + 0x20),uVar2);
  }
  else {
    printf(PTR_LAB_0001345c + 0x1343e);
  }
  __s = (FILE *)(*(int *)(iVar3 + DAT_00013450) + 0x54);
  fwrite(PTR_LAB_00013454 + 0x1340a,1,0xf,__s);
  FUN_0001325c(param_2 + 0x20);
  fwrite(PTR_FUN_00013458 + 0x13424,1,0x14,__s);
  FUN_000132cc(param_2 + 0x20);
  return;
}



/* Function: FUN_0001369c @ 0001369c */

int FUN_0001369c(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = ~(param_1 << 0x18 | param_1 >> 0x18 | (param_1 & 0xff00) << 8 | (param_1 & 0xff0000) >> 8)
  ;
  iVar2 = 0;
  iVar1 = 0x20;
  if (uVar3 != 0) {
    do {
      uVar3 = uVar3 >> 1;
      iVar2 = iVar2 + 1;
    } while (uVar3 != 0);
    iVar1 = 0x20 - iVar2;
  }
  return iVar1;
}



/* Function: FUN_000136d0 @ 000136d0 */

int FUN_000136d0(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    for (uVar1 = ~(uVar1 << 0x18 | uVar1 >> 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8);
        uVar1 != 0; uVar1 = uVar1 >> 1) {
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  return 0x80 - iVar2;
}



/* Function: FUN_00013710 @ 00013710 */

void FUN_00013710(void)

{
  FUN_000232e4(DAT_00013720 + 0x1371a,2);
  return;
}



/* Function: FUN_00013724 @ 00013724 */

void FUN_00013724(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_2 + 0x34) == 0) {
    iVar2 = DAT_00013750 + 0x13736;
  }
  else {
    iVar2 = (int)&DAT_00013750 + DAT_00013758;
  }
  uVar3 = *(undefined4 *)(param_2 + 0x30);
  uVar1 = FUN_000136d0();
  printf((char *)(DAT_00013754 + 0x13746),iVar2,uVar3,uVar1);
  return;
}



/* Function: FUN_00013794 @ 00013794 */

void FUN_00013794(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_2 + 0x34) == 0) {
    puVar2 = PTR_DAT_000137c4 + 0x137a6;
  }
  else {
    puVar2 = PTR_DAT_000137cc + 0x137c2;
  }
  uVar3 = *(undefined4 *)(param_2 + 0x30);
  uVar1 = FUN_0001369c(*(undefined4 *)(param_2 + 0x20));
  printf(PTR_LAB_000137c8 + 0x137b8,puVar2,uVar3,uVar1);
  return;
}



/* Function: FUN_000137d0 @ 000137d0 */

void FUN_000137d0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  uVar1 = FUN_0001369c(*(undefined4 *)(param_2 + 0x20));
  if (*(int *)(param_2 + 0x34) == 0) {
    puVar2 = PTR_LAB_000137fc + 0x137ea;
  }
  else {
    puVar2 = PTR_LAB_00013804 + 0x137fa;
  }
  printf(PTR_LAB_00013800 + 0x137f0,uVar1,puVar2,*(undefined4 *)(param_2 + 0x30));
  return;
}



/* Function: FUN_00013808 @ 00013808 */

undefined4
FUN_00013808(int param_1,undefined4 param_2,uint param_3,uint *param_4,uint *param_5,int param_6)

{
  ulong uVar1;
  undefined4 uVar2;
  uint uVar3;
  int extraout_r3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint local_24 [2];
  char *local_1c [2];
  
  iVar4 = iRam00013a40 + 0x13814;
  local_24[0] = param_3;
  if (param_1 == 0x41) {
    if ((*param_4 & 1) == 0) {
      *param_4 = *param_4 | 1;
      puVar6 = *(undefined4 **)(iVar4 + iRam00013a44);
      FUN_00021dc4(*puVar6,local_24,*(undefined4 *)(iVar4 + iRam00013a48),0,param_2);
      uVar1 = strtoul((char *)*puVar6,(char **)0x0,0);
      param_5[4] = uVar1;
      param_5[5] = local_24[0];
      return 1;
    }
    goto LAB_00013a30;
  }
  if (param_1 != 0x4d) {
    return 0;
  }
  if ((*param_4 & 2) == 0) {
    *param_4 = *param_4 | 2;
    uVar1 = strtoul((char *)**(undefined4 **)(iVar4 + iRam00013a44),local_1c,0);
    if (param_6 != 10) {
      if (((int)uVar1 < 0x21) && (*local_1c[0] == '\0')) {
        uVar3 = 0;
        if (uVar1 != 0) {
          uVar3 = -1 << (0x20 - uVar1 & 0xff);
          uVar3 = uVar3 >> 0x18 | uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | (uVar3 & 0xff0000) >> 8;
        }
        *param_5 = uVar3;
        return 1;
      }
      (**(code **)(**(int **)(iVar4 + iRam00013a4c) + 0x14))(2,iRam00013a50 + 0x13a0c);
      goto LAB_00013a10;
    }
    if (((int)uVar1 < 0x81) && (*local_1c[0] == '\0')) {
      if (uVar1 == 0) {
        param_5[3] = 0;
        param_5[2] = 0;
        param_5[1] = 0;
        *param_5 = 0;
        uVar3 = 0;
      }
      else if (uVar1 < 0x21) {
        uVar3 = *param_5 << (0x20 - uVar1 & 0xff);
        *param_5 = uVar3;
        param_5[3] = 0;
        param_5[2] = 0;
        param_5[1] = 0;
        uVar3 = uVar3 << 0x18 | uVar3 >> 0x18 | (uVar3 & 0xff00) << 8 | (uVar3 & 0xff0000) >> 8;
      }
      else {
        if (uVar1 < 0x41) {
          param_5[1] = param_5[1] << (0x40 - uVar1 & 0xff);
          param_5[3] = 0;
          param_5[2] = 0;
        }
        else if (uVar1 < 0x61) {
          param_5[2] = param_5[2] << (0x60 - uVar1 & 0xff);
          param_5[3] = 0;
        }
        else if (uVar1 < 0x81) {
          param_5[3] = param_5[3] << (0x80 - uVar1 & 0xff);
        }
        uVar3 = *param_5;
        uVar3 = uVar3 << 0x18 | uVar3 >> 0x18 | (uVar3 & 0xff00) << 8 | (uVar3 & 0xff0000) >> 8;
      }
      *param_5 = uVar3;
      uVar3 = param_5[1];
      param_5[1] = uVar3 >> 0x18 | uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | (uVar3 & 0xff0000) >> 8;
      uVar3 = param_5[2];
      param_5[2] = uVar3 >> 0x18 | uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | (uVar3 & 0xff0000) >> 8;
      uVar3 = param_5[3];
      param_5[3] = uVar3 >> 0x18 | uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | (uVar3 & 0xff0000) >> 8;
      return 1;
    }
  }
  else {
LAB_00013a10:
    (**(code **)(**(int **)(iVar4 + iRam00013a4c) + 0x14))(2,iRam00013a54 + 0x13a1c);
  }
  (**(code **)(**(int **)(iVar4 + iRam00013a4c) + 0x14))(2,iRam00013a58 + 0x13a2c);
LAB_00013a30:
  iVar4 = (**(code **)(**(int **)(iVar4 + iRam00013a4c) + 0x14))(2,iRam00013a5c + 0x13a3c);
  iVar5 = extraout_r3 * 0x80;
  *(undefined4 *)(iVar5 + 0xc) = 0xc00;
  *(int *)(iVar4 + extraout_r3) = iVar5;
  *(int *)((int)param_5 + extraout_r3) = iVar5;
  *(undefined4 *)(iVar4 + 0xc00) = 0xc00;
  FUN_00013808(0xc00,0xc00);
                    /* WARNING: Could not recover jumptable at 0x00013a76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)0x13a41)();
  return uVar2;
}



/* Function: FUN_00013a78 @ 00013a78 */

void FUN_00013a78(void)

{
  FUN_00013808();
  return;
}



/* Function: FUN_00013a90 @ 00013a90 */

void FUN_00013a90(int param_1)

{
  memset((void *)(param_1 + 0x20),0xff,0x10);
  return;
}



/* Function: FUN_00013ad4 @ 00013ad4 */

void FUN_00013ad4(void)

{
  FUN_000232e4(DAT_00013ae4 + 0x13ade,2);
  return;
}



/* Function: FUN_00013ae8 @ 00013ae8 */

void FUN_00013ae8(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x28) != '\0') {
    printf((char *)(DAT_00013b30 + 0x13b20));
  }
  printf((char *)(DAT_00013b24 + 0x13afc));
  if (*(int *)(param_2 + 0x24) == -1) {
    printf((char *)(DAT_00013b2c + 0x13b16),*(undefined4 *)(param_2 + 0x20));
  }
  else {
    printf((char *)(DAT_00013b28 + 0x13b0c),*(undefined4 *)(param_2 + 0x20));
  }
  return;
}



/* Function: FUN_00013b80 @ 00013b80 */

void FUN_00013b80(undefined4 param_1,int param_2)

{
  printf(PTR_LAB_00013bbc + 0x13b8c);
  if (*(char *)(param_2 + 0x28) != '\0') {
    putchar(0x21);
  }
  if (*(int *)(param_2 + 0x24) == -1) {
    printf(PTR_DAT_000153c0_2_00013bc4 + 0x13bae,*(undefined4 *)(param_2 + 0x20));
  }
  else {
    printf(PTR_LAB_00015326_2_00013bc0 + 0x13ba4,*(undefined4 *)(param_2 + 0x20));
  }
  return;
}



/* Function: FUN_00013e34 @ 00013e34 */

void FUN_00013e34(void)

{
  FUN_00022d9c(DAT_00013e44 + 0x13e3e,2);
  return;
}



/* Function: FUN_00013e48 @ 00013e48 */

void FUN_00013e48(undefined4 param_1,int param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_2 + 0x2c);
  if (cVar1 == '\x01') {
    printf((char *)(DAT_00013e98 + 0x13e7e),*(undefined4 *)(param_2 + 0x28),
           *(undefined4 *)(param_2 + 0x24));
  }
  else if (cVar1 == '\0') {
    printf((char *)(DAT_00013e94 + 0x13e70),*(undefined4 *)(param_2 + 0x20),
           *(undefined4 *)(param_2 + 0x24));
  }
  else if (cVar1 == '\x02') {
    printf((char *)(DAT_00013e9c + 0x13e8c),*(undefined4 *)(param_2 + 0x28),
           *(undefined4 *)(param_2 + 0x24));
  }
  else {
    printf((char *)(DAT_00013e90 + 0x13e62));
  }
  return;
}



/* Function: FUN_00013ea0 @ 00013ea0 */

void FUN_00013ea0(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_2 + 0x2c);
  if (cVar1 == '\x01') {
    if (*(int *)(param_2 + 0x28) == -1) {
      if (*(int *)(param_2 + 0x24) == -1) {
        printf(PTR_LAB_00013f7c + 0x13f24);
        return;
      }
    }
    else if (*(int *)(param_2 + 0x28) == *(int *)(param_2 + 0x24)) {
      printf(PTR_LAB_00013f88 + 0x13f46);
      return;
    }
    printf(PTR_LAB_00013f70 + 0x13eee);
  }
  else if (cVar1 == '\0') {
    if (*(int *)(param_2 + 0x20) == 0) {
      printf(PTR_LAB_00013f80 + 0x13f32,~*(uint *)(param_2 + 0x24));
    }
    else {
      iVar2 = *(int *)(param_2 + 0x24);
      if (*(int *)(param_2 + 0x20) == iVar2) {
        printf(PTR_LAB_00013f94 + 0x13f64);
      }
      else if (iVar2 == 0) {
        printf(PTR_LAB_00013f90 + 0x13f5a);
      }
      else if (iVar2 == -1) {
        printf(PTR_LAB_00013f8c + 0x13f50);
      }
      else {
        printf(PTR_LAB_00013f6c + 0x13ed8);
      }
    }
  }
  else if (cVar1 == '\x02') {
    if (*(int *)(param_2 + 0x24) == -1) {
      if (*(int *)(param_2 + 0x28) == -1) {
        printf(PTR_LAB_00013f78 + 0x13f14);
        return;
      }
    }
    else if (*(int *)(param_2 + 0x24) == *(int *)(param_2 + 0x28)) {
      printf(PTR_LAB_00013f84 + 0x13f3c);
      return;
    }
    printf(PTR_DAT_00013f74 + 0x13f04);
  }
  else {
    printf(PTR_LAB_00013f68 + 0x13eba);
  }
  return;
}



/* Function: FUN_00013f98 @ 00013f98 */

undefined4 FUN_00013f98(int param_1)

{
  undefined4 uVar1;
  
  if (0x56 < param_1 - 0x26U) {
    return 0;
  }
                    /* WARNING: Could not emulate address calculation at 0x00013fda */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(PTR_LAB_000142a0 +
                    *(int *)(PTR_LAB_000142a0 + (param_1 - 0x26U) * 4 + 0x13fdc) + 0x13fdc))();
  return uVar1;
}



/* Function: FUN_00014308 @ 00014308 */

void FUN_00014308(void)

{
  puts((char *)(DAT_00014314 + 0x14310));
  return;
}



/* Function: FUN_00014688 @ 00014688 */

void FUN_00014688(void)

{
  FUN_00022bd8(DAT_00014694 + 0x14690);
  return;
}



/* Function: FUN_00014698 @ 00014698 */

void FUN_00014698(char *param_1)

{
  if (*param_1 != '\x01') {
    if (*param_1 == '\x02') {
      printf(PTR_LAB_000146d8 + 0x146c6);
      return;
    }
    (**(code **)(**(int **)(PTR_LAB_000146cc + 0x146ae) + 0x14))(1,PTR_LAB_000146d0 + 0x146b2);
  }
  printf(PTR_LAB_000146d4 + 0x146bc);
  return;
}



/* Function: FUN_00014748 @ 00014748 */

void FUN_00014748(void)

{
  FUN_000232e4(DAT_00014758 + 0x14752,5);
  return;
}



/* Function: FUN_0001475c @ 0001475c */

void FUN_0001475c(int param_1)

{
  int iVar1;
  
  if (param_1 << 0x1f < 0) {
    printf((char *)(DAT_00014818 + 0x147de),DAT_0001481c + 0x147e0);
    iVar1 = (int)&DAT_000147e8 + DAT_00014820;
  }
  else {
    iVar1 = DAT_000147e8 + 0x1476a;
  }
  if (param_1 << 0x1c < 0) {
    printf((char *)(DAT_00014810 + 0x147ce),iVar1);
    iVar1 = DAT_00014814 + 0x147d6;
  }
  if (param_1 << 0x1d < 0) {
    printf((char *)(DAT_00014808 + 0x147c0),iVar1);
    iVar1 = DAT_0001480c + 0x147c8;
  }
  if (param_1 << 0x1e < 0) {
    printf((char *)(DAT_00014800 + 0x147b2),iVar1);
    iVar1 = DAT_00014804 + 0x147ba;
  }
  if (param_1 << 0x17 < 0) {
    printf((char *)(DAT_000147f8 + 0x147a4),iVar1);
    iVar1 = DAT_000147fc + 0x147ac;
  }
  if (param_1 << 0x19 < 0) {
    printf((char *)(DAT_000147f0 + 0x14796),iVar1);
    iVar1 = DAT_000147f4 + 0x1479e;
  }
  if (param_1 << 0x18 < 0) {
    printf((char *)(DAT_000147ec + 0x14786),iVar1);
  }
  putchar(0x20);
  return;
}



/* Function: FUN_00014824 @ 00014824 */

void FUN_00014824(int param_1)

{
  undefined *puVar1;
  
  if (param_1 << 0x1f < 0) {
    printf((char *)(DAT_000148a4 + 0x1487e),DAT_000148a8 + 0x14880);
    puVar1 = (undefined *)((int)&PTR_DAT_00014888 + DAT_000148ac);
  }
  else {
    puVar1 = PTR_DAT_00014888 + 0x14832;
  }
  if (param_1 << 0x1e < 0) {
    printf(PTR_LAB_0001489c + 0x1486e,puVar1);
    puVar1 = (undefined *)(DAT_000148a0 + 0x14876);
  }
  if (param_1 << 0x1d < 0) {
    printf(PTR_LAB_00014894 + 0x14860,puVar1);
    puVar1 = PTR_DAT_00014898 + 0x14868;
  }
  if (param_1 << 0x1c < 0) {
    printf(PTR_LAB_000151f0_2_00014890 + 0x14856,puVar1);
  }
  else if (param_1 == 0) {
    printf(PTR_LAB_0001488c + 0x14846,puVar1);
  }
  putchar(0x20);
  return;
}



/* Function: FUN_000148b0 @ 000148b0 */

int * FUN_000148b0(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *unaff_r6;
  
  if (param_3 == 2) {
    if (param_4 == 0) {
      if (*param_1 == 0) {
        param_1 = (int *)printf(PTR_LAB_00014974 + 0x1495c);
      }
      else {
        uVar1 = FUN_00022194();
        uVar2 = FUN_00021f94(param_2);
        param_1 = (int *)printf(PTR_LAB_00014964 + 0x14904,uVar1,uVar2);
      }
    }
    else {
      uVar1 = FUN_00021f64();
      uVar2 = FUN_00021f94(param_2);
      param_1 = (int *)printf(PTR_LAB_00014968 + 0x1491e,uVar1,uVar2);
    }
  }
  else if (param_3 == 10) {
    if (param_4 != 0) {
      FUN_00022018();
      FUN_00022030(param_2);
      return (int *)*unaff_r6;
    }
    if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) && (param_1[3] == 0)) {
      param_1 = (int *)printf(PTR_LAB_00014960 + 0x148e0);
    }
    else {
      uVar1 = FUN_00022114();
      uVar2 = FUN_00022030(param_2);
      param_1 = (int *)printf(PTR_LAB_00014970 + 0x14952,uVar1,uVar2);
    }
  }
  return param_1;
}



/* Function: FUN_00014978 @ 00014978 */

void FUN_00014978(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  ushort uVar2;
  uint uVar3;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  undefined4 uVar4;
  
  uVar2 = *(ushort *)(param_1 + 0x92);
  uVar1 = 1;
  uVar4 = param_4;
  if ((uVar2 & 1) != 0) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x94);
    if ((*(ushort *)(param_1 + 0x94) & 1) != 0) {
      printf(PTR_DAT_00014c84 + 0x14bca);
      uVar1 = extraout_r2;
      uVar3 = extraout_r3;
    }
    printf(PTR_LAB_00014c44 + 0x1499e,param_2,uVar1,uVar3,uVar4);
    FUN_0001475c(*(undefined2 *)(param_1 + 0x96));
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  if ((uVar2 & 2) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 2) != 0) {
      printf(PTR_DAT_00014c88 + 0x14bd4);
    }
    printf(PTR_LAB_00014c48 + 0x149c6,param_2,(uint)*(ushort *)(param_1 + 0x88),0x88,uVar4);
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  uVar1 = 4;
  if ((uVar2 & 4) != 0) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x94);
    if ((*(ushort *)(param_1 + 0x94) & 4) != 0) {
      printf(PTR_DAT_00014c8c + 0x14bde);
      uVar1 = extraout_r2_00;
      uVar3 = extraout_r3_00;
    }
    printf(PTR_LAB_00014c4c + 0x149e6,param_2,uVar1,uVar3,uVar4);
    FUN_000148b0(param_1,param_1 + 0x10,param_3,param_4);
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  uVar1 = 8;
  if ((uVar2 & 8) != 0) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x94);
    if ((*(ushort *)(param_1 + 0x94) & 8) != 0) {
      printf(PTR_DAT_00014c90 + 0x14be8);
      uVar1 = extraout_r2_01;
      uVar3 = extraout_r3_01;
    }
    printf(PTR_LAB_00014c50 + 0x14a12,param_2,uVar1,uVar3,uVar4);
    FUN_000148b0(param_1 + 0x20,param_1 + 0x30,param_3,param_4);
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  if ((uVar2 & 0x10) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 0x10) != 0) {
      printf(PTR_DAT_00014c94 + 0x14bf2);
    }
    printf(PTR_FUN_00014c54 + 0x14a40,param_2);
    FUN_000148b0(param_1 + 0x40,param_1 + 0x50,param_3,param_4);
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  if ((uVar2 & 0x20) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 0x20) != 0) {
      printf(PTR_DAT_00014c98 + 0x14bfc);
    }
    printf(PTR_LAB_00014c58 + 0x14a6e,param_2);
    FUN_000148b0(param_1 + 0x60,param_1 + 0x70,param_3,param_4);
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  if ((uVar2 & 0x100) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 0x100) != 0) {
      printf(PTR_DAT_00014c9c + 0x14c06);
    }
    printf(PTR_LAB_00014c5c + 0x14aaa,param_2,
           (*(ushort *)(param_1 + 0x8a) & 0xff) << 8 | (uint)(*(ushort *)(param_1 + 0x8a) >> 8));
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  if ((uVar2 & 0x200) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 0x200) != 0) {
      printf(PTR_DAT_00014ca0 + 0x14c10);
    }
    printf(PTR_LAB_00014c60 + 0x14ad8,param_2,
           (*(ushort *)(param_1 + 0x8c) & 0xff) << 8 | (uint)(*(ushort *)(param_1 + 0x8c) >> 8));
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  if ((uVar2 & 0x400) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 0x400) != 0) {
      printf(PTR_DAT_00014ca4 + 0x14c1a);
    }
    printf(PTR_LAB_00014c64 + 0x14b06,param_2,
           (*(ushort *)(param_1 + 0x8e) & 0xff) << 8 | (uint)(*(ushort *)(param_1 + 0x8e) >> 8));
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  if ((uVar2 & 0x800) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 0x800) != 0) {
      printf(PTR_DAT_00014ca8 + 0x14c24);
    }
    printf(PTR_LAB_00014fca_2_00014c68 + 0x14b34,param_2,
           (*(ushort *)(param_1 + 0x90) & 0xff) << 8 | (uint)(*(ushort *)(param_1 + 0x90) >> 8));
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  if ((uVar2 & 0x40) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 0x40) != 0) {
      printf(PTR_DAT_00014cac + 0x14c2e);
    }
    printf(PTR_LAB_00014c6c + 0x14b54,param_2);
    FUN_00014824(*(undefined2 *)(param_1 + 0x98));
    uVar2 = *(ushort *)(param_1 + 0x92);
  }
  if ((uVar2 & 0x80) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 0x80) != 0) {
      printf(PTR_DAT_00014c80 + 0x14bc0);
    }
    printf(PTR_PTR_00014c70 + 0x14b78,param_2);
    if (*(int *)(param_1 + 0x84) == *(int *)(param_1 + 0x80)) {
      printf(PTR_DAT_00014cb0 + 0x14c3a,*(int *)(param_1 + 0x84));
      uVar2 = *(ushort *)(param_1 + 0x92);
    }
    else {
      printf(PTR_LAB_00014c74 + 0x14b8c);
      uVar2 = *(ushort *)(param_1 + 0x92);
    }
  }
  if ((uVar2 & 0x1000) != 0) {
    if ((*(ushort *)(param_1 + 0x94) & 0x1000) == 0) {
      printf(PTR_LAB_00014c78 + 0x14baa,param_2);
    }
    else {
      printf(PTR_LAB_00014c7c + 0x14bb6,param_2);
    }
  }
  return;
}



/* Function: FUN_00014cb4 @ 00014cb4 */

void FUN_00014cb4(undefined4 param_1,int param_2)

{
  FUN_00014978(param_2 + 0x20,DAT_00014cc8 + 0x14cc2,10,1);
  return;
}



/* Function: FUN_00014ccc @ 00014ccc */

void FUN_00014ccc(undefined4 param_1,int param_2,int param_3)

{
  FUN_00014978(param_2 + 0x20,DAT_00014ce4 + 0x14cde,10,param_3 != 0);
  return;
}



/* Function: FUN_00014d00 @ 00014d00 */

void FUN_00014d00(undefined4 param_1,int param_2,int param_3)

{
  FUN_00014978(param_2 + 0x20,DAT_00014d18 + 0x14d12,2,param_3 != 0);
  return;
}



/* Function: FUN_00014d70 @ 00014d70 */

void FUN_00014d70(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined1 auStack_b8 [150];
  ushort uStack_22;
  ushort uStack_20;
  int local_1c;
  
  piVar1 = *(int **)(DAT_00014dc8 + 0x14d80);
  local_1c = *piVar1;
  memcpy(auStack_b8,(void *)(param_2 + 0x20),0x96);
  uStack_22 = (ushort)*(byte *)(param_2 + 0xb6);
  uStack_20 = (ushort)*(byte *)(param_2 + 0xb7);
  FUN_00014978(auStack_b8,DAT_00014dcc + 0x14da6,10,param_3 != 0);
  if (local_1c == *piVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00014e24 @ 00014e24 */

void FUN_00014e24(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined1 auStack_b8 [150];
  ushort uStack_22;
  ushort uStack_20;
  int local_1c;
  
  piVar1 = *(int **)(DAT_00014e7c + 0x14e34);
  local_1c = *piVar1;
  memcpy(auStack_b8,(void *)(param_2 + 0x20),0x96);
  uStack_22 = (ushort)*(byte *)(param_2 + 0xb6);
  uStack_20 = (ushort)*(byte *)(param_2 + 0xb7);
  FUN_00014978(auStack_b8,DAT_00014e80 + 0x14e5a,2,param_3 != 0);
  if (local_1c == *piVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00014e84 @ 00014e84 */

undefined4 FUN_00014e84(undefined4 param_1)

{
  int iVar1;
  char *__s1;
  undefined4 uVar2;
  undefined4 local_c;
  
  iVar1 = FUN_000224cc(param_1,0,&local_c,0,0xffffffff);
  if (iVar1 != 0) {
    return local_c;
  }
  __s1 = (char *)(**(code **)(**(int **)(iRam00014eb8 + 0x14eae) + 0x14))
                           (2,iRam00014ebc + 0x14eb2,param_1);
  iVar1 = strncasecmp(__s1,(char *)(DAT_00014fa0 + 0x14ece),(size_t)__s1);
  if (iVar1 == 0) {
    uVar2 = 1;
    *(ushort *)(__s1 + 0x96) = *(ushort *)(__s1 + 0x96) | 1;
  }
  else {
    iVar1 = strncasecmp(__s1,(char *)(DAT_00014fa4 + 0x14ee0),(size_t)__s1);
    if (iVar1 == 0) {
      uVar2 = 1;
      *(ushort *)(__s1 + 0x96) = *(ushort *)(__s1 + 0x96) | 8;
    }
    else {
      iVar1 = strncasecmp(__s1,PTR_PTR_00014fa8 + 0x14ef0,(size_t)__s1);
      if (iVar1 == 0) {
        uVar2 = 1;
        *(ushort *)(__s1 + 0x96) = *(ushort *)(__s1 + 0x96) | 2;
      }
      else {
        iVar1 = strncasecmp(__s1,PTR_PTR_00014fac + 0x14f00,(size_t)__s1);
        if (iVar1 == 0) {
          uVar2 = 1;
          *(ushort *)(__s1 + 0x96) = *(ushort *)(__s1 + 0x96) | 4;
        }
        else {
          iVar1 = strncasecmp(__s1,PTR_PTR_00014fb0 + 0x14f10,(size_t)__s1);
          if (iVar1 == 0) {
            *(ushort *)(__s1 + 0x96) = *(ushort *)(__s1 + 0x96) | 0x100;
            uVar2 = 1;
          }
          else {
            iVar1 = strncasecmp(__s1,PTR_DAT_00014fb4 + 0x14f20,(size_t)__s1);
            if (iVar1 == 0) {
              uVar2 = 1;
              *(ushort *)(__s1 + 0x96) = *(ushort *)(__s1 + 0x96) | 0x40;
            }
            else {
              iVar1 = strncasecmp(__s1,(char *)(DAT_00014fb8 + 0x14f30),(size_t)__s1);
              uVar2 = 0;
              if (iVar1 == 0) {
                uVar2 = 1;
                *(ushort *)(__s1 + 0x96) = *(ushort *)(__s1 + 0x96) | 0x80;
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00014f54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)0x14eb9)(uVar2);
  return uVar2;
}



/* Function: FUN_00014ec0 @ 00014ec0 */

void FUN_00014ec0(int param_1,char *param_2,size_t param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = strncasecmp(param_2,(char *)(DAT_00014fa0 + 0x14ece),param_3);
  if (iVar1 == 0) {
    uVar2 = 1;
    *(ushort *)(param_1 + 0x96) = *(ushort *)(param_1 + 0x96) | 1;
  }
  else {
    iVar1 = strncasecmp(param_2,(char *)(DAT_00014fa4 + 0x14ee0),param_3);
    if (iVar1 == 0) {
      uVar2 = 1;
      *(ushort *)(param_1 + 0x96) = *(ushort *)(param_1 + 0x96) | 8;
    }
    else {
      iVar1 = strncasecmp(param_2,PTR_PTR_00014fa8 + 0x14ef0,param_3);
      if (iVar1 == 0) {
        uVar2 = 1;
        *(ushort *)(param_1 + 0x96) = *(ushort *)(param_1 + 0x96) | 2;
      }
      else {
        iVar1 = strncasecmp(param_2,PTR_PTR_00014fac + 0x14f00,param_3);
        if (iVar1 == 0) {
          uVar2 = 1;
          *(ushort *)(param_1 + 0x96) = *(ushort *)(param_1 + 0x96) | 4;
        }
        else {
          iVar1 = strncasecmp(param_2,PTR_PTR_00014fb0 + 0x14f10,param_3);
          if (iVar1 == 0) {
            *(ushort *)(param_1 + 0x96) = *(ushort *)(param_1 + 0x96) | 0x100;
            uVar2 = 1;
          }
          else {
            iVar1 = strncasecmp(param_2,PTR_DAT_00014fb4 + 0x14f20,param_3);
            if (iVar1 == 0) {
              uVar2 = 1;
              *(ushort *)(param_1 + 0x96) = *(ushort *)(param_1 + 0x96) | 0x40;
            }
            else {
              iVar1 = strncasecmp(param_2,(char *)(DAT_00014fb8 + 0x14f30),param_3);
              uVar2 = 0;
              if (iVar1 == 0) {
                uVar2 = 1;
                *(ushort *)(param_1 + 0x96) = *(ushort *)(param_1 + 0x96) | 0x80;
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00014f54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}



/* Function: FUN_00014fbc @ 00014fbc */

undefined4 FUN_00014fbc(int param_1,char *param_2,size_t param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strncasecmp(param_2,PTR_LAB_00015050 + 0x14fca,param_3);
  uVar2 = 1;
  if (iVar1 != 0) {
    iVar1 = strncasecmp(param_2,PTR_LAB_00015054 + 0x14fde,param_3);
    if (iVar1 == 0) {
      *(ushort *)(param_1 + 0x98) = *(ushort *)(param_1 + 0x98) | 1;
      uVar2 = 1;
    }
    else {
      iVar1 = strncasecmp(param_2,PTR_LAB_00015058 + 0x14fee,param_3);
      if (iVar1 == 0) {
        *(ushort *)(param_1 + 0x98) = *(ushort *)(param_1 + 0x98) | 2;
        uVar2 = 1;
      }
      else {
        iVar1 = strncasecmp(param_2,PTR_LAB_0001505c + 0x14ffe,param_3);
        if (iVar1 == 0) {
          *(ushort *)(param_1 + 0x98) = *(ushort *)(param_1 + 0x98) | 4;
          uVar2 = 1;
        }
        else {
          iVar1 = strncasecmp(param_2,(char *)(DAT_00015060 + 0x1500e),param_3);
          uVar2 = 0;
          if (iVar1 == 0) {
            *(ushort *)(param_1 + 0x98) = *(ushort *)(param_1 + 0x98) | 8;
            uVar2 = 1;
          }
        }
      }
    }
  }
  return uVar2;
}



/* Function: FUN_00015064 @ 00015064 */

undefined4 FUN_00015064(int param_1)

{
  undefined4 uVar1;
  
  if (0x34 < param_1 - 0x31U) {
    return 0;
  }
                    /* WARNING: Could not emulate address calculation at 0x00015090 */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(*(int *)((param_1 - 0x31U) * 4 + DAT_00015388 + 0x15092) +
                    DAT_00015388 + 0x15092))();
  return uVar1;
}



/* Function: FUN_000154cc @ 000154cc */

undefined4 FUN_000154cc(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_20;
  undefined4 *local_1c [2];
  
  iVar4 = DAT_00015628 + 0x154da;
  local_1c[0] = (undefined4 *)0x0;
  local_20 = 0;
  if (param_1 == 0x34) {
    FUN_00022eac(**(undefined4 **)(iVar4 + DAT_0001562c),local_1c,param_4 + 0xc,&local_20);
    if (local_20 < 2) {
      if (local_20 == 1) {
        uVar1 = local_1c[0][1];
        uVar5 = local_1c[0][2];
        param_4[8] = *local_1c[0];
        param_4[9] = uVar1;
        param_4[10] = uVar5;
        param_4[0xb] = local_1c[0][3];
      }
      uVar2 = 8;
    }
    else {
LAB_000155b6:
      (**(code **)(**(int **)(iVar4 + DAT_00015630) + 0x14))(2,PTR_LAB_00015638 + 0x155c2);
LAB_000155c6:
      (**(code **)(**(int **)(iVar4 + DAT_00015630) + 0x14))(2,PTR_DAT_0001563c + 0x155d2);
LAB_000155d6:
      (**(code **)(**(int **)(iVar4 + DAT_00015630) + 0x14))(2,PTR_DAT_00015640 + 0x155e2);
LAB_000155e6:
      uVar1 = local_1c[0][1];
      uVar5 = local_1c[0][2];
      param_4[0x10] = *local_1c[0];
      param_4[0x11] = uVar1;
      param_4[0x12] = uVar5;
      param_4[0x13] = local_1c[0][3];
LAB_00015542:
      uVar2 = 0x10;
    }
LAB_0001558a:
    uVar3 = *(ushort *)((int)param_4 + 0x92) | uVar2;
    *(ushort *)((int)param_4 + 0x92) = uVar3;
    if (param_2 != 0) {
      *(ushort *)(param_4 + 0x25) = uVar2 | *(ushort *)(param_4 + 0x25);
    }
    *param_3 = (uint)uVar3;
    uVar1 = 1;
  }
  else {
    if (param_1 < 0x35) {
      if (param_1 == 0x33) {
        FUN_00022eac(**(undefined4 **)(iVar4 + DAT_0001562c),local_1c,param_4 + 4,&local_20);
        if (1 < local_20) goto LAB_000155c6;
        if (local_20 == 1) {
          uVar1 = local_1c[0][1];
          uVar5 = local_1c[0][2];
          *param_4 = *local_1c[0];
          param_4[1] = uVar1;
          param_4[2] = uVar5;
          param_4[3] = local_1c[0][3];
        }
        uVar2 = 4;
        goto LAB_0001558a;
      }
    }
    else {
      if (param_1 == 0x35) {
        FUN_00022eac(**(undefined4 **)(iVar4 + DAT_0001562c),local_1c,param_4 + 0x14,&local_20);
        if (1 < local_20) {
          (**(code **)(**(int **)(iVar4 + DAT_00015630) + 0x14))(2,PTR_LAB_00015634 + 0x155b2);
          goto LAB_000155b6;
        }
        if (local_20 == 1) goto LAB_000155e6;
        goto LAB_00015542;
      }
      if (param_1 == 0x36) {
        FUN_00022eac(**(undefined4 **)(iVar4 + DAT_0001562c),local_1c,param_4 + 0x1c,&local_20);
        if (local_20 < 2) {
          if (local_20 == 1) {
            uVar1 = local_1c[0][1];
            uVar5 = local_1c[0][2];
            param_4[0x18] = *local_1c[0];
            param_4[0x19] = uVar1;
            param_4[0x1a] = uVar5;
            param_4[0x1b] = local_1c[0][3];
          }
          uVar2 = 0x20;
          goto LAB_0001558a;
        }
        goto LAB_000155d6;
      }
    }
    uVar1 = FUN_00015064(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* Function: FUN_00015644 @ 00015644 */

void FUN_00015644(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6)

{
  FUN_000154cc(param_1,param_3 != 0,param_4,*param_6 + 0x20);
  return;
}



/* Function: FUN_000156f8 @ 000156f8 */

undefined4 FUN_000156f8(char *param_1,size_t param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strncasecmp(param_1,(char *)(DAT_000157c8 + 0x15706),param_2);
  if (iVar1 == 0) {
    uVar2 = 1;
    *param_3 = *param_3 | 1;
  }
  else {
    iVar1 = strncasecmp(param_1,PTR_DAT_000157cc + 0x15718,param_2);
    if (iVar1 == 0) {
      uVar2 = 1;
      *param_3 = *param_3 | 8;
    }
    else {
      iVar1 = strncasecmp(param_1,PTR_DAT_000157d0 + 0x15728,param_2);
      if (iVar1 == 0) {
        uVar2 = 1;
        *param_3 = *param_3 | 2;
      }
      else {
        iVar1 = strncasecmp(param_1,PTR_DAT_000157d4 + 0x15738,param_2);
        if (iVar1 == 0) {
          uVar2 = 1;
          *param_3 = *param_3 | 4;
        }
        else {
          iVar1 = strncasecmp(param_1,PTR_DAT_000157d8 + 0x15748,param_2);
          if (iVar1 == 0) {
            *param_3 = *param_3 | 0x100;
            uVar2 = 1;
          }
          else {
            iVar1 = strncasecmp(param_1,PTR_DAT_000157dc + 0x15758,param_2);
            if (iVar1 == 0) {
              uVar2 = 1;
              *param_3 = *param_3 | 0x40;
            }
            else {
              iVar1 = strncasecmp(param_1,PTR_LAB_000157e0 + 0x15768,param_2);
              uVar2 = 0;
              if (iVar1 == 0) {
                uVar2 = 1;
                *param_3 = *param_3 | 0x80;
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}



/* Function: FUN_000157e4 @ 000157e4 */

undefined4 FUN_000157e4(char *param_1,size_t param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strncasecmp(param_1,PTR_DAT_00015854 + 0x157f2,param_2);
  uVar2 = 1;
  if (iVar1 != 0) {
    iVar1 = strncasecmp(param_1,PTR_DAT_00015858 + 0x15806,param_2);
    if (iVar1 == 0) {
      *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 1;
      uVar2 = 1;
    }
    else {
      iVar1 = strncasecmp(param_1,PTR_DAT_0001585c + 0x15816,param_2);
      if (iVar1 == 0) {
        *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 2;
        uVar2 = 1;
      }
      else {
        iVar1 = strncasecmp(param_1,PTR_DAT_00015860 + 0x15826,param_2);
        uVar2 = 0;
        if (iVar1 == 0) {
          *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 4;
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}



/* Function: FUN_00015864 @ 00015864 */

undefined4 FUN_00015864(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint local_20;
  undefined4 *local_1c [2];
  
  iVar4 = DAT_0001599c + 0x15872;
  local_1c[0] = (undefined4 *)0x0;
  local_20 = 0;
  if (param_1 == 0x34) {
    FUN_00023418(**(undefined4 **)(iVar4 + DAT_000159a0),local_1c,param_4 + 0xc,&local_20);
    if (local_20 < 2) {
      if (local_20 == 1) {
        param_4[8] = *local_1c[0];
      }
      uVar2 = 8;
    }
    else {
LAB_0001594c:
      (**(code **)(**(int **)(iVar4 + DAT_000159a4) + 0x14))(2,PTR_DAT_000159ac + 0x15958);
LAB_0001595c:
      (**(code **)(**(int **)(iVar4 + DAT_000159a4) + 0x14))(2,PTR_DAT_000159b0 + 0x15968);
LAB_0001596c:
      (**(code **)(**(int **)(iVar4 + DAT_000159a4) + 0x14))(2,PTR_DAT_000159b4 + 0x15978);
LAB_0001597c:
      param_4[0x10] = *local_1c[0];
LAB_000158d8:
      uVar2 = 0x10;
    }
LAB_00015920:
    uVar3 = *(ushort *)((int)param_4 + 0x92) | uVar2;
    *(ushort *)((int)param_4 + 0x92) = uVar3;
    if (param_2 != 0) {
      *(ushort *)(param_4 + 0x25) = uVar2 | *(ushort *)(param_4 + 0x25);
    }
    *param_3 = (uint)uVar3;
    uVar1 = 1;
  }
  else {
    if (param_1 < 0x35) {
      if (param_1 == 0x33) {
        FUN_00023418(**(undefined4 **)(iVar4 + DAT_000159a0),local_1c,param_4 + 4,&local_20);
        if (1 < local_20) goto LAB_0001595c;
        if (local_20 == 1) {
          *param_4 = *local_1c[0];
        }
        uVar2 = 4;
        goto LAB_00015920;
      }
    }
    else {
      if (param_1 == 0x35) {
        FUN_00023418(**(undefined4 **)(iVar4 + DAT_000159a0),local_1c,param_4 + 0x14,&local_20);
        if (1 < local_20) {
          (**(code **)(**(int **)(iVar4 + DAT_000159a4) + 0x14))(2,PTR_DAT_000159a8 + 0x15948);
          goto LAB_0001594c;
        }
        if (local_20 == 1) goto LAB_0001597c;
        goto LAB_000158d8;
      }
      if (param_1 == 0x36) {
        FUN_00023418(**(undefined4 **)(iVar4 + DAT_000159a0),local_1c,param_4 + 0x1c,&local_20);
        if (local_20 < 2) {
          if (local_20 == 1) {
            param_4[0x18] = *local_1c[0];
          }
          uVar2 = 0x20;
          goto LAB_00015920;
        }
        goto LAB_0001596c;
      }
    }
    uVar1 = FUN_00015064(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* Function: FUN_000159b8 @ 000159b8 */

void FUN_000159b8(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6)

{
  FUN_00015864(param_1,param_3 != 0,param_4,*param_6 + 0x20);
  return;
}



/* Function: FUN_00015f1c @ 00015f1c */

void FUN_00015f1c(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *__dest;
  
  iVar2 = DAT_00015fa0;
  iVar1 = DAT_00015f9c;
  iVar4 = DAT_00015fa4 + 0x15f2e;
  *(undefined4 *)(&stack0xffffffec + DAT_00015fa8 + DAT_00015f9c) =
       **(undefined4 **)(iVar4 + DAT_00015fa0);
  if (param_3 == 0) {
    if (*param_2 == 0) {
      printf((char *)(DAT_00015fb4 + 0x15f94),DAT_00015fb8 + 0x15f96);
      goto LAB_00015f64;
    }
    pcVar3 = (char *)FUN_00022194();
    __dest = &stack0xfffffff0 + iVar1;
    strcpy(__dest,pcVar3);
  }
  else {
    pcVar3 = (char *)FUN_00021f64();
    __dest = &stack0xfffffff0 + iVar1;
    strcpy(__dest,pcVar3);
  }
  pcVar3 = (char *)FUN_00021f94(param_2);
  strcat(__dest,pcVar3);
  printf((char *)(DAT_00015fac + 0x15f62),__dest);
LAB_00015f64:
  if (*(int *)(&stack0xffffffec + DAT_00015fa8 + iVar1) == **(int **)(iVar4 + iVar2)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00015fbc @ 00015fbc */

void FUN_00015fbc(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  uint uVar3;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_2 + 0x60);
  uVar2 = 1;
  uVar4 = param_4;
  if ((bVar1 & 1) != 0) {
    uVar3 = (uint)*(byte *)(param_2 + 0x61);
    if ((*(byte *)(param_2 + 0x61) & 1) != 0) {
      printf((char *)(DAT_00016198 + 0x16118));
      uVar2 = extraout_r2;
      uVar3 = extraout_r3;
    }
    printf((char *)(DAT_00016170 + 0x15fe4),param_4,uVar2,uVar3,uVar4);
    FUN_0001475c(*(undefined4 *)(param_2 + 0x20));
    bVar1 = *(byte *)(param_2 + 0x60);
  }
  uVar2 = 2;
  if ((bVar1 & 2) != 0) {
    uVar3 = (uint)*(byte *)(param_2 + 0x61);
    if ((*(byte *)(param_2 + 0x61) & 2) != 0) {
      printf((char *)(DAT_0001619c + 0x16122));
      uVar2 = extraout_r2_00;
      uVar3 = extraout_r3_00;
    }
    printf((char *)(DAT_00016174 + 0x16008),param_4,uVar2,uVar3,uVar4);
    printf((char *)(DAT_00016178 + 0x16012),(uint)*(ushort *)(param_2 + 0x36));
    bVar1 = *(byte *)(param_2 + 0x60);
  }
  uVar2 = 4;
  if ((bVar1 & 4) != 0) {
    uVar3 = (uint)*(byte *)(param_2 + 0x61);
    if ((*(byte *)(param_2 + 0x61) & 4) != 0) {
      printf((char *)(DAT_000161a0 + 0x1612c));
      uVar2 = extraout_r2_01;
      uVar3 = extraout_r3_01;
    }
    printf((char *)(DAT_0001617c + 0x16030),param_4,uVar2,uVar3,uVar4);
    FUN_00015f1c(param_2 + 0x28,param_2 + 0x48,param_3);
    bVar1 = *(byte *)(param_2 + 0x60);
  }
  uVar2 = 8;
  if ((bVar1 & 8) != 0) {
    uVar3 = (uint)*(byte *)(param_2 + 0x61);
    if ((*(byte *)(param_2 + 0x61) & 8) != 0) {
      printf((char *)(DAT_000161a4 + 0x16136));
      uVar2 = extraout_r2_02;
      uVar3 = extraout_r3_02;
    }
    printf((char *)(DAT_00016180 + 0x1605c),param_4,uVar2,uVar3,uVar4);
    FUN_00015f1c(param_2 + 0x30,param_2 + 0x50,param_3);
    bVar1 = *(byte *)(param_2 + 0x60);
  }
  if ((bVar1 & 0x10) != 0) {
    if ((*(byte *)(param_2 + 0x61) & 0x10) != 0) {
      printf((char *)(DAT_000161a8 + 0x16140));
    }
    printf((char *)(DAT_00016184 + 0x16086),param_4);
    FUN_00015f1c(param_2 + 0x38,param_2 + 0x4c,param_3);
    bVar1 = *(byte *)(param_2 + 0x60);
  }
  if ((bVar1 & 0x20) != 0) {
    if ((*(byte *)(param_2 + 0x61) & 0x20) != 0) {
      printf((char *)(DAT_000161ac + 0x1614a));
    }
    printf((char *)(DAT_00016188 + 0x160b0),param_4);
    FUN_00015f1c(param_2 + 0x40,param_2 + 0x54,param_3);
    bVar1 = *(byte *)(param_2 + 0x60);
  }
  if ((bVar1 & 0x40) != 0) {
    if ((*(byte *)(param_2 + 0x61) & 0x40) != 0) {
      printf((char *)(DAT_000161b0 + 0x16154));
    }
    printf((char *)(DAT_0001618c + 0x160da),param_4);
    FUN_00014824(*(undefined4 *)(param_2 + 0x24));
    bVar1 = *(byte *)(param_2 + 0x60);
  }
  if ((int)((uint)bVar1 * 0x1000000) < 0) {
    if (0x7f < *(byte *)(param_2 + 0x61)) {
      printf((char *)(DAT_000161b8 + 0x1616a));
    }
    printf((char *)(DAT_00016190 + 0x160fe),param_4);
    if (*(int *)(param_2 + 0x5c) == *(int *)(param_2 + 0x58)) {
      printf((char *)(DAT_000161b4 + 0x16160),*(int *)(param_2 + 0x5c));
    }
    else {
      printf((char *)(DAT_00016194 + 0x1610e));
    }
  }
  return;
}



/* Function: FUN_000161bc @ 000161bc */

void FUN_000161bc(undefined4 param_1,undefined4 param_2)

{
  FUN_00015fbc(param_1,param_2,1,DAT_000161cc + 0x161c6);
  return;
}



/* Function: FUN_000161d0 @ 000161d0 */

void FUN_000161d0(void)

{
  FUN_00015fbc();
  return;
}



/* Function: FUN_000161e0 @ 000161e0 */

void FUN_000161e0(void)

{
  FUN_0002310c(DAT_000161ec + 0x161e8);
  return;
}



/* Function: FUN_000161f0 @ 000161f0 */

void FUN_000161f0(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  char *__format;
  uint uVar2;
  uint uVar3;
  char *__format_00;
  int iVar4;
  
  if (param_2 != 0) {
    printf((char *)(DAT_00016298 + 0x16282));
  }
  if (param_1 != 0) {
    bVar1 = false;
    __format_00 = (char *)(DAT_00016288 + 0x1621a);
    iVar4 = DAT_0001628c + 0x16220;
    __format = (char *)(DAT_00016290 + 0x16222);
    do {
      uVar2 = 0;
      uVar3 = DAT_00016294;
      if ((param_1 & 1) == 0) {
        do {
          uVar2 = uVar2 + 1;
        } while (((int)param_1 >> (uVar2 & 0xff) & 1U) == 0);
        uVar3 = ~(1 << (uVar2 & 0xff)) & 0xffff;
      }
      if (bVar1) {
        putchar(0x2c);
      }
      if (param_3 == 0) {
        printf(__format_00,*(undefined4 *)(uVar2 * 4 + iVar4));
      }
      else {
        printf(__format,uVar2);
      }
      bVar1 = true;
      param_1 = param_1 & uVar3;
    } while (param_1 != 0);
  }
  return;
}



/* Function: FUN_00016384 @ 00016384 */

void FUN_00016384(uint param_1,int param_2)

{
  servent *psVar1;
  
  if (((param_2 == 0) &&
      (psVar1 = getservbyport((param_1 << 8 | param_1 >> 8) & 0xffff,
                              (char *)(DAT_000163c0 + 0x1639c)), psVar1 != (servent *)0x0)) &&
     (psVar1->s_name != (char *)0x0)) {
    printf((char *)(DAT_000163c4 + 0x163ae));
  }
  else {
    printf((char *)(DAT_000163c8 + 0x163ba),param_1);
  }
  return;
}



/* Function: FUN_000163cc @ 000163cc */

void FUN_000163cc(undefined4 param_1,undefined *param_2,undefined *param_3,int param_4,
                 undefined4 param_5)

{
  undefined *puVar1;
  
  if (param_4 == 0) {
    puVar1 = PTR_DAT_00016448 + 0x163e0;
  }
  else {
    puVar1 = &UNK_00016446 + DAT_00016460;
  }
  if ((param_3 == PTR_LAB_0000fffe_1_0001644c) && (param_2 == (undefined *)0x0)) {
    if (param_4 == 0) {
      return;
    }
    printf(PTR_DAT_00016458 + 0x16416,param_1,PTR_LAB_0000fffe_1_0001644c,param_4,param_4);
  }
  else {
    printf(PTR_DAT_00016450 + 0x163ec,param_1,PTR_LAB_0000fffe_1_0001644c,param_4,param_4);
    if (param_2 == param_3) {
      printf(PTR_LAB_00016454 + 0x163fa,puVar1);
      FUN_00016384(param_2,param_5);
      goto LAB_00016438;
    }
  }
  printf((char *)(DAT_0001645c + 0x16420),puVar1);
  FUN_00016384(param_2,param_5);
  putchar(0x3a);
  FUN_00016384(param_3,param_5);
LAB_00016438:
  putchar(0x20);
  return;
}



/* Function: FUN_00016464 @ 00016464 */

void FUN_00016464(undefined4 param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  undefined *puVar2;
  
  printf(PTR_DAT_000164f0 + 0x16472);
  uVar1 = *(ushort *)(param_2 + 0x28);
  if ((uVar1 & 1) != 0) {
    FUN_000163cc(PTR_DAT_00016504 + 0x164e4,*(undefined2 *)(param_2 + 0x24),
                 *(undefined2 *)(param_2 + 0x26),*(ushort *)(param_2 + 0x2a) & 1,param_3);
    uVar1 = *(ushort *)(param_2 + 0x28);
  }
  if ((uVar1 & 2) != 0) {
    FUN_000163cc(PTR_DAT_00016500 + 0x164ce,*(undefined2 *)(param_2 + 0x20),
                 *(undefined2 *)(param_2 + 0x22),*(ushort *)(param_2 + 0x2a) & 2,param_3);
    uVar1 = *(ushort *)(param_2 + 0x28);
  }
  if ((uVar1 & 4) != 0) {
    FUN_000161f0(*(undefined2 *)(param_2 + 0x2c),*(ushort *)(param_2 + 0x2a) & 4,param_3);
    uVar1 = *(ushort *)(param_2 + 0x28);
  }
  if ((int)((uint)uVar1 << 0x1c) < 0) {
    if ((int)((uint)*(ushort *)(param_2 + 0x2a) << 0x1c) < 0) {
      puVar2 = PTR_LAB_000164f4 + 0x1649e;
    }
    else {
      if (*(char *)(param_2 + 0x2e) == '\0') {
        return;
      }
      puVar2 = PTR_DAT_000164fc + 0x164b2;
    }
    printf(PTR_DAT_000164f8 + 0x164a2,puVar2);
  }
  return;
}



/* Function: FUN_00016844 @ 00016844 */

void FUN_00016844(void)

{
  puts((char *)(DAT_00016850 + 0x1684c));
  return;
}



/* Function: FUN_00016878 @ 00016878 */

void FUN_00016878(void)

{
  FUN_0002310c(DAT_00016884 + 0x16880);
  return;
}



/* Function: FUN_00016888 @ 00016888 */

void FUN_00016888(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  
  if (*(char *)(param_2 + 0x21) == '\0') {
    puVar1 = (undefined *)(DAT_000168ac + 0x1689a);
  }
  else {
    puVar1 = &UNK_000168aa + DAT_000168b4;
  }
  printf((char *)(DAT_000168b0 + 0x168a0),puVar1,(uint)*(byte *)(param_2 + 0x20));
  return;
}



/* Function: FUN_000168b8 @ 000168b8 */

void FUN_000168b8(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  
  if (*(char *)(param_2 + 0x21) == '\0') {
    puVar1 = PTR_LAB_000168dc + 0x168ca;
  }
  else {
    puVar1 = PTR_LAB_000168e4 + 0x168da;
  }
  printf(PTR_DAT_000168e0 + 0x168d0,puVar1,(uint)*(byte *)(param_2 + 0x20));
  return;
}



/* Function: FUN_00016a7c @ 00016a7c */

void FUN_00016a7c(void)

{
  FUN_00022bd8(DAT_00016a88 + 0x16a84);
  return;
}



/* Function: FUN_00016a8c @ 00016a8c */

void FUN_00016a8c(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00016a9c + 0x16a98),(uint)*(byte *)(param_2 + 0x20));
  return;
}



/* Function: FUN_00016aa0 @ 00016aa0 */

void FUN_00016aa0(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00016abc + 0x16aaa));
  printf((char *)(DAT_00016ac0 + 0x16ab6),(uint)*(byte *)(param_2 + 0x20));
  return;
}



/* Function: FUN_00016c08 @ 00016c08 */

void FUN_00016c08(void)

{
  FUN_0002310c(DAT_00016c14 + 0x16c10);
  return;
}



/* Function: FUN_00016c18 @ 00016c18 */

void FUN_00016c18(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_2 + 0x20) != 0) || (*(int *)(param_2 + 0x24) != -1)) {
    if ((int)((uint)*(byte *)(param_2 + 0x28) << 0x1f) < 0) {
      iVar1 = DAT_00016c6c + 0x16c56;
    }
    else {
      iVar1 = DAT_00016c60 + 0x16c38;
    }
    printf((char *)(DAT_00016c64 + 0x16c3c),iVar1);
    if (*(int *)(param_2 + 0x20) == *(int *)(param_2 + 0x24)) {
      printf((char *)(DAT_00016c70 + 0x16c5c));
    }
    else {
      printf((char *)(DAT_00016c68 + 0x16c4c));
    }
  }
  return;
}



/* Function: FUN_00016c74 @ 00016c74 */

void FUN_00016c74(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  printf((char *)(DAT_00016ce4 + 0x16c82));
  bVar1 = *(byte *)(param_2 + 0x28);
  iVar3 = *(int *)(param_2 + 0x20);
  iVar4 = *(int *)(param_2 + 0x24);
  if ((bVar1 & 1) == 0) {
    puVar2 = (undefined *)(DAT_00016ce8 + 0x16c9a);
    if (iVar4 != -1) goto LAB_00016c9c;
LAB_00016cca:
    if (iVar3 != 0) goto LAB_00016c9c;
    if ((bVar1 & 1) == 0) goto LAB_00016cb0;
  }
  else {
    puVar2 = PTR_LAB_00016cf8 + 0x16cc8;
    if (iVar4 == -1) goto LAB_00016cca;
LAB_00016c9c:
    if (iVar3 == iVar4) {
      printf(PTR_DAT_00016cfc + 0x16cdc,PTR_LAB_00016d00 + 0x16cde,puVar2);
      bVar1 = *(byte *)(param_2 + 0x28);
      goto LAB_00016cb0;
    }
  }
  printf((char *)(DAT_00016cec + 0x16caa),PTR_DAT_00016cf0 + 0x16cac,puVar2,iVar3,iVar4);
  bVar1 = *(byte *)(param_2 + 0x28);
LAB_00016cb0:
  if ((bVar1 & 0xfe) != 0) {
    printf(PTR_DAT_00016cf4 + 0x16cbc);
  }
  return;
}



/* Function: FUN_00016fb4 @ 00016fb4 */

void FUN_00016fb4(void)

{
  FUN_000232e4(DAT_00016fc4 + 0x16fbe,3);
  return;
}



/* Function: FUN_00016fc8 @ 00016fc8 */

void FUN_00016fc8(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint extraout_r1;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 1;
  puVar4 = (uint *)(DAT_00017024 + 0x16fe4);
  do {
    uVar3 = *puVar4;
    if (uVar3 < param_1) break;
    uVar1 = __aeabi_uidiv(uVar3,param_1);
    __aeabi_uidivmod(uVar3,param_1);
    if (uVar1 < extraout_r1) break;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 2;
  } while (iVar5 != 4);
  iVar6 = (iVar5 + -1) * 8;
  iVar5 = DAT_00017028 + 0x17006;
  uVar2 = __aeabi_uidiv(*(undefined4 *)(iVar5 + iVar6 + 4),param_1);
  printf((char *)(DAT_0001702c + 0x17018),uVar2,*(undefined4 *)(iVar6 + iVar5));
  return;
}



/* Function: FUN_00017030 @ 00017030 */

void FUN_00017030(void)

{
  printf((char *)(DAT_00017040 + 0x1703a),5);
  return;
}



/* Function: FUN_00017044 @ 00017044 */

void FUN_00017044(void)

{
  printf((char *)(DAT_00017054 + 0x1704e),5);
  return;
}



/* Function: FUN_00017058 @ 00017058 */

undefined4 FUN_00017058(char *param_1,undefined4 *param_2)

{
  char *pcVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *__s;
  int extraout_r3;
  char *pcVar6;
  char *__delim;
  char *__s2;
  char *__s2_00;
  char *__s2_01;
  uint extraout_r12;
  
  pcVar1 = strchr(param_1,0x2f);
  if (pcVar1 != (char *)0x0) {
    pcVar6 = pcVar1 + 1;
    if (pcVar1[1] == '\0') {
      return 0;
    }
    __n = strlen(pcVar6);
    iVar2 = strncasecmp(pcVar6,(char *)(iRam00017118 + 0x17084),__n);
    if (iVar2 != 0) {
      iVar3 = strncasecmp(pcVar6,(char *)(iRam00017124 + 0x170da),__n);
      iVar2 = 0x3c;
      if (iVar3 != 0) {
        iVar2 = strncasecmp(pcVar6,(char *)(iRam00017128 + 0x170ee),__n);
        if (iVar2 == 0) {
          iVar2 = 0xe10;
        }
        else {
          iVar3 = strncasecmp(pcVar6,(char *)(iRam00017120 + 0x170c2),__n);
          iVar2 = iRam0001712c;
          if (iVar3 != 0) {
            return 0;
          }
        }
      }
      goto LAB_00017090;
    }
  }
  iVar2 = 1;
LAB_00017090:
  iVar3 = atoi(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  uVar4 = __aeabi_uidiv(iVar3,iVar2);
  if (uVar4 <= uRam0001711c) {
    uVar5 = __aeabi_uidiv(uRam0001711c * iVar2,iVar3);
    *param_2 = uVar5;
    return 1;
  }
  iVar2 = (**(code **)(**(int **)(iRam00017130 + 0x1710c) + 0x14))(2,iRam00017134 + 0x17110,param_1)
  ;
  *(int *)(extraout_r3 * iVar2 + (int)param_2) = extraout_r3 * iVar2;
  __s = (uint *)(extraout_r12 | 1);
  pcVar1 = strdup((char *)__s);
  if (pcVar1 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar6 = strtok(pcVar1,(char *)(DAT_00017208 + 0x1715a));
  iVar2 = DAT_00017214;
  if (pcVar6 != (char *)0x0) {
    __s2 = (char *)(DAT_0001720c + 0x1716e);
    __delim = (char *)(DAT_00017210 + 0x17170);
    __s2_00 = (char *)(DAT_00017218 + 0x17176);
    __s2_01 = (char *)(DAT_0001721c + 0x1717a);
    do {
      iVar3 = strcmp(pcVar6,(char *)(iVar2 + 0x17194));
      if (iVar3 == 0) {
        *__s = *__s | 1;
LAB_00017182:
        pcVar6 = strtok((char *)0x0,__delim);
      }
      else {
        iVar3 = strcmp(pcVar6,__s2);
        if (iVar3 != 0) {
          iVar3 = strcmp(pcVar6,__s2_00);
          if (iVar3 == 0) {
            *__s = *__s | 8;
          }
          else {
            iVar3 = strcmp(pcVar6,__s2_01);
            if (iVar3 != 0) {
              free(pcVar1);
              return 0xffffffff;
            }
            *__s = *__s | 2;
          }
          goto LAB_00017182;
        }
        *__s = *__s | 4;
        pcVar6 = strtok((char *)0x0,__delim);
      }
    } while (pcVar6 != (char *)0x0);
  }
  free(pcVar1);
  return 0;
}



/* Function: FUN_00017138 @ 00017138 */

undefined4 FUN_00017138(uint *param_1,char *param_2)

{
  int iVar1;
  char *__s;
  char *__s1;
  int iVar2;
  undefined4 uVar3;
  char *__delim;
  char *__s2;
  char *__s2_00;
  char *__s2_01;
  
  __s = strdup(param_2);
  if (__s == (char *)0x0) {
LAB_00017202:
    uVar3 = 0xffffffff;
  }
  else {
    __s1 = strtok(__s,(char *)(DAT_00017208 + 0x1715a));
    iVar1 = DAT_00017214;
    if (__s1 != (char *)0x0) {
      __s2 = (char *)(DAT_0001720c + 0x1716e);
      __delim = (char *)(DAT_00017210 + 0x17170);
      __s2_00 = (char *)(DAT_00017218 + 0x17176);
      __s2_01 = (char *)(DAT_0001721c + 0x1717a);
LAB_0001718e:
      do {
        iVar2 = strcmp(__s1,(char *)(iVar1 + 0x17194));
        if (iVar2 == 0) {
          *param_1 = *param_1 | 1;
        }
        else {
          iVar2 = strcmp(__s1,__s2);
          if (iVar2 == 0) {
            *param_1 = *param_1 | 4;
            __s1 = strtok((char *)0x0,__delim);
            if (__s1 == (char *)0x0) break;
            goto LAB_0001718e;
          }
          iVar2 = strcmp(__s1,__s2_00);
          if (iVar2 == 0) {
            *param_1 = *param_1 | 8;
          }
          else {
            iVar2 = strcmp(__s1,__s2_01);
            if (iVar2 != 0) {
              free(__s);
              goto LAB_00017202;
            }
            *param_1 = *param_1 | 2;
          }
        }
        __s1 = strtok((char *)0x0,__delim);
      } while (__s1 != (char *)0x0);
    }
    free(__s);
    uVar3 = 0;
  }
  return uVar3;
}



/* Function: FUN_00017220 @ 00017220 */

undefined4 FUN_00017220(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (0x3d < param_3 - 0x22U) {
    return 0;
  }
                    /* WARNING: Could not emulate address calculation at 0x00017248 */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(*(int *)((param_3 - 0x22U) * 4 + DAT_00017544 + 0x1724a) +
                    DAT_00017544 + 0x1724a))();
  return uVar1;
}



/* Function: FUN_00017654 @ 00017654 */

void FUN_00017654(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6)

{
  FUN_00017220(*param_6 + 0x20,param_4,param_1,param_3,0x20);
  return;
}



/* Function: FUN_00017674 @ 00017674 */

undefined4 FUN_00017674(int param_1)

{
  undefined4 uVar1;
  
  if (0x3d < param_1 - 0x22U) {
    return 0;
  }
                    /* WARNING: Could not emulate address calculation at 0x000176a6 */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(*(int *)((param_1 - 0x22U) * 4 + DAT_000179b4 + 0x176a8) +
                    DAT_000179b4 + 0x176a8))();
  return uVar1;
}



/* Function: FUN_00017a4c @ 00017a4c */

void FUN_00017a4c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  iVar5 = DAT_00017b78;
  iVar6 = DAT_00017b74 + 0x17a58;
  bVar7 = param_1 << 0x1d < 0;
  if (bVar7) {
    fwrite((void *)(DAT_00017b88 + 0x17ae0),1,5,(FILE *)(*(int *)(iVar6 + DAT_00017b78) + 0x54));
  }
  uVar1 = (undefined1)param_2;
  if (param_1 << 0x1c < 0) {
    if (bVar7) {
      iVar2 = *(int *)(iVar6 + iVar5);
      iVar4 = *(int *)(iVar2 + 0x5c) + -1;
      *(int *)(iVar2 + 0x5c) = iVar4;
      if ((iVar4 < 0) && ((iVar4 < *(int *)(iVar2 + 0x6c) || (param_2 == 10)))) {
        __swbuf(param_2,*(int *)(iVar6 + iVar5) + 0x54,*(int *)(iVar2 + 0x6c),iVar4,param_4);
      }
      else {
        iVar2 = *(int *)(iVar6 + iVar5);
        puVar3 = *(undefined1 **)(iVar2 + 0x54);
        *puVar3 = uVar1;
        *(undefined1 **)(iVar2 + 0x54) = puVar3 + 1;
      }
    }
    fwrite((void *)(DAT_00017b7c + 0x17a72),1,7,(FILE *)(*(int *)(iVar6 + iVar5) + 0x54));
    bVar7 = true;
  }
  if (param_1 << 0x1f < 0) {
    if (bVar7) {
      iVar2 = *(int *)(iVar6 + iVar5);
      iVar4 = *(int *)(iVar2 + 0x5c) + -1;
      *(int *)(iVar2 + 0x5c) = iVar4;
      if ((iVar4 < 0) && ((iVar4 < *(int *)(iVar2 + 0x6c) || (param_2 == 10)))) {
        __swbuf(param_2,*(int *)(iVar6 + iVar5) + 0x54,*(int *)(iVar2 + 0x6c),iVar4,param_4);
      }
      else {
        iVar2 = *(int *)(iVar6 + iVar5);
        puVar3 = *(undefined1 **)(iVar2 + 0x54);
        *puVar3 = uVar1;
        *(undefined1 **)(iVar2 + 0x54) = puVar3 + 1;
      }
    }
    fwrite((void *)(DAT_00017b80 + 0x17a8c),1,5,(FILE *)(*(int *)(iVar6 + iVar5) + 0x54));
    bVar7 = true;
  }
  if (param_1 << 0x1e < 0) {
    if (bVar7) {
      iVar2 = *(int *)(iVar6 + iVar5);
      iVar4 = *(int *)(iVar2 + 0x5c) + -1;
      *(int *)(iVar2 + 0x5c) = iVar4;
      if ((iVar4 < 0) && ((iVar4 < *(int *)(iVar2 + 0x6c) || (param_2 == 10)))) {
        __swbuf(param_2,*(int *)(iVar6 + iVar5) + 0x54,*(int *)(iVar2 + 0x6c),iVar4,param_4);
      }
      else {
        iVar2 = *(int *)(iVar6 + iVar5);
        puVar3 = *(undefined1 **)(iVar2 + 0x54);
        *puVar3 = uVar1;
        *(undefined1 **)(iVar2 + 0x54) = puVar3 + 1;
      }
    }
    fwrite((void *)(DAT_00017b84 + 0x17aa4),1,7,(FILE *)(*(int *)(iVar6 + iVar5) + 0x54));
  }
  iVar2 = *(int *)(iVar6 + iVar5);
  iVar4 = *(int *)(iVar2 + 0x5c) + -1;
  *(int *)(iVar2 + 0x5c) = iVar4;
  if ((iVar4 < 0) && (iVar4 < *(int *)(iVar2 + 0x6c))) {
    __swbuf(0x20,iVar2 + 0x54,*(int *)(iVar2 + 0x6c),iVar4,param_4);
  }
  else {
    iVar5 = *(int *)(iVar6 + iVar5);
    puVar3 = *(undefined1 **)(iVar5 + 0x54);
    *puVar3 = 0x20;
    *(undefined1 **)(iVar5 + 0x54) = puVar3 + 1;
  }
  return;
}



/* Function: FUN_00017b8c @ 00017b8c */

void FUN_00017b8c(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00017c64;
  iVar2 = DAT_00017c60 + 0x17b98;
  if (*(int *)(param_1 + 0x10) << 0x1b < 0) {
    fwrite((void *)(DAT_00017c68 + 0x17ba8),1,0x12,(FILE *)(*(int *)(iVar2 + DAT_00017c64) + 0x54));
  }
  else {
    fwrite((void *)(DAT_00017c88 + 0x17c2c),1,0x11,(FILE *)(*(int *)(iVar2 + DAT_00017c64) + 0x54));
  }
  FUN_00016fc8(*(undefined4 *)(param_1 + 0x14));
  printf((char *)(DAT_00017c6c + 0x17bbc),*(undefined4 *)(param_1 + 0x18));
  if ((*(uint *)(param_1 + 0x10) & 0xf) != 0) {
    fwrite((void *)(DAT_00017c8c + 0x17c40),1,0x11,(FILE *)(*(int *)(iVar2 + iVar1) + 0x54));
    FUN_00017a4c(*(undefined4 *)(param_1 + 0x10),0x2c);
  }
  printf((char *)(DAT_00017c70 + 0x17bcc),param_1);
  if (*(int *)(param_1 + 0x1c) != 0) {
    printf((char *)(DAT_00017c94 + 0x17c5c));
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    printf((char *)(DAT_00017c90 + 0x17c52));
  }
  if (*(int *)(param_1 + 0x24) != 1000) {
    printf((char *)(DAT_00017c74 + 0x17bea));
  }
  if (*(int *)(param_1 + 0x28) != DAT_00017c78) {
    printf((char *)(DAT_00017c7c + 0x17bfa));
  }
  if (*(byte *)(param_1 + 0x2c) != param_2) {
    printf((char *)(DAT_00017c80 + 0x17c0a));
  }
  if (*(byte *)(param_1 + 0x2d) != param_2) {
    printf((char *)(DAT_00017c84 + 0x17c1a));
  }
  return;
}



/* Function: FUN_00017c98 @ 00017c98 */

void FUN_00017c98(undefined4 param_1,int param_2)

{
  FUN_00017b8c(param_2 + 0x20,0x80);
  return;
}



/* Function: FUN_00017ca8 @ 00017ca8 */

void FUN_00017ca8(undefined4 param_1,int param_2)

{
  FUN_00017b8c(param_2 + 0x20,0x20);
  return;
}



/* Function: FUN_00017cb8 @ 00017cb8 */

void FUN_00017cb8(int param_1,uint param_2)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00017d84;
  iVar2 = DAT_00017d7c + 0x17cc4;
  if (*(int *)(param_1 + 0x10) << 0x1b < 0) {
    __ptr = (void *)(DAT_00017d80 + 0x17cce);
  }
  else {
    __ptr = (void *)(DAT_00017da0 + 0x17d46);
  }
  fwrite(__ptr,1,0xd,(FILE *)(*(int *)(iVar2 + DAT_00017d84) + 0x54));
  FUN_00016fc8(*(undefined4 *)(param_1 + 0x14));
  printf((char *)(DAT_00017d88 + 0x17ce8),*(undefined4 *)(param_1 + 0x18));
  if ((*(uint *)(param_1 + 0x10) & 0xf) == 0) {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  else {
    fwrite((void *)(DAT_00017da4 + 0x17d54),1,5,(FILE *)(*(int *)(iVar2 + iVar1) + 0x54));
    FUN_00017a4c(*(undefined4 *)(param_1 + 0x10),0x2d);
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x20);
  }
  else {
    printf((char *)(DAT_00017da8 + 0x17d6a));
    iVar1 = *(int *)(param_1 + 0x20);
  }
  if (iVar1 != 0) {
    printf((char *)(DAT_00017dac + 0x17d78));
  }
  if (*(int *)(param_1 + 0x24) != 1000) {
    printf((char *)(DAT_00017d8c + 0x17d0c));
  }
  if (*(int *)(param_1 + 0x28) != DAT_00017d90) {
    printf((char *)(DAT_00017d94 + 0x17d1c));
  }
  if (*(byte *)(param_1 + 0x2c) != param_2) {
    printf((char *)(DAT_00017d98 + 0x17d2c));
  }
  if (*(byte *)(param_1 + 0x2d) != param_2) {
    printf((char *)(DAT_00017d9c + 0x17d3c));
  }
  return;
}



/* Function: FUN_00017db0 @ 00017db0 */

void FUN_00017db0(undefined4 param_1,int param_2)

{
  FUN_00017cb8(param_2 + 0x20,0x80);
  return;
}



/* Function: FUN_00017dc0 @ 00017dc0 */

void FUN_00017dc0(undefined4 param_1,int param_2)

{
  FUN_00017cb8(param_2 + 0x20,0x20);
  return;
}



/* Function: FUN_00017e94 @ 00017e94 */

void FUN_00017e94(undefined4 param_1,int param_2)

{
  int iVar1;
  FILE *__s;
  
  __s = (FILE *)(*(int *)(DAT_00017f20 + 0x17ea0 + DAT_00017f24) + 0x54);
  fwrite((void *)(DAT_00017f28 + 0x17eae),1,0xb,__s);
  FUN_00016fc8(*(undefined4 *)(param_2 + 0x34));
  printf((char *)(DAT_00017f2c + 0x17ec0),*(undefined4 *)(param_2 + 0x38));
  fwrite((void *)(DAT_00017f30 + 0x17ece),1,5,__s);
  FUN_00017a4c(*(undefined4 *)(param_2 + 0x30),0x2d);
  if (*(int *)(param_2 + 0x3c) == 0) {
    iVar1 = *(int *)(param_2 + 0x40);
  }
  else {
    printf(PTR_DAT_00017f40 + 0x17f0e);
    iVar1 = *(int *)(param_2 + 0x40);
  }
  if (iVar1 != 0) {
    printf(PTR_DAT_00017f44 + 0x17f1c);
  }
  if (*(int *)(param_2 + 0x44) != 1000) {
    printf((char *)(DAT_00017f34 + 0x17ef4));
  }
  if (*(int *)(param_2 + 0x48) != DAT_00017f38) {
    printf(PTR_PTR_00017f3c + 0x17f04);
  }
  return;
}



/* Function: FUN_00017f6c @ 00017f6c */

void FUN_00017f6c(void)

{
  FUN_0002310c(DAT_00017f78 + 0x17f74);
  return;
}



/* Function: FUN_00017f7c @ 00017f7c */

void FUN_00017f7c(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  
  if (*(int *)(param_2 + 0x20) == 0) {
    puVar1 = (undefined *)(DAT_00017fa0 + 0x17f8e);
  }
  else {
    puVar1 = &UNK_00017f9e + DAT_00017fa8;
  }
  printf((char *)(DAT_00017fa4 + 0x17f94),puVar1,param_2 + 0x24);
  return;
}



/* Function: FUN_00017fac @ 00017fac */

void FUN_00017fac(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  
  if (*(int *)(param_2 + 0x20) == 0) {
    puVar1 = (undefined *)(DAT_00017fd4 + 0x17fbe);
  }
  else {
    puVar1 = &UNK_00017fd2 + DAT_00017fdc;
  }
  printf((char *)(DAT_00017fd8 + 0x17fc2),puVar1);
  FUN_00021e64(param_2 + 0x24);
  return;
}



/* Function: FUN_0001809c @ 0001809c */

void FUN_0001809c(void)

{
  FUN_000232e4(DAT_000180ac + 0x180a6,3);
  return;
}



/* Function: FUN_000180b0 @ 000180b0 */

void FUN_000180b0(byte *param_1)

{
  printf((char *)(DAT_000180e0 + 0x180cc),(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
         (uint)param_1[3],(uint)param_1[4],(uint)param_1[5],(uint)param_1[6],(uint)param_1[7]);
  return;
}



/* Function: FUN_000180e4 @ 000180e4 */

void FUN_000180e4(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_2 + 0x30);
  if ((int)(uVar1 << 0x1f) < 0) {
    printf((char *)(DAT_00018140 + 0x18114));
    if ((int)((uint)*(byte *)(param_2 + 0x30) << 0x1b) < 0) {
      printf((char *)(DAT_00018148 + 0x18136));
    }
    FUN_000180b0(param_2 + 0x20);
    uVar1 = (uint)*(byte *)(param_2 + 0x30);
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    printf((char *)(DAT_0001813c + 0x180fc));
    if ((int)((uint)*(byte *)(param_2 + 0x30) << 0x1a) < 0) {
      printf((char *)(DAT_00018144 + 0x1812c));
    }
    FUN_000180b0(param_2 + 0x28);
  }
  return;
}



/* Function: FUN_0001814c @ 0001814c */

void FUN_0001814c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_2 + 0x60);
  if ((int)(uVar2 << 0x1f) < 0) {
    if ((int)(uVar2 << 0x1b) < 0) {
      printf((char *)(DAT_000181dc + 0x181c2));
    }
    uVar1 = FUN_00022018(param_2 + 0x20);
    printf((char *)(DAT_000181c8 + 0x1816c),uVar1);
    uVar1 = FUN_00022018(param_2 + 0x30);
    printf((char *)(DAT_000181cc + 0x1817e),uVar1);
    uVar2 = (uint)*(byte *)(param_2 + 0x60);
  }
  if ((int)(uVar2 << 0x1e) < 0) {
    if ((int)(uVar2 << 0x1a) < 0) {
      printf((char *)(DAT_000181d8 + 0x181b8));
    }
    uVar1 = FUN_00022018(param_2 + 0x40);
    printf((char *)(DAT_000181d0 + 0x1819c),uVar1);
    uVar1 = FUN_00022018(param_2 + 0x50);
    printf((char *)(DAT_000181d4 + 0x181ae),uVar1);
  }
  return;
}



/* Function: FUN_000181e0 @ 000181e0 */

void FUN_000181e0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_2 + 0x60);
  if ((int)(uVar2 << 0x1f) < 0) {
    printf((char *)(DAT_00018280 + 0x18230));
    if ((int)((uint)*(byte *)(param_2 + 0x60) << 0x1b) < 0) {
      printf((char *)(DAT_00018290 + 0x18270));
    }
    uVar1 = FUN_00022018(param_2 + 0x20);
    printf((char *)(DAT_00018284 + 0x18246),uVar1);
    uVar1 = FUN_00022018(param_2 + 0x30);
    printf((char *)(DAT_00018288 + 0x18258),uVar1);
    uVar2 = (uint)*(byte *)(param_2 + 0x60);
  }
  if ((int)(uVar2 << 0x1e) < 0) {
    printf((char *)(DAT_00018274 + 0x181fa));
    if ((int)((uint)*(byte *)(param_2 + 0x60) << 0x1a) < 0) {
      printf((char *)(DAT_0001828c + 0x18266));
    }
    uVar1 = FUN_00022018(param_2 + 0x40);
    printf((char *)(DAT_00018278 + 0x18214),uVar1);
    uVar1 = FUN_00022018(param_2 + 0x50);
    printf((char *)(DAT_0001827c + 0x18226),uVar1);
  }
  return;
}



/* Function: FUN_00018294 @ 00018294 */

void FUN_00018294(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_24;
  undefined4 uStack_20;
  
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  local_24 = param_2;
  if (param_4 == 10) {
    puVar5 = &local_24;
    iVar4 = DAT_0001834c + 0x18316;
    puVar1 = (undefined4 *)FUN_00021f44(param_1);
    while( true ) {
      if (puVar1 == (undefined4 *)0x0) {
        FUN_000221e0(7,iVar4,param_5,param_1);
      }
      uVar2 = puVar1[1];
      uVar3 = puVar1[2];
      *param_3 = *puVar1;
      param_3[1] = uVar2;
      param_3[2] = uVar3;
      puVar6 = param_3 + 3;
      param_3 = param_3 + 4;
      *puVar6 = puVar1[3];
      if (puVar5 == &uStack_20) break;
      param_1 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = (undefined4 *)FUN_00021f44(param_1);
    }
  }
  else {
    puVar5 = &local_24;
    iVar4 = DAT_00018348 + 0x182d0;
    uVar2 = param_1;
    puVar1 = (undefined4 *)FUN_00022774(param_1);
    while( true ) {
      if (puVar1 == (undefined4 *)0x0) {
        FUN_000221e0(7,iVar4,param_5,param_1,uVar2);
      }
      *param_3 = *puVar1;
      param_3 = param_3 + 4;
      if (puVar5 == &uStack_20) break;
      param_1 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = (undefined4 *)FUN_00022774(param_1);
    }
  }
  return;
}



/* Function: FUN_00018350 @ 00018350 */

void FUN_00018350(char *param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_000183c4 + 0x18364;
  pcVar1 = strchr(param_1,0x2d);
  if (pcVar1 == (char *)0x0) {
    FUN_00018294(param_1,param_1,param_2,param_3,param_4);
  }
  else {
    *pcVar1 = '\0';
    FUN_00018294(param_1,pcVar1 + 1,param_2,param_3,param_4);
    iVar2 = memcmp(param_2,(void *)((int)param_2 + 0x10),0x10);
    if (0 < iVar2) {
      fprintf((FILE *)(*(int *)(iVar3 + DAT_000183c8) + 0xa8),(char *)(DAT_000183cc + 0x183a2),
              param_1,pcVar1 + 1);
    }
  }
  return;
}



/* Function: FUN_000183d0 @ 000183d0 */

undefined4
FUN_000183d0(int param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5,
            int *param_6)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_6;
  if (param_1 == 0x31) {
    FUN_00018350(**(undefined4 **)(PTR_DAT_0001845c + 0x183f4),iVar3 + 0x20,10,
                 PTR_DAT_00018460 + 0x183fc);
    bVar1 = *(byte *)(iVar3 + 0x60);
    *(byte *)(iVar3 + 0x60) = bVar1 | 1;
    if (param_3 != 0) {
      *(byte *)(iVar3 + 0x60) = bVar1 | 0x11;
    }
    *param_4 = *param_4 | 1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    if (param_1 == 0x32) {
      FUN_00018350(**(undefined4 **)(PTR_LAB_0001dc9e_2_00018464 + 0x1842c),iVar3 + 0x40,10,
                   PTR_DAT_00018468 + 0x18436);
      bVar1 = *(byte *)(iVar3 + 0x60);
      *(byte *)(iVar3 + 0x60) = bVar1 | 2;
      if (param_3 != 0) {
        *(byte *)(iVar3 + 0x60) = bVar1 | 0x22;
      }
      *param_4 = *param_4 | 2;
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* Function: FUN_0001846c @ 0001846c */

undefined4
FUN_0001846c(int param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5,
            int *param_6)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_6;
  if (param_1 == 0x31) {
    FUN_00018350(**(undefined4 **)(PTR_DAT_000184f8 + 0x18490),iVar3 + 0x20,2,
                 PTR_DAT_000184fc + 0x18498);
    bVar1 = *(byte *)(iVar3 + 0x60);
    *(byte *)(iVar3 + 0x60) = bVar1 | 1;
    if (param_3 != 0) {
      *(byte *)(iVar3 + 0x60) = bVar1 | 0x11;
    }
    *param_4 = *param_4 | 1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    if (param_1 == 0x32) {
      FUN_00018350(**(undefined4 **)(PTR_LAB_00018500 + 0x184c8),iVar3 + 0x40,2,
                   PTR_DAT_00018504 + 0x184d2);
      bVar1 = *(byte *)(iVar3 + 0x60);
      *(byte *)(iVar3 + 0x60) = bVar1 | 2;
      if (param_3 != 0) {
        *(byte *)(iVar3 + 0x60) = bVar1 | 0x22;
      }
      *param_4 = *param_4 | 2;
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* Function: FUN_00018508 @ 00018508 */

void FUN_00018508(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_2 + 0x60);
  if ((int)(uVar2 << 0x1f) < 0) {
    if ((int)(uVar2 << 0x1b) < 0) {
      printf(PTR_DAT_00018598 + 0x1857e);
    }
    uVar1 = FUN_00021f64(param_2 + 0x20);
    printf(PTR_DAT_00018584 + 0x18528,uVar1);
    uVar1 = FUN_00021f64(param_2 + 0x30);
    printf(PTR_LAB_00018588 + 0x1853a,uVar1);
    uVar2 = (uint)*(byte *)(param_2 + 0x60);
  }
  if ((int)(uVar2 << 0x1e) < 0) {
    if ((int)(uVar2 << 0x1a) < 0) {
      printf(PTR_DAT_00018594 + 0x18574);
    }
    uVar1 = FUN_00021f64(param_2 + 0x40);
    printf(PTR_DAT_0001858c + 0x18558,uVar1);
    uVar1 = FUN_00021f64(param_2 + 0x50);
    printf(PTR_LAB_00018590 + 0x1856a,uVar1);
  }
  return;
}



/* Function: FUN_0001859c @ 0001859c */

void FUN_0001859c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_2 + 0x60);
  if ((int)(uVar2 << 0x1f) < 0) {
    printf((char *)(DAT_0001863c + 0x185ec));
    if ((int)((uint)*(byte *)(param_2 + 0x60) << 0x1b) < 0) {
      printf(PTR_DAT_0001864c + 0x1862c);
    }
    uVar1 = FUN_00021f64(param_2 + 0x20);
    printf((char *)(DAT_00018640 + 0x18602),uVar1);
    uVar1 = FUN_00021f64(param_2 + 0x30);
    printf(PTR_LAB_00018644 + 0x18614,uVar1);
    uVar2 = (uint)*(byte *)(param_2 + 0x60);
  }
  if ((int)(uVar2 << 0x1e) < 0) {
    printf((char *)(DAT_00018630 + 0x185b6));
    if ((int)((uint)*(byte *)(param_2 + 0x60) << 0x1a) < 0) {
      printf(PTR_DAT_00018648 + 0x18622);
    }
    uVar1 = FUN_00021f64(param_2 + 0x40);
    printf((char *)(DAT_00018634 + 0x185d0),uVar1);
    uVar1 = FUN_00021f64(param_2 + 0x50);
    printf((char *)(DAT_00018638 + 0x185e2),uVar1);
  }
  return;
}



/* Function: FUN_00018650 @ 00018650 */

void FUN_00018650(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(byte *)(param_2 + 0x30);
  iVar2 = DAT_000186b8 + 0x1865e;
  if ((int)(uVar1 << 0x1f) < 0) {
    if ((int)(uVar1 << 0x1b) < 0) {
      printf(PTR_DAT_000186cc + 0x186b2);
    }
    printf((char *)(DAT_000186bc + 0x1866a));
    FUN_000180b0(param_2 + 0x20);
    if (-1 < (int)((uint)*(byte *)(param_2 + 0x30) << 0x1e)) {
      return;
    }
    fputc(0x20,(FILE *)(*(int *)(iVar2 + DAT_000186c0) + 0x54));
    uVar1 = (uint)*(byte *)(param_2 + 0x30);
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    if ((int)(uVar1 << 0x1a) < 0) {
      printf(PTR_DAT_000186c8 + 0x186a8);
    }
    printf(PTR_LAB_000186c4 + 0x18696);
    FUN_000180b0(param_2 + 0x28);
  }
  return;
}



/* Function: FUN_000186d0 @ 000186d0 */

int FUN_000186d0(uint param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5,
                int *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined1 uVar5;
  int local_3c;
  undefined4 local_38 [4];
  undefined4 local_28;
  
  iVar3 = *param_6;
  iVar2 = iRam000187bc + 0x186e0;
  local_3c = param_3;
  if (param_1 == 0x31) {
    uVar5 = 1;
    if ((*param_4 & 1) != 0) {
LAB_000187aa:
      bVar4 = false;
      (**(code **)(**(int **)(iVar2 + iRam000187d0) + 0x14))(2,iRam000187d8 + 0x187b6);
      if (!(bool)uVar5 || bVar4) {
        puts((char *)(DAT_000187e8 + 0x187e4));
                    /* WARNING: Could not recover jumptable at 0x000187e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*(code *)0x187bb)();
        return iVar2;
      }
      if (bVar4 == false) {
        iVar2 = printf((char *)(DAT_00018864 + 0x18848));
      }
      else {
        iVar2 = printf((char *)(DAT_0001886c + 0x18858));
      }
      return iVar2;
    }
    *param_4 = *param_4 | 1;
    iVar1 = iRam000187c0;
    *(byte *)(iVar3 + 0x30) = *(byte *)(iVar3 + 0x30) | 1;
    FUN_00021dc4(**(undefined4 **)(iVar2 + iVar1),&local_3c,*(undefined4 *)(iVar2 + iRam000187c4),0,
                 param_2);
    if (local_3c != 0) {
      *(byte *)(iVar3 + 0x30) = *(byte *)(iVar3 + 0x30) | 0x10;
    }
    FUN_00018350(**(undefined4 **)(iVar2 + iVar1),local_38,2,iRam000187c8 + 0x18738);
    iVar1 = 1;
    *(undefined4 *)(iVar3 + 0x20) = local_38[0];
    *(undefined4 *)(iVar3 + 0x24) = local_28;
  }
  else {
    iVar1 = 0;
    uVar5 = 0x31 < param_1;
    if (param_1 == 0x32) {
      if ((*param_4 & 2) != 0) {
        (**(code **)(**(int **)(iVar2 + iRam000187d0) + 0x14))(2,iRam000187d4 + 0x187a6);
        goto LAB_000187aa;
      }
      *param_4 = *param_4 | 2;
      iVar1 = iRam000187c0;
      *(byte *)(iVar3 + 0x30) = *(byte *)(iVar3 + 0x30) | 2;
      FUN_00021dc4(**(undefined4 **)(iVar2 + iVar1),&local_3c,*(undefined4 *)(iVar2 + iRam000187c4),
                   0,param_2);
      if (local_3c != 0) {
        *(byte *)(iVar3 + 0x30) = *(byte *)(iVar3 + 0x30) | 0x20;
      }
      FUN_00018350(**(undefined4 **)(iVar2 + iVar1),local_38,2,iRam000187cc + 0x1878c);
      iVar1 = 1;
      *(undefined4 *)(iVar3 + 0x28) = local_38[0];
      *(undefined4 *)(iVar3 + 0x2c) = local_28;
    }
  }
  return iVar1;
}



/* Function: FUN_00018810 @ 00018810 */

void FUN_00018810(void)

{
  FUN_0002310c(DAT_0001881c + 0x18818);
  return;
}



/* Function: FUN_00018820 @ 00018820 */

void FUN_00018820(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x24) == '\0') {
    iVar1 = DAT_0001885c + 0x18834;
  }
  else {
    iVar1 = DAT_00018868 + 0x18852;
  }
  printf((char *)(DAT_00018860 + 0x18838),iVar1);
  if (*(short *)(param_2 + 0x20) == *(short *)(param_2 + 0x22)) {
    printf((char *)(DAT_0001886c + 0x18858));
  }
  else {
    printf((char *)(DAT_00018864 + 0x18848));
  }
  return;
}



/* Function: FUN_00018870 @ 00018870 */

void FUN_00018870(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  
  if (*(char *)(param_2 + 0x24) == '\0') {
    puVar1 = (undefined *)(DAT_000188ac + 0x18884);
  }
  else {
    puVar1 = PTR_LAB_000188b8 + 0x188a2;
  }
  printf(PTR_LAB_000188b0 + 0x18888,puVar1);
  if (*(short *)(param_2 + 0x20) == *(short *)(param_2 + 0x22)) {
    printf(PTR_LAB_000188bc + 0x188a8);
  }
  else {
    printf(PTR_LAB_000188b4 + 0x18898);
  }
  return;
}



/* Function: FUN_00018a1c @ 00018a1c */

void FUN_00018a1c(void)

{
  FUN_0002310c(DAT_00018a28 + 0x18a24);
  return;
}



/* Function: FUN_00018a2c @ 00018a2c */

void FUN_00018a2c(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint extraout_r1;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 1;
  puVar4 = (uint *)(DAT_00018a88 + 0x18a48);
  do {
    uVar3 = *puVar4;
    if (uVar3 < param_1) break;
    uVar1 = __aeabi_uidiv(uVar3,param_1);
    __aeabi_uidivmod(uVar3,param_1);
    if (uVar1 < extraout_r1) break;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 2;
  } while (iVar5 != 4);
  iVar6 = (iVar5 + -1) * 8;
  iVar5 = DAT_00018a8c + 0x18a6a;
  uVar2 = __aeabi_uidiv(*(undefined4 *)(iVar5 + iVar6 + 4),param_1);
  printf((char *)(DAT_00018a90 + 0x18a7c),uVar2,*(undefined4 *)(iVar6 + iVar5));
  return;
}



/* Function: FUN_00018a94 @ 00018a94 */

void FUN_00018a94(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00018abc + 0x18aa0));
  FUN_00018a2c(*(undefined4 *)(param_2 + 0x20));
  if (*(int *)(param_2 + 0x24) != 5) {
    printf((char *)(DAT_00018ac0 + 0x18ab6));
  }
  return;
}



/* Function: FUN_00018ac4 @ 00018ac4 */

void FUN_00018ac4(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00018ae8 + 0x18ad0));
  FUN_00018a2c(*(undefined4 *)(param_2 + 0x20));
  printf((char *)(DAT_00018aec + 0x18ae2),*(undefined4 *)(param_2 + 0x24));
  return;
}



/* Function: FUN_00018b04 @ 00018b04 */

/* WARNING: Switch with 1 destination removed at 0x00018c02 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00018b04(char *param_1,undefined4 *param_2)

{
  char *pcVar1;
  size_t __n;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_r1;
  int extraout_r2;
  int *unaff_r4;
  int iVar6;
  char *__s;
  int iVar7;
  undefined4 *puVar8;
  char cVar9;
  int local_34 [2];
  undefined4 local_2c;
  char *pcStack_28;
  char *pcStack_24;
  undefined4 *puStack_20;
  undefined4 uStack_1c;
  
  pcVar1 = strchr(param_1,0x2f);
  if (pcVar1 == (char *)0x0) goto LAB_00018b38;
  __s = pcVar1 + 1;
  if (pcVar1[1] == '\0') {
LAB_00018b74:
    uVar4 = 0;
  }
  else {
    while( true ) {
      __n = strlen(__s);
      iVar2 = strncasecmp(__s,(char *)(iRam00018bc4 + 0x18b30),__n);
      if (iVar2 == 0) {
LAB_00018b38:
        iVar2 = 1;
      }
      else {
        iVar5 = strncasecmp(__s,(char *)(iRam00018bd0 + 0x18b86),__n);
        iVar2 = 0x3c;
        if (iVar5 != 0) {
          iVar2 = strncasecmp(__s,(char *)(iRam00018bd4 + 0x18b9a),__n);
          if (iVar2 == 0) {
            iVar2 = 0xe10;
          }
          else {
            iVar5 = strncasecmp(__s,(char *)(iRam00018bcc + 0x18b6e),__n);
            iVar2 = iRam00018bd8;
            if (iVar5 != 0) goto LAB_00018b74;
          }
        }
      }
      __s = (char *)atoi(param_1);
      if (__s == (char *)0x0) goto LAB_00018b74;
      uVar3 = __aeabi_uidiv(__s,iVar2);
      if (uVar3 <= uRam00018bc8) break;
      iVar2 = (**(code **)(**(int **)(iRam00018bdc + 0x18bb8) + 0x14))
                        (2,iRam00018be0 + 0x18bbc,param_1);
      local_34[0] = extraout_r2;
      uVar4 = 0x18bc3;
      while (iVar5 = iVar2, *(int *)(iVar5 + (int)param_2) = iVar5, iVar5 < 0) {
        iVar7 = *unaff_r4;
        iVar6 = iRam00018c98 + 0x18bf4;
        pcStack_28 = param_1;
        pcStack_24 = __s;
        puStack_20 = param_2;
        uStack_1c = uVar4;
        if (iVar5 == 0x24) {
          puVar8 = *(undefined4 **)(iVar6 + iRam00018c9c);
          uVar4 = 0x18c19;
          iVar2 = FUN_00021dc4(*puVar8,local_34,*(undefined4 *)(iVar6 + iRam00018ca0),0,0x24);
          if (iVar2 == 0) goto LAB_00018c6a;
          goto LAB_00018c1c;
        }
        iVar2 = 0;
        if (iVar5 == 0x25) {
          while( true ) {
            puVar8 = *(undefined4 **)(iVar6 + iRam00018c9c);
            uVar4 = 0x18c49;
            iVar2 = FUN_00021dc4(*puVar8,local_34,*(undefined4 *)(iVar6 + iRam00018ca0),0,iVar5);
            if (iVar2 == 0) {
              uVar4 = 0x18c55;
              iVar2 = FUN_00018b04(*puVar8,iVar7 + 0x20);
              if (iVar2 == 0) {
                (**(code **)(**(int **)(iVar6 + iRam00018ca4) + 0x14))
                          (2,iRam00018cac + 0x18c64,*puVar8);
LAB_00018c6a:
                uVar4 = 0x18c7b;
                iVar2 = FUN_000224cc(*puVar8,0,&local_2c,0,uRam00018cb0);
                cVar9 = '\x01';
                if (iVar2 == 0) {
                  uVar4 = (**(code **)(**(int **)(iVar6 + iRam00018ca4) + 0x14))
                                    (2,iRam00018cb4 + 0x18c90,*puVar8);
                  if (cVar9 != '\0') {
                    FUN_00018b04(DAT_00018cd0 + 0x18cc6,0x1020);
                    _DAT_00001024 = 5;
                    /* WARNING: Could not recover jumptable at 0x00018ccc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    uVar4 = (*(code *)0x18c97)();
                    return uVar4;
                  }
                  uVar4 = FUN_0002310c(DAT_00018d04 + 0x18d00,uVar4);
                  return uVar4;
                }
                *(undefined4 *)(iVar7 + 0x24) = local_2c;
              }
            }
LAB_00018c1c:
            iVar2 = 1;
            param_1 = pcStack_28;
            __s = pcStack_24;
            param_2 = puStack_20;
            if (local_34[0] == 0) break;
            (**(code **)(**(int **)(iVar6 + iRam00018ca4) + 0x14))(2,iRam00018ca8 + 0x18c30);
            iVar5 = extraout_r1;
          }
        }
      }
    }
    uVar4 = __aeabi_uidiv(uRam00018bc8 * iVar2,__s);
    *param_2 = uVar4;
    uVar4 = 1;
  }
  return uVar4;
}



/* Function: FUN_00018cf8 @ 00018cf8 */

void FUN_00018cf8(void)

{
  FUN_0002310c(DAT_00018d04 + 0x18d00);
  return;
}



/* Function: FUN_00018d08 @ 00018d08 */

void FUN_00018d08(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_00018d38;
  printf((char *)(DAT_00018d34 + 0x18d16),(uint)*param_1);
  iVar3 = 1;
  do {
    pbVar1 = param_1 + iVar3;
    iVar3 = iVar3 + 1;
    printf((char *)(iVar2 + 0x18d1e),(uint)*pbVar1);
  } while (iVar3 != 6);
  putchar(0x20);
  return;
}



/* Function: FUN_00018d3c @ 00018d3c */

void FUN_00018d3c(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x28) != 0) {
    printf((char *)(DAT_00018d60 + 0x18d4e));
  }
  printf((char *)(DAT_00018d64 + 0x18d56));
  FUN_00018d08(param_2 + 0x20);
  return;
}



/* Function: FUN_00018d68 @ 00018d68 */

void FUN_00018d68(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00018d8c + 0x18d74));
  if (*(int *)(param_2 + 0x28) != 0) {
    printf((char *)(DAT_00018d90 + 0x18d82));
  }
  FUN_00018d08(param_2 + 0x20);
  return;
}



/* Function: FUN_00018d94 @ 00018d94 */

int FUN_00018d94(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined4 param_5,
                int *param_6)

{
  size_t sVar1;
  int iVar2;
  int extraout_r2;
  int iVar3;
  undefined4 *puVar4;
  char *__s;
  char *__nptr;
  int iVar5;
  int iVar6;
  undefined4 extraout_r12;
  char cVar7;
  undefined4 in_cr0;
  undefined4 in_cr14;
  undefined4 extraout_s0;
  undefined4 extraout_s1;
  undefined8 uVar8;
  int local_2c [2];
  char *local_24;
  
  iVar6 = *param_6;
  iVar3 = 0;
  iVar5 = iRam00018e44 + 0x18db0;
  if (param_1 == 0x31) {
    puVar4 = *(undefined4 **)(iVar5 + iRam00018e48);
    local_2c[0] = param_3;
    FUN_00021dc4(*puVar4,local_2c,*(undefined4 *)(iVar5 + iRam00018e4c),0);
    __s = (char *)*puVar4;
    sVar1 = strlen(__s);
    if (sVar1 != 0x11) {
      cVar7 = __s == (char *)0x0;
      iVar3 = (**(code **)(**(int **)(iVar5 + iRam00018e50) + 0x14))(2,iRam00018e58 + 0x18e3e);
      if (cVar7 != '\0') {
        iVar3 = puts((char *)(DAT_00018e68 + 0x18e64));
        return iVar3;
      }
      coprocessor_load(7,in_cr14,0x191e5);
      coprocessor_store(0,in_cr0,extraout_r12);
      uVar8 = vrev(CONCAT44(extraout_s1,extraout_s0),4);
      printf((char *)(DAT_00018f78 + 0x18f48),(int)uVar8,iVar3,extraout_r2 << 1);
      if (*(char *)(iVar3 + 0x28) != '\0') {
        putchar(0x21);
      }
      if (*(int *)(iVar3 + 0x24) == -1) {
        iVar3 = printf((char *)(DAT_00018f80 + 0x18f6a),*(undefined4 *)(iVar3 + 0x20));
      }
      else {
        iVar3 = printf((char *)(DAT_00018f7c + 0x18f60),*(undefined4 *)(iVar3 + 0x20));
      }
      return iVar3;
    }
    iVar3 = 0;
    __nptr = __s;
    do {
      iVar2 = strtol(__nptr,&local_24,0x10);
      if (local_24 == __nptr + 2) goto LAB_00018e0e;
      do {
        iVar2 = (**(code **)(**(int **)(iVar5 + iRam00018e50) + 0x14))(2,iRam00018e54 + 0x18e08,__s)
        ;
LAB_00018e0e:
      } while ((iVar2 < 0) || (0xff < iVar2));
      *(char *)(iVar6 + 0x20 + iVar3) = (char)iVar2;
      iVar3 = iVar3 + 1;
      __nptr = __nptr + 3;
    } while (iVar3 != 6);
    if (local_2c[0] != 0) {
      *(undefined4 *)(iVar6 + 0x28) = 1;
    }
    iVar3 = 1;
    *param_4 = 1;
  }
  return iVar3;
}



/* Function: FUN_00018e90 @ 00018e90 */

void FUN_00018e90(void)

{
  FUN_000232e4(DAT_00018ea0 + 0x18e9a,2);
  return;
}



/* Function: FUN_00018ea4 @ 00018ea4 */

void FUN_00018ea4(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x28) != '\0') {
    printf((char *)(DAT_00018eec + 0x18edc));
  }
  printf((char *)(DAT_00018ee0 + 0x18eb8));
  if (*(int *)(param_2 + 0x24) == -1) {
    printf((char *)(DAT_00018ee8 + 0x18ed2),*(undefined4 *)(param_2 + 0x20));
  }
  else {
    printf((char *)(DAT_00018ee4 + 0x18ec8),*(undefined4 *)(param_2 + 0x20));
  }
  return;
}



/* Function: FUN_00018f84 @ 00018f84 */

void FUN_00018f84(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00018fc0 + 0x18f90));
  if (*(char *)(param_2 + 0x28) != '\0') {
    putchar(0x21);
  }
  if (*(int *)(param_2 + 0x24) == -1) {
    printf((char *)(DAT_00018fc8 + 0x18fb2),*(undefined4 *)(param_2 + 0x20));
  }
  else {
    printf((char *)(DAT_00018fc4 + 0x18fa8),*(undefined4 *)(param_2 + 0x20));
  }
  return;
}



/* Function: FUN_000190e8 @ 000190e8 */

undefined4
FUN_000190e8(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined4 param_5,
            int *param_6)

{
  int iVar1;
  ulong uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_2c [2];
  char *local_24 [2];
  
  iVar1 = iRam00019198;
  iVar4 = iRam00019194 + 0x190fe;
  iVar5 = *param_6;
  uVar3 = 0;
  if (param_1 == 0x31) {
    puVar6 = *(undefined4 **)(iVar4 + iRam00019198);
    local_2c[0] = param_3;
    FUN_00021dc4(*puVar6,local_2c,*(undefined4 *)(iVar4 + iRam0001919c),0,param_2);
    uVar2 = strtoul((char *)*puVar6,local_24,0);
    *(ulong *)(iVar5 + 0x20) = uVar2;
    if (*local_24[0] == '/') {
      uVar2 = strtoul(local_24[0] + 1,local_24,0);
      *(ulong *)(iVar5 + 0x24) = uVar2;
    }
    else {
      *(undefined4 *)(iVar5 + 0x24) = 0xffffffff;
    }
    if ((*local_24[0] != '\0') || (local_24[0] == (char *)**(undefined4 **)(iVar4 + iVar1))) {
      (**(code **)(**(int **)(iVar4 + iRam000191a0) + 0x14))
                (2,iRam000191a4 + 0x19190,**(undefined4 **)(iVar4 + iVar1));
      puts((char *)(DAT_000191b4 + 0x191b0));
                    /* WARNING: Could not recover jumptable at 0x000191b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*(code *)0x19195)();
      return uVar3;
    }
    if (local_2c[0] != 0) {
      *(undefined1 *)(iVar5 + 0x28) = 1;
    }
    uVar3 = 1;
    *param_4 = 1;
  }
  return uVar3;
}



/* Function: FUN_00019200 @ 00019200 */

void FUN_00019200(void)

{
  FUN_00022d9c(DAT_00019210 + 0x1920a,3);
  return;
}



/* Function: FUN_00019214 @ 00019214 */

void FUN_00019214(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00019228 + 0x19222),*(undefined4 *)(param_2 + 0x20),
         *(undefined4 *)(param_2 + 0x24));
  return;
}



/* Function: FUN_0001922c @ 0001922c */

void FUN_0001922c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x20) == 0) {
    printf(PTR_LAB_00019280 + 0x1925a,~*(uint *)(param_2 + 0x24));
  }
  else {
    iVar1 = *(int *)(param_2 + 0x24);
    if (*(int *)(param_2 + 0x20) == iVar1) {
      printf(PTR_DAT_0001928c + 0x19278);
    }
    else if (iVar1 == 0) {
      printf(PTR_DAT_00019288 + 0x1926e);
    }
    else if (iVar1 == -1) {
      printf(PTR_DAT_00019284 + 0x19264);
    }
    else {
      printf(PTR_LAB_0001927c + 0x1924c);
    }
  }
  return;
}



/* Function: FUN_00019290 @ 00019290 */

void FUN_00019290(undefined4 param_1,int param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_2 + 0x24);
  if (cVar1 == '\x01') {
    printf((char *)(DAT_000192dc + 0x192ca));
  }
  else if (cVar1 == '\0') {
    printf((char *)(DAT_000192d8 + 0x192c0));
  }
  else if (cVar1 == '\x02') {
    printf((char *)(DAT_000192d0 + 0x192ac));
  }
  printf((char *)(DAT_000192d4 + 0x192b6),*(undefined4 *)(param_2 + 0x20));
  return;
}



/* Function: FUN_000192e0 @ 000192e0 */

void FUN_000192e0(undefined4 param_1,int param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_2 + 0x24);
  if (cVar1 == '\x01') {
    printf((char *)(DAT_0001932c + 0x1931a));
  }
  else if (cVar1 == '\0') {
    printf((char *)(DAT_00019328 + 0x19310));
  }
  else if (cVar1 == '\x02') {
    printf((char *)(DAT_00019320 + 0x192fc));
  }
  printf((char *)(DAT_00019324 + 0x19306),*(undefined4 *)(param_2 + 0x20));
  return;
}



/* Function: FUN_00019350 @ 00019350 */

void FUN_00019350(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00019368 + 0x1935a));
  printf((char *)(DAT_0001936c + 0x19364),*(undefined4 *)(param_2 + 0x20));
  return;
}



/* Function: FUN_0001975c @ 0001975c */

undefined * FUN_0001975c(uint param_1)

{
  if (param_1 == 0x21) {
    return &UNK_00019796 + DAT_000197a8;
  }
  if (param_1 < 0x22) {
    if (param_1 == 6) {
      return (undefined *)(DAT_000197a4 + 0x19790);
    }
    if (param_1 == 0x11) {
      return (undefined *)(DAT_00019798 + 0x1977e);
    }
  }
  else {
    if (param_1 == 0x84) {
      return (undefined *)(DAT_000197a0 + 0x1978a);
    }
    if (param_1 == 0x88) {
      return (undefined *)(DAT_0001979c + 0x19784);
    }
  }
  return (undefined *)0x0;
}



/* Function: FUN_000197ac @ 000197ac */

void FUN_000197ac(uint param_1,int param_2)

{
  int iVar1;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r3;
  int iVar2;
  int unaff_r6;
  int *unaff_r7;
  
  iVar2 = iRam000197fc + 0x197b6;
  if (-1 < param_2 << 0x19) {
    iVar1 = FUN_0001975c(param_1 & 0xff);
    if (iVar1 != 0) {
      return;
    }
    if (param_1 == 0) {
      (**(code **)(**(int **)(iVar2 + iRam00019800) + 0x14))(2,iRam00019804 + 0x197d6);
    }
    (**(code **)(**(int **)(iVar2 + iRam00019800) + 0x14))(2,iRam00019808 + 0x197e6);
  }
  (**(code **)(**(int **)(iVar2 + iRam00019800) + 0x14))(2,iRam0001980c + 0x197f6);
  iVar2 = extraout_r1;
  do {
    *unaff_r7 = iVar2;
    unaff_r7[1] = extraout_r3;
    unaff_r7[2] = param_1;
    unaff_r7[3] = unaff_r6;
    unaff_r7 = unaff_r7 + 4;
    iVar2 = (int)unaff_r7 * 0x100;
  } while (iVar2 != 0);
  (**(code **)(**(int **)(iRam0001982c + 0x19822) + 0x14))(2,iRam00019830 + 0x19826);
  FUN_000232e4(DAT_00019844 + 0x1983e,4,*(undefined4 *)(extraout_r1_00 + 4));
                    /* WARNING: Could not recover jumptable at 0x00019840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x1982b)();
  return;
}



/* Function: FUN_00019834 @ 00019834 */

void FUN_00019834(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  FUN_000232e4(DAT_00019844 + 0x1983e,4);
                    /* WARNING: Could not recover jumptable at 0x00019840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



/* Function: FUN_00019848 @ 00019848 */

void FUN_00019848(uint param_1,undefined4 param_2,int param_3)

{
  char *__proto;
  servent *psVar1;
  
  if (param_3 == 0) {
    __proto = (char *)FUN_0001975c(param_2);
    psVar1 = getservbyport((param_1 << 8 | param_1 >> 8) & 0xffff,__proto);
    if ((psVar1 != (servent *)0x0) && (psVar1->s_name != (char *)0x0)) {
      printf((char *)(DAT_00019888 + 0x19876));
      return;
    }
  }
  printf((char *)(DAT_0001988c + 0x19882),param_1);
  return;
}



/* Function: FUN_00019890 @ 00019890 */

void FUN_00019890(int param_1,undefined1 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *__format;
  int iVar5;
  int iVar6;
  
  pcVar4 = (char *)(param_1 + 0x20);
  if (*(char *)(param_1 + 0x4f) == '\0') {
    cVar1 = *pcVar4;
  }
  else {
    printf((char *)(DAT_00019974 + 0x19948));
    cVar1 = *pcVar4;
  }
  if (cVar1 == '\x01') {
    printf((char *)(DAT_00019978 + 0x19956));
  }
  else if (cVar1 == '\0') {
    printf((char *)(DAT_00019970 + 0x19912));
  }
  else if (cVar1 == '\x02') {
    printf((char *)(DAT_0001995c + 0x198ba));
  }
  if (*(char *)(param_1 + 0x21) == '\0') {
LAB_00019934:
    putchar(0x20);
    return;
  }
  uVar3 = 0;
  __format = (char *)(DAT_00019968 + 0x198da);
  iVar6 = DAT_00019960 + 0x198dc;
  iVar5 = DAT_0001996c + 0x198de;
  iVar2 = DAT_00019964 + 0x198d8;
LAB_000198dc:
  printf(__format,iVar2);
  FUN_00019848(*(undefined2 *)(pcVar4 + uVar3 * 2 + 2),param_2,1);
  if (pcVar4[uVar3 + 0x20] == '\0') {
    uVar3 = uVar3 + 1;
    if (*(byte *)(param_1 + 0x21) <= uVar3) goto LAB_00019934;
  }
  else {
    putchar(0x3a);
    FUN_00019848(*(undefined2 *)(pcVar4 + (uVar3 + 1) * 2 + 2),param_2,1);
    uVar3 = uVar3 + 2;
    if (*(byte *)(param_1 + 0x21) <= uVar3) goto LAB_00019934;
  }
  iVar2 = iVar5;
  if (uVar3 == 0) {
    iVar2 = iVar6;
  }
  goto LAB_000198dc;
}



/* Function: FUN_0001999c @ 0001999c */

/* WARNING: Removing unreachable block (ram,0x00019a26) */

void FUN_0001999c(int param_1,undefined4 param_2,undefined1 param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *__format;
  int iVar5;
  
  pcVar4 = (char *)(param_1 + 0x20);
  printf((char *)(DAT_00019a84 + 0x199b2));
  cVar1 = *pcVar4;
  if (cVar1 == '\x01') {
    printf((char *)(DAT_00019aa4 + 0x19a74));
  }
  else {
    if (cVar1 == '\0') {
      return;
    }
    if (cVar1 == '\x02') {
      printf((char *)(DAT_00019aa8 + 0x19a7e));
    }
    else {
      printf((char *)(DAT_00019a88 + 0x199ca));
    }
  }
  if (*(char *)(param_1 + 0x4f) != '\0') {
    printf((char *)(DAT_00019aa0 + 0x19a3c));
  }
  if (*(char *)(param_1 + 0x21) != '\0') {
    uVar3 = 0;
    __format = (char *)(DAT_00019a94 + 0x199f4);
    iVar5 = DAT_00019a98 + 0x199f8;
    iVar2 = DAT_00019a90 + 0x199f0;
    do {
      printf(__format,iVar2);
      FUN_00019848(*(undefined2 *)(pcVar4 + uVar3 * 2 + 2),param_3,param_2);
      if (pcVar4[uVar3 + 0x20] == '\0') {
        uVar3 = uVar3 + 1;
        if (*(byte *)(param_1 + 0x21) <= uVar3) break;
      }
      else {
        putchar(0x3a);
        FUN_00019848(*(undefined2 *)(pcVar4 + (uVar3 + 1) * 2 + 2),param_3,param_2);
        uVar3 = uVar3 + 2;
        if (*(byte *)(param_1 + 0x21) <= uVar3) break;
      }
      iVar2 = iVar5;
      if (uVar3 == 0) {
        return;
      }
    } while( true );
  }
  putchar(0x20);
  return;
}



/* Function: FUN_00019aac @ 00019aac */

void FUN_00019aac(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0001999c(param_2,param_3,*(undefined2 *)(param_1 + 0x80));
  return;
}



/* Function: FUN_00019ad4 @ 00019ad4 */

void FUN_00019ad4(int param_1,undefined1 param_2)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  char *__format;
  undefined *puVar4;
  undefined *puVar5;
  
  cVar1 = *(char *)(param_1 + 0x20);
  if (cVar1 == '\x01') {
    printf(PTR_DAT_00019b78 + 0x19b5c);
  }
  else if (cVar1 == '\0') {
    printf(PTR_DAT_00019b74 + 0x19b44);
  }
  else if (cVar1 == '\x02') {
    printf((char *)(DAT_00019b60 + 0x19af6));
  }
  if (*(char *)(param_1 + 0x21) != '\0') {
    uVar3 = 0;
    __format = (char *)(DAT_00019b6c + 0x19b16);
    puVar5 = (undefined *)(DAT_00019b64 + 0x19b18);
    puVar4 = PTR_DAT_00019b70 + 0x19b1a;
    puVar2 = (undefined *)(DAT_00019b68 + 0x19b12);
    while( true ) {
      printf(__format,puVar2);
      FUN_00019848(*(undefined2 *)((char *)(param_1 + 0x20) + uVar3 * 2 + 2),param_2,1);
      uVar3 = uVar3 + 1;
      if (*(byte *)(param_1 + 0x21) <= uVar3) break;
      puVar2 = puVar4;
      if (uVar3 == 0) {
        puVar2 = puVar5;
      }
    }
  }
  putchar(0x20);
  return;
}



/* Function: FUN_00019b9c @ 00019b9c */

void FUN_00019b9c(int param_1,undefined4 param_2,undefined1 param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *__format;
  int iVar4;
  int iVar5;
  
  printf((char *)(DAT_00019c40 + 0x19bb2));
  cVar1 = *(char *)(param_1 + 0x20);
  if (cVar1 == '\x01') {
    printf(PTR_LAB_00019c5c + 0x19c32);
  }
  else if (cVar1 == '\0') {
    printf(PTR_LAB_00019c58 + 0x19c18);
  }
  else if (cVar1 == '\x02') {
    printf(PTR_LAB_00019c60 + 0x19c3c);
  }
  else {
    printf((char *)(DAT_00019c44 + 0x19bca));
  }
  if (*(char *)(param_1 + 0x21) != '\0') {
    uVar3 = 0;
    __format = (char *)(DAT_00019c50 + 0x19bea);
    iVar5 = DAT_00019c48 + 0x19bec;
    iVar4 = DAT_00019c54 + 0x19bee;
    iVar2 = DAT_00019c4c + 0x19be6;
    while( true ) {
      printf(__format,iVar2);
      FUN_00019848(*(undefined2 *)((char *)(param_1 + 0x20) + uVar3 * 2 + 2),param_3,param_2);
      uVar3 = uVar3 + 1;
      if (*(byte *)(param_1 + 0x21) <= uVar3) break;
      iVar2 = iVar4;
      if (uVar3 == 0) {
        iVar2 = iVar5;
      }
    }
  }
  putchar(0x20);
  return;
}



/* Function: FUN_00019c64 @ 00019c64 */

void FUN_00019c64(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00019b9c(param_2,param_3,*(undefined2 *)(param_1 + 0x80));
  return;
}



/* Function: FUN_00019c8c @ 00019c8c */

/* WARNING: Possible PIC construction at 0x00019ece: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x00019ed2) */

undefined4 FUN_00019c8c(char *param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined2 uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 extraout_r0;
  undefined4 extraout_r1;
  undefined4 *extraout_r1_00;
  undefined4 *extraout_r2;
  undefined4 *puVar6;
  undefined4 *extraout_r2_00;
  int iVar7;
  int *extraout_r3;
  int *piVar8;
  int *extraout_r3_00;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined1 *puVar12;
  int *piVar13;
  char *unaff_r8;
  char *unaff_r9;
  char *pcVar14;
  char *unaff_r10;
  int *piVar15;
  undefined4 uVar16;
  int local_30;
  char *local_2c;
  
  local_30 = iRam00019da4 + 0x19ca2;
  local_2c = strdup(param_1);
  iVar7 = 0;
  pcVar4 = unaff_r8;
  pcVar14 = unaff_r9;
  if (local_2c == (char *)0x0) {
LAB_00019d80:
    (**(code **)(**(int **)(local_30 + iRam00019da8) + 0x14))(1,iRam00019db4 + 0x19d8e);
  }
  else {
    do {
      iVar9 = iVar7 + 0x20;
      iVar7 = iVar7 + 1;
      *(undefined1 *)((int)param_2 + iVar9) = 0;
    } while (iVar7 != 0xf);
    pcVar14 = (char *)0x0;
    pcVar3 = (char *)0x0;
    unaff_r10 = local_2c;
    do {
      unaff_r8 = pcVar3;
      unaff_r9 = strchr(unaff_r10,0x2c);
      if (unaff_r9 != (char *)0x0) {
        *unaff_r9 = '\0';
        unaff_r9 = unaff_r9 + 1;
      }
      pcVar3 = strchr(unaff_r10,0x3a);
      if (pcVar3 == (char *)0x0) {
        uVar2 = FUN_00022828(unaff_r10,param_3);
        *(undefined2 *)((int)param_2 + (int)unaff_r8 * 2 + 2) = uVar2;
      }
      else {
        if (unaff_r8 == (char *)0xe) {
          (**(code **)(**(int **)(local_30 + iRam00019da8) + 0x14))(2,iRam00019dac + 0x19d6a);
          unaff_r8 = (char *)0xe;
LAB_00019d6e:
          (**(code **)(**(int **)(local_30 + iRam00019da8) + 0x14))(2,iRam00019db0 + 0x19d7c);
          goto LAB_00019d80;
        }
        *pcVar3 = '\0';
        pcVar4 = pcVar3 + 1;
        uVar2 = FUN_00022828(unaff_r10,param_3);
        unaff_r10 = (char *)((int)param_2 + (int)unaff_r8 * 2);
        *(undefined2 *)(unaff_r10 + 2) = uVar2;
        if (pcVar4 != (char *)0x0) {
          ((char *)((int)param_2 + (int)unaff_r8))[0x20] = '\x01';
          uVar5 = FUN_00022828(pcVar4,param_3);
          unaff_r8 = unaff_r8 + 1;
          *(short *)((int)param_2 + (int)unaff_r8 * 2 + 2) = (short)uVar5;
          if (uVar5 <= *(ushort *)(unaff_r10 + 2)) goto LAB_00019d6e;
        }
      }
      unaff_r8 = unaff_r8 + 1;
      unaff_r10 = unaff_r9;
    } while ((unaff_r8 < (char *)0xf) && (pcVar3 = unaff_r8, unaff_r9 != (char *)0x0));
    *(char *)((int)param_2 + 1) = (char)unaff_r8;
    if (unaff_r9 == (char *)0x0) {
      free(local_2c);
      return extraout_r0;
    }
  }
  uVar16 = 0x19da5;
  (**(code **)(**(int **)(local_30 + iRam00019da8) + 0x14))(2,iRam00019db8 + 0x19da0);
  *extraout_r2 = extraout_r1;
  extraout_r2[1] = extraout_r2;
  extraout_r2[2] = extraout_r3;
  extraout_r2[3] = unaff_r8;
  extraout_r2[4] = unaff_r9;
  extraout_r2[5] = unaff_r10;
  uVar10 = 0xdc;
  puVar6 = extraout_r2;
  piVar1 = extraout_r3;
  piVar13 = (int *)0x1c;
  piVar15 = &local_30;
  while( true ) {
    piVar8 = piVar1;
    iVar7 = (int)param_2 << 8;
    piVar15[-1] = uVar16;
    piVar15[-2] = (int)param_2;
    piVar15[-3] = (int)piVar13;
    piVar15[-4] = uVar10;
    piVar15[-5] = (int)unaff_r8;
    piVar15[-6] = (int)pcVar14;
    piVar15[-7] = (int)pcVar4;
    piVar15[-9] = (int)puVar6;
    pcVar4 = (char *)(uint)*(ushort *)(piVar15 + 1);
    iVar11 = *(int *)*piVar15;
    iVar9 = iRam00019ea4 + 0x19dd8;
    pcVar14 = (char *)(uint)*(byte *)(piVar15 + 2);
    puVar12 = (undefined1 *)(iVar11 + 0x20);
    if (iVar7 == 0x32) {
      param_2 = *(undefined4 **)(iVar9 + iRam00019ea8);
      uVar10 = *param_2;
      uVar16 = *(undefined4 *)(iVar9 + iRam00019eac);
      piVar15[-0xc] = 0x32;
      FUN_00021dc4(uVar10,piVar15 + -9,uVar16,0);
      uVar10 = FUN_000197ac(pcVar4,pcVar14);
      FUN_00019c8c(*param_2,puVar12,uVar10);
      *puVar12 = 1;
    }
    else if (iVar7 == 0x33) {
      param_2 = *(undefined4 **)(iVar9 + iRam00019ea8);
      uVar10 = *param_2;
      uVar16 = *(undefined4 *)(iVar9 + iRam00019eac);
      piVar15[-0xc] = 0x33;
      FUN_00021dc4(uVar10,piVar15 + -9,uVar16,0);
      uVar10 = FUN_000197ac(pcVar4,pcVar14);
      FUN_00019c8c(*param_2,puVar12,uVar10);
      *puVar12 = 2;
    }
    else {
      if (iVar7 != 0x31) {
        return 0;
      }
      param_2 = *(undefined4 **)(iVar9 + iRam00019ea8);
      uVar10 = *param_2;
      uVar16 = *(undefined4 *)(iVar9 + iRam00019eac);
      piVar15[-0xc] = 0x31;
      FUN_00021dc4(uVar10,piVar15 + -9,uVar16,0);
      uVar10 = FUN_000197ac(pcVar4,pcVar14);
      FUN_00019c8c(*param_2,puVar12,uVar10);
      *puVar12 = 0;
    }
    if (piVar15[-9] != 0) {
      *(undefined1 *)(iVar11 + 0x4f) = 1;
    }
    if (*piVar8 == 0) break;
    (**(code **)(**(int **)(iVar9 + iRam00019eb0) + 0x14))(2,iRam00019eb4 + 0x19ea0);
    *extraout_r1_00 = extraout_r3_00;
    extraout_r1_00[1] = piVar8;
    piVar15[-0xd] = 0x19ea5;
    piVar15[-0xe] = 0x14;
    piVar15[-0xf] = (int)extraout_r3_00 << 7;
    piVar15[-0x14] = piVar15[-0xb];
    piVar15[-0x13] = (uint)*(ushort *)(piVar15[-0xc] + 0x80);
    uVar10 = 0x84;
    unaff_r8 = (char *)(uint)*(byte *)(piVar15[-0xc] + 0x84);
    piVar15[-0x12] = (int)unaff_r8;
    uVar16 = 0x19ed3;
    puVar6 = extraout_r2_00;
    piVar1 = extraout_r3_00;
    piVar13 = piVar8;
    piVar15 = piVar15 + -0x14;
  }
  *piVar8 = 1;
  return 1;
}



/* Function: FUN_00019dbc @ 00019dbc */

undefined4
FUN_00019dbc(int param_1,undefined4 param_2,int param_3,int *param_4,int *param_5,undefined2 param_6
            ,undefined1 param_7)

{
  undefined4 uVar1;
  undefined4 *extraout_r1;
  undefined4 extraout_r3;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  int local_24 [2];
  
  iVar3 = *param_5;
  iVar2 = iRam00019ea4 + 0x19dd8;
  puVar4 = (undefined1 *)(iVar3 + 0x20);
  local_24[0] = param_3;
  if (param_1 == 0x32) {
    puVar5 = *(undefined4 **)(iVar2 + iRam00019ea8);
    FUN_00021dc4(*puVar5,local_24,*(undefined4 *)(iVar2 + iRam00019eac),0);
    uVar1 = FUN_000197ac(param_6,param_7);
    FUN_00019c8c(*puVar5,puVar4,uVar1);
    *puVar4 = 1;
  }
  else if (param_1 == 0x33) {
    puVar5 = *(undefined4 **)(iVar2 + iRam00019ea8);
    FUN_00021dc4(*puVar5,local_24,*(undefined4 *)(iVar2 + iRam00019eac),0);
    uVar1 = FUN_000197ac(param_6,param_7);
    FUN_00019c8c(*puVar5,puVar4,uVar1);
    *puVar4 = 2;
  }
  else {
    if (param_1 != 0x31) {
      return 0;
    }
    puVar5 = *(undefined4 **)(iVar2 + iRam00019ea8);
    FUN_00021dc4(*puVar5,local_24,*(undefined4 *)(iVar2 + iRam00019eac),0);
    uVar1 = FUN_000197ac(param_6,param_7);
    FUN_00019c8c(*puVar5,puVar4,uVar1);
    *puVar4 = 0;
  }
  if (local_24[0] != 0) {
    *(undefined1 *)(iVar3 + 0x4f) = 1;
  }
  if (*param_4 == 0) {
    *param_4 = 1;
    return 1;
  }
  (**(code **)(**(int **)(iVar2 + iRam00019eb0) + 0x14))(2,iRam00019eb4 + 0x19ea0);
  *extraout_r1 = extraout_r3;
  extraout_r1[1] = param_4;
  FUN_00019dbc((int)puVar5 << 8,(int)puVar5 << 8);
                    /* WARNING: Could not recover jumptable at 0x00019ed4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)0x19ea5)();
  return uVar1;
}



/* Function: FUN_00019ed8 @ 00019ed8 */

void FUN_00019ed8(void)

{
  FUN_00019dbc();
  return;
}



/* Function: FUN_00019ef8 @ 00019ef8 */

/* WARNING: Possible PIC construction at 0x0001a0ea: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0001a0ee) */

int FUN_00019ef8(char *param_1,undefined2 *param_2,undefined4 *param_3)

{
  char *pcVar1;
  int *piVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  char *__s;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 *extraout_r2;
  undefined4 *puVar7;
  undefined4 extraout_r3;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int extraout_r3_00;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined2 *puVar14;
  char *__s_00;
  uint unaff_r9;
  int *unaff_r10;
  undefined1 *unaff_r11;
  undefined4 *puVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  
  __s = strdup(param_1);
  if (__s == (char *)0x0) {
    uVar16 = 0x19f9d;
    uVar17 = (**(code **)(**(int **)(iRam00019fa4 + 0x19f94) + 0x14))(1,iRam00019fa8 + 0x19f98);
    puVar6 = (undefined4 *)uVar17;
    *extraout_r2 = (int)((ulonglong)uVar17 >> 0x20);
    extraout_r2[1] = extraout_r3;
    puVar7 = extraout_r2 + 2;
    uVar11 = 0x2a;
    *puVar6 = puVar7;
    puVar6[1] = unaff_r10;
    puVar6[2] = unaff_r11;
    uVar10 = 0;
    piVar2 = (int *)0xd4;
    uVar9 = unaff_r9;
    puVar15 = (undefined4 *)&stack0xffffffd8;
    do {
      piVar8 = piVar2;
      puVar15[-1] = uVar16;
      puVar15[-2] = unaff_r11;
      puVar15[-3] = unaff_r10;
      puVar15[-4] = unaff_r9;
      puVar15[-5] = uVar11;
      puVar15[-6] = uVar10;
      puVar15[-7] = uVar9;
      puVar15[-8] = param_3;
      puVar15[-9] = puVar7;
      uVar9 = (uint)*(ushort *)(puVar15 + 1);
      iVar13 = *(int *)*puVar15;
      iVar12 = iRam0001a0bc + 0x19fca;
      uVar10 = (uint)*(byte *)(puVar15 + 2);
      unaff_r11 = (undefined1 *)(iVar13 + 0x20);
      if (puVar6 == (undefined4 *)0x32) {
        param_3 = *(undefined4 **)(iVar12 + iRam0001a0c0);
        uVar16 = *param_3;
        puVar15[-0xc] = 0x32;
        FUN_00021dc4(uVar16,puVar15 + -9,*(undefined4 *)(iVar12 + iRam0001a0c4),0);
        uVar16 = FUN_000197ac(uVar9,uVar10);
        uVar3 = FUN_00019ef8(*param_3,iVar13 + 0x22,uVar16);
        *(undefined1 *)(iVar13 + 0x21) = uVar3;
        *unaff_r11 = 1;
      }
      else if (puVar6 == (undefined4 *)0x33) {
        param_3 = *(undefined4 **)(iVar12 + iRam0001a0c0);
        uVar16 = *param_3;
        puVar15[-0xc] = 0x33;
        FUN_00021dc4(uVar16,puVar15 + -9,*(undefined4 *)(iVar12 + iRam0001a0c4),0);
        uVar16 = FUN_000197ac(uVar9,uVar10);
        uVar3 = FUN_00019ef8(*param_3,iVar13 + 0x22,uVar16);
        *(undefined1 *)(iVar13 + 0x21) = uVar3;
        *unaff_r11 = 2;
      }
      else {
        if (puVar6 != (undefined4 *)0x31) {
          return 0;
        }
        param_3 = *(undefined4 **)(iVar12 + iRam0001a0c0);
        uVar16 = *param_3;
        puVar15[-0xc] = 0x31;
        FUN_00021dc4(uVar16,puVar15 + -9,*(undefined4 *)(iVar12 + iRam0001a0c4),0);
        uVar16 = FUN_000197ac(uVar9,uVar10);
        uVar3 = FUN_00019ef8(*param_3,iVar13 + 0x22,uVar16);
        *(undefined1 *)(iVar13 + 0x21) = uVar3;
        *unaff_r11 = 0;
      }
      if (puVar15[-9] == 0) {
        if (*piVar8 == 0) {
          *piVar8 = 1;
          return 1;
        }
      }
      else {
        (**(code **)(**(int **)(iVar12 + iRam0001a0c8) + 0x14))(2,iRam0001a0cc + 0x1a0a8);
      }
      (**(code **)(**(int **)(iVar12 + iRam0001a0c8) + 0x14))(2,iRam0001a0d0 + 0x1a0b8);
      puVar6 = (undefined4 *)((int)unaff_r11 * 0x100);
      puVar7 = (undefined4 *)0xfc;
      puVar15[-0xd] = 0x1a0bd;
      puVar15[-0xe] = iVar13;
      puVar15[-0xf] = extraout_r3_00 << 7;
      puVar15[-0x14] = puVar15[-0xb];
      puVar15[-0x13] = (uint)*(ushort *)(puVar15[-0xc] + 0x80);
      unaff_r9 = 0x84;
      uVar11 = (uint)*(byte *)(puVar15[-0xc] + 0x84);
      puVar15[-0x12] = uVar11;
      uVar16 = 0x1a0ef;
      piVar2 = (int *)0x30;
      unaff_r10 = piVar8;
      puVar15 = puVar15 + -0x14;
    } while( true );
  }
  pcVar5 = strchr(__s,0x2c);
  uVar10 = 0;
  pcVar1 = __s;
  puVar14 = param_2;
  while (pcVar5 != (char *)0x0) {
    *pcVar5 = '\0';
    __s_00 = pcVar5 + 1;
    uVar4 = FUN_00022828(pcVar1,param_3);
    *puVar14 = uVar4;
    puVar14 = puVar14 + 1;
    if (uVar10 + 1 < 0xf) goto LAB_00019f56;
    do {
      if (__s_00 == (char *)0x0) goto LAB_00019f76;
      (**(code **)(**(int **)(iRam00019f9c + 0x19f4e) + 0x14))(2,iRam00019fa0 + 0x19f52);
LAB_00019f56:
    } while (__s_00 == (char *)0x0);
    pcVar5 = strchr(__s_00,0x2c);
    uVar10 = uVar10 + 1;
    pcVar1 = __s_00;
  }
  uVar4 = FUN_00022828(pcVar1,param_3);
  param_2[uVar10] = uVar4;
LAB_00019f76:
  free(__s);
  return uVar10 + 1;
}



/* Function: FUN_00019fac @ 00019fac */

undefined4
FUN_00019fac(int param_1,int param_2,int param_3,int *param_4,int *param_5,undefined2 param_6,
            undefined1 param_7)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 local_2c;
  int local_24;
  
  iVar5 = *param_5;
  iVar4 = iRam0001a0bc + 0x19fca;
  puVar6 = (undefined1 *)(iVar5 + 0x20);
  local_24 = param_3;
  if (param_1 == 0x32) {
    puVar3 = *(undefined4 **)(iVar4 + iRam0001a0c0);
    FUN_00021dc4(*puVar3,&local_24,*(undefined4 *)(iVar4 + iRam0001a0c4),0);
    uVar2 = FUN_000197ac(param_6,param_7);
    uVar1 = FUN_00019ef8(*puVar3,iVar5 + 0x22,uVar2);
    *(undefined1 *)(iVar5 + 0x21) = uVar1;
    *puVar6 = 1;
  }
  else if (param_1 == 0x33) {
    puVar3 = *(undefined4 **)(iVar4 + iRam0001a0c0);
    FUN_00021dc4(*puVar3,&local_24,*(undefined4 *)(iVar4 + iRam0001a0c4),0);
    uVar2 = FUN_000197ac(param_6,param_7);
    uVar1 = FUN_00019ef8(*puVar3,iVar5 + 0x22,uVar2);
    *(undefined1 *)(iVar5 + 0x21) = uVar1;
    *puVar6 = 2;
  }
  else {
    if (param_1 != 0x31) {
      return 0;
    }
    puVar3 = *(undefined4 **)(iVar4 + iRam0001a0c0);
    FUN_00021dc4(*puVar3,&local_24,*(undefined4 *)(iVar4 + iRam0001a0c4),0);
    uVar2 = FUN_000197ac(param_6,param_7);
    uVar1 = FUN_00019ef8(*puVar3,iVar5 + 0x22,uVar2);
    *(undefined1 *)(iVar5 + 0x21) = uVar1;
    *puVar6 = 0;
  }
  if (local_24 == 0) {
    if (*param_4 == 0) {
      *param_4 = 1;
      return 1;
    }
  }
  else {
    (**(code **)(**(int **)(iVar4 + iRam0001a0c8) + 0x14))(2,iRam0001a0cc + 0x1a0a8);
  }
  (**(code **)(**(int **)(iVar4 + iRam0001a0c8) + 0x14))(2,iRam0001a0d0 + 0x1a0b8);
  FUN_00019fac((int)puVar6 * 0x100,(int)puVar6 * 0x100,0xfc,0x30,local_2c,
               *(undefined2 *)(param_2 + 0x80),*(undefined1 *)(param_2 + 0x84));
                    /* WARNING: Could not recover jumptable at 0x0001a0f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)0x1a0bd)();
  return uVar2;
}



/* Function: FUN_0001a0f4 @ 0001a0f4 */

void FUN_0001a0f4(void)

{
  FUN_00019fac();
  return;
}



/* Function: FUN_0001a140 @ 0001a140 */

void FUN_0001a140(void)

{
  FUN_00022bd8(DAT_0001a14c + 0x1a148);
  return;
}



/* Function: FUN_0001a150 @ 0001a150 */

void FUN_0001a150(int *param_1,undefined4 param_2)

{
  if ((char)param_1[3] != '\0') {
    printf(PTR_DAT_0001a1b0 + 0x1a198);
    FUN_00021e64(param_1 + 3);
  }
  if ((short)param_1[1] != 0) {
    printf(PTR_DAT_0001a1ac + 0x1a18e,param_2);
  }
  if (*param_1 != 0) {
    printf(PTR_DAT_0001a1a8 + 0x1a182,param_2);
  }
  if (*(short *)((int)param_1 + 6) != 0) {
    printf(PTR_DAT_0001a1a4 + 0x1a176,param_2);
  }
  return;
}



/* Function: FUN_0001a1b4 @ 0001a1b4 */

void FUN_0001a1b4(undefined4 param_1,int param_2)

{
  FUN_0001a150(param_2 + 0x20,DAT_0001a1c4 + 0x1a1c0);
  return;
}



/* Function: FUN_0001a1c8 @ 0001a1c8 */

void FUN_0001a1c8(undefined4 param_1,int param_2)

{
  FUN_0001a150(param_2 + 0x20,DAT_0001a1d8 + 0x1a1d4);
  return;
}



/* Function: FUN_0001a3e4 @ 0001a3e4 */

void FUN_0001a3e4(void)

{
  puts((char *)(DAT_0001a3f0 + 0x1a3ec));
  return;
}



/* Function: FUN_0001a3fc @ 0001a3fc */

void FUN_0001a3fc(void)

{
  int iVar1;
  
  iVar1 = DAT_0001a414;
  FUN_00022bd8(DAT_0001a414 + 0x1a404);
  FUN_00022bd8(iVar1 + 0x1a44c);
  return;
}



/* Function: FUN_0001a484 @ 0001a484 */

void FUN_0001a484(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_0001a494 + 0x1a48e),(uint)*(ushort *)(param_2 + 0x20));
  return;
}



/* Function: FUN_0001a64c @ 0001a64c */

void FUN_0001a64c(void)

{
  puts((char *)(DAT_0001a658 + 0x1a654));
  return;
}



/* Function: FUN_0001a670 @ 0001a670 */

void FUN_0001a670(void)

{
  FUN_00022bd8(DAT_0001a67c + 0x1a678);
  return;
}



/* Function: FUN_0001a6a4 @ 0001a6a4 */

void FUN_0001a6a4(void)

{
  FUN_0002310c(DAT_0001a6b0 + 0x1a6ac);
  return;
}



/* Function: FUN_0001a6b4 @ 0001a6b4 */

void FUN_0001a6b4(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x44) << 0x1c < 0) {
    iVar1 = (int)&DAT_0001a6d4 + DAT_0001a6dc;
  }
  else {
    iVar1 = DAT_0001a6d4 + 0x1a6c6;
  }
  printf((char *)(DAT_0001a6d8 + 0x1a6ca),iVar1);
  return;
}



/* Function: FUN_0001a6e0 @ 0001a6e0 */

void FUN_0001a6e0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x44) << 0x1c < 0) {
    iVar1 = (int)&DAT_0001a700 + DAT_0001a708;
  }
  else {
    iVar1 = DAT_0001a700 + 0x1a6f2;
  }
  printf((char *)(DAT_0001a704 + 0x1a6f6),iVar1);
  return;
}



/* Function: FUN_0001a8c8 @ 0001a8c8 */

void FUN_0001a8c8(void)

{
  FUN_000232e4(DAT_0001a8d8 + 0x1a8d2,3);
  return;
}



/* Function: FUN_0001a8dc @ 0001a8dc */

void FUN_0001a8dc(__uid_t *param_1,undefined4 param_2,byte param_3,int param_4)

{
  passwd *ppVar1;
  group *pgVar2;
  __uid_t _Var3;
  char *__format;
  
  if ((param_3 & (byte)param_1[4]) == 0) {
    return;
  }
  if ((param_3 & *(byte *)((int)param_1 + 0x11)) != 0) {
    printf((char *)(DAT_0001a998 + 0x1a96a));
  }
  __format = (char *)(DAT_0001a990 + 0x1a8fe);
  printf(__format,param_2);
  param_3 = param_3 & (byte)param_1[4];
  if (param_3 == 1) {
    _Var3 = *param_1;
    if (_Var3 != param_1[1]) {
      printf((char *)(DAT_0001a99c + 0x1a974));
      return;
    }
    if (param_4 == 0) {
      ppVar1 = getpwuid(_Var3);
      if ((ppVar1 != (passwd *)0x0) && (ppVar1->pw_name != (char *)0x0)) goto LAB_0001a932;
      _Var3 = *param_1;
    }
    printf((char *)(DAT_0001a9a4 + 0x1a98a),_Var3);
  }
  else {
    if (param_3 != 2) {
      return;
    }
    _Var3 = param_1[2];
    if (_Var3 != param_1[3]) {
      printf((char *)(DAT_0001a9a0 + 0x1a97e));
      return;
    }
    if (param_4 == 0) {
      pgVar2 = getgrgid(_Var3);
      if ((pgVar2 != (group *)0x0) && (pgVar2->gr_name != (char *)0x0)) {
LAB_0001a932:
        printf(__format);
        return;
      }
      _Var3 = param_1[2];
    }
    printf((char *)(DAT_0001a994 + 0x1a960),_Var3);
  }
  return;
}



/* Function: FUN_0001aa2c @ 0001aa2c */

void FUN_0001aa2c(__uid_t *param_1,undefined4 param_2,byte param_3,int param_4)

{
  group *pgVar1;
  passwd *ppVar2;
  char *__format;
  
  if ((param_3 & (byte)param_1[8]) == 0) {
    return;
  }
  if ((param_3 & *(byte *)((int)param_1 + 0x21)) != 0) {
    printf((char *)(DAT_0001aaec + 0x1aa88));
  }
  __format = (char *)(DAT_0001aae4 + 0x1aa52);
  printf(__format,param_2);
  param_3 = param_3 & (byte)param_1[8];
  if (param_3 == 2) {
    if (((param_4 != 0) || (pgVar1 = getgrgid(param_1[1]), pgVar1 == (group *)0x0)) ||
       (pgVar1->gr_name == (char *)0x0)) {
      printf(PTR_LAB_0001aaf8 + 0x1aae0,param_1[1]);
      return;
    }
  }
  else {
    if (2 < param_3) {
      if (param_3 == 4) {
        printf(PTR_DAT_0001aaf0 + 0x1aab2,param_1[2]);
        return;
      }
      if (param_3 != 8) {
        return;
      }
      printf((char *)(DAT_0001aae8 + 0x1aa7e),param_1[3]);
      return;
    }
    if (param_3 != 1) {
      return;
    }
    if (((param_4 != 0) || (ppVar2 = getpwuid(*param_1), ppVar2 == (passwd *)0x0)) ||
       (ppVar2->pw_name == (char *)0x0)) {
      printf(PTR_LAB_0001aaf4 + 0x1aad4,*param_1);
      return;
    }
  }
  printf(__format);
  return;
}



/* Function: FUN_0001aafc @ 0001aafc */

void FUN_0001aafc(undefined4 param_1,int param_2)

{
  param_2 = param_2 + 0x20;
  FUN_0001aa2c(param_2,PTR_DAT_0001ab3c + 0x1ab0a,1,1);
  FUN_0001aa2c(param_2,PTR_DAT_0001ab40 + 0x1ab1a,2,1);
  FUN_0001aa2c(param_2,PTR_DAT_0001ab44 + 0x1ab28,4,1);
  FUN_0001aa2c(param_2,PTR_DAT_0001ab48 + 0x1ab36,8,1);
  return;
}



/* Function: FUN_0001ab4c @ 0001ab4c */

void FUN_0001ab4c(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  
  param_2 = param_2 + 0x20;
  bVar1 = param_3 != 0;
  FUN_0001aa2c(param_2,PTR_DAT_0001ab94 + 0x1ab62,1,bVar1);
  FUN_0001aa2c(param_2,PTR_DAT_0001ab98 + 0x1ab70,2,bVar1);
  FUN_0001aa2c(param_2,PTR_DAT_0001ab9c + 0x1ab7e,4,bVar1);
  FUN_0001aa2c(param_2,PTR_DAT_0001aba0 + 0x1ab8c,8,bVar1);
  return;
}



/* Function: FUN_0001aba4 @ 0001aba4 */

void FUN_0001aba4(__uid_t *param_1,undefined4 param_2,byte param_3,int param_4)

{
  group *pgVar1;
  passwd *ppVar2;
  char *__format;
  
  if ((param_3 & (byte)param_1[8]) == 0) {
    return;
  }
  if ((param_3 & *(byte *)((int)param_1 + 0x21)) != 0) {
    printf(PTR_s_libc_so_0001ac64 + 0x1ac00);
  }
  __format = (char *)(DAT_0001ac5c + 0x1abca);
  printf(__format,param_2);
  param_3 = param_3 & (byte)param_1[8];
  if (param_3 == 2) {
    if (((param_4 != 0) || (pgVar1 = getgrgid(param_1[1]), pgVar1 == (group *)0x0)) ||
       (pgVar1->gr_name == (char *)0x0)) {
      printf(PTR_LAB_0001ac70 + 0x1ac58,param_1[1]);
      return;
    }
  }
  else {
    if (2 < param_3) {
      if (param_3 == 4) {
        printf(PTR_LAB_0001ac68 + 0x1ac2a,param_1[2]);
        return;
      }
      if (param_3 != 8) {
        return;
      }
      printf(PTR_DAT_0001ac60 + 0x1abf6,param_1[3]);
      return;
    }
    if (param_3 != 1) {
      return;
    }
    if (((param_4 != 0) || (ppVar2 = getpwuid(*param_1), ppVar2 == (passwd *)0x0)) ||
       (ppVar2->pw_name == (char *)0x0)) {
      printf(PTR_LAB_0001ac6c + 0x1ac4c,*param_1);
      return;
    }
  }
  printf(__format);
  return;
}



/* Function: FUN_0001ac74 @ 0001ac74 */

void FUN_0001ac74(undefined4 param_1,int param_2)

{
  param_2 = param_2 + 0x20;
  FUN_0001aba4(param_2,PTR_DAT_0001acb4 + 0x1ac82,1,1);
  FUN_0001aba4(param_2,PTR_DAT_0001acb8 + 0x1ac92,2,1);
  FUN_0001aba4(param_2,PTR_LAB_0001acbc + 0x1aca0,4,1);
  FUN_0001aba4(param_2,PTR_LAB_0001acc0 + 0x1acae,8,1);
  return;
}



/* Function: FUN_0001acc4 @ 0001acc4 */

void FUN_0001acc4(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  
  param_2 = param_2 + 0x20;
  bVar1 = param_3 != 0;
  FUN_0001aba4(param_2,PTR_DAT_0001ad0c + 0x1acda,1,bVar1);
  FUN_0001aba4(param_2,PTR_DAT_0001ad10 + 0x1ace8,2,bVar1);
  FUN_0001aba4(param_2,PTR_DAT_0001ad14 + 0x1acf6,4,bVar1);
  FUN_0001aba4(param_2,PTR_DAT_0001ad18 + 0x1ad04,8,bVar1);
  return;
}



/* Function: FUN_0001ad1c @ 0001ad1c */

void FUN_0001ad1c(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  char cVar2;
  char *local_1c;
  
  iVar1 = FUN_000224cc(param_1,&local_1c,param_2,0,0xfffffffe);
  if (iVar1 == 0) {
    FUN_000221e0(7,PTR_DAT_0001adac + 0x1ad92,param_4,param_1);
  }
  *param_3 = *param_2;
  cVar2 = *local_1c;
  if ((cVar2 == ':') || (cVar2 == '-')) {
    iVar1 = FUN_000224cc(local_1c + 1,&local_1c,param_3,0,0xfffffffe);
    if (iVar1 == 0) {
      FUN_000221e0(7,PTR_DAT_0001adb0 + 0x1ada2,param_4,param_1);
    }
    cVar2 = *local_1c;
  }
  if (cVar2 != '\0') {
    FUN_000221e0(7,PTR_DAT_0001ada8 + 0x1ad60,param_4,param_1);
  }
  return;
}



/* Function: FUN_0001adb4 @ 0001adb4 */

undefined4
FUN_0001adb4(int param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5,
            int *param_6)

{
  undefined4 uVar1;
  group *pgVar2;
  passwd *ppVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined *puVar6;
  __gid_t local_28;
  __gid_t local_24 [2];
  
  iVar5 = *param_6;
  if (param_1 == 0x6b) {
    FUN_000221e0(5,PTR_LAB_0001af00 + 0x1ae9e,PTR_DAT_0001af04 + 0x1aea2,*param_4 & 4);
    if (param_3 != 0) {
      *(byte *)(iVar5 + 0x31) = *(byte *)(iVar5 + 0x31) | 4;
    }
    uVar1 = 1;
    *(byte *)(iVar5 + 0x30) = *(byte *)(iVar5 + 0x30) | 4;
    *param_4 = *param_4 | 4;
  }
  else if (param_1 == 0x75) {
    puVar6 = PTR_DAT_0001aef4 + 0x1ae48;
    FUN_000221e0(5,PTR_LAB_0001aef8 + 0x1ae4e,puVar6,*param_4 & 1);
    puVar4 = *(undefined4 **)(PTR_LAB_0001aefc + 0x1ae58);
    ppVar3 = getpwnam((char *)*puVar4);
    if (ppVar3 == (passwd *)0x0) {
      FUN_0001ad1c(*puVar4,local_24,&local_28,puVar6);
    }
    else {
      local_28 = ppVar3->pw_uid;
      local_24[0] = local_28;
    }
    if (param_3 != 0) {
      *(byte *)(iVar5 + 0x31) = *(byte *)(iVar5 + 0x31) | 1;
    }
    uVar1 = 1;
    *(byte *)(iVar5 + 0x30) = *(byte *)(iVar5 + 0x30) | 1;
    *(__gid_t *)(iVar5 + 0x20) = local_24[0];
    *(__gid_t *)(iVar5 + 0x24) = local_28;
    *param_4 = *param_4 | 1;
  }
  else {
    uVar1 = 0;
    if (param_1 == 0x67) {
      puVar6 = PTR_s_BFS_RF_0001aee8 + 0x1adf0;
      FUN_000221e0(5,PTR_DAT_0001aeec + 0x1adf6,puVar6,*param_4 & 2);
      puVar4 = *(undefined4 **)(PTR_LAB_0001aef0 + 0x1ae00);
      pgVar2 = getgrnam((char *)*puVar4);
      if (pgVar2 == (group *)0x0) {
        FUN_0001ad1c(*puVar4,local_24,&local_28,puVar6);
      }
      else {
        local_28 = pgVar2->gr_gid;
        local_24[0] = local_28;
      }
      if (param_3 != 0) {
        *(byte *)(iVar5 + 0x31) = *(byte *)(iVar5 + 0x31) | 2;
      }
      uVar1 = 1;
      *(byte *)(iVar5 + 0x30) = *(byte *)(iVar5 + 0x30) | 2;
      *(__gid_t *)(iVar5 + 0x28) = local_24[0];
      *(__gid_t *)(iVar5 + 0x2c) = local_28;
      *param_4 = *param_4 | 2;
    }
  }
  return uVar1;
}



/* Function: FUN_0001af08 @ 0001af08 */

undefined4
FUN_0001af08(int param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5,
            int *param_6)

{
  undefined *puVar1;
  group *pgVar2;
  passwd *ppVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  __gid_t local_24;
  
  puVar1 = PTR_LAB_0001b11c;
  iVar6 = *param_6;
  if (param_1 == 0x70) {
    puVar7 = PTR_DAT_0001b138 + 0x1b00a;
    puVar9 = PTR_LAB_0001b134 + 0x1b00c;
    FUN_000221e0(5,puVar7,puVar9,*param_4 & 8);
    puVar5 = *(undefined4 **)(puVar1 + DAT_0001b128 + 0x1af22);
    iVar4 = FUN_000224cc(*puVar5,0,&local_24,0,DAT_0001b13c);
    if (iVar4 == 0) {
      FUN_000221e0(7,puVar7,puVar9,*puVar5);
    }
    if (param_3 != 0) {
      *(byte *)(iVar6 + 0x41) = *(byte *)(iVar6 + 0x41) | 4;
    }
    *(byte *)(iVar6 + 0x40) = *(byte *)(iVar6 + 0x40) | 4;
    *(__gid_t *)(iVar6 + 0x28) = local_24;
    *param_4 = *param_4 | 8;
    return 1;
  }
  if (param_1 < 0x71) {
    if (param_1 == 0x67) {
      puVar7 = PTR_DAT_0001b124 + 0x1af58;
      puVar9 = PTR_DAT_0001b120 + 0x1af5a;
      FUN_000221e0(5,puVar7,puVar9,*param_4 & 2);
      puVar5 = *(undefined4 **)(puVar1 + DAT_0001b128 + 0x1af22);
      pgVar2 = getgrnam((char *)*puVar5);
      if (pgVar2 == (group *)0x0) {
        iVar4 = FUN_000224cc(*puVar5,0,&local_24,0,0xfffffffe);
        if (iVar4 == 0) {
          FUN_000221e0(7,puVar7,puVar9,*puVar5);
        }
      }
      else {
        local_24 = pgVar2->gr_gid;
      }
      if (param_3 != 0) {
        *(byte *)(iVar6 + 0x41) = *(byte *)(iVar6 + 0x41) | 2;
      }
      *(byte *)(iVar6 + 0x40) = *(byte *)(iVar6 + 0x40) | 2;
      *(__gid_t *)(iVar6 + 0x24) = local_24;
      *param_4 = *param_4 | 2;
      return 1;
    }
  }
  else {
    if (param_1 == 0x73) {
      iVar8 = DAT_0001b144 + 0x1b066;
      iVar10 = DAT_0001b140 + 0x1b068;
      FUN_000221e0(5,iVar8,iVar10,*param_4 & 0x10);
      puVar5 = *(undefined4 **)(puVar1 + DAT_0001b128 + 0x1af22);
      iVar4 = FUN_000224cc(*puVar5,0,&local_24,0,DAT_0001b13c);
      if (iVar4 == 0) {
        FUN_000221e0(7,iVar8,iVar10,*puVar5);
      }
      if (param_3 != 0) {
        *(byte *)(iVar6 + 0x41) = *(byte *)(iVar6 + 0x41) | 8;
      }
      *(byte *)(iVar6 + 0x40) = *(byte *)(iVar6 + 0x40) | 8;
      *(__gid_t *)(iVar6 + 0x2c) = local_24;
      *param_4 = *param_4 | 0x10;
      return 1;
    }
    if (param_1 == 0x75) {
      puVar7 = PTR_DAT_0001b12c + 0x1afb0;
      puVar9 = PTR_PTR_0001b130 + 0x1afb8;
      FUN_000221e0(5,puVar7,puVar9,*param_4 & 1);
      puVar5 = *(undefined4 **)(puVar1 + DAT_0001b128 + 0x1af22);
      ppVar3 = getpwnam((char *)*puVar5);
      if (ppVar3 == (passwd *)0x0) {
        iVar4 = FUN_000224cc(*puVar5,0,&local_24,0,0xfffffffe);
        if (iVar4 == 0) {
          FUN_000221e0(7,puVar7,puVar9,*puVar5);
        }
      }
      else {
        local_24 = ppVar3->pw_uid;
      }
      if (param_3 != 0) {
        *(byte *)(iVar6 + 0x41) = *(byte *)(iVar6 + 0x41) | 1;
      }
      *(byte *)(iVar6 + 0x40) = *(byte *)(iVar6 + 0x40) | 1;
      *(__gid_t *)(iVar6 + 0x20) = local_24;
      *param_4 = *param_4 | 1;
      return 1;
    }
  }
  return 0;
}



/* Function: FUN_0001b3e0 @ 0001b3e0 */

void FUN_0001b3e0(void)

{
  FUN_0002310c(DAT_0001b3ec + 0x1b3e8);
  return;
}



/* Function: FUN_0001b3f0 @ 0001b3f0 */

void FUN_0001b3f0(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_2 + 0x61);
  if ((bVar1 & 8) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 8) == 0) {
      puVar2 = (undefined *)(DAT_0001b4b4 + 0x1b40e);
    }
    else {
      puVar2 = &UNK_0001b4b2 + DAT_0001b4ec;
    }
    printf((char *)(DAT_0001b4b8 + 0x1b412),puVar2);
    bVar1 = *(byte *)(param_2 + 0x61);
  }
  if ((bVar1 & 1) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 1) == 0) {
      iVar3 = DAT_0001b4bc + 0x1b42c;
    }
    else {
      iVar3 = DAT_0001b4e8 + 0x1b4ac;
    }
    printf((char *)(DAT_0001b4c0 + 0x1b432),iVar3,param_2 + 0x20);
    bVar1 = *(byte *)(param_2 + 0x61);
  }
  if ((bVar1 & 0x10) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 0x10) == 0) {
      iVar3 = DAT_0001b4c4 + 0x1b44c;
    }
    else {
      iVar3 = DAT_0001b4e4 + 0x1b4a6;
    }
    printf((char *)(DAT_0001b4c8 + 0x1b450),iVar3);
    bVar1 = *(byte *)(param_2 + 0x61);
  }
  if ((bVar1 & 2) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 2) == 0) {
      iVar3 = DAT_0001b4cc + 0x1b46a;
    }
    else {
      iVar3 = DAT_0001b4e0 + 0x1b4a0;
    }
    printf((char *)(DAT_0001b4d0 + 0x1b472),iVar3,param_2 + 0x40);
    bVar1 = *(byte *)(param_2 + 0x61);
  }
  if ((bVar1 & 4) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 4) == 0) {
      iVar3 = DAT_0001b4d4 + 0x1b48c;
    }
    else {
      iVar3 = DAT_0001b4dc + 0x1b49a;
    }
    printf((char *)(DAT_0001b4d8 + 0x1b490),iVar3);
  }
  return;
}



/* Function: FUN_0001b4f0 @ 0001b4f0 */

void FUN_0001b4f0(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined *puVar2;
  
  printf(PTR_DAT_0001b5c0 + 0x1b4fc);
  bVar1 = *(byte *)(param_2 + 0x61);
  if ((bVar1 & 8) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 8) == 0) {
      puVar2 = PTR_LAB_0001b5c4 + 0x1b516;
    }
    else {
      puVar2 = PTR_DAT_0001b5fc + 0x1b5c0;
    }
    printf(PTR_DAT_0001b5c8 + 0x1b51a,puVar2);
    bVar1 = *(byte *)(param_2 + 0x61);
  }
  if ((bVar1 & 1) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 1) == 0) {
      puVar2 = (undefined *)(DAT_0001b5cc + 0x1b534);
    }
    else {
      puVar2 = PTR_DAT_0001b5f8 + 0x1b5ba;
    }
    printf((char *)(DAT_0001b5d0 + 0x1b53a),puVar2,param_2 + 0x20);
    bVar1 = *(byte *)(param_2 + 0x61);
  }
  if ((bVar1 & 0x10) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 0x10) == 0) {
      puVar2 = (undefined *)(DAT_0001b5d4 + 0x1b554);
    }
    else {
      puVar2 = PTR_DAT_0001b5f4 + 0x1b5b4;
    }
    printf((char *)(DAT_0001b5d8 + 0x1b558),puVar2);
    bVar1 = *(byte *)(param_2 + 0x61);
  }
  if ((bVar1 & 2) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 2) == 0) {
      puVar2 = (undefined *)(DAT_0001b5dc + 0x1b572);
    }
    else {
      puVar2 = PTR_DAT_0001b5f0 + 0x1b5ae;
    }
    printf((char *)(DAT_0001b5e0 + 0x1b57a),puVar2,param_2 + 0x40);
    bVar1 = *(byte *)(param_2 + 0x61);
  }
  if ((bVar1 & 4) != 0) {
    if ((*(byte *)(param_2 + 0x60) & 4) == 0) {
      puVar2 = (undefined *)(DAT_0001b5e4 + 0x1b594);
    }
    else {
      puVar2 = PTR_DAT_0001b5ec + 0x1b5a8;
    }
    printf(PTR_DAT_0001b5e8 + 0x1b598,puVar2);
  }
  putchar(0x20);
  return;
}



/* Function: FUN_0001b600 @ 0001b600 */

undefined4 FUN_0001b600(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 0x31U < 5) {
                    /* WARNING: Could not emulate address calculation at 0x0001b622 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)((param_1 - 0x31U) * 4 + iRam0001b798 + 0x1b624) +
                      iRam0001b798 + 0x1b624))();
    return uVar1;
  }
  return 0;
}



/* Function: FUN_0001b7e0 @ 0001b7e0 */

void FUN_0001b7e0(void)

{
  FUN_0002310c(DAT_0001b7ec + 0x1b7e8);
  return;
}



/* Function: FUN_0001b7f0 @ 0001b7f0 */

void FUN_0001b7f0(undefined4 param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  
  if (*(int *)(param_2 + 0x24) == 0) {
    iVar1 = DAT_0001b844 + 0x1b800;
  }
  else {
    iVar1 = DAT_0001b854 + 0x1b82e;
  }
  printf((char *)(DAT_0001b848 + 0x1b804),iVar1);
  iVar1 = 0;
  pbVar2 = (byte *)(DAT_0001b84c + 0x1b814);
  do {
    if ((uint)*pbVar2 == *(uint *)(param_2 + 0x20)) {
      printf((char *)(DAT_0001b85c + 0x1b840),*(undefined4 *)(iVar1 * 0xc + DAT_0001b858 + 0x1b83a))
      ;
      return;
    }
    iVar1 = iVar1 + 1;
    pbVar2 = pbVar2 + 0xc;
  } while (iVar1 != 6);
  printf((char *)(DAT_0001b850 + 0x1b824));
  return;
}



/* Function: FUN_0001b860 @ 0001b860 */

void FUN_0001b860(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  byte *pbVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 0x24) == 0) {
    puVar1 = (undefined *)(DAT_0001b8b4 + 0x1b870);
  }
  else {
    puVar1 = PTR_LAB_0001b8c4 + 0x1b89e;
  }
  printf(PTR_DAT_0001b8b8 + 0x1b874,puVar1);
  iVar3 = 0;
  pbVar2 = PTR_LAB_0001b8bc + 0x1b884;
  do {
    if ((uint)*pbVar2 == *(uint *)(param_2 + 0x20)) {
      printf((char *)(DAT_0001b8cc + 0x1b8b0),
             *(undefined4 *)(PTR_LAB_0001b8c8 + iVar3 * 0xc + 0x1b8aa));
      return;
    }
    iVar3 = iVar3 + 1;
    pbVar2 = pbVar2 + 0xc;
  } while (iVar3 != 6);
  printf(PTR_DAT_0001b8c0 + 0x1b894);
  return;
}



/* Function: FUN_0001b8d0 @ 0001b8d0 */

undefined4
FUN_0001b8d0(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined4 param_5,
            int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  char *__s1;
  int iVar5;
  int local_1c;
  
  iVar5 = *param_6;
  uVar2 = 0;
  if (param_1 == 0x31) {
    iVar4 = 0;
    puVar3 = *(undefined4 **)(PTR_DAT_0001b960 + 0x1b8f8);
    local_1c = param_3;
    FUN_00021dc4(*puVar3,&local_1c,*(undefined4 *)(PTR_DAT_0001b964 + 0x1b900),0,param_2);
    __s1 = (char *)*puVar3;
    puVar3 = (undefined4 *)(PTR_LAB_0001b968 + 0x1b912);
    do {
      iVar1 = strcasecmp(__s1,(char *)*puVar3);
      if (iVar1 == 0) goto LAB_0001b938;
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 3;
    } while (iVar4 != 6);
    (**(code **)(**(int **)(PTR_DAT_0001b96c + 0x1b92e) + 0x14))(2,PTR_DAT_0001b970 + 0x1b932,__s1);
LAB_0001b938:
    *(uint *)(iVar5 + 0x20) = (uint)(byte)PTR_LAB_0001b974[iVar4 * 0xc + 0x1b946];
    if (local_1c != 0) {
      *(undefined4 *)(iVar5 + 0x24) = 1;
    }
    uVar2 = 1;
    *param_4 = 1;
  }
  return uVar2;
}



/* Function: FUN_0001bb30 @ 0001bb30 */

void FUN_0001bb30(void)

{
  FUN_000232e4(DAT_0001bb40 + 0x1bb3a,2);
  return;
}



/* Function: FUN_0001bb44 @ 0001bb44 */

void FUN_0001bb44(undefined4 param_1,int param_2)

{
  ushort uVar1;
  
  if ((int)((uint)*(ushort *)(param_2 + 0x130) << 0x1f) < 0) {
    printf(PTR_DAT_0001bba8 + 0x1bb5c,param_1);
    uVar1 = *(ushort *)(param_2 + 0x130);
  }
  else {
    printf(PTR_DAT_0001bbb4 + 0x1bb90,param_1);
    uVar1 = *(ushort *)(param_2 + 0x130);
  }
  if ((int)((uint)uVar1 << 0x1d) < 0) {
    printf(PTR_DAT_0001bbac + 0x1bb70,param_1);
  }
  else {
    printf(PTR_DAT_0001bbb8 + 0x1bba4,param_1);
  }
  if ((int)((uint)*(ushort *)(param_2 + 0x130) << 0x1c) < 0) {
    printf(PTR_DAT_0001bbb0 + 0x1bb84,param_1);
  }
  return;
}



/* Function: FUN_0001bbbc @ 0001bbbc */

void FUN_0001bbbc(undefined4 param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  protoent *ppVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *__format;
  byte bVar5;
  
  bVar5 = *(byte *)(param_2 + 0x4a);
  if ((bVar5 & 0x20) != 0) {
    if ((*(byte *)(param_2 + 0x4b) & 0x20) != 0) {
      printf((char *)(DAT_0001bdc0 + 0x1bd04));
    }
    printf(PTR_DAT_0001bd98 + 0x1bbe8,param_1,*(undefined4 *)(param_2 + 0x44));
    bVar5 = *(byte *)(param_2 + 0x4a);
  }
  if ((bVar5 & 0x10) != 0) {
    if ((*(byte *)(param_2 + 0x4b) & 0x10) != 0) {
      printf((char *)(DAT_0001bdc4 + 0x1bd0e));
    }
    printf(PTR_DAT_0001bd9c + 0x1bc08,param_1,*(undefined4 *)(param_2 + 0x40));
    bVar5 = *(byte *)(param_2 + 0x4a);
  }
  if ((bVar5 & 4) != 0) {
    if ((*(byte *)(param_2 + 0x4b) & 4) != 0) {
      printf((char *)(DAT_0001bdc8 + 0x1bd18));
    }
    bVar5 = *(byte *)(param_2 + 0x48);
    printf(PTR_DAT_0001bda0 + 0x1bc2a,param_1);
    if ((param_3 == 0) && (ppVar2 = getprotobynumber((uint)bVar5), ppVar2 != (protoent *)0x0)) {
      printf((char *)(DAT_0001bdcc + 0x1bd30),ppVar2->p_name);
      bVar5 = *(byte *)(param_2 + 0x4a);
    }
    else {
      printf(PTR_DAT_0001bda4 + 0x1bc3c,(uint)bVar5);
      bVar5 = *(byte *)(param_2 + 0x4a);
    }
  }
  if ((bVar5 & 8) != 0) {
    if ((*(byte *)(param_2 + 0x4b) & 8) != 0) {
      printf((char *)(DAT_0001bdd4 + 0x1bd4c));
    }
    cVar1 = *(char *)(param_2 + 0x49);
    printf(PTR_DAT_0001bda8 + 0x1bc5e,param_1);
    if (cVar1 == '\0') {
      printf(PTR_DAT_0001bdac + 0x1bc6a);
      bVar5 = *(byte *)(param_2 + 0x4a);
    }
    else if (cVar1 == '\x01') {
      printf((char *)(DAT_0001bde0 + 0x1bd90));
      bVar5 = *(byte *)(param_2 + 0x4a);
    }
    else {
      printf((char *)(DAT_0001bdb8 + 0x1bce8));
      bVar5 = *(byte *)(param_2 + 0x4a);
    }
  }
  if ((bVar5 & 2) == 0) goto LAB_0001bca8;
  if ((*(byte *)(param_2 + 0x4b) & 2) == 0) {
    if (param_4 != 10) goto LAB_0001bc84;
LAB_0001bd50:
    uVar3 = FUN_00022018(param_2 + 0x20);
    uVar4 = FUN_00022030(param_2 + 0x30);
    __format = (char *)(DAT_0001bdd8 + 0x1bd6a);
  }
  else {
    printf((char *)(DAT_0001bdd0 + 0x1bd3e));
    if (param_4 == 10) goto LAB_0001bd50;
LAB_0001bc84:
    uVar3 = FUN_00021f64(param_2 + 0x20);
    uVar4 = FUN_00021f94(param_2 + 0x30);
    __format = (char *)(DAT_0001bdb0 + 0x1bc9e);
  }
  printf(__format,param_1,uVar3,uVar4);
  bVar5 = *(byte *)(param_2 + 0x4a);
LAB_0001bca8:
  if ((bVar5 & 1) != 0) {
    if ((*(byte *)(param_2 + 0x4b) & 1) != 0) {
      printf((char *)(DAT_0001bdbc + 0x1bcf6));
    }
    if (param_4 == 10) {
      uVar3 = FUN_00022018(param_2);
      uVar4 = FUN_00022030(param_2 + 0x10);
      printf((char *)(DAT_0001bddc + 0x1bd86),param_1,uVar3,uVar4);
    }
    else {
      uVar3 = FUN_00021f64(param_2);
      uVar4 = FUN_00021f94(param_2 + 0x10);
      printf((char *)(DAT_0001bdb4 + 0x1bcd6),param_1,uVar3,uVar4);
    }
  }
  return;
}



/* Function: FUN_0001be4c @ 0001be4c */

void FUN_0001be4c(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  char *__format;
  
  puVar3 = PTR_LAB_0001bec0 + 0x1be64;
  printf(PTR_LAB_0001bebc + 0x1be62);
  FUN_0001bb44(puVar3,param_2 + 0x20);
  uVar1 = (uint)*(ushort *)(param_2 + 0x152);
  if (uVar1 != 0) {
    uVar2 = 0;
    __format = PTR_LAB_0001bec4 + 0x1be8c;
    do {
      if (1 < uVar1) {
        printf(__format,uVar2);
      }
      FUN_0001bbbc(puVar3,param_2 + 0x20 + uVar2 * 0x4c,param_3 != 0,10);
      uVar1 = (uint)*(ushort *)(param_2 + 0x152);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}



/* Function: FUN_0001bf30 @ 0001bf30 */

void FUN_0001bf30(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *__format;
  
  iVar3 = DAT_0001bfa4 + 0x1bf48;
  printf((char *)(DAT_0001bfa0 + 0x1bf46));
  FUN_0001bb44(iVar3,param_2 + 0x20);
  uVar1 = (uint)*(ushort *)(param_2 + 0x152);
  if (uVar1 != 0) {
    uVar2 = 0;
    __format = (char *)(DAT_0001bfa8 + 0x1bf70);
    do {
      if (1 < uVar1) {
        printf(__format,uVar2);
      }
      FUN_0001bbbc(iVar3,param_2 + 0x20 + uVar2 * 0x4c,param_3 != 0,2);
      uVar1 = (uint)*(ushort *)(param_2 + 0x152);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}



/* Function: FUN_0001bfac @ 0001bfac */

void FUN_0001bfac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_4c [2];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  int local_24;
  
  iVar1 = iRam0001c2e8;
  iVar2 = iRam0001c2e4 + 0x1bfc6;
  local_24 = **(int **)(iVar2 + iRam0001c2e8);
  local_38 = 0;
  local_40 = 0;
  local_44 = 0;
  local_4c[0] = param_3;
  FUN_00021dc4(**(undefined4 **)(iVar2 + iRam0001c2ec),local_4c,
               *(undefined4 *)(iVar2 + iRam0001c2f0),0,param_2);
  if (param_1 - 0x31U < 0x31) {
                    /* WARNING: Could not emulate address calculation at 0x0001c01c */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((param_1 - 0x31U) * 4 + iRam0001c2f4 + 0x1c01e) + iRam0001c2f4 + 0x1c01e))()
    ;
    return;
  }
  if (local_24 != **(int **)(iVar2 + iVar1)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}



/* Function: FUN_0001c59c @ 0001c59c */

void FUN_0001c59c(void)

{
  FUN_0001bfac();
  return;
}



/* Function: FUN_0001c5b4 @ 0001c5b4 */

void FUN_0001c5b4(void)

{
  puts((char *)(DAT_0001c5c0 + 0x1c5bc));
  return;
}



/* Function: FUN_0001c5c4 @ 0001c5c4 */

void FUN_0001c5c4(void)

{
  FUN_0002310c(DAT_0001c5d0 + 0x1c5cc);
  return;
}



/* Function: FUN_0001c5d4 @ 0001c5d4 */

void FUN_0001c5d4(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_0001c5e4 + 0x1c5e0),param_2,*(undefined4 *)(param_2 + 0x28),
         *(undefined4 *)(param_2 + 0x2c));
  return;
}



/* Function: FUN_0001c5e8 @ 0001c5e8 */

void FUN_0001c5e8(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_0001c5f8 + 0x1c5f4),param_2,*(undefined4 *)(param_2 + 0x28),
         *(undefined4 *)(param_2 + 0x2c));
  return;
}



/* Function: FUN_0001c6d8 @ 0001c6d8 */

void FUN_0001c6d8(void)

{
  FUN_0002310c(DAT_0001c6e4 + 0x1c6e0);
  return;
}



/* Function: FUN_0001c6e8 @ 0001c6e8 */

void FUN_0001c6e8(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *__format;
  undefined8 uVar6;
  
  if (param_2 == 0) {
    uVar6 = __aeabi_ui2d();
    uVar6 = __aeabi_dmul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_0001c760,DAT_0001c764);
    uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
    uVar1 = (undefined4)uVar6;
    iVar2 = __aeabi_dcmpge(uVar1,uVar3,DAT_0001c768,DAT_0001c76c);
    if (iVar2 == 0) {
      uVar6 = __aeabi_dcmpge(uVar1,uVar3,DAT_0001c770,DAT_0001c774);
      if ((int)uVar6 == 0) {
        printf((char *)(DAT_0001c780 + 0x1c726),(int)((ulonglong)uVar6 >> 0x20),uVar1,uVar3);
        return;
      }
      __format = (char *)(DAT_0001c784 + 0x1c734);
      uVar4 = DAT_0001c778;
      uVar5 = DAT_0001c77c;
    }
    else {
      __format = (char *)(DAT_0001c78c + 0x1c75c);
      uVar4 = DAT_0001c770;
      uVar5 = DAT_0001c774;
    }
    uVar6 = __aeabi_ddiv(uVar1,uVar3,uVar4,uVar5);
    uVar1 = (undefined4)((ulonglong)uVar6 >> 0x20);
    printf(__format,uVar1,(int)uVar6,uVar1);
  }
  else {
    printf((char *)(DAT_0001c788 + 0x1c74e),param_1);
  }
  return;
}



/* Function: FUN_0001c790 @ 0001c790 */

void FUN_0001c790(int param_1,undefined4 param_2)

{
  short sVar1;
  
  if ((int)((uint)*(ushort *)(param_1 + 0x20) << 0x1f) < 0) {
    printf((char *)(DAT_0001c7e8 + 0x1c7c2));
    sVar1 = *(short *)(param_1 + 0x22);
  }
  else {
    sVar1 = *(short *)(param_1 + 0x22);
  }
  if (sVar1 == 2) {
    printf((char *)(DAT_0001c7ec + 0x1c7d2),param_2);
  }
  else if (sVar1 == 3) {
    printf((char *)(DAT_0001c7f0 + 0x1c7de),param_2);
  }
  else {
    if (sVar1 != 1) {
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    printf((char *)(DAT_0001c7e4 + 0x1c7b8),param_2);
  }
  return;
}



/* Function: FUN_0001c7f4 @ 0001c7f4 */

void FUN_0001c7f4(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_2 + 0x20;
  if ((int)((uint)*(ushort *)(param_2 + 0x40) << 0x1d) < 0) {
    printf(PTR_LAB_0001c8ac + 0x1c808,iVar2);
    uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    if ((int)(uVar1 << 0x1b) < 0) {
      printf(PTR_LAB_0001c8cc + 0x1c86e);
      uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    }
    if ((int)(uVar1 << 0x1a) < 0) {
      printf(PTR_LAB_0001c8c8 + 0x1c864);
    }
    FUN_0001c790(iVar2,PTR_LAB_0001c8b0 + 0x1c81c);
    printf(PTR_LAB_0001c8b4 + 0x1c828,param_2 + 0x30);
  }
  else {
    printf(PTR_LAB_0001c8b8 + 0x1c834,iVar2);
    uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    if ((int)(uVar1 << 0x1b) < 0) {
      printf(PTR_LAB_0001c8d0 + 0x1c87e);
      FUN_0001c6e8(*(undefined4 *)(param_2 + 0x44),0);
      printf(PTR_LAB_0001c8d4 + 0x1c88e);
      FUN_0001c6e8(*(undefined4 *)(param_2 + 0x4c),0);
      FUN_0001c790(iVar2,PTR_LAB_0001c8d8 + 0x1c8a0);
      uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    }
    if ((int)(uVar1 << 0x1a) < 0) {
      printf(PTR_LAB_0001c8bc + 0x1c846);
      FUN_0001c790(iVar2,PTR_LAB_0001c8c0 + 0x1c850);
      printf(PTR_DAT_0001c8c4 + 0x1c85a,*(undefined4 *)(param_2 + 0x50));
    }
  }
  return;
}



/* Function: FUN_0001c8dc @ 0001c8dc */

void FUN_0001c8dc(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  printf((char *)(DAT_0001c9e8 + 0x1c8e8));
  iVar2 = param_2 + 0x20;
  printf((char *)(DAT_0001c9ec + 0x1c8f4),iVar2);
  uVar1 = (uint)*(ushort *)(param_2 + 0x40);
  if ((int)(uVar1 << 0x1c) < 0) {
    printf((char *)(DAT_0001ca14 + 0x1c9a0));
    uVar1 = (uint)*(ushort *)(param_2 + 0x40);
  }
  if ((int)(uVar1 << 0x1b) < 0) {
    printf((char *)(DAT_0001ca0c + 0x1c978));
    uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    if ((int)(uVar1 << 0x1c) < 0) {
      FUN_0001c6e8(*(undefined4 *)(param_2 + 0x44),param_3);
      uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    }
    if ((int)(uVar1 << 0x1e) < 0) {
      FUN_0001c790(iVar2,DAT_0001ca10 + 0x1c98c);
      FUN_0001c6e8(*(undefined4 *)(param_2 + 0x4c),param_3);
      uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    }
  }
  if ((int)(uVar1 << 0x1a) < 0) {
    printf(PTR_LAB_0001ca00 + 0x1c94e);
    uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    if ((int)(uVar1 << 0x1c) < 0) {
      printf((char *)(DAT_0001ca20 + 0x1c9e0),*(undefined4 *)(param_2 + 0x48));
      uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    }
    if ((int)(uVar1 << 0x1e) < 0) {
      FUN_0001c790(iVar2,DAT_0001ca04 + 0x1c962);
      printf((char *)(DAT_0001ca08 + 0x1c96c),*(undefined4 *)(param_2 + 0x50));
      uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    }
  }
  if ((int)(uVar1 << 0x1d) < 0) {
    FUN_0001c790(iVar2,DAT_0001c9f0 + 0x1c912);
    printf((char *)(DAT_0001c9f4 + 0x1c91e),param_2 + 0x30);
    uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    if ((int)(uVar1 << 0x1c) < 0) {
      printf((char *)(DAT_0001ca1c + 0x1c9c6));
      uVar1 = (uint)*(ushort *)(param_2 + 0x40);
    }
    if ((int)(uVar1 << 0x1b) < 0) {
      printf((char *)(DAT_0001ca18 + 0x1c9ac));
      uVar1 = (uint)*(ushort *)(param_2 + 0x40);
      if ((int)(uVar1 << 0x1c) < 0) {
        FUN_0001c6e8(*(undefined4 *)(param_2 + 0x4c),param_3);
        uVar1 = (uint)*(ushort *)(param_2 + 0x40);
      }
    }
    if ((int)(uVar1 << 0x1a) < 0) {
      printf(PTR_LAB_0001c9f8 + 0x1c934);
      if ((int)((uint)*(ushort *)(param_2 + 0x40) << 0x1c) < 0) {
        printf(PTR_FUN_0001c9fc + 0x1c944,*(undefined4 *)(param_2 + 0x50));
      }
    }
  }
  return;
}



/* Function: FUN_0001ca28 @ 0001ca28 */

undefined4 FUN_0001ca28(undefined4 *param_1,char *param_2)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  char *__s1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 *puVar3;
  undefined8 uVar4;
  char *local_14;
  
  strtod(param_2,&local_14);
  uVar4 = CONCAT44(extraout_r1,extraout_r0);
  if (local_14 != param_2) {
    if (*local_14 == '\0') {
LAB_0001ca4c:
      __aeabi_dmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),DAT_0001ca98,DAT_0001ca9c);
      uVar1 = __aeabi_d2uiz();
      *param_1 = uVar1;
      return 0;
    }
    puVar3 = (undefined4 *)(DAT_0001caa0 + 0x1ca6c);
    __s1 = (char *)*puVar3;
    while (__s1 != (char *)0x0) {
      iVar2 = strcasecmp(__s1,local_14);
      if (iVar2 == 0) {
        uVar4 = __aeabi_dmul(extraout_r0,extraout_r1,puVar3[2],puVar3[3]);
        goto LAB_0001ca4c;
      }
      puVar3 = puVar3 + 4;
      __s1 = (char *)*puVar3;
    }
  }
  return 0xffffffff;
}



/* Function: FUN_0001caa8 @ 0001caa8 */

undefined4 FUN_0001caa8(uint param_1)

{
  undefined4 uVar1;
  int *in_stack_00000004;
  
  *(int *)(DAT_0001cdcc + 0x1cac4) = *in_stack_00000004 + 0x20;
  if (param_1 < 10) {
                    /* WARNING: Could not emulate address calculation at 0x0001cad2 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)(param_1 * 4 + DAT_0001cdd0 + 0x1cad4) + DAT_0001cdd0 + 0x1cad4))();
    return uVar1;
  }
  return 0;
}



/* Function: FUN_0001cf98 @ 0001cf98 */

void FUN_0001cf98(void)

{
  puts((char *)(DAT_0001cfa4 + 0x1cfa0));
  return;
}



/* Function: FUN_0001cfb8 @ 0001cfb8 */

void FUN_0001cfb8(void)

{
  FUN_00022bd8(DAT_0001cfc4 + 0x1cfc0);
  return;
}



/* Function: FUN_0001cfc8 @ 0001cfc8 */

void FUN_0001cfc8(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *__format;
  undefined8 uVar6;
  
  uVar6 = __aeabi_ui2d();
  uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar1 = (undefined4)uVar6;
  iVar2 = __aeabi_dcmpge(uVar1,uVar3,DAT_0001d028,DAT_0001d02c);
  if (iVar2 == 0) {
    iVar2 = __aeabi_dcmpge(uVar1,uVar3,DAT_0001d030,DAT_0001d034);
    if (iVar2 == 0) {
      printf((char *)(DAT_0001d038 + 0x1cff8),param_1);
      return;
    }
    __format = (char *)(DAT_0001d03c + 0x1d006);
    uVar4 = DAT_0001d030;
    uVar5 = DAT_0001d034;
  }
  else {
    __format = (char *)(DAT_0001d040 + 0x1d022);
    uVar4 = DAT_0001d028;
    uVar5 = DAT_0001d02c;
  }
  uVar6 = __aeabi_ddiv(uVar1,uVar3,uVar4,uVar5);
  uVar1 = (undefined4)((ulonglong)uVar6 >> 0x20);
  printf(__format,uVar1,(int)uVar6,uVar1);
  return;
}



/* Function: FUN_0001d048 @ 0001d048 */

void FUN_0001d048(int param_1,undefined4 param_2)

{
  sbyte sVar1;
  int iVar2;
  
  sVar1 = *(sbyte *)(param_1 + 0x31);
  iVar2 = DAT_0001d098 << ((int)*(char *)(param_1 + 0x30) + 2U & 0xff);
  iVar2 = (int)(((uint)(iVar2 >> 0x1f) >> 0x1e) + iVar2) >> 2;
  printf((char *)(DAT_0001d09c + 0x1d06e));
  printf((char *)(DAT_0001d0a0 + 0x1d07c),param_2);
  FUN_0001cfc8(iVar2);
  printf((char *)(DAT_0001d0a4 + 0x1d08c),param_2);
  FUN_0001cfc8(iVar2 << sVar1);
  return;
}



/* Function: FUN_0001d0a8 @ 0001d0a8 */

void FUN_0001d0a8(undefined4 param_1,undefined4 param_2)

{
  FUN_0001d048(param_2,DAT_0001d0b8 + 0x1d0b2);
  return;
}



/* Function: FUN_0001d0bc @ 0001d0bc */

void FUN_0001d0bc(undefined4 param_1,undefined4 param_2)

{
  FUN_0001d048(param_2,DAT_0001d0cc + 0x1d0c6);
  return;
}



/* Function: FUN_0001d4cc @ 0001d4cc */

void FUN_0001d4cc(void)

{
  FUN_0002310c(DAT_0001d4d8 + 0x1d4d4);
  return;
}



/* Function: FUN_0001d4dc @ 0001d4dc */

void FUN_0001d4dc(undefined4 param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  if (*(char *)(param_2 + 0x29) == '\0') {
    bVar1 = *(byte *)(param_2 + 0x28);
  }
  else {
    printf((char *)(DAT_0001d5b0 + 0x1d52e));
    bVar1 = *(byte *)(param_2 + 0x28);
  }
  uVar4 = (uint)bVar1;
  if ((int)(uVar4 << 0x1e) < 0) {
    printf((char *)(DAT_0001d5b4 + 0x1d53c));
    uVar4 = (uint)*(byte *)(param_2 + 0x28);
  }
  if ((int)(uVar4 << 0x1f) < 0) {
    printf((char *)(DAT_0001d5b8 + 0x1d54a));
    uVar4 = (uint)*(byte *)(param_2 + 0x28);
  }
  if ((int)(uVar4 << 0x1d) < 0) {
    printf((char *)(DAT_0001d5bc + 0x1d558));
    uVar4 = (uint)*(byte *)(param_2 + 0x28);
  }
  if ((int)(uVar4 << 0x1c) < 0) {
    printf((char *)(DAT_0001d5c0 + 0x1d566));
    iVar3 = *(int *)(param_2 + 0x20);
  }
  else {
    iVar3 = *(int *)(param_2 + 0x20);
  }
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_2 + 0x24);
  }
  else {
    printf((char *)(DAT_0001d5c4 + 0x1d574));
    iVar3 = *(int *)(param_2 + 0x24);
  }
  if (iVar3 == 0) {
    bVar1 = *(byte *)(param_2 + 0x28);
  }
  else {
    printf((char *)(DAT_0001d5c8 + 0x1d582));
    bVar1 = *(byte *)(param_2 + 0x28);
  }
  if ((int)((uint)bVar1 << 0x1b) < 0) {
    printf((char *)(DAT_0001d5cc + 0x1d590));
  }
  printf((char *)(DAT_0001d5ac + 0x1d518),param_2 + 0x2a);
  cVar2 = *(char *)(param_2 + 0xf2);
  if (cVar2 == '\0') {
    printf((char *)(DAT_0001d5d0 + 0x1d59a));
    cVar2 = *(char *)(param_2 + 0xf2);
  }
  if (cVar2 == '\x01') {
    printf((char *)(DAT_0001d5d4 + 0x1d5a8));
  }
  return;
}



/* Function: FUN_0001d5d8 @ 0001d5d8 */

void FUN_0001d5d8(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  
  if (*(char *)(param_2 + 0x29) != '\0') {
    fputc(0x21,(FILE *)(*(int *)(PTR_DAT_0001d6a4 + DAT_0001d6b0 + 0x1d5e8) + 0x54));
  }
  printf(PTR_LAB_0001d6a8 + 0x1d5f0);
  uVar2 = (uint)*(byte *)(param_2 + 0x28);
  if ((int)(uVar2 << 0x1e) < 0) {
    printf((char *)(DAT_0001d6d4 + 0x1d69c));
    uVar2 = (uint)*(byte *)(param_2 + 0x28);
  }
  if ((int)(uVar2 << 0x1f) < 0) {
    printf((char *)(DAT_0001d6d0 + 0x1d690));
    uVar2 = (uint)*(byte *)(param_2 + 0x28);
  }
  if ((int)(uVar2 << 0x1d) < 0) {
    printf((char *)(DAT_0001d6cc + 0x1d684));
    uVar2 = (uint)*(byte *)(param_2 + 0x28);
  }
  if ((int)(uVar2 << 0x1c) < 0) {
    printf((char *)(DAT_0001d6c8 + 0x1d67a));
  }
  if (*(int *)(param_2 + 0x20) != 0) {
    printf((char *)(DAT_0001d6c4 + 0x1d670));
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    printf((char *)(DAT_0001d6c0 + 0x1d666));
  }
  if ((int)((uint)*(byte *)(param_2 + 0x28) << 0x1b) < 0) {
    printf(PTR_DAT_0001d6bc + 0x1d65c);
  }
  printf(PTR_LAB_0001d6ac + 0x1d620,param_2 + 0x2a);
  cVar1 = *(char *)(param_2 + 0xf2);
  if (cVar1 == '\0') {
    printf(PTR_LAB_0001d6b4 + 0x1d644);
    cVar1 = *(char *)(param_2 + 0xf2);
  }
  if (cVar1 == '\x01') {
    printf(PTR_LAB_0001d6b8 + 0x1d652);
  }
  return;
}



/* Function: FUN_0001d6d8 @ 0001d6d8 */

undefined4 FUN_0001d6d8(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 0xc9U < 10) {
                    /* WARNING: Could not emulate address calculation at 0x0001d6fc */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)((param_1 - 0xc9U) * 4 + iRam0001d890 + 0x1d6fe) +
                      iRam0001d890 + 0x1d6fe))();
    return uVar1;
  }
  return 0;
}



/* Function: FUN_0001d8d4 @ 0001d8d4 */

void FUN_0001d8d4(void)

{
  puts((char *)(DAT_0001d8e0 + 0x1d8dc));
  return;
}



/* Function: FUN_0001d8e4 @ 0001d8e4 */

void FUN_0001d8e4(void)

{
  FUN_0002310c(DAT_0001d8f0 + 0x1d8ec);
  return;
}



/* Function: FUN_0001d8f4 @ 0001d8f4 */

void FUN_0001d8f4(void)

{
  puts((char *)(DAT_0001d900 + 0x1d8fc));
  return;
}



/* Function: FUN_0001d904 @ 0001d904 */

void FUN_0001d904(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  undefined *puVar5;
  undefined *puVar6;
  char *__format;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  undefined4 *puVar15;
  byte *pbVar16;
  
  puVar5 = PTR_LAB_0001dae4;
  iVar8 = *(int *)(param_1 + 0x118);
  iVar9 = *(int *)(param_1 + 0x108);
  if (iVar9 == 2) {
    printf((char *)(DAT_0001db0c + 0x1dad4));
  }
  else if (iVar9 == 4) {
    printf((char *)(DAT_0001db08 + 0x1daca));
  }
  else if (iVar9 == 1) {
    printf((char *)(DAT_0001dafc + 0x1da32));
  }
  else {
    puts(PTR_DAT_0001dae8 + 0x1d942);
  }
  puVar6 = PTR_DAT_0001daec;
  iVar9 = 0;
  piVar7 = (int *)(param_1 + 8);
  while (*piVar7 == 0) {
    iVar9 = iVar9 + 1;
    piVar7 = piVar7 + 1;
    if (iVar9 == 0x40) {
      printf((char *)(DAT_0001db04 + 0x1dac0));
      return;
    }
  }
  iVar9 = 0;
  piVar7 = (int *)(param_1 + 8);
  while (*piVar7 == -1) {
    iVar9 = iVar9 + 1;
    piVar7 = piVar7 + 1;
    if (iVar9 == 0x40) {
      printf((char *)(DAT_0001db10 + 0x1dade));
      return;
    }
  }
  __format = (char *)(DAT_0001daf0 + 0x1d984);
  puVar10 = (uint *)(PTR_DAT_0001daec + 0x1d984);
  puVar15 = (undefined4 *)(DAT_0001daf4 + 0x1d98a);
  bVar4 = false;
  uVar11 = 0;
  do {
    if ((1 << (uVar11 & 0x1f) & *(uint *)(((uVar11 >> 5) + 2) * 4 + param_1)) != 0) {
      if (bVar4) {
        putchar(0x2c);
        if (param_2 == 0) goto LAB_0001d9b8;
LAB_0001daa6:
        printf((char *)(DAT_0001db00 + 0x1daae),uVar11);
      }
      else {
        if (param_2 != 0) goto LAB_0001daa6;
LAB_0001d9b8:
        puVar13 = puVar10;
        do {
          while (*puVar13 == uVar11) {
            puVar13 = puVar13 + 3;
            printf(__format,*puVar15);
            if (puVar13 == (uint *)(puVar6 + 0x1da5c)) goto LAB_0001d9da;
          }
          puVar13 = puVar13 + 3;
        } while (puVar13 != (uint *)(puVar6 + 0x1da5c));
      }
LAB_0001d9da:
      iVar9 = DAT_0001daf8;
      if (0 < iVar8) {
        pbVar16 = (byte *)(param_1 + 0x10c);
        iVar14 = 0;
        do {
          if (*pbVar16 == uVar11) {
            bVar2 = pbVar16[1];
            bVar3 = pbVar16[2];
            if (bVar3 != 0) {
              putchar(0x3a);
            }
            iVar12 = 0;
LAB_0001da6e:
            do {
              if (((int)(uint)bVar3 >> (7U - iVar12 & 0xff) & 1U) != 0) {
                if (((int)(uint)bVar2 >> (7U - iVar12 & 0xff) & 1U) != 0) {
                  pbVar1 = (byte *)(puVar15[2] + iVar12);
                  iVar12 = iVar12 + 1;
                  putchar((uint)*pbVar1);
                  if (iVar12 == 8) break;
                  goto LAB_0001da6e;
                }
                putchar((int)*(short *)((*(byte *)(puVar15[2] + iVar12) + 1) * 2 +
                                       **(int **)(puVar5 + iVar9 + 0x1d91a)));
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 != 8);
          }
          iVar14 = iVar14 + 1;
          pbVar16 = pbVar16 + 3;
        } while (iVar14 != iVar8);
      }
      bVar4 = true;
    }
    uVar11 = uVar11 + 1;
    puVar15 = puVar15 + 3;
    if (uVar11 == 0x100) {
      if (bVar4) {
        putchar(0x20);
      }
      return;
    }
  } while( true );
}



/* Function: FUN_0001db14 @ 0001db14 */

void FUN_0001db14(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x13c);
  if ((uVar1 & 1) != 0) {
    if ((*(uint *)(param_2 + 0x140) & 1) == 0) {
      if (*(short *)(param_2 + 0x24) == *(short *)(param_2 + 0x26)) {
LAB_0001dbbc:
        printf((char *)(DAT_0001dbf4 + 0x1dbc2));
        uVar1 = *(uint *)(param_2 + 0x13c);
        goto LAB_0001db48;
      }
    }
    else {
      printf((char *)(DAT_0001dbf0 + 0x1dbb2));
      if (*(short *)(param_2 + 0x24) == *(short *)(param_2 + 0x26)) goto LAB_0001dbbc;
    }
    printf((char *)(DAT_0001dbdc + 0x1db40));
    uVar1 = *(uint *)(param_2 + 0x13c);
  }
LAB_0001db48:
  if ((uVar1 & 2) == 0) goto LAB_0001db6e;
  if ((*(uint *)(param_2 + 0x140) & 2) == 0) {
    if (*(short *)(param_2 + 0x20) == *(short *)(param_2 + 0x22)) {
LAB_0001dbcc:
      printf((char *)(DAT_0001dbf8 + 0x1dbd2));
      uVar1 = *(uint *)(param_2 + 0x13c);
      goto LAB_0001db6e;
    }
  }
  else {
    printf((char *)(DAT_0001dbec + 0x1dba0));
    if (*(short *)(param_2 + 0x20) == *(short *)(param_2 + 0x22)) goto LAB_0001dbcc;
  }
  printf((char *)(DAT_0001dbe0 + 0x1db66));
  uVar1 = *(uint *)(param_2 + 0x13c);
LAB_0001db6e:
  if ((uVar1 & 4) != 0) {
    if ((*(uint *)(param_2 + 0x140) & 4) != 0) {
      printf((char *)(DAT_0001dbe8 + 0x1db96));
    }
    printf((char *)(DAT_0001dbe4 + 0x1db84));
    FUN_0001d904(param_2 + 0x20,0);
  }
  return;
}



/* Function: FUN_0001dbfc @ 0001dbfc */

void FUN_0001dbfc(uint param_1,int param_2)

{
  servent *psVar1;
  
  if (((param_2 == 0) &&
      (psVar1 = getservbyport((param_1 << 8 | param_1 >> 8) & 0xffff,
                              (char *)(DAT_0001dc38 + 0x1dc14)), psVar1 != (servent *)0x0)) &&
     (psVar1->s_name != (char *)0x0)) {
    printf((char *)(DAT_0001dc3c + 0x1dc26));
  }
  else {
    printf((char *)(DAT_0001dc40 + 0x1dc32),param_1);
  }
  return;
}



/* Function: FUN_0001dc44 @ 0001dc44 */

void FUN_0001dc44(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined *puVar1;
  
  if (param_4 == 0) {
    puVar1 = (undefined *)(DAT_0001dcc0 + 0x1dc58);
  }
  else {
    puVar1 = &UNK_0001dcbe + DAT_0001dcd8;
  }
  if ((param_3 == DAT_0001dcc4) && (param_2 == 0)) {
    if (param_4 == 0) {
      return;
    }
    printf((char *)(DAT_0001dcd0 + 0x1dc8e),param_1,DAT_0001dcc4,param_4,param_4);
  }
  else {
    printf((char *)(DAT_0001dcc8 + 0x1dc64),param_1,DAT_0001dcc4,param_4,param_4);
    if (param_2 == param_3) {
      printf((char *)(DAT_0001dccc + 0x1dc72),puVar1);
      FUN_0001dbfc(param_2,param_5);
      goto LAB_0001dcb0;
    }
  }
  printf((char *)(DAT_0001dcd4 + 0x1dc98),puVar1);
  FUN_0001dbfc(param_2,param_5);
  putchar(0x3a);
  FUN_0001dbfc(param_3,param_5);
LAB_0001dcb0:
  putchar(0x20);
  return;
}



/* Function: FUN_0001dcdc @ 0001dcdc */

void FUN_0001dcdc(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  printf((char *)(DAT_0001dd6c + 0x1dcf0));
  uVar1 = *(uint *)(param_2 + 0x13c);
  if ((uVar1 & 1) != 0) {
    FUN_0001dc44(DAT_0001dd74 + 0x1dd56,*(undefined2 *)(param_2 + 0x24),
                 *(undefined2 *)(param_2 + 0x26),*(uint *)(param_2 + 0x140) & 1,param_3);
    uVar1 = *(uint *)(param_2 + 0x13c);
  }
  if ((uVar1 & 2) != 0) {
    FUN_0001dc44(DAT_0001dd70 + 0x1dd36,*(undefined2 *)(param_2 + 0x20),
                 *(undefined2 *)(param_2 + 0x22),*(uint *)(param_2 + 0x140) & 2,param_3);
    uVar1 = *(uint *)(param_2 + 0x13c);
  }
  if ((uVar1 & 4) != 0) {
    if ((*(uint *)(param_2 + 0x140) & 4) != 0) {
      printf((char *)(DAT_0001dd78 + 0x1dd68));
    }
    FUN_0001d904(param_2 + 0x20,param_3);
  }
  return;
}



/* Function: FUN_0001e32c @ 0001e32c */

void FUN_0001e32c(void)

{
  FUN_00022bd8(DAT_0001e338 + 0x1e334);
  return;
}



/* Function: FUN_0001e33c @ 0001e33c */

void FUN_0001e33c(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_0001e374 + 0x1e348));
  if (*(char *)(param_2 + 0x20) != '\x01') {
    (**(code **)(**(int **)(DAT_0001e378 + 0x1e35c) + 0x14))(1,DAT_0001e37c + 0x1e360);
  }
  printf((char *)(DAT_0001e380 + 0x1e36e),param_2 + 0x28);
  return;
}



/* Function: FUN_0001e384 @ 0001e384 */

void FUN_0001e384(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_0001e3bc + 0x1e390));
  if (*(char *)(param_2 + 0x20) != '\x01') {
    (**(code **)(**(int **)(DAT_0001e3c0 + 0x1e3a4) + 0x14))(1,DAT_0001e3c4 + 0x1e3a8);
  }
  printf((char *)(DAT_0001e3c8 + 0x1e3b6),param_2 + 0x28);
  return;
}



/* Function: FUN_0001e3cc @ 0001e3cc */

undefined4
FUN_0001e3cc(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,undefined4 param_5,
            int *param_6)

{
  size_t sVar1;
  undefined4 uVar2;
  char *__s;
  int iVar3;
  int iVar4;
  
  iVar3 = iRam0001e444 + 0x1e3dc;
  iVar4 = *param_6;
  if (param_1 != 0x31) {
    return 0;
  }
  if ((*param_4 & 1) == 0) {
    *(undefined1 *)(iVar4 + 0x20) = 1;
    __s = (char *)**(undefined4 **)(iVar3 + iRam0001e448);
    sVar1 = strlen(__s);
    if (sVar1 < 0x100) {
      strcpy((char *)(iVar4 + 0x28),__s);
      *param_4 = *param_4 | 1;
      return 1;
    }
  }
  else {
    (**(code **)(**(int **)(iVar3 + iRam0001e44c) + 0x14))(2,iRam0001e450 + 0x1e42c);
  }
  (**(code **)(**(int **)(iVar3 + iRam0001e44c) + 0x14))(2,iRam0001e454 + 0x1e43c,0xff);
  puts((char *)(DAT_0001e464 + 0x1e460));
                    /* WARNING: Could not recover jumptable at 0x0001e462. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)0x1e443)();
  return uVar2;
}



/* Function: FUN_0001e468 @ 0001e468 */

void FUN_0001e468(void)

{
  FUN_0002310c(DAT_0001e474 + 0x1e470);
  return;
}



/* Function: FUN_0001e478 @ 0001e478 */

void FUN_0001e478(void)

{
  FUN_00022bd8(DAT_0001e484 + 0x1e480);
  return;
}



/* Function: FUN_0001e488 @ 0001e488 */

void FUN_0001e488(void)

{
  puts((char *)(DAT_0001e494 + 0x1e490));
  return;
}



/* Function: FUN_0001e4bc @ 0001e4bc */

void FUN_0001e4bc(void)

{
  FUN_0002310c(DAT_0001e4c8 + 0x1e4c4);
  return;
}



/* Function: FUN_0001e4cc @ 0001e4cc */

void FUN_0001e4cc(int param_1)

{
  int iVar1;
  
  if (param_1 << 0x1f < 0) {
    printf((char *)(DAT_0001e554 + 0x1e52a),DAT_0001e558 + 0x1e52c);
    iVar1 = (int)&DAT_0001e534 + DAT_0001e55c;
  }
  else {
    iVar1 = DAT_0001e534 + 0x1e4da;
  }
  if (param_1 << 0x1c < 0) {
    printf((char *)(DAT_0001e54c + 0x1e51a),iVar1);
    iVar1 = DAT_0001e550 + 0x1e522;
  }
  if (param_1 << 0x1d < 0) {
    printf((char *)(DAT_0001e544 + 0x1e50c),iVar1);
    iVar1 = DAT_0001e548 + 0x1e514;
  }
  if (param_1 << 0x1e < 0) {
    printf((char *)(DAT_0001e53c + 0x1e4fe),iVar1);
    iVar1 = DAT_0001e540 + 0x1e506;
  }
  if (param_1 << 0x19 < 0) {
    printf((char *)(DAT_0001e538 + 0x1e4ee),iVar1);
  }
  putchar(0x20);
  return;
}



/* Function: FUN_0001e560 @ 0001e560 */

void FUN_0001e560(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_0001e574 + 0x1e56a));
  FUN_0001e4cc(*(undefined4 *)(param_2 + 0x20));
  return;
}



/* Function: FUN_0001e578 @ 0001e578 */

void FUN_0001e578(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_0001e58c + 0x1e582));
  FUN_0001e4cc(*(undefined4 *)(param_2 + 0x20));
  return;
}



/* Function: FUN_0001e844 @ 0001e844 */

void FUN_0001e844(void)

{
  FUN_0002310c(DAT_0001e850 + 0x1e84c);
  return;
}



/* Function: FUN_0001e858 @ 0001e858 */

void FUN_0001e858(short *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  if ((int)((uint)(ushort)param_1[1] << 0x1f) < 0) {
    printf((char *)(DAT_0001e8d4 + 0x1e8bc));
  }
  if (*param_1 == 0) {
    uVar1 = __aeabi_ui2d(*(undefined4 *)(param_1 + 2));
    __aeabi_dmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_0001e8c0,DAT_0001e8c4);
    printf(PTR_DAT_0001e8c8 + 0x1e884,param_2,param_2);
  }
  else if (*param_1 == 1) {
    printf(PTR_DAT_0001e8cc + 0x1e8a0,param_2,param_2,*(int *)(param_1 + 2) + 1);
    if (*(int *)(param_1 + 4) != 0) {
      printf(PTR_DAT_0001e8d0 + 0x1e8b2,param_2);
    }
  }
  return;
}



/* Function: FUN_0001e8d8 @ 0001e8d8 */

void FUN_0001e8d8(undefined4 param_1,int param_2)

{
  FUN_0001e858(param_2 + 0x20,DAT_0001e8e8 + 0x1e8e4);
  return;
}



/* Function: FUN_0001e8ec @ 0001e8ec */

void FUN_0001e8ec(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_0001e908 + 0x1e8f6));
  FUN_0001e858(param_2 + 0x20,DAT_0001e90c + 0x1e902);
  return;
}



/* Function: FUN_0001eb30 @ 0001eb30 */

void FUN_0001eb30(void)

{
  puts((char *)(DAT_0001eb3c + 0x1eb38));
  return;
}



/* Function: FUN_0001eb90 @ 0001eb90 */

bool FUN_0001eb90(byte *param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  
  if (param_2 == 0) {
LAB_0001ebc0:
    bVar2 = param_1[param_2 - 1] == 0x5c;
  }
  else {
    if ((*(byte *)(**(int **)(DAT_0001ebd4 + 0x1eb9c) + (uint)*param_1 + 1) & 0x97) != 0) {
      uVar1 = 0;
      do {
        uVar1 = uVar1 + 1;
        if (param_2 <= uVar1) goto LAB_0001ebc0;
      } while ((*(byte *)(**(int **)(DAT_0001ebd4 + 0x1eb9c) + (uint)param_1[uVar1] + 1) & 0x97) !=
               0);
    }
    bVar2 = true;
  }
  return bVar2;
}



/* Function: FUN_0001ebd8 @ 0001ebd8 */

void FUN_0001ebd8(void)

{
  FUN_000232e4(DAT_0001ebe8 + 0x1ebe2,2);
  return;
}



/* Function: FUN_0001ebec @ 0001ebec */

void FUN_0001ebec(int param_1,uint param_2)

{
  uint uVar1;
  char *__format;
  char *__format_00;
  
  printf((char *)(DAT_0001ec3c + 0x1ebfc));
  if (param_2 != 0) {
    uVar1 = 0;
    __format = (char *)(DAT_0001ec44 + 0x1ec0e);
    __format_00 = (char *)(DAT_0001ec40 + 0x1ec10);
    do {
      while (0xf < *(byte *)(param_1 + uVar1)) {
        uVar1 = uVar1 + 1;
        printf(__format);
        if (param_2 <= uVar1) goto LAB_0001ec2e;
      }
      uVar1 = uVar1 + 1;
      printf(__format_00);
    } while (uVar1 < param_2);
  }
LAB_0001ec2e:
  printf((char *)(DAT_0001ec48 + 0x1ec34));
  return;
}



/* Function: FUN_0001ec4c @ 0001ec4c */

void FUN_0001ec4c(int param_1,uint param_2)

{
  byte *pbVar1;
  uint uVar2;
  
  putchar(0x22);
  if (param_2 != 0) {
    uVar2 = 0;
    do {
      while (pbVar1 = (byte *)(param_1 + uVar2), *pbVar1 == 0x22) {
        putchar(0x5c);
        pbVar1 = (byte *)(param_1 + uVar2);
        uVar2 = uVar2 + 1;
        putchar((uint)*pbVar1);
        if (param_2 <= uVar2) goto LAB_0001ec82;
      }
      uVar2 = uVar2 + 1;
      putchar((uint)*pbVar1);
    } while (uVar2 < param_2);
  }
LAB_0001ec82:
  printf((char *)(DAT_0001ec8c + 0x1ec88));
  return;
}



/* Function: FUN_0001ec90 @ 0001ec90 */

void FUN_0001ec90(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  
  cVar1 = *(char *)(param_2 + 0x1f);
  if (cVar1 == '\0') {
    bVar4 = *(byte *)(param_2 + 0xb5);
  }
  else {
    bVar4 = *(byte *)(param_2 + 0xb5) & 1;
  }
  iVar3 = param_2 + 0x34;
  iVar2 = FUN_0001eb90(iVar3,*(undefined1 *)(param_2 + 0xb4));
  if (iVar2 == 0) {
    if (bVar4 == 0) {
      iVar2 = DAT_0001ed58 + 0x1ecf0;
    }
    else {
      iVar2 = DAT_0001ed68 + 0x1ed36;
    }
    printf(PTR_LAB_0001ed5c + 0x1ecf4,iVar2);
    FUN_0001ec4c(iVar3,*(undefined1 *)(param_2 + 0xb4));
  }
  else {
    if (bVar4 == 0) {
      iVar2 = DAT_0001ed50 + 0x1ecc6;
    }
    else {
      iVar2 = DAT_0001ed6c + 0x1ed3c;
    }
    printf((char *)(DAT_0001ed54 + 0x1ecca),iVar2);
    FUN_0001ebec(iVar3,*(undefined1 *)(param_2 + 0xb4));
  }
  printf(PTR_LAB_0001ed60 + 0x1ed08,param_2 + 0x24);
  if (*(short *)(param_2 + 0x20) != 0) {
    printf((char *)(DAT_0001ed74 + 0x1ed4c));
  }
  if (*(short *)(param_2 + 0x22) != 0) {
    printf((char *)(DAT_0001ed70 + 0x1ed42));
  }
  if (cVar1 != '\0') {
    if ((int)((uint)*(byte *)(param_2 + 0xb5) << 0x1e) < 0) {
      printf(PTR_LAB_0001ed64 + 0x1ed28);
    }
  }
  return;
}



/* Function: FUN_0001ed78 @ 0001ed78 */

void FUN_0001ed78(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  
  cVar1 = *(char *)(param_2 + 0x1f);
  if (cVar1 == '\0') {
    bVar4 = *(byte *)(param_2 + 0xb5);
  }
  else {
    bVar4 = *(byte *)(param_2 + 0xb5) & 1;
  }
  iVar3 = param_2 + 0x34;
  iVar2 = FUN_0001eb90(iVar3,*(undefined1 *)(param_2 + 0xb4));
  if (iVar2 == 0) {
    if (bVar4 == 0) {
      iVar2 = DAT_0001ee40 + 0x1edd8;
    }
    else {
      iVar2 = DAT_0001ee50 + 0x1ee1e;
    }
    printf(PTR_PTR_0001ee44 + 0x1eddc,iVar2);
    FUN_0001ec4c(iVar3,*(undefined1 *)(param_2 + 0xb4));
  }
  else {
    if (bVar4 == 0) {
      iVar2 = DAT_0001ee38 + 0x1edae;
    }
    else {
      iVar2 = DAT_0001ee54 + 0x1ee24;
    }
    printf((char *)(DAT_0001ee3c + 0x1edb2),iVar2);
    FUN_0001ebec(iVar3,*(undefined1 *)(param_2 + 0xb4));
  }
  printf(PTR_DAT_0001ee48 + 0x1edf0,param_2 + 0x24);
  if (*(short *)(param_2 + 0x20) != 0) {
    printf((char *)(DAT_0001ee5c + 0x1ee34));
  }
  if (*(short *)(param_2 + 0x22) != 0) {
    printf((char *)(DAT_0001ee58 + 0x1ee2a));
  }
  if (cVar1 != '\0') {
    if ((int)((uint)*(byte *)(param_2 + 0xb5) << 0x1e) < 0) {
      printf(PTR_PTR_0001ee4c + 0x1ee10);
    }
  }
  return;
}



/* Function: FUN_0001ee60 @ 0001ee60 */

void FUN_0001ee60(int param_1)

{
  if (param_1 - 0x31U < 6) {
                    /* WARNING: Could not emulate address calculation at 0x0001ee96 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((param_1 - 0x31U) * 4 + iRam0001f1a8 + 0x1ee98) + iRam0001f1a8 + 0x1ee98))
              (0);
    return;
  }
  return;
}



/* Function: FUN_0001f2ec @ 0001f2ec */

void FUN_0001f2ec(void)

{
  puts((char *)(DAT_0001f2f8 + 0x1f2f4));
  return;
}



/* Function: FUN_0001f308 @ 0001f308 */

void FUN_0001f308(void)

{
  FUN_0002310c(DAT_0001f314 + 0x1f310);
  return;
}



/* Function: FUN_0001f318 @ 0001f318 */

void FUN_0001f318(uint param_1)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  char *__format;
  int iVar6;
  
  if (param_1 == 0) {
    printf((char *)(DAT_0001f39c + 0x1f38c));
  }
  else {
    bVar1 = false;
    __format = (char *)(DAT_0001f394 + 0x1f338);
    iVar6 = DAT_0001f390 + 0x1f33a;
    puVar2 = (uint *)(DAT_0001f398 + 0x1f348);
    do {
      if ((param_1 & 1) == 0) {
        iVar4 = 0;
        puVar3 = puVar2;
        do {
          uVar5 = *puVar3;
          iVar4 = iVar4 + 1;
          puVar3 = puVar3 + 2;
        } while ((param_1 & uVar5) == 0);
        uVar5 = ~uVar5 & 0xff;
      }
      else {
        uVar5 = 0xfe;
        iVar4 = 0;
      }
      if (bVar1) {
        putchar(0x2c);
      }
      printf(__format,*(undefined4 *)(iVar4 * 8 + iVar6));
      bVar1 = true;
      param_1 = param_1 & uVar5;
    } while (param_1 != 0);
  }
  return;
}



/* Function: FUN_0001f3a0 @ 0001f3a0 */

void FUN_0001f3a0(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  if ((*(short *)(param_2 + 0x20) != 0) || (*(ushort *)(param_2 + 0x22) != DAT_0001f48c)) {
    if ((int)((uint)*(byte *)(param_2 + 0x2b) << 0x1f) < 0) {
      printf((char *)(DAT_0001f4b0 + 0x1f476));
      if (*(short *)(param_2 + 0x22) != *(short *)(param_2 + 0x20)) goto LAB_0001f3c4;
    }
    else if (*(short *)(param_2 + 0x22) != *(short *)(param_2 + 0x20)) {
LAB_0001f3c4:
      printf((char *)(DAT_0001f490 + 0x1f3ca));
      goto LAB_0001f3cc;
    }
    printf((char *)(DAT_0001f4b4 + 0x1f488));
  }
LAB_0001f3cc:
  if ((*(short *)(param_2 + 0x24) != 0) || (*(ushort *)(param_2 + 0x26) != DAT_0001f48c)) {
    if ((int)((uint)*(byte *)(param_2 + 0x2b) << 0x1e) < 0) {
      printf((char *)(DAT_0001f4a8 + 0x1f45c));
      if (*(short *)(param_2 + 0x26) == *(short *)(param_2 + 0x24)) goto LAB_0001f466;
    }
    else if (*(short *)(param_2 + 0x26) == *(short *)(param_2 + 0x24)) {
LAB_0001f466:
      printf((char *)(DAT_0001f4ac + 0x1f46c));
      goto LAB_0001f3ee;
    }
    printf((char *)(DAT_0001f494 + 0x1f3ec));
  }
LAB_0001f3ee:
  uVar1 = (uint)*(byte *)(param_2 + 0x28);
  if (uVar1 == 0) {
    uVar1 = (uint)*(byte *)(param_2 + 0x2b);
    if ((int)(uVar1 << 0x1c) < 0) {
LAB_0001f44a:
      printf((char *)(DAT_0001f4a4 + 0x1f450));
      uVar1 = (uint)*(byte *)(param_2 + 0x28);
      goto LAB_0001f43e;
    }
  }
  else {
    if ((int)((uint)*(byte *)(param_2 + 0x2b) << 0x1c) < 0) goto LAB_0001f44a;
LAB_0001f43e:
    printf((char *)(DAT_0001f4a0 + 0x1f444),uVar1);
    uVar1 = (uint)*(byte *)(param_2 + 0x2b);
  }
  if (*(char *)(param_2 + 0x29) == '\0') {
    if (-1 < (int)(uVar1 << 0x1d)) {
      return;
    }
  }
  else if (-1 < (int)(uVar1 << 0x1d)) goto LAB_0001f412;
  printf((char *)(DAT_0001f498 + 0x1f40a));
LAB_0001f412:
  printf((char *)(DAT_0001f49c + 0x1f418));
  if (*(char *)(param_2 + 0x29) != -1) {
    FUN_0001f318();
  }
  putchar(0x20);
  FUN_0001f318(*(undefined1 *)(param_2 + 0x2a));
  putchar(0x20);
  return;
}



/* Function: FUN_0001f4b8 @ 0001f4b8 */

void FUN_0001f4b8(uint param_1,int param_2)

{
  servent *psVar1;
  
  if (((param_2 == 0) &&
      (psVar1 = getservbyport((param_1 << 8 | param_1 >> 8) & 0xffff,
                              (char *)(DAT_0001f4f4 + 0x1f4d0)), psVar1 != (servent *)0x0)) &&
     (psVar1->s_name != (char *)0x0)) {
    printf((char *)(DAT_0001f4f8 + 0x1f4e2));
  }
  else {
    printf((char *)(DAT_0001f4fc + 0x1f4ee),param_1);
  }
  return;
}



/* Function: FUN_0001f500 @ 0001f500 */

void FUN_0001f500(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined *puVar1;
  
  if (param_4 == 0) {
    puVar1 = (undefined *)(DAT_0001f57c + 0x1f514);
  }
  else {
    puVar1 = &UNK_0001f57a + DAT_0001f594;
  }
  if ((param_3 == DAT_0001f580) && (param_2 == 0)) {
    if (param_4 == 0) {
      return;
    }
    printf((char *)(DAT_0001f58c + 0x1f54a),param_1,DAT_0001f580,param_4,param_4);
  }
  else {
    printf((char *)(DAT_0001f584 + 0x1f520),param_1,DAT_0001f580,param_4,param_4);
    if (param_2 == param_3) {
      printf((char *)(DAT_0001f588 + 0x1f52e),puVar1);
      FUN_0001f4b8(param_2,param_5);
      goto LAB_0001f56c;
    }
  }
  printf((char *)(DAT_0001f590 + 0x1f554),puVar1);
  FUN_0001f4b8(param_2,param_5);
  putchar(0x3a);
  FUN_0001f4b8(param_3,param_5);
LAB_0001f56c:
  putchar(0x20);
  return;
}



/* Function: FUN_0001f598 @ 0001f598 */

void FUN_0001f598(undefined4 param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  printf((char *)(DAT_0001f658 + 0x1f5a6));
  FUN_0001f500(DAT_0001f65c + 0x1f5ba,*(undefined2 *)(param_2 + 0x20),
               *(undefined2 *)(param_2 + 0x22),*(byte *)(param_2 + 0x2b) & 1,param_3);
  FUN_0001f500(DAT_0001f660 + 0x1f5d0,*(undefined2 *)(param_2 + 0x24),
               *(undefined2 *)(param_2 + 0x26),*(byte *)(param_2 + 0x2b) & 2,param_3);
  bVar1 = *(byte *)(param_2 + 0x2b);
  if ((bVar1 >> 3 & 1) == 0) {
    if (*(char *)(param_2 + 0x28) != '\0') {
      iVar2 = DAT_0001f67c + 0x1f646;
      goto LAB_0001f5e2;
    }
  }
  else {
    iVar2 = DAT_0001f664 + 0x1f5e4;
LAB_0001f5e2:
    printf((char *)(DAT_0001f668 + 0x1f5e8),iVar2);
    bVar1 = *(byte *)(param_2 + 0x2b);
  }
  uVar3 = (uint)bVar1;
  uVar4 = (uint)*(byte *)(param_2 + 0x29);
  bVar1 = *(byte *)(param_2 + 0x2a);
  if ((int)(uVar3 << 0x1d) < 0) {
    iVar2 = DAT_0001f66c + 0x1f5fa;
  }
  else {
    if (uVar4 == 0) goto LAB_0001f61e;
    iVar2 = DAT_0001f678 + 0x1f63c;
  }
  printf((char *)(DAT_0001f670 + 0x1f5fe),iVar2);
  if (param_3 == 0) {
    FUN_0001f318(uVar4);
    putchar(0x2f);
    FUN_0001f318((uint)bVar1);
    putchar(0x20);
    uVar3 = (uint)*(byte *)(param_2 + 0x2b);
  }
  else {
    printf((char *)(DAT_0001f680 + 0x1f650),uVar4,(uint)bVar1);
    uVar3 = (uint)*(byte *)(param_2 + 0x2b);
  }
LAB_0001f61e:
  if ((uVar3 & 0xfffffff0) != 0) {
    printf((char *)(DAT_0001f674 + 0x1f62c));
  }
  return;
}



/* Function: FUN_0001f684 @ 0001f684 */

void FUN_0001f684(char *param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  ushort uVar2;
  char *__s;
  char *pcVar3;
  uint uVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar5;
  
  __s = strdup(param_1);
  pcVar3 = strchr(__s,0x3a);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
    if (*__s == '\0') {
      *param_2 = 0;
      cVar1 = pcVar3[1];
      uVar5 = extraout_r2;
    }
    else {
      uVar2 = FUN_00022828(__s,DAT_0001f704 + 0x1f6c4,extraout_r2,*__s,param_4);
      *param_2 = uVar2;
      cVar1 = pcVar3[1];
      uVar5 = extraout_r2_00;
    }
    if (cVar1 == '\0') {
      param_2[1] = 0xffff;
      goto LAB_0001f6b4;
    }
    uVar4 = FUN_00022828(pcVar3 + 1,DAT_0001f708 + 0x1f6d6,uVar5,cVar1,param_4);
    param_2[1] = (ushort)uVar4;
    if (*param_2 <= uVar4) goto LAB_0001f6b4;
    (**(code **)(**(int **)(PTR_DAT_0001f70c + 0x1f6ea) + 0x14))(2,PTR_LAB_0001f710 + 0x1f6ee);
  }
  uVar2 = FUN_00022828(__s,PTR_DAT_0001f714 + 0x1f6fa);
  param_2[1] = uVar2;
  *param_2 = uVar2;
LAB_0001f6b4:
  free(__s);
  return;
}



/* Function: FUN_0001f718 @ 0001f718 */

uint FUN_0001f718(char *param_1)

{
  int iVar1;
  char *__s;
  char *__s2;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *__delim;
  uint uVar6;
  
  __s = strdup(param_1);
  __s2 = strtok(__s,(char *)(DAT_0001f7ac + 0x1f730));
  iVar1 = DAT_0001f7b0;
  uVar6 = 0;
  if (__s2 != (char *)0x0) {
    uVar6 = 0;
    puVar5 = (undefined4 *)(DAT_0001f7b8 + 0x1f74e);
    __delim = (char *)(DAT_0001f7b4 + 0x1f752);
    do {
      iVar3 = 0;
      puVar4 = puVar5;
      do {
        iVar2 = strcasecmp((char *)*puVar4,__s2);
        if (iVar2 == 0) goto LAB_0001f77c;
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 2;
      } while (iVar3 != 8);
      do {
        (**(code **)(**(int **)(DAT_0001f7bc + 0x1f772) + 0x14))(2,DAT_0001f7c0 + 0x1f776,__s2);
LAB_0001f77c:
        uVar6 = uVar6 | *(uint *)(iVar3 * 8 + iVar1 + 0x1f754);
      } while (iVar3 == 8);
      __s2 = strtok((char *)0x0,__delim);
    } while (__s2 != (char *)0x0);
  }
  free(__s);
  return uVar6;
}



/* Function: FUN_0001f7c4 @ 0001f7c4 */

undefined4 FUN_0001f7c4(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 0x31U < 5) {
                    /* WARNING: Could not emulate address calculation at 0x0001f7f0 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)((param_1 - 0x31U) * 4 + iRam0001f9e4 + 0x1f7f2) +
                      iRam0001f9e4 + 0x1f7f2))();
    return uVar1;
  }
  return 0;
}



/* Function: FUN_0001fa4c @ 0001fa4c */

void FUN_0001fa4c(void)

{
  FUN_0002310c(DAT_0001fa58 + 0x1fa54);
  return;
}



/* Function: FUN_0001fa5c @ 0001fa5c */

void FUN_0001fa5c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x24) == '\0') {
    iVar1 = DAT_0001fa98 + 0x1fa70;
  }
  else {
    iVar1 = DAT_0001faa4 + 0x1fa8e;
  }
  printf((char *)(DAT_0001fa9c + 0x1fa74),iVar1);
  if (*(short *)(param_2 + 0x20) == *(short *)(param_2 + 0x22)) {
    printf((char *)(DAT_0001faa8 + 0x1fa94));
  }
  else {
    printf((char *)(DAT_0001faa0 + 0x1fa84));
  }
  return;
}



/* Function: FUN_0001faac @ 0001faac */

void FUN_0001faac(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x24) == '\0') {
    iVar1 = DAT_0001fae8 + 0x1fac0;
  }
  else {
    iVar1 = DAT_0001faf4 + 0x1fade;
  }
  printf((char *)(DAT_0001faec + 0x1fac4),iVar1);
  if (*(short *)(param_2 + 0x20) == *(short *)(param_2 + 0x22)) {
    printf((char *)(DAT_0001faf8 + 0x1fae4));
  }
  else {
    printf((char *)(DAT_0001faf0 + 0x1fad4));
  }
  return;
}



/* Function: FUN_0001fc54 @ 0001fc54 */

void FUN_0001fc54(void)

{
  int iVar1;
  
  iVar1 = DAT_0001fc6c;
  FUN_00022bd8(DAT_0001fc6c + 0x1fc5c);
  FUN_00022bd8(iVar1 + 0x1fca4);
  return;
}



/* Function: FUN_0001fc70 @ 0001fc70 */

/* WARNING: Control flow encountered bad instruction data */

undefined4
FUN_0001fc70(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,undefined4 param_5,
            int *param_6,int param_7)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *unaff_r6;
  int iVar5;
  undefined2 local_1c [4];
  
  iVar1 = iRam0001fd00;
  iVar4 = iRam0001fd00 + 0x1fc7e;
  iVar5 = *param_6;
  if (param_1 == 0x31) {
    if (*param_4 == 0) {
      unaff_r6 = *(undefined4 **)(iVar4 + iRam0001fd04);
      iVar2 = FUN_000224cc(*unaff_r6,0,local_1c,0,DAT_0001fd08 - param_7);
      if (iVar2 != 0) {
        *(undefined2 *)(iVar5 + 0x20) = local_1c[0];
        *param_4 = 1;
        return 1;
      }
    }
    else {
      (**(code **)(**(int **)(iVar4 + DAT_0001fd0c) + 0x14))(2,DAT_0001fd10 + 0x1fcd8);
    }
    (**(code **)(**(int **)(iVar4 + DAT_0001fd0c) + 0x14))(2,DAT_0001fd14 + 0x1fce8,*unaff_r6);
LAB_0001fcee:
    (**(code **)(**(int **)(iVar4 + DAT_0001fd0c) + 0x14))(2,DAT_0001fd18 + 0x1fcfa);
    *(undefined4 *)(iVar1 + 0x1fca6) = extraout_r2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar3 = 0;
  if (param_1 == 0x32) {
    if (*param_4 != 0) goto LAB_0001fcee;
    *(undefined2 *)(iVar5 + 0x20) = 0xffff;
    uVar3 = 1;
    *param_4 = 1;
  }
  return uVar3;
}



/* Function: FUN_0001fd1c @ 0001fd1c */

void FUN_0001fd1c(void)

{
  FUN_0001fc70();
  return;
}



/* Function: FUN_0001fd34 @ 0001fd34 */

void FUN_0001fd34(void)

{
  FUN_0001fc70();
  return;
}



/* Function: FUN_0001fd4c @ 0001fd4c */

void FUN_0001fd4c(void)

{
  printf((char *)(DAT_0001fd5c + 0x1fd56),0x3c);
  return;
}



/* Function: FUN_0001fdf8 @ 0001fdf8 */

void FUN_0001fdf8(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  
  __aeabi_uidivmod(param_1,0x3c,param_3,param_4,param_4);
  *param_4 = extraout_r1;
  uVar1 = __aeabi_uidiv(param_1,0x3c);
  __aeabi_uidivmod(uVar1,0x3c);
  *param_3 = extraout_r1_00;
  uVar1 = __aeabi_uidiv(uVar1,0x3c);
  *param_2 = uVar1;
  return;
}



/* Function: FUN_0001fe28 @ 0001fe28 */

void FUN_0001fe28(void)

{
  FUN_0002310c(DAT_0001fe34 + 0x1fe30);
  return;
}



/* Function: FUN_0001fe38 @ 0001fe38 */

void FUN_0001fe38(uint param_1,int param_2)

{
  int extraout_r1;
  int iVar1;
  uint uVar2;
  int iVar3;
  char *__format;
  char *__format_00;
  char *__format_01;
  char *__format_02;
  
  iVar1 = 0;
  uVar2 = 1;
  __format = (char *)(DAT_0001fee0 + 0x1fe5c);
  __format_00 = (char *)(DAT_0001fedc + 0x1fe60);
  __format_01 = (char *)(DAT_0001fee4 + 0x1fe62);
  __format_02 = (char *)(DAT_0001fee8 + 0x1fe64);
  while( true ) {
    if ((1 << (uVar2 & 0xff) & param_1) != 0) {
      iVar3 = iVar1 + 1;
      if (iVar1 != 0) {
        putchar(0x2c);
      }
      printf(__format,uVar2);
      iVar1 = iVar3;
      if (param_2 != 0) {
        __aeabi_uidivmod(uVar2,10);
        if (extraout_r1 == 2) {
          printf(__format_00);
        }
        else if (extraout_r1 == 3) {
          printf(__format_01);
        }
        else if (extraout_r1 == 1) {
          printf((char *)(DAT_0001feec + 0x1feb4));
        }
        else {
          printf(__format_02);
        }
      }
    }
    if (uVar2 == 0x1f) break;
    uVar2 = uVar2 + 1;
  }
  putchar(0x20);
  return;
}



/* Function: FUN_0001fef0 @ 0001fef0 */

void FUN_0001fef0(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  char *__format;
  char *__format_00;
  
  uVar1 = 1;
  puVar2 = (undefined4 *)(DAT_0001ff50 + 0x1ff0c);
  iVar3 = 0;
  __format = (char *)(DAT_0001ff4c + 0x1ff14);
  __format_00 = (char *)(DAT_0001ff54 + 0x1ff16);
  do {
    if ((1 << (uVar1 & 0xff) & param_1) != 0) {
      if (iVar3 == 0) {
        printf(__format,*puVar2);
      }
      else {
        printf(__format_00,*puVar2);
      }
      iVar3 = iVar3 + 1;
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 != 8);
  putchar(0x20);
  return;
}



/* Function: FUN_0001ff58 @ 0001ff58 */

void FUN_0001ff58(int param_1,int param_2)

{
  tm *ptVar1;
  int local_14 [2];
  
  if ((param_1 != DAT_0001ffc4) && (param_1 != 0)) {
    local_14[0] = param_1;
    ptVar1 = localtime(local_14);
    if (param_2 == 0) {
      printf((char *)(DAT_0001ffd0 + 0x1ffb4),ptVar1->tm_year + DAT_0001ffc8,ptVar1->tm_mon + 1,
             ptVar1->tm_mday,ptVar1->tm_hour,ptVar1->tm_min,ptVar1->tm_sec);
    }
    else {
      printf((char *)(DAT_0001ffcc + 0x1ff88),param_2,ptVar1->tm_year + DAT_0001ffc8,
             ptVar1->tm_mon + 1,ptVar1->tm_mday,ptVar1->tm_hour,ptVar1->tm_min,ptVar1->tm_sec);
    }
  }
  return;
}



/* Function: FUN_0001ffd4 @ 0001ffd4 */

void FUN_0001ffd4(undefined4 param_1,int param_2)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((*(int *)(param_2 + 0x28) != 0) ||
     (*(undefined **)(param_2 + 0x2c) != PTR_LAB_0001517c_3_00020084)) {
    FUN_0001fdf8(*(int *)(param_2 + 0x28),&local_1c,&local_20,&local_24);
    printf(PTR_DAT_00020088 + 0x2000e,local_1c,local_20,local_24);
    FUN_0001fdf8(*(undefined4 *)(param_2 + 0x2c),&local_1c,&local_20,&local_24);
    printf(PTR_DAT_0002008c + 0x20026,local_1c,local_20,local_24);
  }
  if (*(int *)(param_2 + 0x30) != -2) {
    printf(PTR_DAT_00020090 + 0x20036);
    FUN_0001fe38(*(undefined4 *)(param_2 + 0x30),0);
  }
  if (*(char *)(param_2 + 0x34) != -2) {
    printf(PTR_DAT_00020094 + 0x2004c);
    FUN_0001fef0(*(undefined1 *)(param_2 + 0x34));
    putchar(0x20);
  }
  FUN_0001ff58(*(undefined4 *)(param_2 + 0x20),PTR_LAB_00020098 + 0x20062);
  FUN_0001ff58(*(undefined4 *)(param_2 + 0x24),PTR_LAB_00010bca_2_0002009c + 0x2006c);
  if (-1 < (int)((uint)*(byte *)(param_2 + 0x35) << 0x1f)) {
    printf(PTR_DAT_000200a0 + 0x2007a);
  }
  return;
}



/* Function: FUN_000200a4 @ 000200a4 */

void FUN_000200a4(undefined4 param_1,int param_2)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  printf(PTR_DAT_00020174 + 0x200b6);
  if ((*(int *)(param_2 + 0x28) != 0) ||
     (*(undefined **)(param_2 + 0x2c) != PTR_LAB_0001517c_3_00020178)) {
    FUN_0001fdf8(*(int *)(param_2 + 0x28),&local_1c,&local_20,&local_24);
    printf(PTR_DAT_0002017c + 0x200e6,local_1c,local_20,local_24);
    FUN_0001fdf8(*(undefined4 *)(param_2 + 0x2c),&local_1c,&local_20,&local_24);
    printf(PTR_DAT_00020180 + 0x200fe,local_1c,local_20,local_24);
  }
  if (*(char *)(param_2 + 0x34) != -2) {
    printf(PTR_DAT_00020184 + 0x2010e);
    FUN_0001fef0(*(undefined1 *)(param_2 + 0x34));
  }
  if (*(int *)(param_2 + 0x30) != -2) {
    printf(PTR_DAT_00020188 + 0x20122);
    FUN_0001fe38(*(undefined4 *)(param_2 + 0x30),1);
  }
  if (*(int *)(param_2 + 0x20) != 0) {
    printf(PTR_DAT_00020198 + 0x20166);
    FUN_0001ff58(*(undefined4 *)(param_2 + 0x20),0);
  }
  if (*(int *)(param_2 + 0x24) != DAT_0002018c) {
    printf(PTR_DAT_00020190 + 0x20140);
    FUN_0001ff58(*(undefined4 *)(param_2 + 0x24),0);
  }
  if (-1 < (int)((uint)*(byte *)(param_2 + 0x35) << 0x1f)) {
    printf(PTR_DAT_00020194 + 0x20156);
  }
  return;
}



/* Function: FUN_0002019c @ 0002019c */

int FUN_0002019c(char *param_1)

{
  char cVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  char *extraout_r3;
  char *pcVar5;
  char *local_1c [2];
  
  uVar2 = strtoul(param_1,local_1c,10);
  pcVar5 = local_1c[0];
  if (uVar2 < 0x18) goto LAB_000201c8;
  do {
    do {
      do {
        (**(code **)(**(int **)(DAT_00020224 + 0x201be) + 0x14))(2,DAT_00020228 + 0x201c2,param_1);
        pcVar5 = extraout_r3;
LAB_000201c8:
      } while (*pcVar5 != ':');
      param_1 = pcVar5 + 1;
      uVar3 = strtoul(param_1,local_1c,10);
      cVar1 = *local_1c[0];
    } while (((cVar1 != '\0') && (cVar1 != ':')) || (0x3b < uVar3));
    uVar4 = 0;
    if (cVar1 == '\0') break;
    param_1 = local_1c[0] + 1;
    uVar4 = strtoul(param_1,local_1c,10);
  } while ((0x3b < uVar4) || (*local_1c[0] != '\0'));
  return uVar3 * 0x3c + uVar2 * 0xe10 + uVar4;
}



/* Function: FUN_0002022c @ 0002022c */

void FUN_0002022c(char *param_1)

{
  byte bVar1;
  ulong uVar2;
  byte *pbVar3;
  time_t tVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  uint extraout_r3;
  int iVar8;
  ulong uVar9;
  tm local_50;
  byte *local_24;
  
  uVar2 = strtoul(param_1,(char **)&local_24,10);
  uVar7 = (uint)*local_24;
  if ((((uVar7 == 0) || (uVar7 == 0x2d)) && (uVar2 <= uRam00020398)) &&
     (pbVar3 = local_24, uRam00020398 - 0x45 < uVar2)) goto LAB_00020272;
  while( true ) {
    do {
      do {
        do {
          pbVar3 = (byte *)(**(code **)(**(int **)(iRam0002039c + 0x20268) + 0x14))
                                     (2,iRam000203a0 + 0x2026c,param_1);
          uVar7 = extraout_r3;
LAB_00020272:
          if (uVar7 == 0) {
            local_50.tm_min = 0;
            uVar6 = 0;
            uVar9 = 1;
            local_50.tm_mon = 0;
            local_50.tm_sec = 0;
            goto LAB_0002027e;
          }
          uVar5 = strtoul((char *)(pbVar3 + 1),(char **)&local_24,10);
          bVar1 = *local_24;
        } while (((bVar1 != 0) && (bVar1 != 0x2d)) || (0xc < uVar5));
        if (bVar1 == 0) {
          local_50.tm_mon = uVar5 - 1;
          local_50.tm_min = 0;
          uVar6 = 0;
          uVar9 = 1;
          local_50.tm_sec = 0;
          goto LAB_0002027e;
        }
        uVar9 = strtoul((char *)(local_24 + 1),(char **)&local_24,10);
        bVar1 = *local_24;
      } while (((bVar1 != 0) && (bVar1 != 0x54)) || (0x1f < uVar9));
      if (bVar1 == 0) {
        local_50.tm_mon = uVar5 - 1;
        local_50.tm_min = 0;
        uVar6 = 0;
        local_50.tm_sec = 0;
        goto LAB_0002027e;
      }
      uVar6 = strtoul((char *)(local_24 + 1),(char **)&local_24,10);
      bVar1 = *local_24;
    } while (((bVar1 != 0) && (bVar1 != 0x3a)) || (0x17 < uVar6));
    if (bVar1 == 0) break;
    local_50.tm_min = strtoul((char *)(local_24 + 1),(char **)&local_24,10);
    bVar1 = *local_24;
    if (((bVar1 == 0) || (bVar1 == 0x3a)) && ((uint)local_50.tm_min < 0x3c)) {
      if (bVar1 == 0) {
        local_50.tm_mon = uVar5 - 1;
        local_50.tm_sec = 0;
        goto LAB_0002027e;
      }
      local_50.tm_sec = strtoul((char *)(local_24 + 1),(char **)&local_24,10);
      if (((uint)local_50.tm_sec < 0x3c) && (*local_24 == 0)) {
        local_50.tm_mon = uVar5 - 1;
LAB_0002027e:
        iVar8 = uVar2 + iRam000203a4;
        local_50.tm_hour = uVar6;
        local_50.tm_mday = uVar9;
        local_50.tm_year = iVar8;
        tVar4 = mktime(&local_50);
        if (-1 < tVar4) {
          return;
        }
        perror((char *)(iRam000203a8 + 0x20382));
        (**(code **)(**(int **)(iRam000203ac + 0x2038e) + 0x14))(1,iRam000203b0 + 0x20392);
        HintPreloadData(iVar8 + 0xfff);
        puts((char *)(DAT_000203c0 + 0x203bc));
                    /* WARNING: Could not recover jumptable at 0x000203be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)0x20397)();
        return;
      }
    }
  }
  local_50.tm_mon = uVar5 - 1;
  local_50.tm_min = 0;
  local_50.tm_sec = 0;
  goto LAB_0002027e;
}



/* Function: FUN_000203c4 @ 000203c4 */

char * FUN_000203c4(char *param_1,size_t param_2,undefined4 *param_3)

{
  char *pcVar1;
  char *__s;
  
  __s = (char *)*param_3;
  if ((__s == (char *)0x0) || (*__s == '\0')) {
    param_1 = (char *)0x0;
  }
  else {
    pcVar1 = strchr(__s,0x2c);
    if (pcVar1 == (char *)0x0) {
      snprintf(param_1,param_2,(char *)(DAT_0002042c + 0x2041c),__s);
      *param_3 = 0;
    }
    else {
      snprintf(param_1,param_2,(char *)(DAT_00020428 + 0x20402),(int)pcVar1 - (int)__s,__s);
      *param_3 = pcVar1 + 1;
    }
  }
  return param_1;
}



/* Function: FUN_00020430 @ 00020430 */

undefined4 FUN_00020430(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (0x33 < param_1 - 0x44U) {
    return 0;
  }
  iVar1 = (param_1 - 0x44U) * 4;
                    /* WARNING: Could not emulate address calculation at 0x0002046e */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)(*(int *)(iVar1 + iRam00020770 + 0x20470) + iRam00020770 + 0x20470))
                    (iVar1,uRam0002076c);
  return uVar2;
}



/* Function: FUN_0002082c @ 0002082c */

void FUN_0002082c(void)

{
  FUN_000232e4(DAT_0002083c + 0x20836,2);
  return;
}



/* Function: FUN_00020840 @ 00020840 */

void FUN_00020840(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x22) != '\0') {
    printf((char *)(DAT_00020864 + 0x20852));
  }
  printf((char *)(DAT_00020868 + 0x2085e),(uint)*(byte *)(param_2 + 0x21),
         (uint)*(byte *)(param_2 + 0x20));
  return;
}



/* Function: FUN_0002086c @ 0002086c */

void FUN_0002086c(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x21) != '\0') {
    printf((char *)(DAT_0002088c + 0x2087e));
  }
  printf((char *)(DAT_00020890 + 0x20888),(uint)*(byte *)(param_2 + 0x20));
  return;
}



/* Function: FUN_00020894 @ 00020894 */

void FUN_00020894(undefined4 param_1,int param_2,int param_3)

{
  byte *pbVar1;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar2;
  
  printf(PTR_DAT_000208fc + 0x208a0);
  if (*(char *)(param_2 + 0x22) != '\0') {
    putchar(0x21);
  }
  if (param_3 == 0) {
    uVar4 = (uint)*(byte *)(param_2 + 0x20);
    uVar3 = (uint)*(byte *)(param_2 + 0x21);
    if (uVar4 == 0x3f) {
      iVar5 = *(int *)(PTR_LAB_00020904 + 0x208da);
      if (iVar5 != 0) {
        pbVar2 = PTR_LAB_00020904 + 0x208d6;
        if (uVar3 != 0x10) {
          do {
            pbVar1 = pbVar2 + 8;
            iVar5 = *(int *)(pbVar2 + 0xc);
            if (iVar5 == 0) goto LAB_000208b6;
            pbVar2 = pbVar1;
          } while (*pbVar1 != uVar3);
        }
        printf(PTR_LAB_00020908 + 0x208f6,DAT_0002090c + 0x208f8,iVar5);
        return;
      }
    }
  }
  else {
    uVar3 = (uint)*(byte *)(param_2 + 0x21);
    uVar4 = (uint)*(byte *)(param_2 + 0x20);
  }
LAB_000208b6:
  printf(PTR_DAT_00020900 + 0x208bc,uVar3,uVar4);
  return;
}



/* Function: FUN_000209c4 @ 000209c4 */

/* WARNING: Removing unreachable block (ram,0x00020b26) */
/* WARNING: Switch with 1 destination removed at 0x00020ad8 */

undefined4 FUN_000209c4(char *param_1,undefined1 *param_2,undefined1 param_3)

{
  uint *puVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  uint *extraout_r3;
  uint *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char **unaff_r8;
  uint *unaff_r9;
  undefined4 uVar11;
  undefined2 local_5c;
  char **ppcStack_58;
  uint *puStack_54;
  undefined1 *puStack_4c;
  char *pcStack_48;
  int iStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int *local_34;
  char *local_2c;
  uint local_28;
  undefined1 auStack_24 [8];
  
  local_38 = 0xff;
  iVar9 = iRam00020a98 + 0x209e2;
  iVar2 = FUN_000224cc(param_1,auStack_24,0,0);
  if (iVar2 == 0) {
    param_2[1] = param_3;
    pcVar3 = *(char **)(iRam00020a9c + 0x209f6);
    puVar7 = (undefined1 *)(iRam00020a9c + 0x209f2);
    while (pcVar3 != (char *)0x0) {
      iVar2 = strcasecmp(param_1,pcVar3);
      if (iVar2 == 0) {
        *param_2 = *puVar7;
        return 1;
      }
      pcVar3 = *(char **)(puVar7 + 0xc);
      puVar7 = puVar7 + 8;
    }
    (**(code **)(**(int **)(iVar9 + iRam00020aa0) + 0x14))(2,iRam00020aa8 + 0x20a80,param_1);
  }
  else {
    unaff_r8 = &local_2c;
    unaff_r9 = &local_28;
    puVar7 = (undefined1 *)0xffffffff;
    local_38 = 0xffffffff;
    FUN_000224cc(param_1,unaff_r8,unaff_r9,0);
    param_2[1] = 0xff;
    *param_2 = (char)local_28;
    cVar4 = *local_2c;
    pcVar3 = local_2c;
    if (cVar4 == '/') goto LAB_00020a58;
    while( true ) {
      if (cVar4 == '\0') {
        return 1;
      }
      pcVar3 = (char *)(**(code **)(**(int **)(iVar9 + iRam00020aa0) + 0x14))
                                 (2,iRam00020aa4 + 0x20a52,param_1);
LAB_00020a58:
      local_38 = 0xffffffff;
      iVar2 = FUN_000224cc(pcVar3 + 1,unaff_r8,unaff_r9,0);
      if (iVar2 == 0) break;
      param_2[1] = (char)local_28;
      cVar4 = *local_2c;
    }
  }
  uVar11 = 0x20a99;
  iVar2 = (**(code **)(**(int **)(iVar9 + iRam00020aa0) + 0x14))(2,iRam00020aac + 0x20a92,param_1);
  puVar1 = extraout_r3;
  puStack_4c = puVar7;
  iStack_44 = iVar9;
  ppcStack_58 = unaff_r8;
  puStack_54 = unaff_r9;
  do {
    do {
      puVar5 = puVar1;
      param_2[(int)puStack_4c] = (char)iStack_44;
      *(int *)(puStack_4c + iVar2) = iStack_44;
      iVar9 = *local_34;
      iVar2 = 0;
      puVar1 = puStack_54;
    } while (iStack_44 * 0x100000 != 0x74);
    local_5c = 0xff00;
    iVar10 = DAT_00020b48 + 0x20af2;
    iVar8 = DAT_00020b4c + 0x20af4;
    pcStack_48 = param_1;
    puStack_40 = param_2;
    uStack_3c = uVar11;
    FUN_000221e0(5,iVar10,iVar8,*puVar5 & 1);
    puVar6 = *(undefined4 **)(DAT_00020b50 + 0x20b08);
    uVar11 = 0x20b11;
    iVar2 = FUN_000209c4(*puVar6,&local_5c,0x3f);
    if (iVar2 == 0) {
      uVar11 = 0x20b45;
      FUN_000221e0(7,iVar10,iVar8,*puVar6);
    }
    *(undefined1 *)(iVar9 + 0x21) = (undefined1)local_5c;
    *(undefined1 *)(iVar9 + 0x20) = local_5c._1_1_;
    iVar2 = 1;
    *puVar5 = *puVar5 | 1;
    puVar1 = puStack_54;
    param_1 = pcStack_48;
    param_2 = puStack_40;
  } while( true );
}



/* Function: FUN_00020c2c @ 00020c2c */

void FUN_00020c2c(void)

{
  FUN_00022d9c(DAT_00020c3c + 0x20c36,2);
  return;
}



/* Function: FUN_00020c40 @ 00020c40 */

void FUN_00020c40(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00020c54 + 0x20c4c),(uint)*(byte *)(param_2 + 0x20),
         (uint)*(byte *)(param_2 + 0x21));
  return;
}



/* Function: FUN_00020c58 @ 00020c58 */

void FUN_00020c58(undefined4 param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar5;
  byte *pbVar4;
  
  if (param_3 == 0) {
    bVar1 = *(byte *)(param_2 + 0x21);
    bVar2 = *(byte *)(param_2 + 0x20);
    if (bVar1 == 0x3f) {
      iVar5 = *(int *)(DAT_00020ce4 + 0x20c8a);
      if (iVar5 != 0) {
        pbVar4 = (byte *)(DAT_00020ce4 + 0x20c86);
        if (bVar2 != 0x10) {
          do {
            pbVar3 = pbVar4 + 8;
            iVar5 = *(int *)(pbVar4 + 0xc);
            if (iVar5 == 0) goto LAB_00020c6a;
            pbVar4 = pbVar3;
          } while (*pbVar3 != bVar2);
        }
        printf((char *)(DAT_00020ce8 + 0x20ca6),PTR_DAT_00020cec + 0x20ca8,iVar5);
        return;
      }
    }
LAB_00020c6a:
    if (bVar2 == 0) {
      printf(PTR_DAT_00020cf4 + 0x20cc6,(uint)(byte)~bVar1);
    }
    else if (bVar2 == bVar1) {
      printf(PTR_DAT_00020cfc + 0x20cda);
    }
    else if (bVar1 == 0) {
      printf(PTR_DAT_00020cf8 + 0x20cd0);
    }
    else {
      printf((char *)(DAT_00020ce0 + 0x20c7c));
    }
  }
  else {
    printf(PTR_DAT_00020cf0 + 0x20cb6,(uint)*(byte *)(param_2 + 0x20),
           (uint)*(byte *)(param_2 + 0x21));
  }
  return;
}



/* Function: FUN_00020d00 @ 00020d00 */

void FUN_00020d00(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00020d10 + 0x20d0c),(uint)*(byte *)(param_2 + 0x20));
  return;
}



/* Function: FUN_00020d14 @ 00020d14 */

void FUN_00020d14(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_00020d30 + 0x20d1e));
  printf((char *)(DAT_00020d34 + 0x20d2a),(uint)*(byte *)(param_2 + 0x20));
  return;
}



/* Function: FUN_00020dc4 @ 00020dc4 */

undefined4 FUN_00020dc4(char *param_1,undefined1 *param_2,undefined1 param_3)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char cVar5;
  uint *extraout_r3;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  undefined *puVar11;
  char **unaff_r8;
  int iVar12;
  undefined *puVar13;
  undefined1 *unaff_r9;
  undefined4 uStack_60;
  byte bStack_5c;
  undefined1 uStack_5b;
  char **ppcStack_54;
  undefined1 *puStack_50;
  undefined1 *puStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int *piStack_34;
  char *local_2c;
  undefined1 local_28 [4];
  undefined1 auStack_24 [8];
  
  local_38 = 0xff;
  iVar8 = iRam00020e98 + 0x20de2;
  iVar2 = FUN_000224cc(param_1,auStack_24,0,0);
  if (iVar2 == 0) {
    param_2[1] = param_3;
    pcVar3 = *(char **)(iRam00020e9c + 0x20df6);
    puVar6 = (undefined1 *)(iRam00020e9c + 0x20df2);
    while (pcVar3 != (char *)0x0) {
      iVar2 = strcasecmp(param_1,pcVar3);
      if (iVar2 == 0) {
        *param_2 = *puVar6;
        return 1;
      }
      pcVar3 = *(char **)(puVar6 + 0xc);
      puVar6 = puVar6 + 8;
    }
    (**(code **)(**(int **)(iVar8 + iRam00020ea0) + 0x14))(2,PTR_LAB_00020ea8 + 0x20e80,param_1);
  }
  else {
    unaff_r8 = &local_2c;
    unaff_r9 = local_28;
    puVar6 = (undefined1 *)0xffffffff;
    local_38 = 0xffffffff;
    FUN_000224cc(param_1,unaff_r8,unaff_r9,0);
    param_2[1] = 0xff;
    *param_2 = local_28[0];
    cVar5 = *local_2c;
    pcVar3 = local_2c;
    if (cVar5 == '/') goto LAB_00020e58;
    while( true ) {
      if (cVar5 == '\0') {
        return 1;
      }
      pcVar3 = (char *)(**(code **)(**(int **)(iVar8 + iRam00020ea0) + 0x14))
                                 (2,PTR_DAT_00020ea4 + 0x20e52,param_1);
LAB_00020e58:
      local_38 = 0xffffffff;
      iVar2 = FUN_000224cc(pcVar3 + 1,unaff_r8,unaff_r9,0);
      if (iVar2 == 0) break;
      param_2[1] = local_28[0];
      cVar5 = *local_2c;
    }
  }
  (**(code **)(**(int **)(iVar8 + iRam00020ea0) + 0x14))(2,PTR_LAB_00020eac + 0x20e92,param_1);
  *(int *)(param_2 + (int)puVar6) = iVar8;
  puVar1 = PTR_PTR_00021050;
  iVar2 = iVar8 * 0x10;
  iVar4 = iVar8 * 0x100;
  uStack_3c = 0x20e99;
  uStack_48 = uRam00021018;
  iVar9 = *piStack_34;
  pbVar10 = (byte *)(iVar9 + 0x20);
  ppcStack_54 = unaff_r8;
  puStack_50 = unaff_r9;
  puStack_4c = puVar6;
  iStack_44 = iVar8;
  puStack_40 = param_2;
  if (iVar2 == 0x3d) {
    puVar11 = PTR_PTR_0002106c + 0x20f94;
    iVar8 = DAT_00021068 + 0x20f96;
    FUN_000221e0(5,puVar11,iVar8,*extraout_r3 & 1);
    FUN_000221e0(6,puVar11,iVar8,iVar4);
    puVar7 = *(undefined4 **)(puVar1 + DAT_0002105c + 0x20ec8);
    iVar2 = FUN_00020dc4(*puVar7,&bStack_5c,0x3f);
    if (iVar2 == 0) {
      FUN_000221e0(7,puVar11,iVar8,*puVar7);
    }
    *pbVar10 = bStack_5c;
    *(undefined1 *)(iVar9 + 0x21) = uStack_5b;
  }
  else if (iVar2 < 0x3e) {
    if (iVar2 != 0x26) {
      return 0;
    }
    puVar11 = PTR_DAT_00021058 + 0x20ef8;
    puVar13 = PTR_DAT_00021054 + 0x20efa;
    FUN_000221e0(5,puVar11,puVar13,*extraout_r3 & 1);
    FUN_000221e0(6,puVar11,puVar13,iVar4);
    puVar7 = *(undefined4 **)(puVar1 + DAT_0002105c + 0x20ec8);
    iVar2 = FUN_000224cc(*puVar7,0,&uStack_60,0,0xff);
    if (iVar2 == 0) {
      FUN_000221e0(7,puVar11,puVar13,*puVar7);
    }
    *pbVar10 = 0;
    *(byte *)(iVar9 + 0x21) = ~(byte)uStack_60;
  }
  else if (iVar2 == 0x5e) {
    puVar11 = PTR_DAT_00021074 + 0x20fde;
    puVar13 = PTR_DAT_00021070 + 0x20fe0;
    FUN_000221e0(5,puVar11,puVar13,*extraout_r3 & 1);
    FUN_000221e0(6,puVar11,puVar13,iVar4);
    puVar7 = *(undefined4 **)(puVar1 + DAT_0002105c + 0x20ec8);
    iVar2 = FUN_000224cc(*puVar7,0,&uStack_60,0,0xff);
    if (iVar2 == 0) {
      FUN_000221e0(7,puVar11,puVar13,*puVar7);
    }
    *pbVar10 = (byte)uStack_60;
    *(undefined1 *)(iVar9 + 0x21) = 0;
  }
  else {
    if (iVar2 != 0x7c) {
      return 0;
    }
    iVar8 = DAT_00021064 + 0x20f4c;
    iVar12 = DAT_00021060 + 0x20f4e;
    FUN_000221e0(5,iVar8,iVar12,*extraout_r3 & 1);
    FUN_000221e0(6,iVar8,iVar12,iVar4);
    puVar7 = *(undefined4 **)(puVar1 + DAT_0002105c + 0x20ec8);
    iVar2 = FUN_000224cc(*puVar7,0,&uStack_60,0,0xff);
    if (iVar2 == 0) {
      FUN_000221e0(7,iVar8,iVar12,*puVar7);
    }
    *pbVar10 = (byte)uStack_60;
    *(byte *)(iVar9 + 0x21) = (byte)uStack_60;
  }
  *extraout_r3 = *extraout_r3 | 1;
  return 1;
}



/* Function: FUN_00020eb0 @ 00020eb0 */

undefined4
FUN_00020eb0(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,undefined4 param_5,
            int *param_6)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  undefined *puVar9;
  byte local_28 [4];
  byte local_24;
  undefined1 local_23;
  
  puVar1 = PTR_PTR_00021050;
  iVar4 = *param_6;
  pbVar5 = (byte *)(iVar4 + 0x20);
  if (param_1 == 0x3d) {
    puVar7 = PTR_PTR_0002106c + 0x20f94;
    iVar6 = DAT_00021068 + 0x20f96;
    FUN_000221e0(5,puVar7,iVar6,*param_4 & 1);
    FUN_000221e0(6,puVar7,iVar6,param_3);
    puVar3 = *(undefined4 **)(puVar1 + DAT_0002105c + 0x20ec8);
    iVar2 = FUN_00020dc4(*puVar3,&local_24,0x3f);
    if (iVar2 == 0) {
      FUN_000221e0(7,puVar7,iVar6,*puVar3);
    }
    *pbVar5 = local_24;
    *(undefined1 *)(iVar4 + 0x21) = local_23;
  }
  else if (param_1 < 0x3e) {
    if (param_1 != 0x26) {
      return 0;
    }
    puVar7 = PTR_DAT_00021058 + 0x20ef8;
    puVar9 = PTR_DAT_00021054 + 0x20efa;
    FUN_000221e0(5,puVar7,puVar9,*param_4 & 1);
    FUN_000221e0(6,puVar7,puVar9,param_3);
    puVar3 = *(undefined4 **)(puVar1 + DAT_0002105c + 0x20ec8);
    iVar2 = FUN_000224cc(*puVar3,0,local_28,0,0xff);
    if (iVar2 == 0) {
      FUN_000221e0(7,puVar7,puVar9,*puVar3);
    }
    *pbVar5 = 0;
    *(byte *)(iVar4 + 0x21) = ~local_28[0];
  }
  else if (param_1 == 0x5e) {
    puVar7 = PTR_DAT_00021074 + 0x20fde;
    puVar9 = PTR_DAT_00021070 + 0x20fe0;
    FUN_000221e0(5,puVar7,puVar9,*param_4 & 1);
    FUN_000221e0(6,puVar7,puVar9,param_3);
    puVar3 = *(undefined4 **)(puVar1 + DAT_0002105c + 0x20ec8);
    iVar2 = FUN_000224cc(*puVar3,0,local_28,0,0xff);
    if (iVar2 == 0) {
      FUN_000221e0(7,puVar7,puVar9,*puVar3);
    }
    *pbVar5 = local_28[0];
    *(undefined1 *)(iVar4 + 0x21) = 0;
  }
  else {
    if (param_1 != 0x7c) {
      return 0;
    }
    iVar6 = DAT_00021064 + 0x20f4c;
    iVar8 = DAT_00021060 + 0x20f4e;
    FUN_000221e0(5,iVar6,iVar8,*param_4 & 1);
    FUN_000221e0(6,iVar6,iVar8,param_3);
    puVar3 = *(undefined4 **)(puVar1 + DAT_0002105c + 0x20ec8);
    iVar2 = FUN_000224cc(*puVar3,0,local_28,0,0xff);
    if (iVar2 == 0) {
      FUN_000221e0(7,iVar6,iVar8,*puVar3);
    }
    *pbVar5 = local_28[0];
    *(byte *)(iVar4 + 0x21) = local_28[0];
  }
  *param_4 = *param_4 | 1;
  return 1;
}



/* Function: FUN_00021150 @ 00021150 */

void FUN_00021150(void)

{
  FUN_00022bd8(DAT_0002115c + 0x21158);
  return;
}



/* Function: FUN_00021160 @ 00021160 */

void FUN_00021160(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  printf((char *)(DAT_0002119c + 0x2117a),
         (*(ushort *)(param_2 + 0x2c) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 0x2c) >> 8));
  uVar1 = FUN_00021f64(param_2 + 0x28);
  printf((char *)(DAT_000211a0 + 0x2118c),uVar1);
  printf((char *)(DAT_000211a4 + 0x21198),*(undefined4 *)(param_2 + 0x24),
         *(undefined4 *)(param_2 + 0x20));
  return;
}



/* Function: FUN_000211a8 @ 000211a8 */

void FUN_000211a8(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00021f64(param_2 + 0x28);
  printf((char *)(DAT_000211dc + 0x211d2),uVar1,
         (*(ushort *)(param_2 + 0x2c) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 0x2c) >> 8),
         *(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_2 + 0x20));
  return;
}



/* Function: FUN_000211e0 @ 000211e0 */

undefined4
FUN_000211e0(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,undefined4 param_5,
            int *param_6)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  char *local_2c;
  undefined4 local_28;
  uint local_24;
  
  puVar1 = PTR_LAB_00021390;
  iVar6 = *param_6;
  if (param_1 == 0x32) {
    puVar7 = PTR_FUN_000213ac + 0x212e8;
    puVar8 = PTR_LAB_000213b0 + 0x212ea;
    FUN_000221e0(5,puVar7,puVar8,*param_4 & 2);
    FUN_000221e0(6,puVar7,puVar8,param_3);
    uVar5 = **(undefined4 **)(puVar1 + DAT_0002139c + 0x211fc);
    puVar3 = (undefined4 *)FUN_00022774(uVar5);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_000221e0(7,puVar7,puVar8,uVar5);
    }
    uVar5 = 1;
    *(undefined4 *)(iVar6 + 0x28) = *puVar3;
    *param_4 = *param_4 | 2;
  }
  else if (param_1 == 0x33) {
    puVar7 = PTR_LAB_000213a8 + 0x21282;
    puVar8 = PTR_DAT_000213a4 + 0x21284;
    FUN_000221e0(5,puVar7,puVar8,*param_4 & 4);
    FUN_000221e0(6,puVar7,puVar8,param_3);
    uVar5 = **(undefined4 **)(puVar1 + DAT_0002139c + 0x211fc);
    local_28 = 0xffffffff;
    iVar2 = FUN_000224cc(uVar5,&local_2c,&local_24,0,0xffffffff);
    if (iVar2 == 0) {
      FUN_000221e0(7,puVar7,puVar8,uVar5);
    }
    cVar4 = *local_2c;
    if (cVar4 == '/') {
      iVar2 = FUN_000224cc(local_2c + 1,&local_2c,&local_28,0,0xffffffff);
      if (iVar2 == 0) {
        FUN_000221e0(7,DAT_000213bc + 0x21388,DAT_000213c0 + 0x2138a,uVar5);
      }
      cVar4 = *local_2c;
    }
    if (cVar4 != '\0') {
      FUN_000221e0(7,DAT_000213b4 + 0x21330,DAT_000213b8 + 0x21332,uVar5);
    }
    uVar5 = 1;
    *(undefined4 *)(iVar6 + 0x20) = local_28;
    *(uint *)(iVar6 + 0x24) = local_24;
    *param_4 = *param_4 | 4;
  }
  else {
    uVar5 = 0;
    if (param_1 == 0x31) {
      puVar7 = PTR_DAT_00021394 + 0x21226;
      puVar8 = PTR_DAT_00021398 + 0x21228;
      FUN_000221e0(5,puVar7,puVar8,*param_4 & 1);
      FUN_000221e0(6,puVar7,puVar8,param_3);
      uVar5 = **(undefined4 **)(puVar1 + DAT_0002139c + 0x211fc);
      iVar2 = FUN_000224cc(uVar5,0,&local_24,0,PTR_LAB_0000fffe_1_000213a0);
      if (iVar2 == 0) {
        FUN_000221e0(7,puVar7,puVar8,uVar5);
      }
      else {
        *(ushort *)(iVar6 + 0x2c) =
             (ushort)(local_24 >> 8) & 0xff | (ushort)((local_24 & 0xffff) << 8);
      }
      uVar5 = 1;
      *param_4 = *param_4 | 1;
    }
  }
  return uVar5;
}



/* Function: FUN_000213d4 @ 000213d4 */

void FUN_000213d4(void)

{
  FUN_00022bd8(DAT_000213e0 + 0x213dc);
  return;
}



/* Function: FUN_000213e4 @ 000213e4 */

void FUN_000213e4(void)

{
  FUN_0002310c(DAT_000213f0 + 0x213ec);
  return;
}



/* Function: FUN_000213f4 @ 000213f4 */

void FUN_000213f4(int param_1)

{
  char cVar1;
  int iVar2;
  char *__format;
  char *__format_00;
  char *pcVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  byte *pbVar7;
  char *__format_01;
  char *__format_02;
  uint uVar8;
  
  iVar2 = DAT_00021530;
  if (*(char *)(param_1 + DAT_0002152c) != '\0') {
    uVar8 = 0;
    __format_00 = (char *)(DAT_00021538 + 0x21424);
    __format = (char *)(DAT_0002153c + 0x21426);
    pbVar7 = (byte *)(param_1 + 0xb0);
    __format_01 = (char *)(DAT_00021534 + 0x2142e);
LAB_0002142c:
    printf((char *)(iVar2 + 0x21438),*(undefined4 *)(pbVar7 + -0xb0));
    if (1 < *pbVar7) {
      uVar4 = 1;
      pcVar3 = (char *)(uVar8 * 0xb4 + param_1 + 0xc);
      do {
        cVar1 = *pcVar3;
        if (cVar1 == '\x01') {
          printf(__format_00);
        }
        else if (cVar1 == '\0') {
          putchar(0x26);
        }
        else if (cVar1 == '\x02') {
          printf(__format);
        }
        else if (cVar1 == '\x03') {
          putchar(0x40);
        }
        printf(__format_01,*(undefined4 *)(pcVar3 + -4));
        uVar4 = uVar4 + 1;
        pcVar3 = pcVar3 + 8;
      } while (uVar4 < *pbVar7);
    }
    putchar(0x3d);
    if (pbVar7[1] != 0) {
      piVar5 = (int *)(uVar8 * 0xb4 + 0x58 + param_1);
      uVar4 = 0;
      pcVar3 = (char *)(DAT_00021544 + 0x214bc);
      __format_02 = (char *)(DAT_00021540 + 0x214be);
      if (*piVar5 == piVar5[1]) goto LAB_000214dc;
      while( true ) {
        printf(pcVar3);
        uVar4 = uVar4 + 1;
        piVar6 = piVar5;
        if (pbVar7[1] <= uVar4) break;
        while( true ) {
          if (uVar4 != 0) {
            putchar(0x2c);
          }
          piVar5 = piVar6 + 2;
          if (*piVar5 != piVar6[3]) break;
LAB_000214dc:
          printf(__format_02);
          uVar4 = uVar4 + 1;
          piVar6 = piVar5;
          if (pbVar7[1] <= uVar4) goto LAB_000214ea;
        }
      }
    }
LAB_000214ea:
    uVar8 = uVar8 + 1;
    if (uVar8 < *(byte *)(param_1 + DAT_0002152c)) {
      if (uVar8 == 0) {
        pbVar7 = pbVar7 + 0xb4;
      }
      else {
        pbVar7 = pbVar7 + 0xb4;
        printf((char *)(DAT_00021548 + 0x21514));
      }
      goto LAB_0002142c;
    }
  }
  putchar(0x20);
  return;
}



/* Function: FUN_0002154c @ 0002154c */

void FUN_0002154c(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x20 + DAT_00021574) != '\0') {
    printf((char *)(DAT_00021578 + 0x21560));
  }
  printf((char *)(DAT_0002157c + 0x21568));
  FUN_000213f4(param_2 + 0x20);
  return;
}



/* Function: FUN_00021580 @ 00021580 */

void FUN_00021580(undefined4 param_1,int param_2)

{
  printf((char *)(DAT_000215a8 + 0x2158c));
  if (*(char *)(param_2 + 0x20 + DAT_000215ac) != '\0') {
    printf((char *)(DAT_000215b0 + 0x2159c));
  }
  FUN_000213f4(param_2 + 0x20);
  return;
}



/* Function: FUN_00021984 @ 00021984 */

void FUN_00021984(void)

{
  FUN_0002310c(DAT_00021990 + 0x2198c);
  return;
}



/* Function: FUN_00021994 @ 00021994 */

void FUN_00021994(undefined4 param_1,int param_2)

{
  short sVar1;
  
  if ((*(short *)(param_2 + 0x20) == 0) && (*(ushort *)(param_2 + 0x22) == DAT_00021a14))
  goto LAB_000219be;
  if ((int)((uint)*(byte *)(param_2 + 0x28) << 0x1f) < 0) {
    printf((char *)(DAT_00021a28 + 0x219fe));
    if (*(short *)(param_2 + 0x22) == *(short *)(param_2 + 0x20)) goto LAB_00021a08;
  }
  else if (*(short *)(param_2 + 0x22) == *(short *)(param_2 + 0x20)) {
LAB_00021a08:
    printf((char *)(DAT_00021a2c + 0x21a0e));
    goto LAB_000219be;
  }
  printf((char *)(DAT_00021a18 + 0x219bc));
LAB_000219be:
  sVar1 = *(short *)(param_2 + 0x24);
  if ((sVar1 != 0) || (*(ushort *)(param_2 + 0x26) != DAT_00021a14)) {
    if ((int)((uint)*(byte *)(param_2 + 0x28) << 0x1e) < 0) {
      printf((char *)(DAT_00021a24 + 0x219f2));
      sVar1 = *(short *)(param_2 + 0x24);
    }
    if (*(short *)(param_2 + 0x26) == sVar1) {
      printf((char *)(DAT_00021a20 + 0x219e8));
    }
    else {
      printf((char *)(DAT_00021a1c + 0x219de));
    }
  }
  return;
}



/* Function: FUN_00021a30 @ 00021a30 */

void FUN_00021a30(uint param_1,int param_2)

{
  servent *psVar1;
  
  if (((param_2 == 0) &&
      (psVar1 = getservbyport((param_1 << 8 | param_1 >> 8) & 0xffff,
                              (char *)(DAT_00021a6c + 0x21a48)), psVar1 != (servent *)0x0)) &&
     (psVar1->s_name != (char *)0x0)) {
    printf((char *)(DAT_00021a70 + 0x21a5a));
  }
  else {
    printf((char *)(DAT_00021a74 + 0x21a66),param_1);
  }
  return;
}



/* Function: FUN_00021a78 @ 00021a78 */

void FUN_00021a78(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined *puVar1;
  
  if (param_4 == 0) {
    puVar1 = (undefined *)(DAT_00021af4 + 0x21a8c);
  }
  else {
    puVar1 = &UNK_00021af2 + DAT_00021b0c;
  }
  if ((param_3 == DAT_00021af8) && (param_2 == 0)) {
    if (param_4 == 0) {
      return;
    }
    printf((char *)(DAT_00021b04 + 0x21ac2),param_1,DAT_00021af8,param_4,param_4);
  }
  else {
    printf((char *)(DAT_00021afc + 0x21a98),param_1,DAT_00021af8,param_4,param_4);
    if (param_2 == param_3) {
      printf((char *)(DAT_00021b00 + 0x21aa6),puVar1);
      FUN_00021a30(param_2,param_5);
      goto LAB_00021ae4;
    }
  }
  printf((char *)(DAT_00021b08 + 0x21acc),puVar1);
  FUN_00021a30(param_2,param_5);
  putchar(0x3a);
  FUN_00021a30(param_3,param_5);
LAB_00021ae4:
  putchar(0x20);
  return;
}



/* Function: FUN_00021b10 @ 00021b10 */

void FUN_00021b10(undefined4 param_1,int param_2,undefined4 param_3)

{
  printf((char *)(DAT_00021b64 + 0x21b20));
  FUN_00021a78(DAT_00021b68 + 0x21b34,*(undefined2 *)(param_2 + 0x20),
               *(undefined2 *)(param_2 + 0x22),*(byte *)(param_2 + 0x28) & 1,param_3);
  FUN_00021a78(DAT_00021b6c + 0x21b48,*(undefined2 *)(param_2 + 0x24),
               *(undefined2 *)(param_2 + 0x26),*(byte *)(param_2 + 0x28) & 2,param_3);
  if ((*(byte *)(param_2 + 0x28) & 0xfc) != 0) {
    printf((char *)(DAT_00021b70 + 0x21b5c));
  }
  return;
}



/* Function: FUN_00021d00 @ 00021d00 */

int FUN_00021d00(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((((*param_1 == '\0') || (iVar1 = strcmp(param_1,(char *)(DAT_00021da4 + 0x21d12)), iVar1 == 0)
       ) || (iVar1 = strcmp(param_1,(char *)(DAT_00021db0 + 0x21d56)), iVar1 == 0)) ||
     ((iVar1 = strcmp(param_1,(char *)(DAT_00021db4 + 0x21d64)), iVar1 == 0 ||
      (iVar1 = strcmp(param_1,(char *)(DAT_00021db8 + 0x21d72)), iVar1 == 0)))) {
    param_1 = (char *)(DAT_00021da8 + 0x21d1e);
  }
  iVar1 = **(int **)(DAT_00021dac + 0x21d22);
  do {
    if (iVar1 == 0) {
      iVar1 = 0;
      if (param_2 == 3) {
        (**(code **)(**(int **)(DAT_00021dbc + 0x21d8a) + 0x14))(2,DAT_00021dc0 + 0x21d8e,param_1);
LAB_00021d94:
        if (param_2 == 0) {
          iVar1 = 0;
        }
        else {
          *(undefined4 *)(iVar1 + 0x44) = 1;
LAB_00021d42:
          if (iVar1 != 0) {
            *(undefined4 *)(iVar1 + 0x40) = 1;
          }
        }
      }
      return iVar1;
    }
    iVar2 = strcmp(param_1,*(char **)(iVar1 + 8));
    if (iVar2 == 0) {
      if (*(int *)(iVar1 + 0x44) != 0) goto LAB_00021d42;
      goto LAB_00021d94;
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}



/* Function: FUN_00021dc4 @ 00021dc4 */

undefined4 FUN_00021dc4(char *param_1,int *param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  byte *__s;
  size_t sVar3;
  byte *pbVar4;
  code *pcVar5;
  char *__accept;
  int iVar6;
  FILE *pFVar7;
  int iVar8;
  undefined4 extraout_r12;
  undefined4 in_cr0;
  
  iVar6 = iRam00021e44 + 0x21dd0;
  if ((param_1 == (char *)0x0) ||
     (iVar8 = param_4, iVar1 = strcmp(param_1,(char *)(iRam00021e48 + 0x21dda)), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    fwrite((void *)(iRam00021e50 + 0x21df0),1,0x72,(FILE *)(*(int *)(iVar6 + iRam00021e4c) + 0xa8));
    if (*param_2 != 0) {
LAB_00021e34:
      (**(code **)(**(int **)(iVar6 + iRam00021e58) + 0x14))(2,iRam00021e60 + 0x21e40);
      coprocessor_loadlong(0,in_cr0,extraout_r12);
      __s = (byte *)(param_4 * 0x100);
      coprocessor_load(0,in_cr0,__s);
      coprocessor_store(0,in_cr0,__s);
      iVar8 = DAT_00021f04 + 0x21e76;
      sVar3 = strcspn((char *)__s,(char *)(DAT_00021f00 + 0x21e74));
      iVar6 = DAT_00021f08;
      if ((sVar3 == 0) || (__s[sVar3] != 0)) {
        putc(0x22,(FILE *)(*(int *)(iVar8 + DAT_00021f08) + 0x54));
        __accept = (char *)(DAT_00021f0c + 0x21ed8);
        while (pbVar4 = (byte *)strpbrk((char *)__s,__accept), pbVar4 != (byte *)0x0) {
          if (__s < pbVar4) {
            fwrite(__s,1,(int)pbVar4 - (int)__s,(FILE *)(*(int *)(iVar8 + iVar6) + 0x54));
          }
          pFVar7 = (FILE *)(*(int *)(iVar8 + iVar6) + 0x54);
          putc(0x5c,pFVar7);
          putc((uint)*pbVar4,pFVar7);
          __s = pbVar4 + 1;
        }
        fputs((char *)__s,(FILE *)(*(int *)(iVar8 + iVar6) + 0x54));
        printf((char *)(DAT_00021f10 + 0x21ede));
      }
      else {
        pFVar7 = (FILE *)(*(int *)(iVar8 + DAT_00021f08) + 0x54);
        fputs((char *)__s,pFVar7);
        putc(0x20,pFVar7);
      }
                    /* WARNING: Could not recover jumptable at 0x00021ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)0x21e45)();
      return uVar2;
    }
    *param_2 = 1;
    if (param_3 != (int *)0x0) {
      uVar2 = *(undefined4 *)(*param_3 * 4 + param_5);
      **(undefined4 **)(iVar6 + iRam00021e54) = uVar2;
      iVar1 = *param_3;
      *param_3 = iVar1 + 1;
      if ((param_4 != 0) && (param_4 < iVar1 + 1)) {
        pcVar5 = *(code **)(**(int **)(iVar6 + iRam00021e58) + 0x14);
        (*pcVar5)(2,iRam00021e5c + 0x21e30,uVar2,pcVar5,iVar8);
        goto LAB_00021e34;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* Function: FUN_00021e64 @ 00021e64 */

void FUN_00021e64(byte *param_1)

{
  int iVar1;
  size_t sVar2;
  byte *pbVar3;
  char *__accept;
  FILE *pFVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar5 = DAT_00021f04 + 0x21e76;
  sVar2 = strcspn((char *)param_1,(char *)(DAT_00021f00 + 0x21e74));
  iVar1 = DAT_00021f08;
  if ((sVar2 == 0) || (param_1[sVar2] != 0)) {
    putc(0x22,(FILE *)(*(int *)(iVar5 + DAT_00021f08) + 0x54));
    __accept = (char *)(DAT_00021f0c + 0x21ed8);
    while (pbVar3 = (byte *)strpbrk((char *)param_1,__accept), pbVar3 != (byte *)0x0) {
      if (param_1 < pbVar3) {
        fwrite(param_1,1,(int)pbVar3 - (int)param_1,(FILE *)(*(int *)(iVar5 + iVar1) + 0x54));
      }
      pFVar4 = (FILE *)(*(int *)(iVar5 + iVar1) + 0x54);
      putc(0x5c,pFVar4);
      putc((uint)*pbVar3,pFVar4);
      param_1 = pbVar3 + 1;
    }
    fputs((char *)param_1,(FILE *)(*(int *)(iVar5 + iVar1) + 0x54));
    printf((char *)(DAT_00021f10 + 0x21ede));
  }
  else {
    pFVar4 = (FILE *)(*(int *)(iVar5 + DAT_00021f08) + 0x54);
    fputs((char *)param_1,pFVar4);
    putc(0x20,pFVar4);
  }
                    /* WARNING: Could not recover jumptable at 0x00021ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



/* Function: FUN_00021f14 @ 00021f14 */

void FUN_00021f14(int param_1)

{
  void *__ptr;
  int *piVar1;
  
  piVar1 = *(int **)(DAT_00021f40 + 0x21f1e);
  __ptr = *(void **)(*piVar1 + 0x10);
  if (__ptr != *(void **)(*piVar1 + 0xc)) {
    free(__ptr);
    *(undefined4 *)(*piVar1 + 0x10) = *(undefined4 *)(*piVar1 + 0xc);
    if (param_1 != 0) {
      *(undefined4 *)*piVar1 = 0;
    }
  }
  return;
}



/* Function: FUN_00021f44 @ 00021f44 */

uint FUN_00021f44(char *param_1)

{
  int iVar1;
  void *__buf;
  
  __buf = (void *)(DAT_00021f60 + 0x21f50);
  iVar1 = inet_pton(10,param_1,__buf);
  return -(uint)(iVar1 == 1) & (uint)__buf;
}



/* Function: FUN_00021f64 @ 00021f64 */

char * FUN_00021f64(byte *param_1)

{
  char *__s;
  
  __s = &UNK_00021f8a + DAT_00021f8c;
  sprintf(__s,(char *)(DAT_00021f90 + 0x21f80),(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
          (uint)param_1[3]);
  return __s;
}



/* Function: FUN_00021f94 @ 00021f94 */

char * FUN_00021f94(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  bool bVar6;
  
  uVar3 = *param_1;
  uVar3 = uVar3 >> 0x18 | uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | (uVar3 & 0xff0000) >> 8;
  if (uVar3 == 0xffffffff) {
    pcVar5 = (char *)(DAT_00022014 + 0x22000);
  }
  else {
    if (uVar3 == 0xfffffffe) {
      iVar2 = 0x1f;
    }
    else {
      iVar2 = 0x1e;
      for (uVar4 = 0xfffffffc; uVar3 != uVar4; uVar4 = uVar4 << 1) {
        bVar6 = iVar2 == 0;
        iVar2 = iVar2 + -1;
        if (bVar6) {
          uVar1 = FUN_00021f64();
          pcVar5 = (char *)((int)&DAT_00022010 + DAT_0002200c + 2);
          sprintf(pcVar5,(char *)(DAT_00022010 + 0x21ff2),uVar1);
          return pcVar5;
        }
      }
    }
    pcVar5 = (char *)(DAT_00022004 + 0x21ff8);
    sprintf(pcVar5,(char *)(DAT_00022008 + 0x21fd8),iVar2);
  }
  return pcVar5;
}



/* Function: FUN_00022018 @ 00022018 */

void FUN_00022018(void *param_1)

{
  inet_ntop(10,param_1,(char *)(DAT_0002202c + 0x2205c),0x33);
  return;
}



/* Function: FUN_00022030 @ 00022030 */

int FUN_00022030(uint *param_1)

{
  char *__src;
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *__dest;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = *param_1;
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  uVar3 = uVar3 << 0x18 | uVar3 >> 0x18 | (uVar3 & 0xff00) << 8 | (uVar3 & 0xff0000) >> 8;
  uVar4 = uVar4 << 0x18 | uVar4 >> 0x18 | (uVar4 & 0xff00) << 8 | (uVar4 & 0xff0000) >> 8;
  uVar5 = param_1[3];
  uVar5 = uVar5 << 0x18 | uVar5 >> 0x18 | (uVar5 & 0xff00) << 8 | (uVar5 & 0xff0000) >> 8;
  iVar2 = 0;
  for (uVar1 = uVar1 << 0x18 | uVar1 >> 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8;
      (int)uVar1 < 0; uVar1 = uVar1 << 1 | uVar6) {
    uVar6 = uVar3 >> 0x1f;
    uVar3 = uVar3 << 1 | uVar4 >> 0x1f;
    iVar2 = iVar2 + 1;
    uVar4 = uVar4 << 1 | uVar5 >> 0x1f;
    uVar5 = uVar5 << 1;
  }
  if ((((uVar3 == 0) && (uVar1 == 0)) && (uVar4 == 0)) && ((uVar5 == 0 && (iVar2 != -1)))) {
    sprintf((char *)(DAT_0002210c + 0x22166),(char *)(DAT_00022110 + 0x220fc));
  }
  else {
    __dest = (char *)(DAT_00022104 + 0x22132);
    __dest[0] = '/';
    __dest[1] = '\0';
    __src = (char *)FUN_00022018();
    strcat(__dest,__src);
  }
  return DAT_00022108 + 0x22146;
}



/* Function: FUN_00022114 @ 00022114 */

void FUN_00022114(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__host;
  sockaddr local_40;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  iVar1 = DAT_0002218c;
  iVar3 = DAT_00022188 + 0x22126;
  local_24 = **(int **)(iVar3 + DAT_0002218c);
  local_40.sa_data[2] = '\0';
  local_40.sa_data[3] = '\0';
  local_40.sa_data[4] = '\0';
  local_40.sa_data[5] = '\0';
  local_28 = 0;
  local_40.sa_data._6_4_ = *(undefined4 *)param_1;
  local_40.sa_data._10_4_ = *(undefined4 *)(param_1 + 4);
  uStack_30 = *(undefined4 *)(param_1 + 8);
  local_2c = *(undefined4 *)(param_1 + 0xc);
  local_40.sa_family = 10;
  local_40.sa_data[0] = '\0';
  local_40.sa_data[1] = '\0';
  __host = (char *)(DAT_00022190 + 0x2216a);
  iVar2 = getnameinfo(&local_40,0x1c,__host,0x400,(char *)0x0,0,0);
  if (iVar2 != 0) {
    __host = (char *)FUN_00022018(param_1);
  }
  if (local_24 == **(int **)(iVar3 + iVar1)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__host);
}



/* Function: FUN_00022194 @ 00022194 */

void FUN_00022194(uint *param_1)

{
  hostent *phVar1;
  netent *pnVar2;
  uint uVar3;
  
  phVar1 = gethostbyaddr(param_1,4,2);
  if ((phVar1 == (hostent *)0x0) || (phVar1->h_name == (char *)0x0)) {
    uVar3 = *param_1;
    pnVar2 = getnetbyaddr(uVar3 >> 0x18 | uVar3 << 0x18 | (uVar3 & 0xff00) << 8 |
                          (uVar3 & 0xff0000) >> 8,2);
    if ((pnVar2 == (netent *)0x0) || (pnVar2->n_name == (char *)0x0)) {
      FUN_00021f64(param_1);
    }
  }
  return;
}



/* Function: FUN_000221e0 @ 000221e0 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_000221e0(uint param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  code *pcVar2;
  int local_8;
  undefined4 local_4;
  
  local_4 = param_4;
  local_8 = param_3;
  pcVar2 = (code *)&local_8;
  iVar1 = iRam00022290 + 0x221f0;
  if (param_1 == 6) {
LAB_00022242:
    if (*(int *)(pcVar2 + 4) == 0) {
      return;
    }
    pcVar2 = *(code **)(**(int **)(iVar1 + iRam00022294) + 0x14);
    (*pcVar2)(2,DAT_0002229c + 0x2225e,param_2,local_8);
    iVar1 = extraout_r1_01;
  }
  else {
    if (6 < param_1) {
      if (param_1 != 7) {
        if (param_1 == 8) {
          if (param_3 == 0) {
            return;
          }
          goto LAB_0002227e;
        }
        goto LAB_00022218;
      }
LAB_00022226:
      pcVar2 = *(code **)(**(int **)(iVar1 + iRam00022294) + 0x14);
      (*pcVar2)(2,DAT_00022298 + 0x22240,param_2,local_8,local_4);
      iVar1 = extraout_r1_00;
      param_2 = extraout_r2_00;
      goto LAB_00022242;
    }
    if (param_1 != 5) {
LAB_00022218:
      (**(code **)(**(int **)(iVar1 + iRam00022294) + 0x14))(param_1,param_2,pcVar2);
      iVar1 = extraout_r1;
      param_2 = extraout_r2;
      goto LAB_00022226;
    }
  }
  if (*(int *)(pcVar2 + 4) == 0) {
    return;
  }
  (**(code **)(**(int **)(iVar1 + iRam00022294) + 0x14))(2,DAT_000222a0 + 0x2227c);
  iVar1 = extraout_r1_02;
LAB_0002227e:
  (**(code **)(**(int **)(iVar1 + iRam00022294) + 0x14))(2,DAT_000222a4 + 0x2228c);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: FUN_000222a8 @ 000222a8 */

undefined4 FUN_000222a8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = DAT_000222e4 + 0x222b0;
  if (param_1 == 0) {
    fprintf((FILE *)(*(int *)(iVar2 + DAT_000222f0) + 0xa8),(char *)(DAT_000222f8 + 0x222d8),
            DAT_000222f4 + 0x2231e);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    **(int **)(iVar2 + DAT_000222e8) = param_1;
    if (*(int *)(param_1 + 0x14) == 0) {
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar2 + DAT_000222ec);
    }
  }
  return uVar1;
}



/* Function: FUN_000222fc @ 000222fc */

void FUN_000222fc(int param_1)

{
  if (param_1 == 2) {
    *(int *)((int)&DAT_0002234c + DAT_0002234c) = DAT_00022350 + 0x2232a;
  }
  else if (param_1 == 10) {
    *(int *)((int)&DAT_00022358 + DAT_00022358 + 2) = (int)&DAT_00022348 + DAT_00022354;
  }
  else {
    fprintf((FILE *)(*(int *)(DAT_0002233c + 0x22304 + DAT_00022340) + 0xa8),
            (char *)(DAT_00022348 + 0x22318),DAT_00022344 + 0x22372);
  }
  return;
}



/* Function: FUN_0002235c @ 0002235c */

void * FUN_0002235c(char *param_1,char *param_2,void *param_3)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  void *pvVar4;
  servent *psVar5;
  uint __n;
  char *pcVar6;
  size_t __n_00;
  ushort *extraout_r12;
  
  sVar3 = strlen(param_1);
  iVar2 = iRam00022430;
  memset(param_3,0,0x10);
  memset(param_2,0,0x10);
  __n = sVar3 + 1;
  if (0x10 < __n) {
    pcVar6 = (char *)(**(code **)(**(int **)(iVar2 + 0x2238c + iRam0002243c) + 0x14))
                               (2,iRam00022440 + 0x22428,param_1,0xf);
    psVar5 = getservbyname((char *)(uint)*extraout_r12,pcVar6);
    if (psVar5 == (servent *)0x0) {
      pvVar4 = (void *)0xffffffff;
    }
    else {
      pvVar4 = (void *)((psVar5->s_port & 0xffU) << 8 | (psVar5->s_port & 0xffffU) >> 8);
    }
    return pvVar4;
  }
  strcpy(param_2,param_1);
  if (sVar3 == 0) {
    pvVar4 = memset(param_3,0,0x10);
  }
  else {
    __n_00 = sVar3 - 1;
    if (param_2[__n_00] == '+') {
      memset(param_3,0xff,__n_00);
      pvVar4 = memset((void *)((int)param_3 + __n_00),0,0x11 - sVar3);
    }
    else {
      memset(param_3,0xff,__n);
      pvVar4 = memset((void *)((int)param_3 + __n),0,0xf - sVar3);
      cVar1 = *param_2;
      if (cVar1 != '\0') {
        if ((cVar1 != '/') && (pcVar6 = param_2, cVar1 != ' ')) {
          do {
            pcVar6 = pcVar6 + 1;
            cVar1 = *pcVar6;
            if (cVar1 == '\0') {
              return pvVar4;
            }
          } while ((cVar1 != ' ') && (cVar1 != '/'));
        }
        pvVar4 = (void *)fprintf((FILE *)(*(int *)(iVar2 + 0x2238c + iRam00022434) + 0xa8),
                                 (char *)(iRam00022438 + 0x223ea),param_2);
      }
    }
  }
  return pvVar4;
}



/* Function: FUN_00022444 @ 00022444 */

uint FUN_00022444(char *param_1,char *param_2)

{
  servent *psVar1;
  uint uVar2;
  
  psVar1 = getservbyname(param_1,param_2);
  if (psVar1 == (servent *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (psVar1->s_port & 0xffU) << 8 | (psVar1->s_port & 0xffffU) >> 8;
  }
  return uVar2;
}



/* Function: FUN_00022464 @ 00022464 */

bool FUN_00022464(char *param_1,undefined4 *param_2,ulong *param_3,uint param_4,uint param_5)

{
  undefined4 *puVar1;
  ulong uVar2;
  int *piVar3;
  char *local_1c;
  
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0;
  uVar2 = strtoul(param_1,&local_1c,0);
  if (local_1c != param_1) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = local_1c;
    }
    piVar3 = (int *)__errno();
    if (((*piVar3 != 0x22) && (param_4 <= uVar2)) && ((uVar2 <= param_5 || (param_5 == 0)))) {
      if (param_3 != (ulong *)0x0) {
        *param_3 = uVar2;
      }
      if (param_2 != (undefined4 *)0x0) {
        return true;
      }
      return *local_1c == '\0';
    }
  }
  return false;
}



/* Function: FUN_000224cc @ 000224cc */

void FUN_000224cc(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_c;
  
  FUN_00022464(param_1,param_2,&local_c,param_4,param_5);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_c;
  }
  return;
}



/* Function: FUN_000224e8 @ 000224e8 */

uint FUN_000224e8(char *param_1)

{
  int iVar1;
  protoent *ppVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint local_1c;
  
  iVar4 = DAT_0002257c + 0x22500;
  iVar1 = FUN_000224cc(param_1,0,&local_1c,0,0xff);
  if (iVar1 == 0) {
    iVar1 = strcmp(param_1,(char *)(DAT_00022580 + 0x22510));
    if (iVar1 == 0) {
      return 0;
    }
    ppVar2 = getprotobyname(param_1);
    iVar1 = DAT_00022584;
    if (ppVar2 == (protoent *)0x0) {
      iVar6 = 0;
      puVar5 = *(undefined4 **)(iVar4 + DAT_00022584);
      do {
        if (((char *)*puVar5 != (char *)0x0) &&
           (iVar3 = strcmp(param_1,(char *)*puVar5), iVar3 == 0)) goto LAB_0002256a;
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 2;
      } while (iVar6 != 0xd);
      do {
        (**(code **)(**(int **)(iVar4 + DAT_00022588) + 0x14))(2,DAT_0002258c + 0x22564,param_1);
LAB_0002256a:
        local_1c = (uint)*(byte *)(*(int *)(iVar4 + iVar1) + iVar6 * 8 + 4);
      } while (iVar6 == 0xd);
    }
    else {
      local_1c = ppVar2->p_proto;
    }
  }
  return local_1c & 0xffff;
}



/* Function: FUN_00022590 @ 00022590 */

/* WARNING: Control flow encountered bad instruction data */

void * FUN_00022590(int param_1)

{
  int iVar1;
  void *__s;
  int iVar2;
  uint local_14;
  
  if (param_1 == 0) {
    __s = (void *)(iRam00022630 + 0x225da);
    memset(__s,0xff,0x10);
  }
  else {
    __s = (void *)FUN_00021f44(param_1);
    if (__s == (void *)0x0) {
      iVar2 = FUN_000224cc(param_1,0,&local_14,0,0x80);
      iVar1 = iRam00022634;
      if (iVar2 == 0) {
        (**(code **)(**(int **)(iRam0002263c + 0x22626) + 0x14))(2,DAT_00022640 + 0x2262a,param_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (local_14 == 0) {
        *(undefined4 *)(iRam00022634 + 0x22602) = 0;
        *(undefined4 *)(iVar1 + 0x22606) = 0;
        *(undefined4 *)(iVar1 + 0x2260a) = 0;
        *(undefined4 *)(iVar1 + 0x2260e) = 0;
        __s = (void *)(iVar1 + 0x22602);
      }
      else {
        __s = (void *)(iRam00022638 + 0x22618);
        memset(__s,0xff,local_14 >> 3);
        memset((void *)((int)__s + (local_14 >> 3) + 1),0,0x80 - local_14 >> 3);
        *(char *)((int)__s + (local_14 >> 3)) = (char)(0xff << (8 - (local_14 & 7) & 0xff));
      }
    }
  }
  return __s;
}



/* Function: FUN_00022644 @ 00022644 */

void FUN_00022644(char *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  char *__dest;
  int iVar9;
  undefined1 local_44 [4];
  char acStack_40 [19];
  undefined1 local_2d;
  int local_2c;
  
  iVar1 = DAT_00022754;
  iVar9 = DAT_00022750 + 0x2265c;
  __dest = acStack_40;
  local_2c = **(int **)(iVar9 + DAT_00022754);
  strncpy(__dest,param_1,0x13);
  iVar8 = DAT_00022758;
  local_2d = 0;
  puVar5 = (undefined1 *)(DAT_00022758 + 0x226b6);
  puVar6 = (undefined1 *)(DAT_00022758 + 0x226b9);
  puVar7 = puVar5;
  do {
    pcVar2 = strchr(__dest,0x2e);
    if (pcVar2 == (char *)0x0) {
      iVar8 = (int)puVar7 - (int)puVar5;
      if ((param_2 == 0) && (iVar3 = FUN_000224cc(__dest,0,local_44,0,0xff), iVar3 != 0)) {
        puVar5[iVar8] = local_44[0];
        if (iVar8 < 3) {
          puVar7 = (undefined1 *)(DAT_00022760 + 0x2276e + iVar8);
          do {
            puVar7[1] = 0;
            puVar7 = puVar7 + 1;
          } while (puVar7 != puVar6);
        }
        pcVar4 = FUN_00022780 + DAT_00022764;
        goto LAB_000226e6;
      }
      goto LAB_00022702;
    }
    *pcVar2 = '\0';
    iVar3 = FUN_000224cc(__dest,0,local_44,0,0xff);
    if (iVar3 == 0) goto LAB_00022702;
    __dest = pcVar2 + 1;
    *puVar7 = local_44[0];
    puVar7 = puVar7 + 1;
  } while (puVar7 != puVar6);
  iVar3 = FUN_000224cc(__dest,0,local_44,0,0xff);
  if (iVar3 == 0) {
LAB_00022702:
    pcVar4 = (code *)0x0;
  }
  else {
    pcVar4 = (code *)(DAT_0002275c + 0x2271c);
    *(undefined1 *)(iVar8 + 0x226b9) = local_44[0];
  }
LAB_000226e6:
  if (local_2c != **(int **)(iVar9 + iVar1)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pcVar4);
  }
  return;
}



/* Function: FUN_00022768 @ 00022768 */

void FUN_00022768(undefined4 param_1)

{
  FUN_00022644(param_1,1);
  return;
}



/* Function: FUN_00022774 @ 00022774 */

void FUN_00022774(undefined4 param_1)

{
  FUN_00022644(param_1,0);
  return;
}



/* Function: FUN_00022780 @ 00022780 */

/* WARNING: Control flow encountered bad instruction data */

int FUN_00022780(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  
  iVar2 = iRam00022814;
  if (param_1 == 0) {
    *(undefined4 *)(iRam00022814 + 0x227de) = 0xffffffff;
    iVar2 = iVar2 + 0x227de;
  }
  else {
    iVar2 = FUN_00022768(param_1);
    if (iVar2 == 0) {
      iVar3 = FUN_000224cc(param_1,0,&local_14,0,0x20);
      iVar1 = iRam0002281c;
      iVar2 = iRam00022818;
      if (iVar3 == 0) {
        (**(code **)(**(int **)(iRam00022820 + 0x22808) + 0x14))(2,DAT_00022824 + 0x2280c,param_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (local_14 == 0) {
        *(undefined4 *)(iRam00022818 + 0x22802) = 0;
        iVar2 = iVar2 + 0x22802;
      }
      else {
        uVar4 = -1 << (0x20U - local_14 & 0xff);
        *(uint *)(iRam0002281c + 0x22834) =
             uVar4 >> 0x18 | uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | (uVar4 & 0xff0000) >> 8;
        iVar2 = iVar1 + 0x22834;
      }
    }
  }
  return iVar2;
}



/* Function: FUN_00022828 @ 00022828 */

/* WARNING: Control flow encountered bad instruction data */

uint FUN_00022828(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint local_14 [2];
  
  iVar1 = FUN_000224cc(param_1,0,local_14,0,DAT_00022870);
  if ((iVar1 == 0) && (local_14[0] = FUN_00022444(param_1,param_2), local_14[0] == 0xffffffff)) {
    (**(code **)(**(int **)(DAT_00022874 + 0x22864) + 0x14))(2,DAT_00022878 + 0x22868,param_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return local_14[0] & 0xffff;
}



/* Function: FUN_0002287c @ 0002287c */

int * FUN_0002287c(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  size_t __n;
  int iVar9;
  
  piVar1 = param_1;
  if (param_2 != (int *)0x0) {
    iVar6 = 0;
    __n = 0;
    iVar2 = *param_1;
    while (iVar2 != 0) {
      iVar6 = iVar6 + 1;
      __n = iVar6 * 0x10;
      iVar2 = param_1[iVar6 * 4];
    }
    iVar2 = 0;
    iVar3 = *param_2;
    while (iVar3 != 0) {
      iVar2 = iVar2 + 1;
      iVar3 = param_2[iVar2 * 4];
    }
    puVar4 = *(undefined4 **)(DAT_0002294c + 0x228ce);
    piVar1 = (int *)*puVar4;
    *piVar1 = *piVar1 + 0x100;
    *param_3 = *(int *)*puVar4;
    piVar1 = malloc((iVar2 + iVar6 + 1) * 0x10);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      memcpy(piVar1,param_1,__n);
      FUN_00021f14(0);
      if (iVar2 != 0) {
        iVar3 = *param_3;
        piVar7 = piVar1 + iVar6 * 4;
        iVar9 = 0;
        do {
          iVar5 = param_2[1];
          iVar8 = param_2[2];
          *piVar7 = *param_2;
          piVar7[1] = iVar5;
          piVar7[2] = iVar8;
          iVar9 = iVar9 + 1;
          piVar7[3] = param_2[3] + iVar3;
          param_2 = param_2 + 4;
          piVar7 = piVar7 + 4;
        } while (iVar9 != iVar2);
      }
      piVar7 = piVar1 + (iVar2 + iVar6) * 4;
      *piVar7 = 0;
      piVar7[1] = 0;
      piVar7[2] = 0;
      piVar7[3] = 0;
    }
  }
  return piVar1;
}



/* Function: FUN_00022950 @ 00022950 */

undefined4 FUN_00022950(undefined4 param_1,char *param_2,int param_3)

{
  __pid_t _Var1;
  int __fd;
  ssize_t sVar2;
  size_t sVar3;
  int iVar4;
  char *local_40;
  char *local_38;
  char *local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  uint local_1c [2];
  
  iVar4 = DAT_00022a3c + 0x2295e;
  local_38 = (char *)0x0;
  local_40 = param_2;
  if (param_2 != (char *)0x0) {
LAB_00022966:
    fflush((FILE *)(*(int *)(iVar4 + DAT_00022a40) + 0x54));
    _Var1 = vfork();
    if (_Var1 != -1) {
      if (_Var1 == 0) {
        local_2c = local_40;
        if (param_3 == 0) {
          local_24 = 0;
        }
        else {
          local_24 = DAT_00022a44 + 0x229ce;
        }
        local_20 = 0;
        local_28 = param_1;
        execv(local_40,&local_2c);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      wait(local_1c);
      free(local_38);
      if (((local_1c[0] & 0x7f) == 0) && ((local_1c[0] & 0xffff) >> 8 == 0)) {
        return 0;
      }
    }
    return 0xffffffff;
  }
  __fd = open((char *)(DAT_00022a48 + 0x229d6),0);
  if (__fd < 0) {
    return 0xffffffff;
  }
  local_40 = malloc(0x400);
  if (local_40 != (char *)0x0) {
    memset(local_40,0,0x400);
    sVar2 = read(__fd,local_40,0x400);
    if ((sVar2 != -1) && (sVar2 != 0x400)) {
      sVar3 = strlen(local_40);
      if (local_40[sVar3 - 1] == '\n') {
        local_40[sVar3 - 1] = '\0';
      }
      close(__fd);
      local_38 = local_40;
      goto LAB_00022966;
    }
  }
  free(local_40);
  close(__fd);
  return 0xffffffff;
}



/* Function: FUN_00022a4c @ 00022a4c */

int FUN_00022a4c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00022a80;
  if (*(char *)(DAT_00022a80 + 0x22a98) == '\0') {
    iVar2 = FUN_00022950(**(undefined4 **)(DAT_00022a80 + 0x22a7c),param_1,param_2);
    *(int *)(DAT_00022a88 + 0x22a76) = iVar2;
    *(bool *)(iVar1 + 0x22a98) = iVar2 == 0;
  }
  else {
    iVar2 = *(int *)(DAT_00022a84 + 0x22a64);
  }
  return iVar2;
}



/* Function: FUN_00022a8c @ 00022a8c */

void FUN_00022a8c(char *param_1,int param_2,int param_3)

{
  int iVar1;
  int __fd;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  bool bVar6;
  socklen_t local_50;
  char acStack_4c [29];
  undefined1 local_2f;
  int local_2c;
  
  iVar2 = DAT_00022bc0;
  iVar1 = DAT_00022bbc;
  iVar5 = DAT_00022bb8 + 0x22aa2;
  local_2c = **(int **)(iVar5 + DAT_00022bbc);
  local_50 = 0x1e;
  __fd = socket((uint)*(byte *)(*(int *)(DAT_00022bc0 + 0x22acc) + 8),3,0xff);
  if (__fd < 0) {
    piVar3 = (int *)__errno();
    if (*piVar3 != 1) {
      piVar3 = (int *)__errno();
      pcVar4 = strerror(*piVar3);
      fprintf((FILE *)(*(int *)(iVar5 + DAT_00022bc8) + 0xa8),(char *)(DAT_00022bd0 + 0x22b8c),
              pcVar4);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    bVar6 = true;
    if (param_2 != 0) {
      fprintf((FILE *)(*(int *)(iVar5 + DAT_00022bc8) + 0xa8),(char *)(DAT_00022bcc + 0x22b34));
      bVar6 = true;
    }
  }
  else {
    FUN_00022a4c(**(undefined4 **)(iVar5 + DAT_00022bc4),1);
    strcpy(acStack_4c,param_1);
    local_2f = (undefined1)param_2;
    iVar2 = getsockopt(__fd,(uint)*(byte *)(*(int *)(iVar2 + 0x22acc) + 9),param_3,acStack_4c,
                       &local_50);
    if (iVar2 < 0) {
      piVar3 = (int *)__errno();
      if (*piVar3 != 2) {
        piVar3 = (int *)__errno();
        if (*piVar3 != 0x5d) {
          piVar3 = (int *)__errno();
          if (*piVar3 != 0x5c) {
            piVar3 = (int *)__errno();
            pcVar4 = strerror(*piVar3);
            fprintf((FILE *)(*(int *)(iVar5 + DAT_00022bc8) + 0xa8),(char *)(DAT_00022bd4 + 0x22bac)
                    ,pcVar4);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
          close(__fd);
          bVar6 = param_2 == 0;
          goto LAB_00022b00;
        }
      }
      close(__fd);
      bVar6 = false;
    }
    else {
      close(__fd);
      bVar6 = true;
    }
  }
LAB_00022b00:
  if (local_2c == **(int **)(iVar5 + iVar1)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(bVar6);
}



/* Function: FUN_00022bd8 @ 00022bd8 */

void FUN_00022bd8(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  byte bVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  char *pcVar10;
  
  pcVar10 = (char *)*param_1;
  iVar7 = DAT_00022d60 + 0x22be4;
  if (pcVar10 == (char *)0x0) {
    fprintf((FILE *)(*(int *)(iVar7 + DAT_00022d80) + 0xa8),(char *)(DAT_00022d88 + 0x22ce4),
            *(undefined4 *)(**(int **)(iVar7 + DAT_00022d7c) + 4),param_1[2],
            (uint)*(byte *)(param_1 + 3));
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  pcVar8 = (char *)(DAT_00022d64 + 0x22bf2);
  iVar2 = strcmp(pcVar10,pcVar8);
  if (iVar2 != 0) {
    fprintf((FILE *)(*(int *)(iVar7 + DAT_00022d80) + 0xa8),(char *)(DAT_00022d84 + 0x22cc2),
            *(undefined4 *)(**(int **)(iVar7 + DAT_00022d7c) + 4),param_1[2],pcVar10,pcVar8);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  pcVar10 = (char *)param_1[2];
  sVar3 = strlen(pcVar10);
  if (sVar3 < 0x1d) {
    uVar1 = *(ushort *)((int)param_1 + 0xe);
    if (uVar1 < 0xff) {
      if ((*(byte *)(*(int *)(DAT_00022d68 + 0x22c3a) + 8) == uVar1) || (uVar1 == 0)) {
        iVar2 = FUN_00021d00(pcVar10,1);
        if (iVar2 != 0) {
          if ((*(uint *)(iVar2 + 0xc) & DAT_00022d6c) == (DAT_00022d6c & param_1[3])) {
            fprintf((FILE *)(*(int *)(iVar7 + DAT_00022d80) + 0xa8),(char *)(DAT_00022d94 + 0x22d30)
                    ,*(undefined4 *)(**(int **)(iVar7 + DAT_00022d7c) + 4),param_1[2]);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
          iVar4 = FUN_00022a8c(*(undefined4 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 0xc),
                               *(undefined4 *)(*(int *)(DAT_00022d70 + 0x22c6a) + 0x10));
          if (iVar4 == 0) {
            bVar5 = *(byte *)(param_1 + 3);
          }
          else {
            bVar5 = *(byte *)(param_1 + 3);
            if (bVar5 < *(byte *)(iVar2 + 0xc)) {
              return;
            }
          }
          iVar4 = FUN_00022a8c(param_1[2],bVar5,
                               *(undefined4 *)(*(int *)(DAT_00022d74 + 0x22c84) + 0x10));
          if (iVar4 == 0) {
            return;
          }
          if ((*(char *)(iVar2 + 0xc) == *(char *)(param_1 + 3)) &&
             (*(short *)((int)param_1 + 0xe) == 0)) {
            return;
          }
          piVar6 = *(int **)(iVar7 + DAT_00022d78);
          for (iVar4 = *piVar6; iVar2 != iVar4; iVar4 = *(int *)(iVar4 + 4)) {
            piVar6 = (int *)(iVar4 + 4);
          }
          *piVar6 = *(int *)(iVar2 + 4);
        }
        uVar9 = param_1[4];
        if (uVar9 != (uVar9 + 7 & 0xfffffff8)) {
          fprintf((FILE *)(*(int *)(iVar7 + DAT_00022d80) + 0xa8),(char *)(DAT_00022d98 + 0x22d4e),
                  *(undefined4 *)(**(int **)(iVar7 + DAT_00022d7c) + 4),param_1[2],uVar9);
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        piVar6 = *(int **)(iVar7 + DAT_00022d78);
        param_1[1] = *piVar6;
        *piVar6 = (int)param_1;
        param_1[0xe] = 0;
        param_1[0xf] = 0;
      }
      return;
    }
    iVar2 = *(int *)(iVar7 + DAT_00022d80);
    pcVar8 = (char *)(DAT_00022d8c + 0x22d02);
  }
  else {
    iVar2 = *(int *)(iVar7 + DAT_00022d80);
    pcVar8 = (char *)(DAT_00022d90 + 0x22d20);
  }
  fprintf((FILE *)(iVar2 + 0xa8),pcVar8,*(undefined4 *)(**(int **)(iVar7 + DAT_00022d7c) + 4),
          pcVar10);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



/* Function: FUN_00022d9c @ 00022d9c */

void FUN_00022d9c(int param_1,int param_2)

{
  param_1 = param_1 + param_2 * 0x48 + -0x48;
  do {
    param_2 = param_2 + -1;
    FUN_00022bd8(param_1);
    param_1 = param_1 + -0x48;
  } while (param_2 != 0);
  return;
}



/* Function: FUN_00022dbc @ 00022dbc */

void FUN_00022dbc(void *param_1,size_t param_2)

{
  void *pvVar1;
  
  pvVar1 = realloc(param_1,param_2);
  if (pvVar1 != (void *)0x0) {
    return;
  }
  perror((char *)(DAT_00022dd8 + 0x22dce));
                    /* WARNING: Subroutine does not return */
  exit(1);
}



/* Function: FUN_00022ddc @ 00022ddc */

void FUN_00022ddc(size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 != (void *)0x0) {
    return;
  }
  perror((char *)(DAT_00022df8 + 0x22dee));
                    /* WARNING: Subroutine does not return */
  exit(1);
}



/* Function: FUN_00022dfc @ 00022dfc */

void FUN_00022dfc(char *param_1,undefined4 *param_2)

{
  addrinfo *paVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  addrinfo local_3c;
  addrinfo *local_1c [2];
  
  paVar1 = (addrinfo *)FUN_00021f44();
  if (paVar1 == (addrinfo *)0x0) {
    local_3c.ai_flags = 2;
    local_3c.ai_family = 10;
    local_3c.ai_socktype = 3;
    local_3c.ai_protocol = 0x29;
    *param_2 = 0;
    local_3c.ai_addrlen = (socklen_t)paVar1;
    local_3c.ai_addr = (sockaddr *)paVar1;
    local_3c.ai_canonname = (char *)paVar1;
    local_3c.ai_next = paVar1;
    iVar4 = getaddrinfo(param_1,(char *)0x0,&local_3c,local_1c);
    if (iVar4 == 0) goto LAB_00022e62;
    do {
      do {
        (**(code **)(**(int **)(DAT_00022ea0 + 0x22e58) + 0x14))(2,DAT_00022ea4 + 0x22e5c,param_1);
LAB_00022e62:
      } while ((local_1c[0]->ai_family != 10) || (local_1c[0]->ai_addrlen != 0x1c));
      puVar2 = (undefined4 *)FUN_00022ddc(0x10);
      iVar4 = DAT_00022ea8;
      *(undefined4 **)(DAT_00022ea8 + 0x22ec4) = puVar2;
      pcVar5 = local_1c[0]->ai_canonname;
      uVar3 = *(undefined4 *)(pcVar5 + 0xc);
      uVar7 = *(undefined4 *)(pcVar5 + 0x10);
      *puVar2 = *(undefined4 *)(pcVar5 + 8);
      puVar2[1] = uVar3;
      puVar2[2] = uVar7;
      puVar2[3] = *(undefined4 *)(pcVar5 + 0x14);
      freeaddrinfo(local_1c[0]);
      *param_2 = 1;
    } while (*(int *)(iVar4 + 0x22ec4) == 0);
  }
  else {
    puVar2 = (undefined4 *)FUN_00022ddc(0x10);
    iVar4 = paVar1->ai_family;
    iVar6 = paVar1->ai_socktype;
    *puVar2 = paVar1->ai_flags;
    puVar2[1] = iVar4;
    puVar2[2] = iVar6;
    puVar2[3] = paVar1->ai_protocol;
    *param_2 = 1;
  }
  return;
}



/* Function: FUN_00022eac @ 00022eac */

void FUN_00022eac(char *param_1,int *param_2,uint *param_3,int *param_4)

{
  int iVar1;
  char *pcVar2;
  uint *puVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  void *__s1;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint *__s2;
  int iVar14;
  undefined2 local_12c;
  undefined1 local_12a;
  undefined1 uStack_2d;
  int local_2c;
  
  iVar1 = DAT_00022fb8;
  iVar10 = DAT_00022fb4 + 0x22ec2;
  local_2c = **(int **)(iVar10 + DAT_00022fb8);
  strncpy((char *)&local_12c,param_1,0xff);
  uStack_2d = 0;
  pcVar2 = strrchr((char *)&local_12c,0x2f);
  if (pcVar2 == (char *)0x0) {
    puVar3 = (uint *)FUN_00022590(0);
  }
  else {
    *pcVar2 = '\0';
    puVar3 = (uint *)FUN_00022590(pcVar2 + 1);
  }
  uVar7 = puVar3[1];
  uVar11 = puVar3[2];
  *param_3 = *puVar3;
  param_3[1] = uVar7;
  param_3[2] = uVar11;
  iVar4 = DAT_00022fbc;
  param_3[3] = puVar3[3];
  iVar4 = memcmp(param_3,(void *)(iVar4 + 0x22f4e),0x10);
  if (iVar4 == 0) {
    local_12a = 0;
    local_12c = (undefined2)DAT_00022fc0;
  }
  pvVar5 = (void *)FUN_00022dfc(&local_12c,param_4);
  *param_2 = (int)pvVar5;
  iVar4 = *param_4;
  if (iVar4 != 0) {
    iVar13 = 0;
    iVar14 = 0;
    do {
      __s2 = (uint *)(iVar13 * 0x10 + (int)pvVar5);
      iVar9 = 0;
      puVar3 = param_3;
      puVar8 = __s2;
      do {
        uVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        iVar9 = iVar9 + 1;
        *puVar8 = uVar7 & *puVar8;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 4);
      iVar9 = iVar13 + 1;
      if (iVar13 != 0) {
        iVar12 = 0;
        __s1 = pvVar5;
        do {
          iVar6 = memcmp(__s1,__s2,0x10);
          if (iVar6 == 0) {
            *param_4 = *param_4 + -1;
            iVar9 = iVar13;
            break;
          }
          iVar12 = iVar12 + 1;
          __s1 = (void *)((int)__s1 + 0x10);
        } while (iVar12 != iVar13);
      }
      iVar13 = iVar9;
      iVar14 = iVar14 + 1;
    } while (iVar14 != iVar4);
  }
  if (local_2c != **(int **)(iVar10 + iVar1)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_00022fc4 @ 00022fc4 */

/* WARNING: Control flow encountered bad instruction data */

void * FUN_00022fc4(char *param_1,int param_2,int *param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  void *__src;
  void *__dest;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_s1;
  undefined8 unaff_d12;
  
  iVar4 = iRam000230e8 + 0x22fd6;
  sVar1 = strlen(param_1);
  if (0x1c < sVar1) {
    uVar5 = (**(code **)(**(int **)(iVar4 + iRam00023100) + 0x14))
                      (2,DAT_00023108 + 0x230e0,param_1,0x1c);
    VectorAdd(unaff_d12,CONCAT44(extraout_s1,uVar5),1,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar2 = strcmp(param_1,(char *)(iRam000230ec + 0x22fe8));
  if (((iVar2 == 0) || (iVar2 = strcmp(param_1,(char *)(iRam000230f0 + 0x22ff6)), iVar2 == 0)) ||
     (iVar2 = strcmp(param_1,(char *)(iRam000230fc + 0x2305c)), iVar2 == 0)) {
    param_1 = (char *)(iRam000230f4 + 0x23002);
  }
  __src = (void *)**(undefined4 **)(iVar4 + iRam000230f8);
  do {
    if (__src == (void *)0x0) {
      __dest = (void *)0x0;
      if (param_2 == 3) {
        (**(code **)(**(int **)(iVar4 + iRam00023100) + 0x14))(2,DAT_00023104 + 0x230b8,param_1);
LAB_000230be:
        if (param_2 == 0) {
          __dest = (void *)0x0;
        }
        else {
          *(undefined4 *)((int)__dest + 0x40) = 1;
LAB_00023046:
          if (param_3 != (int *)0x0) {
            puVar3 = (undefined4 *)FUN_00022ddc(0xc);
            iVar4 = *param_3;
            while (iVar4 != 0) {
              iVar2 = strcmp(param_1,*(char **)(*(int *)(iVar4 + 4) + 8));
              if (iVar2 == 0) {
                *(undefined1 *)(iVar4 + 8) = 1;
              }
              param_3 = (int *)*param_3;
              iVar4 = *param_3;
            }
            puVar3[1] = __dest;
            *(undefined1 *)(puVar3 + 2) = 0;
            *puVar3 = 0;
            *param_3 = (int)puVar3;
          }
        }
      }
      return __dest;
    }
    iVar2 = strcmp(param_1,*(char **)((int)__src + 8));
    if (iVar2 == 0) {
      __dest = __src;
      if (*(int *)((int)__src + 0x38) != 0) {
        __dest = (void *)FUN_00022ddc(0x44);
        memcpy(__dest,__src,0x44);
        *(undefined4 *)((int)__dest + 0x3c) = 0;
        *(void **)((int)__dest + 4) = __dest;
      }
      if (*(int *)((int)__dest + 0x40) == 0) goto LAB_000230be;
      goto LAB_00023046;
    }
    __src = *(void **)((int)__src + 4);
  } while( true );
}



/* Function: FUN_0002310c @ 0002310c */

void FUN_0002310c(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  byte bVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  char *pcVar10;
  
  pcVar10 = (char *)*param_1;
  iVar7 = DAT_000232a8 + 0x23118;
  if (pcVar10 == (char *)0x0) {
    fprintf((FILE *)(*(int *)(iVar7 + DAT_000232c8) + 0xa8),(char *)(DAT_000232d0 + 0x2322a),
            *(undefined4 *)(**(int **)(iVar7 + DAT_000232c4) + 4),param_1[2],
            (uint)*(byte *)(param_1 + 3));
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  pcVar8 = (char *)(DAT_000232ac + 0x23126);
  iVar2 = strcmp(pcVar10,pcVar8);
  if (iVar2 != 0) {
    fprintf((FILE *)(*(int *)(iVar7 + DAT_000232c8) + 0xa8),(char *)(DAT_000232cc + 0x23208),
            *(undefined4 *)(**(int **)(iVar7 + DAT_000232c4) + 4),param_1[2],pcVar10,pcVar8);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  pcVar10 = (char *)param_1[2];
  sVar3 = strlen(pcVar10);
  if (sVar3 < 0x1d) {
    uVar1 = *(ushort *)((int)param_1 + 0xe);
    if (uVar1 < 0xff) {
      if ((*(byte *)(*(int *)(DAT_000232b0 + 0x23170) + 8) == uVar1) || (uVar1 == 0)) {
        iVar2 = FUN_00022fc4(pcVar10,1,0);
        if (iVar2 != 0) {
          if ((*(uint *)(iVar2 + 0xc) & DAT_000232b4) == (DAT_000232b4 & param_1[3])) {
            fprintf((FILE *)(*(int *)(iVar7 + DAT_000232c8) + 0xa8),(char *)(DAT_000232d4 + 0x2324c)
                    ,*(undefined4 *)(**(int **)(iVar7 + DAT_000232c4) + 4),param_1[2]);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
          iVar4 = FUN_00022a8c(*(undefined4 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 0xc),
                               *(undefined4 *)(*(int *)(DAT_000232b8 + 0x231a2) + 0xc));
          if (iVar4 == 0) {
            bVar5 = *(byte *)(param_1 + 3);
          }
          else {
            bVar5 = *(byte *)(param_1 + 3);
            if (bVar5 < *(byte *)(iVar2 + 0xc)) {
              return;
            }
          }
          iVar4 = FUN_00022a8c(param_1[2],bVar5,
                               *(undefined4 *)(*(int *)(DAT_000232bc + 0x231bc) + 0xc));
          if (iVar4 == 0) {
            return;
          }
          if ((*(char *)(iVar2 + 0xc) == *(char *)(param_1 + 3)) &&
             (*(short *)((int)param_1 + 0xe) == 0)) {
            return;
          }
          piVar6 = *(int **)(iVar7 + DAT_000232c0);
          for (iVar4 = *piVar6; iVar2 != iVar4; iVar4 = *(int *)(iVar4 + 4)) {
            piVar6 = (int *)(iVar4 + 4);
          }
          *piVar6 = *(int *)(iVar2 + 4);
        }
        uVar9 = param_1[4];
        if (uVar9 != (uVar9 + 7 & 0xfffffff8)) {
          fprintf((FILE *)(*(int *)(iVar7 + DAT_000232c8) + 0xa8),(char *)(DAT_000232e0 + 0x23294),
                  *(undefined4 *)(**(int **)(iVar7 + DAT_000232c4) + 4),param_1[2],uVar9);
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        piVar6 = *(int **)(iVar7 + DAT_000232c0);
        for (iVar7 = *piVar6; iVar7 != 0; iVar7 = *(int *)(iVar7 + 4)) {
          piVar6 = (int *)(iVar7 + 4);
        }
        param_1[1] = 0;
        *piVar6 = (int)param_1;
        param_1[0xe] = 0;
        param_1[0xf] = 0;
      }
      return;
    }
    iVar2 = *(int *)(iVar7 + DAT_000232c8);
    pcVar8 = (char *)(DAT_000232d8 + 0x23266);
  }
  else {
    iVar2 = *(int *)(iVar7 + DAT_000232c8);
    pcVar8 = (char *)(DAT_000232dc + 0x23284);
  }
  fprintf((FILE *)(iVar2 + 0xa8),pcVar8,*(undefined4 *)(**(int **)(iVar7 + DAT_000232c4) + 4),
          pcVar10);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



/* Function: FUN_000232e4 @ 000232e4 */

void FUN_000232e4(int param_1,int param_2)

{
  param_1 = param_1 + param_2 * 0x44 + -0x44;
  do {
    param_2 = param_2 + -1;
    FUN_0002310c(param_1);
    param_1 = param_1 + -0x44;
  } while (param_2 != 0);
  return;
}



/* Function: FUN_00023304 @ 00023304 */

void FUN_00023304(size_t param_1,size_t param_2)

{
  void *pvVar1;
  
  pvVar1 = calloc(param_1,param_2);
  if (pvVar1 != (void *)0x0) {
    return;
  }
  perror((char *)(DAT_00023320 + 0x23316));
                    /* WARNING: Subroutine does not return */
  exit(1);
}



/* Function: FUN_00023324 @ 00023324 */

void FUN_00023324(char *param_1,uint *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  netent *pnVar4;
  hostent *phVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  puVar2 = (undefined4 *)FUN_00022774();
  if (puVar2 == (undefined4 *)0x0) {
    pnVar4 = getnetbyname(param_1);
    if ((pnVar4 == (netent *)0x0) || (pnVar4->n_addrtype != 2)) {
      *param_2 = 0;
      phVar5 = gethostbyname(param_1);
      if ((phVar5 != (hostent *)0x0) && ((phVar5->h_addrtype == 2 && (phVar5->h_length == 4)))) {
        if (phVar5->h_addr_list[*param_2] != (char *)0x0) {
          uVar7 = *param_2 + 1;
          iVar6 = uVar7 * 4;
          do {
            *param_2 = uVar7;
            uVar7 = uVar7 + 1;
            piVar1 = (int *)((int)phVar5->h_addr_list + iVar6);
            iVar6 = iVar6 + 4;
          } while (*piVar1 != 0);
        }
        iVar6 = FUN_00023304();
        if (*param_2 != 0) {
          iVar8 = 0;
          uVar7 = 0;
          do {
            memcpy((void *)(iVar6 + iVar8),*(void **)((int)phVar5->h_addr_list + iVar8),4);
            uVar7 = uVar7 + 1;
            iVar8 = iVar8 + 4;
          } while (uVar7 < *param_2);
        }
        if (iVar6 != 0) {
          return;
        }
      }
      pnVar4 = (netent *)
               (**(code **)(**(int **)(DAT_0002340c + 0x23376) + 0x14))
                         (2,DAT_00023410 + 0x2337a,param_1);
    }
    iVar6 = DAT_00023414;
    uVar7 = pnVar4->n_net;
    *(uint *)(&UNK_0002340a + DAT_00023414) =
         uVar7 >> 0x18 | uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | (uVar7 & 0xff0000) >> 8;
    puVar2 = (undefined4 *)(&UNK_0002340a + iVar6);
  }
  puVar3 = (undefined4 *)FUN_00022ddc(4);
  *puVar3 = *puVar2;
  *param_2 = 1;
  return;
}



/* Function: FUN_00023418 @ 00023418 */

void FUN_00023418(char *param_1,int *param_2,uint *param_3,int *param_4)

{
  int iVar1;
  char *pcVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 local_12c;
  undefined4 local_128;
  undefined1 uStack_2d;
  int local_2c;
  
  iVar1 = DAT_00023530;
  iVar10 = DAT_0002352c + 0x2342e;
  local_2c = **(int **)(iVar10 + DAT_00023530);
  strncpy((char *)&local_12c,param_1,0xff);
  uStack_2d = 0;
  pcVar2 = strrchr((char *)&local_12c,0x2f);
  if (pcVar2 == (char *)0x0) {
    puVar3 = (uint *)FUN_00022780(0);
  }
  else {
    *pcVar2 = '\0';
    puVar3 = (uint *)FUN_00022780(pcVar2 + 1);
  }
  uVar5 = *puVar3;
  *param_3 = uVar5;
  if (uVar5 == 0) {
    local_12c = DAT_00023534;
    local_128 = DAT_00023538;
  }
  puVar3 = (uint *)FUN_00023324(&local_12c,param_4);
  *param_2 = (int)puVar3;
  iVar6 = *param_4;
  if (iVar6 != 0) {
    *puVar3 = *param_3 & *puVar3;
    iVar8 = 1;
    iVar11 = 1;
    if (iVar6 != 1) {
      do {
        iVar9 = iVar11 + 1;
        uVar5 = *param_3 & puVar3[iVar11];
        puVar3[iVar11] = uVar5;
        if (iVar11 != 0) {
          if (uVar5 != *puVar3) {
            iVar7 = 0;
            puVar4 = puVar3;
            do {
              puVar4 = puVar4 + 1;
              iVar7 = iVar7 + 1;
              if (iVar7 == iVar11) goto LAB_000234e4;
            } while (uVar5 != *puVar4);
          }
          *param_4 = *param_4 + -1;
          iVar9 = iVar11;
        }
LAB_000234e4:
        iVar8 = iVar8 + 1;
        iVar11 = iVar9;
      } while (iVar8 != iVar6);
    }
  }
  if (local_2c != **(int **)(iVar10 + iVar1)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_0002353c @ 0002353c */

void FUN_0002353c(char *param_1,int *param_2,int *param_3,uint *param_4)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  uint *puVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  size_t local_150;
  uint local_148;
  void *local_144;
  uint local_130;
  undefined4 local_12c;
  undefined4 local_128;
  int local_2c;
  
  iVar1 = DAT_00023760;
  iVar9 = DAT_0002375c + 0x23552;
  local_2c = **(int **)(iVar9 + DAT_00023760);
  local_148 = 1;
  pcVar2 = param_1;
  while (pcVar2 = strchr(pcVar2,0x2c), pcVar2 != (char *)0x0) {
    local_148 = local_148 + 1;
    pcVar2 = pcVar2 + 1;
  }
  iVar3 = FUN_00022ddc(local_148 * 4);
  *param_2 = iVar3;
  iVar3 = FUN_00022ddc(local_148 * 4);
  *param_3 = iVar3;
  if ((local_148 != 0) && (param_1 != (char *)0x0)) {
    uVar8 = 0;
    while( true ) {
      cVar7 = *param_1;
      if (cVar7 == ',') {
        param_1 = param_1 + 1;
        cVar7 = *param_1;
      }
      if (cVar7 == '\0') break;
      pcVar2 = strchr(param_1,0x2c);
      local_150 = (int)pcVar2 - (int)param_1;
      if (pcVar2 == (char *)0x0) {
        local_150 = strlen(param_1);
      }
      if (0xfe < local_150 - 1) break;
      strncpy((char *)&local_12c,param_1,local_150);
      *(char *)((int)&local_12c + local_150) = '\0';
      pcVar2 = strrchr((char *)&local_12c,0x2f);
      if (pcVar2 == (char *)0x0) {
        pvVar5 = (void *)FUN_00022780(0);
      }
      else {
        *pcVar2 = '\0';
        pvVar5 = (void *)FUN_00022780(pcVar2 + 1);
      }
      iVar3 = uVar8 * 4;
      memcpy((void *)(*param_3 + iVar3),pvVar5,4);
      if (*(int *)(*param_3 + iVar3) == 0) {
        local_128 = DAT_00023764;
        local_12c = DAT_00023768;
        local_144 = (void *)FUN_00023324(&local_12c,&local_130);
        if (local_130 < 2) goto LAB_00023736;
LAB_00023638:
        local_148 = local_148 + (local_130 - 1);
        iVar4 = FUN_00022dbc(*param_2,local_148 * 4);
        *param_2 = iVar4;
        iVar4 = FUN_00022dbc(*param_3,local_148 * 4);
        *param_3 = iVar4;
        if (local_130 != 0) {
          uVar10 = 0;
          pvVar5 = local_144;
          iVar4 = iVar3;
          do {
            memcpy((void *)(*param_2 + iVar4),pvVar5,4);
            uVar10 = uVar10 + 1;
            iVar4 = iVar4 + 4;
            pvVar5 = (void *)((int)pvVar5 + 4);
          } while (uVar10 < local_130);
          if (1 < local_130) {
            iVar4 = (uVar8 + 1) * 4;
            uVar10 = 1;
            do {
              uVar10 = uVar10 + 1;
              memcpy((void *)(*param_3 + iVar4),(void *)(*param_3 + iVar3),4);
              iVar4 = iVar4 + 4;
            } while (uVar10 < local_130);
          }
        }
        uVar8 = (uVar8 - 1) + local_130;
      }
      else {
        local_144 = (void *)FUN_00023324(&local_12c,&local_130);
        if (1 < local_130) goto LAB_00023638;
LAB_00023736:
        memcpy((void *)(*param_2 + iVar3),local_144,4);
      }
      free(local_144);
      uVar8 = uVar8 + 1;
      if ((local_148 <= uVar8) || (param_1 = param_1 + local_150, param_1 == (char *)0x0)) break;
    }
  }
  *param_4 = local_148;
  if (local_130 != 0) {
    uVar8 = 0;
    do {
      iVar3 = uVar8 * 4;
      puVar6 = (uint *)(*param_2 + iVar3);
      uVar8 = uVar8 + 1;
      *puVar6 = *(uint *)(*param_3 + iVar3) & *puVar6;
    } while (uVar8 < local_130);
  }
  if (local_2c != **(int **)(iVar9 + iVar1)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_0002376c @ 0002376c */

void FUN_0002376c(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = DAT_000237d8;
  iVar1 = DAT_000237d4;
  pcVar3 = getenv((char *)(DAT_000237d0 + 0x23778));
  *(char **)((int)&DAT_000237e8 + iVar1 + 2) = pcVar3;
  if (pcVar3 == (char *)0x0) {
    pcVar3 = getenv((char *)(DAT_000237dc + 0x2378c));
    *(char **)((int)&DAT_000237e8 + iVar1 + 2) = pcVar3;
    if (pcVar3 == (char *)0x0) {
      pcVar3 = getenv((char *)(DAT_000237e8 + 0x237ae));
      *(char **)((int)&DAT_000237e8 + iVar1 + 2) = pcVar3;
      if (pcVar3 == (char *)0x0) {
        *(undefined4 *)((int)&DAT_000237e8 + iVar1 + 2) = 1;
      }
      else {
        fwrite((void *)(DAT_000237ec + 0x237c4),1,0x35,
               (FILE *)(*(int *)(iVar2 + 0x23780 + DAT_000237e0) + 0xa8));
      }
    }
    else {
      fwrite((void *)(DAT_000237e4 + 0x237a2),1,0x34,
             (FILE *)(*(int *)(iVar2 + 0x23780 + DAT_000237e0) + 0xa8));
    }
  }
  return;
}



/* Function: FUN_000237f0 @ 000237f0 */

void FUN_000237f0(undefined4 param_1,undefined4 param_2)

{
  FUN_0002376c();
  FUN_000222fc(param_2);
  FUN_000222a8(param_1);
  return;
}



/* Function: basic_exit_err @ 00023808 */

void basic_exit_err(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  FILE *__stream;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = **(int **)(DAT_0002384c + 0x2381e + DAT_00023854);
  __stream = (FILE *)(*(int *)(DAT_0002384c + 0x2381e + DAT_00023850) + 0xa8);
  uStack_8 = param_3;
  uStack_4 = param_4;
  fprintf(__stream,(char *)(DAT_00023858 + 0x2382c),*(undefined4 *)(iVar1 + 4),
          *(undefined4 *)(iVar1 + 8));
  vfprintf(__stream,param_2,&uStack_8);
  fputc(10,__stream);
                    /* WARNING: Subroutine does not return */
  exit(param_1);
}



/* Function: putchar @ 00039000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putchar(int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcpy @ 00039004 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: log @ 00039008 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double log(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: printf @ 0003900c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strerror @ 00039010 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: inet_pton @ 00039014 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int inet_pton(int __af,char *__cp,void *__buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getopt_long @ 00039018 */

/* WARNING: Control flow encountered bad instruction data */

void getopt_long(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: snprintf @ 0003901c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_unwind_cpp_pr0 @ 00039024 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __errno @ 00039028 */

/* WARNING: Control flow encountered bad instruction data */

void __errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getgrgid @ 0003902c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

group * getgrgid(__gid_t __gid)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getprotobynumber @ 00039030 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

protoent * getprotobynumber(int __proto)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getenv @ 00039034 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getprotobyname @ 00039038 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

protoent * getprotobyname(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fgets @ 0003903c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 00039040 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: perror @ 00039044 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void perror(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_uldivmod @ 00039048 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_uldivmod(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: puts @ 0003904c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: malloc @ 00039050 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtoul @ 00039058 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_ui2d @ 0003905c */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_ui2d(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: gethostbyaddr @ 00039060 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * gethostbyaddr(void *__addr,__socklen_t __len,int __type)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: socket @ 00039068 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_dcmplt @ 0003906c */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_dcmplt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fflush @ 00039070 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_ddiv @ 00039074 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_ddiv(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_dmul @ 00039078 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_dmul(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strncasecmp @ 0003907c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: freeaddrinfo @ 00039080 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void freeaddrinfo(addrinfo *__ai)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: abort @ 00039084 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 00039088 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getnameinfo @ 0003908c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getnameinfo(sockaddr *__sa,socklen_t __salen,char *__host,socklen_t __hostlen,char *__serv,
               socklen_t __servlen,uint __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtol @ 00039090 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strnlen @ 00039094 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getnetbyaddr @ 00039098 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

netent * getnetbyaddr(uint32_t __net,int __type)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: uname @ 0003909c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int uname(utsname *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __libc_init @ 000390a0 */

/* WARNING: Control flow encountered bad instruction data */

void __libc_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strrchr @ 000390a4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strrchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: calloc @ 000390a8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtod @ 000390ac */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double strtod(char *__nptr,char **__endptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fprintf @ 000390b0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_dadd @ 000390b8 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_dadd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcat @ 000390bc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcat(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setsockopt @ 000390c0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t __optlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_dcmpgt @ 000390c4 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_dcmpgt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: wait @ 000390cc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t wait(void *__stat_loc)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_dcmpge @ 000390d0 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_dcmpge(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: mktime @ 000390d4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t mktime(tm *__tp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: read @ 000390d8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strncmp @ 000390dc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strncpy @ 000390e0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcasecmp @ 000390e4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcasecmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: realloc @ 000390e8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_i2d @ 000390ec */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_i2d(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtok @ 000390f0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcmp @ 000390f4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sscanf @ 000390fc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: execv @ 00039100 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int execv(char *__path,char **__argv)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strdup @ 00039104 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strdup(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtoull @ 00039108 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulonglong strtoull(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fopen @ 0003910c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: localtime @ 00039110 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime(time_t *__timer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memset @ 00039114 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __swbuf @ 00039118 */

/* WARNING: Control flow encountered bad instruction data */

void __swbuf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_uidiv @ 0003911c */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_uidiv(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fclose @ 00039120 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getservbyport @ 00039124 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

servent * getservbyport(int __port,char *__proto)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: putc @ 00039128 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putc(int __c,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 0003912c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getpwuid @ 00039130 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

passwd * getpwuid(__uid_t __uid)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: gethostbyname @ 00039134 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * gethostbyname(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getpwnam @ 00039138 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

passwd * getpwnam(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getservbyname @ 0003913c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

servent * getservbyname(char *__name,char *__proto)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sprintf @ 00039140 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcspn @ 00039144 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strcspn(char *__s,char *__reject)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: vfork @ 00039148 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t vfork(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fputc @ 0003914c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fputc(int __c,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_d2uiz @ 00039154 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_d2uiz(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getsockopt @ 00039158 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t *__optlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getaddrinfo @ 0003915c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getaddrinfo(char *__name,char *__service,addrinfo *__req,addrinfo **__pai)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_uidivmod @ 00039160 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_uidivmod(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fwrite @ 00039164 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getnetbyname @ 00039168 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

netent * getnetbyname(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: exit @ 0003916c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: inet_ntop @ 00039170 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * inet_ntop(int __af,void *__cp,char *__buf,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getgrnam @ 00039174 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

group * getgrnam(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: atoi @ 0003917c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strlen @ 00039184 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: open @ 00039188 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_unwind_cpp_pr1 @ 0003918c */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strchr @ 00039190 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fputs @ 00039194 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fputs(char *__s,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: close @ 00039198 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: vfprintf @ 0003919c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vfprintf(FILE *__s,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strpbrk @ 000391a0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: free @ 000391a4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



