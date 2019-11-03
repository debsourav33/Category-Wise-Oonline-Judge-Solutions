#include<bits/stdc++.h>
using namespace std;

main(){
    int n, start[100005], finish[100005], i=0, j=0, maxi=1;

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>start[i];
    for(int i=0;i<n;i++)
        cin>>finish[i];

    while(i<n && j<n){
        if(start[i]<=finish[j]){
            maxi= max(maxi, i-j+1);
            i++;
        }
        else
            j++;
    }

    cout<<maxi<<endl;

}
