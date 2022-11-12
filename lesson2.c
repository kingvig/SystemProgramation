#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){
    int id=fork();
    printf("Current ID: %d, parent ID: %d\n", getpid(), getppid() );
    int res = wait(NULL);
    if (res== -1){
        printf("no children to wait for\n");

    }else{
    printf("%d finished the execution", res);
    }
    return 0;
}
