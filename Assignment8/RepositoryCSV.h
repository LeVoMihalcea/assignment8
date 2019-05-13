#pragma once
#include "RepositoryTXT.h"
class RepositoryCSV : public RepositoryTXT
{
private:
	string path;

public:
	RepositoryCSV(string path);
	~RepositoryCSV();

	bool save();
	bool load();
	string getPath();
};

