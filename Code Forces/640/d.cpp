//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 09/May/20 08:46:03 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		ve< int > arr (n);
		fr (i, 0, n) cin >> arr[i];
		int alice = 0, bob = 0;
		int x = 0, y = 0;
		int px = 0, py = 0;
		int i = 0, j = n - 1;
		int ans = 0;
		bool flag = 0;
		bool p = 0;
		while (i <= j) {
			if (!flag) {
				x += arr[i];
				alice += arr[i];
				i++;
				if (x > py) {
					flag = 1;
					px = x;
					x = 0;
				}
			} else {
				y += arr[j];
				bob += arr[j];
				j--;
				if (y > px) {
					flag = 0;
					py = y;
					y = 0;
				}
			}
			if (p != flag) ans++;
			p = flag;
		}
		if (x or y) ans++;
		pr (ans, alice, bob);
	}
	return 0;
}