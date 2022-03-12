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
	fast;

	int n, m;
	cin >> n >> m;

	int a[n][m], b[n][m], c[n][m];

	fr (i, 0, n) fr (j, 0, m) {
		cin >> a[i][j];
	}
	fr (i, 0, n) fr (j, 0, m) cin >> b[i][j];

	fr (i, 0, n) {
		fr (j, 0, m) {
			if (a[i][j] == b[i][j])
				c[i][j] = 0;
			else
				c[i][j] = 1;
			// cout<<c[i][j];
		}
		// cout<<"\n";
	}
	fr (i, 0, n) {
		fr (j, 0, m) {
			if (c[i][j] == 1) {
				int t1 = i + 1, t2 = j + 1;
				while (t1 < n && c[t1][j] == 0)
					t1++;
				while (t2 < m && c[i][t2] == 0)
					t2++;
				if (t1 == n || t2 == m) {
					cout << "No";
					return 0;
				}
				c[i][t2] = 0;
				c[t1][j] = 0;
				c[t1][t2] = 1 - c[t1][t2];
			}
		}
	}
	cout << "Yes";
}
