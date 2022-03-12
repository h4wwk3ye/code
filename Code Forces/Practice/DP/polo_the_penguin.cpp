/*
				C++
				encoding:UTF-8
				Modified: <11/May/2019 08:58:31 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
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
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, m, d;
	cin >> n >> m >> d;
	int matrix[n][m];
	int mn = 1e9, mx = 0;
	int chk;
	bool flag = true;
	fr (i, 0, n) fr (j, 0, m) {
		cin >> matrix[i][j];
		mn = min (mn, matrix[i][j]);
		mx = max (mx, matrix[i][j]);
		if (i == 0 and j == 0)
			chk = matrix[i][j] % d;
		else if (matrix[i][j] % d != chk)
			flag = false;
	}

	if (flag == false) {
		pr1 (-1);
		return 0;
	}

	umap< int, int > mp;
	mp.reserve ((int) 1e5 + 5);
	mp.max_load_factor (0.25);

	fr (i, 0, n) {
		fr (j, 0, m) {
			int cnt = 0;
			for (int k = matrix[i][j]; k >= mn; k -= d) {
				mp[k] += cnt;
				cnt++;
			}
			cnt = 0;
			for (int k = matrix[i][j]; k <= mx; k += d) {
				mp[k] += cnt;
				cnt++;
			}
		}
	}

	int ans = 1e9;
	int mini = 1e9;
	for (auto k : mp) {
		ans = min (ans, k.ss);
	}
	pr1 (ans);

	return 0;
}
