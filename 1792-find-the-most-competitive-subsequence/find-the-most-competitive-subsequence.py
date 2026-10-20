class Solution:
    def mostCompetitive(self, nums: list[int], k: int) -> list[int]:
        n = len(nums)
        stack = []
        for i in range(n):
            while len(stack) and stack[-1] > nums[i] and len(stack)-1+n-i >= k:
                stack.pop()
            
            if len(stack) < k:
                stack.append(nums[i])

        return stack        