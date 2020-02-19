import posix_ipc
import time
mq = posix_ipc.MessageQueue('/elevator_ipc', posix_ipc.O_CREAT)
print (mq.name)
while True:
    print (mq.receive())
