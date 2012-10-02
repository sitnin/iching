//
//  test.cc
//  libiching
//
//  Created by Gregory Sitnin on 9/25/12.
//  Copyright (c) 2012 Gregory Sitnin. All rights reserved.
//

#include <iostream>
#include "iching.h"

using namespace std;

class IChingTest {
public:
    int run(int year, int month, int day, int hour) {
        hex_info info;
        int result;
        cout << "---  " << year << "-" << month << "-" << day << ", " << hour << endl;
        result = make_hexagrams(year, month, day, hour, &info);
        cout << "res: " << info.birth << " - " << info.core << " - " << info.end << " - " << info.mline << endl;
        return result;
    }
};

int main() {
    cout << "I-Ching C++ Library test\n";

    int overall = 0;
    IChingTest *t = new IChingTest();

    overall += t->run(1973, 12, 3, 0);
    std::cout << "ref: 51 - 39 - 54 - 2" << endl << endl;

    overall += t->run(1980, 11, 24, 1);
    std::cout << "ref: 23 - 2 - 2 - 6" << endl << endl;

    return overall;
}
