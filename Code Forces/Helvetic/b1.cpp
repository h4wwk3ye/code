/*
				C++
				encoding: UTF-8
				Modified: <07/Jul/2019 01:03:35 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         umap                   unordered_map
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<ll, ll>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define         pr1(x)                 cout<<x<<"\n"
#define         pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define         pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

bool cmp (pii b, ll a) {
	return b.ff < a;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	ll s, b;
	cin >> s >> b;
	ve< ll > attack (s);
	fr (i, 0, s) cin >> attack[i];
	ve< pii > defense (b);
	fr (i, 0, b) {
		ll d, g;
		cin >> d >> g;
		defense[i] = {d, g};
	}
	sort (all (defense));
	ll prefix[b];
	prefix[0] = defense[0].ss;
	fr (i, 1, b) prefix[i] = prefix[i - 1] + defense[i].ss;

	fr (i, 0, s) {
		int j = lower_bound (all (defense), attack[i], cmp) - defense.begin ();
		if (defense[j].ff != attack[i]) j--;
		// pr3 (i, j, prefix[j]);
		if (j < 0)
			cout << 0 << " ";
		else
			cout << prefix[j] << " ";
	}
	return 0;
}
