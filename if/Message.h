#ifndef FSM_MESSAGE_H
#define FSM_MESSAGE_H
#include "Base.h"

namespace FSM {
  class Message:public Base {
  public:
    class Node {
    public:
      enum Direction {
        UNKNOWN,
        RECEIVER,
        SENDER,
        BOTH
      };
    public:
      Node(Direction p_direction = UNKNOWN);
      ~Node();
      
      void setDirection(Direction p_direction);
      Direction getDirection(){return m_direction;};
    
    private:
      Direction m_direction;
    };
    
    template <class T> class Data {
    public:
      Data();
      Data(const T& p_data);
      ~Data();
      
      void setData(const T& p_data);
      T &getData() const;
      
    private:
      T m_data;
      
    };
  public:
    Message();
    ~Message();
    
  private:
  };
};

#endif
