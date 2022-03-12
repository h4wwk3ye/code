//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 16/Mar/20 07:01:31 PM
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
	int u, v;
	cin >> u >> v;
	string x, y;
	dfr (i, 62, -1) {
		int curr_bit = (v >> i) & 1;
		x += (curr_bit + '0');
		int c = (u >> i) & 1;
		y += (c + '0');
	}
	ve< int > p;
	bool flag;
	fr (i, 0, 63) {
		if (x[i] == '0' and y[i] == '0') continue;
		if (x[i] == '1' and y[i] == '0') {
			p.pb (i + 1);
		} else if (x[i] == '0' and y[i] == '1') {
			p.pb (i + 1);
		}
	}


	return 0;
}
