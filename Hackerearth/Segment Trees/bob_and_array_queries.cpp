/*
				C++
				encoding:UTF-8
				Modified: <02/Apr/2019 08:41:16 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     unsigned long long
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

const ll N = 5e5 + 5;
ll arr[N], b[N];
ll tree[4 * N];

void update_1 (ll node, ll index, ll start, ll end) {
	if (start == end) {
		arr[index] = 2 * arr[index] + 1;
		tree[node]++;
		return;
	}
	ll mid = (start + end) / 2;

	if (start <= index and mid >= index) {
		update_1 (2 * node, index, start, mid);
	} else {
		update_1 (2 * node + 1, index, mid + 1, end);
	}
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update_2 (ll node, ll index, ll start, ll end) {
	if (start == end) {
		arr[index] = arr[index] / 2;
		tree[node] = __builtin_popcount (arr[index]);
		return;
	}
	ll mid = (start + end) / 2;

	if (start <= index and mid >= index) {
		update_2 (2 * node, index, start, mid);
	} else {
		update_2 (2 * node + 1, index, mid + 1, end);
	}
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query (ll node, ll start, ll end, ll l, ll r) {
	if (start > r or end < l) return 0;
	if (start >= l and end <= r) return tree[node];

	ll mid = (start + end) / 2;

	return query (2 * node, start, mid, l, r) + query (2 * node + 1, mid + 1, end, l, r);
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	ll n, q;
	cin >> n >> q;

	// build (1, 1, n);

	while (q--) {
		ll t, x;
		cin >> t >> x;
		if (t == 1) {
			update_1 (1, x, 1, n);
		} else if (t == 2) {
			update_2 (1, x, 1, n);
		} else {
			ll y;
			cin >> y;
			pr1 (query (1, 1, n, x, y));
		}
	}
	return 0;
}
