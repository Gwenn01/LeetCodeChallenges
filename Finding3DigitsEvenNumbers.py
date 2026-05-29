from typing import List
class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        ...
        answer = []
        for i in range(100, 1000):
            ...
            if i % 2 == 0:
                count = 0
                three_digits = str(i)
                for j in digits:
                    if str(j) in str(three_digits):
                        three_digits = three_digits.replace(str(j), "", 1)
                        count += 1
                if count == 3:
                    answer.append(i)
        return answer
                                
                
        
digits = [2,2,8,8,2]
my_class = Solution()
print(my_class.findEvenNumbers(digits))
        