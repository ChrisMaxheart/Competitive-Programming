import sys

# input
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


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

# How to use:
# 1) copy line 1-25
# 2) declare variable as SamInput()
# Ex: test = SamInput()
# 3) to read one line, use readln
# Ex: newline = test.readln()
# 4) to read one element(splitted by empty line / whitespace), use read
# Ex: newline = test.read()
# 5) remember, all this function will return a string, need to convert to int
# 6) if there is no more element/line, it will return False (boolean object)

def main():
    inp = SamInput()
    n = int(inp.read())
    bil = 1
    ggccdd = -1
    mdl = 1000000000 + 7
    for i in range(n):
        x = int(inp.read())
        bil *= x
        bil %= mdl
        if ggccdd == -1:
            ggccdd = x
        else:
            ggccdd = gcd(ggccdd, x)
        ggccdd %= mdl
    bil *= ggccdd
    bil %= mdl
    print(bil)


if __name__ == '__main__':
    main()