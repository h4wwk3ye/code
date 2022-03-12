/*
				C++
				encoding:UTF-8
				Modified: <10/Apr/2019 07:50:04 PM>

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
const int N = 5e4 + 5;
int n;
int arr[55];
int dp[55][N];
int total = 0;

void init () {
	fr (i, 0, 55) {
		fr (j, 0, N) {
			dp[i][j] = 0;
		}
	}
}

int main () {
	// ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		init ();
		cin >> n;
		fr (i, 1, n + 1) {
			cin >> arr[i];
			total += arr[i];
		}
		sort (arr + 1, arr + n + 1);
		ve< set< int > > s (N);

		fr (i, 1, n + 1) {
			fr (j, 1, total + 1) {
				pr2 (i, j);
				if (arr[i] > j)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i - 1][j - arr[i]];

				if (j == arr[i]) {
					dp[i][j] = 1;
					s[j].insert (1);
					continue;
				}
				if (!dp[i][j]) continue;
				if (!len (s[j - arr[i]])) continue;
				for (int x : s[j - arr[i]]) {
					s[j].insert (1 + x);
				}
			}
		}

		pr1 ("here");
		ve< set< int > > p (total + 1);
		int mn = 1e9, mx = -1;
		int mni, mxi;

		fr (j, 1, total + 1) {
			for (int i : s[j]) {
				p[j].insert (i);
			}
			int l = len (p[j]);
			if (l == 0) continue;
			if (l > mx) {
				mx = l;
				mxi = j;
			}
			if (l < mn) {
				mn = l;
				mni = j;
			}
		}
		pr2 (mn, mni);
		pr2 (mx, mxi);
	}


	return 0;
}
