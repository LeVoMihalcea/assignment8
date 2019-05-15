#pragma once
#include "Validators.h"

class ValidatorsFake : public Validators
{
public:
	ValidatorsFake();
	~ValidatorsFake();
	bool validateHuman() {
		return true;
	}
};

