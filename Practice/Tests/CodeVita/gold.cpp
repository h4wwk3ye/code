/*
				C++
				encoding: UTF-8
				Last Modified: 15/Aug/20 05:44:22 PM
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

const int mod = 1e9 + 7;

int largestArea (vector< int >& heights) {
	stack< int > stk;
	int ans = 0, n = heights.size ();
	int i = 0;
	while (i < n) {
		if (stk.empty () or heights[i] > heights[stk.top ()]) {
			stk.push (i);
			i++;
		} else {
			int x = stk.top ();
			stk.pop ();
			int area = heights[x] % mod * (stk.empty () ? i : i - stk.top () - 1);
			ans = max (ans, area % mod);
		}
	}
	while (!stk.empty ()) {
		int x = stk.top ();
		stk.pop ();
		int area = heights[x] % mod * (stk.empty () ? n : n - stk.top () - 1);
		ans = max (ans, area % mod);
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int b, h;
	cin >> b >> h;
	vector< int > arr (n);
	int totalVolume = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		totalVolume += arr[i] * b * h;
		totalVolume %= mod;
	}
	int ans = largestArea (arr);
	ans = ans * b * h;
	ans %= mod;

	ans = (totalVolume - ans + mod) % mod;
	cout << ans;

	return 0;
}