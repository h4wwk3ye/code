/*
                C++
                encoding:UTF-8
                Modified: <17/Feb/2019 05:17:31 PM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define sum(v) accumulate(v.begin(), v.end(), 0);
#define reset(a, b) memset(a, b, sizeof(a));
#define pb push_back

const int N = 1e3 + 5;
int matrix[N][N], n, m, cnt = 0, visited[N][N], mx = 0, curr = 0;

bool check(int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m)
    return true;
  return false;
}

void explore(int i, int j) {
  visited[i][j] = 1;
  int neighbours[8][2] = {{i - 1, j - 1}, {i, j - 1},    {i + 1, j - 1},
                          {i - 1, j},     {i + 1, j},    {i - 1, j + 1},
                          {i, j + 1},     {i + 1, j + 1}};
  for (auto p : neighbours) {
    int x = p[0];
    int y = p[1];
    if (check(x, y) && visited[x][y] == 0 && matrix[x][y] == 1) {
      curr++;
      explore(x, y);
    }
  }
}

void dfs() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (matrix[i][j] == 1 && visited[i][j] == 0) {
        cnt++;
        curr = 1;
        explore(i, j);
        mx = max(mx, curr);
      }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    reset(matrix, 0);
    reset(visited, 0);
    cnt = 0;
    mx = 0;
    curr = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> matrix[i][j];
    dfs();
    cout << cnt << " " << mx << "\n";
  }

  return 0;
}
