# Develop a single Python program (executable as a client or server) that implements a simple system 
# for processing mathematical operations via UDP sockets. It should run in an infinite loop and 
# process text requests in the format OPERATION:VALUES.
#
#  Supported Operations:
#     ADD: a,b -> Returns the arithmetic sum (e.g., RESULT: 30.0).
#
#     SUBTRACT: a,b -> Returns the arithmetic sum (e.g., RESULT: 50.0).
#
#     POWER: base,exponent -> Returns the exponentiation (e.g., RESULT: 64.0).

import socket

mode = input("Type 'server' or 'client': ")

host = '127.0.0.1'
port = 50000

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

if mode == 'server':
    sock.bind((host, port))
    print("Server is running...")
    
    while True:
        data, address = sock.recvfrom(1024)
        message = data.decode('utf-8')
        
        try:
            parts = message.split(':')
            operation = parts[0]
            numbers = parts[1].split(',')
            
            a = float(numbers[0])
            b = float(numbers[1])
            
            if operation == 'ADD':
                result = a + b
            elif operation == 'SUBTRACT':
                result = a - b
            elif operation == 'POWER':
                result = a ** b
            else:
                result = "Invalid"
                
            response = "RESULT:" + str(result)
            
        except:
            response = "RESULT:Error"
            
        sock.sendto(response.encode('utf-8'), address)

elif mode == 'client':
    print("Client is running...")
    
    while True:
        message = input("Enter operation (ADD:a,b | SUBTRACT:a,b | POWER:a,b): ")
        sock.sendto(message.encode('utf-8'), (host, port))
        
        data, address = sock.recvfrom(1024)
        print(data.decode('utf-8'))