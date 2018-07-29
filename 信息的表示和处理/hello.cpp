#include <iostream>
using std::ostream; using std::cin; using std::cout; using std::endl;
using std::hex; using std::dec;
int main()
{   
    short usi = 32768;
    int i = usi;
    cout <<" hex:" << " usi= " << hex << usi << endl;
    cout << dec << usi << endl;
    cout <<" hex:" << "   i= " << hex <<   i << endl;
    cout << dec << i << endl;
    return 0;
}