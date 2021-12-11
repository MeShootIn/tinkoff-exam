#include <stdio.h>

int * tmp;

void rec(int i, int n, int s){
    if(s == n && i != 2){
	
        for(int i = 0; i <= n; ++i) {
		if ()
	}
    }

    if(s < n){
        for(int j = tmp[i - 1]; j <= n; j++){
            tmp[i] = j;

            rec(i + 1, n, s + j);
        }
    }
}

int main() {
	int N, M;

	scanf("%d%d", &N, &M);

	tmp = new int[N];

	for(int i = 0; i <= N; i++){
		tmp[i] = 1;
	}

	rec(1, N, 0);

	delete [] tmp;
	tmp = nullptr;

	return 0;
}
