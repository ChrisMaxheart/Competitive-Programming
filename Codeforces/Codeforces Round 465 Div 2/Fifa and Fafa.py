from math import *
import sys

R, x2, y2, x1, y1 = map(int,sys.stdin.readline().split())

dist = sqrt((x1-x2)**2 + (y1-y2)**2)

radi = 0.5 * (dist+R)

if (x1 != x2) or (y1 != y2):
  xnew = radi * (x2-x1) / dist
  xnew += x1
  ynew = radi * (y2-y1) / dist
  ynew += y1
else:
  xnew = x1+radi
  ynew = y1+radi

if (dist >= R):
  xnew = x2
  ynew = y2
  radi = R

print(xnew, ynew, radi)
# print('test')

