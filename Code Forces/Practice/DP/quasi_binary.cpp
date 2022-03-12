/*
				C++
				encoding:UTF-8
				Modified: <11/May/2019 08:23:07 PM>

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

ve< int > coins;

bool compute (int n) {
	bool flag = true;
	while (n > 0) {
		int x = n % 10;
		if (x != 0 and x != 1) {
			flag = false;
			break;
		}
		n /= 10;
	}
	return flag;
}


int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n;
	cin >> n;
	fr (i, 1, n + 1) {
		if (compute (i)) coins.pb (i);
	}

	int dp[n + 1];
	fill (dp, dp + n + 1, 1e9);
	dp[0] = 0;

	int optimal[n + 1];
	fill (optimal, optimal + n + 1, 0);

	fr (i, 1, n + 1) {
		for (int coin : coins) {
			if (coin > i) break;
			if (dp[i] > 1 + dp[i - coin]) {
				dp[i] = 1 + dp[i - coin];
				optimal[i] = coin;
			}
		}
	}
	pr1 (dp[n]);

	int i = n;
	while (i != 0) {
		cout << optimal[i] << " ";
		i -= optimal[i];
	}

	return 0;
}
