//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/May/20 07:40:33 PM
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


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int arr[n][n];
		fr (i, 0, n) {
			string s;
			cin >> s;
			fr (j, 0, n) {
				arr[i][j] = s[j] - '0';
			}
		}
		// if its 1 either below or on right every cell should be 1
		bool ans = 1;
		fr (i, 0, n) {
			fr (j, 0, n) {
				if (arr[i][j]) {
					if (i == n - 1 or j == n - 1) continue;
					if (arr[i + 1][j] or arr[i][j + 1]) continue;
					ans = 0;
				}
			}
		}
		pr (ans ? "YES" : "NO");
	}
	return 0;
}