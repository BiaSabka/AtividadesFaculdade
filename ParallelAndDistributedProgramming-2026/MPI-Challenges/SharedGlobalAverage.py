# Challenge: Calculate the arithmetic mean of all elements. However, the final result 
#            (the mean) must be available to all processes, not just the master.
#
#    * What to research: Investigate the comm.allreduce() function.
#    * Instruction: Understand why allreduce dispenses with the use of the root parameter for the final result.
#    * Expected Output: All 4 processes should print: "[Process X] The overall mean is: 50.5".

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

    total_sum = comm.allreduce(local_sum, op=MPI.SUM)
    
    global_average = total_sum / 100

    print(f"[Process {rank}] The global average is: {global_average}")

if __name__ == "__main__":
    main()