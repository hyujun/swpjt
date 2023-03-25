#include <iostream>
#include <algorithm>
using namespace std;

int N;//정수

void InputData(){ 
	cin >> N; 
}

struct sfrac{
    int den;
    int num;
};

std::ostream &operator<<(std::ostream &os, const sfrac &f)
{
    return (os << f.den << "/" << f.num);
}

int sum(int num)
{
    if(num <= 1) return 1;
    return num+sum(num-1);
}

bool cmp(sfrac &a, sfrac &b)
{
    int tmp1, tmp2;
    tmp1 = a.den * b.num;
    tmp2 = b.den * a.num;

    return tmp1 < tmp2;
}

void abbr(sfrac &a)
{
    int min = a.den;
    for(int i=min; i>1; i--)
    {
       if(a.num%i == 0)
       {
        if(a.den%i == 0)
        {
            a.num /= i;
            a.den /= i;
        }
       }
    }
}

void Solve()
{
    int size_frac = sum(N-1)+2;
    sfrac frac[size_frac];
    frac[0].den=0;
    frac[0].num=1;

    frac[size_frac-1].den=1;
    frac[size_frac-1].num=1;

    int count=1;

    for(int j=1; j <N; j++)
    {
        for(int k=1; k<=j; k++)
        {
 
            frac[count].den = k;
            frac[count].num = j+1;
            abbr(frac[count]);
            count++;
        }
    }

    for(int i=0; i<size_frac; i++)
    {
        cout << frac[i] << "\n";
    }

    sort(frac, frac+size_frac, cmp);

    cout << "after sort: \n";

    for(int i=0; i<size_frac; i++)
    {
        if(i > 1)
        {
            if(frac[i].num == frac[i-1].num && frac[i].den == frac[i-1].den)
            {
                
            }
            else{
                cout << frac[i] << "\n";
            }

        }
        else
        {
            cout << frac[i] << "\n";
        }

    }


}

int main() {
	InputData();//입력
	
    if(N==1)
    {
        cout << "0/1" << endl;
        cout << "1/1" << endl;
        return 0;
    }
	//여기서부터 작성
    Solve();
	
	return 0;
}