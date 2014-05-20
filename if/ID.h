#ifndef FSM_ID_H
#define FSM_ID_H
#include <atomic>
#include <iostream>

namespace FSM {
  class Id
  {
  public:
    Id();
    ~Id();
    
    bool operator==(const Id &p_id) const;
    
    friend std::ostream & operator<<(std::ostream & p_out, const Id & p_id);
    
  private:
    static std::atomic<unsigned long long> s_seed;
    unsigned long long m_id;
  };


};

#endif
