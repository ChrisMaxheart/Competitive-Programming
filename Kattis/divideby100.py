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

inp = SamInput()
N = inp.read()
M = inp.read()

counter = 0

for num in M:
    if num == '0':
        counter += 1

sebelumnol = 0 - len(N) + 1 + counter

ans = ""

if sebelumnol > 0:
    ans += "0."
    sebelumnol -= 1
    for i in range(sebelumnol):
        ans += '0'
    ans += N
elif counter == 0:
    ans = N
else:
    buang = 0
    ans = N[:-counter] + '.' + N[-counter:]
    for i in range(1,counter+2):
        if ans[-i] == '0' or ans[-i] == '.':
            buang += 1
        else:
            break
    if buang != 0:
        ans = ans[:-buang]

print(ans)
