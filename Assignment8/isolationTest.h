#pragma once
#include <iostream>
#include "RepositoryFake.h"
#include "Service.h"
#include "Validators.h"
using namespace std;
void testAdd() {
	Repository* repo = new RepositoryFake();
	Validators* validator = new Validators();
	Service* service = new Service(repo, validator);
	string name = "1", job = "1", photo = "1"; int age = 1;
	Human h1(name, job, age, photo);
	assert(service->add(h1));
	assert(service->add(h1) == 0);
}