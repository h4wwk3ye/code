#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, c, s;

const int N = 1e5 + 1;

struct eg {
  int b, c, w;
};

struct node {
  int cur, prev;
  ll w;
};

vector<eg> adj[N];
unordered_map<int, ll> dist[N];
ll bd[N];

struct comp {
  bool operator()(const node n1, const node n2) { return n1.w > n2.w; }
};

void dij(int s) {
  priority_queue<node, vector<node>, comp> q;

  for (int i = 1; i <= n; ++i) {
    if (i == s)
      dist[i].reserve(c);
    else
      dist[i].reserve(adj[i].size());
    dist[i].max_load_factor(.25);
  }

  for (int i = 1; i <= c; ++i) {
    dist[s][i] = 0;
  }

  dist[s][-1] = 0;
  q.push({s, -1, 0});

  while (!q.empty()) {
    node x = q.top();
    cout << "x " << x.cur << " " << x.prev << "\n";
    q.pop();
    if (dist[x.cur].count(x.prev) && dist[x.cur][x.prev] < x.w)
      continue;

    for (auto i : adj[x.cur]) {
      if (i.c == x.prev)
        continue;
      ll nd = x.w + i.w;
      if (dist[i.b].count(i.c) && dist[i.b][i.c] <= nd)
        continue;
      dist[i.b][i.c] = nd;
      q.push({i.b, i.c, nd});
    }
  }

  for (int i = 1; i <= n; ++i) {
    ll bst = 1e17;
    for (auto j : dist[i]) {
      bst = min(bst, j.second);
    }
    if (bst == 1e17)
      bst = -1;
    bd[i] = bst;
  }

  return;
}

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt" , "w" , stdout) ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> c;

  for (int i = 0; i < m; ++i) {
    int a, b, c, w;
    cin >> a >> b >> w >> c;
    adj[a].push_back({b, c, w});
  }

  int q;

  cin >> s >> q;

  dij(s);

  while (q--) {
    int t;
    cin >> t;
    cout << bd[t] << "\n";
  }

  return 0;
}
