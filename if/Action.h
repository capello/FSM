#ifndef FSM_ACTION_H
#define FSM_ACTION_H
#include "Base.h"
#include <functional>

namespace FSM {
  class Action:public Base
  {
  public:
    enum When {
      ENTERING_STATE,
      EXITING_STATE,
      IN_TRANSITION
    };
    Action(std::function<void(When,Base*)> p_fct = [](When p_when, Base* p_base){return;});
    Action(std::string p_name, std::function<void(When, Base*)> p_fct = [](When p_when, Base* p_base){return;});
    Action(const FSM::Action& p_action);
    ~Action();
    
    void run(When p_when, Base * p_base);
    void setAction(std::function<void(When, Base*)> p_function);
    
  private:
    std::function<void(When, Base *)> m_fct;
  };
};

#endif