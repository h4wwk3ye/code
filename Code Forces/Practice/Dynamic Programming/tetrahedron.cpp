#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD=1000000007;
int main() {
 ll n;
  cin>>n;
  ll D=1;
  ll A=0;
  ll nD,nA;
  for (int i=1;i<=n;i++){
      nD=(3*A+D-D)%MOD;
      nA=(3*A+D-A)%MOD;
      D=nD;
      A=nA;
  }
 std::cout << D << '\n';
  return 0;
}
