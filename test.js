var fs = require('fs'),
    binding = require('./build/Release/test');
console.log(binding.test(fs.openSync('test.js', 'r')));
