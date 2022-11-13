#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int fd[2];
    int start, end;
    int arr[]={2,3,7,14,12,20,28,14,26};
    int arrSize = sizeof(arr)/sizeof(int);

    if (pipe(fd) == -1){
    printf("could not create the pipe");
    return 1;
    }
    int id = fork();
    if (id == -1){
    printf("could not do the fork");
    return 2;
    }
    if (id == 0){
    start = 0;
    end = start + arrSize/2;
    } else{
        start = arrSize/2;
    }
    int sum = 0;
    int i;
    for (i = start; i<end; i++){
        sum += arr[i];
    }
    printf("Calculated partial sum: %d\n",sum);
    if (id ==0){
        close(fd[0]);
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);
    }else{
        int sumFromChild;
        close(fd[1]);
        read(fd[0], &sumFromChild, sizeof(int));
         close(fd[0]);
         int totalSum = sum + sumFromChild;
         printf("Calculated total sum: %d\n",totalSum);
         wait(NULL);

    }

    return 0;
}


