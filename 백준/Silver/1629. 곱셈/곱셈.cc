#include <iostream>
using namespace std;

int A, B, C;

long long multiply(long long b) {
    if (b == 0) return 1;
    if (b == 1) return A % C;

    long long temp = multiply(b / 2) % C;
    if (b % 2) return temp * temp % C * A % C;
    else return temp * temp % C;
}


int main() {

    cin >> A >> B >> C;
    
    cout << multiply(B) % C;
} 