# MPI — Threshold Filtering in Vectors
#
#  Context: The Scatter splits an original array and distributes it into equal chunks. 
#  The master then waits for the calculated data back using Gather.
#
#   * Task: Write an MPI script where Rank 0 creates a sorted vector with 20 elements 
#     (integers from 1 to 20) and distributes it equally to 4 worker processes (each 
#     process will receive 5 elements).
#
#  Implementation Rule: Each process should traverse its local buffer and apply a 
#  threshold filter: any number within its local buffer that is greater than 10 should 
#  be replaced with -1. After the change, use the comm.Gather() function to collect 
#  the modified vector back into Rank 0 and print the complete modified vector.

from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

send_array = None

if rank == 0:
    send_array = np.arange(1, 21, dtype='i')

local_buffer = np.empty(5, dtype='i')

comm.Scatter(send_array, local_buffer, root=0)

for i in range(5):
    if local_buffer[i] > 10:
        local_buffer[i] = -1

gathered_array = None

if rank == 0:
    gathered_array = np.empty(20, dtype='i')

comm.Gather(local_buffer, gathered_array, root=0)

if rank == 0:
    print("Modified Array:")
    print(gathered_array)