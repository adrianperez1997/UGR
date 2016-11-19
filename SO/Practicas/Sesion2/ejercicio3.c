
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

#define PERM_XGRP(permiso) permiso & S_IXGRP == S_IXGRP
#define PERM_XOTH(permiso) permiso & S_IXOTH == S_IXOTH

void buscar(const char* pathname, int *n, int *tam){

struct stat atributos;
DIR* directorio=opendir(pathname);

if(directorio==NULL){
	perror("\nError al abrir el directorio.\n");
	exit(-1);
}

struct dirent* strdir = readdir(directorio);

while(strdir!=NULL){

	char current_file[1024];
	sprintf(current_file,"%s/%s", pathname, strdir->d_name);
	if(stat(current_file,&atributos) < 0) {
		printf("\nError al intentar acceder a los atributos");
		perror("\nError en lstat");
		exit(-1);
	}
	else if(!S_ISDIR(atributos.st_mode)){
		if(S_ISREG(atributos.st_mode) && PERM_XGRP(atributos.st_mode) && PERM_XOTH(atributos.st_mode)){
		printf("%s %lu\n", current_file, strdir->d_ino);
		int numArchivos=*n+1;
		*n=numArchivos;
		tam+=atributos.st_size;
		}
	}
	else if(S_ISDIR(atributos.st_mode)&& (strcmp(strdir->d_name, ".")!=0) && (strcmp(strdir->d_name, "..")!=0)){ buscar(current_file,n,tam);}
	strdir = readdir(directorio);
}

closedir(directorio);
}
int main(int argc, char *argv[]){


if(argc<2) {
	printf("\nSintaxis de ejecucion erronea\n\n");
	exit(-1);
}
const char* pathname = argv[1];
int n=0;
int tam=0;

printf("Los i-nodos son: \n");

buscar(pathname,&n,&tam);
printf("Existen %i archivos regulares con permiso x para grupo y otros\n",n);
printf("El tamaño total ocupado por dichos archivos es %d bytes\n",tam);


return 0;
}
