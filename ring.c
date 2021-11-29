#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

// Etiquette
#define TAG 100

int main(int argc, char *argv[])
{
    int value, x, prev_proc, next_proc;
    MPI_Status status;
    // Unique rank is assigned to each process in a communicator
    int rank;
    // Total number of ranks (processors)
    int size;
    // The machine we are on
    char name[80];
    // Length of the machine name
    int length;
    double start_time, end_time;

    // Initializes the MPI execution environment
    MPI_Init(&argc, &argv);
    // Get this process' rank (process within a communicator)
    // MPI_COMM_WORLD is the default communicator
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // Get the total number of ranks in this communicator
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Gets the name of the processor
    // Implementation specific (may be gethostname, uname, or sysinfo)
    MPI_Get_processor_name(name, &length);
    start_time = MPI_Wtime();
    next_proc = (rank + 1) % size;
    prev_proc = (size + rank - 1) % size;
    if (rank == 0)
    {
        value = rank + 1000;
        MPI_Send(&value, 1, MPI_INT, next_proc, TAG, MPI_COMM_WORLD);
        MPI_Recv(&x, 1, MPI_INT, prev_proc, TAG, MPI_COMM_WORLD, &status);
    }
    else
    {
        MPI_Recv(&x, 1, MPI_INT, prev_proc, TAG, MPI_COMM_WORLD, &status);
        value = rank + 1000;
        MPI_Send(&value, 1, MPI_INT, next_proc, TAG, MPI_COMM_WORLD);
    }

    end_time = MPI_Wtime();
    printf("Process %d : Recieved %d from process %d in %f seconds\n", rank, x, prev_proc, end_time - start_time);

    // Terminate MPI execution environment
    MPI_Finalize();
    return 0;
}
