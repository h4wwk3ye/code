/*
				C++
				encoding:UTF-8
				Modified: <23/May/2019 07:16:48 PM>

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
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {
    ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;
}

// clang-format on

const int N = 21;
int matrix[N][N];
int dp1[N][N], dp2[N][N];
int n;

bool check (int i, int j) {
	return (i >= 1 and i <= n and j >= 1 and j <= n);
}


int s1 (int i, int j) {
	if (!check (i, j)) return 0;
	if (i == n and j == n) return matrix[i][j];
	if (dp1[i][j]) return dp1[i][j];
	dp1[i][j] = max (dp1[i][j], matrix[i][j] + max (s1 (i + 1, j), s1 (i, j + 1)));
	return dp1[i][j];
}

int s2 (int i, int j) {
	if (!check (i, j)) return 2e9;
	if (i == 1 and j == 1) return matrix[1][1];
	if (dp2[i][j] < 1e9) return dp2[i][j];
	dp2[i][j] = min (dp2[i][j], matrix[i][j] + min (s2 (i - 1, j), s2 (i, j - 1)));
	return dp2[i][j];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 1, n + 1) {
		fr (j, 1, n + 1) {
			cin >> matrix[i][j];
			dp2[i][j] = 1e9;
		}
	}
	cout << s1 (1, 1) << " ";
	cout << s2 (n, n) << " ";
	return 0;
}
