//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Nov/19 07:19:07 PM
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
		int n, m, s;
		cin >> n >> m >> s;
		ve< int > arr (n);
		fr (i, 0, n) cin >> arr[i];
		sort (all (arr));
		int ans = 0;
		int i = 0, j = 0;
		while (i < m) {
			if (j >= n) break;
			if (arr[j] <= s) {
				j++;
				ans++;
				i++;
			} else if (2 * s >= arr[j] and i + 1 < m) {
				ans++;
				j++;
				i += 2;
			} else
				break;
		}
		pr (ans);
	}
	return 0;
}