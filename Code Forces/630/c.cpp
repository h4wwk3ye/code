//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 31/Mar/20 08:31:59 PM
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
		map< int, map< char, int > > mp;
		for (int i = 0; i < k; i++) {
			for (int j = i; j < n; j += k) {
				mp[i][s[j]]++;
			}
		}

		int ans = 0;
		int i = 0, j = k - 1;
		int z = n / k;
		while (i < j) {
			map< char, int > mp;
			for (int l = i; l < n; l += k)
				mp[s[l]]++;
			for (int l = j; l < n; l += k)
				mp[s[l]]++;
			int mx = 0;
			for (auto& [l, m] : mp) {
				mx = max (mx, m);
			}
			ans += 2 * z - mx;

			i++;
			j--;
		}
		if (i == j) {
			map< char, int > mp;
			for (int l = i; l < n; l += k)
				mp[s[l]]++;
			int mx = 0;
			for (auto& [l, m] : mp) {
				mx = max (mx, m);
			}
			ans += z - mx;
		}
		pr (ans);
	}
	return 0;
}