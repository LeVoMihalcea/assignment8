#pragma once
#include "RepositoryTXT.h"
class RepositoryHTML : public RepositoryTXT
{
private:
	string path;
public:
	RepositoryHTML(string path);
	~RepositoryHTML();
	bool load(string path);
	bool save();
};

