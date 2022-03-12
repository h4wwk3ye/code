//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 03/Apr/20 04:08:06 PM
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
		ve< int > left (n), right (n);
		int p = 1e9;
		fr (i, 0, n) {
			if (s[i] == '1') p = i;
			left[i] = p;
		}
		p = 1e9;
		dfr (i, n - 1, -1) {
			if (s[i] == '1') p = i;
			right[i] = p;
		}
		// pr (left, right);
		int d;
		cin >> d;
		set< int > blocks;
		fr (i, 1, d + 1) {
			cin >> p;
			p--;
			int r = right[p - 1], l = left[p];

			if (s[p] == '1' and s[p - 1] == '1') continue;

			if (s[p] == '1') {
				if (abs (r - (p - 1)) >= i) {
					blocks.insert (p);
				}
			} else if (s[p - 1] == '1') {
				if (abs (l - p) >= i) {
					blocks.insert (p);
				}
			} else {
				if (abs (r - (p - 1)) >= i and abs (l - p) >= i) blocks.insert (p);
			}
		}
		// pr (blocks);
		ve< string > arr;
		string curr = "";
		fr (i, 0, n) {
			if (blocks.find (i) != blocks.end ()) {
				arr.pb (curr);
				curr = s[i];
			} else {
				curr += s[i];
			}
		}
		arr.pb (curr);
		// pr (arr);
		int ans = 0;
		for (auto& i : arr) {
			bool flag = 0;
			for (auto& j : i) {
				if (j == '1') {
					flag = 1;
					true;
				}
			}
			if (flag) ans += len (i);
		}
		pr (ans);
	}
	return 0;
}
/*
1
8
10001000
3
8
3
4
*/