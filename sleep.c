#include <unistd.h>
#include <stdio.h>

int main(int argc, int *argv[]) {
  unasigned int* string = argv[1];
  printf("%ls\n", string);
  sleep(argv[1]);
  return 0;
}
