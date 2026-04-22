''' - Use Recursion;
    - Store Already Calculated Results;
    - Avoid Recomputing Subproblems;
    -Test the Algorithm with N = 10, N = 100 AND N = 1000;
    - Display the Final Result. '''

memo_notebook = {}

def climb_stairs(n):
    if n in memo_notebook:
        return memo_notebook[n]
    
    if n == 1:
        return 1
    if n == 2:
        return 2

    result = climb_stairs(n - 1) + climb_stairs(n - 2)
    memo_notebook[n] = result
    return result

tests = [10, 100, 1000]

import sys
sys.setrecursionlimit(3000)

print("Calculating the Wizard's Challenges...")
print("-" * 40)

for steps in tests:
    final_result = climb_stairs(steps)
    print(f"For {steps} steps, there are {final_result} ways to climb!")

print("-" * 40)