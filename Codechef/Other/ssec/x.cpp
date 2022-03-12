/*
				C++
				encoding: UTF-8
				Last Modified: 19/Sep/20 07:52:21 PM
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

int n, k;
string s;
const int N = 1e3 + 5;
string arr[N];

int dp[205][1001][2][2][2]; // index, k, o-a, t-l, erase,

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> k;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int l = (int)arr[i].size ();
		for ()
	}

	return 0;
}