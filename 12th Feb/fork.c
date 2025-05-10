#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(1);
    } 
    else if (pid == 0) 
    {
        printf("Child Process: PID = %d\n", getpid());
        sleep(2);
        printf("Child exit\n");
        exit(0);
    } 
    else 
    {
        printf("Parent waiting for child\n");
        wait(NULL);  
        printf("Parent resumes after child exit.\n");
    }

    return 0;
}