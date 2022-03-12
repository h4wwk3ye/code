//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 27/Mar/20 05:59:00 PM
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
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector< int > a (n);
		vector< pair< int, int > > e;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			e.push_back ({a[i], i});
		}
		sort (e.begin (), e.end ());
		vector< int > r (n);
		for (int i = n - 1; i >= 0; i--) {
			r[i] = i;
			if (i + 1 < n && e[i + 1].second > e[i].second) {
				r[i] = r[i + 1];
			}
		}
		vector< int > suf (n);
		set< int > q;
		for (int i = n - 1; i >= 0; i--) {
			suf[i] = q.size ();
			q.insert (e[i].first);
		}
		vector< int > pref (n);
		q.clear ();
		for (int i = 0; i < n; i++) {
			pref[i] = q.size ();
			q.insert (e[i].first);
		}
		int ans = q.size ();
		for (int i = 0; i < n; i++) {
			if (i == 0 || e[i].first != e[i - 1].first) {
				int go = r[i];
				ans = min (ans, pref[i] + suf[go]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}