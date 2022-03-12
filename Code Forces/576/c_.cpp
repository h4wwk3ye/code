/*
				C++
				encoding: UTF-8
				Modified: <30/Jul/2019 09:30:56 PM>

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

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

ll counter[(int)4e5 + 5];

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	ll n, I;
	cin >> n >> I;
	I *= 8;
	I = ceil (log2 (I));
	pr (I);
	ll arr[n + 1];
	unordered_map< ll, ll > mp;
	ll cnt = 0;
	fr (i, 1, n + 1) {
		ll x;
		cin >> x;
		if (mp.find (x) == mp.end ()) {
			cnt++;
			mp[x] = cnt;
		}
		arr[i] = mp[x];
		counter[arr[i]]++;
	}

	ll dp[cnt + 5];
	reset (dp, 0);
	fr (i, 1, cnt + 5) {
		dp[i] = dp[i - 1] + counter[i];
	}
	fr (i, 1, cnt + 1) cout << dp[i] << " ";
	return 0;
}
