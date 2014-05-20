
#ifndef FSM_STATE_H
#define FSM_STATE_H
#include <string>
#include <functional>
#include "Base.h"


namespace FSM
{
  class Transition;
  
  class State:public Base
  {
  public:
    State();
    State(std::string p_name);
    ~State();
    
    
    virtual void f_in(Transition * p_from);
    virtual void f_out(Transition * p_to);
    
    void setInFunction( std::function<void(Transition*,State*)> p_in);
    void setOutFunction( std::function<void(Transition*,State*)> p_out);
    
  private:
    std::function<void(Transition *, State *)> m_in;
    std::function<void(Transition *, State *)> m_out;
  };
};

#endif