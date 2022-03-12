//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 22/Mar/20 10:57:06 AM
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
	fr (i, 1, tc + 1) {
		cout << "Case #" << i << ": ";
		int n, k;
		cin >> n >> k;
		int arr[n];
		fr (i, 0, n) cin >> arr[i];
		int mx = 0, mx2 = 0;
		fr (i, 0, n - 1) {
			if (arr[i + 1] - arr[i] > mx) {
				mx2 = mx;
				mx = arr[i + 1] - arr[i];
			} else if (arr[i + 1] - arr[i] > mx2) {
				mx2 = arr[i + 1] - arr[i];
			}
		}
		int x = ceil (mx / (2 * 1.0));
		pr (max (x, mx2));
	}
	return 0;
}