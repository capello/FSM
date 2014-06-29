
#ifndef FSM_STATE_H
#define FSM_STATE_H
#include <string>
#include <functional>
#include "Base.h"
#include "Action.h"
#include "FSM.h"


namespace FSM
{

  class Transition;
  
  class State:public Base
  {
  public:
    State(Machine *p_machine);
    State(Machine* p_machine, std::string p_name);
    ~State();
    
    
    virtual void doInAction(Transition * p_from);
    virtual void doOutAction(Transition * p_to);
    
    void setInAction(Action* p_in);
    void setOutAction(Action* p_out);
    Machine* getMachine() const {return m_machine;};
    
  private:
    Action* m_in;
    Action* m_out;
    Machine* m_machine;
  };
};

#endif