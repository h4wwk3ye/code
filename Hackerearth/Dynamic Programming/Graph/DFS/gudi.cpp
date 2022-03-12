/*
				C++
				encoding:UTF-8
				Modified: <06/Mar/2019 06:06:30 PM>

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

int a,h;
string s,mn;
umap<string, int> mp;

void init(){
    mp.clear();
    h%=len(s);
    mn=s;
}

void dfs(string s){
    int u=stoi(s);
    if (u<stoi(mn))
        mn=s;
    mp[s]=1;
    string y=s;
    rotate(s.begin(),s.begin()+h,s.end());
    //cout<<"s \n";
    /*for (int i=0;i<s.size();i++){
        cout<<s[i];
    }
    cout<<endl;*/
    for (int i=1;i<y.size();i+=2){
        int x=y[i]-'0';
        x+=a;
        x%=10;
        y[i]='0'+x;
    }
    /*
    cout<<"y \n";
    for (int i=0;i<s.size();i++){
        cout<<y[i];
    }
    cout<<endl;*/
    if (mp.find(s)==mp.end())
        dfs(s);
    if (mp.find(y)==mp.end())
        dfs(y);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        cin>>a>>h;
        init();
        dfs(s);
        pr1(mn);
    }
    return 0;
}
