#include <Windows.h>

#include "token-generation/token.h"
#include "user/user.h"

// without ext libs, this is a pretty basic example in how to gen a unique token for an user on login.
// to make this even more secure you should use crypto++ -> AES to encrypt your data.
// if you use it, make sure that you include proper error handling, security practices and key, iv management

int main() {
	token t;

	std::string username;

	std::cout << "[?] Username: ";
	std::cin >> username;

	std::string token = t.get(username);
	user session(token); // session initialization, you can do this 10x better

	std::cout << session.get_token() << std::endl;

	session.end_session();
}