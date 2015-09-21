// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/Tutorial2.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <rice/tutorial/remotesocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::tutorial::remotesocket::Tutorial2_Tutorial2_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::java::nio::channels::SocketChannel* socket);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    Tutorial2_Tutorial2_1(Tutorial2 *Tutorial2_this);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    Tutorial2 *Tutorial2_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Tutorial2;
    friend class Tutorial2_Tutorial2_1_receiveResult_1_1;
};
