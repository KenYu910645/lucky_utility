#-*- coding: utf-8 -*-
import cv2
import sys

if (len(sys.argv) != 2):
  print("usage: " + sys.argv[0] + " <Image_Path>\n")
  sys.exit(-1);

img = cv2.imread(sys.argv[1], cv2.IMREAD_COLOR)

cv2.namedWindow("Display Image", cv2.WINDOW_AUTOSIZE);

cv2.imshow('Display Image', img)

cv2.waitKey(0)
