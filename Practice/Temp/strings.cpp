#include <bits/stdc++.h>

using namespace std;

int ch[101][101];
int choose (int n, int k) {
	if (n < 0 || k < 0 || k > n) return 0;
	if (!k || n == k) return 1;
	if (ch[n][k]) return ch[n][k];
	return ch[n][k] = choose (n - 1, k - 1) + choose (n - 1, k);
}

int nthkset (int N, int n, int k) {
	if (!n) return (1 << k) - 1;
	if (choose (N - 1, k - 1) > n) return 1 | (nthkset (N - 1, n, k - 1) << 1);
	return nthkset (N - 1, n - choose (N - 1, k - 1), k) << 1;
}

int nthset (int N, int n) {
	for (int k = 0; k <= N; k++)
		if (choose (N, k) > n)
			return nthkset (N, n, k);
		else
			n -= choose (N, k);
	return -1;
}

int main () {
	int n, r;
	cin >> n >> r;

	string d;
	cin >> d;
	stringstream ss (d);
	vector< string > inp;
	while (ss.good ()) {
		string s;
		getline (ss, s, ',');
		inp.push_back (s);
	}

	if (r == 1) {
		cout << "\n";
		return 0;
	}

	int a = nthset (n, r - 1);
	vector< string > ans;
	for (int i = 0; i < n; i++) {
		int x = !!(a & 1 << i);
		if (x) {
			ans.push_back (inp[i]);
		}
	}
	for (int i = 0; i < ans.size () - 1; ++i) {
		cout << ans[i] << ',';
	}
	if (!ans.empty ()) cout << ans.back ();
	cout << "\n";
}