class Solution {
public:
    bool isVowel(char c){
        return c=='A' || c=='a' || c=='E'||c=='e' ||c=='I'||c=='i'||c=='O'||c=='o'||
            c=='U'||c=='u';
    }
    string reverseVowels(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            while(left<right && !isVowel(s[left])) left++;
            while(left<right && !isVowel(s[right])) right--;
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};