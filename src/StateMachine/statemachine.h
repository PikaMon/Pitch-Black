#include "state.h"
template<class BaseEntity>
class StateMachine{
	private:
	BaseEntity *pOwner;
	State<BaseEntity> *pCurrent;
	State<BaseEntity> *pPrevious;
	State<BaseEntity> *pGlobal;

	public:
	StateMachine(BaseEntity *owner):pOwner(owner), pCurrent(NULL), pPrevious(NULL), pGlobal(NULL);
	
	void setCurrent(State<BaseEntity> *);
	void SetPrevious(State<BaseEntity> *);
	void SetGlobal(State<BaseEntity> *);
	
	void Update();
	
	bool checkState(state<BaseEntity> &s);

	void Change State(State<BaseEntity> *New);
	State<BaseEntity> *Current();
	State<BaseEntity> *Previous;
	State<BaseEntity> *Global;
};
