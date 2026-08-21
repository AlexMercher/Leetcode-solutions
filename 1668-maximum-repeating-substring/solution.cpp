class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k=0;
        string current=word;
        while(sequence.find(current)!=string::npos){
            k++;
            current+=word;
        }
        return k;
    }
};