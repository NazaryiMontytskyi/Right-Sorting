//
// Created by nazar on 01.09.2023.
//

#ifndef EXTERNALSORTINGRIGHTMERGE_SORTING_H
#define EXTERNALSORTINGRIGHTMERGE_SORTING_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <filesystem>
using namespace std;

const string B_FILE = "B.bin";
const string C_FILE = "C.bin";

class fileSorter{
private:
    string nameOfFile;
    int A_SIZE;

    ifstream A_in;
    ifstream B_in;
    ifstream C_in;

    ofstream A_out;
    ofstream B_out;
    ofstream C_out;

    fstream A;
    fstream B;
    fstream C;

    int powerOfGroupSize ;
    int groupHalfSize;

    int pos_B, pos_C;
    int size_B, size_C;
    int var_B, var_C;
public:
    fileSorter(string nameOfFile);
    ~fileSorter();
    void divideFile();
    void mergeFiles();
    void rightMerge();
private:
    void mergeGroup();
};






#endif //EXTERNALSORTINGRIGHTMERGE_SORTING_H
