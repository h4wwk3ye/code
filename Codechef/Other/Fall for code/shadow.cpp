/*
				C++
				encoding:UTF-8
				Modified: <20/Jun/2019 10:28:16 PM>

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
	int tc;
	cin >> tc;
	ll A, B, L, R;
	while (tc--) {
		cin >> A >> B >> L >> R;

		if (L > R) swap (L, R);


		ll a;
		if (L % A == 0)
			a = L;
		else
			a = (L / A) * A + A;
		ll l;
		l = (R / A) * A;
		ll n = (l - a) / A + 1;
		ll s1 = ((a + l) * n) / 2;


		ll b;
		if (L % B == 0)
			b = L;
		else
			b = (L / B) * B + B;
		l = (R / B) * B;
		n = (l - b) / B + 1;
		ll s2 = ((b + l) * n) / 2;

		ll c = (A * B) / __gcd (A, B);
		if (L % c == 0)
			b = L;
		else
			b = (L / c) * c + c;
		l = (R / c) * c;
		n = (l - b) / c + 1;
		ll s3 = ((b + l) * n) / 2;


		// pr3 (s1, s2, s3);

		s3 = s1 - s3 + s2;
		ll ps = s1 + s2;
		if (s3 % 2 == 0 and (ps % 2 == 0 or ps % 3 == 0)) {
			pr1 ("TRUE LOVE");
		} else if (s3 % 2 == 0 or ps % 2 == 0 or ps % 3 == 0) {
			pr1 ("LOVE");
		} else
			pr1 ("FAKE LOVE");
	}
	return 0;
}
