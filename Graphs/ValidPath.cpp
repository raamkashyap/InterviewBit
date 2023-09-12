string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    int rect[A+1][B+1];
    memset(rect, 0 , sizeof(rect));
 
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            for(int k=0;k<C;k++)
            {
                if(sqrt(pow(E[k]-i,2)+pow(F[k]-j,2)) <= D)
                {
                    rect[i][j] = -1;
                    break;
                }
            }
        }
    }
 
    if(rect[0][0]==-1 || rect[A][B]==-1)
        return "NO";
 
    queue<pair<int,int> > q;
    q.push({0,0});
    rect[0][0] = 1;
    int row[] = {0, 0, 1, 1, 1, -1, -1, -1};
    int col[] = {1, -1, 0, 1, -1, 0, 1, -1};
 
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(r==A && c==B)
            return "YES";
        
        // rect[r][c] = 1;
        for(int i=0;i<8;i++)
        {
            int new_r = r + row[i];
            int new_c = c + col[i];
            if(new_r>=0 && new_r<=A && new_c>=0 && new_c<=B && rect[new_r][new_c]==0)
            {
                rect[new_r][new_c] = 1;
                q.push({new_r,new_c});
            }
        }
    }
    return "NO";
}
