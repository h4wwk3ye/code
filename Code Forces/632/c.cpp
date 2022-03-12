//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Apr/20 10:05:47 PM
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
	int n;
	cin >> n;
	ve< int > arr (n + 1), vis (n + 1, 0);
	fr (i, 1, n + 1) cin >> arr[i];
	map< int, int > mp;

	int ans = 0;
	int s = 0;
	int p = 1;
	mp[0] = 1;
	fr (i, 1, n + 1) {
		if (arr[i] == 0) {
			ans += ((i - p) * (i - p - 1)) / 2;
			p = i + 1;
			mp[0] = i;

		} else {
			s += arr[i];
			if (mp.find (s) == mp.end ()) { // havent yet found
				mp[s] = i;
			} else {
				ans += ((i - p) * (i - p - 1)) / 2;

				p = mp[s] + 1;
				mp[s] = i;
			}
		}
		pr (mp, ans, s, i, p);
	}
	int t = 0;
	fr (i, p, n + 1) t += arr[i];

	ans += ((n - p + 1) * (n - p)) / 2;
	pr (ans);
	// if (p == n - 1) vis[n] = 1;
	fr (i, 1, n + 1) if (arr[i] and !vis[i]) ans++;
	pr (ans);

	return 0;
}