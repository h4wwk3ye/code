/*
				C++
				encoding:UTF-8
				Modified: <15/Jun/2019 06:50:51 PM>

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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n;
	cin >> n;
	int arr[n];
	fr (i, 0, n) {
		cin >> arr[i];
	}
	sort (arr, arr + n);
	int low = arr[0], high = arr[n - 1], j = 0, k = n - 1;
	int ans = arr[0], flag = 0;
	vector< pii > v;
	while (j < k) {
		if (k - j == 1) {
			ans = abs (high - low);
			v.push_back ({max (high, low), min (high, low)});
			break;
		}
		if (flag == 0) {
			v.push_back ({low, high});
			ans = low - high;
			low = ans;

			high = arr[--k];
			flag = 1;

		} else {
			v.push_back ({high, low});
			ans = high - low;
			high = ans;

			low = arr[++j];
			flag = 0;
		}
	}
	cout << ans << endl;
	for (ll i = 0; i < n - 1; i++)
		cout << v[i].ff << " " << v[i].ss << endl;
	return 0;
}
