/*
				C++
				encoding:UTF-8
				Modified: <07/Mar/2019 09:10:06 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll					long long
#define		 mod					1000000007
#define		 ve					vector
#define		 pb					push_back
#define		 umap					unordered_map
#define		 pq					priority_queue
#define		 endl					"\n";
#define		 ff					first
#define		 ss					second
#define		 len(v)					int(v.size())
#define		 all(v)					v.begin(), v.end()
#define		 reset(a, b)				memset(a, b, sizeof(a));
#define		 sum(v)					accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)					cout<<x<<"\n"
#define		 pr2(x, y)				cout<<x<<" "<<y<<"\n"
#define		 prv(v)					for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, k, n)				for (int i = k ; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
   int k;
   cin >> n >> k;
   int a[n];
   int m[k];
   for(int i=0; i<k; i++)
       m[i]=0;
    for(int i = 0; i < n; i++){
       cin >> a[i];
        m[a[i]%k]++;
    }
    int sum=0;
    sum+=(m[0]*(m[0]-1))/2;
     for(int i=1; i<=k/2 && i!=k-i; i++){
         sum+=m[i]*m[k-i];
     }
    if(k%2==0)
        sum+=(m[k/2]*(m[k/2]-1))/2;
    cout<<sum;
    return 0;
    return 0;
}
