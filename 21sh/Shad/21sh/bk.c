while (x <= i)
{
	pipe(fd + x);
	x = x + 2;
}
x = (x - 2) - 1;
length = x;
father = fork();
if (father != 0)
	wait(NULL);
	else
{
	dup2(fd[1], STDOUT);
	while (length >= 0)
	{
		close(fd[length]);
		length--;
	}
	w->line = com[0];
	ft_minishell2(env, *w);
}
n = 0;
while (com[y + 1] != NULL)
{
	father = fork();
	if (father != 0)
	{
		wait(NULL);
		y++;
		n += 2;
	}
	else
	{
		length = x;
		dup2(fd[n], STDIN);
		dup2(fd[n + 3], STDOUT);
		while (length >= 0)
		{
			close(fd[length]);
			length--;
		}
		w->line = com[y];
		ft_minishell2(env, *w);
	}
}
father = fork();
if (father != 0)
{
	wait(NULL);
	length = x;
	while (length >= 0)
	{
		close(fd[length]);
		length--;
	}
}
else
{
	length = x;
	dup2(fd[n], STDIN);
	while (length >= 0)
	{
		close(fd[length]);
		length--;
	}
	w->line = com[y];
	ft_minishell2(env, *w);
}

