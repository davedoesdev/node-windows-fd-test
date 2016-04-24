#include <nan.h>

using namespace v8;

static NAN_METHOD(Test)
{
    if (info.Length() < 1 || !info[0]->IsInt32())
    {
        return Nan::ThrowTypeError("Bad argument");
    }

    HANDLE handle = _get_osfhandle(info[0]->ToInt32());

    if (handle == -1)
    {
        return Nan::ThrowError(Nan::ErrnoException(errno));    
    }
}

extern "C"
NAN_MODULE_INIT(init)
{
    target->Set(Nan::New<String>("test").ToLocalChecked(),
                Nan::New<FunctionTemplate>(Test)->GetFunction());
}

NODE_MODULE(test, init)
