#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main() {
   char cwd[PATH_MAX];
   getcwd(cwd, sizeof(cwd));
   printf("%s\n", cwd);
   return 0;
}
