#pragma once
#include <iostream>
#include <string>
#include <ctime>

class token
{
public:
	std::string xor_encrypt(const std::string& input, const std::string& key);
	std::string get(const std::string& token);
	unsigned long hash(const std::string& str);
};

