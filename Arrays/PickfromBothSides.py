class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        curr_val = 0
        max_val = 0
        for i in range(B):
            curr_val += A[i]
        max_val = curr_val
        j = len(A) -1
        for i in range(B - 1,-1,-1):
            curr_val = curr_val + A[j] - A[i]
            max_val = max(max_val,curr_val)
            j -=1
        
        return max_val