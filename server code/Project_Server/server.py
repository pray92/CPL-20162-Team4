from socket import *
import sys
import threading

#thread function
def threadfunc(s1):
    name = str(i) + '.png'
    fp = open(name, 'wb')

    while(True):
        data = s1.recv(1024)
        if not data:
            break

        fp.write(data)

    fp.close()
    s1.close()

#need port input interface
HOST = ''
PORT = 9000

ADDR = (HOST, PORT)

serv_sock = socket(AF_INET, SOCK_STREAM)

serv_sock.bind(ADDR)

serv_sock.listen(50)

clnt_sock, addr = serv_sock.accept()

a = int(clnt_sock.recv(4))

for i in range(0, a):

    s1, add = serv_sock.accept()

    th = threading.Thread(target=threadfunc, args=(s1,))
    th.start()
    th.join()

serv_sock.close()