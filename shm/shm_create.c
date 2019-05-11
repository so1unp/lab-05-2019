#include <fcntl.h>      // Constantes O_*
#include <sys/stat.h>   // Constantes de modo
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>     // ftruncate()
#include <stdio.h>      // printf()

int main(int argc, char* argv[])
{
    int fd;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s nombre_segmento\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*
     * COMPLETAR
     * Crear un nuevo segmento de memoria compartida, utilizando la función
     * shm_open(). El nombre debe ser el indicado desde la linea de comandos,
     * y la invocación a shm_open() debe fallar si ya existe un segmento de
     * memoria compartida con el mismo nombre. Además, debe ser creado en 
     * modo de lectura y escritura (RDWR). Los permisos con que debe ser
     * creado son de lectura y escritura para el usuario dueño, y de solo
     * lectura para otros usuarios (esto es, rw-r--r--). 
     * Consultar el manual de shm_open() para más detalles.
     */
    fd = shm_open();

    /* Verifica que no haya errores */
    if (fd == -1) {
        perror("shm_open()");
        exit(EXIT_FAILURE);
    }

    /* Cierra el descriptor de archivo que permite referenciar al segmento
     * de memoria compartida, pero no la elimina.
     */
    close(fd);

    exit(EXIT_SUCCESS);
}

