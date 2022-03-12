#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	ll p, q, r, s;
	cin >> p >> q >> r >> s;
	ll ans = 0;
	for (ll i = p; i <= q; ++i) {
		for (ll j = r; j <= s; ++j) {
			ll mn = min (i, j);
			ll mx = max (i, j);
			while (mn > 1) {
				ans++;
				ll tmp = mx;
				mx = mn;
				mn = tmp - mx;
				if (mn > mx) swap (mn, mx);
			}
			if (mn == 1) ans += mx;
		}
	}
	cout << ans << endl;
	return 0;
}
