#include "Repository.h"

bool Repository::add(Human toAdd)
{
	auto iterator = find(this->data.begin(), this->data.end(), toAdd);
	if (iterator == this->data.end()) {
		this->data.push_back(toAdd);
		return true;
	}
	return false;
}

bool Repository::update(Human toUpdate)
{
	auto iterator = find(this->data.begin(), this->data.end(), toUpdate);
	if (iterator != this->data.end()) {
		*iterator = toUpdate;
		return true;
	}
	return false;
}

bool Repository::remove(Human toRemove)
{
	auto iterator = find(this->data.begin(), this->data.end(), toRemove);
	if (iterator != this->data.end()) {
		this->data.erase(iterator);
		return true;
	}
	return false;
}

vector<Human> Repository::getAll()
{
	return this->data;
}

void Repository::reset()
{
	this->data.clear();
}

void Repository::save(){}
