#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>		//Needed for open
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include "dirent.h"  //cabecera necesaria para el tratamiento de directorios
#include <string.h>
#include <ftw.h>


#define PERM_XGRP(permiso) permiso & S_IXGRP == S_IXGRP
#define PERM_XOTH(permiso) permiso & S_IXOTH == S_IXOTH


int visitar(const char* path, const struct stat* stat, int flags, struct FTW* ftw) {

	if(S_ISREG(stat->st_mode) && PERM_XGRP(stat->st_mode) && PERM_XOTH(stat->st_mode)){
		printf("%s %lu\n",path, stat->st_ino);
		
	}
    return 0;
}


int main(int argc, char *argv[]){

if(argc<2){
   perror("\nError en la ejecucion del programa.\n Uso: ej2 <pathname>\n");
	exit(-1);
}

const char* pathname= argv[1];

printf("Los i-nodos son: \n");
 
if(nftw(argc >= 2 ? argv[1] : ".", visitar, 10, 0) != 0) {
   perror("nftw");
}

return 0;
}
