#include <iostream>

using namespace std;
#include  "dataReader.h"
int main()
{
    dataReader * reader = new dataReader();
    reader->readGraph("input/example_input_file.dat");
    return 0;
}
