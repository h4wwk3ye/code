/*
				C++
				encoding: UTF-8
				Last Modified: 15/Sep/20 10:50:50 AM
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
	string s;
	cin >> s;
	int l (s.size ());
	int curr (0);
	bool ans (true);
	for (int i = 1; i <= l; ++i) {
		curr = curr * 10 + (s[i - 1] - '0');
		if (curr % (l - i + 1)) {
			ans = false;
			break;
		}
	}
	print (ans ? "Yes" : "No");
	return 0;
}