class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i=0;i<number.size();i++){
            if(number[i]==digit && number[i+1]>digit){
                number.erase(i,1);
                return number;
            }
        }
        int pos=number.rfind(digit);
        number.erase(pos,1);
        return number;
    }
};