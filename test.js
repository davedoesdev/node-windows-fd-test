var fs = require('fs'),
    binding = require('./build/Release/test');
binding.test(fs.openSync('test.js', 'r'));
