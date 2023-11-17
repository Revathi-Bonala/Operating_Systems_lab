#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the string:";
    string s;
    cin>>s;
    int f_size;
    cout<<"enter the frame size:";
    cin>>f_size;
   int f[f_size];

    int n=s.length();
    int it=0,pf=0;
    int i=0;
    while(it<n)
    {
        if(i==f_size)
        i=0;
        int ft=0;
       for(int k=0;k<f_size;k++)
       {
        if(s[it]-'0' == f[k])
        {
        ft=1;
        break;
        }
       }
        if(ft!=1)
       {  
         f[i]=s[it]-'0';
            pf++;
            i++;
       }
       
        it++;
         
    }
    cout<<"Number of pagefaults: "<<pf<<endl;
    
}