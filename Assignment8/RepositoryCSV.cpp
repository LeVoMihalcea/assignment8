#include "RepositoryCSV.h"



RepositoryCSV::RepositoryCSV(string path) : RepositoryTXT{path}
{
	this->path = path;
}


RepositoryCSV::~RepositoryCSV()
{
}

bool RepositoryCSV::save()
{
	RepositoryTXT::save();
	return true;
}

bool RepositoryCSV::load()
{
	RepositoryTXT::load(this->path);
	return true;
}
