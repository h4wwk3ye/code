//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 23/Feb/20 12:27:59 PM
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
		string s;
		cin >> s;
		string a, b;
		int f = 0;
		fr (i, 0, n) {
			if (f) {
				a += '1';
				b += '0';
			} else {
				a += '0';
				b += '1';
			}
			f = 1 ^ f;
		}
		int curr = 0;
		fr (i, 0, n) if (s[i] != a[i]) curr++;

		int ans = curr;
		curr = 0;
		fr (i, 0, n) if (s[i] != b[i]) curr++;
		ans = min (ans, curr);
		pr (ans);
	}
	return 0;
}