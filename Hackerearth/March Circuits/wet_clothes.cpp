/*
				C++
				encoding:UTF-8
				Modified: <23/Mar/2019 03:57:25 PM>

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
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (int i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int main () {
	// ios_base::sync_with_stdio (false), cin.tie (0);
	int n, m, g;
	cin >> n >> m >> g;
	int t[n];
	fr (i, 0, n) cin >> t[i];
	int a[m];
	fr (i, 0, m) cin >> a[i];
	int x[n];
	fr (i, 1, n) {
		x[i] = t[i] - t[i - 1];
	}
	x[0] = 0;
	sort (x, x + n);
	sort (a, a + m);

	int index = upper_bound (a, a + m, x[n - 1]) - a;

	pr1 (index);
	return 0;
}
