#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    int T,n,p,x;

    cin >> T;

    while(T--){
        int a[1005] = {};
        cin >> n;
        cin >> p;
        a[0] = 1;
        for(int i = 0; i < p; i++){
            cin >> x;
            for(int j = n - x; j >= 0; j--){
                if(a[j] && !a[j + x])
                    a[j + x] = 1;
            }
        }
        if(a[n])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
