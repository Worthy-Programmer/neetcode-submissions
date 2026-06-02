class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prev_data = {}

        for i, n in enumerate(nums):
            diff = target - n
            if diff in prev_data:
                return [prev_data[diff], i]
            prev_data[n] = i
        