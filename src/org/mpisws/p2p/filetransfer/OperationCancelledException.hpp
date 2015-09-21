// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/OperationCancelledException.java

#pragma once

#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::OperationCancelledException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

public: /* package */
    Receipt* receipt {  };
protected:
    void ctor(Receipt* receipt);

public:
    virtual Receipt* getReceipt();

    // Generated
    OperationCancelledException(Receipt* receipt);
protected:
    OperationCancelledException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
