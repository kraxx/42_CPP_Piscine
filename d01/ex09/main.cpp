#include "Logger.hpp"

int main() {

	Logger log("testoOutputo");

	log.log("console", "diddly doo");
	log.log("file", "hippity hop");
	log.log("file", "swiggity swag");
	log.log("console", "criminey crikey");
	return 0;
};
