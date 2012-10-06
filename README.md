# I-Ching birth/core/end hexagram calculation library

This is a static c/c++ library for calculation birth/core/end hexagram numbers.

[![Build Status](https://secure.travis-ci.org/sitnin/iching.png)](http://travis-ci.org/sitnin/iching)

## Node.JS

This library tested in node.js 0.8.9 and 0.8.11.

Maybe it works with the 0.6. If it so, please, let me know.

You can install the library via npm:

`npm install iching`

### Known problems

Ubuntu 12.04.1 LTS node.js package seems not to have a node-gyp, so it must be installed prior to the library

`sudo npm install -g node-gyp`

## References

Read this [Livejournal post](http://fima-psuchopadt.livejournal.com/1294476.html) (in russian) for the explanation.

## Examples

View `tests/test.c` or `tests/test.cc` for the usage example.

### Node.JS

Sample `test.js`:

    var iching=require('iching');
    console.log(iching.getHexagrams(1980,11,24,1));

Should print out:

    { birth: 23, core: 2, end: 2, mline: 6 }
