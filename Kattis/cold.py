def function(n, tpl):
  counter = 0
  for i in tpl:
    if i < 0:
      counter += 1
  return counter

n = int(input())
tpl = ()
tpl = tuple(map(int,input().split()))
print(function(n, tpl))