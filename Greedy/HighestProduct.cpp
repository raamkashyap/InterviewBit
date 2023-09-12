int Solution::maxp3(vector<int> &A) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
    for(auto num : A){
        if(num > max1){
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if(num > max2 && num !=max1){
            max3 = max2;
            max2 = num;
        }
        else if(num > max3 && num != max1 && num != max2){
            max3 = num;
        }
        if(num < min1){
            min2 = min1;
            min1 = num;
        }
        else if(num < min2){
            min2 = num;
        }
    }
    /*for(auto num : A){
        if(num < min1){
            min3 = min2;
            min2 = min1;
            min1 = num;
        }
        else if(num < min2 && num !=min1){
            min3 = min2;
            min2 = num;
        }
        else if(num < min3 && num != min1 && num != min2){
            min3 = num;
        }
    }*/
    return max(min1*min2*max1,max1*max2*max3);
}
