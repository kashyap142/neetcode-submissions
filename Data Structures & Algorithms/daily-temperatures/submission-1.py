class Solution:
    def dailyTemperatures(self, temp: List[int]) -> List[int]:
        n = len(temp)
        st = []
        ans = [0] * n

        for i in range(n):
            while st and temp[st[-1]] < temp[i]:
                ans[st[-1]] = i - st[-1]
                st.pop()
            st.append(i)

        return ans

