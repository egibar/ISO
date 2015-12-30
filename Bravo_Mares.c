/*
*
*	Authors: Christian Mares
*                Gorka Bravo
*
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main (int argc, char* argv[])
{

int ec;
int errorFound = 0;

char error[]= "ERROR: ";
char error1[]="no arguments.\n";
char error2[]=" directory already exists.\n";

   if(argc == 1){
      write(2, error, strlen(error));
      write(2, error1, strlen(error1));
      return 1;
   }

   int i;
   for(i=1; i<argc; i++){

      ec = mkdir(argv[i], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

      if(ec == -1){
         write(2, error, strlen(error));
         write(2, argv[i], strlen(argv[i]));
         write(2, error2, strlen(error2));
         errorFound = 1;
      }
      else{

         if( (ec = chdir(argv[i])) != -1){
            mkdir("source", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            mkdir("exe", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            mkdir("test", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            chdir("..");
         }
      }
   }
	

   return errorFound;

}



