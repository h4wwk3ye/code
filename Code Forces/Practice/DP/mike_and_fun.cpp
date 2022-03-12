/*
				C++
				encoding: UTF-8
				Modified: <30/Jun/2019 05:56:13 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         umap                   unordered_map
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define         pr1(x)                 cout<<x<<"\n"
#define         pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define         pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	int arr[n + 1][m + 1];
	fr (i, 1, n + 1) {
		fr (j, 1, m + 1) {
			cin >> arr[i][j];
		}
	}
	int mx = 0;
	fr (i, 1, n + 1) {
		int curr = 0;
		fr (j, 1, m + 1) {
			if (arr[i][j] == 1) {
				curr++;
				mx = max (mx, curr);
			} else
				curr = 0;
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		arr[u][v] = 1 - arr[u][v];
		int curr = 0;
		fr (i, 1, m + 1) {
			if (arr[u][i] == 1) {
				curr++;
				mx = max (mx, curr);
			} else
				curr = 0;
		}
		pr1 (mx);
	}
	return 0;
}
