#include "token.h"

unsigned long token::hash(const std::string& str) {
	unsigned long hash = 5381;

	for (char c : str) {
		hash = ((hash << 5) + hash) + c;
	}

	return hash;
}

std::string token::xor_encrypt(const std::string& input, const std::string& key) {
	std::string e = input;

	for (size_t i = 0; i < input.size(); i++) {
		e[i] = input[i] ^ key[i % key.size()];
	}

	return e;
}

std::string token::get(const std::string& token) {
	time_t now = time(0);

	tm* ltm = localtime(&now);
	int hour = ltm->tm_hour;

	std::string data = std::to_string(hour) + token;
	std::string key = "randomkey";

	std::string encrypted = xor_encrypt(data, key);
	unsigned long hashed = hash(encrypted);

	return std::to_string(hashed);
}