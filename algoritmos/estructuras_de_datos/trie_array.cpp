#include <bits/stdc++.h> 
using namespace std;
int cont = 0;
int nodeCount = 0;

struct node {
    char currentCharacter;       // 'a'
    bool isWord = false;
    int number = 0;              // false 
    struct node *children[27];  // sus nodos hijos  [null,null,null.....] 
}*trie; 

// Inicializar 

void init() {
    trie = new node();
}

void insertWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
            cont++;
        }
        currentNode->number = currentNode->number+1;
        cout << currentNode->number << endl;
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
    }
    currentNode->isWord = true;
}

bool searchWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->isWord;
}

int findPrefix() {
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
}


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


void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe :P"<<endl;
    }
}

int main() {
    init();
    /*int N;
    cin >> N;
    while (N--){
        string words;
        cin >> words;
        insertWord(words);
    }
    cout << cont << endl;
    return 0;*/

    string word = "alan";
    insertWord(word);
    isThereWord(word);
    word = "alanoca";   
    insertWord(word);
    isThereWord(word);
    word = "alfredo";   
    insertWord(word);
    isThereWord(word);
    return 0;
}