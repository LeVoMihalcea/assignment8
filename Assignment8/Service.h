#pragma once
#include "Human.h"
#include "Repository.h"
#include "RepositoryCSV.h"
#include "RepositoryHTML.h"
#include "RepositoryTXT.h"
class Service
{
private:
	Repository* repo;
	Repository* mylistRepo = NULL;
	char mode = 'n';
	vector<Human> myList;
	vector<Human>::iterator myListIterator;

public:
	Service(Repository* repo);
	~Service();

	vector<Human> interpretCommand(vector<string> words);
	bool add(Human toAdd);
	bool remove(Human toRemove);
	bool update(Human toUpdate);
	
};

