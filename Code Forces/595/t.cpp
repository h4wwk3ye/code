#include <bits/stdc++.h>

#define ll long long
#define int long long
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
#define hash_map(mpp)            \
	unordered_map< ll, ll > mpp; \
	mpp.reserve (1048576);       \
	mpp.max_load_factor (0.25);
#define all(a) a.begin (), a.end ()
#define lower(a, x) lower_bound (all (a), x) - a.begin ()
#define upper(a, x) upper_bound (all (a), x) - a.begin ()
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

const int N = 1e4 + 5;
int num = 0;
int freq[40];
int happy[N];
int seq[N], ans[N];

signed main () {
	freq[0] = 1;
	for (int i = 1; i < 40; i++) {
		freq[i] = freq[i - 1] * 3;
	}
	happy[0] = 1;
	happy[1] = 3;
	happy[2] = happy[0] + happy[1];
	int temp = 3;
	for (int i = 2; i < 20; i++) {
		happy[temp] = freq[i];
		temp++;
		int thinking = temp;
		for (int j = 0; j < thinking - 1; j++) {
			happy[temp] = freq[i] + happy[j];
			// cout << (temp) << " ";
			temp++;
		}
		/*printf("debug temp %d\n", temp);
		for (int j = 0; j < temp; j++){
			printf("%d\n", happy[j]);
		}*/
	}

	cin >> num;


	for (int i = 0; i < num; i++) {
		cin >> seq[i];
	}

	for (int i = 0; i < num; i++) {
		int pog = 1020;
		while (happy[pog] >= seq[i]) {
			ans[i] = happy[pog];
			pog--;
		}
	}

	for (int i = 0; i < num; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}