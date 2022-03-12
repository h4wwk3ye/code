/*
				C++
				encoding:UTF-8
				Modified: <18/Mar/2019 10:03:36 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     int64_t
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define      pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int n, m;
	cin >> n >> m;
	ve< pii > h (m);
	fr (i, 0, m) {
		int u, v;
		cin >> u >> v;
		h[i] = {u, v};
	}


	int mx = max (h[0].ss + h[0].ff - 1, h[m - 1].ss + (n - h[m - 1].ff));
	fr (i, 0, m - 1) {
		if (abs (h[i + 1].ss - h[i].ss) > h[i + 1].ff - h[i].ff) {
			pr1 ("IMPOSSIBLE");
			return 0;
		}
		mx = max (mx,
				  max (h[i].ss, h[i + 1].ss) +
				  (h[i + 1].ff - h[i].ff - abs (h[i].ss - h[i + 1].ss)) / 2);
	}
	pr1 (mx);
	return 0;
}
