#include <iostream>
#include "FSM.h"
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
  static void stateFct(FSM::Transition* p_transition, FSM::State* p_state);
  static void transitionFct(FSM::Transition* p_transition);
  
  FSM::State New;
  FSM::State Aproved;
  FSM::State Closed;
  FSM::State Abort;

} g_SimpleFSM;

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
  New.setInFunction(stateFct);
  New.setOutFunction(stateFct);
  Aproved.setInFunction(stateFct);
  Aproved.setOutFunction(stateFct);
  Closed.setInFunction(stateFct);
  Closed.setOutFunction(stateFct);
  Abort.setInFunction(stateFct);
  Abort.setOutFunction(stateFct);
  StartToNew.setTransFunction(transitionFct);
  New.setName("New");
}

MyFSM::~MyFSM()
{

}

void MyFSM::stateFct(FSM::Transition* p_transition, FSM::State* p_state)
{
  if (p_transition->getFromState() == p_state)
    std::cout << "Exiting ";
  else
    std::cout << "Entering ";
  std::cout << p_state->getName() << " state.\n";
}

void MyFSM::transitionFct(FSM::Transition* p_transition)
{
  std::cout << "\tDoing transition from <" << p_transition->getFromState()->getName() << "> to <" << p_transition->getToState()->getName() << ">.\n";
}

// Init by template.
//FSM::FSM<States<State<"New">, State<"Aproved">, State<"Closed">, State<"Abort"> >,
//    Transitions<Transition<Transition::start, "New">, Transition<"New","Aproved">, Transition<"Aproved","Closed">, Transition<"Closed",Transition::end>, Transition<"New","Abort">, Transition<"Abort","Closed"> > > g_SimpleFSM;

int main()
{
  std::cout << "Hello !" << std::endl;
  // First Start FSM
  g_SimpleFSM.start();
  
  std::cout << "STATE: <" << g_SimpleFSM.getCurrentState()->getName() << ">.\n";
  g_SimpleFSM.step(&g_SimpleFSM.StartToNew);
  std::cout << "STATE: <" << g_SimpleFSM.getCurrentState()->getName() << ">.\n";
  g_SimpleFSM.step(&g_SimpleFSM.NewToAproved);
  std::cout << "STATE: <" << g_SimpleFSM.getCurrentState()->getName() << ">.\n";
  g_SimpleFSM.step(&g_SimpleFSM.AprovedToClosed);
  std::cout << "STATE: <" << g_SimpleFSM.getCurrentState()->getName() << ">.\n";
  g_SimpleFSM.step(&g_SimpleFSM.ClosedToEnd);
  std::cout << "STATE: <" << g_SimpleFSM.getCurrentState()->getName() << ">.\n";
  
  return 0;
}
