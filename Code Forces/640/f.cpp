//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 09/May/20 09:23:49 PM
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
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;

		if (n0 == 0) {
			string ans;
			if (n2) {
				ans += "11";
				n2--;
			}
			while (n2) {
				ans += '1';
				n2--;
			}

			while (n1) {
				if (!len (ans))
					ans += "01";
				else {
					if (ans.back () == '0')
						ans += '1';
					else
						ans += '0';
				}
				n1--;
			}
			pr (ans);
			continue;
		}

		bool flag = 0;

		if (n1 > 0 and !(n1 & 1)) flag = 1;

		string ans;
		if (n0) {
			ans += "00";
			n0--;
		}

		while (n0) {
			ans += '0';
			n0--;
		}

		if (n1) {
			if (!len (ans))
				ans += "10";
			else
				ans += '1';
			n1--;
		}

		while (true) {
			if (!flag) {
				if (n1 == 0) break;
			} else {
				if (n1 == 1) break;
			}
			if (ans.back () == '0')
				ans += '1';
			else
				ans += '0';
			n1--;
		}

		if (n2) {
			if (!ans.size ()) {
				ans += "11";
			} else {
				ans += '1';
			}
			n2--;
		}
		while (n2) {
			ans += '1';
			n2--;
		}
		if (flag) ans += '0';
		pr (ans);
	}
	return 0;
}