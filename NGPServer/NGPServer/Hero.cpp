#include "pch.h"
#include <cmath>

extern bool catlive;
extern bool doglive;
extern bool bearlive;
extern bool herodead;
extern float HeroLocationX;
extern float HeroLocationZ;

extern Attack catattack[AnimalMax];
extern Attack dogattack[AnimalMax];
extern Attack bearattack;

extern vector<Animal*> AniCats;
extern vector<Animal*> AniDogs;
extern Animal AniBear;

Hero::Hero(int id) : ID{id}
{
	PosX = 0;
	PosY = 0.5;
	PosZ = 10.0;
	HP = 100;
	firstmap = true;
}

Hero::~Hero()
{

}

void Hero::damage()
{

	HP = 100;
	lightColorG = 1.0;
	lightColorB = 1.0;
	for (int i = 0; i < 6; ++i) {
		HP -= (catattack[i].AttackCount) * 10 / 24;
		lightColorG -= catattack[i].AttackCount * 0.1f / 24.;
		lightColorB -= catattack[i].AttackCount * 0.1f / 24.;

		HP -= (dogattack[i].AttackCount) * 20 / 24;
		lightColorG -= dogattack[i].AttackCount * 0.2f / 24.;
		lightColorB -= dogattack[i].AttackCount * 0.2f / 24.;
	}


	HP -= (bearattack.AttackCount) * 30 / 24;
	lightColorG -= bearattack.AttackCount * 0.3f / 24.;
	lightColorB -= bearattack.AttackCount * 0.3f / 24.;


	if (lightColorG < 0.1) {
		herodead = true;
		lightColorB = 0.1;
		lightColorG = 0.1;
		lightColorR = 0.1;
	}
}



int Hero::InfoHP() {
	return HP / 10;
}

void Hero::Update()
{

	damage();

	

	if (PosX < -1 && firstmap)
	{
		PosX += 0.1;
	}
	if (PosX > 1 && firstmap)
	{
		PosX -= 0.1;
	}

	if (PosZ > 11 && firstmap)
	{
		PosZ -= 0.1;
	}


	if (PosZ < -10 && firstmap) {
		PosX = -100;
		PosZ = 0;
		catlive = true;
		bearlive = false;
		doglive = false;
		firstmap = false;
	}
	if (PosZ < -7 && catlive) {
		PosX = 100;
		PosZ = 0;
		catlive = false;
		doglive = true;
		bearlive = false;

	}
	if (PosZ < -7 && doglive) {
		PosX = 0;
		PosZ = -100;

		doglive = false;
		catlive = false;
		bearlive = true;
	}


}


void Hero::location()
{

	HeroLocationX = PosX;
	HeroLocationZ = PosZ;
}

void Hero::isQuit()
{
	_flag = false;
}

void Hero::ISW()
{
	float radians = VAngleY * PI / 180.0f;

	PosZ -= 0.2 * cos(radians);
	PosX += 0.2 * sin(radians);

}

void Hero::ISA()
{
	float radians = VAngleY * PI / 180.0f;

	PosZ -= 0.2 * sin(radians);
	PosX -= 0.2 * cos(radians);

}

void Hero::ISS()
{
	float radians = VAngleY * PI / 180.0f;
	PosZ += 0.2 *cos(radians);
	PosX -= 0.2 *sin(radians);
}

void Hero::ISD()
{
	float radians = VAngleY * PI / 180.0f;

	PosZ += 0.2 * sin(radians);
	PosX += 0.2 * cos(radians);
}

float Hero::getLeft()
{
	return PosX - 0.12f;
}

float Hero::getRight()
{
	return PosX + 0.12f;
}

float Hero::getBehind()
{
	return PosZ - 0.12f;
}

float Hero::getFront()
{
	return PosZ + 0.12f;
}



//void Hero::VAngleMotion(int x, int y)
//{
//	VAngleY += (x - 1000 / 2) / 12.5;
//
//
//	VAngleX += (y - 800 / 2) / 12.5;
//	if (VAngleX >= 15.f) {
//		VAngleX = 15.f;
//	}
//	else if (VAngleX <= -15.f) {
//		VAngleX = -15.f;
//	}
//}

void Hero::initHero()
{

	PosX = 0;
	PosY = 0.5;
	PosZ = 10.0;

	HP = 100;

	lightColorR = 1.0f;
	lightColorG = 1.0f;
	lightColorB = 1.0f;


	VAngleX = 0;
	VAngleY = 0;
	firstmap = true;
}
