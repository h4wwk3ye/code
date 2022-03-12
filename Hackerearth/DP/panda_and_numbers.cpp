/*
				C++
				encoding:UTF-8
				Modified: <19/Apr/2019 04:15:13 PM>

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

const int N = 1e6 + 5;
int dp[N];
ve< int > panda;


void precompute () {
	fr (i, 1, 8) {
		panda.pb (pow (i, i));
	}
	fr (i, 0, 7) dp[panda[i]] = 1;
	fr (i, 13, 1e6 + 5) {
		int n = i;
		int r;
		int x = 0;
		while (n > 0) {
			r = n % 10;
			n /= 10;
			x = x || dp[i - r * r];
		}
		dp[i] = x;
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	precompute ();
	int tc;
	cin >> tc;
	prv (dp, 0, 20);
	while (tc--) {
		int n;
		cin >> n;
		if (dp[n])
			pr1 ("Yes");
		else
			pr1 ("No");
	}
	return 0;
}
