#include <iostream>

using namespace std;

int main() {
    int a;
    bool c = false;
    cout << "Please input an integer.\n";
    cin >> a;
    for(int i=2; i<a-1; i++) {
        if (a % i == 0) {
            c = true;
            break;
        }
    }
    if (c==true) {
        cout << "The number is not prime.\n";
    } else
        cout << "The number is  prime.\n";

    return 0;
    }


