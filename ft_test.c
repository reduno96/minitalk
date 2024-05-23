

// t_list	g_info;

// void	ft_init(void)
// {
// 	g_info.c = 0;
// 	g_info.count = 7;
// 	g_info.i = 0;
// 	g_info.len_bits = 31;
// 	g_info.check_alloc = -1;
// 	g_info.len = 0;
// 	g_info.client_pid = 0;
// }

// void	ft_alloc(int signal)
// {
// 	if (g_info.check_alloc == -1)
// 	{
//         // printf("%d\n",g_info.len);
//         if (g_info.len > 0)
// 		    g_info.string = ft_calloc(g_info.len + 1, 1);
//         else
//             exit(1);
// 		// if (!g_info.string)
// 		// 	exit(1);
// 		g_info.check_alloc = 0;
// 	}
// 	if (signal == SIGUSR1)
// 		g_info.c |= (1 << g_info.count);
// 	g_info.count--;
// 	if (g_info.count < 0)
// 	{
// 		g_info.string[g_info.i++] = (char)g_info.c;
// 		if (ft_strlen(g_info.string) == g_info.len)
// 		{
// 			write(1, g_info.string, ft_strlen(g_info.string));
// 			write(1, "\n", 1);
// 			ft_free (&g_info.string);
// 			g_info.i = 0;
// 			g_info.len_bits = 31;
// 			g_info.check_alloc = -1;
// 		}
// 		g_info.count = 7;
// 		g_info.c = 0;
// 	}
// }

// void	handle_len(int signal)
// {
// 	static int	c;
// 	static int	count = 31;

// 	if (signal == SIGUSR1)
// 		g_info.len |= (1 << count);
// 	count--;
// 	if (count < 0)
// 	{
// 		count = 31;
// 		c = 0;
// 	}
// }

// void	handle(int signal, siginfo_t *frs, void *ntg)
// {
// 	(void)ntg;
// 	g_info.client_pid = frs->si_pid;
// 	if (g_info.client_pid != g_info.new_pid)
// 	{
// 		g_info.count = 7;
// 		g_info.c = 0;
// 		g_info.new_pid = g_info.client_pid;
// 		g_info.len_bits = 31;
// 		ft_free(&g_info.string);
// 		g_info.check_alloc = -1;
// 		g_info.i = 0;
// 		g_info.len = 0;
// 	}
// 	if (g_info.len_bits >= 0)
// 	{
// 		handle_len(signal);
// 		g_info.len_bits--;
// 	}
// 	else
// 	{
// 		ft_alloc(signal);
// 	}
// }

// int	main(void)
// {
// 	struct sigaction	sa;

// 	ft_init();
// 	sa.sa_sigaction = handle;
// 	sa.sa_flags = SA_SIGINFO;
// 	ft_printf("\e[30;40mHello, I am a server...\n");
// 	ft_printf("My Pid Is : \e[31;40m[%d] !!\n\e[0m", getpid());
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);
// 	while (1)
// 	{
// 	}
// }