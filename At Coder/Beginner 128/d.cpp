/*
				C++
				encoding:UTF-8
				Modified: <26/May/2019 07:25:51 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<ll, ll>
#define		 len(v)                 ll(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on
const ll N = 51;
ll v[N];
ll n, k;
ll mx;


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> k;
	fr (i, 0, n) cin >> v[i];
	ll ans = 0;
	fr (i, 0, min (n, k) + 1) {
		fr (j, 0, min (k - i, n - i) + 1) {
			multiset< ll > s;
			ll a = 0;
			fr (p, 0, i) {
				a += v[p];
				if (v[p] < 0) s.insert (v[p]);
			}
			fr (p, 0, j) {
				a += v[n - 1 - p];
				if (v[n - 1 - p] < 0) s.insert (v[n - 1 - p]);
			}
			ll out = k - i - j;
			while (out and !s.empty ()) {
				auto it = s.begin ();
				a -= (*it);
				s.erase (it);
				out--;
			}
			ans = max (ans, a);
		}
	}
	pr1 (ans);
	return 0;
}
