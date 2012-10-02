//
//  iching.h
//  libiching
//
//  Created by Gregory Sitnin on 9/25/12.
//  Copyright (c) 2012 Gregory Sitnin. All rights reserved.
//

#ifdef __cplusplus
    extern "C" {
#endif

extern const unsigned int TRIGRAMS[8];
extern const unsigned int VANVEN_ORDER[64];

typedef struct {
    unsigned int birth;
    unsigned int core;
    unsigned int end;
    int mline;
} hex_info;

int make_hexagrams(int year, int month, int day, int hour, hex_info *info);

#ifdef __cplusplus
    }
#endif
