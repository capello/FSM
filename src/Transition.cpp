#include "Transition.h"

FSM::Transition::Transition()
{
}

FSM::Transition::~Transition()
{
}

void FSM::Transition::setFromState(State* p_from)
{
  m_stateFrom = p_from;
}

void FSM::Transition::setToState(State* p_to)
{
  m_stateTo = p_to;
}

void FSM::Transition::f_trans(FSM::Transition* p_transition)
{
  if (m_trans) 
    m_trans(this);
  
}

void FSM::Transition::setTransFunction(const std::function<void(Transition*)> p_trans)
{
  m_trans = p_trans;
}
