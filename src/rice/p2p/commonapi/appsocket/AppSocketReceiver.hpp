// Generated from /pastry-2.1/src/rice/p2p/commonapi/appsocket/AppSocketReceiver.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::appsocket::AppSocketReceiver
    : public virtual ::java::lang::Object
{
    virtual void receiveSocket(AppSocket* socket) /* throws(IOException) */ = 0;
    virtual void receiveSelectResult(AppSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ = 0;
    virtual void receiveException(AppSocket* socket, ::java::lang::Exception* e) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
