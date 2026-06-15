# Challenge: Simulate an image processing filter. Each process should multiply the values ​​of 
#            its slice by 2. After that, the Master should collect the modified pieces and 
#            assemble a new complete matrix.
#
#  What to research: Investigate the comm.Gather() function. It is the inverse of Scatter.
#      Instruction:
#          * Prepare a receiving buffer in the Master with the total size (100 elements).
#          * Use Gather to collect the processed buffer_local.
#          * In Rank 0, transform the result back into a 10x10 matrix and print it.
#          * Expected Output: A matrix where the first element is 2 and the last is 201.

from mpi4py import MPI
import numpy as np

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()
    
    if size != 4:
        if rank == 0:
            print("Error: Run with exactly 4 processes.")
        return

    if rank == 0:
        matrix = np.arange(1, 101, dtype='i').reshape(10, 10)
        flat_data = matrix.flatten()
    else:
        flat_data = None

    local_buffer = np.empty(25, dtype='i')

    comm.Scatter(flat_data, local_buffer, root=0)

    local_buffer = local_buffer * 2

    gathered_flat = None
    if rank == 0:
        gathered_flat = np.empty(100, dtype='i')

    comm.Gather(local_buffer, gathered_flat, root=0)

    if rank == 0:
        final_matrix = gathered_flat.reshape(10, 10)
        print("Final Matrix:")
        print(final_matrix)

if __name__ == "__main__":
    main()