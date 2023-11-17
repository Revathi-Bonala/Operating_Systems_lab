#include<bits/stdc++.h>
using namespace std;
struct process{
    int pid;
    int at;
    int bt;
    int priority;
    int ct;
    int tat;
    int wt;
    int start;
   
};
int main()
{
    struct process p[100];
  float atat;
  float awt;
  int turn_time=0;
  int wait_time=0;
  int vis[100]={0};
  int n;
  cout<<"enter the number of process:";
  cin>>n;              
  for(int i=0;i<n;i++)
  {
    cout<<"enter the arrival time of procces"<<i+1<<":";
    cin>>p[i].at;
    cout<<"enter the burst time of process"<<i+1<<":";
    cin>>p[i].bt;
    cout<<"enter the priority of process"<<i+1<<":";
    cin>>p[i].priority;
    p[i].pid=i+1;
    cout<<endl;
  }
  int completed=0;
  int current_time=0;
  while(completed!=n)
  {
    //to find the proccess with higher priority 
    int mx=-1;
    int idx=-1;
    for(int i=0;i<n;i++)
    {
        if(p[i].at<=current_time && vis[i]==0)
        {
        if(p[i].priority>mx)
        {
            mx=p[i].priority;
            idx=i;
           
        }
        if(p[i].priority==mx)
        {
            if(p[i].at<p[idx].at)
            {
           mx=p[i].priority;
           idx=i;
           
        }
        }
        cout<<idx<<endl;
        }
    }
  
  if(idx!=-1)
  {
    p[idx].start=current_time;
    p[idx].ct=p[idx].start+p[idx].bt;//completion time
    p[idx].tat=p[idx].ct-p[idx].at;//total around time
    p[idx].wt=p[idx].tat-p[idx].bt;// waiting time
    turn_time+=p[idx].tat;//sum of tat
    wait_time+=p[idx].wt;//sum of wt
    vis[idx]=1;
    completed++;
    current_time=p[idx].ct;

  }
  else
  {
    current_time++;
  }
  }
  atat=float(turn_time)/n;
  awt=float(wait_time)/n;
cout<<"p"<<"\t"<<"A"<<"\t"<<"B"<<"\t"<<"prio"<<"\t"<<"C"<<"\t"<<"TAT"<<"\t"<<"WT"<<"\t"<<endl;
for(int i=0;i<n;i++)
{
    cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].priority<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<endl;
}
 cout<<"Average turnaround time:"<<atat<<endl;
 cout<<"Average waiting time:"<<awt<<endl; 


}