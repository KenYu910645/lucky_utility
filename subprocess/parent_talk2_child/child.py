import time 
import sys
import os 
while True :
    os.system('play -nq -t alsa synth {} sine {}'.format(0.05, 440))
    print (sys.stdin.readline()) # blocking forever ?! 
    #asdf = input("fuckyou")
    #print (asdf)
    time.sleep(0.01)
    # break 
