#include <iostream>
#include <string>

namespace game {
	int damage;
	std::string type;
}

class Weapon {
private:
	int damage;
	char* type;
public:
	Weapon(int damage, char* type)
	{
		this->damage = damage;
		this->type = new char[strlen(type) + 1];
		strcpy_s(this->type, strlen(type) + 1, type);
	}

	int getDamage() { return this->damage; }
	void setDamage(int damage) { this->damage = damage; }

	char* getType() { return this->type; }
	
	void setType(char* type) 
	{ 
		delete this->type;
		this->type = new char[strlen(type) + 1];
		strcpy_s(this->type, strlen(type)+1, type); 
	}

	void showInfo(){
		std::cout << "Damage: " << this->damage;
		std::cout << "\nType: " << this->type;
	}

	void save() {
		game::damage = this->damage;
		game::type = this->type;
	}

};

int main()
{
	Weapon* Sword = new Weapon(12, (char*)("Excalibur"));

	Sword->showInfo();
	Sword->save();
	std::cout << "\n" << game::damage;//saved info

	Sword->setDamage(30);
	std::cout << "\n" << game::damage;//previous info 

	Sword->save();
	std::cout << "\n" << game::damage;//new saved info 
	

}

