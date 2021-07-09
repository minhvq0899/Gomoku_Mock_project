#pragma once
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <iostream>
#include <string>
#include <vector>

class Database {
public:
	// std::vector<char[256]> account_list;
	// std::vector<char[256]> password_list;

	Database();  
	void showSQLError(unsigned int, const SQLHANDLE&);
	void retrieveData(std::string);
	// 1 for winning, 0 for losing
	int retrieveMatch(std::string, std::string, int); 
	void updateMatch(std::string, int, std::string, int); 
	void insertAccounts(std::string, std::string);
}; 






