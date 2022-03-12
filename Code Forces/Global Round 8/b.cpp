/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jun/20 11:38:31 AM
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

int power (int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = r * a;
		b >>= 1;
		a = a * a;
	}
	return r;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int k;
	cin >> k;
	string s = "codeforces";

	vector< int > cnt (10, 1);
	int curr = 1;
	int idx = 0;
	while (curr < k) {
		// remove the previous contribution
		curr /= cnt[idx];
		cnt[idx]++;
		// add the new contribution
		curr *= cnt[idx];
		idx++;
		idx %= 10;
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			cout << s[i];
		}
	}
	return 0;
}