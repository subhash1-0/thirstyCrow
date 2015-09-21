// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class javax::crypto::Cipher_Transform
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::String* mode {  };
    ::java::lang::String* pad {  };

private:
    static ::java::util::concurrent::ConcurrentMap* patternCache_;

public: /* package */
    ::java::lang::String* suffix {  };
    ::java::lang::String* transform {  };

protected:
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3);
    /*static bool matches(::java::lang::String* arg0, ::java::lang::String* arg1); (private) */

public: /* package */
    virtual void setModePadding(CipherSpi* arg0);
    /*static int32_t supports(::java::security::Provider_Service* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2); (private) */
    virtual int32_t supportsMode(::java::security::Provider_Service* arg0);
    virtual int32_t supportsModePadding(::java::security::Provider_Service* arg0);
    virtual int32_t supportsPadding(::java::security::Provider_Service* arg0);

    // Generated
    Cipher_Transform(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3);
protected:
    Cipher_Transform(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::util::concurrent::ConcurrentMap*& patternCache();
    virtual ::java::lang::Class* getClass0();
};
