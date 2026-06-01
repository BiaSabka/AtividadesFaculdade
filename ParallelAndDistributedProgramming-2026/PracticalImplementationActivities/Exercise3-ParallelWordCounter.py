# 3: Dask — Parallel Word Counter (Classic MapReduce)
#
#  Context: The file test_local.py distributes the calculation of mathematical 
#  powers through lists of tasks. We will use this same parallel computing approach for string processing.
#
#  * Task: Create a Dask script where the distributed function is called count_letters(word).
#
#  Implementation Rule:
#     - The function should receive a string, count how many characters it has (using len()) 
#       and return a tuple containing: (word, size, process_PID).
#     - In the main scope (__main__), instantiate the local Dask cluster and pass the following 
#       list for parallel computing: ["parallel", "distributed", "systems", "cloud", "socket", "computing"].
#     - Collect the results using client.gather() and display the detailed count of each word on the screen.


import os
from dask.distributed import Client, LocalCluster

def count_letters(word):
    pid = os.getpid()
    length = len(word)
    return (word, length, pid)

if __name__ == "__main__":
    cluster = LocalCluster(n_workers=4, threads_per_worker=1)
    client = Client(cluster)

    print("\n--- Active Cluster ---")
    print(f"Dashboard Link: {client.dashboard_link}")
    print("----------------------\n")

    words = ["paralela", "distribuida", "sistemas", "nuvem", "socket", "computacao"]
    
    print("Sending tasks to the cluster...")
    
    futures = client.map(count_letters, words)
    results = client.gather(futures)

    print("\n=== FINAL RESULTS ===")
    for w, length, pid in results:
        print(f"Word: {w} | Length: {length} | Processed by PID: {pid}")

    input("\nPress Enter to close the cluster...")
    client.close()
    cluster.close()