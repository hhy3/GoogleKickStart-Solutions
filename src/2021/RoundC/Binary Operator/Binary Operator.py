from collections import defaultdict
from functools import lru_cache
import random


@lru_cache(None)
def f(x, y):
  return random.randint(0, 2 ** 64 - 1)

op = "+*#"
def parse(exp):
  if exp[0] != '(':
    return int(exp)
  cnt = 0
  n = len(exp)
  for i in range(1, n - 1):
    if exp[i] == '(': 
      cnt += 1
    elif exp[i] == ')':
      cnt -= 1
    if cnt == 0 and exp[i] in op:
      x = parse(exp[1 : i])
      y = parse(exp[i + 1 : n - 1])
      if exp[i] == '+':
        return x + y
      if exp[i] == '*':
        return x * y
      if exp[i] == '#':
        z = f(x, y)
        return z

def solve(caseNum):
  print(f"Case #{caseNum}: ", end="")
  mp = defaultdict(int)
  n = int(input())
  lst = []
  exp2val = defaultdict(int)
  for i in range(n):
    exp = input()
    lst.append(exp)
    exp2val[exp] = parse(exp)

  ans = [0 for _ in range(n)]
  tot = 0
  for exp in lst:
    tup = exp2val[exp]
    if tup not in mp:
      tot += 1
      mp[tup] = tot
    print(mp[tup], end=" ")
  print()

t = int(input())
for i in range(t): 
  solve(i + 1)