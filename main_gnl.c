# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*linePrinted;
	int		a;

	a = 0;
	//fd = open ("./archivos/caracter.txt", O_RDONLY);
	//fd = open ("./archivos/linea.txt", O_RDONLY);
	//fd = open ("./archivos/lineas.txt", O_RDONLY);
	//fd = open ("./archivos/2lineas.txt", O_RDONLY);
	//fd = open ("./archivos/two_line_no_nl", O_RDONLY);
	//fd = open ("./archivos/quijote.txt", O_RDONLY);
	//fd = open ("./archivos/41_no_nl", O_RDONLY);
	//fd = open ("./archivos/41_with_nl", O_RDONLY);
	//fd = open ("./archivos/42_no_nl", O_RDONLY);
	//fd = open ("./archivos/42_with_nl", O_RDONLY);
	//fd = open ("./archivos/43_no_nl", O_RDONLY);
	//fd = open ("./archivos/43_with_nl", O_RDONLY);
	//fd = open ("./archivos/alternate_line_nl_no_nl", O_RDONLY);
	//fd = open ("alternate_line_no_with_nl", O_RDONLY);
	//fd = open ("./archivos/big_line_no_nl", O_RDONLY);
	//fd = open ("./archivos/big_line_with_nl", O_RDONLY);
	//fd = open ("./archivos/nl", O_RDONLY);
	//fd = open ("./archivos/empty", O_RDONLY);
	//fd = open ("./archivos/1char.txt", O_RDONLY);
	//fd = open ("./archivos/giant_line_nl.txt", O_RDONLY);
	//fd = open ("./archivos/giant_line.txt", O_RDONLY);
	//fd = open ("./archivos/lines_around_10.txt", O_RDONLY);
	//fd = open ("./archivos/multiple_nl.txt", O_RDONLY);
	//fd = open ("./archivos/multiple_line_no_nl", O_RDONLY);
	//fd = open ("./archivos/multiple_nlx5.txt", O_RDONLY);
	//fd = open ("./archivos/one_line_no_nl.txt", O_RDONLY);
	//fd = open ("./archivos/only_nl.txt", O_RDONLY);
	fd = open ("./archivos/read_error.txt", O_RDONLY);
	//fd = open ("./archivos/variable_nls.txt", O_RDONLY);

	if (fd == -1)
		return (0);
	
	while (1)
	{
		linePrinted = get_next_line(fd);
		if (!linePrinted)
		{
			close(fd);
			system("leaks -q a.out");
			return (0);
		}
		if (linePrinted == NULL)
		{
			free (linePrinted);
			return (0);
		}
		printf("%s", linePrinted);
	if (linePrinted) 
		(free(linePrinted), linePrinted = NULL);
	}
	close(fd);
	system("leaks -q a.out");
	return (0);

}