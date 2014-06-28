
#ifndef FSM_STATE_H
#define FSM_STATE_H
#include <string>
#include <functional>
#include "Base.h"
#include "Action.h"


namespace FSM
{
  class Transition;
  
  class State:public Base
  {
  public:
    State();
    State(std::string p_name);
    ~State();
    
    
    virtual void doInAction(Transition * p_from);
    virtual void doOutAction(Transition * p_to);
    
    void setInAction(Action* p_in);
    void setOutAction(Action* p_out);
    
  private:
    Action* m_in;
    Action* m_out;
  };
};

#endif