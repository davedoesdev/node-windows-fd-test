{
    "targets": [
        {
            "target_name": "test",
            "include_dirs" : [ "<!(node -e \"require('nan')\")" ],
            "sources": [ "test.cc" ]
        }
    ]
}
