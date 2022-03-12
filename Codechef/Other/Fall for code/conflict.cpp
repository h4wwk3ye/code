/*
				C++
				encoding:UTF-8
				Modified: <21/Jun/2019 12:35:57 AM>

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
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		multiset< ll > s;
		ll n, d;
		cin >> n >> d;
		fr (i, 0, n) {
			ll x;
			cin >> x;
			s.insert (x);
		}
		fr (i, 0, d) {
			auto it1 = s.end ();
			it1--;
			ll tmp1 = *it1;
			auto it2 = s.begin ();
			if (tmp1 == *it2) break;
			s.erase (it1);
			s.insert (tmp1 - 1);
			ll tmp2 = *it2;
			s.erase (it2);
			s.insert (tmp2 + 1);
		}
		auto it = s.rbegin ();
		ll tmp1 = *it;
		auto it1 = s.begin ();
		ll tmp2 = *it1;
		pr1 (tmp1 - tmp2);
	}
	return 0;
}
