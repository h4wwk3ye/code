//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 28/Mar/20 12:11:05 PM
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
		multiset< int > s;
		fr (i, 0, n) {
			int x;
			cin >> x;
			s.insert (x);
		}
		int b[n];
		fr (i, 0, n) cin >> b[i];

		int ans = 0;
		fr (i, 0, n) {
			if (!s.size ()) break;
			auto it = s.upper_bound (b[i]);
			if (it == s.end ()) {
				auto it2 = s.begin ();
				s.erase (it2);
				continue;
			}
			int y = *it;
			ans++;
			s.erase (it);
		}
		pr (ans);
	}
	return 0;
}