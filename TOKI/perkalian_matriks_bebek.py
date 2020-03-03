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


MOD = 26101991
catalan_memo = {}
row = []
col = []
kali_memo = {}


def solve(l, r):
    if l == r:
        return 0
    if (l, r) not in kali_memo:
        best = 1000000000000000
        for i in range(l, r):
            curr = solve(l, i) + solve(i+1, r) + row[l] * col[i] * col[r]
            best = min(best, curr)
        kali_memo[(l, r)] = best
    return kali_memo[(l, r)]


def catalan(n):
    if n <= 1:
        return 1
    if n not in catalan_memo:
        res = 0
        for i in range(n):
            res += (catalan(i) * catalan(n - i - 1))
            res %= MOD
        catalan_memo[n] = res
    return catalan_memo[n]


def main():
    inp = SamInput()

    lst = []
    N = int(inp.read())
    for i in range(N+1):
        x = int(inp.read())
        lst.append(x)

    for i in range(N):
        row.append(lst[i])
        col.append(lst[i+1])

    q = int(inp.read())
    if q == 1:
        print(solve(0, N-1))
    elif q == 2:
        counta = 1
        for i in range(1, N):
            if row[0] == row[i] and col[0] == col[i]:
                counta += 1
            else:
                break
        print(catalan(counta - 1))
    else:
        print(catalan(N - 1))


if __name__ == '__main__':
    main()
