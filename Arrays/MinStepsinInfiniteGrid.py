class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @return an integer
    def coverPoints(self, A, B):
        size = len(A)
        x ,y = A[0], B[0]
        maxSteps = 0
        for i in range(1,size):
            dx = abs(x - A[i])
            dy = abs(y - B[i])
            maxSteps += max(dx,dy)
            x,y = A[i],B[i]
        return maxSteps
            