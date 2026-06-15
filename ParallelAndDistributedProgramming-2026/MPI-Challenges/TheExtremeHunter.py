#  Challenge: Modify the base code so that, in addition to the sum, the program 
#             identifies the largest and smallest values ​​contained in the array.
#
#   * What to observe: The comm.reduce() function accepts different types of 
#     mathematical operations.
#   * Expected Output: Rank 0 should print: "Maximum: 100, Minimum: 1".

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

    local_sum = np.sum(local_buffer)
    local_max = np.max(local_buffer)
    local_min = np.min(local_buffer)
    
    print(f"[Process {rank}] Local sum, max, and min calculated.")

    total_sum = comm.reduce(local_sum, op=MPI.SUM, root=0)
    total_max = comm.reduce(local_max, op=MPI.MAX, root=0)
    total_min = comm.reduce(local_min, op=MPI.MIN, root=0)

    if rank == 0:
        print(f"\n>>> Final Sum Result: {total_sum}")
        print(f"Maximum: {total_max}, Minimum: {total_min}")

if __name__ == "__main__":
    main()