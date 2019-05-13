#pragma once
#include "Service.h"
#include <iostream>
#include "Validators.h"
#include "exceptions.h"
using namespace std;
class UI
{
private:
	Service* service;
public:
	UI(Service* service);
	~UI();

	void run() {
		char command[512] = "nothing here";
		while (strcmp(command, "exit")!=0) {
			vector<string> words;
			cin.getline(command, 512);
			char* word = strtok(command, " ");
			while (word != NULL) {
				words.push_back(word);
				word = strtok(NULL, ",");
			}
			try {
				auto output = this->service->interpretCommand(words);
				if (output.size() > 0) {
					for (auto i : output) {
						cout << i;
					}
				}
			}
			catch (RepositoryError) {
				cout << "element already existing\n";
			}
			catch (ValidationError) {
				cout << "invalid parameters for a human\n";
			}
		}
	}
};

