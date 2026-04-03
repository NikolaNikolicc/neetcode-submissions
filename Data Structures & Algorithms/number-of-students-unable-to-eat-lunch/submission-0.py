class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        prefs = Counter(students)
        res = len(students)
        for sandwich in sandwiches:
            if prefs[sandwich] > 0:
                prefs[sandwich] -= 1
                res -= 1
            else:
                break
        return res