#include "lib.h"

// (method) read: read a file and input the data into the matrix
bool MyMatrix::read(char *filename){
    FILE *fp = fopen(filename,"r");
    if (fp==NULL){
        cout << "Cannot open file: %s" << filename << "\n";
        exit(100);
    }

    char row[100];
    float value;

    // read each line
    while (fgets(row, sizeof(row), fp)){
        char *ptr = row;

        // initialize new row to store numbers
        vector<float> current_row;

        // read each floating point and store into vector
        // this points to the first character of the float (ex. '1' of 13.2)
        // and passes the whole float to 'value'
        while(sscanf(ptr, "%f", &value) == 1){

            // push the number into the current row vector (ex. 13.2)
            current_row.push_back(value);

            // skip over the next few digits (ex. '2', '.', '2')
            while (*ptr != ' ' && *ptr != '\n' && *ptr !='\0'){
                ptr++;
            }

            // skip over non digits
            if (*ptr == ' ' || *ptr == '\n'){   
                ptr++;
            }
        }

        data.push_back(current_row);
    }

    return true;
}

void MyMatrix::display(){
    for (size_t r=0; r<data.size(); r++){
        for (size_t c=0; c<data[r].size(); c++){
            printf("%.2f ", data[r][c]);
        }
            printf("\n");
    }
}

bool MyMatrix::isRectangle(){
    for (size_t r=0; r<data.size(); r++){
        if (data[r].size() != data[0].size()){
            printf("Not a rectangle.\n");
            return false;
        }
    }
    printf("Is a rectangle.\n");
    return true;
}

MyMatrix MyMatrix::operator+(MyMatrix& other){
    if (this->isRectangle() == false && other.isRectangle()){

    }
}

