int Solution::repeatedNumber(const vector<int> &v) {
     vector<int> numRay = v;
     int arr_size = v.size();
     for (int i = 0; i < arr_size; i++) {
        numRay[(numRay[i]-1) % arr_size]
            = numRay[(numRay[i]-1)% arr_size] + arr_size;
    }
    for (int i = 0; i < arr_size; i++) {
        if (numRay[i] >= arr_size * 2) {
            return i+1;
        }
    }
     return -1;
}
