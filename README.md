Shows [`_get_osfhandle`](https://msdn.microsoft.com/en-us/library/ks2530z6.aspx)
failing on Windows due to MSVCR being statically linked into Node.

To run, clone this repo then:

```shell
npm install
node test.js
```

You'll see it throw a `EBADF` exception because `_get_osfhandle` can't find
the file descriptor opened in Javascript. This is because the file descriptor
to handle map in the add-on is separate to the one statically linked into the
Node executable.
