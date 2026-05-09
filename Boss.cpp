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
		_bossText.setString("I'm snow\nexcited for\nwinter!");
	}
	else if (_randomEventText == 2)
	{
		_bossText.setString("Snow doubt\nabout it, I'm\nchillin'.");
	}
	else if (_randomEventText == 3)
	{
		_bossText.setString("Snow way,\nthat's\nhilarious!");
	}
	else if (_randomEventText == 4)
	{
		_bossText.setString("Snow excited\nto see\nyou!");
	}
	else if (_randomEventText == 5)
	{
		_bossText.setString("Snowbody\ncompares to\nyou.");
	}
	else if (_randomEventText == 6)
	{
		_bossText.setString("Chill vibes\nonly.");
	}
	else if (_randomEventText == 7)
	{
		_bossText.setString("Cold enough\nCold enough\nto pun yet?");
	}
	else if (_randomEventText == 8)
	{
		_bossText.setString("Snow kidding\naround.");
	}
	else if (_randomEventText == 9)
	{
		_bossText.setString("Ice to\nsee your\njokes.");
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
			_randomEventText = rand() % 9 + 1;
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
