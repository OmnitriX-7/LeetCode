class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        n = len(s)
        last_idx = {}
        stack = []
        visited = set()

        for i in range(n):
            last_idx[s[i]] = i

        for i in range(n):
            if s[i] in visited:
                continue
            
            while len(stack) > 0 and s[i] < stack[-1] and i < last_idx[stack[-1]]:
                popped = stack.pop()
                visited.remove(popped)

            stack.append(s[i])
            visited.add(s[i])
        
        return "".join(stack)