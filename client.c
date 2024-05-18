// client.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    pid_t server_pid = 21123/* server's PID here */;
    kill(server_pid, SIGUSR1); //sends signal SIGUSR1 to a server
    kill(server_pid, SIGUSR2); //sends signal SIGUSR2 to a server
}
