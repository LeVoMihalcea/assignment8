#pragma once

#include "Human.h"

class Validators
{
public:
	Validators();
	~Validators();

	bool validateHuman(Human human) {
		if (human.getName() == "") return false;
		if (human.getJob() == "") return false;
		if (human.getAge() < 0 or human.getAge() > 200) return false; //maybe people live longer in the apocalypse
		if (human.getPhoto() == "") return false;
	}

	bool validateInput(char command[]) {
		if (strcmp(command, "") == 0) return false;
	}
};

