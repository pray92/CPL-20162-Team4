import numpy as np
import cv2

cap = cv2.VideoCapture(0)

i = 0

while(True):
    # Capture frame-by-frame
    ret, img = cap.read()

    # Display the resulting frame
    cv2.imshow('frame',img)
    ch = cv2.waitKey(1)

    if ch == 27: #ESC input -> Exit
        break
    elif ch == 13: #Enter inuput -> Capture
        cv2.imwrite('Image\\' +str(i) + '.jpg', img)
        i += 1
