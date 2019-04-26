#pragma once
#include <string>
#include <assert.h>
#include <iostream>

#include "Repository.h"
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

void testBasicRepository() {
	Repository* repository = new Repository();

	string name = "leo";
	string job = "programator";
	int age = 19;
	string photo = "photo.jpg";
	Human human1(name, job, age, photo);
	repository->add(human1);
	repository->add(human1);


	name = "istvan"; job = "softEngineer"; age = 19; photo = "brocolli.jpg";
	Human human2(name, job, age, photo);
	repository->add(human2);


	auto output = repository->getElements().size();
	assert(output == 2);

	repository->remove(human1);
	repository->remove(human1);

	output = repository->getElements().size();
	assert(output == 1);

	job = "random"; age = 20; photo = "random.jpg";
	Human human3(name, job, age, photo);
	repository->update(human3);

	name = "abcxyz";
	Human human4(name, job, age, photo);
	repository->update(human4);

	repository->reset();
	assert(repository->getElements().size() == 0);

}

void runTests() {
	testHuman();
	testBasicRepository();
}