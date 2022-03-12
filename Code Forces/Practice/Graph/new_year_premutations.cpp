/*
				C++
				encoding:UTF-8
				Modified: <23/Mar/2019 10:01:21 PM>

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
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (int i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 305;
string graph[N];
int n;
int arr[N];
int parent[N], rnk[N];
int curr[N];


void init () {
	fr (i, 0, N) {
		parent[i] = i;
	}
}

int fnd (int x) {
	if (parent[x] != x) {
		parent[x] = fnd (parent[x]);
	}
	return parent[x];
}

void unon (int x, int y) {
	int x_id = fnd (x);
	int y_id = fnd (y);
	if (x_id == y_id) return;

	if (rnk[x_id] > rnk[y_id])
		parent[y_id] = x_id;
	else {
		parent[x_id] = y_id;
		if (rnk[x_id] == rnk[y_id]) rnk[y_id]++;
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	init ();
	cin >> n;
	fr (i, 1, n + 1) {
		cin >> arr[i];
	}

	fr (i, 1, n + 1) {
		cin >> graph[i];
	}

	fr (i, 1, n + 1) {
		fr (j, 0, n) {
			if (graph[i][j] == '1') {
				unon (i, j + 1);
			}
		}
	}

	ve< int > pos[n + 1];
	fr (i, 1, n + 1) {
		pos[fnd (i)].pb (arr[i]);
	}

	fr (i, 1, n + 1) {
		sort (all (pos[i]));
	}


	fr (i, 1, n + 1) {
		int x = fnd (i);
		cout << pos[x][curr[x]] << " ";
		curr[x]++;
	}
	cout << endl;

	return 0;
}
