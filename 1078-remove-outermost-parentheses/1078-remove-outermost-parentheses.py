class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        res = ""
        count = 0
        
        for ch in s:
            if ch == '(':
                if count > 0:
                    res += ch
                count += 1
            else:
                count -= 1
                if count > 0:
                    res += ch

        return res