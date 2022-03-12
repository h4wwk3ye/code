
#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n"
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

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
		ll n, k;
		cin >> n >> k;
		ll arr[n];
		fr (i, 0, n) cin >> arr[i];
		ve< ll > chk[n];
		fr (i, 0, n) {
			if (arr[i] % k != 0) {
				chk[i].pb (arr[i]);
				chk[i].pb (arr[i] * k);
			} else {
				while (arr[i] % k == 0) {
					chk[i].pb (arr[i]);
					arr[i] /= k;
				}
				chk[i].pb (arr[i]);
			}
			sort (all (chk[i]));
		}

		ll ans = LLONG_MAX;
		for (ll j = 0; j < n; j++)
			for (auto k : chk[j]) {
				ll mx = 0, mn = LLONG_MAX;
				bool flag = 1;
				for (ll i = 0; i < n; i++) {
					ll idx = lower_bound (chk[i].begin (), chk[i].end (), k) - chk[i].begin ();
					if (idx == chk[i].size ()) {
						flag = 0;
						break;
					}
					mx = max (mx, chk[i][idx]);
					mn = min (mn, chk[i][idx]);
				}
				if (flag == 0) break;
				ans = min (ans, abs (mx - mn));
			}
		pr (ans);
	}
	return 0;
}
