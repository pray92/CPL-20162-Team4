from socket import *
import os
import threading

#Thread function
def threadfunc(file):
    fp = open(file, 'rb')

    s1 = socket()
    s1.connect((ADDR, PORT))

    while True:
        a = fp.read(1024)

        if  a == '':
            break
        s1.send(a)
    s1.close()
    fp.close()

#need gui input
ADDR = "127.0.0.1"
PORT = 9000

filenames = os.listdir('./images')

s = socket()

s.connect((ADDR, PORT))

#need file positon
filenames = os.listdir('./images')

a = filenames.__len__()

s.send(str(a).encode())

for filename in filenames:
    file = os.path.join('./images/', filename)

    th = threading.Thread(target=threadfunc, args=(file,))
    th.start()
    th.join()

s.close()