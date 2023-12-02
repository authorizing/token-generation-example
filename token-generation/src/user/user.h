#pragma once
#include <string>

class user {
private:
	std::string user_token;
public:
	user(const std::string& str) : user_token(str) {}

	std::string get_token() const {
		return user_token;
	}

	void end_session() {
		user_token.clear();
	}
};