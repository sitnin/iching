//
//  test.c
//  libiching
//
//  Created by Gregory Sitnin on 9/25/12.
//  Copyright (c) 2012 Gregory Sitnin. All rights reserved.
//

#include <stdio.h>
#include "iching.h"

void test(int year, int month, int day, int hour) {
    hex_info info;
    printf("---  %d-%d-%d, %d\n", year, month, day, hour);
    make_hexagrams(year, month, day, hour, &info);
    printf("res: %d - %d - %d - %d\n", info.birth, info.core, info.end, info.mline);
}

int main(int argc, char* argv[]) {
    printf("I-Ching C Library test\n");

    test(1973, 12, 3, 0);
    printf("ref: 51 - 39 - 54 - 2\n\n");

    test(1980, 11, 24, 1);
    printf("ref: 23 - 2 - 2 - 6\n\n");

    return 0;
}
