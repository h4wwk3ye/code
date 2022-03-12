#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif
using namespace std;

const int N = 5e6 + 5; // a[i] <= 1e6 so 5 * a[i] just for safety
vector< int > prime (N, 1);

void sieve () {
	prime[0] = prime[1] = 1;
	for (int i = 2; i * i < N; ++i) {
		if (prime[i]) {
			for (int j = 2 * i; j < N; j += i) {
				prime[j] = 0;
			}
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	sieve ();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x = arr[i] + arr[j];
				if (prime[x]) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}