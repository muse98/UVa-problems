/*
=======================
 A : Rim Benyaich/sse/stud/aui/ma
 De : Rim Benyaich/sse/stud/aui/ma
 Date : 06/04/2018 09:28
 Objet : Wedding Shopping
 =======================
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[201][21],N,M,C;
int price[21][21],K[21];

int shopping(int remM, int G){
        if(remM < 0)
                return -1e6;
        if(G == C)
                return M - remM;
        if(dp[remM][G] != -1)
                return dp[remM][G];

        int x = -1e6;

        for(int i = 0; i < K[G]; i++)
                x = max(x,shopping(remM - price[G][i],G + 1));

        return dp[remM][G] = x;

}

int main() {
        cin >> N;

        while(N--){
                cin >> M >> C;

                for(int i = 0; i < C; i++){
                        cin >> K[i];
                        for(int j = 0; j < K[i]; j++)
                                cin >> price[i][j];
                }
                memset(dp, -1, sizeof dp);
                int ans = shopping(M,0);

                if(ans > 0)
                        cout << ans << endl;
                else
                        cout << "no solution" << endl;

        }
        return 0;
}
