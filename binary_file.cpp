//
// Created by nazar on 01.09.2023.
//

#include "binary_file.h"

void generate_file(string filename) {
    ofstream out_file;

    const int MAX_SIZE = 20;

    const int MIN = -25;
    const int MAX = 25;

    int size = rand()%MAX_SIZE;
    int var;

    out_file.open(filename,ios::binary);

    for(int i = 0; i < size; i++)
    {
        var = MIN  + rand()%(MAX - MIN + 1);
        out_file.write((char*)&var, sizeof(int));
    }

    out_file.close();

}

void show_file(string filename) {


    ifstream infile;
    int var;

    infile.open(filename, ios::binary);

    while(infile.read((char*)&var, sizeof(int)))
        cout << var << " ";
    cout << endl;

    infile.close();
}

void initialize_file(string filename)
{
    ofstream out_file;
    vector<int> initialize = {42, 17, 8, 56, 23, 39, 71, 5, 32, 12, 88, 61, 27, 19, 50, 3, 67, 10, 55, 4, 29, 91, 15, 72, 6, 48, 20, 63, 9};

    out_file.open(filename, ios::binary);
    for(int i = 0; i < initialize.size(); i++)
    {
        out_file.write((char*)&initialize[i], sizeof(int));
    }
    out_file.close();
}