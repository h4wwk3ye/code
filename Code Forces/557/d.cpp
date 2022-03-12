/*
				C++
				encoding:UTF-8
				Modified: <05/May/2019 08:29:46 AM>

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

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, m;
	cin >> n >> m;
	set< pii > d;
	fr (i, 0, m) {
		int a, b;
		cin >> a >> b;
		d.insert ({a, b});
		d.insert ({b, a});
	}
	int a, b, x, y;
	fr (i, 1, n) {
		bool flag = true;
		for (auto k : d) {
			x = k.ff;
			y = k.ss;
			a = (x + i) % (n + 1);
			b = (y + i) % (n + 1);
			if (a < x) a++;
			if (b < y) b++;

			if (d.find ({a, b}) == d.end ()) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			pr1 ("YES");
			return 0;
		}
	}
	pr1 ("NO");
	return 0;
}
