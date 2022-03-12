/*
				C++
				encoding:UTF-8
				Modified: <07/Apr/2019 11:10:25 AM>

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
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 5e5 + 5;
ll tree[4 * N], arr[N], mn[4 * N];
int n;

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node] = 3 * arr[start];
		mn[node] = arr[start];
		// pr2 (start, mn[node]);
		return;
	}
	int mid = (start + end) / 2;
	build (node * 2, start, mid);
	build (node * 2 + 1, mid + 1, end);
	// cout << arr[start] << " " << arr[end] << " " << mn[2 * node] << " " << mn[2 * node + 1] << endl;
	mn[node] = min (mn[2 * node], mn[2 * node + 1]);
	tree[node] = arr[start] + arr[end] + mn[node];
}

int main () {
	// ios_base::sync_with_stdio (false), cin.tie (0);
	ll k;
	cin >> n >> k;
	fr (i, 1, n + 1) cin >> arr[i];
	build ();
	prv (tree, 1, 4 * n);
	return 0;
}
