#include <iostream>
#include <unistd.h>
#include <stdint.h>
using namespace std;

size_t highestOneBitPosition(uint32_t a) {
    size_t bits=0;
    while (a!=0) {
        ++bits;
        a /= 10;
    };
    return bits;
}

bool addition_is_safe(uint32_t a, uint32_t b) {
    size_t a_bits=highestOneBitPosition(a), b_bits=highestOneBitPosition(b);
    return (a_bits<32 and b_bits<32);
}


int main() {
   uint32_t a = 0, b = 1;
   cout << a << " " << flush;
   usleep(100000);
   cout << b << " " << flush;
   usleep(100000);
   uint32_t c = 1;
   int counter = 2;
   while (addition_is_safe(a,b) and a + b < 2147483640) {
    cout << c << " " << flush;
    usleep(100000);
    ++counter;
    if (counter%7 == 0) cout << endl;
    a = b;
    b = c;
    c = a + b;
   }
   cout << endl << "Highest Fibonacci number you can write with 32 bits: " << b << endl;
}