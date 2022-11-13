#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){
    int fd[2];
    //fd[0] - read
    //fd[1] - write
    if (pipe(fd) == -1){
        printf("an error occured when opening the pipe \n");
        return 1;
    }
    int id = fork();
    if ( id == 0){
        close(fd[0]);
        int x;
        printf("enter a number: ");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    }else {
        close(fd[1]);
    int y;
    read(fd[0], &y, sizeof(int));
    close(fd[0]);
    printf("Got the number: %d from the child process",y);
    return 0;
}
}
