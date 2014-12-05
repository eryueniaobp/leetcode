
int dp[30][30];
 
void LCS_dp(char * X, int xlen, char * Y, int ylen)
{
    maxlen = maxindex = 0;
    for(int i = 0; i < xlen; ++i)
    {
        for(int j = 0; j < ylen; ++j)
        {
            if(X[i] == Y[j])
            {
                if(i && j)
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                if(dp[i][j] > maxlen)
                {
                    maxlen = dp[i][j];
                    maxindex = i + 1 - maxlen;
                }
            }
        }
    }
    outputLCS(X);
}

