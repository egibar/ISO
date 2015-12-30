//ASIER EGUIBAR, JULEN FRAILE, GORKA BRAVO.

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define errore(a) {perror(a); exit(1);};

int main(int argc, char *argv[]){

char Arg[]=("ERROR: Incorrect number of arguments are pased.\n");
struct stat infoinode;
mode_t modo1,modo2;

if (argc != 2){
	write (2,Arg,strlen(Arg));
	return 1;
}

stat(argv[1], &infoinode);
modo1=infoinode.st_mode;

stat(argv[2], &infoinode);
modo2=infoinode.st_mode;

if (mode1!=mode2)
return 1;

return 0;
}