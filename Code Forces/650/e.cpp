/*
				C++
				encoding: UTF-8
				Last Modified: 16/Jun/20 09:54:32 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int long long

template < typename T > void print (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

int n, k;
string s;
const int N = 2e3 + 5;
map< pair< int, string >, int > mp;
int ans;

int solve (int i, string curr) {
	print (i, curr);
	if (i == s.size ()) {
		for (int p = 0; p < k && p < curr.size (); ++p) {
			for (int q = 0; q < curr.size (); q += k) {
				if (curr[p] != curr[q]) return false;
			}
		}
		ans = max (ans, (int)curr.size ());
		return true;
	}
	if (mp.find ({i, curr}) != mp.end ()) return mp[{i, curr}];
	int& x = mp[{i, curr}];

	for (int j = i; j < s.size (); ++j) {
		curr += s[j];
		x = solve (j + 1, curr);
		curr.pop_back ();
	}
	return x;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		cin >> s;
		mp.clear ();
		solve (0, "");
		print (ans);
	}

	return 0;
}