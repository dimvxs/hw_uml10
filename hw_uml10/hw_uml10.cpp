// hw_uml10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

//Flyweight
//������������� ���������� �������� ����.���������� �����
//���������� ���� ���������, �� ������� ����� ��������� �������
//�������.
//��� ������ ������� ����� ����� ����� :
//� �������� ��� �����������.
//� �������� �����������.
//� ����������� ����.
//� ����� Show, ������� ��������� � �������� ��������� �������
//�������.
//������ ������� ����� ������� ������������� :
//1. ������ ������
//a.�������� 20
//b.���� 10
//2. ������������ ����������
//a.�������� 70
//b.���� 0
//3. ������� �������� ������ �������
//a.�������� 15
//b.���� 150
//4. ������ �������� ������ �������
//a.�������� 50
//b.���� 30
//5. �����������
//a.�������� 300
//b.���� 100
//��� ���� ����� ���������� ��������� ������ ��������,
//���������� ��������� ����������� ������� ���������� �� ������
//�������� �Flyweight�.������� �������, ������ ������� ���� ������
//������� ����� ����, ������ ���������� ����� ����� � ���������� ������
//������
class Sprite {
public:
    string picture;
    int x;
    int y;
};



class MilitaryBase{
protected:
	string name;
    int speed;
    int force;
    Sprite* sprite;
public:
	void Show(Sprite* ref) 
	{
		sprite = ref;
		printf("name: %s, speed: %d, force: %d\picture: %s, x: %d, y: %d\n\n", name.c_str(), speed, force, this->sprite->picture.c_str(), this->sprite->x, this->sprite->y);
	}

};



class LightInfantry : public MilitaryBase
{
public:
	LightInfantry()
	{
		name = "Light Infantry";
		speed = 70;
		force = 0;
	}
};



class TransportCar : public MilitaryBase
{
public:
	TransportCar()
	{
		name = "Transport Car";
		speed = 20;
		force = 10;
	}
};


class HeavyGroundEquipment : public MilitaryBase
{
public:
	HeavyGroundEquipment()
	{
		name = "Heavy Ground Equipment";
		speed = 15;
		force = 150;
	}
};


class LightGroundEquipment : public MilitaryBase
{
public:
	LightGroundEquipment()
	{
		name = "Light Ground Equipment";
		speed = 50;
		force = 30;
	}
};


class Aviation : public MilitaryBase
{
public:
	Aviation()
	{
		name = "Aviation";
		speed = 300;
		force = 100;
	}
};


class CharacterFactory
{
private:
	map<string, MilitaryBase*> characters;
public:
	MilitaryBase* GetCharacter(string key)
	{
		MilitaryBase* character = characters[key];
		if (character == nullptr)
		{
			if (key == "LightInfantry") {
				character = new LightInfantry();
			}

			if (key == "TransportCar") {
				character = new TransportCar();
			}

			if (key == "HeavyGroundEquipment") {
				character = new HeavyGroundEquipment();
			}

			if (key == "LightGroundEquipment") {
				character = new LightGroundEquipment();
			}

			if (key == "Aviation") {
				character = new Aviation();
			}
			
			characters[key] = character;
		}
		return character;
	}
};
int main()
{
	Sprite sprite;
	sprite.x = 7;
	sprite.y = 8;

	string names[5]{ "LightInfantry", "TransportCar", "HeavyGroundEquipment", "LightGroundEquipment", "Aviation" };
	CharacterFactory* pCF = new CharacterFactory();

	for (int i = 0; i < 5; i++)
	{
		sprite.x++;
		sprite.y++;
		MilitaryBase* base = pCF->GetCharacter(names[i]);
		base->Show(&sprite);
	}


	delete pCF;

	return 0;

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
