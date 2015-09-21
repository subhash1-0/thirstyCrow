// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/DirectTutorial.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/tutorial/deterministicsimulator/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Observer.hpp>

struct default_init_tag;

class rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1_run_1_1
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Observer
{

public:
    typedef ::java::lang::Object super;
    void update(::java::util::Observable* o, ::java::lang::Object* arg) override;

    // Generated
    DirectTutorial_scheduleBootTask_1_run_1_1(DirectTutorial_scheduleBootTask_1 *DirectTutorial_scheduleBootTask_1_this, ::rice::pastry::PastryNode* node, ::rice::environment::Environment* env, int32_t myCurNode, int32_t numNodes, ::rice::pastry::NodeIdFactory* nidFactory);
    static ::java::lang::Class *class_();
    DirectTutorial_scheduleBootTask_1 *DirectTutorial_scheduleBootTask_1_this;
    ::rice::pastry::PastryNode* node;
    ::rice::environment::Environment* env;
    int32_t myCurNode;
    int32_t numNodes;
    ::rice::pastry::NodeIdFactory* nidFactory;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DirectTutorial;
    friend class DirectTutorial_scheduleBootTask_1;
    friend class DirectTutorial_scheduleDeliveryTask_2;
    friend class DirectTutorial_scheduleDeliveryTask_3;
};
