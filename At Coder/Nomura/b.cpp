//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 30/May/20 05:45:35 PM
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
	string s;
	cin >> s;
	string ans;

	if (s[0] == '?') {
		if (len (s) > 1) {
			if (s[1] == 'D')
				ans += 'P';
			else if (s[1] == '?') {
				ans += 'P';
			} else {
				ans += 'D';
			}
		} else {
			ans += 'D';
		}
	} else {
		ans += s[0];
	}

	fr (i, 1, len (s)) {
		if (s[i] != '?') {
			ans += s[i];
		} else {
			if (ans.back () == 'P')
				ans += 'D';
			else {
				if (i + 1 < len (s)) {
					if (s[i + 1] == 'D' or s[i + 1] == '?') {
						ans += 'P';
					} else
						ans += 'D';
				} else {
					ans += 'D';
				}
			}
		}
	}
	pr (ans);
	return 0;
}