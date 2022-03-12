//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 14/May/20 10:05:06 PM
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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		int ans = 1e18;
		int cnt = 0;
		for (auto& i : s)
			if (i == '1') cnt++;

		for (int j = 0; j < k; ++j) {
			ve< int > pos;
			bool f = 0;
			int c = 0;
			char p = '1';
			int x = 0;
			for (int i = j; i < n; i += k) {
				if (s[i] == '1') x++;
				if (!f and s[i] == '0') continue;
				f = 1;
				if (p != s[i]) {
					pos.pb (c);
					c = 1;
					p = s[i];
				} else
					c++;
			}
			pos.pb (c);
			if (p == '0' and len (pos)) pos.pop_back (); // trailing zeroes

			// so ones are at beginning and end
			int l = len (pos);
			if (!f) { // all zeroes
				// toggle all remaining
				ans = min (ans, cnt);
				continue;
			}

			ve< int > prefix (l); // count of ones

			prefix[l - 1] = pos[l - 1];

			f = 0;
			for (int i = l - 2; i >= 0; --i) {
				if (!f)
					prefix[i] = prefix[i + 1];
				else
					prefix[i] = prefix[i + 1] + pos[i];
				f = !f;
			}
			// pr (prefix, pos);
			int prev = 0;
			fr (i, 0, l) {
				if (i & 1) { // 0
					ans = min (ans, prev + cnt - (x - prefix[i]));
					prev += pos[i];
				} else {
					// ans = min (ans, prev + cnt - (x - prefix[i]));
					// iske aage ke saare 1
					ans = min (ans, prev + cnt - (x - (prefix[i] - pos[i])));
				}
				// pr (i, prev, cnt, prefix[i], x, ans);
			}
		}
		pr (ans);
	}
	return 0;
}