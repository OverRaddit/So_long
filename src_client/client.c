#include "client.h"

void	transmit(char c, pid_t pid)
{
	static int	i;
	int			sig;

	if (i == 8)
	{
		i = 0;
		return ;
	}
	sig = (c >> i) & 1;
	if (sig == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(50);
	i++;
	transmit(c, pid);
}

void	print_pid(int pid)
{
	ft_putstr_fd("SERVER's PID: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	int		i;
	int		strlen;

	if (argc != 3)
	{
		ft_putstr_fd("Nah.. Submit like [./client (pid) (string)]\n", 1);
		return (-1);
	}
	server_pid = ft_atoi(argv[1]);
	print_pid(server_pid);
	i = 0;
	transmit('>', server_pid);
	strlen = ft_strlen(argv[2]);
	while (i < strlen)
		transmit(argv[2][i++], server_pid);
	transmit('\n', server_pid);
	return (0);
}
