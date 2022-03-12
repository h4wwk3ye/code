/*
				C++
				encoding: UTF-8
				Modified: <27/Jul/2019 05:48:35 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettyprint.hpp>
#endif

using namespace std;

// clang-format off

#define         int                     long long
#define ll long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int a[n + 1];
	fr (i, 0, n + 1) cin >> a[i];
	int b[n];
	fr (i, 0, n) cin >> b[i];
	int ans = 0, curr = 0;

	fr (i, 0, n) {
		curr = min (a[i], b[i]);
		ans += curr;
		b[i] -= curr;
		curr = min (a[i + 1], b[i]);
		a[i + 1] -= curr;
		ans += curr;
	}
	print (ans);
	return 0;
}
