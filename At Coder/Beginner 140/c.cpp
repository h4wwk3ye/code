/*
				C++
				encoding: UTF-8
				Modified: <07/Sep/2019 07:23:00 PM>

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
	int b[n];
	b[0] = 0;
	fr (i, 1, n) cin >> b[i];
	int a[n + 1];
	a[1] = a[2] = b[1];
	int prv = a[2];
	fr (i, 3, n + 1) {
		a[i] = b[i - 1];
		if (prv > b[i - 1]) a[i - 1] = b[i - 1];
		prv = a[i];
	}

	int ans = 0;
	fr (i, 1, n + 1) ans += a[i];
	pr (ans);
	return 0;
}
