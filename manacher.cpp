//求最大回文子串 ： manacher 算法

#include<iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        const int len = s.size();
        if(len <= 1) return -1;
        int maxLen = 0;
        for(int i = 1; i < len; i++){
            //寻找以i-1,i为中点偶数长度的回文
            int low = i-1, high = i;
            while(low >= 0 && high < len && s[low] == s[high]){
                 low--; high++;
            }
            if(high - low - 1 > maxLen)
               maxLen = high - low -1;
            //寻找以i为中心的奇数长度的回文
            low = i- 1; high = i + 1;
            while(low >= 0 && high < len && s[low] == s[high]){
                low--; high++;
            }
            if(high - low - 1 > maxLen)
               maxLen = high - low -1;
        }
        cout<<maxLen<<endl;
    }
    return 0;
}
