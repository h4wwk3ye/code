// Sanjit_Prasad
#include <bits/stdc++.h>
#define db double
#define ff first
#define ss second
#define initial 0
#define waiting 1
#define visited 2
#define mx 1000005
#define mxx 4000005
#define mod 1000000007
#define inf 1000000009
#define nil -1000000009
#define pb push_back
#define mp make_pair
#define pr pair< ll, ll >
#define ll long long int
#define ull unsigned long long int
#define mem(a, b) memset (a, b, sizeof (a))
#define fr(i, p, q) for (int i = p; i < q; ++i)
#define frr(i, p, q) for (int i = p; i <= q; ++i)
#define input freopen ("input.txt", "r", stdin);
#define output freopen ("output.txt", "w", stdout);
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


int main () {
	// input;
	ios_base::sync_with_stdio (false);
	// Please change array size before submission!

	ll q;
	cin >> q;
	while (q--) {
		ll k, kk, n, a, b;
		cin >> k >> n >> a >> b;
		kk = k;

		if (k <= n * b) {
			cout << -1 << endl;
		} else if (n * a < k) {
			cout << n << endl;
		} else {
			ll mn = 1, mm = n, ans = 0;
			while (mn < mm) {
				ll mid = (mn + mm) / 2;
				// cout<<mid<<endl;
				if ((mid >= n) && mid * a < k) {
					mn = mid;
					ans = max (ans, mid);
				} else if ((mid * a + (n - mid) * b) < k) {
					ans = max (ans, mid);
					mn = mid + 1;
				} else {
					mm = mid;
				}
			}

			cout << ans << endl;
		}
	}

	return 0;
}
