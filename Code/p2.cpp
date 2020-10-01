#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

vector<int> readv(int n){
  vector<int> v;
  for(int e, int i=0;i<n;i++){
    cin>>e;
    v.push_back({i,e});
  }
  return v;
}

void makeRow(vector<int> &v, int bw){
  int dp[bw+]; dp[0]=-2;
  for(int i=0;i<=bw;i++) dp[i]=-1;
  for(int i=0;i<v.size();++i){
    for(int j=bw;j>=v[i];--j)
      if(dp[j]==-1 && dp[j-v[i]]!=-1)
        dp[j]=i;
    dp[vi]=0;
    if(dp[bw]!=-1) break;
  }

  // construct the row

}

void makeBoard(vector<int> &v, int bw){
  vector<vector<int>> board;  
  while(!v.empty()){
    board.push_back(makeRow(v,bw));
  }
  return board;
}

int main(){
  int n;
  vector<int> v;
  vector<vector<int>> billBoard;

  // read board width
  cin>>n;
  v=readv(n);





  return 0;
}




