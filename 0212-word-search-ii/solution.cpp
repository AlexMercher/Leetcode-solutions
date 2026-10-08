class Solution {
private:
    struct alignas(64) TrieNode{
        uint32_t child[26];
        uint32_t mask{0};
        int word_index{-1};

        TrieNode()=default;
    };
    vector<TrieNode> trie;
    vector<string> *wordsPtr;
    int m,n;

    void insert(const string& word,int index){
        uint32_t level=0;
        for(char c:word){
            uint32_t idx=c-'a';

            if((trie[level].mask & (1u<<idx))==0){
                trie[level].child[idx]=trie.size();
                trie[level].mask |=(1u<<idx);
                trie.emplace_back();
            }
            level=trie[level].child[idx];
        }
        trie[level].word_index=index;
    }
    void dfs(vector<vector<char>>& board,int r,int c,uint32_t level,vector<string>& answer){
        char ch=board[r][c];
        uint32_t idx=ch-'a';

        if((trie[level].mask & 1u<<idx)==0){
            return;
        }
        uint32_t next=trie[level].child[idx];
        if(trie[next].word_index!=-1){
            int wordIndex=trie[next].word_index;
            answer.push_back((*wordsPtr)[wordIndex]);
            trie[next].word_index=-1;//Prevent finding the same word again.
        }

        board[r][c]='#';//Mark the current one as visited
        static constexpr int dr[4]={1,-1,0,0};
        static constexpr int dc[4]={0,0,1,-1};
        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];

            if(nr<0 || nc<0 || nr>=m || nc>=n) continue;
            if(board[nr][nc]=='#') continue;
            dfs(board,nr,nc,next,answer);
        }
        board[r][c]=ch;//Restoring the board
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();

        trie.reserve(3000001);
        trie.emplace_back();

        wordsPtr=&words;

        for(int i=0;i<words.size();i++){
            insert(words[i],i);
        }
        vector<string> answer;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                dfs(board,r,c,0,answer);
            }
        }
        return answer;
    }
};