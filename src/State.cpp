#include "State.h"


FSM::State::State()
{
}

FSM::State::~State()
{
}

void FSM::State::f_in(Transition * p_from)
{
  if (m_in) 
    m_in(p_from);
}

void FSM::State::f_out(Transition * p_to)
{
  if (m_out)
    m_out(p_to);
}
