/*
				C++
				encoding:UTF-8
				Modified: <02/Apr/2019 12:20:13 PM>

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

void build (int node, int start, int end) {
	if (start == end) {
		arr[start] = 1;
		tree[node] = 1;
		return;
	}

	int mid = (start + end) / 2;

	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update (int node, int index, int start, int end) {
	if (start == end) {
		arr[index] = 0;
		tree[node] = 0;
		return;
	}
	int mid = (start + end) / 2;

	if (start <= index and mid >= index)
		update (2 * node, index, start, mid);
	else
		update (2 * node + 1, index, mid + 1, end);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query (int node, int k, int start, int end, int curr) {
	if (start == end) {
		return start;
	}

	int mid = (start + end) / 2;

	if (k <= curr + tree[2 * node])
		return query (2 * node, k, start, mid, curr);
	else {
		curr += tree[2 * node];
		return query (2 * node + 1, k, mid + 1, end, curr);
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n;
	cin >> n;

	build (1, 1, n);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, k;
		cin >> a >> k;

		// prv (tree, 1, 4 * n + 1);

		if (a == 0) {
			update (1, k, 1, n);
		} else {
			if (tree[1] < k)
				pr1 (-1);
			else
				pr1 (query (1, k, 1, n, 0));
		}
	}

	return 0;
}
