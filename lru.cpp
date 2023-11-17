
#include<bits/stdc++.h> 
using namespace std;
int main() 
{ 
   string pages="";
   cout<<"enter the ";
   cin>>pages;


    int n =pages.length();
    int frames;
    cout<<"enter number of frames:";
    cin>>frames; 
    unordered_set<int> s; 
    unordered_map<int, int> ind;   // To store least recently used indexes
    int page_faults = 0; 
    for (int i=0; i<n; i++) 
    { 
        if (s.size() < frames) 
        { 
            // Insert it into set if not present 
            // already which represents page fault 
            if (s.find(pages[i])==s.end()) 
            { 
                s.insert(pages[i]); 
                page_faults++; //incrementing pagefaults
            }  
            ind[pages[i]] = i;  // Storing  the recently used index of each page  
        } 
        else
        { 
            // Check if current page is not present in the set 
            if (s.find(pages[i]) == s.end()) 
            { 
                // Find the least recently used pages 
                // that is present in the set 
                int lru = INT_MAX, val; 
                for (auto it=s.begin(); it!=s.end(); it++) 
                { 
                    if (ind[*it] < lru) 
                    { 
                        lru = ind[*it]; 
                        val = *it; 
                    } 
                } 
  
                // Removing the page in that index in a string 
                s.erase(val); 
  
                // insert the current page in frame
                
                s.insert(pages[i]); 
  
                // Increment page faults 
                page_faults++; 
            } 
  
            // Update the current page index 
            ind[pages[i]] = i; 
        } 
    } 
   
 
    cout <<"no of pagefaults= "<<page_faults; 
    return 0; 
} 
//string: 12321521625631361243
//output:no of pagefaults=11

