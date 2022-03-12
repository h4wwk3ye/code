void multiply (int F[][2], int M[][2]) {
	int x = (((F[0][0] % mod * M[0][0] % mod) % mod) + ((F[0][1] % mod * M[1][0] % mod) % mod)) % mod;
	int y = (((F[0][0] % mod * M[0][1] % mod) % mod) + ((F[0][1] % mod * M[1][1] % mod) % mod)) % mod;
	int z = (((F[1][0] % mod * M[0][0] % mod) % mod) + ((F[1][1] % mod * M[1][0] % mod) % mod)) % mod;
	int w = (((F[1][0] % mod * M[0][1] % mod) % mod) + ((F[1][1] % mod * M[1][1] % mod) % mod)) % mod;
	F[0][0] = x, F[0][1] = y, F[1][0] = z, F[1][1] = w;
}

void power (int matrix[2][2], int n) {
	if (n == 0 || n == 1) return;
	int res[2][2] = {{1, 1}, {1, 0}};
	power (matrix, n / 2);
	multiply (matrix, matrix);
	if (n & 1) multiply (matrix, res);
}

int fib (int n) {
	int matrix[2][2] = {{1, 1}, {1, 0}};
	power (matrix, n - 1);
	return matrix[0][0];
}
