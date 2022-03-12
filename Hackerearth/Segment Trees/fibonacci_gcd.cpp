/*
				C++
				encoding:UTF-8
				Modified: <04/Apr/2019 01:50:13 PM>

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
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (ll i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const ll N = 1e5 + 5;
ll arr[N], tree[4 * N];

ll n;

void multiply (ll F[][2], ll M[][2]) {
	ll x = (((F[0][0] % mod * M[0][0] % mod) % mod) + ((F[0][1] % mod * M[1][0] % mod) % mod)) % mod;
	ll y = (((F[0][0] % mod * M[0][1] % mod) % mod) + ((F[0][1] % mod * M[1][1] % mod) % mod)) % mod;
	ll z = (((F[1][0] % mod * M[0][0] % mod) % mod) + ((F[1][1] % mod * M[1][0] % mod) % mod)) % mod;
	ll w = (((F[1][0] % mod * M[0][1] % mod) % mod) + ((F[1][1] % mod * M[1][1] % mod) % mod)) % mod;
	F[0][0] = x, F[0][1] = y, F[1][0] = z, F[1][1] = w;
}

void power (ll matrix[2][2], ll n) {
	if (n == 0 || n == 1) return;
	ll res[2][2] = {{1, 1}, {1, 0}};
	power (matrix, n / 2);
	multiply (matrix, matrix);
	if (n & 1) multiply (matrix, res);
}

ll fib (ll n) {
	ll matrix[2][2] = {{1, 1}, {1, 0}};
	power (matrix, n - 1);
	return matrix[0][0];
}


void build (ll node = 1, ll start = 1, ll end = n) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	ll mid = (start + end) / 2;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);
	tree[node] = __gcd (tree[2 * node], tree[2 * node + 1]);
	tree[node] %= mod;
}

ll query (ll node, ll l, ll r, ll start = 1, ll end = n) {
	if (start > r or end < l) return 0;
	if (start >= l and end <= r) return tree[node];

	ll mid = (start + end) / 2;

	return __gcd (query (2 * node, l, r, start, mid), query (2 * node + 1, l, r, mid + 1, end));
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	ll tc;
	cin >> n >> tc;
	fr (i, 1, n + 1) cin >> arr[i];

	build ();
	while (tc--) {
		ll l, r;
		cin >> l >> r;
		pr1 (fib (query (1, l, r)) % mod);
	}
	return 0;
}
