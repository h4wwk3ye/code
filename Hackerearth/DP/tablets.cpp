/*
				C++
				encoding:UTF-8
				Modified: <11/Apr/2019 07:39:41 PM>

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
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n";
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n";
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n;
	cin >> n;
	int arr[n + 2];
	fr (i, 1, n + 1) cin >> arr[i];
	arr[0] = 0;
	arr[n + 1] = 0;
	int f[n + 1], s[n + 1];
	fr (i, 1, n + 1) {
		f[i] = 1;
		s[i] = 1;
	}
	int curr = 0;
	fr (i, 1, n + 1) {
		if (arr[i] > arr[i + 1])
			curr++;
		else
			curr = 1;
		f[i] = curr;
	}
	curr = 0;
	dfr (i, n, 0) {
		if (arr[i] > arr[i + 1])
			curr++;
		else
			curr = 1;
		s[i] = curr;
	}
	ll ans = 0;
	fr (i, 1, n + 1) {
		ans += max (f[i], s[i]);
	}
	pr1 (ans);
	return 0;
}
