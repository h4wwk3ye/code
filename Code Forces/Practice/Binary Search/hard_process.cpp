/*
				C++
				encoding:UTF-8
				Modified: <21/Mar/2019 02:11:41 PM>

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
#define		 prv(v, s, n)           for (int i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, k;
	cin >> n >> k;
	int arr[n];
	fr (i, 0, n) {
		cin >> arr[i];
	}
	int cnt = 0;
	int l = 0, mx = 0;
	int left = 0, right = 0;
	fr (i, 0, n) {
		if (arr[i] == 0) cnt++;
		while (cnt > k) {
			if (arr[l] == 0) cnt--;
			l++;
		}
		// mx = max (mx, (int) i - l + 1);
		if (i - l + 1 > mx) {
			mx = i - l + 1;
			left = l;
			right = i;
		}
	}
	pr1 (mx);
	if (left == right) {
		if (k == 1) arr[left] = 1;
		prv (arr, 0, n);
		return 0;
	}
	fr (i, left, right + 1) arr[i] = 1;
	prv (arr, 0, n);
	return 0;
}
