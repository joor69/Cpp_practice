#include<bits/stdc++.h>
using namespace std;

//to find the substrings of a string 
//we can use two methods :::
//first find the suffixes of the string  then prefixes of those suffixes;
//OR
//Find the prefixes of the string then suffixes of those prefixes

//Then count the total nodes from the trie after building the trie from the suffixes ;

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

    // STARTSWITH FUNCTION BUILT
    bool startswith(string prefix)
    {
        Node *temp;
        temp = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (temp->child.count(prefix[i]) == 0)
                return false;
            temp = temp->child[prefix[i]];
        }

        return true;
    }


    //for calculatiing the nodes of a trie ;
    int counthelper(Node* root)
    {
        int ans=0;

        for(pair<char,Node*> ch:root->child)
        {
            ans+=counthelper(ch.second);
        }

        return ans+1;
    }

    int countNodes()
    {
        return counthelper(root);
    }
};

int countthesubstrings(string str)
{
    Trie trie;
    int count=0;
    //find the substrings and making a trie of those substrings
    for(int i=0;i<str.size();i++)
    {
        trie.insert(str.substr(i));
    }

    return trie.countNodes();

}

int main()
{
    string key="abcd";
   cout<<countthesubstrings("ababa");
    return 0;
}