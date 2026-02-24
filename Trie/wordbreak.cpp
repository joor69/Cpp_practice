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

    bool search(string_view key)
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


//PROBLEM:::::::::::

bool searchindict(Trie &tr, string_view key) // using string_view instead of string since string makes copy of substr
                                             // which is time consuming
{
    if (key.empty())
    {
        return true;
    }

    for (int i = 0; i < key.size(); i++)
    {
        string_view firsthalf = key.substr(0, i + 1);
        string_view secondhalf = key.substr(i + 1);

        if (tr.search(firsthalf))
        {
            return searchindict(tr, secondhalf);
        }
    }

    return false;
}

void wordbreak(vector<string> dict,string key)
{
    Trie tr;
    // Building the trie
    for (string ele : dict)
    {
        tr.insert(ele);
    }

    cout<<searchindict(tr,key);
}

int main()
{
    vector<string> dict = {"i", "love", "coding", "and", "love", "apple", "products"};
    wordbreak(dict,"ilovehim");
    return 0;
}