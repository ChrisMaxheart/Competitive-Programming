import sys
import random

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
    T = int(inp.read())
    for i in range(T):
        N = int(inp.read())
        while True:
            rand1 = random.randint(1, N//2)
            if '4' in str(rand1):
                continue
            rand2 = N - rand1
            if '4' in str(rand2):
                continue
            print("Case #" + str(i+1) + ":", rand1, rand2)
            break

if __name__ == '__main__':
    main()