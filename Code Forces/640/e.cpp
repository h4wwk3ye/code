//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 09/May/20 09:05:23 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

// #define		int                    long long
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
	unordered_map< int, int > mp;
	unordered_set< int > s;
	ve< int > prefix;
	while (tc--) {
		int n;
		cin >> n;
		prefix.resize (n + 1);
		prefix[0] = 0;
		int mx = 0;
		mp.clear ();
		fr (i, 1, n + 1) {
			int x;
			cin >> x;
			mx = max (mx, x);
			mp[x]++;
			prefix[i] = x + prefix[i - 1];
		}

		int ans = 0;
		// set< int > s;
		s.clear ();

		fr (i, 1, n + 1) {
			fr (j, i + 1, n + 1) {
				int sum = prefix[j] - prefix[i - 1];
				if (sum > mx) break; // useless optimization

				if (s.find (sum) == s.end ()) {
					ans += mp[sum];
					s.insert (sum);
				}
			}
		}

		pr (ans);
	}
	return 0;
}