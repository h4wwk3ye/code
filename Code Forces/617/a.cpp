//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Feb/20 08:07:26 PM
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
		int arr[n];
		bool even = 0, odd = 0;
		int t = 0;
		fr (i, 0, n) {
			cin >> arr[i];
			t += arr[i];
			if (arr[i] % 2 == 0)
				even = 1;
			else
				odd = 1;
		}
		if (t % 2 == 1) {
			pr ("YES");
			continue;
		}
		if (even and odd)
			pr ("YES");
		else
			pr ("NO");
	}
	return 0;
}