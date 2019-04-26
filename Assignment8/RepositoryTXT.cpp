#include "RepositoryTXT.h"



RepositoryTXT::RepositoryTXT(string path)
{
	this->data = new vector<Human>;
	this->load(path);
}


RepositoryTXT::~RepositoryTXT()
{
}

bool RepositoryTXT::add(Human toAdd)
{
	Repository::add(toAdd);
	this->save();
	return true;
}

bool RepositoryTXT::update(Human toUpdate)
{
	Repository::update(toUpdate);
	this->save();
	return true;
}

bool RepositoryTXT::remove(Human toDelete)
{
	Repository::remove(toDelete);
	this->save();
	return false;
}

bool RepositoryTXT::load(string path)
{
	this->path = path;
	this->reset();

	ifstream file(path);
	if (!file.is_open()) return false;

	Human human;
	while (file >> human) {
		this->add(human);
	}
	file.close();
	return true;
}

bool RepositoryTXT::save()
{
	if (this->path != "") {
		ofstream file(this->path);
		auto humans = this->getElements();
		for (auto human : humans) {
			file << human;
		}
	}
	return true;
}

void RepositoryTXT::reset()
{
	delete this->data;
	this->data = new vector<Human>;
}
