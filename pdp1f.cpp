/* USER: koliofotis35pdp
LANG: C++
TASK: coupon */
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main() {

//declarations

    int X;
    int Xo;
    int N;
    int B;
    int C;
    int totalma;
    int z;
    double A;
    int ma;

    vector<int> familynumber;
    vector<double> moneyamounts;

//file input

    ifstream in("coupon.in");
    in >> N >> A >> B;
    for(int a = 0; a < N; a++) {
        in >> C;
        familynumber.push_back(C);
    }
    in.close();
//calculations
    
   
    for(int i = 0; i < N; i++){
        z = z + familynumber[i] * pow(A, i);
    }

    X = B/z;
    moneyamounts.push_back(X);
    for (int i = 1; i < N; i++) {
        Xo = moneyamounts[i-1] * A;
        if(Xo < 10) {
            Xo = 0;
        }
        moneyamounts.push_back(Xo);
    }

    for(int i = 0; i < N; i++) {
        totalma = totalma + moneyamounts[i] * familynumber[i];
    }

    while (totalma < B) {
        
        X++;
        moneyamounts.clear();
        moneyamounts.push_back(X);
        for (int i = 1; i < N; i++) {
        Xo = moneyamounts[i-1] * A;
        if(Xo < 10) {
            Xo = 0;
        }
        moneyamounts.push_back(Xo);
        }
        totalma = 0;
        for(int i = 0; i < N; i++) {
        totalma = totalma + moneyamounts[i] * familynumber[i];
        }
    }
    X--;
    moneyamounts.clear();
    moneyamounts.push_back(X);
    for (int i = 1; i < N; i++) {
        Xo = moneyamounts[i-1] * A;
        if(Xo < 10) {
            Xo = 0;
        }
        moneyamounts.push_back(Xo);
    }
    
    totalma = 0;
    for(int i = 0; i < N; i++) {
        totalma = totalma + moneyamounts[i] * familynumber[i];
    }  

//output

  ofstream out("coupon.out");
  out << totalma << '\n';
  for(int a = 0; a < N; a++) {
    out << moneyamounts[a] << '\n';
  }
  out.close();
  
  return 0;
} 