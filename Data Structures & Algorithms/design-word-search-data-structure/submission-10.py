class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.word = True

    def search(self, word: str) -> bool:
        
        def dfs(root, position):
            curr = root

            for i in range(position, len(word)):
                c = word[i]
                if c == '.':
                    for child in curr.children.values():
                        if dfs(child, i + 1):
                            return True
                    return False
                elif c in curr.children:
                    curr = curr.children[c]
                else:
                    return False
            return curr.word

        return dfs(self.root, 0)