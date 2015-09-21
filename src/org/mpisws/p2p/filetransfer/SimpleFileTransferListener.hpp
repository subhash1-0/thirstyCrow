// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/SimpleFileTransferListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferListener.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::SimpleFileTransferListener
    : public virtual ::java::lang::Object
    , public virtual FileTransferListener
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::String* prefix {  };
protected:
    void ctor(::java::lang::String* prefix);

public:
    void fileTransferred(FileReceipt* receipt, int64_t bytesTransferred, int64_t total, bool incoming) override;
    void msgTransferred(BBReceipt* receipt, int32_t bytesTransferred, int32_t total, bool incoming) override;
    void transferCancelled(Receipt* receipt, bool incoming) override;
    void transferFailed(Receipt* receipt, bool incoming) override;

    // Generated
    SimpleFileTransferListener(::java::lang::String* prefix);
protected:
    SimpleFileTransferListener(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
