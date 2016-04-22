#include <iostream>
#include <mpi.h>

int main() {
    MPI::Init();
    int size;
    size = MPI::COMM_WORLD.Get_size();
    int rank;
    rank = MPI::COMM_WORLD.Get_rank();

    MPI::COMM_WORLD.Send(&rank, 1, MPI::INT, (rank + 1) % size, 0);

    int buf = 0;
    MPI::COMM_WORLD.Recv(&buf, 1, MPI::INT, (rank == 0) ? size - 1 : rank - 1, 0);
    std::cout << "process " << rank << " get message from process " << buf << std::endl;
    MPI_Finalize();
    return 0;
}