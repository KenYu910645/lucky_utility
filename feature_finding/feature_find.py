import cv2

rad = 2
img = cv2.imread("test.jpeg")

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

detector = cv2.FeatureDetector_create("FAST")

kps = detector.detect(gray)

print("# of keypoints: {}".format(len(kps)))

while True:
    #Get image from webcam and convert to greyscale
    #Draw a small red circle with the desired radius
    #at the (x, y) location for each feature found
    for kp in kps:
        x = int(kp.pt[0])
        y = int(kp.pt[1])
        cv2.circle(img, (x, y), rad, (0, 0, 255))

    #Display colour image with detected features
    cv2.namedWindow('features',cv2.WINDOW_NORMAL)
    cv2.imshow("features", img)
    cv2.resizeWindow('features', 900,900)

    #Sleep infinite loop for ~10ms
    #Exit if user presses <Esc>
    if cv2.waitKey(10) == 27:
        break
