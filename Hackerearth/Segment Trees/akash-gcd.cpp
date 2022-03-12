/*
				C++
				encoding:UTF-8
				Modified: <04/Apr/2019 12:27:51 PM>

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
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e6 + 5;
int arr[N], tree[4 * N];
int phi[N], F[N];

int n;

void precompute () {
	fr (i, 1, N) {
		phi[i] += i;
		for (int j = 2 * i; j < N; j += i) {
			phi[j] -= phi[i];
		}
	}
	fr (i, 1, N) {
		for (int j = i; j < N; j += i) {
			F[j] += j / i * phi[i];
			F[j] %= mod;
		}
	}
}

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		int x = F[arr[start]];
		tree[node] = x;
		return;
	}
	int mid = (start + end) / 2;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
	tree[node] %= mod;
}

void update (int node, int index, int val, int start = 1, int end = n) {
	if (start == end) {
		arr[index] = val;
		int x = F[val];
		x %= mod;
		tree[node] = x;
		return;
	}
	int mid = (start + end) / 2;

	if (start <= index and mid >= index)
		update (2 * node, index, val, start, mid);
	else
		update (2 * node + 1, index, val, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
	tree[node] %= mod;
}

int query (int node, int l, int r, int start = 1, int end = n) {
	if (end < l or start > r) return 0;
	if (start >= l and end <= r) return tree[node];

	int mid = (start + end) / 2;
	int p = query (2 * node, l, r, start, mid);
	int q = query (2 * node + 1, l, r, mid + 1, end);

	return (p + q) % mod;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	precompute ();

	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	build ();

	int tc;
	cin >> tc;
	while (tc--) {
		string c;
		int x, y;
		cin >> c >> x >> y;
		if (c == "C") {
			pr1 (query (1, x, y));
		} else {
			update (1, x, y);
		}
	}

	return 0;
}
