#pragma once
#include "Repository.h"

#include <fstream>

class RepositoryTXT : public Repository
{
	friend class Service;
private:
	string path;
public:
	RepositoryTXT(string path);
	~RepositoryTXT();

	bool add(Human toAdd);
	bool update(Human toUpdate);
	bool remove(Human toDelete);
	bool load(string path);
	bool save();
	void reset();
	void setPath(string path);
	virtual string getPath();
};

