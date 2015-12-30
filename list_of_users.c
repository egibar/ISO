/*
 Authors : Julen Fraile, Asier Egibar and Gorka Bravo
*/
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc,char* argv[]) {

	struct group* gr;	
	char** str;
	int i = 0;

	if(argc > 2)
	{
		printf("Bad arguments.\n");
		exit(0);
	} else {
		if((gr = getgrnam(argv[1])) == NULL)
			return 1;
		str = gr->gr_mem;
		//str_split(str,',');
		while(str[i] != NULL) {
			if(*str[i] == ',')
				write(0,"\n",1);
			else
				write(0,str[i],1);
			i++;
		}
		write(0,"\n",1);
	}
	return 0;
}
