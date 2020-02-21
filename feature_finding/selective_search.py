import cv2

im = cv2.imread('test.jpeg')

ss = cv2.ximgproc.segmentation.createSelectiveSearchSegmentation()

ss.setBaseImage(im)

ss.switchToSelectiveSearchFast()

# ss.switchToSelectiveSearchQuality()

rects = ss.process()

print('Count: {}'.format(len(rects)))

numShowRects = 1000

increment = 50
count = 0 
while True:
  imOut = im.copy()

  for i, rect in enumerate(rects):
      if (i < numShowRects):
          x, y, w, h = rect
          if h/w > 1.5 and h/w < 5:
              count += 1
              cv2.rectangle(imOut, (x, y), (x+w, y+h), (0, 255, 0), 1, cv2.LINE_AA)
      else:
          break
  cv2.imshow("Output", imOut)

  k = cv2.waitKey(0) & 0xFF

  if k == 109:
      print count 
      # numShowRects += increment
  elif k == 108 and numShowRects > increment:
      pass
      # numShowRects -= increment
  elif k == 113:
      break

cv2.destroyAllWindows()
