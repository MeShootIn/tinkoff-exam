#include <stdio.h>
//#include <time.h>
#include <math.h>
#include <algorithm>



bool check(double * A, int N, int K, double len) {
	for (int i = 0; i < N; ++i) {
		if (A[i] > len) {
			int k = (int) ceil(A[i] / len - 1.0);

			if (K < k) {
				return false;
			}

			K -= k;
		}
	}

	return true;
}

double getMinLen(double * A, int N, int K) {
	double l = 0.0, r = *(std::max_element(A, A + N));
	double const EPS = 1e-10;

	while (r - l > EPS) {
		double m = (l + r) / 2.0;

		if (check(A, N, K, m)) {
			r = m;
		}
		else {
			l = m;
		}
	}

	return (l + r) / 2.0;
}



int main() {
	// TIME START
	//double start = clock();
	//

	// BOOST
        setvbuf(stdin, (char*) calloc(1 << 20, sizeof(char)), _IOFBF, 1 << 20);
        setvbuf(stdout, (char*) calloc(1 << 20, sizeof(char)), _IOFBF, 1 << 20);
        //

	int N, K;

	scanf("%d%d", &N, &K);

	double A[N];

	for (int i = 0; i < N; ++i) {
		scanf("%lf", &A[i]);
	}

	printf("%d", (int) ceil(getMinLen(A, N, K)));

	/*
	//
	printf("\n");
	//

	// TIME END
	double time = (clock() - start) / CLOCKS_PER_SEC;
	printf("%lf", time);

	//
	printf("\n");
	//
	*/

	return 0;
}
