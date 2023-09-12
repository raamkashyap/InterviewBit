class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        size = len(A)
        count =0;
        for i in range(size):
            isBulbLight = False
            left = max(0,i-B+1)
            right = min(size-1,i+B-1)
            for light in range(right,left-1,-1):
                if  A[light] == 1:
                    count += 1
                    i = light + B
                    isBulbLight = True
                    break
        
             if isBulbLight == False
                return -1
        return count
                