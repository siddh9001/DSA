#include<iostream>
using namespace std;

struct TrieNode {
        TrieNode *children[26];
        bool isEndOfWord;
};
class Trie{
    public:
    TrieNode* getNode()
    {
        TrieNode* new_node = new TrieNode();

        for(int i=0;i<26;i++)
            new_node->children[i] = NULL;

        new_node->isEndOfWord = false;

        return new_node;
    }
    void insert(TrieNode *root, string key)
    {
        TrieNode* temp = root;

        for(int i=0;i<key.length();i++)
        {
            int index = key[i] - 'a';
            if(!temp->children[index])
                temp->children[index] = getNode();

            temp = temp->children[index];
        }

        temp->isEndOfWord = true;
    }
    bool search(TrieNode* root, string key)
    {
        TrieNode* temp = root;

        for(int i=0;i<key.length();i++)
        {
            int index = key[i] - 'a';
            if(!temp->children[index])
                return false;

            temp = temp->children[index];
        }

        return (temp->isEndOfWord);
    }
};
int main()
{
    Trie T;
    int n;
    cin >> n;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        string temp;
        cout << "Enter string " << i+1 << ": ";
        cin >> temp;
        arr[i] = temp;
    }

    TrieNode *root = T.getNode();

    for(int i=0;i<n;i++)
    {
        T.insert(root, arr[i]);
         cout << i+1 <<" String inserted..\n";
    }

    cout << "Hello is " <<(T.search(root, "hello") ? "Present" : "Not Present") << "\n";
    cout << "This is " <<(T.search(root, "this") ? "Present" : "Not Present") << "\n";

    return  0;
}