/*
** Authors: Julen Fraile, Gorka Bravo and Asier Eguibar.
*/


#include <string.h>
#include <sys/types.h>
#include <fcntl.h>


int main(int argv,char* argc[]) {
    int fd,fd1;
	int n = 10;
	int length;
	char error[] = "ERROR : ";
	char error1[] = "no arguments.\n";
	char error2[] = "tail: no se puede abrir ";
	char error3[] = " para lectura: No existe el archivo o el directorio.\n";
	char buff[10];

	if(argv == 1) 
	{
		write(2,error,strlen(error));
		write(2,error1,strlen(error1));
		return 0;
	}
	
	int i;
	for(i=1;i < argv;i++)
	{		
		if((fd = open(argc[i],O_RDONLY)) == -1)
		{
			write(2,error2,strlen(error2));
			write(2,argc[i],strlen(argc[i]));
			write(2,error3,strlen(error3));		
		}else{
			lseek(fd,0,SEEK_CUR);
			length = lseek(fd,0,SEEK_END);
			lseek(fd,length-n,SEEK_SET);
	
	
			write(2,">>",2);
			write(2,argc[i],strlen(argc[i]));
			write(2,">>\n",3);
	
			while((fd1 =read(fd,buff,n)) != 0); {
				write(2,buff,n);
			} 
			close(fd);
//			write(2,"\n",1);
		}
	}
	return 0;
}
