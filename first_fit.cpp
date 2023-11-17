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
    int i=0;
    int it=0;
      vector<pair<int,int>>order;
      vector<int>vis(m_size,0),visit(n,0);
       while(i<n)
       {
        int f=0;
        for(int it=0;it<m_size;it++)
        {
            if(p[i].second<=m[it].first && vis[it]==0)
            {
                order.push_back({p[i].first,m[it].first});
                visit[i]=1;
               vis[it]=1;
                break;
            }
        }
        if(visit[i]!=1)
        wt.push_back(p[i].first);
        i++;
       }
        cout<<"order of process in memory blocks:"<<endl;
       for(int i=0;i<order.size();i++)
       cout<<"p"<<order[i].first<<"->"<<order[i].second<<endl;
      cout<<"processes in waiting list:";
       for(int i=0;i<wt.size();i++)
       cout<<"p"<<wt[i]<<endl;
}
