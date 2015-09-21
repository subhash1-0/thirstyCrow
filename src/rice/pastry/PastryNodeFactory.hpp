// Generated from /pastry-2.1/src/rice/pastry/PastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::PastryNodeFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int8_t rtMax {  };
    int8_t lSetSize {  };
    int8_t rtBase {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::environment::Environment* env);

public:
    virtual PastryNode* newNode(NodeHandle* bootstrap) = 0;
    virtual PastryNode* newNode() /* throws(IOException) */ = 0;
    virtual PastryNode* newNode(NodeHandle* bootstrap, Id* nodeId) = 0;
    virtual PastryNode* newNode(Id* nodeId) /* throws(IOException) */ = 0;
    virtual ::rice::environment::Environment* getEnvironment();

    // Generated
    PastryNodeFactory(::rice::environment::Environment* env);
protected:
    PastryNodeFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
