#include "encryption.h"

std::string Encryption::encrypt(std::string& value) {
	std::string data = value;
	for (int i = 0; data[i] != '\0'; i++) {
		data[i] += key;
	}
	return data;
}
std::string Encryption::decrypt(std::string& value) {
	std::string data = value;
	for (int i = 0; data[i] != '\0'; i++) {
		data[i] -= key;
	}
	return data;
}