class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int now=0;
        for(auto it:str1){
            if(it==str2[now])now++;
            else{
                auto it2=it;
                if(it2=='z')it2='a';
                else it2++;
                if(it2==str2[now])now++;
            }
            if(now==str2.size())return true;
        }
        return false;
    }
};