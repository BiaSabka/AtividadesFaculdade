"""   
      1. Crie uma lista (matriz unidimensional) com 100.000 elementos, todos inicializados 
        com o valor 1.0. 
      2. Crie uma função chamada aplicar_brilho(dados) que percorra essa lista e 
        multiplique cada elemento por 1.1. 
      3. Execute essa função 4 vezes de forma sequencial e meça o tempo total. 
      4. Tente executar as mesmas 4 funções usando 4 Threads (threading.Thread) 
        simultaneamente. 
      5. Compare os tempos e explique por que as Threads não reduziram o tempo de 
        execução, apesar de usarem "paralelismo".
Objetivo: Simular a aplicação de um "filtro de brilho" em grandes volumes de dados para 
observar como o interpretador Python (GIL) lida com tarefas intensivas de CPU. 
                                                                                         
                                                                                         """

import time
import threading

data = [1.0] * 100_000

def apply_brightness(values):
    for i in range(len(values)):
        values[i] = values[i] * 1.1

print("\n=== SEQUENTIAL (4 times) ===")

data_seq = data.copy()  

start_time = time.time()

apply_brightness(data_seq)
apply_brightness(data_seq)
apply_brightness(data_seq)
apply_brightness(data_seq)

end_time = time.time()
print(f"Sequential total time: {end_time - start_time:.4f} seconds")

print("\n=== 4 THREADS ===")

data_thr = data.copy()

start_time = time.time()

threads = []

for _ in range(4):
    t = threading.Thread(target=apply_brightness, args=(data_thr,))
    threads.append(t)
    t.start()

for t in threads:
    t.join()

end_time = time.time()
print(f"Threaded total time: {end_time - start_time:.4f} seconds")
