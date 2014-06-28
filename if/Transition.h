#ifndef FSM_TRANSITION_H
#define FSM_TRANSITION_H

#include "State.h"
#include "Base.h"
#include "Action.h"
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
    void f_trans();
    void setTransAction(Action* p_trans);
    
  private:
    State *m_stateFrom;
    State *m_stateTo;
    Action* m_trans;
  };
};

#endif