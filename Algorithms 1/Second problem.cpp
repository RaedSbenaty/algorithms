#include <bits/stdc++.h>

using namespace std;

/// Complexity: O[ K_MAX^N ]

int n,m;
bool check_solution=0;

vector< vector<string> > row,col;
vector< vector<char> > cur;

bool check()
{
    vector<string> cpy;

    for(int c=0; c<m; c++)
    {
        bool check_col=0;

        for(int i=0; i<col[c].size(); i++)
        {
            if(col[c][i].size()>n)
                continue;
            bool check_string=1;
            for(int j=0; j<col[c][i].size(); j++)
            {
                if(cur[j][c]!='#'&&cur[j][c]!=col[c][i][j])
                {
                    check_string=0;
                    break;
                }
            }

            if(check_string)
            {
                check_col=1;
                cpy.push_back(col[c][i]);
                break;
            }
        }

        if(!check_col)
            return 0;
    }

    for(int i=0;i<cpy.size();i++)
        for(int j=0;j<cpy[i].size();j++)
            cur[j][i]=cpy[i][j];

    return 1;
}

void print()
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<cur[i][j];
        cout<<endl;
    }
}

void bt(int r)
{
    if(check_solution)
      return;

    if(r==n)
    {
        if(check())
        {
            check_solution=1;
            print();
        }
        return;
    }

    for(int i=0; i<row[r].size(); i++)
    {
        if(row[r][i].size()>m)
            continue;

        for(int j=0; j<row[r][i].size(); j++)
            cur[r][j] = row[r][i][j];

        bt(r+1);

        for(int j=0; j<row[r][i].size(); j++)
            cur[r][j] ='#';
    }

}


int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        vector<string> v;
        row.push_back(v);
        for(int j=0; j<k; j++)
        {
            string s;
            cin>>s;
            row[i].push_back(s);
        }
    }

    for(int i=0; i<m; i++)
    {
        int k;
        cin>>k;
        vector<string> v;
        col.push_back(v);
        for(int j=0; j<k; j++)
        {
            string s;
            cin>>s;
            col[i].push_back(s);
        }
    }

    for(int i=0; i<n; i++)
    {
        vector<char> v;
        cur.push_back(v);
        for(int j=0; j<m; j++)
            cur[i].push_back('#');
    }


    bt(0);

    if(!check_solution)
        cout<<"IMPOSSIBLE"<<endl;



}
