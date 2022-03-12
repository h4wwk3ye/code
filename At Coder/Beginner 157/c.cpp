//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 01/Mar/20 05:52:46 PM
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
	int n, m;
	cin >> n >> m;
	string x;
	fr (i, 0, n) x += '.';
	bool flag = 1;
	while (m--) {
		int s, c;
		cin >> s >> c;
		if (x[s - 1] == '.') {
			x[s - 1] = c + '0';
		} else {
			if (x[s - 1] != c + '0') flag = 0;
		}
	}
	if (!flag) {
		pr (-1);
		return 0;
	}
	fr (i, 0, n) if (x[i] == '.') {
		if (i == 0 and n != 1)
			x[i] = '1';
		else
			x[i] = '0';
	}

	if (n != 1 and x[0] == '0') x = "-1";
	pr (x);
	return 0;
}