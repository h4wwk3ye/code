/*
				C++
				encoding:UTF-8
				Modified: <03/Apr/2019 08:49:04 AM>

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

typedef pair< int, pii > node;

const int N = 1e6 + 5;
string s;
int n;
int t[4 * N], o[4 * N], c[4 * N];


void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		if (s[start - 1] == '(')
			o[start]++;
		else
			c[start]++;
		return;
	}

	int mid = (start + end) / 2;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);

	int tmp = min (o[2 * node], c[2 * node + 1]);
	t[node] = t[2 * node] + t[2 * node + 1] + tmp;
	o[node] = o[2 * node] + o[2 * node + 1] - tmp;
	c[node] = c[2 * node] + c[2 * node + 1] - tmp;
}

node query (int node, int l, int r, int start = 1, int end = n) {
	if (start > r or end < r) return node (0, pii (0, 0));

	if (start >= l and end <= r) return node (t[node], pii (o[node], c[node]));

	int mid = (start + end) / 2;
	node a = query (2 * node, l, r, start, mid);
	node b = query (2 * node + 1, l, r, mid + 1, end);

	int tmp = min (a.ss.ff, b.ss.ss);
	int t = a.ff + b.ff + tmp;
	int o = a.ss.ff + b.ss.ff - tmp;
	int c = a.ss.ss + b.ss.ss - tmp;
	return node (t, pii (o, c));
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);

	cin >> s;
	n = len (s);
	build ();
	int tc;
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		query (1, l, r);
	}

	return 0;
}
