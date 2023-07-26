#include "shell.h"
/**
 * main -starting point
 *
 * Return: 0 if Success
 */
int main(void)
{	char *userinput = NULL;
	ssize_t n = 0;
	size_t nline = 0;
	pid_t process_pid;
	int inter_mode = isatty(STDIN_FILENO);

	if (!inter_mode)
	{	n = getline(&userinput, &nline, stdin);
		if (_strcmp(userinput, "exit") == 0)
			;
		else if (_strcmp(userinput, "env") == 0)
			_print_env();
		else if (call_fork(userinput, n) == 1)
			_exec_cmd(userinput, n); }
	while (inter_mode)
	{
		if (n != -1)
		{	write(STDOUT_FILENO, "#cisfun$ ", 10);
			n = getline(&userinput, &nline, stdin); }
		if (_strcmp(userinput, "exit") == 0)
			break;
		if (n == -1)
		{
			if (feof(stdin))
			{	write(STDOUT_FILENO, "\n", 1);
				break; }
			break; }
		else if (_strcmp(userinput, "\n") == 0)
		;
		else if (_strcmp(userinput, "env") == 0)
			_print_env();
		else if (call_fork(userinput, n) == 1)
		{	process_pid = fork();
			if (process_pid == -1)
				perror("fork");
			else if (process_pid == 0)
				_exec_cmd(userinput, n);
			else
				wait(NULL); } }
		free(userinput);
		return (0); }
