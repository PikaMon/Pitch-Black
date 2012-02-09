#include "statemachine.h"
StateMachine::StateMachine(BaseEntity *owner):pOwner(owner), pCurrent(NULL), pPrevious(NULL), pGlobal(NULL){
	
}

void StateMachine::setCurrent(State<BaseEntity> &s){
	pCurrent = s;
}

void StateMachine::setPrevious(State<BaseEntity> &s){
	pPrevious = s;
}

void StateMachine::setGlobal(State<BaseEntity> &s){	
	pGlobal = s;
}

void StateMachine::Update(){
//if Current state exists
if(pCurrent)
	pCurrent->Execute(pOwner);
//If Global State Exists
if(pGlobal)
	pGlobal->Execute(pOwner);
}

bool checkState(State<BaseEntity> *s){
	if(s.pCurrent == pCurrent)
		return true;
	else
		return false;
}

void changeState(State<BaseEntity> *new){
	setPrevious(pCurrent);
	setCurrent(new);
}

State<BaseEntity> *StateMachine::Current(){
	return pCurrent;
}

State<BaseEntity> *StateMachine::Previous(){
	return pPrevious;
}

State<BaseEntity> *StateMachine::Global(){
	return pGlobal();
}

