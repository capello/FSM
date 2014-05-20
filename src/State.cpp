#include "State.h"


FSM::State::State():Base()
{

}

FSM::State::State(std::string p_name):Base(p_name)
{
}

FSM::State::~State()
{
}

void FSM::State::f_in(Transition * p_from)
{
  if (m_in) 
    m_in(p_from,this);
}

void FSM::State::f_out(Transition * p_to)
{
  if (m_out)
    m_out(p_to,this);
}

void FSM::State::setInFunction(const std::function<void(Transition*,State*)> p_in)
{
  m_in = p_in;
}

void FSM::State::setOutFunction(std::function< void(Transition*,State*) > p_out)
{
  m_out = p_out;
}

