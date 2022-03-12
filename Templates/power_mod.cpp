int power (int a, int b, int m) {
	int r = 1;
	while (b) {
		if (b & 1) r = (r * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return r;
}
