string Solution::countAndSay(int A) {
    if(A == 1) return "1";
    if(A == 2) return "11";
    vector<string> dp(A+1,"");
    dp[1] = "1";
    dp[2] = "11";
    for(int i=3;i<=A;i++){
        string last = dp[i-1];
        string temp = "";
        int count =1;
        for (int j = 1; j < last.size(); j++) {
            if (last[j] == last[j - 1])
                count++;
            else {
                temp += to_string(count) + last[j - 1];
                count = 1;
            }
        }    
        temp += to_string(count) + last[last.size() - 1];
        dp[i] = temp;
    }
    return dp[A];
    
}
