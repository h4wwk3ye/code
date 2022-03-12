/*
				C++
				encoding:UTF-8
				Modified: <20/Mar/2019 12:29:27 PM>

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
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on
const int N = 1e5 + 5;
int vis[N];

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	// freopen ("inp.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	int arr[n];
	fr (i, 0, n) cin >> arr[i];

	int s[m + 1];
	fr (i, 1, m + 1) s[i] = k;

	int ans = 0;
	int i = 0;
	int cnt = 0;
	int high = 1e9;
	int flag = 0;
	for (; i < n; i++) {
		int x = arr[i];

		if (cnt == m) break;

		if (s[x] != 0) {
			s[x]--;
			if (s[x] == 0) {
				cnt++;
				high = min (high, x);
			}
			continue;
		}

		ans++;
		x = high;
		int prev = x;
		while (x <= m and s[x] == 0) {
			x++;
			if (x == prev) {
				flag = 1;
				break;
			}
			if (x == m + 1) x = high;
		}
		if (flag) break;
		s[x]--;
		if (s[x] == 0) {
			high = min (high) cnt++;
		}
	}
	pr1 (ans + (n - i));

	return 0;
}
