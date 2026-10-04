class Solution:
    def checkValidString(self, s: str) -> bool:
        min_open = 0
        max_open = 0
        
        for char in s:
            if char == '(':
                min_open += 1
                max_open += 1
            elif char == ')':
                min_open -= 1
                max_open -= 1
            else:  # char == '*'
                min_open -= 1  # '*' as ')'
                max_open += 1  # '*' as '('
            
            # If max_open < 0, we have too many ')'
            if max_open < 0:
                return False
            
            # min_open cannot be negative (we can't match non-existent '(')
            if min_open < 0:
                min_open = 0
                
        return min_open == 0