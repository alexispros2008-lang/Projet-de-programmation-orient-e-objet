#include "Boss.h"
#include "mesFonctions.h"

Boss::Boss()
{
	_boss.setPosition(110.f, 25.f);
	_boss.setSize({ 600.f, 250.f });
	initSpriteBoss();
}

void Boss::initSpriteBoss()
{
	static sf::Texture bossTexture;

	verificationTexture(bossTexture, "images\\BossAndBg.png");
	_boss.setTexture(&bossTexture);
	
}

sf::RectangleShape Boss::getBoss()
{
	return _boss;
}
