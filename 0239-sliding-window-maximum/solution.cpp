class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;//Used only for storing the indices that are there.
        vector<int> ans;

        for(int right=0;right<nums.size();right++){
            while(!dq.empty() && dq.front()<=right-k) dq.pop_front();
            // Pop from the front to keep the window size in the k;

            while(!dq.empty() && nums[dq.back()]<nums[right]) dq.pop_back();
            // Pop from the back if the elements in the back are smaller that the element that is entering the phase.

            dq.push_back(right);
            if(right>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};