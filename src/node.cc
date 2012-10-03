//
//  node.cc
//  libiching Node.JS binding
//
//  Created by Gregory Sitnin on 10/03/12.
//  Copyright (c) 2012 Gregory Sitnin. All rights reserved.
//

#include <node.h>
#include <v8.h>
#include "iching.h"

using namespace node;
using namespace v8;

Handle<Value> GetHexagrams(const Arguments& args) {
    HandleScope scope;

    if (args.Length() != 4) {
        return ThrowException(Exception::TypeError(String::New("There must be 4 integers (year, month, day and hour)")));
    }

    hex_info info;
    make_hexagrams(
        args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(),
        args[3]->Int32Value(), &info
    );

    Handle<Object> result = Object::New();
    result->Set(String::New("birth"), Integer::New(info.birth));
    result->Set(String::New("core"), Integer::New(info.core));
    result->Set(String::New("end"), Integer::New(info.end));
    result->Set(String::New("mline"), Integer::New(info.mline));

    return scope.Close(result);
}

void init(Handle<Object> target) {
    HandleScope scope;

    target->Set(String::New("version"), String::New("1.0"));
    target->Set(String::NewSymbol("getHexagrams"),
        FunctionTemplate::New(GetHexagrams)->GetFunction()
    );
}

NODE_MODULE(iching, init)
