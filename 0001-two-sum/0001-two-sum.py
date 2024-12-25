class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for i in range(len(nums)):
            a = nums[i]
            b = target - a
            if b in mp:
                return [mp[b], i]
            mp[a] = i
        return [] 
        