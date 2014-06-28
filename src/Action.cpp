#include <Action.h>
#include <functional>


FSM::Action::Action(std::function<void(When, Base*)> p_fct ):Base(),m_fct(p_fct)
{
}

FSM::Action::Action(std::string p_name, std::function<void(When, Base*)> p_fct):Base(p_name),m_fct(p_fct)
{
}

FSM::Action::~Action()
{
}

FSM::Action::Action(const Action&p_action)
{
  std::cerr << "Copy action\n";
}

void FSM::Action::run(When p_when, Base * p_base)
{
  if (m_fct)
    m_fct(p_when,p_base);
  else
    std::cerr << "m_fct invalide ! (" << this->getName() << ")\n";
}
void FSM::Action::setAction(std::function<void(When, Base*)> p_function)
{
  m_fct = p_function;
}