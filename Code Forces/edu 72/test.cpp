#include <bits/stdc++.h>
#define fast                       \
	ios_base::sync_with_stdio (0); \
	cin.tie (0);                   \
	cout.tie (0);
#define debug cout << "here" << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD = 1e9 + 7;
#define MAX 100005
#define eps 1e-9
#define infi 1000000
#define intial 0
#define waiting 1
#define visited 2
#define nill -1
#define max3(a, b, c) max (a, max (b, c))
#define min3(a, b, c) min (a, min (b, c))
#define PII pair< ll, ll >
#define input freopen ("input.txt", "r", stdin);
#define output freopen ("output.txt", "w", stdout);
using namespace std;
int main () {
	fast;
	int t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		ll maxdif_d, maxdif_h, max_d, max_h;
		cin >> maxdif_d >> maxdif_h;
		max_d = maxdif_d;
		max_h = maxdif_h;

		for (int i = 1; i < n; i++) {
			ll d, h;
			cin >> d >> h;
			if (d > max_d) {
				max_d = d, max_h = h;
			}
			if (maxdif_d - maxdif_h < d - h) {
				maxdif_d = d;
				maxdif_h = h;
			}
		}
		if (maxdif_d - maxdif_h <= 0) {
			if (x <= max_d)
				cout << 1 << endl;
			else
				cout << -1 << endl;
		} else {
			ll ans, diff = maxdif_d - maxdif_h;
			if (x <= max_d) {
				cout << 1 << endl;
				continue;
			}

			ans = ceil ((x - max_d) / (1.0 * diff));
			ans++;
			cout << ans << endl;
		}
	}
	return 0;
}
