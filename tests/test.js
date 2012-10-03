//
//  test.js
//  libiching JavaScript binding test
//
//  Created by Gregory Sitnin on 10/03/12.
//  Copyright (c) 2012 Gregory Sitnin. All rights reserved.
//

var util = require("util");
var iching = require('../build/Release/iching');

function test(year, month, day, hour) {
    var h = iching.getHexagrams(year, month, day, hour);
    console.log(util.format("res: %d - %d - %d - %d", h.birth, h.core, h.end, h.mline));
}

console.log("I-Ching Node.JS Library binding test");

test(1973, 12, 3, 0);
console.log("ref: 51 - 39 - 54 - 2\n");

test(1980, 11, 24, 1);
console.log("ref: 23 - 2 - 2 - 6\n");
