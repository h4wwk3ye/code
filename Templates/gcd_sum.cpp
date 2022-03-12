const int N = 1e6 + 5;
int phi[N], F[N];
void precompute () {
	fr (i, 1, N) {
		phi[i] += i;
		for (int j = 2 * i; j < N; j += i) {
			phi[j] -= phi[i];
		}
	}
	fr (i, 1, N) {
		for (int j = i; j < N; j += i) {
			F[j] += j / i * phi[i];
			F[j] %= mod;
		}
	}
}
