#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "parser.h"

void print_tline(tline *line)
{
	if (line == NULL)
	{
		printf("La línea es nula.\n");
		return;
	}
	printf("Número de comandos: %d\n", line->ncommands);
	for (int i = 0; i < line->ncommands; i++)
	{
		printf("Comando %d:\n", i);
		printf("  Nombre del archivo: %s\n", line->commands[i].filename);
		printf("  Número de argumentos: %d\n", line->commands[i].argc);
		for (int j = 0; j < line->commands[i].argc; j++) {
			printf("    Argumento %d: %s\n", j, line->commands[i].argv[j]);
		}
	}
	if (line->redirect_input)
	{
		printf("Redirección de entrada: %s\n", line->redirect_input);
	}
	if (line->redirect_output)
	{
		printf("Redirección de salida: %s\n", line->redirect_output);
	}
	if (line->redirect_error)
	{
		printf("Redirección de error: %s\n", line->redirect_error);
	}
	if (line->background)
	{
		printf("El comando se ejecuta en segundo plano.\n");
	}
	else
	{
		printf("El comando no se ejecuta en segundo plano.\n");
	}
}


int main(int argc, char **argv, char **envp) {
	tline	*line;
	int		pid;
	int		pipefd[2];

	if (argc < 2) {
		printf("Uso: ./minishell \"comando\"\n");
		return 1;
	}
	line = tokenize(argv[1]);
	if (line == NULL) {
		printf("Error al tokenizar el comando.\n");
		return 1;
	}

	print_tline(line);

	if (line->ncommands == 2)
	{
		pipe(pipefd);
		pid = fork();
		if (pid < 0)
		{
			perror("El fork ha ido mal");
			return (1);
		}
		else if (pid == 0)
		{
			printf("Soy el hijo\n");
		}
		else
		{
			printf("Soy el padre\n");
		}
	}

	return 0;
}
