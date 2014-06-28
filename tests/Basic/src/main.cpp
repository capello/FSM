#include <iostream>
#include "FSM.h"
#include <Action.h>
#include <State.h>
// Test Basic FSM.
// Define a basic FSM.
// Start -> New -> Aproved -> Closed -> endl
//           |---> Abort ------^

class MyFSM:public FSM::Machine
{
public:
  MyFSM();
  ~MyFSM();
 
  FSM::Transition StartToNew;
  FSM::Transition NewToAproved;
  FSM::Transition NewToAbort;
  FSM::Transition AprovedToClosed;
  FSM::Transition AbortToClosed;
  FSM::Transition ClosedToEnd;  
private:
  
  FSM::State New;
  FSM::State Aproved;
  FSM::State Closed;
  FSM::State Abort;
  FSM::Action whereAmI;

} ;


void whereAmIFunction(FSM::Action::When p_when, FSM::Base* p_base)
{
  switch (p_when)
  {
    case FSM::Action::ENTERING_STATE:
      std::cout << "Entering " << p_base->getName() << std::endl;
      break;
    case FSM::Action::EXITING_STATE:
      std::cout << "Exiting " << p_base->getName() << std::endl;
      break;
    case FSM::Action::IN_TRANSITION:
    {
      FSM::Transition * l_transition = dynamic_cast<FSM::Transition*>(p_base);
      std::cout << "\tDoing transition from <" << l_transition->getFromState()->getName() << "> to <" << l_transition->getToState()->getName() << ">.\n";
    }
    break;
    default:
      std::cerr << "Should never append\n";
      break;
  }
}

MyFSM::MyFSM()
{
  addState(&New);
  addState(&Aproved);
  addState(&Closed);
  addState(&Abort);
  addTransition(&StartToNew,getStartState(),&New);
  addTransition(&NewToAproved,&New,&Aproved);
  addTransition(&NewToAbort,&New,&Abort);
  addTransition(&AprovedToClosed,&Aproved,&Closed);
  addTransition(&AbortToClosed,&Abort,&Closed);
  addTransition(&ClosedToEnd,&Closed,getEndState());
  New.setInAction(&whereAmI);
  New.setOutAction(&whereAmI);
  Aproved.setInAction(&whereAmI);
  Aproved.setOutAction(&whereAmI);
  Closed.setInAction(&whereAmI);
  Closed.setOutAction(&whereAmI);
  Abort.setInAction(&whereAmI);
  Abort.setOutAction(&whereAmI);
  StartToNew.setTransAction(&whereAmI);
  ClosedToEnd.setTransAction(&whereAmI);
  whereAmI.setAction(whereAmIFunction);
  New.setName("New");
}

MyFSM::~MyFSM()
{

}



// Init by template.
//FSM::FSM<States<State<"New">, State<"Aproved">, State<"Closed">, State<"Abort"> >,
//    Transitions<Transition<Transition::start, "New">, Transition<"New","Aproved">, Transition<"Aproved","Closed">, Transition<"Closed",Transition::end>, Transition<"New","Abort">, Transition<"Abort","Closed"> > > g_SimpleFSM;

int main()
{
  MyFSM l_SimpleFSM;
  
  std::cout << "Hello !" << std::endl;
  // First Start FSM
  l_SimpleFSM.start();
  
  std::cout << "STATE: <" << l_SimpleFSM.getCurrentState()->getName() << ">.\n";
  l_SimpleFSM.step(&l_SimpleFSM.StartToNew);
  std::cout << "STATE: <" << l_SimpleFSM.getCurrentState()->getName() << ">.\n";
  l_SimpleFSM.step(&l_SimpleFSM.NewToAproved);
  std::cout << "STATE: <" << l_SimpleFSM.getCurrentState()->getName() << ">.\n";
  l_SimpleFSM.step(&l_SimpleFSM.AprovedToClosed);
  std::cout << "STATE: <" << l_SimpleFSM.getCurrentState()->getName() << ">.\n";
  l_SimpleFSM.step(&l_SimpleFSM.ClosedToEnd);
  std::cout << "STATE: <" << l_SimpleFSM.getCurrentState()->getName() << ">.\n";
  
  return 0;
}
