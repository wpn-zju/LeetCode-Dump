class Solution {
public:

    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        vector<int> vHave(10001);  ///代表有相应数字
        vector<vector<int>> vNode(10001);   ///后续
        vector<int> vRu(10001);    //入度
        int sN=0;
        for(int i=0;i<seqs.size();i++){                
            int last=0;

            //vHave[seqs[i][0]]=1;
            for(int j=0;j<seqs[i].size();j++){
                int t=seqs[i][j];
                if(t>10000||t<=0)
                    return false;

                vHave[t]=1;

                if(last!=0){
                    vRu[t]++;
                    vNode[last].push_back(t);                    
                }

                last=t;
            }
        }
        //return true;
        //cout<<"OK"<<endl;
        int begin=0;  ///最开始的数字
        for(int i=1;i<=10000;i++){
            if(vHave[i]>0){
                sN++;
                if(vRu[i]==0){
                    if(begin==0){
                        begin=i;
                    }else{
                        return false;
                    }
                }
            }
        }
        //cout<<"OK1"<<endl;
        vector<int> vAns;
        while(begin!=0){
            vAns.push_back(begin);
            vector<int> &vT=vNode[begin];
            int b1=0;
            for(int i=0;i<vT.size();i++){
                
                if(--vRu[vT[i]]==0){
                    if(b1!=0){
                        return false;
                    }
                    b1=vT[i];
                }
            }
            begin=b1;
        }
        if(sN!=vAns.size()){
            return false;  //有循环依赖
        }
        //cout<<"OK2"<<endl;
        //cout<<vAns.size()<<" "<<org.size()<<endl;
        int index=0;
        for(int i=0;i<vAns.size()&&index<org.size();i++){
            if(vAns[i]==org[index])
                index++;

        }
        return index==org.size();
    }
};