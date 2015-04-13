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

char to_print[512];
int i=1;
char Arg[]=("ERROR: Incorrect number of arguments are pased.\n");
char buf[512];
DIR *dir;

struct stat sb;
struct dirent *sarrera;

if (argc != 2){
	write (2,Arg,strlen(Arg));
	return 1;
}
if ((dir=opendir(argv[1]))==NULL)
	errore("opendir");

while ((sarrera=readdir(dir)) != NULL){
	strcpy (buf,argv[1]);
	strcat(buf,"/");
	strcat(buf,sarrera->d_name);
	if (stat(buf,&sb)==-1){
		errore("stat");
	}
	sprintf(to_print, "%lo %ld %ld %ld %lld %d\n",(unsigned long)sb.st_mode, (long)sb.st_nlink, (long)sb.st_uid, (long)sb.st_gid, (long long)sb.st_size, ctime(sb.st_mtime));
	
	write(1, to_print, strlen(to_print));
	write(1,"	",1);
	write(1,sarrera->d_name,strlen(sarrera->d_name));
	write(1,"\n",1);
}

closedir(dir);
return 0;
}
