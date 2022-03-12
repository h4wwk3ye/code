/*
				C++
				encoding: UTF-8
				Modified: <07/Sep/2019 05:37:17 PM>

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

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int a[n + 1], b[n + 1], c[n + 1];
	a[0] = b[0] = c[0] = c[1] = 0;
	fr (i, 1, n + 1) cin >> a[i];
	fr (i, 1, n + 1) cin >> b[i];
	fr (i, 2, n + 1) cin >> c[i];

	int ans = 0;
	int prv = -1;
	fr (i, 1, n + 1) {
		int dish = a[i];
		ans += b[dish];
		if (dish == 1 + prv) {
			ans += c[dish];
		}
		prv = dish;
	}
	pr (ans);
	return 0;
}
