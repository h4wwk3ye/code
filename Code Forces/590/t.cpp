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

int main () {
	int n, k;
	cin >> n >> k;

	int a[n];

	deque< int > d;

	unordered_map< int, int > mpp;
	mpp.max_load_factor (0.25);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (mpp[a[i]] == 0 and d.size () < k) {
			mpp[a[i]] = 1;
			d.push_front (a[i]);
		} else if (mpp[a[i]] == 0 and d.size () == k) {
			int x = d.back ();
			mpp[x]--;
			mpp[a[i]] = 1;
			// cout<<x<<" ";
			// cout<<"run"<<' ';
			d.pop_back ();
			d.push_front (a[i]);
		}

		// cout<<a[i]<<" "<<d.size()<<" "<<mpp.size()<<"\n";
	}

	cout << d.size () << "\n";
	while (d.size () > 0) {
		cout << d.front () << " ";
		d.pop_front ();
	}

	return 0;
}
