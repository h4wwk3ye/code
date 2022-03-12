//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 10/Apr/20 08:23:05 PM
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
		int n, x;
		cin >> n >> x;
		ve< int > arr (n);
		fr (i, 0, n) cin >> arr[i];
		sort (all (arr), greater<> ());

		int idx = -1;
		int s = 0;
		fr (i, 0, n) {
			if (arr[i] >= x) {
				idx = i;
				s += arr[i];
			} else
				break;
		}
		if (idx == -1) {
			pr (0);
			continue;
		}

		while (idx + 1 < n) {
			if ((s + arr[idx + 1]) / (idx + 2) >= x) {
				s += arr[idx + 1];
				idx++;
			} else {
				break;
			}
		}
		pr (idx + 1);
	}
	return 0;
}