class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        number_to_index = {nums[i]: i for i in range(len(nums))} # O(n)
        
        for i in range(len(nums)): # O(n)
            ni = nums[i]
            npair =  target - ni
            if npair in number_to_index: 
                j = number_to_index[npair]
                if i !=j :
                    return [i, number_to_index[npair]]