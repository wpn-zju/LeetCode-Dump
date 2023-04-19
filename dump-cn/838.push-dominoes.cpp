class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        int leftr[n],rightl[n];
        int tmp=-999999;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R') tmp=i;
            else if(dominoes[i]=='L') tmp=-999999;
            leftr[i]=tmp;
        }
        tmp=999999;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L') tmp=i;
            else if(dominoes[i]=='R') tmp=999999;
            rightl[i]=tmp;
        }
        string res=dominoes;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='.'){
                int ld=i-leftr[i];
                int rd=rightl[i]-i;
                if(ld>n&&rd>n) res[i]='.';
                else if(ld<=n&&rd>n){
                    res[i]='R';
                }
                else if(ld>n&&rd<=n){
                    res[i]='L';
                }
                else{
                    if(ld>rd) res[i]='L';
                    if(ld<rd) res[i]='R';
                }
            }
        }
        return res;
    }
};