#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>


int main(int argc, char* argv[]){
    int id = fork();//we fork the main process and obtain 2 processes
    int n;
    if (id == 0){
        n = 1;
    }else{
        n = 6;
    }
    if (id !=0){
         wait(&id);
       // we wait for the child process to finish its execution before we launch the main process
    }
    int i;
    for(i=n;i<n+5;i++){
        printf("%d ",i);
        fflush(stdout);// we print every line each time it is executed directly
    }
    if (id !=0){
        printf("\n");//we prevent the chikd process from printing a line break character
    }
return 0;
}
