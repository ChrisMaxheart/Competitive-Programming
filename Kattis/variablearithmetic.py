# mistake
import sys
for i in sys.stdin:
  if (len(i) == 1 and i == '0'):
    continue
  else:
    print(eval(i))