#include "./minitalk.h"

int		main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	kill(server_pid, SIGUSR1);
	kill(server_pid, SIGUSR2);
	return (0);

	// 이후에 문자열을 받아서 넘겨주는 함수를 작성하면 끝
}
 