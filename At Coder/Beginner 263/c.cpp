/*
				C++
				encoding: UTF-8
				Last Modified: 06/Aug/22 05:45:02 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << ' ';
	print (u, args...);
}

vector< vector< int > > ans;
int n, m;

void solve (int curr, int sz, vector< int > v) {
	if (curr > m or sz == n) {
		if (sz == n) ans.push_back (v);
		return;
	}
	// either add the current or continue
	solve (curr + 1, sz, v);
	v.push_back (curr);
	solve (curr + 1, sz + 1, v);
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	solve (1, 0, {});
	sort (ans.begin (), ans.end ());
	for (auto& i : ans) {
		for (auto& j : i)
			cout << j << ' ';
		cout << '\n';
	}
	return 0;
}