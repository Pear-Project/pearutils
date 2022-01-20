#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_LEN 1024

int main(){
    char user_input[BUFFER_LEN];
    char* argv[120];
    int argc ;
    char* path= "/bin/";
    char file_path[50];

    while(1){

        printf("pearOS Simple Shell %% ");

        if(!fgets(user_input,BUFFER_LEN, stdin)){
            break;
        }

        size_t length = strlen(user_input);

        if(length == 0){
            break;
        }

        if (user_input[length - 1] == '\n'){
            user_input[length - 1] = '\0';
        }

        char *token;
        token = strtok(user_input," ");
        int argc=0;
        if(token == NULL){
            continue;
        }
        while(token!=NULL){
            argv[argc]=token;
            token = strtok(NULL," ");
            argc++;
        }

        argv[argc]=NULL;

        strcpy(file_path, path);
        strcat(file_path, argv[0]);

        if (access(file_path,F_OK)==0){

            pid_t pid, wpid;
            int status;

            pid = fork();
            if (pid == 0) {
                if (execvp(file_path,argv) == -1) {
                  perror("Child proccess end");
                }
                exit(EXIT_FAILURE);
            }
            else if (pid > 0) {
                wpid = waitpid(pid, &status, WUNTRACED);
                while (!WIFEXITED(status) && !WIFSIGNALED(status)){
                    wpid = waitpid(pid, &status, WUNTRACED);
                }
            }
            else {
                perror("Fork Failed");
            }
        }
        else {
            printf("Command is not available in the bin\n");
        }

    }
}
