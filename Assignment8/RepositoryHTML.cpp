#include "RepositoryHTML.h"

RepositoryHTML::RepositoryHTML(string path) : RepositoryTXT{path}
{
	this->path = path;
}

RepositoryHTML::~RepositoryHTML()
{
}

bool RepositoryHTML::load(string path)
{
	return true;
}

bool RepositoryHTML::save()
{
	ofstream file(this->path);
	
	file << "<!DOCTYPE html>\n"
		<< "<html>\n"
		<< "\t<body>\n"
		<< "\t\t<table border=\"1\">";
	for (auto human : this->getElements()) {
		file << human.toHtml();
	}
	file << "</table></body></html>";


	file.close();
	return true;
}
