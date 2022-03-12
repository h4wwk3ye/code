/*
				C++
				encoding: UTF-8
				Modified: <18/Aug/2019 09:49:36 PM>

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

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k, l, r;
		cin >> n >> m >> k >> l >> r;
		pii arr[n];
		int ans = 1e9;
		fr (i, 0, n) {
			cin >> arr[i].ff >> arr[i].ss;
			if (arr[i].ff > k) {
				arr[i].ff = max (k, arr[i].ff - m);
			} else {
				arr[i].ff = min (k, arr[i].ff + m);
			}
			if (arr[i].ff >= l and arr[i].ff <= r) ans = min (ans, arr[i].ss);
		}
		if (ans == 1e9)
			pr (-1);
		else
			pr (ans);
	}
	return 0;
}
