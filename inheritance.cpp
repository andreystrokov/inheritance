#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Animal {
public:
    Animal (const string& type): type_(type) {

    };
    void Eat (const string& fruit){
        cout << type_ << " eats " << fruit << endl;
    }
    virtual void Voice() const = 0;
private:
    const string type_;
};

class Cat : public Animal {
public:
    Cat (): Animal("Cat"){
    }
    void Voice() const override {
        cout << "Meow!" << endl;
    }
};
class Dog : public Animal{
public:
    Dog () : Animal("Dog"){
    }
    void Voice() const override {
        cout << "Whaf!" << endl;
    }
};
class Parrot : public Animal {
public:
    Parrot (const string& name) : Animal("parrot"),name_(name){
    }
    void Voice() const override {
        cout << name_ << " is good!" << endl;
    }
private:
    const string name_;
};
class Horse : public Animal {
public:
    Horse () : Animal("horse") {
    }
    void Voice() const override {
        cout << type_ << " is silent!" << endl;
    }

};
void MakeSound (const Animal& a){
    a.Voice();
}
int main(){

Cat c;
Dog d;
Parrot p("Kesha");

    vector <shared_ptr<Animal>> animals = {
            make_shared<Parrot>("Ivan"),
            make_shared<Cat>(),
            make_shared<Dog>()
    };
    for (const auto& a : animals){
        MakeSound(a);
    }
return 0;
}
