class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        
        def correspond(w1, w2):
            if len(w1) != len(w2):
                return False

            cnt = 0
            for ch1, ch2 in zip(w1, w2):
                if ch1 != ch2 and cnt == 0:
                    cnt += 1
                elif ch1 != ch2 and cnt != 0:
                    return False
            return True
        
        used = set()
        def dfs(w):

            if w == endWord:
                return 1

            minLen = float("inf")
            used.add(w)
            for word in wordList:
                if word not in used and correspond(w, word):
                    minLen = min(minLen, 1 + dfs(word))
            used.remove(w)
            return minLen
            
        res = dfs(beginWord)
        return res if res != float("inf") else 0