/*
                C++
                encoding:UTF-8
                Modified: <21/Jan/2019 02:07:12 PM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define sum(v) accumulate(v.begin(), v.end(), 0);
#define sort(v) sort(v.begin(), v.end())
#define reset(a, b) memset(a, b, sizeof(a));
#define pb push_back
#define inf 1e7

std::vector<std::vector<ll>> graph(100005);
ll visited[100005];
ll parent[100005];
ll low[100005];
ll disc[100005];
map<pair<ll, ll>, ll> bridges;

void explore(ll node, ll time) {
  visited[node] = 1;
  low[node] = time;
  disc[node] = time;
  for (auto child : graph[node]) {
    if (visited[child] == 0) {
      parent[child] = node;
      explore(child, time + 1);

      low[node] = min(low[node], low[child]);

      if (low[child] > disc[node]) {

        bridges[make_pair(child, node)] = 1;
        bridges[make_pair(node, child)] = 1;
      }
    }

    else if (child != parent[node]) {
      low[node] = min(low[node], disc[child]);
    }
  }
}

void dfs(ll n, ll m) {
  memset(visited, 0, sizeof(visited));
  memset(parent, -1, sizeof(parent));
  memset(low, inf, sizeof(low));
  memset(disc, inf, sizeof(disc));
  for (size_t i = 1; i < n + 1; i++) {
    if (visited[i] == 0)
      explore(i, 0);
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll n, m, q;
  cin >> n >> m >> q;

  map<ll, pair<ll, ll>> edges;

  ll u, v, z;
  for (size_t i = 0; i < n; i++) {
    cin >> u >> v >> z;
    graph[u].pb(v);
    graph[v].pb(u);
    edges[z] = make_pair(u, v);
  }
  dfs(n, m);
  /*unordered_map<string, ll>::iterator itr;
  for (itr = bridges.begin(); itr != bridges.end(); itr++) {
    cout << itr->first << "  " << itr->second << endl;
  }
  unordered_map<ll, string>::iterator itre;
  cout << "next"
       << "\n";
  for (itre = edges.begin(); itre != edges.end(); itre++) {
    cout << itre->first << "  " << itre->second << endl;
  }*/
  while (q--) {
    ll o;
    cin >> o;
    pair<ll, ll> edge = edges[o];

    if (bridges.find(edge) == bridges.end())
      cout << "no"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
  return 0;
}
