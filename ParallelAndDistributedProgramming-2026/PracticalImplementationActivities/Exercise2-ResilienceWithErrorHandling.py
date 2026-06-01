# 2: Sockets (TCP) — Resilience with Error Handling
#
#  Context: In the ctcp.py file, if the server is suddenly down, the client abruptly 
#  breaks with a network exception.
#
#   * Task: Modify the TCP client code using try/except blocks to make it resilient.
#
#  Implementation Rule: Wrap the sending and receiving of messages in a try block. 
#  If a connection error occurs (such as socket.error or ConnectionResetError), the 
#  client should catch the exception, print the friendly message "Connection lost to 
#  the server!" and terminate the program cleanly.

import socket
import sys

host = 'localhost'
port = 50000

c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
c.connect((host, port))

message = ' '

while message != '\x18':
    message = input()
    message2 = str.encode(message)
    
    try:
        c.sendall(str.encode(message))
        data = c.recv(1024)
        print('Echoed message: ', data.decode())
    except (socket.error, ConnectionResetError):
        print('Connection lost with the server!')
        break

c.close()