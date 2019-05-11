#include <iostream>
#include "RepositoryCSV.h"
#include "RepositoryTXT.h"
//#include "RepositoryHTML.h"
#include "Service.h"
#include "UI.h"
#include "tests.h"

using namespace std;

int main() {

	//runTests();
		
	Repository* repo = new Repository();
	Service* service = new Service(repo);
	UI* ui = new UI(service);

	ui->run();

	return 0;
}