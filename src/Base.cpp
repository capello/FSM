#include "Base.h"
#include <sstream> 
#include <string>

FSM::Base::Base()
{
  std::ostringstream ostr;
  
  ostr << "Anonymous[" << m_Id << "]";
  m_name = ostr.str();
}
