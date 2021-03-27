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

    def readint(self):
        return int(self.read())

def main():
    inp = SamInput()
    T = inp.readint()
    for i in range(T):
        N = inp.readint()
        C = inp.readint()
        sol = solution(N, C)
        ans = ' '.join(sol) if sol else 'IMPOSSIBLE'
        print(f'Case #{i+1}: {ans}')


def solution(N, C):
    min_cost = N - 1
    max_cost = ((N-1) * (2 + N)) / 2
    if C < min_cost or C > max_cost:
        return []
    ranges = []
    for max_curr_cost in range(N, 1, -1):
        remaining_switch_possible = max_curr_cost - 2
        found = False
        for cost in range(max_curr_cost, 1, -1):
            if C >= cost + remaining_switch_possible:
                C -= cost
                ranges.append(cost)
                found = True
                break
        if not found:
            C -= 1
            ranges.append(1)

    lst = []
    for i in range(N):
        lst.append(i+1)
    for idx, swap_range in enumerate(ranges[::-1]):
        current_pivot = N - 2 - idx
        to_flip = lst[current_pivot:current_pivot+swap_range]
        lst = lst[:current_pivot] + to_flip[::-1] + lst[current_pivot+swap_range:]

    return [str(x) for x in lst]


if __name__ == '__main__':
    main()