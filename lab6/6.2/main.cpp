#include <iostream>
#include <algorithm>

const int SIZE = 1000;

union Time {
    struct {
        unsigned short seconds : 6;
        unsigned short minutes : 6;
        unsigned short hours : 4;
    } fields;
};
Time generateRandomTime() {
    Time t;
    t.fields.hours = rand() % 12;
    t.fields.minutes = rand() % 60;
    t.fields.seconds = rand() % 60;
    return t;
}

void printTime(Time t) {
    std::cout << "Hours: " << t.fields.hours << "\tMinutes: " << t.fields.minutes << "\tSeconds: " << t.fields.seconds << '\n';
}

bool cmp(Time &a, Time &b) {
    if (a.fields.hours != b.fields.hours) {
        return a.fields.hours < b.fields.hours;
    } else if (a.fields.minutes != b.fields.minutes) {
        return a.fields.minutes < b.fields.minutes;
    } else {
        return a.fields.seconds < b.fields.seconds;
    }
}

void findDuplicates(Time* times) {
    std::cout << "\nEqual elements:\n\n";
    bool hasDuplicates = false;

    for (int i = 1; i < SIZE; ++i) {
        if (times[i].fields.hours == times[i + 1].fields.hours &&
        times[i].fields.minutes == times[i + 1].fields.minutes &&
        times[i].fields.seconds == times[i + 1].fields.seconds) {
            printTime(*(times + i));
            hasDuplicates = true;
        }
    }
    if (!hasDuplicates) {
        std::cout << "No equal elements found.\n";
    }
}

int main() {
    srand(time(0));
    Time array[SIZE];

    for (int i = 0; i < SIZE; i++) {
        array[i] = generateRandomTime();
    }
    std::cout << "Unsorted array:\n\n";
    for (size_t i = 0; i < SIZE; i++) {
        printTime(array[i]);
    }
    std::sort(array, array + SIZE, cmp);
    std::cout << "\nSorted array:\n\n";
    for (size_t i = 0; i < SIZE; i++) {
        printTime(array[i]);
    }
    
    findDuplicates(array);

    return 0;
}