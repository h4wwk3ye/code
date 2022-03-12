/*
				C++
				encoding:UTF-8
				Modified: <16/Apr/2019 10:11:45 PM>

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
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on
const int N = 2e5 + 5;
int ans[N];
int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, k;
	cin >> n >> k;
	set< int > s;
	int arr[n];
	umap< int, int > mp;
	fr (i, 0, n) {
		int x;
		cin >> x;
		arr[i] = x;
		s.insert (x);
		mp[x] = i;
	}
	int flag = 0;
	while (!s.empty ()) {
		auto it = s.end ();
		int p = *x;
		s.erase (it);
		int pos = mp[p];
		ans[pos] = flag;
		for (i, pos + 1, k + 1) {
			s.erase ()
		}
	}
	return 0;
}
