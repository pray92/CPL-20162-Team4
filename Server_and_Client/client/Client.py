from socket import *
import os
import threading

# Thread function for sending images to server
def send_image(filename, address='127.0.0.1', port=9000):
    with open(filename, 'rb') as fp:  # Open image file as binary reading
        s1 = socket()  # Connect to server
        s1.connect((address, port))

        while True:                                                             # Sending the binary data of-
                                                                                # -image until no data is to be sent
            image_data = fp.read(1024)                                          # Read the data step by step
            if image_data == '':                                                # Break the loop when there is no data to send
                break
            s1.send(image_data)                                                 # Send to server
    s1.close()

class client :
    def client_begin(self, address='127.0.0.1', port=9000):
        s = socket()                                                            # Connect to server
        s.connect((address, port))

        file_names = os.listdir('./images')                                     # list of file names in directory
        list_count = file_names.__len__()                                       # The number of list
        s.send(str(list_count).encode())                                        # Send the number of list to server

        for file_name in file_names:                                            # Loop for creating thread
            filename = os.path.join('./images/', file_name)                      # Extract file name
            th = threading.Thread(target=send_image, args=(filename,))          # Thread initialization
            th.start()                                                          # Thread start
            th.join()                                                           # Thread end for protecting zombies
        s.close()
