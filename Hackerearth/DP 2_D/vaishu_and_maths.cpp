/*
				C++
				encoding:UTF-8
				Modified: <04/Jun/2019 11:13:12 PM>

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

int l, n, x, y;
int arr[105];
int dp[105][(int) 2e4 + 5];


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> l >> n >> x >> y;
	fr (i, 1, n + 1) cin >> arr[i];
	dp[0][l] = 1;
	fr (i, 1, n + 1) {
		fr (j, 1, 1e4 + 1) {
			if ((j - arr[i] >= x and j - arr[i] <= y and dp[i - 1][j - arr[i]]) or
				(j + arr[i] >= x and j + arr[i] <= y and dp[i - 1][j + arr[i]])) {
				dp[i][j] = 1;
			}
		}
	}
	ve< int > s;
	fr (i, x, y + 1) if (dp[n][i] == 1) s.pb (i);
	int tc;
	cin >> tc;
	int l = len (s);
	while (tc--) {
		char a;
		int b;
		cin >> a >> b;
		if (l == 0) {
			pr1 ("NO");
			continue;
		}
		if (a == '>') {
			auto it = upper_bound (all (s), b);
			if (it != s.end ())
				pr1 ("YES");
			else
				pr1 ("NO");
		} else {
			int p = *s.begin ();
			if (p >= b)
				pr1 ("NO");
			else
				pr1 ("YES");
		}
	}
	return 0;
}
