import sys

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

  def read_int(self):
    dummy = self.read()
    if (dummy and dummy.isdigit()):
      return int(dummy)
    else:
      return False

inp = SamInput()
a = int(inp.read())
b = int(inp.read())
print(a+b)
