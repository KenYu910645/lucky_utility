# https://docs.python.org/3/library/subprocess.html # document of subprocess
import subprocess
import time 
import sys
from subprocess import PIPE, Popen
import threading
from queue import Queue, Empty

child = subprocess.Popen(["python3", "-u" ,"child.py"], shell=False,stdin=subprocess.PIPE , stdout=subprocess.PIPE ,stderr=subprocess.PIPE ,bufsize=1,close_fds=True)# ,universal_newlines=True)

# readlines() # read()
# child.poll() # Check if child is terminated # Return None if child process is not running # Return exiting code if child process is still running 
# child.wait() # wait for child 
# child.terminate() # terminate child , POSIX send signal SIGTERM
# child.kill()     #  kill child  POSIX send SIGKILL

#Use thread to tackle with blocking readline

def read_print_to_textBox(out):
    # while True : 
    for line in iter(out.readline, b''):
        print(line.decode())
    out.close()

t1 = threading.Thread(target=read_print_to_textBox, args=(child.stdout,))
t1.daemon = True # thread dies with the program
t1.start()
child.communicate(input=b"hi")

while True : 
    # do adult thing 
    child.stdin.write(b"hi")
    
    # child.stdin.flush()
    time.sleep(0.1)
