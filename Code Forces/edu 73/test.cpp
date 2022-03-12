/*
				C++
				encoding: UTF-8
				Modified: <19/Sep/2019 10:19:47 PM>

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
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

#define int long long

bool check (ll cnt, ll c, ll m, ll x) {
	if (c >= cnt && m >= cnt) {
		ll resi = c - cnt + m - cnt + x;
		if (resi >= cnt) return 1;
		return 0;
	} else
		return 0;
}


int f (int c, int m, int x) {
	// freopen("in.txt" , "r" , stdin) ;
	// freopen("out.txt" , "w" , stdout) ;

	ll ans = 0, low = 0, high = 1e9;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (check (mid, c, m, x)) {
			ans = mid;
			low = mid + 1;
		} else
			high = mid - 1;
	}
	return ans;
}

int s (int a, int b, int c) {
	return min (min (a, b), (a + b + c) / 3);
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	freopen ("inp.txt", "r", stdin);
	int tc;
	cin >> tc;
	while (tc--) {
		ll c, m, x;
		cin >> c >> m >> x;
		if (f (c, m, x) != s (c, m, x)) {
			pr (c, m, x);
		}
	}
	return 0;
}
