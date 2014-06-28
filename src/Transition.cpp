#include "Transition.h"

FSM::Transition::Transition():m_trans(0),m_stateFrom(0),m_stateTo(0)
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

void FSM::Transition::f_trans()
{
  if (m_trans!=0)
    m_trans->run(Action::IN_TRANSITION,this);
  
}

void FSM::Transition::setTransAction(Action* p_trans)
{
  m_trans = p_trans;
}
