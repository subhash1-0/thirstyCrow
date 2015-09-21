// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Comparable.hpp>

struct org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapper
    : public virtual ::java::lang::Comparable
{
    virtual int8_t getPriority() = 0;
    virtual void complete() = 0;
    virtual void drop() = 0;
    virtual int32_t getUid() = 0;
    virtual int64_t getSeq() = 0;
    virtual bool receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
