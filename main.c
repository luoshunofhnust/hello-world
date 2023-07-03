#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial ( const int N )
{
    int res[300],res1[300];
    for(int i=0;i<300;i++){
        res[i] =0;
        res1[i] = 0;
    }
    res[0] = 1;

    for(int i=2;i<=N;i++){
        int t = i;
        int cnt = 0;
        while(t!=0){
            //提取t中每一位数字
            int p = t%10;
            t = t/10;
            printf("cnt %d\n",cnt);
            for(int j=0;j<300&&p!=0;j++){
                res1[j+cnt]+=p*res[j];
                int k = j+cnt;
                while(res1[k]>10){
                    res1[++k]+=res1[i]/10;
                    res1[k]=res1[i]%10;
                }
            }

            cnt++;
        }
        for(int k=0;k<300;k++){
            res[k] =res1[k];
            res1[k] = 0;
        }
    }

    for(int i=299;i>=0;i--){
        int kaiguan = 0;
        if(kaiguan||res[i]!=0){
            printf("%d",res[i]);
            kaiguan = 1;
        }
    }
}
