#include "./minitalk.h"

void sig_handler(int signo)
{
	if (signo == SIGUSR1)
		printf("SIGUSR1\n");
	else
		printf("SIGUSR2\n");
}
 
int main()
{
	printf("PID: %d\n", getpid());    
    signal(SIGUSR1, (void *)sig_handler);
    signal(SIGUSR2, (void *)sig_handler);
    while(1)
        pause();
    return (0);
}
