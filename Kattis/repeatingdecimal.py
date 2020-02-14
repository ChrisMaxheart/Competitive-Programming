import sys
from decimal import *
class SamInput(object):
    def __init__(self):
        self.inp = []
        for i in sys.stdin:
            i = i.replace("\n", "")
            j = list(i.split())
            self.inp.append(j)

    def readln(self):
        if len(self.inp) == 0:
            return False
        else:
            return str.join(" ", self.inp.pop(0))

    def read(self):
        if len(self.inp) == 0:
            return False
        while len(self.inp[0]) == 0:
            self.inp.pop(0)
            if len(self.inp) == 0:
                return False
        return self.inp[0].pop(0)

def main():
    inp = SamInput()
    while(True):
        a = inp.read()
        if a == False:
            break
        getcontext().prec = 10000
        a = Decimal(a)
        b = Decimal(inp.read())
        c = int(inp.read())

        val = (a/b)
        
        # print(val)
        val = str(val)
        val = val[:c+2]
        # print(val)

        lngt = len(val)
        # print(val)
        if (len(val) < c+2):
            val += ("0" * (c+2 - lngt))
        print(val)

if __name__ == '__main__':
    main()