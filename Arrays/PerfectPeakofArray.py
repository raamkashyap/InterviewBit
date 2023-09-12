class Solution:
    # @param A : list of integers
    # @return an integer
    def perfectPeak(self, A):
        n = len(A)
        left = [0]*n
        right = [0]*n
        left[0] = A[0]
        right[n-1] = A[n-1]
        for i in range(1,n):
            left[i] = max(left[i-1],A[i])
        for i in range(n-2,-1,-1):
            right[i] = min(right[i+1],A[i])
            
        # print left
        # print "hello"
        # print right
        for i in range(1,n-1):
            if(A[i] > left[i-1] and A[i] < right[i+1]):
                return 1
        return 0
                