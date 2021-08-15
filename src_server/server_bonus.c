#include "server_bonus.h"

void	handler(int signum)
{
	static int	i;
	static int	c;

	if (signum == SIGUSR2)
		c += (1 << i);
	if (i == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
		return ;
	}
	i++;
}

void	print_pid(int pid)
{
	ft_putstr_fd("SERVER's PID: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	print_pid(pid);
	if (signal(SIGUSR1, handler) == SIG_ERR)
		return (0);
	if (signal(SIGUSR2, handler) == SIG_ERR)
		return (0);
	while (1)
	{
	}
	return (0);
}
