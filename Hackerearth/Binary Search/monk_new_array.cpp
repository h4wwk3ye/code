/*
				C++
				encoding:UTF-8
				Modified: <19/Mar/2019 05:48:40 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define ve vector
#define pb push_back
#define umap unordered_map
#define pq priority_queue
#define endl "\n";
#define ff first
#define ss second
#define len(v) int(v.size ())
#define all(v) v.begin (), v.end ()
#define reset(a, b) memset (a, b, sizeof (a));
#define sum(v) accumulate (v.begin (), v.end (), (ll) 0);
#define pr1(x) cout << x << "\n"
#define pr2(x, y) cout << x << " " << y << "\n"
#define prv(v)              \
	for (auto& ijk : v)     \
		cout << ijk << " "; \
	cout << "\n"
#define fr(i, s, n) for (int i = s; i < n; i++)
#define dfr(i, s, n) for (int i = s; i > n; i--)

ll powermod (ll _a, ll _b, ll _m) {
	ll _r = 1;
	while (_b) {
		if (_b % 2 == 1) _r = (_r * _a) % _m;
		_b /= 2;
		_a = (_a * _a) % _m;
	}
	return _r;
}


int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int n, m;
	cin >> n >> m;
	int matrix[n][m];
	fr (i, 0, n) fr (j, 0, m) cin >> matrix[i][j];

	ve< int > x;
	int mn   = 1e9;
	int flag = 0;
	fr (i, 0, n - 1) {
		x.clear ();
		fr (j, 0, m) x.pb (matrix[i][j]);
		sort (all (x));
		fr (j, 0, m) {
			auto it1 = lower_bound (all (x), matrix[i + 1][j]);
			auto it2 = upper_bound (all (x), matrix[i + 1][j]);

			if (it2 != x.begin ()) it2--;

			mn = min (mn, abs (matrix[i + 1][j] - *it1));
			mn = min (mn, abs (matrix[i + 1][j] - *it2));
			if (mn == 0) {
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	pr1 (mn);

	return 0;
}
