#include "Boss.h"
#include "mesFonctions.h"

Boss::Boss()
{
	_boss.setPosition(300.f, 50.f);
	_boss.setSize({ 200.f, 200.f });
	initSpriteBoss();
}

void Boss::initSpriteBoss()
{
	static sf::Texture bossTexture;

	verificationTexture(bossTexture, "images\\Snowman.png");
	_boss.setTexture(&bossTexture);
	
}

sf::RectangleShape Boss::getBoss()
{
	return _boss;
}
