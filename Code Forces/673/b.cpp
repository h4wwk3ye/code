/*
				C++
				encoding: UTF-8
				Last Modified: 27/Sep/20 08:52:18 PM
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
	cout << t << ' ';
	print (u, args...);
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, t;
		cin >> n >> t;
		vector< int > arr (n);
		map< int, int > mp;
		for (auto& i : arr) {
			cin >> i;
			mp[i]++;
		}
		vector< int > ans (n);
		set< int > s;
		if (t & 1) {
			// can separate with 0 ans
			for (int i = 0; i < n; ++i) {
				if (s.find (arr[i]) != s.end ()) {
					ans[i] = 1;
					continue;
				}
				if (mp.find (t - arr[i]) == mp.end ()) {
					s.insert (arr[i]);
					ans[i] = 1;
				} else {
					if (s.find (t - arr[i]) == s.end ()) {
						s.insert (arr[i]);
						ans[i] = 1;
					} else {
						ans[i] = 0;
					}
				}
			}
		} else {
			int cnt = mp[t / 2] / 2;
			// put half in 0
			for (int i = 0; i < n; ++i) {
				if (arr[i] * 2 == t) {
					if (cnt) {
						ans[i] = 1;
						cnt--;
					} else {
						ans[i] = 0;
					}
				} else {
					if (s.find (arr[i]) != s.end ()) {
						ans[i] = 1;
						continue;
					}
					if (mp.find (t - arr[i]) == mp.end ()) {
						s.insert (arr[i]);
						ans[i] = 1;
					} else {
						if (s.find (t - arr[i]) == s.end ()) {
							s.insert (arr[i]);
							ans[i] = 1;
						} else {
							ans[i] = 0;
						}
					}
				}
			}
		}
		for (auto& i : ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}