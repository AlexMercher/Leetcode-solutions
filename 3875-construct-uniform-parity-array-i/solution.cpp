class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
        /*If we have only 1 element that is there then its true by default.
        If we have more than one element then we can make either all odd or all even with them:
        Odd+Odd=> even
        Even+Odd=> Odd
        
        If only one Odd in the entire array then we can make only odds thus we make only odds of size n,
        If we have atleast 2 odds then we can make evens with them therefore we make sure that the evens are there in the same place but the odd ones are replaced by their substraction with another odd element. Thus in all cases we can make the nums 2 array of length n.*/
    }
};