/*
** Authors: Julen Fraile, Gorka Bravo and Asier Eguibar.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main (int argc, char* argv[])
{
	if(argc != 3 )
	{
		write(2, "Incorrect number of arguments.\n",31);
		return 0;
	}
	int f1, f2;
	if((f1=open(argv[1],O_APPEND))==-1)
	{
		write(2, "First file does not exist.\n",27);
		return 0;
	}
	if((f2=open(argv[2],O_RDONLY))==-1)
	{
		write(2, "Second file does not exist.\n",28);
		return 0;
	}
	char c[1];
	while(read(f2,c,1)!=0) {
		write(1,c,1);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
