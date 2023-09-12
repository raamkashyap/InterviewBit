int Solution::solve(vector<int> &A) {
    int oddSum =0, evenSum =0;
    for(int i =1; i < A.size();i += 2){
        oddSum += A[i];
    }
    for(int i = 0;i<A.size();i +=2){
        evenSum += A[i];
    }
    int count =0, currEven = 0, currOdd =0, newEvenSum =0, newOddSum=0;
    for(int i=0;i<A.size();i++){
        if(i%2 ==1){
            currOdd += A[i];
            
            newEvenSum = currEven + oddSum - currOdd;
            newOddSum = currOdd + evenSum - currEven -A[i];
        }
        else{
            currEven += A[i];
            
            newOddSum = currOdd + evenSum - currEven;
            newEvenSum = currEven + oddSum - currOdd - A[i];
        }
        if(newEvenSum == newOddSum ){
            count++;
        }
    }
    return count;
}
