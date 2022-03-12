/*
				C++
				encoding:UTF-8
				Modified: <09/Apr/2019 02:37:46 AM>

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
#define		 pii                    pair<ll, ll>
#define		 len(v)                 ll(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n";
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n";
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (ll i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const ll N = 1e6 + 5;
ll prime[N];

void SieveOfEratosthenes (ll n) {
	fill (prime, prime + N, 1);
	prime[0] = prime[1] = 0;
	for (ll p = 2; p * p <= n; p++) {
		if (prime[p] == 1) {
			for (ll i = p * p; i <= n; i += p)
				prime[i] = 0;
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	SieveOfEratosthenes (1e6 + 2);
	ll tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n;

		ll x = n;

		ll flag = 0;
		while (1) {
			ll n = x;
			ll pos = 0;
			ll num[8];
			while (n > 0) {
				num[pos++] = n % 10;
				n /= 10;
			}
			ll sz = pos;
			sort (num, num + sz);

			do {
				ll temp = 0;
				pos = 0;
				while (pos < sz) {
					temp = temp * 10 + num[pos];
					pos++;
				}

				if (prime[temp] == 1) {
					flag = 1;
					cout << x << "\n";
					break;
				}
				// cout << temp << " " << prime[temp] << endl;
			} while (next_permutation (num, num + sz));

			if (flag == 1) break;
			x--;
		}
	}
	return 0;
}
