/*
				C++
				encoding: UTF-8
				Last Modified: 16/Aug/20 11:17:09 PM
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

int solve (vector< pair< int, int > >& mp, int idx, int z, int o) {
	if (idx == (int)mp.size ()) {
		return z == o and z != 0;
	}
	// either select or not
	return solve (mp, idx + 1, z, o) + solve (mp, idx + 1, z + mp[idx].first, o + mp[idx].second);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int mx = 0;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		mx = max (mx, arr[i]);
	}

	const int bits = log2 (mx) + 1;

	vector< pair< int, int > > mp;

	for (int i = 0; i < n; ++i) {
		int z = 0, o = 0;
		for (int j = 0; j < bits; ++j) {
			int x = (arr[i] >> j) & 1;
			if (x)
				o++;
			else
				z++;
		}
		mp.push_back ({z, o});
	}

	// now recursing for solutions
	int ans = 0;
	ans = max (ans, solve (mp, 0, 0, 0));
	string op;
	for (int i = bits - 1; i >= 0; --i) {
		int c = (ans >> i) & 1;
		op += (c ? '1' : '0');
	}
	cout << op;
	return 0;
}