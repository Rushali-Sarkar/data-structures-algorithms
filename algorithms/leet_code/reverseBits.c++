#include<iostream>

using namespace std;

unsigned reverseBits(unsigned number) {

    unsigned shift_by = 32;
    unsigned reversed = 0;

    while (number != 0) {
        unsigned rightmost_bit = (number & 1) << shift_by;
        reversed += rightmost_bit;
        number = number >> 1;
        shift_by -= 1;
    }
    return reversed;
}

int main(int argc, char* argv[]) {

    unsigned number = 4;
    cout << reverseBits(number) << endl;
    return 0;

}