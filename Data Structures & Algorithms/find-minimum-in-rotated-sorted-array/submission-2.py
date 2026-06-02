class Solution:
    def findMin(self, nums: List[int]) -> int:
        upper = len(nums) - 1
        lower = 0

        while lower < upper:
            mid = (upper + lower) // 2

            if nums[upper] < nums[mid]:
                lower = mid + 1
            else:
                upper = mid 
            
        return nums[lower]
