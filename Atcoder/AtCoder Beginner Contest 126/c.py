import sys

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
    N = int(inp.read())
    K = int(inp.read())

    ttl = 0

    for i in range(N):
        dc = i + 1
        ctr = 0
        while dc < K:
            ctr += 1
            dc *= 2
        ttl += (1/N * (0.5**ctr))

    print(ttl)

    # print( (1/6) * (0.5**K + 0.5 ** (K/2) + 0.5 ** (K/3) + 0.5**(K/4) + 0.5 ** (K/5) + 0.5 ** (K/6)))

if __name__ == '__main__':
    main()