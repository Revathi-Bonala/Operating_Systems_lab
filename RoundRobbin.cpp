#include <bits/stdc++.h>
using namespace std;

void rr(vector<pair<int,pair<int,int>>> &job,int n,int tq){
    int start=v[0].first;
    queue<pair<int,pair<int,int>>> rq;//ready queue -id,bt,at
    rq.push({v[0].second.first,{v[0].second.second,v[0].first}});
    v.erase(v.begin());
    while(!q.empty()){
      int time=start+tq;
      for(int i=0;i<v.size();i++){
        if(v[i].first<=time){
            rq.push({v[i].second.first,{v[i].second.second,v[i].first}});
            auto pair={v[i].first,{v[i].second.first,v[i].second.second}};
            auto it=find(v.begin(),v.end(),pair);
            v.erase(it);
        }
      }
      int front_id=rq.front().first;
      int front_bt=rq.front().second.first;
      int front_at=rq.front().second.second;rq.pop();
      int mintime=min(tq,front_bt);
      front_bt-=mintime;
      if(front_bt!=0) rq.push({id,{front_bt,front_at}});
      else
      {
        int tat=time-front_at;
        int wt=tat-front_bt;
        atat+=tat;awt+=wt;
        cout<<front_id<<" "<<time<<" "<<tat<<" "<<wt<<endl;
      }

    }
}



int main(){
    int n;cout<<"enter the no. of processes ";
    cin>>n;vector<pair<int,pair<int,int>>> job(n);
   
    cout<<"enter arrival times,processes id and burst time of each job\n";
    for(int i=0;i<n;i++){
        int at,bt,id;
        cin>>id>>at>>bt;
        job[i]={at,{id,bt}};
    }cout<<endl;
   sort(job.begin(),job.end());
    for(int i=0;i<n;i++){
        cout<<job[i].first<<" "<<job[i].second.first<<" "<<job[i].second.second<<endl;
    }

}