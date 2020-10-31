#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main(){
    int f = fork();
    if(f<0){
        printf("error");
        exit(1);
    }
    else if(f==0){
        //child_process
        printf("In child:\n");
        printf("child process id = %d\n",getpid());
        printf("parent process id = %d\n",getppid());
        exit(0);
    }
    else{
        //parent_process
        wait(NULL);
        printf("In parent:\n");
        printf("process id = %d\n",getpid());
        printf("child id = %d\n",f);
        printf("owner id =%d\n",getppid());
        exit(0);
    }
}
