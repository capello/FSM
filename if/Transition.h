#ifndef FSM_TRANSITION_H
#define FSM_TRANSITION_H

#include "State.h"
#include "Base.h"
#include <functional>

namespace FSM {

  class Transition: public Base {
  public:
    Transition();
    virtual ~Transition();
    void setFromState(State* p_from);
    void setToState(State* p_to);
    
    State * getFromState(){ return m_stateFrom;};
    State * getToState() {return m_stateTo;};
    void f_trans(Transition* p_transition);
    void setTransFunction(const std::function<void(Transition*)> p_trans);
    
  private:
    State *m_stateFrom;
    State *m_stateTo;
    std::function<void(Transition *)> m_trans;
  };
};

#endif