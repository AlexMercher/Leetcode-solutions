class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        maxi=max(nums)
        mini=min(nums)
        ans=[]
        nums_set=set(nums)
        for i in range(mini,maxi):
            if i in nums_set: 
                continue
            ans.append(i)
        return ans
        