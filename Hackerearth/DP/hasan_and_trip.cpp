/*
				C++
				encoding:UTF-8
				Modified: <23/Apr/2019 08:17:29 AM>

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
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int n;
const int N = 1e5 + 5;
pii loc[N];
int hap[N];

long double dp[N];

long double dis (int x1, int y1, int x2, int y2) {
	return sqrt (pow (x1 - x2, 2) + pow (y1 - y2, 2));
}

long double solve (int i) {
	if (i == n) {
		return hap[i];
	}
	if (dp[i] != 0) return dp[i];
	long double mx = -1 * LONG_MAX;
	fr (j, i + 1, n + 1) {
		mx = max (mx, hap[i] + solve (j) - dis (loc[i].ff, loc[i].ss, loc[j].ff, loc[j].ss));
	}
	dp[i] = mx;
	return mx;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 1, n + 1) {
		int x, y, z;
		cin >> x >> y >> z;
		loc[i] = {x, y};
		hap[i] = z;
	}
	cout << fixed;
	cout << setprecision (6);
	pr1 (solve (1));

	return 0;
}
