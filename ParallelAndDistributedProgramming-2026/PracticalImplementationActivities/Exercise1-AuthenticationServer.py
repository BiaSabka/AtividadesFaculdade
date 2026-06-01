# 1: Sockets (UDP) — Authentication Server
#
#  Context: In the original server.py file, the server accepts any UDP message and 
#  simply echoes it back to the client.
#
#   * Task: Modify the UDP server code so that it functions as a simple password validator.
#
#  Implementation Rule: The server should verify the received message. If the client sends
#  the string exactly equal to "admin123", the server should respond "Access Granted". 
#  For any other message, the server should respond "Access Denied".


import socket
import sys

HOST = '127.0.0.1' 
PORT = 50000

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serv = (HOST, PORT)

udp.bind(serv)

print("Server is online! Waiting for passwords...")

while True:
    message, user = udp.recvfrom(1024)

    text_received = message.decode('utf-8')
    
    print(f"O cliente {user} tentou a senha: {text_received}")

    if text_received == "admin123":
        response = "Access Granted."
    else:
        response = "Access Denied."

    bytes_response = response.encode('utf-8')

    udp.sendto(bytes_response, user)

udp.close()