""" Now that you've seen that Threads didn't help in calculating the matrices, 
    modify the code above to use the multiprocessing library.

         1. Instead of threading.Thread, use multiprocessing.Process.

         2. Observe the CPU usage on your system during execution.

         3. Calculate the actual Speedup relative to the sequential time of Question 2. """
         
import time
import multiprocessing as mp

DATA_SIZE = 100_000
data = [1.0] * DATA_SIZE

def apply_brightness_chunk(chunk):
    for i in range(len(chunk)):
        chunk[i] = chunk[i] * 1.1
    return chunk

def worker(index, chunk, out_queue):
    processed = apply_brightness_chunk(chunk)
    out_queue.put((index, processed))

def run_sequential(original_data, times=4):
    values = original_data.copy()
    start = time.perf_counter()

    for _ in range(times):
        for i in range(len(values)):
            values[i] = values[i] * 1.1

    end = time.perf_counter()
    return end - start

def run_multiprocessing(original_data, times=4, num_processes=4):
    values = original_data.copy()
    start = time.perf_counter()

    for _ in range(times):
        chunk_size = len(values) // num_processes
        chunks = []
        for p in range(num_processes):
            left = p * chunk_size
            right = (p + 1) * chunk_size if p != num_processes - 1 else len(values)
            chunks.append(values[left:right])

        out_queue = mp.Queue()
        processes = []

        for idx, chunk in enumerate(chunks):
            proc = mp.Process(target=worker, args=(idx, chunk, out_queue))
            processes.append(proc)
            proc.start()

        results = [None] * num_processes
        for _ in range(num_processes):
            idx, processed_chunk = out_queue.get()
            results[idx] = processed_chunk

        for proc in processes:
            proc.join()

        values = []
        for part in results:
            values.extend(part)

    end = time.perf_counter()
    return end - start

if __name__ == "__main__":
    seq_time = run_sequential(data, times=4)
    print(f"Sequential total time: {seq_time:.4f} seconds")

    num_proc = 4
    mp_time = run_multiprocessing(data, times=4, num_processes=num_proc)
    print(f"Multiprocessing total time ({num_proc} processes): {mp_time:.4f} seconds")

    speedup = seq_time / mp_time if mp_time > 0 else float("inf")
    print(f"Speedup: {speedup:.2f}x")
