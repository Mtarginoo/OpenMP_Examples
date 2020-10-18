#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(void); /* Thread function */

int main(int argc, char* argv[]){
    /*Get number of threads from commando line */
    int thread_count = strtol(argv[1], NULL, 10);

    //strol é usada para ler um valor diretamente da linha de comando (string, ponteiro para NULL(apenas um argumento), base decimal)
    
    #pragma omp parallel num_threads(thread_count)
    Hello();

    return 0;
}

void Hello(void){
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    printf("Hello from thread %d of %d\n", my_rank, thread_count);
}



