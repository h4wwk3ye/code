/*
				C++
				encoding: UTF-8
				Last Modified: 30/Aug/22 09:35:07 PM
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

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		map< string, int > mp;
		vector< vector< string > > arr (3);
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < n; ++j) {
				string s;
				cin >> s;
				arr[i].push_back (s);
				mp[s]++;
			}
		}

		vector< int > ans;
		for (int i = 0; i < 3; ++i) {
			int cnt = 0;
			for (int j = 0; j < n; ++j) {
				string& s = arr[i][j];
				if (mp[s] == 1)
					cnt += 3;
				else if (mp[s] == 2)
					cnt++;
			}
			ans.push_back (cnt);
		}
		for (auto& i : ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}