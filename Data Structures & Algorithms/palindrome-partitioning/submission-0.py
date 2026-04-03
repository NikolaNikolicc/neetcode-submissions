from typing import List, Set, Tuple

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def pali(left: int, right: int) -> Set[Tuple[str, ...]]:
            if left > right:
                return {tuple()}  # Empty tuple for base case
            
            unique_partitions = set()
            
            for i in range(left, right + 1):
                # Odd-length palindromes
                l, r = i, i
                while l >= left and r <= right and s[l] == s[r]:
                    l -= 1
                    r += 1
                current_pali = s[l + 1 : r]
                lpali = pali(left, l)
                rpali = pali(r, right)
                for lp in lpali:
                    for rp in rpali:
                        partition = lp + (current_pali,) + rp
                        unique_partitions.add(partition)
                
                # Even-length palindromes
                if i + 1 <= right and s[i] == s[i + 1]:
                    l_even, r_even = i, i + 1
                    while l_even >= left and r_even <= right and s[l_even] == s[r_even]:
                        l_even -= 1
                        r_even += 1
                    current_even_pali = s[l_even + 1 : r_even]
                    lpali_even = pali(left, l_even)
                    rpali_even = pali(r_even, right)
                    for lp in lpali_even:
                        for rp in rpali_even:
                            partition = lp + (current_even_pali,) + rp
                            unique_partitions.add(partition)
            
            return unique_partitions
        
        # Convert tuples back to lists
        return [list(partition) for partition in pali(0, len(s) - 1)]