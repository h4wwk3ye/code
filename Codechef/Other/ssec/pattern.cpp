/*
				C++
				encoding: UTF-8
				Last Modified: 15/Sep/20 10:45:40 AM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	map< int, vector< int > > mp;
	mp[0] = mp[6] = {83};
	mp[1] = mp[5] = {83, 83};
	mp[2] = mp[4] = {83, 83, 69};
	mp[3] = {83, 83, 69, 67};

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		n--;
		n %= 7;
		for (auto& i : mp[n]) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}