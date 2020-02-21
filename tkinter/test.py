import threading # get rid of counters, use timer
import time 
def CB():
    print ("This is CB")

timer = None 
timer = threading.Timer(1,CB)
timer.start()
while True : 
    print ("Loop")
    time.sleep(0.5)