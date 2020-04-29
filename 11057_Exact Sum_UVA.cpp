#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int N;
    while(cin >> N){
        vector <int> v(N);
        int target;
        for(int i = 0; i < N; i++)
            cin >> v[i];
        sort(v.begin(),v.end());
        cin >> target;
        int hi = N,lo,dif = 10000001,best;
        for(int i = 0; i < N; i++){
            int a = v[i];
            int b = target - a;
            bool ok = false;
            lo = i + 1;
            hi = N - 1;
            while(hi >= lo){
                int mid = (hi + lo) / 2;
                if(v[mid] == b){
                    ok = true;
                    break;
                }
                else if(v[mid] > b)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            if(ok){
                if((b - a) < dif){
                    best = a;
                    dif = b - a;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << best << " and " << target - best << endl;
        cout << endl;
    }
    return 0;
}
