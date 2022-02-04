#include <stdio.h>
//#include <time.h>
#include <string.h>
#include <malloc.h>
#include <vector>
#include <set>
//#include <list>

#define MOD 998244353



int main() {
	// BOOST
	setvbuf(stdin, (char*) calloc(1 << 20, sizeof(char)), _IOFBF, 1 << 20);
	setvbuf(stdout, (char*) calloc(1 << 20, sizeof(char)), _IOFBF, 1 << 20);
	//

	// TIME START
	//double start = clock();
	//

	int N, M, K;

	scanf("%d%d%d", &N, &M, &K);

	std::vector<std::set<int>> g(N);

	for (int u = 0; u < N; ++u) {
		for (int v = 0; v < N; ++v) {
			if (u != v) {
				g[u].insert(v);
			}
		}
	}

	//std::vector<std::list<int>> removed(N);

	for (int m = 0; m < M; ++m) {
		int U, V;

		scanf("%d%d", &U, &V);

		--U;
		--V;

		/*removed[U].push_back(V);
		removed[V].push_back(U);*/
		g[U].erase(V);
		g[V].erase(U);
	}

	//unsigned long long sum_dp_prev = 1;
	int dp[2][N];
	int dp_k = 0;

	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;

	for (int k = 1; k <= K; ++k) {
		dp_k = 1 - dp_k;
		//unsigned long long sum_dp_cur = 0;

		for (int v = 0; v < N; ++v) {
			if (k == K && v != 0) {
				break;
			}

			dp[dp_k][v] = 0;

			/*unsigned long long sum = sum_dp_prev - dp[1 - dp_k][v];

			for (int const& u : removed[v]) {
				sum -= dp[1 - dp_k][u];
			}

			sum_dp_cur += sum;
			dp[dp_k][v] = sum % MOD;*/

			for (int const& u : g[v]) {
				dp[dp_k][v] += dp[1 - dp_k][u] % MOD;
				dp[dp_k][v] %= MOD;
			}
		}

		//sum_dp_prev = sum_dp_cur;
	}

	printf("%d", dp[dp_k][0]);

	//
	//printf("\n");
	//

	// TIME END
        /*double time = (clock() - start) / CLOCKS_PER_SEC;
        printf("%lf", time);*/

	//
	//printf("\n");
	//

	return 0;
}