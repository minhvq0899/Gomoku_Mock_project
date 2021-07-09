#include "Database.h"
#include <iostream>
#include <string>

Database::Database() {}

void Database::showSQLError(unsigned int handleType, const SQLHANDLE& handle)
{
	SQLCHAR SQLState[1024];	
	SQLCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL)) {
		// Returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information
		std::cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << std::endl;
	}
}

// ===================================================================================================================================================================================================================

void Database::retrieveData(std::string table)
{
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	std::string SQLQuery_str = "SELECT * FROM " + table;
	char* SQLQuery_char;
	SQLQuery_char = &SQLQuery_str[0]; 


	do {
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
			// Allocates the environment
			break;
		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			// Sets attributes that govern aspects of environments
			break;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
			// Allocates the connection
			break;
		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
			// Sets attributes that govern aspects of connections
			break;
		SQLCHAR retConString[1024]; // Conection string

		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=temp-minhvq12, 1433; DATABASE=mock_project;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
			// Establishes connections to a driver and a data source
		case SQL_SUCCESS:
			std::cout << "Successfully connected to SQL Server";
			std::cout << "\n";
			break;
		case SQL_SUCCESS_WITH_INFO:
			std::cout << "Successfully connected to SQL Server";
			std::cout << "\n";
			break;
		case SQL_NO_DATA_FOUND:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}

		if (retCode == -1)
			break;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
			// Allocates the statement
			break;
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery_char, SQL_NTS)) {
			// Executes a preparable statement
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else {
			char account_names[256]; 
			char password[256]; 
			int winning_match; 
			int losing_match; 
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
				// Fetches the next rowset of data from the result
				SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &account_names, sizeof(account_names), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &password, sizeof(password), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &winning_match, sizeof(password), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &losing_match, sizeof(password), NULL);
				// Retrieves data for a single column in the result set
				std::cout << account_names << "  " << password << "  " << winning_match << "  " << losing_match << "\n";
				
				// account_list.push_back(account_names); 
				// password_list.push_back(password);
			}
			std::cout << "Retrieve all data successfully\n";
		}
	} while (FALSE);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	// Frees the resources and disconnects
	getchar();
}

// ===================================================================================================================================================================================================================

int Database::retrieveMatch(std::string table, std::string username, int match_retrieved)
{
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	int numMatch;
	std::string column; 

	if (match_retrieved) {
		column = "[Winning Matches]"; 
	} 
	else {
		column = "[Losing Matches]";
	}
	std::string SQLQuery_str = "SELECT " + column + " FROM " + table + " WHERE [Account Name] = '" + username + "'";
	char* SQLQuery_char;
	SQLQuery_char = &SQLQuery_str[0];


	do {
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
			// Allocates the environment
			break;
		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			// Sets attributes that govern aspects of environments
			break;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
			// Allocates the connection
			break;
		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
			// Sets attributes that govern aspects of connections
			break;
		SQLCHAR retConString[1024]; // Conection string

		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=temp-minhvq12, 1433; DATABASE=mock_project;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
			// Establishes connections to a driver and a data source
		case SQL_SUCCESS:
			std::cout << "Successfully connected to SQL Server. Ready to retrieve an instance";
			std::cout << "\n";
			break;
		case SQL_SUCCESS_WITH_INFO:
			std::cout << "Successfully connected to SQL Server. Ready to retrieve an instance";
			std::cout << "\n";
			break;
		case SQL_NO_DATA_FOUND:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}

		if (retCode == -1)
			break;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
			// Allocates the statement
			break;
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery_char, SQL_NTS)) {
			// Executes a preparable statement
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else {
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
				// Fetches the next rowset of data from the result
				SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &numMatch, sizeof(numMatch), NULL); 
				std::cout << "Retrieve info successfully";
			}
		}
	} while (FALSE);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	// Frees the resources and disconnects
	getchar();

	return numMatch; 
}

// ===================================================================================================================================================================================================================

void Database::updateMatch(std::string table, int match_retrieved, std::string username, int updateInfo) {
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	std::string column;

	if (match_retrieved) {
		column = "[Winning Matches]";
	}
	else {
		column = "[Losing Matches]";
	}
	std::string SQLQuery_str = "UPDATE " + table + " SET " + column + " = " + std::to_string(updateInfo) + " WHERE [Account Name] = '" + username + "'";
	char* SQLQuery_char;
	SQLQuery_char = &SQLQuery_str[0];


	do {
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
			// Allocates the environment
			break;
		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			// Sets attributes that govern aspects of environments
			break;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
			// Allocates the connection
			break;
		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
			// Sets attributes that govern aspects of connections
			break;
		SQLCHAR retConString[1024]; // Conection string

		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=temp-minhvq12, 1433; DATABASE=mock_project;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
			// Establishes connections to a driver and a data source
		case SQL_SUCCESS:
			std::cout << "Successfully connected to SQL Server. Ready to update an instance";
			std::cout << "\n";
			break;
		case SQL_SUCCESS_WITH_INFO:
			std::cout << "Successfully connected to SQL Server. Ready to update an instance";
			std::cout << "\n";
			break;
		case SQL_NO_DATA_FOUND:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}

		if (retCode == -1)
			break;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
			// Allocates the statement
			break;
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery_char, SQL_NTS)) {
			// Executes a preparable statement
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else {
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
				retCode = SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery_char, SQL_NTS);
			}
		}
	} while (FALSE);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	std::cout << "Update successfully";

	// Frees the resources and disconnects
	getchar();
}

// ===================================================================================================================================================================================================================

void Database::insertAccounts(std::string account, std::string password) {
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	std::string SQLQuery_str = "INSERT INTO dbo.Accounts ([Account Name], [Password], [Winning Matches], [Losing Matches]) VALUES ('" + account + "', '" + password + "', 0, 0)"; 
	char* SQLQuery_char;
	SQLQuery_char = &SQLQuery_str[0];


	do {
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
			// Allocates the environment
			break;
		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			// Sets attributes that govern aspects of environments
			break;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
			// Allocates the connection
			break;
		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
			// Sets attributes that govern aspects of connections
			break;
		SQLCHAR retConString[1024]; // Conection string

		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=temp-minhvq12, 1433; DATABASE=mock_project;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
			// Establishes connections to a driver and a data source
		case SQL_SUCCESS:
			std::cout << "Successfully connected to SQL Server. Ready to insert";
			std::cout << "\n";
			break;
		case SQL_SUCCESS_WITH_INFO:
			std::cout << "Successfully connected to SQL Server. Ready to insert";
			std::cout << "\n";
			break;
		case SQL_NO_DATA_FOUND:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}

		if (retCode == -1)
			break;
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
			// Allocates the statement
			break;
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery_char, SQL_NTS)) {
			// Executes a preparable statement
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else {
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
				retCode = SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery_char, SQL_NTS);
			}
		}
	} while (FALSE);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	std::cout << "Insert successfully into SQL Server";

	// Frees the resources and disconnects
	getchar();
}

// ===================================================================================================================================================================================================================







