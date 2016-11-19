/*
ejercicio2.c
Trabajo con llamadas al sistema del Sistema de Archivos ''POSIX 2.10 compliant''
*/


#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>  	/* Primitive system data types for abstraction\
			   of implementation-dependent data types.
			   POSIX Standard: 2.6 Primitive System Data Types
			   <sys/types.h>
			*/
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
int fd1, fd2, i=0;
char bloque[15], bloque2[30], bloque3[2];
char buf1[80];

if(argc<2) {
	fd1=STDIN_FILENO;
}
if((fd1=open(argv[1],O_RDONLY,S_IRUSR|S_IWUSR))<0) {
	printf("\nError %d en open",errno);
	perror("\nError en open");
	exit(EXIT_FAILURE);
}

fd2=open("salida.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);

sprintf(bloque2, "El numero de bloques es:  \n");
write(fd2, bloque2, sizeof(bloque2));

while(read(fd1, buf1, 80)>0){
	sprintf(bloque, "\n\nBLOQUE %i: \n\n", i+1);
	write(fd2,bloque,sizeof(bloque));
	write(fd2,buf1,80);
	i++;
}
lseek(fd2,25,SEEK_SET);
sprintf(bloque3, "%i", i);
write(fd2, bloque3, sizeof(bloque3));


return 0;
}
