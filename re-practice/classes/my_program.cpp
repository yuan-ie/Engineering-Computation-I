#include "lib.h"

class Person {
    public:
        int age;
        string name;
};

int main(int argc, char ** argv){
    int people;
    cout << "How many people do you want to log in?\n";
    while(true){
        if(cin >> people){
            break;
        }
        else{
            cout << "Not a valid number.\n";
            return 1;
        }
    }

    int p;
    string name;
    int age;

    Person persons[people];

    for(p=0; p<people; p++){
        cout << "Enter a name: ";
            cin >> persons[p].name;
        cout << "Enter age: ";
            cin >> persons[p].age;
    }

    cout << "Log-ins:\n";

    for(p=0; p<people; p++){
        cout << "\tName: \t" << persons[p].name;
        cout << "\tAge: \t" << persons[p].age;
        cout << "\n";
    }

    return 0;
}