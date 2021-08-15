#include <bits/stdc++.h>
using namespace std;
int cont = 0;
int nodeCount = 0;

struct node {
    char currentCharacter;       
    bool isWord = false;
    int number = 0;             
    struct node *children[27]; 
}*trie; 

void init() {
    trie = new node();
}

void insertWord(string word) {   
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';      
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
        }
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
    }
    currentNode->isWord = true;
}

bool searchWord(string word) {   
    node *currentNode =  trie;  
    for (int i = 0; i < word.length(); i++) {
        int character = word[i] - 'a';      
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->isWord;
}

void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"Si existe "<<word<<" en el trie :)"<<endl;
    } else {
        cout<<"No Existe :("<<endl;
    }
}

bool trieDelete(string word){
    if(searchWord(word)){
        node *currentNode =  trie;
        for(int i = 0; i < word.length(); i++){
            int character = word[i] - 'a';
            currentNode -> children[character];
            currentNode = currentNode -> children[character];
        }
        currentNode->isWord = false;
    }
}

/*int findPrefix() {
    node *currentNode =  trie;  
    for (int i = 0; i< cont; i++) {
        currentNode = currentNode->children[i];
        //int character = prefix[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->isWord == false ) {
           return 0;
        }
        currentNode = currentNode->children[i];
    }
    //return currentNode->countWords;
}*/

/*int findWords(string prefix) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< prefix.length(); i++) {
        int character = prefix[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return 0;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->countWords;
}*/

/*void showTrie(node currentNode ) {
    node *currentNode =  trie;  
    for (int i =0; i< 27; i++) {
        currentNode = currentCharacter = word[i];
        cout (char(i+'a'));
        showTrie(currentNode)
    }
}*/

int main() {
    init();
    insertWord("alan");
    isThereWord("alan"); 
    insertWord("alanoca");
    isThereWord("alanoca");
    insertWord("alfredo");
    isThereWord("alfredo");
    trieDelete("alan");
    trieDelete("alanoca");
    isThereWord("alan");
    isThereWord("alanoca");
    return 0;
}