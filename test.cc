#include <nan.h>

using namespace v8;

static NAN_METHOD(Test)
{
    if (info.Length() < 1 || !info[0]->IsInt32())
    {
        return Nan::ThrowTypeError("Bad argument");
    }

    HANDLE handle = (HANDLE) uv_get_osfhandle(info[0]->Int32Value());

    if (handle == (HANDLE) -1)
    {
        return Nan::ThrowError(Nan::ErrnoException(errno));    
    }
}

static void uv__crt_invalid_parameter_handler(const wchar_t* expression,
                                              const wchar_t* function,
					      const wchar_t * file,
					      unsigned int line,
                                              uintptr_t reserved)
{
  /* No-op. */
}

extern "C"
NAN_MODULE_INIT(init)
{
    _set_invalid_parameter_handler(uv__crt_invalid_parameter_handler);

    target->Set(Nan::New<String>("test").ToLocalChecked(),
                Nan::New<FunctionTemplate>(Test)->GetFunction());
}

NODE_MODULE(test, init)
