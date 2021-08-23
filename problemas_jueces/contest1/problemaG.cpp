//TRIE

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

int main() {
    int P, S;
    cin >> P >> S;
    init();
    while(P != 0 && S != 0){
        while(P--){
            string wordP;
            cin >> wordP;
            insertWord(wordP);
        }
        while(S--){
            string wordS;
            cin >> wordS;
            insertWord(wordS);
        }
    }
    return 0;
}