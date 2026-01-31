#include "Bandit.h"

Bandit::Bandit() : Monster()
{
	this->state = banditState::WAITING;
}

Bandit::Bandit(string nName) : Monster(nName)
{
	this->state = banditState::WAITING;
}

void Bandit::update(Player& currPlayer)
{

	if (this->state == banditState::WAITING) {
		if (currPlayer.isAlive()) {
			this->state = banditState::AIMING;
			cout << "[info]: " << this->name << " is aiming..." << endl;
		}
	}
	else if (this->state == banditState::AIMING) {
		if (currPlayer.isAlive()) {
			this->state = banditState::SHOOTING;
			cout << "[info]: " << this->name << " is preparing to shoot..." << endl;
		}
		else {
			this->state = banditState::WAITING;
			cout << "[info]: " << this->name << " is waiting..." << endl;
		}
	}
	else if (this->state == banditState::SHOOTING) {
		if (currPlayer.isAlive()) {
			currPlayer.damage(50);
			cout << "[attack]: " << this->name << " has attacked " << currPlayer.getName() << " for 50." << endl;
			this->state = banditState::AIMING;
		}
		else {
			this->state = banditState::AIMING;
		}
	}
}
