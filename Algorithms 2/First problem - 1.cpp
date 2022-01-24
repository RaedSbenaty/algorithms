#include <bits/stdc++.h>
using namespace std; 

vector < int >l, r, lvl, p, sum; int q, n;

void dfs (int x = 1, int pa = 0)
{ 
 if (x == -1)
      return; 
 lvl[x] = lvl[pa] + 1; 
 sum[x] = sum[pa] + x; 
 p[x] = pa; 
 dfs (l[x], x), dfs (r[x], x);
}

int lca (int u, int v)
{ 
 if (lvl[u] > lvl[v]) 
    swap (u, v);

 while (lvl[v] != lvl[u]) 
    v = p[v]; 

 while (p[u] != p[v]) 
    u = p[u], v = p[v]; 

 return (u==v)?u:p[u];
}

double res (int u, int v)
{ 
 int a = lca (u, v);
 double r = sum[u] + sum[v] - 2 * sum[a] + a; 
 double d = lvl[u] + lvl[v] - 2 * lvl[a] + 1; 
 return r / d;
}

int main ()
{ 
 cin >> n;
 l.resize(n+1),r.resize(n+1),lvl.resize(n+1); 
 p.resize(n+1),sum.resize(n+1);
 
 for (int i = 1; i <= n; i++) 
     cin >> l[i] >> r[i];

 dfs (); 

 cin >> q; 
 while (q--)
 { 
  int u, v; 
  cin >> u >> v; 
  cout << res (u, v) << endl;
 }

 return 0;
}