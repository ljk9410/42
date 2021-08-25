#include "./minitalk.h"

int		main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	kill(server_pid, SIGUSR1);
	kill(server_pid, SIGUSR2);
	return (0);
}
 