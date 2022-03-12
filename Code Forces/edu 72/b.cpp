/*
				C++
				encoding: UTF-8
				Modified: <05/Sep/2019 09:09:50 PM>

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

bool cmp (const pii& a, const pii& b) {
	if (a.ff - a.ss == b.ff - b.ss) return a.ff > b.ff;
	return a.ff - a.ss > b.ff - b.ss;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		ve< pii > arr;
		int mx = 0;
		int mx1 = 0;
		fr (i, 0, n) {
			int d, h;
			cin >> d >> h;
			int tmp = d - h;
			mx1 = max (mx1, d);
			if (tmp <= 0) continue;
			mx = max (mx, d - h);
			arr.pb ({d, h});
		}
		sort (all (arr), cmp);
		n = len (arr);

		if (n == 0) {
			pr (-1);
			continue;
		}

		int tmp = x - mx1;
		if (tmp <= 0) {
			pr (1);
			continue;
		}
		int ans = ceil ((tmp * 1.0) / (arr[0].ff - arr[0].ss));

		// if (tmp % (arr[0].ff - arr[0].ss) == 0) ans--;

		pr (ans + 1);
	}
	return 0;
}
