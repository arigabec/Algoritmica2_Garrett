//TRIE

#include <bits/stdc++.h>
using namespace std;
string s[10010];

bool check(string a, string b){
    if(a.size() > b.size()){
        return false;
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            return false;
        } 
    }
    return true;
}

int main(){
    int cases, n;
    cin >> cases;
    while(cases--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        sort(s, s+n);
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(check(s[i], s[i + 1])){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}






/*bool flag;

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
}*/