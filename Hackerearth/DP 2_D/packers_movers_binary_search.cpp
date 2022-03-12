/*
				C++
				encoding:UTF-8
				Modified: <10/May/2019 10:31:14 PM>

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


int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int m;
	cin >> m;
	int n;
	cin >> n;
	int arr[n];
	int low = 0, high = 1e9, ans;
	fr (i, 0, n) {
		cin >> arr[i];
	}
	while (low < high) {
		int mid = (low + high + 1) / 2;
		int c = 0;
		int cnt = 1;
		fr (i, 0, n) {
			if (c + arr[i] > mid) {
				c = 0;
				cnt++;
				i--;
				if (cnt == m + 1) break;
			} else {
				c += arr[i];
			}
		}
		if (cnt <= m) {
			high = mid - 1;
		} else
			low = mid;
	}
	pr1 (low + 1);
	return 0;
}
