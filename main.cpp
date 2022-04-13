#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout; using std::endl;
struct data_t
{
    int id_;
    char name_[50];
};

const int rate = 10;

void initialize(data_t* array, const data_t* input);
void sort(data_t* array);
void print(const data_t* array);

int main(int argc, char const* argv[])
{
    data_t array[rate];
    data_t input[] = {
        {1, "Alpha"},
        {2, "Bravo"},
        {3, "Charlie"},
        {4, "Delta"},
        {5, "Echo"},
        {6, "Foxtrot"},
        {7, "Golf"},
        {8, "Hotel"},
        {9, "India"},
        {10, "Juliett"},
    };

    initialize(array, input);

    assert(array[1].id_ == 2);
    assert(!strcmp(array[1].name_, "Bravo"));

    assert(array[7].id_ == 8);
    assert(!strcmp(array[7].name_, "Hotel"));

    print(array);

    sort(array);

    assert(array[1].id_ == 9);
    assert(!strcmp(array[1].name_, "India"));

    assert(array[7].id_ == 3);
    assert(!strcmp(array[7].name_, "Charlie"));

    print(array);
}

void print(const data_t* array){
    for (int i = 0; i < rate; ++i)
{
    cout << array[i].id_ << "\t" << array[i].name_ << endl;
}
}

void initialize(data_t* array, const data_t* input)
{
    for (int i = 0; i < rate; ++i)
        array[i] = input[i];
}

void sort(data_t* array)
{
    for (int i = 0; i < rate - 1; ++i)
    {
        for (int j = 0; j < rate - i - 1; ++j)
        {
            if (strcmp(array[j].name_, array[j + 1].name_) < 0)
            {
                data_t temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

}