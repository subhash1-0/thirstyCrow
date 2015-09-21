// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <rice/pastry/NodeHandle.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardRouter_getBestRoutingCandidates_4
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Iterator* rtIterator {  };
    ::java::util::Iterator* iterator {  };
    ::java::util::ArrayList* lsCollection {  };
    ::rice::pastry::NodeHandle* next_ {  };
    ::rice::pastry::routing::RouteSet* best {  };
    int32_t k {  };

public:
    bool hasNext() override;
    virtual ::rice::pastry::NodeHandle* getNext();
    ::rice::pastry::NodeHandle* next() override;
    void remove() override;

    // Generated
    StandardRouter_getBestRoutingCandidates_4(StandardRouter *StandardRouter_this, ::rice::pastry::Id* target, int32_t lsPos);
    static ::java::lang::Class *class_();

private:
    void init();
    StandardRouter *StandardRouter_this;
    ::rice::pastry::Id* target;
    int32_t lsPos;
    virtual ::java::lang::Class* getClass0();
    friend class StandardRouter;
    friend class StandardRouter_AliveRouterStrategy;
    friend class StandardRouter_StandardRouter_1;
    friend class StandardRouter_route_2;
    friend class StandardRouter_sendTheMessage_3;
};
