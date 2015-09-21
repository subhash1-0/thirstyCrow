// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/Tutorial2.java

#pragma once

#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <rice/tutorial/remotesocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::tutorial::remotesocket::Tutorial2_Tutorial2_1_receiveResult_1_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    Tutorial2_Tutorial2_1_receiveResult_1_1(Tutorial2_Tutorial2_1 *Tutorial2_Tutorial2_1_this, ::java::nio::channels::SocketChannel* socket);
    static ::java::lang::Class *class_();
    Tutorial2_Tutorial2_1 *Tutorial2_Tutorial2_1_this;
    ::java::nio::channels::SocketChannel* socket;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Tutorial2;
    friend class Tutorial2_Tutorial2_1;
};
