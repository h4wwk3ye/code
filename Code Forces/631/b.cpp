#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 03/Apr/20 11:30:56 PM
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
		int arr[n + 1];
		fr (i, 1, n + 1) cin >> arr[i];
		set< int, greater<> > s;
		ve< int > ans;
		fr (i, 1, n + 1) {
			s.insert (arr[i]);
			if (len (s) == i) {
				auto it = s.begin ();
				if (*it == i) ans.pb (i);
			}
		}
		ve< int > o;
		set< int, greater<> > t;
		int p = n;
		dfr (i, len (ans) - 1, -1) {
			fr (j, ans[i] + 1, p + 1) t.insert (arr[j]);

			if (len (t) == n - ans[i]) {
				auto it = t.begin ();

				if (*it == n - ans[i]) o.pb (ans[i]);
			}
		}
		pr (len (o));
		for (auto& i : o) {
			pr (i, n - i);
		}
	}
	return 0;
}