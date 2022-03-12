/*
				C++
				encoding:UTF-8
				Modified: <12/Apr/2019 05:53:15 PM>

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

bool ispal (string x) {
	int i = 0;
	int j = len (x) - 1;
	if (j == 0) return false;
	while (i < j) {
		if (x[i] != x[j]) return false;
		i++;
		j--;
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	string s;
	cin >> s;
	int n = len (s);
	int ans = 0;
	fr (i, 0, n) {
		fr (j, i, n) {
			fr (k, j + 1, n) {
				fr (l, k, n) {
					string a = s.substr (i, n - j);
					string b = s.substr (k, n - l);
					cout << a << " " << b << endl;
					string x = s.substr (i, j + 1) + s.substr (k, l + 1);
					if (ispal (x)) ans++;
				}
			}
		}
	}
	pr1 (ans);

	return 0;
}
