#include <iostream>
using namespace std;
 
char str[100000 + 10];//쇠막대기와 레이저의 배치를 나타내는 괄호 표현 문자열
 
int Solve() {
    int count = 0, sum = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') {
            count++;
        }
        else {
            count--;
            if (str[i-1] == '(') {
                sum += count;
            }
            else {
                sum++;
            }
        }
    }
    return sum;
}
 
void InputData(){
    cin >> str;
}
 
int main() {
    int ans;
    InputData();
    ans = Solve();
    cout << ans << endl;
    return 0;
}