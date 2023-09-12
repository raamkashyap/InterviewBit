bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    /*vector<pair<int,int>> v;
    for(int i=0;i<arrive.size();i++){
        v.push_back({arrive[i],depart[i]});
    }
     sort(v.begin(),v.end());
    for(int i=0;i<arrive.size();i++){
        cout<< v[i].first<< " "<< v[i].second<< endl;
    }*/
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int count =0, i =0,j=0;
    while(i<arrive.size() && j <arrive.size()){
        if(arrive[i] <= depart[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        if(count >K) return false;
    }
    return true;
}
