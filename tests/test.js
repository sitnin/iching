//
//  test.js
//  libiching JavaScript binding test
//
//  Created by Gregory Sitnin on 10/03/12.
//  Copyright (c) 2012 Gregory Sitnin. All rights reserved.
//

var util = require("util");
var iching = require('../build/Release/iching');

function test(year, month, day, hour, reference) {
    var h = iching.getHexagrams(year, month, day, hour);
    var s = util.format("%d - %d - %d - %d", h.birth, h.core, h.end, h.mline);
    var testRest = s === reference;
    console.log("\nRES:", s, "\nREF:", reference, testRest ? "OK" : "FAIL");
    return testRest ? 0 : 1;
}

console.log("iChing Node.JS Library binding test");

var errCount = 0;
errCount += test(1973, 12, 3, 0, "51 - 39 - 54 - 2");
errCount += test(1980, 11, 24, 1, "23 - 2 - 2 - 6");

console.log("\nErrors:", errCount);
process.exit(errCount);
