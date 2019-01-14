#include<iostream>
#include "lib/Num.h"
#include "lib/Exp.h"

using namespace std;

int main()
{
    Num n(3);
    Exp e(5);
    cout << "square of 3 is: " << n.getSqaureOfNumber() << endl;
    cout << "e^5 is: " << e.getExpo() << endl;
    return 0;
}

