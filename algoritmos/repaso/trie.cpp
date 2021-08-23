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
    //cout<<"Se inserto la palabra "<<word<<endl;
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
    string word = "2350PaulLandaeta";
    insertWord(word);
    word = "2150JuanPerez";   
    insertWord(word);
    word = "2210LucasAlba";   
    insertWord(word);
    word = "2211ElianaRamirez";   
    insertWord(word);
    cout << findPrefixCommon() << endl;
    return 0;
}