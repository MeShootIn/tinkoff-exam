def scanStrs():
	return input().split()

def scanInts():
	return [int(s) for s in scanStrs()]

def getMinDist(K, N, A):
	minDist = K

	for i in range(N):
		if i == N - 1:
			space = K - A[N - 1] + A[0]
		else:
			space = A[i + 1] - A[i]

		minDist = min(K - space, minDist)

	return minDist



if __name__ == '__main__':
	K, N = scanInts()
	A = scanInts()

	print(getMinDist(K, N, A))
