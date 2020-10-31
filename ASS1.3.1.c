#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
void main(){
    int f = fork();
    if(f<0){
        printf("error\n");
        exit(1);
    }
    else if(f==0){
        printf("child:\n");
        char *args[] = {"Hello","Calling","Firefox",NULL};
        execv("./ASS1.3.2",args);
        exit(0);
    }
    else{
        printf("Parent_Process:\n");
        system("ls -l");
        exit(0);
    }
    
}
