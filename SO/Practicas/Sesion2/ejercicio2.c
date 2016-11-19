
#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>		//Needed for open
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
int fd1,fd2;
struct stat atributos;

if(argc<2) {
	printf("\nSintaxis de ejecucion erronea\n\n");
	exit(-1);
}
const char* pathname = argv[1];

const char* octal = argv[2],*finalptr;


DIR* directorio=opendir(pathname);
if(directorio==NULL){
   perror("\nError al abrir el directorio.\n");
	exit(-1);
}

struct dirent* strdir = readdir(directorio);

while(strdir!=NULL){
	char current_file[1024];
	sprintf(current_file,"%s/%s", pathname, strdir->d_name);
		if(stat(current_file,&atributos)< 0) {
		printf("\nError al intentar acceder a los atributos");
		perror("\nError en lstat");
		exit(-1);
	}
	if(!S_ISDIR(atributos.st_mode)){
		int permisosAntiguos = atributos.st_mode&0777;
		int permisosNuevos = strtol(argv[2],NULL,8)&0777;
		
		if(chmod(current_file, permisosNuevos) < 0){
			printf("\nError en chmod para %s", strdir->d_name);
			printf("%s	%i	%o\n", strdir->d_name, errno, permisosAntiguos);
		}
		else{printf("%s	%i	%o\n", strdir->d_name, permisosAntiguos, permisosNuevos);}
	}
	strdir = readdir(directorio);

}
	

return 0;
}
