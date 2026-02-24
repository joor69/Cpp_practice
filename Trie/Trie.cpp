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
};

int main()
{
    vector<string> words = {"there", "a", "their", "any", "anywhere", "the"};
    Trie tr;

    for (int i = 0; i < words.size(); i++)
    {
        tr.insert(words[i]);
    }

    cout << tr.search("there");
    return 0;
}
