#include <bits/stdc++.h>

using namespace std;

/// Complexity: O[ log_10(ID_MAX) ]

struct information
{
    string first,last,age;
};

struct trie
{
    trie* next[10];
    information* info;

    trie()
    {
        info=NULL;
        for(int i=0;i<10;i++)
            next[i]=NULL;
    }
};

trie* head=new trie;

void add(string id,information* f)
{
    trie* temp=head;

    for(char c:id)
    {
        if(!temp->next[c-'0'])
            temp->next[c-'0']=new trie;

        temp=temp->next[c-'0'];
    }
    temp->info=f;
}

information* ser(string id)
{
    trie* temp=head;
    for(char c:id)
    {
        temp=temp->next[c-'0'];
        if(!temp)
            return 0;
    }
    return temp->info;
}


int main()
{
    int Q,choice;
    string id,first,last,age;
    information *f;
    cin>>Q;
    while(Q--)
    {
        cin>>choice;
        cin>>id;
        if(choice==1)
        {
            cin>>first>>last>>age;
            f=new information;
            f->first=first,f->last=last,f->age=age;
            add(id,f);
        }
        else
        {
             f=ser(id);
            (f)?cout<<id<<" "<<f->first<<" "<<f->last<<" "<<f->age:cout<<"Not found";
            cout<<endl;
        }
    }
}
