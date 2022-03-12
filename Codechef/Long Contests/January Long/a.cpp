#include "bits/stdc++.h"
#define vi vector<int>
#define pb push_back

using namespace std;

const int N = 1e4 + 1;

vi adj[N];
int n, n1, n2;
int par[N], grp[N];

void dfs(int cur) {
  if (!grp[cur])
    ++n1;
  else
    ++n2;

  for (auto i : adj[cur]) {
    if (i == par[cur])
      continue;
    par[i] = cur;
    grp[i] = !(grp[cur]);
    dfs(i);
  }
  return;
}

vi opt, path, vec[2];

void findPath(int cur) {
  path.pb(cur);
  bool flag = 0;

  for (auto i : adj[cur]) {
    if (i == par[cur] || grp[i] != -1)
      continue;
    if (flag) {
      opt.pb(i);
    } else {
      findPath(i);
      flag = 1;
    }
  }
  return;
}

void add(int cur) {
  path.clear();
  int p = par[cur];
  findPath(cur);
  int n1 = path.size();
  int mg = !(grp[p]);
  cout << grp[p] << "grp[p]\n";
  cout << mg << "mg \n";
  if (n1 % 2 && vec[mg].size() > vec[!mg].size())
    mg ^= 1;
  grp[path[0]] = mg;
  vec[mg].pb(cur);

  for (int i = 1; i < n1; ++i) {
    grp[path[i]] = !(grp[path[i - 1]]);
    vec[grp[path[i]]].pb(path[i]);
  }

  return;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
    par[i] = 0;
  }

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  n1 = 0;
  n2 = 0;
  grp[1] = 0;
  dfs(1);

  if (n1 == n2) {
    cout << "1\n";
    for (int i = 1; i <= n; ++i) {
      if (!grp[i])
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i) {
      if (grp[i])
        cout << i << " ";
    }
    cout << "\n";
    return;
  }

  grp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    grp[i] = -1;
  }

  n1 = 0;
  n2 = 0;

  opt.clear();
  opt.pb(1);
  vec[0].clear();
  vec[1].clear();

  while (1) {
    while (!opt.empty() && grp[opt.back()] != -1)
      opt.pop_back();
    if (opt.empty())
      break;
    int x = opt.back();
    opt.pop_back();
    add(x);
  }

  cout << "2\n";
  for (int ii = 0; ii < 2; ++ii) {
    for (auto i : vec[ii])
      cout << i << " ";
    cout << "\n";
  }
  return;
}

int main() {
  // freopen("in.txt" , "r" , stdin) ;
  // freopen("out.txt" , "w" , stdout) ;
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
