#include <iostream>
#include <stdlib.h>
#include <vector>

#include <memory>
#include <tr1/memory>

using namespace std;
using namespace std::tr1;


class Person {

public:

    Person() {
        int a[1000] = { 0 };
        cout << "Person constructed\n";
    }
    virtual ~Person() {
        cout << "Person destructed\n";
    }
};


int main() {

    vector<Person*> persons;

    Person *p1 = new Person();
    Person *p2 = new Person();
    Person *p3 = new Person();
    Person *p4 = new Person();

    persons.push_back(p1);
    persons.push_back(p2);
    persons.push_back(p3);
    persons.push_back(p4);


    vector<Person*>::iterator it;
    for ( it = persons.begin(); it != persons.end();  ++it ) {
        delete *it;
    }

    system("pause");

    return 0;
}

