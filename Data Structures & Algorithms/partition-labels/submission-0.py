class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        letters = Counter(s)
        
        i = 0
        visited = set()
        cnt = 0
        res = []

        while i < len(s):

            letters[s[i]] -= 1
            if letters[s[i]] > 0:
                visited.add(s[i])
            cnt = i
            i += 1
            
            while i < len(s) and len(visited) > 0:
                letters[s[i]] -= 1
                if letters[s[i]] > 0:
                    visited.add(s[i])
                elif letters[s[i]] == 0 and s[i] in visited:
                    visited.remove(s[i])
                i += 1

            if i != cnt:
                res.append(i - cnt)

        return res        