#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Nov/19 10:43:35 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

// ve< ve< int > > arr;
int n;
// int dp[5005][10005];

// int solve (int i, int j) {
// 	if (j > 10000) return -1e9;
// 	if (i >= n) return 0;
// 	int& ans = dp[i][j];
// 	if (ans != -1) return ans;
// 	ans = 0;
// 	ans = max (1 + solve (i + 1, j + (arr[i][0] + arr[i][1] + arr[i][2])), solve (i + 1, j));
// 	return ans;
// }


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		// arr.clear ();
		// arr.resize (n);
		ve< int > arr[n];
		// reset (dp, -1);
		ve< int > m;
		fr (i, 0, n) {
			int x, y, z;
			cin >> x >> y >> z;
			arr[i] = {x, y, z};
			m.pb (y);
		}
		sort (arr, arr + n);
		int a[n], b[n], c[n];
		fr (i, 0, n) {
			a[i] = arr[i][0];
			b[i] = arr[i][1];
			c[i] = arr[i][2];
		}
		int low = 0, high = 10000;
		int ans = 0;
		fr (p, 0, n) {
			int i = arr[p][0];
			for (auto& j : m) {
				if (i + j > 10000) break;
				int k = 10000 - i - j;
				int idx = lower_bound (a, a + n, i) - a;
				pr (idx);
				idx = lower_bound (b, b + idx, j) - b;
				pr (idx);
				idx = lower_bound (c, c + idx, k) - c;
				pr (idx);
				ans = max (ans, n - idx);
			}
		}
		pr (ans + 1);
	}
	return 0;
}
