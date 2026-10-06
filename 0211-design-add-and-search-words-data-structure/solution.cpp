class WordDictionary {
private:
    struct Node{
        Node* children[26];
        bool isEnd;
        Node(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
    };
    Node* root;

    bool dfs(Node* curr,string& word,int index){
        if(index==word.size()) return curr->isEnd;
        char c=word[index];

        //if the words are not . then only this part will work it can find the words that are definetly there in the trie;
        if(c!='.'){
            int idx=c-'a';
            if(curr->children[idx]==nullptr) return false;
            return dfs(curr->children[idx],word,index+1);
        }

        for(int i=0;i<26;i++){
            if(curr->children[i]!=nullptr){
                if(dfs(curr->children[i],word,index+1))
                    return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* curr=root;
        for(char c:word){
            int id=c-'a';
            if(curr->children[id]==nullptr){
                curr->children[id]=new Node();
            }
            curr=curr->children[id];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */