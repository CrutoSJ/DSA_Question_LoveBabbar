// #Question:-

// Link-> https://www.naukri.com/code360/problems/implement-trie_631356

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        char data;
        trieNode* children[26];
        bool isTerminal;

        trieNode(char ch){
            this->data=ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {

    trieNode* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new trieNode('\0');
    }

    void insertUtil(trieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal= true;
            return ;
        }

        int idx = word[0] - 'a';
        trieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        } else{
            child = new trieNode(word[idx]);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        return insertUtil(root, word);
    }

    bool searchUtil(string word, trieNode* root){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int idx = word[0] - 'a';
        trieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        } else{
            return false;
        }

        return searchUtil(word.substr(1), child);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(word, root);
    }

    bool prefixUtil(string word, trieNode* root){
        if(word.length() == 0){
            return true;
        }

        int idx = word[0] - 'a';
        trieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        } else{
            return false;
        }

        return prefixUtil(word.substr(1), child);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixUtil(prefix, root);
    }
};