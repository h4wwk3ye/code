#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define fast                           \
	ios_base::sync_with_stdio (false); \
	cin.tie (NULL);
#define ff first
#define ss second
#define nil -10e+9
#define initial 0
#define waiting 1
#define visit 2
#define inf 10e+9
#define mx 200005
#define mxx 1000005
#define mod 1000000007
#define pr pair< ll, ll >
#define pp_queue priority_queue< pr, vector< pr >, greater< pr > >
#define dp_queue priority_queue< int, vector< int >, greater< int > >
#define sp_queue priority_queue< int >
#define fr(i, p, q) for (int i = p; i < q; ++i)
#define frr(i, p, q) for (int i = p; i <= q; ++i)
#define mem(a, b) memset (a, b, sizeof (a))
#define len(a) (int)a.size ()
#define input freopen ("input.txt", "r", stdin);
#define output freopen ("output.txt", "w", stdout);
#define debug(arr, j, n) fr (i, j, n) cout << arr[i] << " ";

ll power (ll a, ll b) {
	ll aa = 1;
	while (b) {
		if (b & 1) {
			aa = aa * a;
			aa %= mod;
		}
		a = a * a;
		a %= mod;
		b /= 2;
	}
	return aa;
}

using namespace std;

vector< int > f (5000005, 1);
vector< int > prime (5000005, 0);
vector< int > pre (5000005, 0);

void func () {
	for (int i = 2; i < 5000005; i++) {
		for (int j = i; j < 5000005; j += i)
			f[j] += 1;
	}
}

void sieve () {
	prime[0] = prime[1] = 1;

	for (int i = 2; i * i < 5000005; i++) {
		if (prime[i] == 0) {
			for (int j = 2 * i; j < 5000005; j += i) {
				prime[j] = 1;
			}
		}
	}
}

int main () {
	func ();
	sieve ();

	fr (i, 1, 5000004) {
		pre[i] = pre[i - 1];

		if (prime[f[i]] == 0) pre[i]++;
	}

	int t;
	cin >> t;

	while (t--) {
		int l, r;
		cin >> l >> r;

		cout << pre[r] - pre[l - 1] << "\n";
	}

	return 0;
}
