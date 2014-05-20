#ifndef FSM_BASE_H
#define FSM_BASE_H

#include <string>
#include "ID.h"

namespace FSM {
  class Base {
  public:
    Base();
    Base(std::string p_name):m_name(p_name),m_Id() {};
    
    virtual ~Base() {};
    
    void setName(std::string p_name) {
      m_name = p_name;
    };
    std::string getName() {return m_name;};
    
    const Id & getId() const {return m_Id;};
    
    bool operator==(const Base & p_base) { return m_Id == p_base.m_Id;};
    
  private:
    std::string m_name;
    const Id m_Id;
  };
};

#endif