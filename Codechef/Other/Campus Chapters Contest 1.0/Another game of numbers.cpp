//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Apr/20 05:27:44 PM
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
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		int ans = 0, mx, curr = 0;
		string B = bitset< 62 > (b).to_string ();
		string A = bitset< 62 > (a).to_string ();
		reverse (all (A));
		while (A.back () == '0')
			A.pop_back ();
		reverse (all (B));
		while (B.back () == '0')
			B.pop_back ();
		if (B == "") B = "0";
		while (len (B) < len (A))
			B += '0';
		reverse (all (B));

		mx = a ^ stoll (B, nullptr, 2);

		fr (i, 0, len (B) - 1) {
			rotate (B.begin (), B.begin () + len (B) - 1, B.end ());
			int c = a ^ stoll (B, nullptr, 2);

			curr++;
			if (mx < c) {
				mx = c;
				ans = curr;
			}
		}
		pr (ans, mx);
	}
	return 0;
}