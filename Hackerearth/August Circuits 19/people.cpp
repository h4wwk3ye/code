/*
				C++
				encoding: UTF-8
				Modified: <27/Aug/2019 10:38:39 AM>

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

long double dist (int x1, int y1, int x2, int y2) {
	long double ans = sqrt (pow (x1 - x2, 2) + pow (y1 - y2, 2));
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int g;
	cin >> g;
	pii arr[n + 1];
	fr (i, 1, n + 1) cin >> arr[i].ff >> arr[i].ss;

	pr (1);
	pr (n);
	fr (i, 1, n + 1) cout << i << " ";
	cout << endl;

	return 0;
}
