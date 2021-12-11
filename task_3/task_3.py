import math

def f(arr, K, l):
	for a in arr:
		if a > l:
			k = int(math.ceil(a / l) - 1)

			if K - k < 0:
				return False

			K -= k

	return True

n, k = list(map(int,input().split()))
a = list(map(float,input().split()))
ans = None

l, r = 0, max(a)
E = 1e-7

while r - l > E:
	ans = (l + r) / 2

	if f(a, k, ans):
		r = ans
	else:
		l = ans

ans = int(math.ceil(ans))
print(ans)
