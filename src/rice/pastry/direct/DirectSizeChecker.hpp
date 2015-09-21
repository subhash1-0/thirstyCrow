// Generated from /pastry-2.1/src/rice/pastry/direct/DirectSizeChecker.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/rawserialization/SizeChecker.hpp>

struct default_init_tag;

class rice::pastry::direct::DirectSizeChecker
    : public ::rice::p2p::util::rawserialization::SizeChecker
{

public:
    typedef ::rice::p2p::util::rawserialization::SizeChecker super;

public: /* package */
    int32_t directNodeHandleSize {  };
protected:
    void ctor();
    void ctor(int32_t directNodeHandleSize);

public:
    void writeSpecial(::java::lang::Object* o) /* throws(IOException) */ override;

    // Generated
    DirectSizeChecker();
    DirectSizeChecker(int32_t directNodeHandleSize);
protected:
    DirectSizeChecker(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
