// Sanjit_Prasad
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define nil -10e+9
#define initial 0
#define waiting 1
#define visited 2
#define inf 10e+9
#define mx 200005
#define mxx 1000005
#define mod 1000000007



#define pr pair< ll, ll >
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
	// ios_base::sync_with_stdio(false);
	// input;
	int arr[6] = {4, 8, 15, 16, 23, 42}, ans[720][6];
	int t = 720, j = 0;
	while (t--) {
		fr (i, 0, 6) ans[j][i] = arr[i];
		j++;
		next_permutation (arr, arr + 6);
	}
	int val;
	cout << "? 1 2" << endl;
	fflush (stdout);
	cin >> val;
	fr (i, 0, 720) {
		if (ans[i][0] != 0 && ans[i][0] * ans[i][1] != val) {
			fr (j, 0, 6) ans[i][j] = 0;
		}
	}
	cout << "? 2 3" << endl;
	fflush (stdout);
	cin >> val;
	fr (i, 0, 720) {
		if (ans[i][0] != 0 && ans[i][1] * ans[i][2] != val) {
			fr (j, 0, 6) ans[i][j] = 0;
		}
	}
	cout << "? 3 4" << endl;
	fflush (stdout);
	cin >> val;
	fr (i, 0, 720) {
		if (ans[i][0] != 0 && ans[i][2] * ans[i][3] != val) {
			fr (j, 0, 6) ans[i][j] = 0;
		}
	}
	cout << "? 4 5" << endl;
	fflush (stdout);
	cin >> val;
	fr (i, 0, 720) {
		if (ans[i][0] != 0 && ans[i][3] * ans[i][4] != val) {
			fr (j, 0, 6) ans[i][j] = 0;
		}
	}
	int flag = 0;
	cout << "! ";
	fr (i, 0, 720) {
		flag = 0;
		fr (j, 0, 6) {
			if (ans[i][j] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			fr (j, 0, 6) cout << ans[i][j] << " ";
			return 0;
		}
	}
	return 0;
}
