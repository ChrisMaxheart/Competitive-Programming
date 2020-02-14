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
    n = int(inp.read())
    p = int(inp.read())
    k = int(inp.read())

    lst = [0]
    for i in range(n):
        x = int(inp.read())
        lst.append(x)
    lst.append(k)

    ttl = 0

    for i in range(n+1):
        dur = lst[i+1] - lst[i]
        ttl += (dur * (((i * p) + 100) / 100))
    print(ttl)

if __name__ == '__main__':
    main()