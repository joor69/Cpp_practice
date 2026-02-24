#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> child;
    bool endofword;
    int freq;
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
        root->freq = -1;
    }

    void insert(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->child.count(key[i]) == 0)
            {
                temp->child[key[i]] = new Node();
                temp->child[key[i]]->freq=1;
            }
            else
                temp->child[key[i]]->freq++;

            temp = temp->child[key[i]];
        }
        temp->endofword = true;
    }
//Specially for Prefix problem
    string getprefix(string key)
    {
        Node* temp=root;
        string prefix="";
        for(int i=0;i<key.size();i++)
        {
            char c=key[i];
            prefix+=c;
            if(temp->child[key[i]]->freq==1)
                   return prefix;
            temp=temp->child[key[i]];
        }

        return prefix;
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
};

// Problem start::::: PrefixProblem:::::
void prefix(vector<string> words)
{
    Trie trie;
    vector<string> ans;

    //Building Trie
    for (string ele : words)
    {
        trie.insert(ele);
    }

    for(string ele: words)
    {
        cout<<trie.getprefix(ele)<<" ";
    }
}

int main()
{
    vector<string> words = {"zebra", "dog", "dove", "duck"};

    prefix(words);
    return 0;
}