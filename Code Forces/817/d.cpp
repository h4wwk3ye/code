/*
				C++
				encoding: UTF-8
				Last Modified: 30/Aug/22 10:24:32 PM
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
		string s;
		cin >> s;

		// change from either end
		// if the person is not looking in the opposite direction

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'L') {
				cnt += i;
			} else {
				cnt += (n - i - 1);
			}
		}

		vector< int > ans;
		for (int i = 1; i <= n; ++i) {
			int k = i;

			int c = cnt;
			int l = 0, r = n - 1;
			vector< bool > vis (n, false);
			while (k > 0 and (l <= n / 2 or r >= n / 2)) {
				// debug (i, c, l, r);
				//      if changing from left
				bool f = false;
				while (l < n / 2 and s[l] == 'R') {
					if (vis[l]) {
						f = true;
						break;
					}
					l++;
				}

				while (r > n / 2 and s[r] == 'L' and !vis[r]) {
					if (vis[r]) {
						f = true;
						break;
					}
					r--;
				}

				if (f or l > r) break;
				int x = (n - l - 1) - (l);

				int y = (r) - (n - r - 1);
				if (x > y and x > 0) {
					// switch from left
					c += x;
					l++;
					vis[l] = true;
				} else if (x <= y and y > 0) {
					c += y;
					r--;
					vis[r] = true;
				}
				k--;
				// debug (i, c, l, r);
			}
			ans.push_back (c);
		}
		for (auto& i : ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}