class Solution:

    def encode(self, strs: List[str]) -> str:
        final = ""
        for s in strs:
            final += str(len(s)) + "#" + s
        return final

    def decode(self, s: str) -> List[str]:
        final = []
        pos = 0
        while pos < len(s):
            num = 0
            while s[pos] != "#":
                num *= 10
                num += int(s[pos])
                pos += 1

            pos += 1

            string = ""
            while num > 0:
                string += s[pos]
                num -= 1
                pos += 1
            final.append(string)

        return final