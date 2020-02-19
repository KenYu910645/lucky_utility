# https://docs.python.org/3/library/subprocess.html # document of subprocess
import subprocess
import time 
import sys
from subprocess import PIPE, Popen
import threading
from queue import Queue, Empty

child1 = subprocess.Popen(["python3 -u child1.py"], shell=True, stdout=subprocess.PIPE ,stderr=subprocess.PIPE ,bufsize=1,close_fds=True)# ,universal_newlines=True)
child2 = subprocess.Popen(["python3 -u child2.py"], shell=True, stdout=subprocess.PIPE ,stderr=subprocess.PIPE ,bufsize=1,close_fds=True)# ,universal_newlines=True)
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

t1 = threading.Thread(target=read_print_to_textBox, args=(child1.stdout,))
t1.daemon = True # thread dies with the program
t1.start()

t2 = threading.Thread(target=read_print_to_textBox, args=(child2.stdout,))
t2.daemon = True # thread dies with the program
t2.start()

while True : 
    # do adult thing 
    print ("Main thread")
    time.sleep(0.01)

# Use queue to implement non-blocking readline

'''
def enqueue_output(out, queue):
    for line in iter(out.readline, b''):
        queue.put(line)
    out.close()

q1 = Queue()
t = threading.Thread(target=enqueue_output, args=(child1.stdout, q1))
t.daemon = True # thread dies with the program
t.start()

q2 = Queue()
t = threading.Thread(target=enqueue_output, args=(child2.stdout, q2))
t.daemon = True # thread dies with the program
t.start()

# ... do other things here
while True : 
    # read line without blocking
    try:  
        line = q1.get_nowait() # or q.get(timeout=.1)
    except Empty:
        print('no output yet')
    else: # got line
        print ("[parent heard child1 says]" + line.decode())
    
    # read line without blocking
    try:  
        line = q2.get_nowait() # or q.get(timeout=.1)
    except Empty:
        print('no output yet')
    else: # got line
        print ("[parent heard child1 says]" + line.decode())
    time.sleep(0.1)
'''
'''
while True: 
    # doing adult things
    print ("im parent")
    c1_out = "".encode()
    #c2_out = "".encode()
    # check if child1 talk to me 
    print (child1.poll())
    if child1.poll() == None : # only get stdout if child is still alive 
        for line in iter(child1.stdout.readline, b''):
            print (line)
        pass 
    else: 
        print ("[Finish child]")
        break 
        # c1_out = child1.stdout.readline()# blocking ?
    # (c1_out,erroutput) = child1.communicate() # Blocking !! wait untill process end 
    # check if child2 talk to me 
    #if child2.poll() == None :# only get stdout if child is still alive 
    #    c2_out = child2.stdout.readline()# blocking ?
    
    print ("[parent heard child1 says]" + c1_out.decode())
    #print ("[parent heard child2 says]" + c2_out.decode())

    time.sleep(0.1)
'''



