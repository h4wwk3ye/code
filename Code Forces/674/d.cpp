/*
				C++
				encoding: UTF-8
				Last Modified: 28/Sep/20 03:19:47 PM
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
	int n;
	cin >> n;
	int arr[n];
	map< int, vector< int > > mp;
	int curr = 0;
	mp[0].push_back (0);
	vector< pair< int, int > > intervals;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		curr += arr[i];
		mp[curr].push_back (i);
	}

	for (auto& [k, v] : mp) {
		if (v.size () > 1) {
			for (int j = 0; j < v.size (); ++j) {
				for (int m = j + 1; m < v.size (); ++m) {
					intervals.push_back ({v[j], v[m] - 1});
				}
			}
			// for (int j = 1; j < v.size (); ++j) {
			// 	intervals.push_back ({v[j - 1], v[j]});
			// }
		}
	}

	sort (intervals.begin (), intervals.end (), [] (const pair< int, int >& a, const pair< int, int >& b) {
		return a.second < b.second;
	});
	print (intervals);
	int ans = 0, last = -1;
	for (auto& [x, y] : intervals) {
		if (last <= x) {
			ans++;
			last = y;
		}
	}
	print (ans);
	return 0;
}