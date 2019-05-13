#include <iostream>
#include "RepositoryCSV.h"
#include "RepositoryTXT.h"
//#include "RepositoryHTML.h"
#include "Service.h"
#include "UI.h"
#include "tests.h"
#include "isolationTest.h"
using namespace std;

int main() {

	//runTests();
	try { testAdd(); }
	catch (RepositoryError) {}

	Repository* repo = new Repository();
	Validators* validators = new Validators();
	Service* service = new Service(repo, validators);
	UI* ui = new UI(service);

	ui->run();
	delete repo;
	delete service;
	delete ui;

	return 0;
}