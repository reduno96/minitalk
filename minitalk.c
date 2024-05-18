// server.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum)
{
	if (signum == SIGUSR1) //if the signal is equal to SIGUSR1 then he prints "Hello World"
		printf("Hello World\n");
	else if (signum == SIGUSR2)
		printf("The random number is: %d\n", rand());
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGUSR1, &sa, NULL); //every time it receives signal SIGUSR1 and will apply a specific function to it (signal handler)
	sigaction(SIGUSR2, &sa, NULL); //every time receives signal SIGUSR1 and will apply a specific function to it (signal handler)
	// int i = getpid();
	// printf("%d\n", i);
	while(1) pause(); // keep the program running to receive signals
}
