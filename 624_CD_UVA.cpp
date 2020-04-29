#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n,track,duration, bestdur;
vector <int> cd, bestconfig;

void setoftrack(int remS, int ind, vector <int> used){
    if(ind == track){
        duration = n - remS;
        if (duration > bestdur){
            bestdur = duration;
            bestconfig = used;
        }
        return;
    }
    if(remS - cd[ind] >= 0){
        used.push_back(ind);
        setoftrack(remS - cd[ind],ind + 1,used);
        used.pop_back();
    }
    setoftrack(remS, ind + 1,used);
}

int main(void){
    while(cin >> n){
        cin >> track;
        cd.reserve(track);
        vector <int> used;
        for(int i = 0; i < track; i++){
            cin >> cd[i];
        }
        bestdur = 0;
        setoftrack(n,0,used);
        for(int i = 0; i < bestconfig.size(); i++){
            cout << cd[bestconfig[i]] << " ";
        }
        cout << "sum:" <<  bestdur << endl;
        used.clear();
        cd.clear();
    }
    return 0;
}
