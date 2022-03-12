/*
				C++
				encoding:UTF-8
				Modified: <09/May/2019 12:24:53 PM>

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

ve< int > primes;

void SieveOfEratosthenes (int n) {
	bool prime[n + 1];
	reset (prime, true);

	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p]) primes.pb (p);
}

string s;
int n;

int palindrome (int left, int right) {
	int l = left;
	while (left >= 0 and right < n and s[left] == s[right]) {
		left--;
		right++;
	}
	return l - left;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	SieveOfEratosthenes (10005);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s;
		n = len (s);
		int mx = 0;
		fr (i, 0, n) {
			int s1 = palindrome (i - 1, i + 1);
			mx = max (mx, 2 * s1 + 1);
			int s2 = palindrome (i, i + 1);
			mx = max (mx, 2 * s2);
		}

		int i = lower_bound (all (primes), mx) - primes.begin ();
		if (primes[i] == mx)
			pr1 ("PRIME");
		else
			pr1 ("NOT PRIME");
	}
	return 0;
}
