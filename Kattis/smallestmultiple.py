import sys
from fractions import gcd
from functools import reduce
class SamInput(object):
  def __init__(self):
    self.inp = []
    for i in sys.stdin:
      i = i.replace("\n", "")
      j = list(i.split())
      self.inp.append(j)

  def readln(self):
    if (len(self.inp) == 0) :
      return False
    else:
      return str.join(" ", self.inp.pop(0))

  def read(self):
    if (len(self.inp) == 0):
      return False
    while (len(self.inp[0]) == 0):
      self.inp.pop(0)
      if (len(self.inp) == 0):
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
# 5) remember, all this function will return a string, need to convert to int or smt like that if you want to process as integer or others
# 6) if there is no more element/line, it will return False (boolean object)
# 

def gcd(a, b):
    if b == 0:
       return a
    else:
       return gcd(b, a % b)

def lcm(a, b):
    return (a * b)//gcd(a,b)

inp = SamInput()
while (True):
    x = inp.readln()
    if not x:
        break
    x = list(map(lambda y : int(y), x.split()))
    first = True
    y = 0
    for elem in x:
        if (first):
            first = False
            y = elem
        else:
            y = lcm(y, elem)
    print(int(y))

