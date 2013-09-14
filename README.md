# I-Ching birth/core/end hexagram calculation library

This is a static c/c++ library for calculation birth/core/end hexagram numbers.

[![Build Status](https://secure.travis-ci.org/sitnin/iching.png)](http://travis-ci.org/sitnin/iching)

![Codeship](https://www.codeship.io/projects/3b3bab30-ff5f-0130-0225-4a774a26fa08/status)

## Node.JS

This library works with Node.js 0.8.x and 0.10.x.

Maybe it works with the 0.6. If it so, please, let me know.

You can install the library via npm:

`npm install iching`

### Prerequisites

You should have `node-gyp` and `c++ compiler` (gcc or clang) installed.

## References

Read this [Livejournal post](http://fima-psuchopadt.livejournal.com/1294476.html) (in russian) for the explanation (about I-Ching).

## Examples

View `tests/test.c` or `tests/test.cc` for the usage example.

### Node.JS

Sample `test.js`:

    var iching=require('iching');
    console.log(iching.getHexagrams(1980,11,24,1));

Should print out:

    { birth: 23, core: 2, end: 2, mline: 6 }
