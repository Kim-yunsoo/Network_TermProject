#pragma once
#include "pch.h"

//extern CatAttack catattack[AnimCnt];
//extern DogAttack dogattack[AnimCnt];
//extern BearAttack bearattack;

class Hero
{

	bool firstmap;
	/// <summary>
	/// ī�޶� �����մϴ�.
	/// </summary>




public:
	bool _flag = true;

	bool catlive;
	bool doglive;
	bool bearlive;
	bool herodead;

	int ID;
	int HP;
	float PosX;
	float PosY;
	float PosZ;
	float lightColorR = 1.0f;
	float lightColorG = 1.0f;
	float lightColorB = 1.0f;
	float VAngleX = 1;
	float VAngleY = 1;
	Hero(int id);
	~Hero();
	void ISW();
	void ISA();
	void ISS();
	void ISD();
	void damage();
	void Update();
	int InfoHP();
	void location();
	void isQuit();
	float getLeft();
	float getRight();
	float getBehind();
	float getFront();
	//void VAngleMotion(int x, int y);
	void initHero();
	float getPosX() const { return PosX; }
	float getPosZ() const { return PosZ; }
	/*friend void HeroVSDog();
	friend void HeroVSBear();
	friend void HeroVSCat();*/
	///////////////ī�޶� �����մϴ�.///////////////

};