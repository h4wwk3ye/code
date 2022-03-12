/*
				C++
				encoding:UTF-8
				Modified: <24/Apr/2019 07:16:20 AM>

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

int n;
const int N = 505;
// int arr[N];

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

int solve (int i, int arr[]) {
	if (i >= n) return 0;
	if (i == n - 1) {
		bool flag = true;
		fr (i, 0, n) {
			if (arr[i] != -1) {
				flag = false;
				break;
			}
		}
		if (flag)
			return 0;
		else
			return INT_MAX;
	}
	while (arr[i] == -1)
		i++;

	int p = lower_bound (all (primes), arr[i]) - primes.begin ();
	int q = lower_bound (all (primes), arr[i + 1]) - primes.begin ();
	if (arr[i] == primes[p] and arr[i + 1] == primes[q] and p + 1 == q) {
		arr[i] = -1;
		arr[i + 1] = -1;
		return 1 + solve (i + 2, arr);
	} else {
		arr[i]++;
		solve ()
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	SieveOfEratosthenes ((int) 1e6);
	cin >> n;
	int arr[n];
	fr (i, 0, n) cin >> arr[i];
	solve (0, arr);
	return 0;
}
