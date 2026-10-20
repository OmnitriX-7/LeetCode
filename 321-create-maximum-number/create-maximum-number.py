class Solution:
    def maxNumber(self, nums1: list[int], nums2: list[int], k: int) -> list[int]:
        n1 = len(nums1)
        n2 = len(nums2)
        final = []

        for i in range(n1+1):
            pick1, pick2 = i, k-i
            if (pick1 <= k and 0 <= pick2 <= n2):
                ans = []
                ans1 = []
                ans2 = []

                for j in range(n1):
                    while (ans1 and ans1[-1] < nums1[j] and len(ans1)-1+n1-j >= pick1):
                        ans1.pop()
                    if len(ans1) < pick1: ans1.append(nums1[j])

                for j in range(n2):
                    while (ans2 and ans2[-1] < nums2[j] and len(ans2)-1+n2-j >= pick2):
                        ans2.pop()
                    if len(ans2) < pick2: ans2.append(nums2[j])

                p1, p2 = 0, 0
                while p1 < pick1 or p2 < pick2:
                    if p1 == pick1: 
                        ans.append(ans2[p2])
                        p2 += 1
                    elif p2 == pick2: 
                        ans.append(ans1[p1])
                        p1 += 1
                    else:
                        if ans1[p1:] > ans2[p2:]:
                            ans.append(ans1[p1])
                            p1 += 1
                        else:
                            ans.append(ans2[p2])
                            p2 += 1

                if ans > final:
                    final = ans
        
        return final
        