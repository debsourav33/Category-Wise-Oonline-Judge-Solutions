#include<bits/stdc++.h>
using namespace std;


int n,col[20], queen[20], diagonal[40], diagonal2[40], flag=0;

void NQueen(int at){

    if(at==n){
        for(int i=0;i<at;i++){
            cout<<i+1<<" "<<queen[i]+1<<endl;
        }
        flag=1;
        return;
    }


    for(int i=0;i<n;i++){

        if(col[i] || diagonal[i+at] || diagonal2[n+i-at])
            continue;

        col[i]= diagonal[i+at]= diagonal2[n+i-at]= 1;
        queen[at]= i;

        NQueen(at+1);   if(flag) return;
        col[i]= diagonal[i+at]= diagonal2[n+i-at]= 0;


    }


}


main(){
    cin>>n;
    NQueen(0);

}
