/*
				C++
				encoding:UTF-8
				Modified: <20/Jun/2019 11:20:14 PM>

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
	// ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n;
		set< ll > s;
		set< ll > flag;
		fr (i, 0, n) {
			ll x;
			cin >> x;
			if (s.find (x) != s.end ()) {
				flag.insert (x);
			} else
				s.insert (x);
		}
		ll a = 0, b = 0;
		int f = 0;
		int p = 0;
		while (!s.empty ()) {
			auto it = s.end ();
			it--;
			ll tmp = *it;
			if (tmp == 0) break;
			if (flag.find (tmp) != flag.end ()) {
				auto it1 = flag.lower_bound (tmp);
				flag.erase (it1);
				s.erase (it);
			} else {
				if (f == 0)
					a += tmp;
				else
					b += tmp;

				s.erase (it);
				tmp /= 2;
				// if (len (s) == 0) break;
				if (s.find (tmp) != s.end ()) {
					flag.insert (tmp);
				}
				s.insert (tmp);
			}
			f = 1 - f;
		}
		if (a > b) {
			pr2 ("Cherry", a - b);
		} else
			pr1 ("Hazardous");
	}
	return 0;
}
