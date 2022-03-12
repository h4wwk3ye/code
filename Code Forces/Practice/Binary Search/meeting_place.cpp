/*
				C++
				encoding:UTF-8
				Modified: <19/Mar/2019 12:48:52 PM>

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
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

#define ld long double

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int n;
	cin >> n;
	int x[n];
	fr (i, 0, n) cin >> x[i];
	int v[n];
	fr (i, 0, n) cin >> v[i];

	ld low = 0, high = 1e9 + 5, mid;

	int cnt = 100;

	while (cnt--) {
		mid = (low + high) / 2;

		ld l = -1e9 - 5, r = 1e9 + 5;

		fr (i, 0, n) {
			l = max (l, x[i] - mid * v[i]);
			r = min (r, x[i] + mid * v[i]);

			if (r < l) break;
		}
		if (l <= r)
			high = mid;
		else
			low = mid;
	}
	cout << fixed << setprecision (7) << high;
	return 0;
}
