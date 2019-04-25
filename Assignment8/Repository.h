#pragma once

#include <vector>

#include "Human.h"

using namespace std;

class Repository
{
private:
	vector<Human> data;

public:
	Repository() {};
	~Repository() {};
	virtual bool add(Human toAdd);
	virtual bool update(Human toUpdate);
	virtual bool remove(Human toRemove);
	virtual vector<Human> getAll();
	virtual void reset();
	virtual void save();
};

