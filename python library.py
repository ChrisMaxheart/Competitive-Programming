# Fenwick, 1-indexed
from __future__ import division

class FenwickTree:
    def __init__(self, n):
        self.sz = n
        self.vals = [0] * (n + 1)

    def update(self, idx, delta):
        "add c to the value at index idx"
        while idx < self.sz:
            self.vals[idx] += delta
            idx += idx & (-idx)

    def accumulate(self, idx):
        "get sum from the start to the index of idx "
        ret = 0
        while idx > 0:
            ret += self.vals[idx]
            idx -= idx & (-idx)
        return ret

    def rsq(self, start, end):
        "Calculate a[start], a[start+1], ... a[end]"
        return self.accumulate(end) - self.accumulate(start - 1)

class RURQFenwickTree:

    def __init__(self, n):
        self.sz = n
        self.fta = FenwickTree(n)
        self.ftb = FenwickTree(n)

    def update(self, l, r, v):
        self.fta.update(l, v)
        self.fta.update(r+1, -v)
        self.ftb.update(l, (l-1)*v)
        self.ftb.update(r+1, -r*v)

    def accumulate(self, idx):
        return self.fta.accumulate(idx) * idx - self.ftb.accumulate(idx)

    def rsq(self, start, end):
        return self.accumulate(end) - self.accumulate(start - 1)


# segment tree 
class SegmentTree(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.max_value = {}
        self.sum_value = {}
        self.len_value = {}
        self._init(start, end)

    def add(self, start, end, weight=1):
        start = max(start, self.start)
        end = min(end, self.end)
        self._add(start, end, weight, self.start, self.end)
        return True

    def query_max(self, start, end):
        return self._query_max(start, end, self.start, self.end)

    def query_sum(self, start, end):
        return self._query_sum(start, end, self.start, self.end)

    def query_len(self, start, end):
        return self._query_len(start, end, self.start, self.end)

    """"""
    def _init(self, start, end):
        self.max_value[(start, end)] = 0
        self.sum_value[(start, end)] = 0
        self.len_value[(start, end)] = 0
        if start < end:
            mid = start + int((end - start) / 2)
            self._init(start, mid)
            self._init(mid+1, end)

    def _add(self, start, end, weight, in_start, in_end):
        key = (in_start, in_end)
        if in_start == in_end:
            self.max_value[key] += weight
            self.sum_value[key] += weight
            self.len_value[key] = 1 if self.sum_value[key] > 0 else 0
            return

        mid = in_start + int((in_end - in_start) / 2)
        if mid >= end:
            self._add(start, end, weight, in_start, mid)
        elif mid+1 <= start:
            self._add(start, end, weight, mid+1, in_end)
        else:
            self._add(start, mid, weight, in_start, mid)
            self._add(mid+1, end, weight, mid+1, in_end)
        self.max_value[key] = max(self.max_value[(in_start, mid)], self.max_value[(mid+1, in_end)])
        self.sum_value[key] = self.sum_value[(in_start, mid)] + self.sum_value[(mid+1, in_end)]
        self.len_value[key] = self.len_value[(in_start, mid)] + self.len_value[(mid+1, in_end)]

    def _query_max(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.max_value[(start, end)]
        else:
            mid = in_start + int((in_end - in_start) / 2)
            if mid >= end:
                ans = self._query_max(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_max(start, end, mid+1, in_end)
            else:
                ans = max(self._query_max(start, mid, in_start, mid),
                        self._query_max(mid+1, end, mid+1, in_end))
        #print start, end, in_start, in_end, ans
        return ans

    def _query_sum(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.sum_value[(start, end)]
        else:
            mid = in_start + int((in_end - in_start) / 2)
            if mid >= end:
                ans = self._query_sum(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_sum(start, end, mid+1, in_end)
            else:
                ans = self._query_sum(start, mid, in_start, mid) + self._query_sum(mid+1, end, mid+1, in_end)
        return ans

    def _query_len(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.len_value[(start, end)]
        else:
            mid = in_start + int((in_end - in_start) / 2)
            if mid >= end:
                ans = self._query_len(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_len(start, end, mid+1, in_end)
            else:
                ans = self._query_len(start, mid, in_start, mid) + self._query_len(mid+1, end, mid+1, in_end)

        #print start, end, in_start, in_end, ans
        return ans

 # extra stuff
def remove_exponent(d):
    return d.quantize(Decimal(1)) if d == d.to_integral() else d.normalize()