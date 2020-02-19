import posix_ipc
import time
mq = posix_ipc.MessageQueue('/elevator_ipc', posix_ipc.O_CREAT)
mq.send('elevator_cmd',priority=9)