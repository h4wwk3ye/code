//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/Feb/20 08:28:28 PM
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
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		int p[m];
		fr (i, 0, m) cin >> p[i];
		ve< int > cnt (n + 1, 0);
		ve< int > ans (26, 0);
		for (auto& i : p) {
			cnt[i]++;
		}
		dfr (i, n - 1, 0) {
			cnt[i] += cnt[i + 1];
		}
		fr (i, 1, n + 1) {
			ans[s[i - 1] - 'a'] += cnt[i];
		}
		for (auto& i : s) {
			ans[i - 'a']++;
		}
		for (auto& i : ans)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}