/*
				C++
				encoding:UTF-8
				Modified: <18/May/2019 11:07:30 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
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
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e5 + 5;
ll arr[N];
int n;
ll freq[128], tmp[128];

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 0, n) cin >> arr[i];

	fr (i, 0, n) {
		reset (tmp, 0);
		fr (j, 0, 128) {
			tmp[j] = (freq[j] + freq[j ^ arr[i]]);
			tmp[j] %= mod;
		}
		tmp[arr[i]]++;

		fr (j, 0, 128) {
			freq[j] = tmp[j];
			freq[j] %= mod;
		}
	}
	ll ans = 0;
	fr (i, 0, 128) {
		ans += (freq[i] * (freq[i] - 1)) / 2;
		ans %= mod;
	}
	pr1 (ans);

	return 0;
}
