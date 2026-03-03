""" Imagine you have a folder with 10 log files and you need to simulate rea-
    ding and processing each one.


       * Create a function process_log(name) that simulates reading a large file from
         disk using time.sleep(1).
       * Implement a loop that processes 10 logs sequentially and measures the time.
       *Use threading.Thread to trigger the processing of the 10 logs simultaneously.


Objective: To demonstrate that while the system "waits" for the disk to read a file,
           other threads can start reading the next ones, reducing the total time
           from ~10s to ~1s."""


import time
import threading

def process_log(name):
    print(f"Starting to read {name}...")
    time.sleep(1)  
    print(f"Finished reading {name}")

logs = [f"log_{i}.txt" for i in range(1, 11)]

print("\n=== SEQUENTIAL PROCESSING ===")
start_time = time.time()

for log in logs:
    process_log(log)

end_time = time.time()
print(f"Sequential time: {end_time - start_time:.2f} seconds")

print("\n=== PROCESSING WITH THREADS ===")
start_time = time.time()

threads = []

for log in logs:
    t = threading.Thread(target=process_log, args=(log,))
    threads.append(t)
    t.start()

for t in threads:
    t.join()

end_time = time.time()
print(f"Threaded time: {end_time - start_time:.2f} seconds")