#include <iostream>
using namespace std;


class trieNode{
  public:
    char data;
    trieNode* children[26];
    bool isTerminal;


  public:
    trieNode(char ch){
      data = ch;
      for(int i = 0; i < 26; i++){
        children[i] = NULL;
      }
      isTerminal = false;
    }
};

class Trie{
  public:
    trieNode* root;

  public:
    Trie(){
      root = new trieNode('\0');
    }

  public:
    void insertUtil(trieNode* root, string word){
      // base case
      if(word.length() == 0){
        root->isTerminal = true;
        return;
      }

      // letter present
      int index = word[0] - 'a';
      trieNode* child;

      if(root->children[index] != NULL){
        child = root->children[index];
      }

      else{      // letter prensent nahi hai
        child = new trieNode(word[0]);
        root->children[index] = child;
      }

      // recursion
      insertUtil(child, word.substr(1));
    }
  
    void insertWord(string word){
      insertUtil(root, word);
    }

    bool searchUtil(trieNode* root, string word){
      // base case
      if(word.length() == 0){
        return root->isTerminal;
      }

      int index = word[0] - 'a';
      trieNode* child;

      //present
      if(root->children[index] != NULL){
        child = root->children[index];
      }
      
      // absent
      else     return false;

      //recursion
      return searchUtil(child, word.substr(1));
    }


    bool searchWord(string word){
      return searchUtil(root, word);
    }


  void removeUtil(trieNode* root, string word){
    // base case 
    if(word.length() == 0){
      root->isTerminal = false;
    }

    int index = word[0] - 'a';
    trieNode* child;
    // present
    if(root->children[index] != NULL){
      child = root->children[index];
    }
    // absent
    else return;

    // recursion
    removeUtil(child, word.substr(1));
  }

  void removeWord(string word){
    if(!searchWord(word)){
      return;
    }

    removeUtil(root, word);
  }
};

int main() {
  Trie* t = new Trie();
  t->insertWord("abcd");

  cout<<"present or not:- "<<t->searchWord("abcd")<<endl;

  t->removeWord("abcd");
  cout<<"present or not:- "<<t->searchWord("abcd")<<endl;
  
  return 0;
}