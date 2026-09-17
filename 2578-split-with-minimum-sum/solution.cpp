class Solution {
public:
    int splitNum(int num) {
        string nums=to_string(num);
        sort(nums.begin(),nums.end());
        int num1,num2;
        num1=num2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0) num1=num1*10+(nums[i]-'0');
            else num2=num2*10+(nums[i]-'0');
        }
        return num1+num2;
    }
};