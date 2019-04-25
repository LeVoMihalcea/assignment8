#pragma once
#include <string>
#include <assert.h>

#include "Human.h"

using namespace std;

void testHuman() {
	string name = "leo";
	string job = "programator";
	int age = 19;
	string photo = "photo.jpg";

	Human newHuman(name, job, age, photo);

	assert(newHuman.getName() == "leo");
	assert(newHuman.getJob() == "programator");
	assert(newHuman.getAge() == 19);
	assert(newHuman.getPhoto() == "photo.jpg");
}

void runTests() {
	testHuman();
}