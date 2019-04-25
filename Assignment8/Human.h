#pragma once

#include <string>
#include <vector>
#include <sstream>

class Human
{

private:
	std::string name;
	std::string job;
	std::string photo;
	int age;

public:
	Human();
	Human(std::string name);
	Human(std::string name, std::string job, int age, std::string photo);
	~Human();

	std::string getName();
	std::string getJob();
	int getAge();
	std::string getPhoto();

	bool operator==(Human otherHuman);
	bool operator=(Human otherHuman);

	friend std::istream& operator>>(std::istream& inputStream, Human& human);
	friend std::ostream& operator<<(std::ostream& outputStream, Human& human);
};

