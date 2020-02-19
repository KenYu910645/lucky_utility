import os 
import mmap
import time
import posix_ipc
size = os.statvfs('.')[1]
mem = posix_ipc.SharedMemory('/foo', posix_ipc.O_CREAT,size=size)
f = mmap.mmap(mem.fd, size)
i = 0
while i<20:
    seconds = int(time.time())
    
    f[:10] = (str(seconds).encode())
    time.sleep(2)
    i += 1
f.close()
mem.close_fd()
mem.unlink()