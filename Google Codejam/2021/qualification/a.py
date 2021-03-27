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
    T = int(inp.read())
    for tc in range(T):
        lst = []
        N = int(inp.read())
        for _ in range(N):
            lst.append(int(inp.read()))
        ans = solution(N, lst)
        print(f'Case #{tc+1}: {ans}')

def solution(N, lst):
    cpylst = lst[:]
    ttl = 0
    for i in range(len(cpylst) - 1):
        elem = min(cpylst[i:len(cpylst)])
        idx = cpylst.index(elem, i)
        to_reverse = cpylst[i:idx+1]
        ttl += len(to_reverse)
        cpylst = cpylst[:i] + to_reverse[::-1] + cpylst[idx+1:]
    return ttl


if __name__ == '__main__':
    main()