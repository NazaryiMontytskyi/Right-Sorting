//
// Created by nazar on 01.09.2023.
//

#include "sorting.h"

fileSorter::fileSorter(string nameOfFile):nameOfFile(nameOfFile), powerOfGroupSize(0){
    groupHalfSize = (int)pow(2, powerOfGroupSize) ;
    A_SIZE = std::filesystem::file_size(nameOfFile);
}

void fileSorter::divideFile() {


    A_in.open(nameOfFile, ios::binary);
    B_out.open(B_FILE, ios::binary);
    C_out.open(C_FILE, ios::binary);

    int var;
    for (int i = 0; A_in.read((char *) &var, sizeof(int)); i++){
        if((int)(i / (int)pow(2, powerOfGroupSize )) % 2) {
            B_out.write((char*)&var, sizeof(int));

            continue;
        }
        C_out.write((char*)&var, sizeof(int));


    }

    A_in.close();
    B_out.close();
    C_out.close();
}

fileSorter::~fileSorter() {

}

void fileSorter::mergeFiles(){
    A_out.open(nameOfFile, ios::binary);
    B_in.open(B_FILE, ios::binary);
    C_in.open(C_FILE, ios::binary);

    groupHalfSize = (int)pow(2, powerOfGroupSize) ;

    size_B = std::filesystem::file_size(B_FILE)/sizeof(int);
    size_C = std::filesystem::file_size(C_FILE)/sizeof(int);

    pos_B = 0;
    pos_C = 0;

    B_in.read((char*)&var_B, sizeof(int));
    C_in.read((char*)&var_C, sizeof(int));

    while(pos_B < size_B and pos_C < size_C)
    {
        mergeGroup();
    }

    while(pos_B < size_B)
    {
        A_out.write((char*)&var_B, sizeof(int));
        B_in.read((char*)&var_B, sizeof(int));
        pos_B++;
    }

    while(pos_C < size_C)
    {
        A_out.write((char*)&var_C, sizeof(int));
        C_in.read((char*)&var_C, sizeof(int));
        pos_C++;
    }

    A_out.close();
    B_in.close();
    C_in.close();

    powerOfGroupSize++;
}

void fileSorter::mergeGroup() {

    int counter_B =0, counter_C = 0;
    while(( groupHalfSize > counter_B and groupHalfSize > counter_C) and (pos_B < size_B and pos_C < size_C))
    {
        if (var_B > var_C)
        {
            A_out.write((char*)&var_C,sizeof(int));
            C_in.read((char*)&var_C, sizeof(int));
            counter_C++;
            pos_C++;
            continue;
        }

        A_out.write((char*)&var_B, sizeof(int));
        B_in.read((char*)&var_B, sizeof(int));
        counter_B++;
        pos_B++;
    }
    while (groupHalfSize > counter_B and pos_B < size_B)
    {
        A_out.write((char*)&var_B, sizeof(int));
        //var_B = B.read();
        B_in.read((char*)&var_B, sizeof(int));
        counter_B++;
        pos_B++;
    }
    while (groupHalfSize > counter_C and pos_C < size_C)
    {
        A_out.write((char*)&var_C, sizeof(int));
        //var_C = C.read();
        C_in.read((char*)&var_C, sizeof(int));
        counter_C++;
        pos_C++;
    }
}

void fileSorter::rightMerge() {
    while(groupHalfSize < ( A_SIZE/2))
    {
        this->divideFile();
        this->mergeFiles();
    }
}
