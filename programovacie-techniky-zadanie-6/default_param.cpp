// Tema: Default (implicitne) parametre funkcie
// Autor: Pavol Marak
// Datum: 2. 11. 2021

#include <iostream>

using namespace std;

// funkcia s 2 standardnymi parametrami
void fn0(int a, char b) {
    cout << "fn0: " << a << " " << b << endl;
}

// funkcia s:
//   * 1 standardnym parametrom
//   * 1 default parametrom
void fn1(int a, char b = 'x') {
    cout << "fn1: " << a << " " << b << endl;
}

// funkcia, ktora ma len default parametre
void fn2(int a = 1, char b = 'x') {
    cout << "fn2: " << a << " " << b << endl;
}

int main() {
    fn0(0,'e');
    // fn0(); // nebude kompilovatelne
    // fn0(9); // nebude kompilovatelne

    fn1(1); // parameter 'b' ma default hodnotu 'x'
    fn1(1,'r');
    // fn1(); // nepojde skompilovat

    fn2(2); // parameter 'b' ma default hodnotu 'x'
    fn2(3, 'G'); // default parametre sa nepouziju
    fn2(); // obidva parametre maju default hodnoty
    return 0;
}
