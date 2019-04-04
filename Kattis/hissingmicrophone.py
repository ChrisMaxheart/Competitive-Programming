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

question = inp.read()


def hissing_for(question):
  is_hiss = False
  for i in range (len(question)-1):
    if (question[i] == question[i+1] and question[i] == "s"):
      is_hiss = True

  if is_hiss:
    return "hiss"
  else:
    return "no hiss"

def hissing_while(question):
  is_hiss = False
  position = 0
  while(position < len(question) - 1):
    if (question[position] == question[position+1] and question[position] == "s"):
      is_hiss = True
    position += 1

  if is_hiss:
    return "hiss"
  else:
    return "no hiss"


# just comment out one of this
# print(hissing_for(question))
print(hissing_while(question))