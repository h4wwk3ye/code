/*
				C++
				encoding:UTF-8
				Modified: <13/May/2019 07:27:03 PM>

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

// Miller-Rabin

bool isprime (ll x) {
	fr (i, 0, 40) {
		ll a = 1 + rand () % x;
		if (a == x) a--;
		if (powermod (a, x - 1, x) != 1) return false;
	}
	return true;
}

bool check (ll x) {
	if (isprime (x)) return false;
	ll pf = x % (ll) pow (10, (ll) log10 (x));
	ll pba = x / 10;
	bool ans = false;
	if (check (pf) or check (pba)) ans = true;
	return !ans;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		ll x;
		cin >> x;
		if (!check (x))
			pr1 ("Alice");
		else
			pr1 ("Bob");
	}


	return 0;
}
