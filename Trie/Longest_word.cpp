#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> child;
    bool endofword;
    Node()
    {
        endofword = false;
    }
};

class Trie
{

    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->child.count(key[i]) == 0)
            {
                temp->child[key[i]] = new Node();
            }
            temp = temp->child[key[i]];
        }
        temp->endofword = true;
    }

    bool search(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->child.count(key[i]) == 0)
                return false;

            temp = temp->child[key[i]];
        }
        if (temp->endofword == false)
            return false;
        return true;
    }


    void longesthelper(Node*root,string& ans,string temp)
    {
        for(pair<char,Node*> ch:root->child)
        {
            if(ch.second->endofword==true)
            {
                temp+=ch.first;
                if((temp.size()==ans.size() && temp<ans)||(temp.size() > ans.size()))
                    ans=temp;
                
            }
            longesthelper(ch.second,ans,temp);
            temp=temp.substr(0,temp.size()-1);
        }
    }

    string longestprefix()
    {
        string ans="";
        longesthelper(root,ans,"");
        return ans;
    }
};

string Longestword(vector<string> dict)
{
    Trie trie;
    for(string ele:dict)
    {
        trie.insert(ele);
    }

    return trie.longestprefix();
}

int main()
{
    vector<string> dict={"a","banana","app","appl","ap","apply","apple"};
    cout<<Longestword(dict);
    return 0;
}
