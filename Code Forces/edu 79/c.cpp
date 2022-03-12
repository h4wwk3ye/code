//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 27/Dec/19 09:07:13 PM
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

const int N = 1e5 + 5;
int a[N], b[N], vis[N];
int n, m;


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		fr (i, 1, n + 1) {
			vis[i] = 0;
			cin >> a[i];
		}
		fr (i, 1, m + 1) cin >> b[i];

		int i = 1, j = 1;
		int ans = 0;
		while (i <= m) {
			if (vis[b[i]]) {
				ans++;
				i++;
			} else {
				// int j = 0;
				while (j <= n and b[i] != a[j]) {
					vis[a[j]] = 1;
					j++;
				}
				ans += 2 * (j - i) + 1;
				i++;
			}
		}
		pr (ans);
	}

	return 0;
}