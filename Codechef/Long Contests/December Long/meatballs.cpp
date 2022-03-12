#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc,n;
    cin>>tc;
    for(int _=0;_<tc;_++)
    {
        cin>>n;
        if (n>6)
        {
            int flag_arr[n+1]={true};
            for (int i=1;i<n+1;i++)
                flag_arr[i]=1;
            //cout<<endl;
            set<int> st;
            int check=0;
            while(true)
            {
                int op[5]={0};
                int index=0;
                for (int i=1;i<n+1;i++)
                {
                    if (flag_arr[i]==1)
                    {
                        op[index]=i;
                        index++;
                        if (i==n)
                            check=1;
                        if (index==5)
                            break;
                    }
                }

                if (index!=5)
                {
                    for (int i=0;i<n;i++)
                    {
                        if (flag_arr[i]==0)
                        {
                            op[index]=i;
                            index++;
                            if (index==5)
                                break;
                        }
                    }
                }
                /*for (int i=0;i<5;i++)
                    cout<<op[i]<< " ";*/
                //cout<<endl;
                cout<<"?"<<" "<<op[0]<<" "<<op[1]<<" "<<op[2]<<" "<<op[3]<<" "<<op[4]<<"\n"<<flush;
                int x,y;
                cin>>x>>y;
                st.insert(x);
                st.insert(y);
                flag_arr[x]=0;
                flag_arr[y]=0;
                if (check)
                    break;
            }
            int popped[4];
            set<int>::iterator it;
            /*for (it=st.begin();it!=st.end();it++)
                cout<<*it;*/
            //cout<<endl;
            int index=0;
            for (it=st.begin();;it++)
            {
                popped[index]=*it;
                index++;
                if (index==4)
                    break;
            }
            /*for(int i=0;i<4;i++)
            {
                cout<<popped[i];
            }*/
            int op[3];
            int indx=0;
            for (int i=1;i<n+1;i++)
            {
                if (flag_arr[i]==1)
                {
                    //cout<<i;
                    op[indx]=i;
                    indx+=1;
                    if (indx==3)
                        break;
                }
            }
            cout<<"?"<<" "<<op[0]<<" "<< popped[0]<<" "<< popped[1]<<" "<< popped[2]<<" "<< popped[3]<<"\n"<<flush;
            int p,q;
            cin>>p>>q;
            cout<<"?"<<" "<<op[1]<<" "<< popped[0]<<" "<< popped[1]<<" "<< popped[2]<<" "<< popped[3]<<"\n"<<flush;
            int r,s;
            cin>>r>>s;
            cout<<"?"<<" "<<op[2]<<" "<< popped[0]<<" "<< popped[1]<<" "<< popped[2]<<" "<< popped[3]<<"\n"<<flush;
            int u,v;
            cin>>u>>v;

            if ((p != r && q != s) && (p != u && q != v))
                cout<<"!"<<" "<<op[0]<<"\n"<<flush;
            else if ((r != u && v != s) && (r != p && s != q))
                cout<<"!"<<" "<<op[1]<<"\n"<<flush;
            else
                cout<<"!"<<" "<<op[2]<<"\n"<<flush;

    }
    else
    {
        int flag_arr[n+1];
        for (int i=1;i<n+1;i++)
                flag_arr[i]=1;
        int op[3];
        set<int> st;
        cout<<"?"<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<"\n"<<flush;
        int p,q;
        cin>>p>>q;
        flag_arr[p] = false;
        flag_arr[q] =false;
        st.insert(p);
        st.insert(q);
        cout<<"?"<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<6<<"\n"<<flush;
        int r,s;
        cin>>r>>s;
        flag_arr[r] = false;
        flag_arr[s] = false;
        st.insert(r);
        st.insert(s);
        cout<<"?"<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<"\n"<<flush;
        int u,v;
        cin>>u>>v;
        flag_arr[u] = false;
        flag_arr[v] = false;
        st.insert(u);
        st.insert(v);
        int oup[3];
        int index=0;
        for (int i=1;i<n+1;i++)
        {
            if (flag_arr[i]==1)
            {
                oup[index]=i;
                index++;
                if (index==3)
                    break;
            }

        }
        int x[3];
        int ind=0;
        set<int>::iterator it;
        for (it=st.begin();it!=st.end();it++)
        {
            x[ind]=*it;
            ind++;
        }

        cout<<"?"<<" "<<oup[0]<<" "<<oup[1]<<" "<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n"<<flush;
        int a,b;
        cin>>a>>b;
        cout<<"?"<<" "<<oup[1]<<" "<<oup[2]<<" "<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n"<<flush;
        int c,d;
        cin>>c>>d;
        cout<<"?"<<" "<<oup[0]<<" "<<oup[2]<<" "<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n"<<flush;
        int e,f;
        cin>>e>>f;
        if ((a!=c && b!=d) &&(a!=e and b!=f))
            cout<<"!"<<" "<<oup[2]<<"\n"<<flush;
        else if ((a!=c && b!=d) &&(c!=e and d!=f))
            cout<<"!"<<" "<<oup[0]<<"\n"<<flush;
            else
            cout<<"!"<<" "<<oup[1]<<"\n"<<flush;
    }
    }
}
