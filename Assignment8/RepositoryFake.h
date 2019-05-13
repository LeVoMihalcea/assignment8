#pragma once
#include "Repository.h"
class RepositoryFake : public Repository
{
public:
	RepositoryFake();
	~RepositoryFake();
	
	vector<Human> getElements() {
		string name = "1", job = "1", photo = "1"; int age = 1;
		Human h1(name, job, age, photo);
		name = "2"; job = "2"; photo = "2"; age = 2;
		Human h2(name, job, age, photo);
		name = "3"; job = "3"; photo = "3"; age = 3;
		Human h3(name, job, age, photo);
		
		vector<Human> toReturn;
		toReturn.push_back(h1);
		toReturn.push_back(h2);
		toReturn.push_back(h3);

		return toReturn;
	}
};

