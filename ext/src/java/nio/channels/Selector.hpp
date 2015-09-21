// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/nio/channels/spi/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Closeable.hpp>

struct default_init_tag;

class java::nio::channels::Selector
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Closeable
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();
    /*void close(); (already declared) */

public:
    virtual bool isOpen() = 0;
    virtual ::java::util::Set* keys() = 0;
    static Selector* open();
    virtual ::java::nio::channels::spi::SelectorProvider* provider() = 0;
    virtual int32_t select() = 0;
    virtual int32_t select(int64_t arg0) = 0;
    virtual int32_t selectNow() = 0;
    virtual ::java::util::Set* selectedKeys() = 0;
    virtual Selector* wakeup() = 0;

    // Generated

public: /* protected */
    Selector();
protected:
    Selector(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
