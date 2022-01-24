#include <bits/stdc++.h>
using namespace std; 

int n,lg,q; 
vector<int> l,r,lvl; 
vector<vector <int>> p,s; 

void dfs(int x=1,int pa=0)
{ 
  if(x==-1) 
    return; lvl[x]=lvl[pa]+1,p[x][0]=pa,s[x][0]=x;

  for(int j=1;j<=lg;j++)
  { 
    p[x][j]=p[ p[x][j-1] ][j-1]; s[x][j]=s[x][j-1]+s[ p[x][j-1] ][j-1];
  }

  dfs(l[x],x),dfs(r[x],x);
} 

int lca(int u,int v)
{ 
 if(lvl[u]>lvl[v]) 
   swap(u,v); 
 int d=lvl[v]-lvl[u];
 for(int i=lg;i>=0;i--) 
    if(d>>i&1) v=p[v][i];
 
 for(int i=lg;i>=0;i--) 
    if(p[u][i]!=p[v][i]) u=p[u][i],v=p[v][i];

 return (u==v)?u:p[u][0];
}

double res(int u,int v)
{ 
 int a=lca(u,v); 
 double r=s[u][lg]+s[v][lg]-2*s[a][lg]+s[a][0]; 
 double d=lvl[u]+lvl[v]-2*lvl[a]+1; 
 return r/d;
}

int main()
{ 
 cin>>n; 
 lg=log2(n)+1; 
 l.resize(n+1),r.resize(n+1),lvl.resize(n+1);
 p.resize(n+1),s.resize(n+1);

 for(int i=0;i<=n;i++) 
  p[i].resize(lg+1),s[i].resize(lg+1);

 for(int i=1;i<=n;i++)
  cin>>l[i]>>r[i];

 dfs(); 
 cin>>q;
 while(q--)
 { 
  int u,v;
  cin>>u>>v;
  cout<<res(u,v)<<endl;
 }

 return 0;
}