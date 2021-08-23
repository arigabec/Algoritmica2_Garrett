//TRIE

#include <bits/stdc++.h>
using namespace std;
bool flag;

struct node {
    char currentCharacter;       
    bool isWord = false;
    int number = 0;             
    struct node *children[27]; 
}*trie; 

void init() {
    trie = new node();
    flag = true;
}

bool insertWord(string word) {   
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

bool searchWord() {   
    node *currentNode =  trie;  
    for (int i = 0; i < 27; i++) {     
        if(currentNode->isWord == true){
           currentNode= currentNode->children[i+1];
           if(currentNode->isWord == false){
               return false;
           }
        }
    }
}

void del(node *currentNode =  trie){ 
    for(int i = 0; i < 20; i++){
        if(currentNode->children[i] != NULL){
            del(currentNode->children[i]);
        }
    }
    delete(currentNode);
}

int main() {
    int cases;
    cin >> cases;
    init();
    while(cases--){
        int numbers;
        cin >> numbers;
        while (numbers--){
            string number;
            cin >> number;
            if(flag){
                flag = insertWord(number);
            }
        }
        if(!flag){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        del();
    }
    return 0;
}