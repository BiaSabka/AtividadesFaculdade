# Write an MPI script in Python using the mpi4py package. 
#    * The master process (Rank 0) stores a vector with 16 student grades (floating-point numbers from 0.0 to 10.0). 
#    * Using collective communication, Rank 0 should divide the vector and send equal parts to 4 worker processes 
#      (each process will receive exactly 4 grades).
#    * Each process in the workgroup should iterate through its local grade buffer and calculate a bonus grade: 
#      if the grade is less than 9.0, it receives an increase of +1.0 point (without exceeding the maximum limit of 10.0). 
#    * Grades greater than or equal to 9.0 should be preserved. 
#    * After the change, use the comm.Gather function to consolidate the modified grades back into Rank 0 and display 
#      the final result on the screen.

from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

grades = None

if rank == 0:
    grades = np.array([5.5, 8.5, 9.0, 9.5, 4.0, 7.0, 8.2, 9.1, 3.5, 6.0, 8.8, 10.0, 7.5, 8.0, 9.9, 2.0], dtype='f')

local_grades = np.empty(4, dtype='f')

comm.Scatter(grades, local_grades, root=0)

for i in range(4):
    if local_grades[i] < 9.0:
        local_grades[i] = local_grades[i] + 1.0
        
        if local_grades[i] > 10.0:
            local_grades[i] = 10.0

final_grades = None

if rank == 0:
    final_grades = np.empty(16, dtype='f')

comm.Gather(local_grades, final_grades, root=0)

if rank == 0:
    print("Final Grades:")
    print(final_grades)