//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 29/Feb/20 11:38:58 PM
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

vector< string > ans;
map< int, char > mp;
void solve (string& s, int i, string temp, string curr) {
	if (i == s.size ()) {
		if (temp != "") {
			int k = stoi (temp);
			if (k > 26) return;
			curr += mp[k];
		}
		ans.push_back (curr);
		return;
	}
	temp += s[i];
	int k = stoi (temp);
	if (k > 26) return;

	solve (s, i + 1, temp, curr);
	solve (s, i + 1, "", curr + mp[k]);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	for (int i = 1; i < 27; ++i) {
		mp[i] = 'a' + i - 1;
	}
	string x = "1123";
	solve (x, 0, "", "");
	return 0;
}