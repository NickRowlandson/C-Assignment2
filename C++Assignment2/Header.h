#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <regex>
#include <cstdlib>

using namespace std;
vector<string> lines, lines2;

// HighScoreManager class
class HighScoreManager {
public:
	//HighScoreManager();
	void PrintHighScore();
	void UpdateScoreVector();

private:
	string username;
	int score;
	string date;
};

// User class
class User {
public:
	//User();
	void Login();
	bool CheckIfUserExist(string);
	void UpdateUserVector();
	void UpdateUserInfo();
	bool DeleteUser();
	void SetHighScore();
	void ViewUserInfo();

private:
	string username;
	string firstNameLastName;
};

#endif