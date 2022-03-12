//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 16/Feb/20 05:36:53 PM
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
	int n;
	cin >> n;
	bool flag = 0;
	fr (i, 0, n) {
		int x;
		cin >> x;
		if (x % 2 == 0) {
			if (x % 3 == 0 or x % 5 == 0)
				continue;
			else
				flag = 1;
		}
	}
	if (flag) {
		pr ("DENIED");
	} else {
		pr ("APPROVED");
	}

	return 0;
}