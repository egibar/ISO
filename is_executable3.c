/*
 Authors : Julen Fraile, Asier Egibar and Gorka Bravo
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int is_executable3( char *filename)
{
	struct stat infoinode;

	if (access(filename, F_OK) == -1) {
		perror(filename);
		return 0;
	}
	if (stat(filename, &infoinode) == -1) {
           perror("stat");
           return 0;
        }
	if (infoinode.st_mode & S_IXUSR)
		return 1;
	return 0;
}
