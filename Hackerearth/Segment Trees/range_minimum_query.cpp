/*
				C++
				encoding:UTF-8
				Modified: <14/Sep/2019 07:11:55 PM>

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

const int N = 4e5 + 5;
int arr[N];
int tree[4 * N];

void build (int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);

	tree[node] = min (tree[2 * node], tree[2 * node + 1]);
}

int query (int node, int start, int end, int l, int r) {
	if (start > r or end < l) return 2e9 - 5;
	if (start >= l and end <= r) return tree[node];

	int mid = (start + end) / 2;

	return min (query (2 * node, start, mid, l, r), query (2 * node + 1, mid + 1, end, l, r));
}

void update (int node, int index, int val, int start, int end) {
	if (start == end) {
		arr[index] = val;
		tree[node] = val;
		return;
	}

	int mid = (start + end) / 2;

	if (start <= index and index <= mid) {
		update (2 * node, index, val, start, mid);
	} else {
		update (2 * node + 1, index, val, mid + 1, end);
	}
	tree[node] = min (tree[2 * node], tree[2 * node + 1]);
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, q;
	cin >> n >> q;

	fr (i, 1, n + 1) cin >> arr[i];

	build (1, 1, n);

	while (q--) {
		char x;
		int l, r;
		cin >> x >> l >> r;

		if (x == 'q') {
			pr1 (query (1, 1, n, l, r));
		} else {
			update (1, l, r, 1, n);
		}
	}

	return 0;
}
