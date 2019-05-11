#include "Service.h"
#include <iostream>
using namespace std;
Service::Service(Repository * repo)
{
	this->repo = repo;
}

Service::~Service()
{
}

vector<Human> Service::interpretCommand(vector<string> words)
{
	vector<Human> toReturn;
	if (words[0] == "fileLocation") {
		if (words[1].substr(words[1].length() - 3) == "txt")
			this->repo = new RepositoryTXT(words[1]);
		return toReturn;
	}
	if (words[0] == "mylistLocation") {
		if (words[1].substr(words[1].length() - 3) == "csv") {
			this->mylistRepo = new RepositoryCSV(words[1]);
		}
		if (words[1].substr(words[1].length() - 4) == "html") {
			this->mylistRepo = new RepositoryHTML(words[1]);
		}
	}
	if (words[0] == "mode") {
		if (words[1] == "A")
			this->mode = 'A';
		if (words[1] == "B") {
			this->mode = 'B';
			this->myList.clear();
			this->myListIterator = this->repo->data->begin();
		}
	}
	if (this->mode == 'A') {
		if (words[0] == "add") {
			words[2].erase(words[2].begin());
			words[4].erase(words[4].begin());
			Human newHuman(words[1], words[2], stoi(words[3]), words[4]);
			this->add(newHuman);
			return toReturn;
		}
		if (words[0] == "list") {
			return this->repo->getElements();
		}
		if (words[0] == "update") {
			Human newHuman(words[1], words[2], stoi(words[3]), words[4]);
			this->update(newHuman);
			return toReturn;
		}
		if (words[0] == "delete") {
			Human toDelete(words[1]);
			this->remove(toDelete);
			return toReturn;
		}
	}
	if (this->mode == 'B') {
		if (words[0] == "save") {
			Human toFind(words[1]);
			auto repoCopy = this->repo->getElements();
			for (auto i : repoCopy) {
				if (i == toFind) {
					this->myList.push_back(i);
					if(this->mylistRepo!=NULL)
						this->mylistRepo->add(i);
					break;
				}
			}
		}
		if (words[0] == "mylist") {
			return this->myList;
		}
		if (words[0] == "next") {
			toReturn.push_back(*this->myListIterator);
			this->myListIterator = next(this->myListIterator);
			return toReturn;
		}
		if (words[0] == "list") {
			auto repoCopy = this->repo->getElements();
			if (words.size() == 2) {
				//only age
				int ageLimit = stoi(words[1]);
				for(auto i : repoCopy){
					if (i.getAge() < ageLimit) {
						toReturn.push_back(i);
					}
				}
				return toReturn;
			}
			else if( words.size() == 3 ){
				int ageLimit = stoi(words[2]);
				for (auto i : repoCopy) {
					if (i.getAge() < ageLimit && i.getJob() == words[1]) {
						toReturn.push_back(i);
					}
				}
				return toReturn;
			}
		}
	}
	return toReturn;
}

bool Service::add(Human toAdd)
{
	this->repo->add(toAdd);
	return true;
}

bool Service::remove(Human toRemove)
{
	this->repo->remove(toRemove);
	return true;
}

bool Service::update(Human toUpdate)
{
	this->repo->update(toUpdate);
	return true;
}
