#include "Boss.h"
#include "mesFonctions.h"

Boss::Boss()
{
	_boss.setPosition(110.f, 25.f);
	_boss.setSize({ 600.f, 250.f });
	initSpriteBoss();
	_timerForNextText.restart();
}

void Boss::initSpriteBoss()
{
	static sf::Texture bossTexture;

	_boss.setSize({ 600.f, 250.f });
	verificationTexture(bossTexture, "images\\BossAndBg.png");
	_boss.setTexture(&bossTexture);
}

void Boss::randomSpriteBoss(std::string randomNumberForBossText)
{
	static sf::Texture bossTexture2;

	std::string pathToBoss = ("images/boss/boss" + randomNumberForBossText + ".png");
	_boss.setSize({ 680.f, 285.f });
	verificationTexture(bossTexture2, pathToBoss);
	_boss.setTexture(&bossTexture2);
}

sf::RectangleShape Boss::getBoss()
{
	std::string randomNumberStringVersion = std::to_string(_randomNumberIntVersion);
	if (_timerForNextText.getElapsedTime() >= sf::seconds(5.f))
	{
		randomSpriteBoss(randomNumberStringVersion);
		if (_timerForNextText.getElapsedTime() >= sf::seconds(20.f)) 
		{
			_randomNumberIntVersion = rand() % 2 + 1;
			_timerForNextText.restart();
			initSpriteBoss();
		}
	}
	return _boss;
}