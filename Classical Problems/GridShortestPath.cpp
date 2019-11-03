#include<bits/stdc++.h>
using namespace std;

#define clr(a) memset(a,0,sizeof(a))

int m,n;
char ch[100][100];
int visited[100][100];

int call(int i, int j){
    if(visited[i][j])  return 9999999;
    if(i<0|| i>=m|| j<0|| j>=n) return 9999999;
    if(i==m-1 && j==n-1) return 0;

    visited[i][j]= 1;

    if(ch[i][j]=='#') return 9999999;

    int opt1= 1+call(i+1,j);
    int opt2= 1+call(i,j+1);
    int opt3= 1+call(i-1,j);
    int opt4= 1+call(i,j-1);

    visited[i][j]= 0;

    return min(min(opt1,opt2), min(opt3,opt4));

}

main(){
    clr(visited);
    cin>>m>>n;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>ch[i][j];

    cout<<call(0,0)<<endl;
}
