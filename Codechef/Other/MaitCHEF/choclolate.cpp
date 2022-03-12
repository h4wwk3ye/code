//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 09/Nov/19 01:00:56 PM
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
		int z;
		cin >> z;
		string ans = "";
		dfr (i, 31, -1) {
			int c = (z >> i) & 1;
			if (c)
				ans += "1";
			else
				ans += "0";
		}

		string mn = "", mx = "1";
		int flag = 0;
		fr (i, 0, len (ans)) {
			if (!flag) {
				mn += "0";
				if (ans[i] == '1') {
					flag = 1;
					mx += "0";
				}
				continue;
			}
			if (ans[i] == '0') {
				mn += "1";
			} else
				mn += "0";
			mx += "0";
		}

		int i = std::stoll (mn, nullptr, 2);
		int j = std::stoll (mx, nullptr, 2);
		pr (i, j);
	}
	return 0;
}