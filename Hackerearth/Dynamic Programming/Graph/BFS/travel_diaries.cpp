/*
				C++
				encoding:UTF-8
				Modified: <18/Mar/2019 06:57:39 PM>

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
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e3 + 1;
int n, m;
int matrix[N][N], dist[N][N], visited[N][N];

bool check (int i, int j) {
	if (i >= 0 and i < n and j >= 0 and j < n) return true;
	return false;
}

auto neighbours (int i, int j) {
	ve< pair< int, int > > ne = {{i, j - 1}, {i - 1, j}, {i + 1, j}, {i, j + 1}};
	return ne;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	cin >> n >> m;
	queue< pair< int, int > > q, temp;
	fr (i, 0, n) {
		fr (j, 0, m) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 2) q.push ({i, j});
		}
	}

	while (!q.empty ()) {
		auto p = q.front ();
		q.pop ();
		int x = p.ff, y = p.ss;
		for (auto& t : neighbours (x, y)) {
			if (check (t.ff, t.ss) and !visited[t.ff][t.ss] and matrix[t.ff][t.ss] == 1) {
				visited[t.ff][t.ss] = 1;
				matrix[t.ff][t.ss]  = 2;
				dist[t.ff][t.ss]	= 1 + dist[x][y];
				temp.push ({t.ff, t.ss});
			}
		}
		if (q.empty ()) { swap (q, temp); }
	}

	int flag = 0;
	int mx   = 0;
	fr (i, 0, n) {
		fr (j, 0, n) {
			if (matrix[i][j] == 1) {
				flag = 1;
				break;
			}
			if (dist[i][j] != 0) mx = max (mx, dist[i][j]);
		}
		if (flag) break;
	}
	if (flag) {
		pr1 (-1);
		return 0;
	}
	pr1 (mx);

	return 0;
}
