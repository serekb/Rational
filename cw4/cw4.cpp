#include <iostream>
using namespace std;
#include "Rational.h"

int main()
{
    Rational u1 = Rational( 1,3 );
    Rational u2 = Rational();
    cout << "Wprowadz drugi ulamek: ";
    cin >> u2;
    cout << "suma ulamkow = " << u1 + u2;
    cout << "jako double = " << (u1+u2).Value() << endl;
    cout << "\nroznica ulamkow = " << u1 - u2;
    cout << "jako double = " << (u1 - u2).Value() << endl;
    cout << "\niloczyn ulamkow = " << u1 * u2;
    cout << "jako double = " << (u1 * u2).Value() << endl;
    cout << "\niloraz ulamkow = " << u1 / u2;
    cout << "jako double = " << (u1 / u2).Value() << endl;
    return 0;
}
