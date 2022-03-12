/*
				C++
				encoding: UTF-8
				Last Modified: 22/Oct/2019 08:00:31 PM
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		 int                    long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n"
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 (int)v.size()
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

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
		int l, r;
		cin >> l >> r;
		string L = "", R = "";
		dfr (i, 63, -1) {
			int curr_bit = (l >> i) & 1;
			L += to_string (curr_bit);
		}
		dfr (i, 63, -1) {
			int curr_bit = (r >> i) & 1;
			R += to_string (curr_bit);
		}
		string ans = "";
		int f = 0;
		fr (i, 0, 64) {
			if (L[i] == '1' or R[i] == '1' or f == 1)
				ans += "1";
			else
				ans += "0";
			if (R[i] == '1' and L[i] == '0') f = 1;
		}

		int t = stoll (ans, 2);
		pr (t);
	}
	return 0;
}
