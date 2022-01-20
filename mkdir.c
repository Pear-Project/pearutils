#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    const char *directory = argv[1];
    struct stat sb;

  if (argc < 2) {
    printf("mkdir: missing operand\n");
    exit(EXIT_FAILURE);
    } else {
    	if (stat(directory, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        	printf("mkdir: cannot create directory ‘%s’: File exists\n", directory);
		exit(EXIT_FAILURE);
    	} else {
        	mkdir(directory, S_IRWXU);
		exit(EXIT_SUCCESS);
    	}
    }
}
