#include "ID.h"

std::atomic<unsigned long long> FSM::Id::s_seed (0);

FSM::Id::Id()
{
  m_id = s_seed.fetch_add(1);
}

FSM::Id::~Id()
{
}

bool FSM::Id::operator==(const FSM::Id& p_id) const
{
  return m_id == p_id.m_id;
}

namespace FSM {
std::ostream & operator<<(std::ostream & p_out, const FSM::Id & p_id)
{
  p_out << p_id.m_id;
  return p_out;
}
};