#include "State.h"


FSM::State::State(Machine* p_machine):Base(),m_machine(p_machine),m_in(0),m_out(0)
{

}

FSM::State::State(Machine* p_machine,std::string p_name):Base(p_name),m_machine(p_machine),m_in(0),m_out(0)
{
}

FSM::State::~State()
{
}

void FSM::State::doInAction(Transition * p_from)
{
  if (m_in != 0)
    m_in->run(Action::ENTERING_STATE,this);
}

void FSM::State::doOutAction(Transition * p_to)
{
  if (m_out != 0)
    m_out->run(Action::EXITING_STATE,this);
}

void FSM::State::setInAction(Action * p_in)
{
  m_in = p_in;
}

void FSM::State::setOutAction(Action * p_out)
{
  m_out = p_out;
}

