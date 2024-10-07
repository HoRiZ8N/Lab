#include <iostream>
#include <fstream>

struct Student
{ 
    char name[50];
    char surname[50];
    char secondSurname[50];
    int age;
    short year;
    char gender[10];
    float mark;
};

double averageAge(int year, int n, Student* array) {
    double avAge = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (year == array[i].year)
        {
            avAge += array[i].age;
            count++;
        }   
    }
    return avAge / count;
}

int main()
{
    std::ifstream fin;
    fin.open("input.txt");
    int n;
    fin >> n; //get array size

    Student array[n];

    for (int i = 0; i < n; i++) //fill array
    {
        fin >> array[i].name >> array[i].surname >> array[i].secondSurname >> array[i].age >>
        array[i].year >> array[i].gender >> array[i].mark; 
    }

    int y;
    fin >> y; //get students year to calc average age

    std::cout << averageAge(y, n, array);

    fin.close();

    return 0;
}