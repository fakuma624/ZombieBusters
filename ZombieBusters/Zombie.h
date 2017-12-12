#pragma once
#include <d3dx9.h>
#include "DirectGraphics.h"
#include "CharaBase.h"

class Zombie:public CharaBase
{
public:
	Zombie();
	~Zombie();
	void Update();
	void Draw();
	void Control();
	void LifeOrDeath();
	void Animation(CUSTOMVERTEX vertex[]);
	bool GetAlive() { return Alive; }
	bool GetFirstHit() { return FirstHit;}
	void SetFirstHit(bool Hit);
	TEXTURESIZE GetSize() { return Size; }
	D3DXVECTOR2 GetPos() { return WindowPos; }
	int* GetTexture() { return &TextureID; }
	int* ZombieHp() { return &Hp; }
	int* ZombieAtk() { return &Atk; }
	void SetZombieHp(int* Atk);
private:
	int TextureID;
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	D3DXVECTOR2 SpawnPos;//�X�|�[���������W
	TEXTURESIZE Size;
	bool IsRight;
	int Hp;
	int Atk;
	bool IsActive;
	bool Alive;
	bool FirstHit;
	float Speed;
	float ZombieTu = 90.f / 1024.f;
	float ZombieTv = 180.f / 2048.f;
	float const MovingRange = 100;//�ړ��͈�
};

