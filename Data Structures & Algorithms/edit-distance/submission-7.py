class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # word2 would be shorter one (we need it for space optimization)
        if len(word1) < len(word2):
            word1, word2 = word2, word1

        old = [i for i in range(len(word2), -1, -1)]

        for w1 in range(len(word1) - 1, -1, -1):
            new = [0] * (len(word2) + 1)
            new[-1] = old[-1] + 1
            for w2 in range(len(word2) - 1, -1, -1):
                if word2[w2] == word1[w1]:
                    new[w2] = old[w2 + 1]
                else:
                    new[w2] = 1 + min(old[w2], old[w2 + 1], new[w2 + 1])

            old = new[:]
            print(old)

        return old[0]