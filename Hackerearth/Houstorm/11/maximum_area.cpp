/*
				C++
				encoding:UTF-8
				Modified: <21/May/2019 08:15:48 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
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
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 155;
int matrix[N][N];
int n, t;
int ans = 1;


ve< pii > neighbours (int i, int j) {
	ve< pii > x = {{i - 1, j}, {i, j - 1}, {i, j + 1}, {i + 1, j}};
	return x;
}

bool check (int i, int j) {
	return (i >= 1 and i <= n and j >= 1 and j <= n);
}

void dfs (int i, int j, int r, int rm, int cm) {
	rm = max (rm, i);
	cm = max (cm, j);
	ans = max (ans, rm * cm);
	for (auto ne : neighbours (i, j)) {
		if (check (ne.ff, ne.ss)) {
			if (r + matrix[ne.ff][ne.ss] <= t) dfs (ne.ff, ne.ss, r + matrix[ne.ff][ne.ss], rm, cm);
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> t;
	fr (i, 1, n + 1) fr (j, 1, n + 1) {
		cin >> matrix[i][j];
	}
	dfs (1, 1, 0, 1, 1);
	pr1 (ans);
	return 0;
}
