class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        if(pattern.size()!=words.size()) return false;
        unordered_map<char,string> CharToString;
        unordered_map<string,char> StringToChar;
        int n=pattern.size();
        for(int i=0;i<n;i++){
            char c=pattern[i];
            string w=words[i];
            if(CharToString.count(c) && CharToString[c]!=w) return false;
            if(StringToChar.count(w) && StringToChar[w]!=c) return false;
            CharToString[c]=w;
            StringToChar[w]=c;
        }
        return true;
    }
};