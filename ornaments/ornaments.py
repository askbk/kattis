import math
import sys

for i in sys.stdin:
    rhs = i.split();
    r = int(rhs[0]);
    h = int(rhs[1]);
    s = int(rhs[2]);
    if r == 0 and h == 0 and s == 0:
        sys.exit();
    s = 1 + s / 100;
    v = math.acos(r / h);
    print((2 * math.sqrt(h*h-r*r)+r*(math.pi-v))*s); 
                

