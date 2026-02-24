#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
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
        root = new Node;
    }

    void insert(string key)
    {
        Node *temp;
        temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
                temp->children[key[i]] = new Node;

            temp = temp->children[key[i]];
        }
        temp->endofword = true;
    }

    bool search(string key)
    {
        Node *temp;
        temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
                return false;
            temp = temp->children[key[i]];
        }

        return temp->endofword;
    }

    // STARTSWITH FUNCTION BUILT
    bool startswith(string prefix)
    {
        Node *temp;
        temp = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (temp->children.count(prefix[i]) == 0)
                return false;
            temp = temp->children[prefix[i]];
        }

        return true;
    }
};

int main()
{
    Trie tr;
    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    for (string ele : words)
    {
        tr.insert(ele);
    }

    cout << tr.startswith("app");
    cout << tr.startswith("man");
    cout<<tr.startswith("woma");
    cout << tr.startswith("wob");

    return 0;
}