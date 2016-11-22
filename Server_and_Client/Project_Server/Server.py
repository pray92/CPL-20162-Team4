from socket import *
import sys
import threading

# thread function for receiving images from client
def receive_image(client, i):
    name = str(i) + '.png'                                                          # Name with .png
    with open(name, 'wb') as fp:                                                   # Open file to save image file
        while True:
            data = client.recv(1024)                                                # Receive image data from client step-
                                                                                    # -by step
            if not data:                                                           # Break the loop when receiving is over
                break
            fp.write(data)                                                         # Write data on file
    client.close()

class server :
    def begin_server(self, port=9000):
        server_socket = socket(AF_INET, SOCK_STREAM)                                # Initialze the TCP/IP server
        server_socket.bind(('', port))
        server_socket.listen(50)

        client_socket, address = server_socket.accept()

        list_count = int(client_socket.recv(4))                                     # Receive the number of list to receive

        for i in range(0, list_count):
            client, add = server_socket.accept()

            th = threading.Thread(target=receive_image, args=(client, i,))          # Thread initialization
            th.start()                                                              # Thread starts
            th.join()                                                               # Thread ends for zombie processes
        server_socket.close()
