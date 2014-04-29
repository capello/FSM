
#ifndef FSM_STATE_H
#define FSM_STATE_H
#include <string>
#include <functional>


namespace FSM
{
  class Transition;
  
  class State
  {
  public:
    State();
    ~State();
    
    const std::string & getName() {return m_name;};
    
    virtual void f_in(Transition * p_from);
    virtual void f_out(Transition * p_to);
    
    void setInFunction(const std::function<void(Transition*)> p_in);
    void setOutFunction(const std::function<void(Transition*)> p_out);
    
  private:
    std::string m_name;
    std::function<void(Transition *)> m_in;
    std::function<void(Transition *)> m_out;
  };
};

#endif