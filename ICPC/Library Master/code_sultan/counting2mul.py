dp_size = 3;

# initialize dp table
dp = []
temp = 0
for times in range(3):
  dp = []
  for i in range(dp_size):
    dp.append(temp)
  temp = dp

print(dp)