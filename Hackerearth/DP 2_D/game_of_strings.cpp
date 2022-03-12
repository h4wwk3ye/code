/*
				C++
				encoding:UTF-8
				Modified: <07/Jun/2019 11:28:46 AM>

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

// clang-format on

string x, y;
int l1, l2;
int dp[5005][5005];
set< char > vowels;
int ans;

int solve (int i, int j) {
	if (i >= l1 or j >= l2) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (x[i] == y[j] and vowels.count (x[i]) == 0) {
		dp[i][j] = 1 + solve (i + 1, j + 1);
	} else {
		dp[i][j] = max (solve (i + 1, j), max (solve (i, j + 1), solve (i + 1, j + 1)));
	}
	return dp[i][j];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	vowels.insert ({'a', 'e', 'i', 'o', 'u'});
	cin >> x >> y;
	l1 = len (x);
	l2 = len (y);
	reset (dp, -1);
	pr1 (solve (0, 0));
	return 0;
}
