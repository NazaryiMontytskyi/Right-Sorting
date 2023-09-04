#include <iostream>
#include "sorting.h"
#include "binary_file.h"

int main() {
    srand(time(nullptr));
    string filename = "file.bin";
    initialize_file(filename);
    show_file(filename);

    fileSorter test(filename);

    test.rightMerge();
    cout << "RESULT:\n";
    show_file(filename);

    return 0;
}
