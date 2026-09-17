class Solution {
public:
    int replaceall(string& nums,char c,char tar){
        int n=nums.size();
        for(int i=0;i<n;i++){
            char ch=nums[i];
            if(ch==c) nums[i]=tar;
        }
        return stoi(nums);
    }
    int minMaxDifference(int num) {
        string nums=to_string(num);
        int maax=num;
        int n=nums.size();
        for(int i=0;i<n;i++){
            char c=nums[i];
            if(c!='9'){
                nums[i]='9';
                maax=replaceall(nums,c,'9');
                break;
            }
        }
        int miin=0;
        nums=to_string(num);
        for(int i=0;i<n;i++){
            char c=nums[i];
            if(c!='0'){
                nums[i]='0';
                miin=replaceall(nums,c,'0');
                break;
            }
        }
        return maax-miin;
    }
};