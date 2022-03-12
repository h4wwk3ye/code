/*
				C++
				encoding:UTF-8
				Modified: <13/Jun/2019 04:37:18 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
//#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<ll, ll>
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

// Taken From :- https://www.quora.com/
// Is-there-any-way-to-solve-the-dquery-problem-on-SPOJ-
// using-persistent-segment-trees-an-online-solution

const ll N = 1e6 + 5;
ll n, q;
ll a[N], pre[N], dummy[N], fact[N];
const ll mod = 1e9 + 7;

void precompute () {
	fact[0] = 1, fact[1] = 1;
	fr (i, 2, N) {
		fact[i] = (fact[i - 1] * i);
		fact[i] %= mod;
	}
}

struct node {
	ll count;
	node *left, *right;
	node (ll count, node* left, node* right) : count (count), left (left), right (right) {
	}
	node* insert (ll l, ll r, ll w);
};

node* null = new node (0, NULL, NULL);
node* root[N];
node* node::insert (ll l, ll r, ll w) {
	if (l <= w and w <= r) {
		if (l == r) {
			return new node (this->count + 1, null, null);
		}
		ll mid = (l + r) >> 1;
		return new node (this->count + 1, this->left->insert (l, mid, w), this->right->insert (mid + 1, r, w));
	}
	return this;
}
ll query (node* a, ll start, ll end, ll l, ll r) {
	if (end < l or start > r) return 0;
	if (start >= l and end <= r) {
		return a->count;
	}
	ll mid = (start + end) >> 1;
	return query (a->left, start, mid, l, r) + query (a->right, mid + 1, end, l, r);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	// freopen ("inp.txt", "r", stdin);
	precompute ();
	cin >> n >> q;
	unordered_map< ll, ll > mp;
	mp.reserve (n + 1);
	mp.max_load_factor (0.25);
	ll curr = 0;
	fr (i, 1, n + 1) {
		ll x;
		cin >> x;
		if (mp.find (x) == mp.end ()) {
			curr++;
			mp[x] = curr;
		}
		a[i] = mp[x];
		dummy[a[i]] = 0;
	}
	fr (i, 1, n + 1) {
		pre[i] = dummy[a[i]];
		dummy[a[i]] = i;
	}

	null->left = null->right = null;
	root[0] = null;
	fr (i, 1, n + 1) {
		root[i] = ((i == 1) ? null : root[i - 1])->insert (0, n, pre[i]);
	}
	ll l1, l2, r1, r2, u, v, A = 0, AA = 0;
	while (q--) {
		cin >> l1 >> l2 >> r1 >> r2;
		u = ((l1 * A) % n + l2) % (n);
		v = ((r1 * A) % n + r2) % (n);
		u++, v++;
		if (u > v) swap (u, v);
		ll x = query (root[u - 1], 0, n, 0, u - 1);
		ll y = query (root[v], 0, n, 0, u - 1);
		A = fact[y - x];
		pr1 (A);
	}
	// pr1 ("Completed");
	return 0;
}
