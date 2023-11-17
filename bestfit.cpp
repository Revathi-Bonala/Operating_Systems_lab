#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of process:";
    cin>>n;
      cout<<"enter the number of memory blocks:";
    int m_size;
    cin>>m_size;
    vector<pair<int,int>>p;
    vector<pair<int,int>>m;
    vector<int>wt;
  
    for(int i=0;i<n;i++)
    {
          cout<<"enter the number of process with memory:";
       int pid;
       cin>>pid;
       int mem;
       cin>>mem;
       p.push_back({pid,mem});
    }
   
     for(int i=0;i<m_size;i++)
    {
        cout<<"enter the memory blocks and process:";
       int mem;
       cin>>mem;
       int pid;
       cin>>pid;
        m.push_back({mem,pid});
    }
    sort(m.begin(),m.end());
    int i=0;int it=0;
    vector<int>vis(m_size,0),visit(n,0);
    vector<pair<int,int>>order;
    while(it<p.size() )
    {
        for(int i=0;i<m_size;i++)
        {
        if(p[it].second<=m[i].first && vis[i]==0)
        {
        order.push_back({p[it].first,m[i].first});
        vis[i]=1;
        visit[it]=1;
        break;
        }  
        }
        it++;
       
    }
    cout<<"order of process in memory blocks:"<<endl;
    for(int i=0;i<order.size();i++) cout<<"p"<<order[i].first<<"->"<<order[i].second<<endl;
    cout<<"processes in wait list:"<<endl;
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        wt.push_back(p[i].first);
    }
    for(int i=0;i<wt.size();i++)
    cout<<"p"<<wt[i]<<" ";


}