//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 16/Feb/20 05:41:17 PM
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
	map< string, int > mp;
	fr (i, 0, n) {
		string s;
		cin >> s;
		mp[s]++;
	}
	ve< pair< int, string > > v;
	for (auto& i : mp) {
		v.push_back ({i.ss, i.ff});
	}
	sort (all (v));
	reverse (all (v));
	int x = v[0].ff;
	ve< string > ans;
	for (auto& i : v) {
		if (i.ff < x) break;
		ans.pb (i.ss);
	}
	sort (all (ans));
	for (auto& i : ans)
		pr (i);
	return 0;
}