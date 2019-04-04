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


inp = input()
inp = inp.replace(";", ",");
inp = inp.split(",")

lst = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

theint = []
thestr = []

for elem in inp:
  if (len(elem) > 0):
    if (elem[0] == '0' and len(elem) > 1):
      thestr.append(elem)
    else:
      catet = True
      for char in elem:
        if char not in lst:
          thestr.append(elem)
          catet = False
          break
      if catet:
        theint.append(elem)
  else:
    thestr.append("")

lastint = ""
laststr = ""

start = True

for i in theint:
  if (not start):
    lastint += ","
  lastint += i
  start = False

start = True

for i in thestr:
  if (not start):
    laststr += ","
  laststr += i
  start = False

if (len(lastint) == 0):
  print("-")
else:
  print("\"" + lastint + "\"")

if (len(laststr) == 0):
  print("-")
else:
  print("\"" + laststr + "\"")