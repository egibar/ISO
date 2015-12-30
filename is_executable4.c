/*
 Authors : Julen Fraile, Asier Egibar and Gorka Bravo
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int is_executable4(char *filename)
{
        if (access(filename, F_OK) == -1) {
                perror(filename);
                return 0;
        }
	if (access(filename, X_OK) == -1) {
		return 0;
	}
	else
	{
		return 1;
	}
   
}

