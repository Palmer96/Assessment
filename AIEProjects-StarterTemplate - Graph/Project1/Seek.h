#pragma once
#include "IBehaviour.h"
#include "Agents.h"



class Seek : public IBehaviour
{
public:
	Seek();
	~Seek();



	virtual void Update(Agents *pAgent);


	



};

