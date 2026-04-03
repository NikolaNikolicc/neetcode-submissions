class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for elem in s:
            if elem in ("(", "{", "["):
                stack.append(elem)
            elif len(stack) == 0:
                return False
            elif elem == ")":
                if stack[-1] == "(":
                    stack.pop(-1)
                else:
                    return False
            elif elem == "}":
                if stack[-1] == "{":
                    stack.pop(-1)
                else:
                    return False
            elif elem == "]":
                if stack[-1] == "[":
                    stack.pop(-1)
                else:
                    return False
        return True if len(stack) == 0 else False