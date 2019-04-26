#pragma once

#include <vector>

#include "Human.h"

using namespace std;

class Repository
{
	friend class RepositoryTXT;
private:
	vector<Human>* data = new vector<Human>;

public:
	Repository() {};
	~Repository() {};
	virtual bool add(Human toAdd);
	virtual bool update(Human toUpdate);
	virtual bool remove(Human toRemove);
	virtual vector<Human> getElements();
	virtual void reset();
	virtual bool save();
	virtual bool load();
};

