#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PATH_ARCHIVO "data2.bin"

int main(void)
{
	

	//Abrir archivo
	int fd;	
	fd = open(PATH_ARCHIVO,O_CREAT|O_RDWR);

	//Mapeo y cierre archivo
	int tamanio = 5;
	int offset = 0;
	char *bloque= (char *) mmap(NULL,  tamanio,  PROT_READ|PROT_WRITE, MAP_SHARED,  fd,  (off_t) offset); 
	close(fd);
	
	//Lectura, escritura
 	
	/*Visualización del contenido del archivo*/ 
	int i = 0;	 
	for (; i<=tamanio; i++) 
		 putchar(proyeccion[i]); 
	puts("");
	
	 /*Liberación y actualizacion del archivo*/ 
	 munmap (proyeccion, tamanio); 

	return 0;
}