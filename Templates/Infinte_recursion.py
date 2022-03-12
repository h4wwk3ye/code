import sys
sys.setrecursionlimit(10**6)

# Codeforces
import threading
if __name__ == '__main__':
    threading.stack_size(10**8)
    t = threading.Thread(target=main)
    t.start()
    t.join()

# All other
import resource
resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))
