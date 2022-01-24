#include <bits/stdc++.h>
using namespace std; 

vector <string> s; 
vector <vector <int>> g; 
vector <bool> vis; 

void dfs(int x)
{ 
 vis[x]=1; 
 for(int y:g[x]) 
   if(!vis[y]) dfs(y);
} 

int main()
{ 
 int n,m,cmp=0; 
 cin>>n>>m;
 s.resize(n+1),g.resize(n+1),vis.resize(n+1);

 for(int i=1;i<=n;i++)
  cin>>s[i];
 
 for(int i=1;i<=n;i++)
 { 
  for(int j=i+1;j<=n;j++)
  {
    int cnt=0;
    for(int c=0;c<m;c++) 
      if(s[i][c]!=s[j][c]) cnt++;

    if(cnt<=1) 
      g[i].push_back(j),g[j].push_back(i);
  }
 }

 for(int i=1;i<=n;i++) 
   if(!vis[i]) dfs(i),cmp++;

 cout<<cmp;
 return 0;
}