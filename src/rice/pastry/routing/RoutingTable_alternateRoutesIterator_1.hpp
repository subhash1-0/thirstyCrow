// Generated from /pastry-2.1/src/rice/pastry/routing/RoutingTable.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <rice/pastry/NodeHandle.hpp>

struct default_init_tag;

class rice::pastry::routing::RoutingTable_alternateRoutesIterator_1
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t keyDigit {  };
    int32_t myDigit {  };
    int32_t i {  };
    int32_t j {  };
    int32_t k {  };
    ::rice::pastry::NodeHandle* next_ {  };
    RouteSet* rs {  };
    int32_t digit {  };

public: /* protected */
    virtual ::rice::pastry::NodeHandle* findNext();

public:
    bool hasNext() override;
    ::rice::pastry::NodeHandle* next() override;
    void remove() override;

    // Generated
    RoutingTable_alternateRoutesIterator_1(RoutingTable *RoutingTable_this, ::rice::pastry::Id* key, int32_t diffDigit, ::rice::pastry::Id_Distance* myDistance);
    static ::java::lang::Class *class_();

private:
    void init();
    RoutingTable *RoutingTable_this;
    ::rice::pastry::Id* key;
    int32_t diffDigit;
    ::rice::pastry::Id_Distance* myDistance;
    virtual ::java::lang::Class* getClass0();
    friend class RoutingTable;
};
