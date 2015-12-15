#include"Boss.h"

void Boss::PassAnotherYear() {
	HP = std::max(TotalHP, HP + (TotalHP / 20));
	//you should change this amount
	TotalHP -= 10;
	//you should change this amount, remove this line after you done
	PhysicalDamage -= 1;
}