#ifndef DLFCN_H_STUB
#define DLFCN_H_STUB

#define RTLD_NOW 2

void *dlopen(const char *path, int mode);
void *dlsym(void *handle, const char *symbol);
int dlclose(void *handle);

#endif
