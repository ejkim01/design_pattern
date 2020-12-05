/*
	Convert the interface of a class into another interface that clients expect. 
	Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.
*/
#include <iostream>
#include <memory>

class Dog {	// Abstract Target
public:
	virtual ~Dog() = default;
	virtual void performsConversion() const = 0;
};

class DogFemale : public Dog {	// Abstract Adaptee
public:
	virtual void performsConversion() const override {
		std::cout << "Dog female performs conversion." << std::endl;
	}
};

class Cat {	// Abstract Target
public:
	virtual ~Cat() = default;
	virtual void performsConversion() const = 0;
};

class CatFemale : public Cat {	// Abstract Adaptee
public:
	virtual void performsConversion() const override {
		std::cout << "Cat female performs conversion." << std::endl;
	}
};

class DogNature {
public:
	void carryOutNature(shared_ptr<Dog> dog) {
		std::cout << "On with the Dog nature!" << std::endl;
		dog->performsConversion();
	}
};

class ConversionAdapter : public Dog {	// Adapter
private:
	shared_ptr<Cat> cat;
public:
	ConversionAdapter(shared_ptr<Cat> c) : cat(c) {}
	virtual void performsConversion() const override { cat->performsConversion(); }
};

int main() {
	shared_ptr<DogFemale> dogFemale = make_shared<DogFemale>();
	shared_ptr<CatFemale> catFemale = make_shared<CatFemale>();
	DogNature dogNature;
	// dogNature.carryOutNature(catFemale);	// Will not compile of couorse since the parameter must be of type Dog*
	shared_ptr<ConversionAdapter> adaptedCat = make_shared<ConversionAdapter>(catFemale);   // catFemale has adapted to become a Dog!

	dogNature.carryOutNature(dogFemale);
	dogNature.carryOutNature(adaptedCat);	// So now catFemale, in the form of adaptedCat, participates in the dogNature!
	// Note that catFemale is carrying out her own type of nature in dogNature though.
}
