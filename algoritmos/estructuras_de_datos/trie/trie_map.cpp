#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int cont = 0;

struct node{
    map<char, node*> mapero;
    bool isWord;                
} *trie;

void init(){
    trie = new node();
    trie->isWord = false;
    cont++;
}

void insertWord(string word){
    node *currentNode =  trie;  
    for (int i = 0; i < word.length(); i++){
        if (!currentNode->mapero[word[i]]){
            currentNode->mapero[word[i]] = new node();
            cont++;
        }
        currentNode = currentNode -> mapero[word[i]];
    }
    currentNode->isWord = true;
    cout<<"Se inserto la palabra "<<word<<endl;
}

string findPrefixCommon(){
    node *currentNode = trie;
    string prefix = "";
    while (currentNode->mapero.size() == 1 && !currentNode->isWord){
        prefix += currentNode->mapero.begin()->first;
        currentNode = currentNode->mapero.begin()->second;
    }
    return prefix;
}

int main() {
    init(); 
    string word = "auto";
    insertWord(word);
    word = "autos";   
    insertWord(word);
    word = "automovil";   
    insertWord(word);
    //cout << cont << endl;
    cout << findPrefixCommon() << endl;
    return 0;
}