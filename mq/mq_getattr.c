#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    /* Constantes O_* */
#include <sys/stat.h> /* Constantes de modo */
#include <mqueue.h>   /* Cola de mensajes */

int main(int argc, char* argv[])
{
    mqd_t mq;
    struct mq_attr attr;

    if (argc < 2) {
        fprintf(stderr, "Uso: %s queue\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*
     * COMPLETAR invocación a mq_open().
     * Consultar el manual para detalles de la función.
     *
     * Abrir la cola de mensajes indicada como parámetro desde la línea
     * de comandos. No es necesario escribir en la cola de mensaje, por
     * lo que se debe abrir solo para lectura. 
     */ 
    mq = mq_open();

    if (mq < 0) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    /*
     * COMPLETAR invocación a mq_getattr().
     * Consultar el manual para detalles de la función.
     * 
     * Obtener los atributos de la cola de mensajes abierta con mp_open()
     * anteriormente. Consultar el manual de la función mq_getattr().
     */
    int r = mq_getattr();

    if (r < 0) {
        perror("mq_getattr");
        exit(EXIT_FAILURE);
    }

    /*
     * COMPLETAR
     * Modificar las invocaciones a printf() para imprimir los valores de
     * los atributos indicados. Estos estan en la estructura mq_attr.
     */
    printf("mq_maxmsg = \n");
    printf("mq_msgsize = \n");
    printf("mq_curmsgs = \n");

    exit(EXIT_SUCCESS);
}
    
