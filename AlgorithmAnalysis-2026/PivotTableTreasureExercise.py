''' - Coins = [1, 2, 5]
    - Value = 11
Develop an algorithm that calculates the smallest number of coins needed to form the value 11.
Your code should:
      - Use dynamic programming with tabulation;
      - Create a DP table;
      - Fill the table from smallest to largest;
      - Return the smallest number of coins;
      - Display the final result; '''
      
# COIN CHEST CHALLENGE ✨

def solve_change():
    coins = [1, 2, 5]
    target_value = 11
    
    table = [12] * (target_value + 1)
    table[0] = 0
    
    for current_cent in range(1, target_value + 1):
        for coin in coins:
            if current_cent >= coin:
                current_option = 1 + table[current_cent - coin]
                
                if current_option < table[current_cent]:
                    table[current_cent] = current_option
                    
    result = table[target_value]
    print(f"The Smallest Amount of Coins for the Value {target_value} is: {result}")

solve_change()