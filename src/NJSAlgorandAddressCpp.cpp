// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from idl.djinni

#include "NJSAlgorandAddressCpp.hpp"
#include "NJSObjectWrapper.hpp"
#include "NJSHexUtils.hpp"

using namespace v8;
using namespace node;
using namespace std;

NAN_METHOD(NJSAlgorandAddress::fromPublicKey) {

    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        return Nan::ThrowError("NJSAlgorandAddress::fromPublicKey needs 1 arguments");
    }

    //Check if parameters have correct types
    if(!info[0]->IsString())
    {
        Nan::ThrowError("info[0] should be a hexadecimal string.");
    }
    std::vector<uint8_t> arg_0;
    Nan::Utf8String str_arg_0(info[0]);
    std::string string_arg_0(*str_arg_0, str_arg_0.length());
    if (string_arg_0.rfind("0x", 0) == 0)
    {
        arg_0 = djinni::js::hex::toByteArray(string_arg_0.substr(2));
    }
    else
    {
        arg_0 = std::vector<uint8_t>(string_arg_0.cbegin(), string_arg_0.cend());
    }


    auto result = ledger::core::api::AlgorandAddress::fromPublicKey(arg_0);

    //Wrap result in node object
    auto arg_1 = Nan::New<String>(result).ToLocalChecked();

    //Return result
    info.GetReturnValue().Set(arg_1);
}
NAN_METHOD(NJSAlgorandAddress::toPublicKey) {

    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        return Nan::ThrowError("NJSAlgorandAddress::toPublicKey needs 1 arguments");
    }

    //Check if parameters have correct types
    Nan::Utf8String string_arg_0(info[0]->ToString(Nan::GetCurrentContext()).ToLocalChecked());
    auto arg_0 = std::string(*string_arg_0);

    auto result = ledger::core::api::AlgorandAddress::toPublicKey(arg_0);

    //Wrap result in node object
    auto arg_1 = Nan::New<String>("0x" + djinni::js::hex::toString(result)).ToLocalChecked();


    //Return result
    info.GetReturnValue().Set(arg_1);
}

NAN_METHOD(NJSAlgorandAddress::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSAlgorandAddress function can only be called as constructor (use New)");
    }
    info.GetReturnValue().Set(info.This());
}


Nan::Persistent<ObjectTemplate> NJSAlgorandAddress::AlgorandAddress_prototype;

Local<Object> NJSAlgorandAddress::wrap(const std::shared_ptr<ledger::core::api::AlgorandAddress> &object) {
    Nan::EscapableHandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(AlgorandAddress_prototype);

    Local<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
        djinni::js::ObjectWrapper<ledger::core::api::AlgorandAddress>::Wrap(object, obj);
    }
    else
    {
        Nan::ThrowError("NJSAlgorandAddress::wrap: object template not valid");
    }
    return scope.Escape(obj);
}

NAN_METHOD(NJSAlgorandAddress::isNull) {
    auto cpp_implementation = djinni::js::ObjectWrapper<ledger::core::api::AlgorandAddress>::Unwrap(info.This());
    auto isNull = !cpp_implementation ? true : false;
    return info.GetReturnValue().Set(Nan::New<Boolean>(isNull));
}

void NJSAlgorandAddress::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSAlgorandAddress::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSAlgorandAddress").ToLocalChecked());

    //SetPrototypeMethod all methods
    Nan::SetPrototypeMethod(func_template,"fromPublicKey", fromPublicKey);
    Nan::SetPrototypeMethod(func_template,"toPublicKey", toPublicKey);
    Nan::SetPrototypeMethod(func_template,"isNull", isNull);
    //Set object prototype
    AlgorandAddress_prototype.Reset(objectTemplate);

    //Add template to target
    Nan::Set(target, Nan::New<String>("NJSAlgorandAddress").ToLocalChecked(), Nan::GetFunction(func_template).ToLocalChecked());
}
