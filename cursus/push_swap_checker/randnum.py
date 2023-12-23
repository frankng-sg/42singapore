import random
import sys

N = 100
MAXVAL = 1000000
MINVAL = -1000000

if len(sys.argv) > 1:
    N = int(sys.argv[1])
if len(sys.argv) > 3:
    MINVAL = int(sys.argv[2])
    MAXVAL = int(sys.argv[3])

Output = f"rand{N}.txt"

nums = []
seen = dict()

while len(nums) < N:
    num = random.randint(MINVAL, MAXVAL)
    if num not in seen:
        seen[num] = True
        nums.append(num)

with open(Output, "w") as f:
   f.write(" ".join(str(i) for i in nums))

print("OK")
