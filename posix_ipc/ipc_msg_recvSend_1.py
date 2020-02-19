#document of posix_ipc
#  http://semanchuk.com/philip/posix_ipc/
import posix_ipc
import time 

mq_send = posix_ipc.MessageQueue('/1_send_2', posix_ipc.O_CREAT)
mq_send.block = False # non-blocking recv , send
mq_recv = posix_ipc.MessageQueue('/2_send_1', posix_ipc.O_CREAT)
mq_recv.block = False # non-blocking recv , send
# print (mq.name)
while True:
    #-------- Send ---------# 
    try:
        mq_send.send('elevator_cmd',priority=9)
    except posix_ipc.BusyError:
        print ("queue full")
    else: # successfully send 
        pass 
    #-------- Receive ---------# 
    try:
        r = mq_recv.receive() # r = (message , priority)
    except posix_ipc.BusyError:
        print ("queue empty")
    else:
        print (r)
    time.sleep(0.01)
mq_send.close()
mq_recv.close()
