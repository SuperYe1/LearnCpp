#include <iostream>
#include <vector>
using namespace std;

class Trie
{
private:
    vector<Trie *> children;
    bool isEnd;

public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false)
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *Node = this;
        for (char c : word)
        {
            if (Node->children[c - 'a'] == NULL)
                Node->children[c - 'a'] = new Trie();
            Node = Node->children[c - 'a'];
        }
        Node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *Node = this;
        for (char c : word)
        {
            Node = Node->children[c - 'a'];
            if (Node == NULL)
                return false;
        }
        return Node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *Node = this;
        for (char c : prefix)
        {
            Node = Node->children[c - 'a'];
            if (Node == NULL)
                return false;
        }
        return true;
    }
};

int main()
{

    system("pause");
    return 0;
}
