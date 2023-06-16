#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

int (*orig_puts)(const char *s);

int puts(const char *s)
{
   if (orig_puts == 0) {
     orig_puts = dlsym(RTLD_NEXT, "puts");
   }
   orig_puts("EXTRA FROM PATCH: ");
   return orig_puts(s);
}


int main()
{
}
