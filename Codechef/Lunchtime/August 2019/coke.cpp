/*
				C++
				encoding: UTF-8
				Last Modified: 2019/09/01 19:58:52

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)
/*
void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}*/

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;

	while (tc--) {
		int n, q, k, l, r;
		cin >> n >> q >> k >> l >> r;
		pii arr[n];
		fr (i, 0, n) cin >> arr[i].ff >> arr[i].ss;
		fr (m, 1, q + 1) {
			int ans = 1e9;
			fr (i, 0, n) {
				int x = arr[i].ff;
				int y = arr[i].ss;
				if (x > k) {
					x = max (k, x - m);
				} else {
					x = min (k, x + m);
				}
				if (x >= l and x <= r) ans = min (ans, y);
			}
			if (ans == 1e9)
				cout << -1 << " ";
			else
				cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}
