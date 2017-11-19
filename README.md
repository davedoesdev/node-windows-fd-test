# node-windows-fd-test&nbsp;&nbsp;&nbsp;[![Build status](https://ci.appveyor.com/api/projects/status/y4a096ppu5xvm23q?svg=true)](https://ci.appveyor.com/project/davedoesdev/node-windows-fd-test)

Shows [`uv_osfhandle`](https://github.com/libuv/libuv/pull/1323) works on
Windows.

To run, clone this repo then:

```shell
npm install
node test.js
```
You should see nothing if it works.

Tested using Node 6.12.0 and 8.9.1 on Windows 10 and Windows Server 2012 R2.
