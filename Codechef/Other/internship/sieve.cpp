#include <bits/stdc++.h>
using namespace std;

// attribution: https://www.geeksforgeeks.org/segmented-sieve/

const int N = 2e6 + 5;
set< int > pr;

void sieve (int limit, vector< int >& prime) {
	vector< bool > mark (limit + 1, 1);

	for (int p = 2; p * p < limit; p++) {
		if (mark[p]) {
			for (int i = p * 2; i < limit; i += p)
				mark[i] = false;
		}
	}

	for (int p = 2; p < limit; p++) {
		if (mark[p] == true) {
			prime.push_back (p);
			pr.insert (p);
		}
	}
}

void segmentedSieve () {
	int limit = floor (sqrt (N)) + 1;
	vector< int > prime;

	sieve (limit, prime);

	int low = limit;
	int high = 2 * limit;

	while (low < N) {
		if (high >= N) high = N;
		vector< bool > mark (limit + 1, 1);

		for (int i = 0; i < prime.size (); i++) {
			int loLim = floor (low / prime[i]) * prime[i];
			if (loLim < low) loLim += prime[i];

			for (int j = loLim; j < high; j += prime[i])
				mark[j - low] = false;
		}

		for (int i = low; i < high; i++)
			if (mark[i - low] == true) {
				pr.insert (i);
			}

		low = low + limit;
		high = high + limit;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	segmentedSieve ();
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
				if (pr.find (x) != pr.end ()) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}