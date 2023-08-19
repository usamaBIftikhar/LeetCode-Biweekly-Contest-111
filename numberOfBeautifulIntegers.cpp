class Solution {
public:
    int dp[11][30][11][11];
    int DP(int x,int k){
        memset(dp,0,sizeof(dp));
        char cc[20];
        sprintf(cc,"%d",x);
        int a=0,b=0,c=0;
        for(int i = 0;cc[i]!=0;i++){
            for(int j = 0;j<cc[i]-'0';j++){
                if(i==0&&j==0){
                    continue;
                }
                int ta=(a*10+j)%k;
                int tb=b;
                int tc=c;
                if(j%2==0)tb++;
                else tc++;
                dp[i][ta][tb][tc]++;
            }
            a=(a*10+cc[i]-'0')%k;
            if((cc[i]-'0')%2==0)b++;
            else c++;
        }
        for(int i = 1;cc[i]!=0;i++){
            for(int j = 1;j<=9;j++){
                if(j%2==0)dp[i][j%k][1][0]++;
                else dp[i][j%k][0][1]++;
            }
        }
        for(int i = 1;cc[i]!=0;i++){
            for(int j = 0;j<k;j++){
                for(int a=0;a<10;a++){
                    for(int b=0;b<10;b++){
                        for(int c=0;c<10;c++){
                            int ta=(j*10+c)%k;
                            int tb=a;
                            int tc=b;
                            if(c%2==0)tb++;
                            else tc++;
                            if(dp[i-1][j][a][b])
                            dp[i][ta][tb][tc]+=dp[i-1][j][a][b];
                        }
                    }
                }
            }
        }
        int sum=0;
        int n=strlen(cc);
        for(int i = 0;i<10;i++){
            sum+=dp[n-1][0][i][i];
        }
        return sum;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return DP(high+1,k)-DP(low,k);
    }
};