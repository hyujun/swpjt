#include <iostream>
using namespace std;
 
int R;//원의 반지름
 
void InputData(){
    cin >> R;
}
 
int Solve() {
    int count = 0;
    for (int a = 1; a <= R; a++) {
        for (int b = 1; b <= R; b++) {
            if (a * a + b * b <= R * R) {
                count++;
            }
        }
    }
    return count * 4;
}
 
int main() {
    int ans;
    InputData();
    ans = Solve();
    cout << ans << endl;
    return 0;
}