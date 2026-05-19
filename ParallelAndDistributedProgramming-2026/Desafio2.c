#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

    int meu_rank;
    int total;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &total);

    printf("Eu sou o processo %d\n", meu_rank);
    printf("O total de processos e: %d\n", total);

    MPI_Finalize();

    return 0;
}