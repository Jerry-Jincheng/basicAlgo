
// 背包问题
/*

如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有 0 个、 1 个或 2 个附件。附件不再有从属于自己的附件。王强想买的东西很多，为了不超出预算，他把每件物品规定了一个重要度，分为 5 等：用整数 1 ~ 5 表示，第 5 等最重要。他还从因特网上查到了每件物品的价格（都是 10 元的整数倍）。他希望在不超过 N 元（可以等于 N 元）的前提下，使每件物品的价格与重要度的乘积的总和最大。
    设第 j 件物品的价格为 v[j] ，重要度为 w[j] ，共选中了 k 件物品，编号依次为 j 1 ， j 2 ，……， j k ，则所求的总和为：
v[j 1 ]*w[j 1 ]+v[j 2 ]*w[j 2 ]+ … +v[j k ]*w[j k ] 。（其中 * 为乘号）
    请你帮助王强设计一个满足要求的购物单。
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 100, M = 32000;
int v[N][3], c[N][3], f[M];
int n, m, cnt;


int main(){
    while(scanf("%d%d", &m, &n) == 2)// check for the first line for total money and number of things
    {
        memset(v, 0, sizeof(v[0]) * (n + 5));// store the
        memset(c, 0, sizeof(c[0]) * (n + 5));// c[] store the total cost of certain combinations
        memset(f, 0, sizeof(f[0]) * (m + 5));// initialise the f with all zeros
        for(int i = 1; i <= n; ++i){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if(z == 0) v[i][2] = x * y, c[i][2] = x;
            else for(int j = 0; j <= 1; ++j) if(v[z][j] == 0) {
                v[z][j] = x * y;
                c[z][j] = x;
                break;
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int k = m; k >= 0; --k){
                for(int s = 0; s < 4; ++s){
                    int val = v[i][2], cst = c[i][2];
                    for(int j = 0; j <= 1; ++j){
                        if(s & (1 << j)) val += v[i][j], cst += c[i][j];
                    }
                    if(cst <= k) f[k] = max(f[k], f[k - cst] + val);
                }
            }
        }
        printf("%d\n", f[m]);
    }
    return 0;
}
