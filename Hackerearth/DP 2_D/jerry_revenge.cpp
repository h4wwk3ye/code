/*
				C++
				encoding:UTF-8
				Modified: <07/Jun/2019 12:25:01 PM>

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

const int N = 505;
int n, m;
int arr[N][N];
int zeroes[N][N];
int mx;
int x, y, inc;
int ans = 0;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> m;
	fr (i, 1, n + 1) fr (j, 1, m + 1) {
		cin >> arr[i][j];
		if (arr[i][j] == 1) ans++;
	}
	fr (i, 1, n + 1) {
		fr (j, 1, m + 1) {
			zeroes[i][j] = zeroes[i - 1][j] + zeroes[i][j - 1] - zeroes[i - 1][j - 1];
			if (arr[i][j] == 0)
				zeroes[i][j]++;
			else
				zeroes[i][j]--;
		}
	}

	fr (i, 1, n + 1) {
		fr (j, 1, m + 1) {
			int curr = 0;
			while (curr + i <= n and curr + j <= m) {
				/*int cnt = 0;
				fr (k, i, i + curr + 1) {
					cnt += zeroes[k][j + curr] - zeroes[k][j - 1];
				}*/
				int cnt = zeroes[i + curr][j + curr] - zeroes[i - 1][j + curr] -
						  zeroes[i + curr][j - 1] + zeroes[i - 1][j - 1];
				if (cnt > mx) {
					mx = cnt;
					x = i;
					y = j;
					inc = curr;
				}
				curr++;
			}
		}
	}
	if (x == 0 and y == 0) {
		pr1 (ans - 1);
		return 0;
	}

	fr (i, x, x + inc + 1) {
		fr (j, y, y + inc + 1) {
			if (arr[i][j] == 1)
				ans--;
			else
				ans++;
		}
	}
	pr1 (ans);

	return 0;
}
