#pragma once

#include <exception>
#include <string>

using namespace std;

class ValidationError : public std::exception {
	virtual const char* what() const throw() {
		return "Something went wrong\n";
	}
};

class RepositoryError : public std::exception {
	virtual const char* what() const throw() {
		return "Something went wrong\n";
	}
};