class Solution:
    def isValid(self, s: str) -> bool:
        p = {")":"(", "}":"{", "]":"["}
        stack = []
        for ch in s:
            if ch in p.values():
                stack.append(ch)
            else:
                if len(stack) > 0 and stack[-1] == p[ch]:
                    stack.pop()
                else:
                    return False

        return len(stack) == 0