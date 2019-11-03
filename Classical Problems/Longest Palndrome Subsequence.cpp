#include<bits/stdc++.h>
using namespace std;

string str;

int dp[10000][10000];

struct node{
    int i, j;
    node(int _i, int _j){
        i=_i;
        j=_j;
    }

    node(){
    }
};

node dir[10000][10000];

int cnt=0;
int call(int i, int j){
    if(dp[i][j]!=-1) return dp[i][j];

    if(i>j) return 0;
    if(i==j) return 1;

    if(str[i]==str[j]){
        dir[i][j]= node(i+1,j-1);
        return dp[i][j]=2+ call(i+1,j-1);
    }

    int opt1= call(i,j-1);
    int opt2= call(i+1,j);

    if(opt1>=opt2)
        dir[i][j]= node(i,j-1);
    else
        dir[i][j]= node(i+1,j);

    return dp[i][j]=max(opt1,opt2);

}

vector<int> v,w;

void print(){
    for(int i=0;i<v.size();i++)
        cout<<str[v[i]];
    for(int i=0;i<w.size();i++)
        cout<<str[w[i]];

    puts("");

}

void solution(int i, int j){
    int n_i= dir[i][j].i;
    int n_j= dir[i][j].j;

    if(i==-1){
        print();
        return;
    }

    if(i==j){
        v.push_back(i);
        print();
        return;
    }

    if(n_i==i+1 && n_j==j-1){
       v.push_back(i);
       w.insert(w.begin(),j);
    }

    solution(n_i,n_j);

}


main(){
    memset(dp, -1, sizeof dp);
    memset(dir, -1, sizeof dir);
    cin>>str;

    call(0,str.length()-1);
    solution(0,str.length()-1);
}
