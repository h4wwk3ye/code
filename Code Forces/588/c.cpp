#include <bits/stdc++.h>

#define   ll             long long int
#define   pb             push_back
#define   mp             make_pair
#define   fast           ios_base::sync_with_stdio(false);cin.tie(NULL);
#define   ff             first
#define   ss             second
#define   nil           -10e+9
#define   initial         0
#define   waiting         1
#define   visit           2
#define   inf            10e+9
#define   mx             200005
#define   mxx            1000005
#define   mod            1000000007
#define   pr             pair<ll,ll>
#define   pp_queue       priority_queue<pr,vector<pr>, greater<pr> >
#define   dp_queue       priority_queue<int,vector<int>, greater<int> >
#define   sp_queue       priority_queue<int>
#define   fr(i,p,q)      for(int i=p;i<q;++i)
#define   frr(i,p,q)     for(int i=p;i<=q;++i)
#define   mem(a,b)       memset(a,b,sizeof(a))
#define   len(a)         (int)a.size()
#define   input          freopen("input.txt", "r", stdin);
#define   output         freopen("output.txt", "w", stdout);
#define   debug(arr,j,n) fr(i,j,n) cout<<arr[i]<<" ";

ll power(ll a,ll b){ll aa=1;while(b){if(b&1){aa=aa*a;aa%=mod;}a=a*a;a%=mod;b/=2;}return aa;}

using namespace std;

vector<int> graph[8];
vector<vector<int> > a;
vector<int> temp;
vector<int> d(7);

void dfs(int n,int i)
{
    if(i==n)
        a.pb(temp);
    else
    {
        fr(j,1,7){
                temp[i] = j;
                dfs(n,i+1);
        }
    }
}
int main()
{

    fast
    int n,m;
    cin>>n>>m;

    fr(i,0,m)
    {
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
    }

    fr(i,0,n+1) temp.pb(0);

    dfs(n+1,1);


    int ans = 0;

    fr(i,0,7) d[i]=6;

    fr(i,0,len(a))
    {
        int count = 0;
        fr(j,1,n+1){

            for(int it:graph[j])
            {
              if(d[a[i][j]]>0&&d[a[i][it]]>0)
              {
                  d[a[i][j]]--;
                  d[a[i][it]]--;
                  count++;
              }
          }
        }

        ans = max(ans,count);

        fr(i,0,7) d[i]=6;
    }

    cout<<ans<<endl;

    return 0;
}
