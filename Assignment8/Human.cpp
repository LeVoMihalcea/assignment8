#include "Human.h"

using namespace std;

vector<string> tokenize(string str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

Human::Human()
{
}

Human::Human(std::string name)
{
	this->name = name;
}

Human::Human(std::string name, std::string job, int age, std::string photo)
{
	this->name = name;
	this->job = job;
	this->age = age;
	this->photo = photo;
}

Human::~Human()
{
}

std::string Human::getName()
{
	return this->name;
}

std::string Human::getJob()
{
	return this->job;
}

int Human::getAge()
{
	return this->age;
}

std::string Human::getPhoto()
{
	return this->photo;
}

bool Human::operator==(Human otherHuman)
{
	return this->name == otherHuman.getName();
}

bool Human::operator=(Human otherHuman)
{
	this->name = otherHuman.getName();
	this->job = otherHuman.getJob();
	this->age = otherHuman.getAge();
	this->photo = otherHuman.getPhoto();
	return true;
}

std::string Human::toHtml()
{
	string toReturn = "";
	toReturn = "<tr>\n\t<td>" + this->getName() + "</td>\n\t\t<td>" + this->getJob() + "</td>\n\t\t<td>" + to_string(this->getAge()) + "</td>\n\t\t<td><img src=\"poza.jpg\" width=\"100px\"><br>" + this->getPhoto() + "</img></td>\n\t\</tr>";
	return toReturn;
}

std::istream & operator>>(std::istream & inputStream, Human & human)
{
	std::string lineRead;
	getline(inputStream, lineRead);

	vector<string> tokens = tokenize(lineRead, ',');

	if (tokens.size() != 4) {
		//just making sure it is valid
		return inputStream;
	}

	human.name = tokens[0];
	human.job = tokens[1];
	human.age = stoi(tokens[2]);
	human.photo = tokens[3];

	return inputStream;
}

std::ostream & operator<<(std::ostream & outputStream, Human & human)
{
	outputStream << human.name << ","
		<< human.job << ","
		<< human.age << ","
		<< human.photo << "\n";
	return outputStream;
}
