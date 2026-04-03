class Solution:
    def multiply(self, num1: str, num2: str) -> str:

        if num1 == "0" or num2 == "0":
            return "0"

        res = [0 for _ in range(len(num1) + len(num2))]

        offset = 0
        for ch2 in reversed(num2):
            for i, ch1 in enumerate(reversed(num1)):
                n1 = ord(ch1) - ord("0")
                n2 = ord(ch2) - ord("0")

                mul = n1 * n2 + res[offset + i]
                res[offset + i] = mul % 10
                res[offset + i + 1] += mul // 10

            offset += 1
                
        
        for i in range(len(res)):
            res[i] = chr(res[i] + ord("0"))

        start = len(res) - 1
        while start > -1 and res[start] == "0":
            start -= 1

        print("res: " + str(res) + " start: " + str(start))
        return "".join(res[start::-1])
                
