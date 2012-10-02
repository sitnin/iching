//
//  iching.c
//  libiching
//
//  Created by Gregory Sitnin on 9/25/12.
//  Copyright (c) 2012 Gregory Sitnin. All rights reserved.
//

#include <stdio.h>
#include "iching.h"

const unsigned int TRIGRAMS[8] = {7, 3, 5, 1, 6, 2, 4, 0};

const unsigned int VANVEN_ORDER[64] = {
    0x3F, 0x00, 0x11, 0x22, 0x17, 0x3A, 0x02, 0x10,
    0x37, 0x3B, 0x07, 0x38, 0x3D, 0x2F, 0x04, 0x08,
    0x19, 0x26, 0x03, 0x30, 0x29, 0x25, 0x20, 0x01,
    0x39, 0x27, 0x21, 0x1E, 0x12, 0x2D, 0x1C, 0x0E,
    0x3C, 0x0F, 0x28, 0x05, 0x35, 0x2B, 0x14, 0x0A,
    0x23, 0x31, 0x1F, 0x3E, 0x18, 0x06, 0x1A, 0x16,
    0x1D, 0x2E, 0x09, 0x24, 0x34, 0x0B, 0x0D, 0x2C,
    0x36, 0x1B, 0x32, 0x13, 0x33, 0x0C, 0x15, 0x2A
};

int day_num(int year, int month, int day) {
    return ((year % 12) == 0 ? 12 : year % 12) + month + day;
}

int outer_trigram_no(int year, int month, int day) {
    int result = day_num(year, month, day) % 8;
    return result != 0 ? result : 8;
}

int inner_trigram_no(int year, int month, int day, int hour) {
    int result = (day_num(year, month, day) + hour) % 8;
    return result != 0 ? result : 8;
}

int trigram(int no) {
    return TRIGRAMS[no-1];
}

int hexagram_no(unsigned int bitmask) {
    int i;
    for (i = 0; i < 64; i++) {
        if (bitmask == VANVEN_ORDER[i])
            return i+1;
    }
    return -1;
}

int mutable_line(int year, int month, int day, int hour) {
    int result = (day_num(year, month, day) + hour) % 6;
    return result != 0 ? result : 6;
}

unsigned int birth_hexagram(unsigned int outer, unsigned int inner) {
    int result = (outer << 3) + inner;
    return result;
}

unsigned int core_hexagram(unsigned int bhex) {
    int sz = sizeof(bhex) * 8;
    unsigned int lo = bhex;
    unsigned int hi = bhex;
    lo = ((lo >> 1) << (sz - 3)) >> (sz - 3);
    hi = ((hi >> 2) << (sz - 3)) >> (sz - 6);
    return hi + lo;
}

unsigned int end_hexagram(unsigned int bhex, int mline) {
    return bhex ^ 1 << (mline - 1);
}

int make_hexagrams(int year, int month, int day, int hour, hex_info *info) {
    int outer_no = outer_trigram_no(year, month, day);
    int outer = trigram(outer_no);
    int inner_no = inner_trigram_no(year, month, day, hour);
    int inner = trigram(inner_no);
    int bhex_mask = birth_hexagram(outer, inner);
    int bhex_no = hexagram_no(bhex_mask);
    if (bhex_no > 0) {
        int chex_mask = core_hexagram(bhex_mask);
        int chex_no = hexagram_no(chex_mask);
        if (chex_no > 0) {
            int mline = mutable_line(year, month, day, hour);
            int ehex_mask = end_hexagram(bhex_mask, mline);
            int ehex_no = hexagram_no(ehex_mask);
            if (ehex_no > 0) {
                info->birth = bhex_no;
                info->core = chex_no;
                info->end = ehex_no;
                info->mline = mline;
                return 0;
            } else {
                return -3;
            }
        } else {
            return -2;
        }
    } else {
        return -1;
    }
}
