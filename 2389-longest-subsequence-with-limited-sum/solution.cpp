class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ans;
        for(int x:queries){
            int sum=0;
            int count=0;
            for(int i=0;i<n;i++){
                if(sum+nums[i]>x) break;
                sum+=nums[i];
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};