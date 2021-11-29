#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int value, sum;
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
    if (rank == 0)
    {
        value = 1000;
    }
    else
    {
        value = rank;
    }
    end_time = MPI_Wtime();
    MPI_Reduce(&value, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Process 0 : Global Sum %d\n", sum);
        printf("Process 0 : Time -> %f seconds\n", end_time - start_time);
    }

    // Terminate MPI execution environment
    MPI_Finalize();
    return 0;
}
