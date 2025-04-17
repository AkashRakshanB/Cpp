#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include<string>
class Encryption {
private:
	int key = 6;
public:
	std::string encrypt(std::string& data);
	std::string decrypt(std::string& data);
};
#endif // !ENCRYPTION_H
