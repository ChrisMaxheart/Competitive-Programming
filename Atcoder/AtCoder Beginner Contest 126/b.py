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
    x = inp.read()

    p1 = int(x[:2])
    p2 = int(x[2:])

    posdm = True
    posmd = True

    if p1 < 1 or p1 > 12:
        posmd = False

    if p2 < 1 or p2 > 12:
        posdm = False

    if posdm and posmd:
        print("AMBIGUOUS")
    elif (not posdm) and (not posmd):
        print("NA")
    elif posdm:
        print("YYMM")
    else:
        print("MMYY")


if __name__ == '__main__':
    main()