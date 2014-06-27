#ifndef FSM_PORTS_H
#define FSM_PORTS_H
#include "Base.h"
#include <string>

namespace FSM {
class Port:public Base
{
public:
  Port();
  Port(std::string &p_name);
  ~Port();
};

};
#endif