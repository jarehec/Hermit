#include "hermit.h"

extern int yyparse(void);
extern FILE *yyin;


/**
 * main - Entry point
 * @ac: number of arguments
 * @av: array of argument strings
 * Return: todo
 */
int main(int ac, char **av)
{
	if (ac == 2)
		yyin = fopen(av[1], "r");
	if (!yyin)
	{
		fputs("Usage: ./hermit <file>\n", stderr);
		exit(EXIT_FAILURE);
	}
	yyparse();
	print_tree(A_root);
	fclose(yyin);
	return (0);
}
