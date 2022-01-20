#include<stdio.h>
#include<stdlib.h>

int main(int c, char *argv[])
{
    if (remove(argv[1]) == 0)
    printf("File/directory %s was removed.\n", argv[1]);
    else
      printf("Unable to remove file/direcory.\n");
return 0;
}
