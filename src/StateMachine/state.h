template <class BaseEntity>
class State{
	virtual ~State();
	State(State &);
	//perform upon entering state
	virtual void Enter(BaseEntity *);
	//execute on update
	virtual void Execute(BaseEntity *);
	//perform when leaving state
	virtual void Exit(BaseEntity *);
};
