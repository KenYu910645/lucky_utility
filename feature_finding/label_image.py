#!/usr/bin/env python
import os
import sys
import cv2
from pynput.keyboard import Key, Listener
import sys, termios, tty, os, time
import shutil

ImagePath = "/home/lucky/Desktop/lucky/manypeople/"
MoveImgTo = "/home/jimmy/catkin_ws/src/ev_safety_check/Img/preprossedImg/test/safe/"
ControversialImgPath = "/home/lucky/Desktop/contr_/"
button_delay = 0.2

def getch():
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(sys.stdin.fileno())
        ch = sys.stdin.read(1)
 
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return ch

def moveFile(fname):
    shutil.move(ImagePath + fname ,MoveImgTo + fname)

def moveControversialFile(fname):
    shutil.move(ImagePath + fname ,ControversialImgPath + fname)

i = 0
def main(args):
    for fname in os.listdir( ImagePath ):
        global i
        if fname.endswith( "jpeg" ):
            print '====== ',i,' ======'
            print 'fname :',fname
            
            cv2.namedWindow('image',cv2.WINDOW_NORMAL)
            cv2.resizeWindow('image', 900,900)
            srcImage = cv2.imread( ImagePath + fname )
            detector = cv2.FeatureDetector_create("FAST")

            kps = detector.detect(srcImage)
            for kp in kps:
                x = int(kp.pt[0])
                y = int(kp.pt[1])
                cv2.circle(srcImage, (x, y), 2, (0, 0, 255))
                
            print("# of keypoints: {}".format(len(kps)))
            cv2.imshow("image", srcImage)

            # Canny
            #srcImage = cv2.GaussianBlur(srcImage,(3,3),0)
            #canny = cv2.Canny(srcImage, 50, 150)
            #cv2.imshow('image',canny)
            # Selective Search 
            '''
                ss = cv2.ximgproc.segmentation.createSelectiveSearchSegmentation()
            ss.setBaseImage(srcImage)
            ss.switchToSelectiveSearchFast()
            rects = ss.process()
            imOut = srcImage.copy()
                count = 0 
                for i, rect in enumerate(rects):
            if (i < 1000):
            x, y, w, h = rect
            if h/w > 1.5 and h/w < 5 and w > 40:
                count += 1
                cv2.rectangle(imOut, (x, y), (x+w, y+h), (0, 255, 0), 1, cv2.LINE_AA)
            else:
            break
            cv2.imshow("image", imOut)
            print "COunt = ", count 
                imageVar=cv2.Laplacian(srcImage, cv2.CV_64F).var()
            
                print "imageVar = ",imageVar
            '''
            cv2.waitKey(30)
            keyboardInput = getch()
            print  keyboardInput
            if keyboardInput == "q":
                time.sleep(button_delay)
                break
            elif keyboardInput == "m" :
                print 'move Image from :',ImagePath, ' to: ',MoveImgTo
                moveFile(fname)
            elif keyboardInput == "c" :
                print 'move Image from :',ImagePath, ' to: ',ControversialImgPath
                moveControversialFile(fname)
            else:
                print  keyboardInput
                time.sleep(button_delay)
                
            i += 1

if __name__ == '__main__':
    #main(sys.argv)
    #main(sys.argv)
    main(sys.argv)

