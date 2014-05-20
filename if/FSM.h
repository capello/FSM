#ifndef FSM_MACHINE_H
#define FSM_MACHINE_H
#include <list>
#include "State.h"
#include "Transition.h"
#include "Base.h"

namespace FSM {
  class Machine:public Base
  {
  public:
    Machine();
    virtual ~Machine();
    
    // Initialise
    // Only if isRunning false;
    void addState(State * p_state);
    void addTransition(Transition* p_transition, State* p_from, State* p_to);
    
    // Run
    virtual void start();
    virtual void stop();
    virtual void reset();
    virtual void step(Transition *p_transition);
    
    
    
    // Acces
    State * getStartState(){return &m_start;};
    State * getEndState(){return &m_end;};
    State * getCurrentState(){return m_current;};
    
  private:
    State * m_current;
    State m_start;
    State m_end;
    std::list<State*> m_states;
    std::list<Transition*> m_transitions;
    bool m_isRunning;
  };
};

#endif