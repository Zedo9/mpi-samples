# MPI Examples

Examples of parallel programs using the MPI library.

## How to run

-   Make sure you have `make`, `gcc` and `mpi`.
-   Run `make all` to generate the binaries and then `./main.out` to execute the main program.

An additional sample program was added to test that you have the required environment. Run `make test` and then `mpirun -np 4 ./test.out`.

You can tinker with the number of processors directly from the source code in each `system()` call (the `-np 4` flag indicates 4 processors).
