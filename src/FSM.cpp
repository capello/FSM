#include "FSM.h"
#include "State.h"
#include "Port.h"
#include "Transition.h"

FSM::Machine::Machine():Base(),m_isRunning(false),m_transitions(),m_states()
{
  m_start = new State(this,"start");
  m_end = new State(this,"end");
  m_states.push_back(m_start);
  m_states.push_back(m_end);
}

FSM::Machine::Machine(std::string p_name):Base(p_name),m_isRunning(false),m_transitions(),m_states()
{
  m_start = new State(this,"start");
  m_end = new State(this,"end");
  m_states.push_back(m_start);
  m_states.push_back(m_end);
  
}

FSM::Machine::~Machine()
{
}

void FSM::Machine::addState(FSM::State* p_state)
{
  if (!m_isRunning)
    m_states.push_back(p_state);
}

void FSM::Machine::addTransition(FSM::Transition* p_transition, FSM::State* p_from, FSM::State* p_to)
{
  if (!m_isRunning)
  {
    p_transition->setFromState(p_from);
    p_transition->setToState(p_to);
  }
}

void FSM::Machine::start()
{
  if (!m_isRunning)
  {
    m_isRunning = true;
    m_current = m_start;
  }
}

void FSM::Machine::stop()
{
}

void FSM::Machine::reset()
{
}

void FSM::Machine::step(FSM::Transition* p_transition)
{
  if (p_transition->getFromState() == m_current)
  {
    p_transition->getFromState()->doOutAction(p_transition);
    p_transition->f_trans();
    p_transition->getToState()->doInAction(p_transition);
    m_current = p_transition->getToState();
  }
}
