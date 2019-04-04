def fast_exp(base, pangkat):
  if (pangkat == 1):
    return base
  elif (pangkat == 0):
    return 1
  elif (pangkat%2):
    return fast_exp(base, pangkat-1) * base
  else:
    return (fast_exp(base,pangkat//2))**2

x, y = map(int, input().split())
kiri = y
kanan = x
# kiri = fast_exp(x,y)
# kanan = fast_exp(y,x)
# print(kiri)
# print(kanan)
if (kiri == kanan):
  print('=')
elif (kiri > kanan):
  print('>')
else:
  print('<')