 #include <stdio.h>

int main ()
{
 unsigned char echo[20];
 while(1)
 {
   fgets(echo, 80, stdin);
   fputs(echo, stdout);
 }
 return 0;
}
//asier eguibar and gorka bravo
