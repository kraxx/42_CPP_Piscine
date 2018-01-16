#include <ctime>
#include <iostream>
#include <string>

struct Data {
	std::string s1;
	int			n;
	std::string s2;
};

void* serialize(void) {

	char const AlNum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	Data *d = new Data();
	d->s1 = "";
	d->s2 = "";

	for (int i = 0; i < 8; i++) {
		d->s1 += AlNum[rand() % 62];
	}
	d->n = rand() % 10;
	for (int i = 0; i < 8; i++) {
		d->s2 += AlNum[rand() % 62];
	}
	return reinterpret_cast<void*>(d);
}

Data* deserialize(void* raw) {

	return reinterpret_cast<Data*>(raw);
}

int main(void) {

	srand(time(nullptr));

	void* v = serialize();
	
	std::cout << "Serialized: " << v << std::endl;

	Data* d = deserialize(v);

	std::cout << "Deserialized: " << d->s1 << d->n << d->s2 << std::endl;

	delete d;

}