//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 14/May/20 08:14:37 PM
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
		int n, k;
		cin >> n >> k;
		int a[n], b[n];
		fr (i, 0, n) cin >> a[i];
		fr (i, 0, n) cin >> b[i];
		sort (a, a + n);
		sort (b, b + n);
		int i = 0, j = n - 1;
		while (i < n and j >= 0 and k) {
			if (a[i] < b[j]) {
				a[i] = b[j];
				k--;
				i++;
				j--;
			} else
				break;
		}
		pr (accumulate (a, a + n, 0));
	}
	return 0;
}