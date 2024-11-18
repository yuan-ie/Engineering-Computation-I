#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class MyMatrix{
    protected:
        vector<vector<float>> data;

    public:

        bool read(char *filename);
        void display();
        bool isRectangle();

        MyMatrix operator+(MyMatrix& other);

};