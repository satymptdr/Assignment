#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
void main(){
    int f = fork();
    int status;
    if(f<0){
        printf("error");
        exit(1);
    }
    else if(f==0){
        //child_process
        printf("In child:\n");
        printf("child process id = %d\n",getpid());
        printf("parent process id = %d\n",getppid());
        status=getpid();
        exit(0);

    }
    else{
        //parent_process
        wait(&status);
        printf("In Parent:\n");
        if(WIFEXITED(status)){
            int exit_status = WEXITSTATUS(status);
            printf("The exit status of child process = %d\n",exit_status);
        }
        if(WIFSIGNALED(status)){
            int exit_signaled = WIFSIGNALED(status);
            printf("The exit status of child process = %d\n",exit_signaled);
        }  
        else if(WIFSTOPPED(status)){
            int exit_stopped = WIFSTOPPED(status);
            printf("The exit status of child process = %d\n",exit_stopped);
        }
        exit(0);
      }
}
