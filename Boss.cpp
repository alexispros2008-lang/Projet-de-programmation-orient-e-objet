#include "Boss.h"
#include "mesFonctions.h"

Boss::Boss()
{
	initSpriteBoss();
	initTextBoss();
	_timerForNextText.restart();
}

void Boss::initSpriteBoss()
{
	_boss.setPosition(110.f, 25.f);
	_boss.setSize({ 590.f, 255.f });
	verificationTexture(_bossTextureWithText, "images/BossAndBgAndText.png");
	verificationTexture(_bossTexture, "images\\BossAndBg.png");
	_boss.setTexture(&_bossTexture);
}

void Boss::initTextBoss()
{
	verificationFont(_textboxBossFont, "fonts\\PixelOperator8-bold.ttf");
	_bossText.setFont(_textboxBossFont);
	_bossText.setCharacterSize(12);
	_bossText.setFillColor(sf::Color::Black);
	_bossText.setPosition(215, 140);
}

void Boss::randomTextBoss(int randomEventText)
{
	if (_randomEventText == 1) 
	{
		_bossText.setString("Snow joke \n"
			"here1...");
	}
	else if (_randomEventText == 2)
	{
		_bossText.setString("Snow joke here2...");
	}
}

sf::RectangleShape Boss::getBoss()
{
	if (_timerForNextText.getElapsedTime() >= sf::seconds(5.f))
	{
		if (!_hasChanged)
		{
			randomTextBoss(_randomEventText);
			_hasChanged = true;
			_boss.setTexture(&_bossTextureWithText);
		}
		if (_timerForNextText.getElapsedTime() >= sf::seconds(20.f)) 
		{
			_randomEventText = rand() % 2 + 1;
			_timerForNextText.restart();
			_bossText.setString(" ");
			_boss.setTexture(&_bossTexture);
			_hasChanged = false;
		}
	}
	return _boss;
}

sf::Text& Boss::getBossText()
{
	return _bossText;
}
