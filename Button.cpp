#include "Button.h"
#include "Game.h"
#include "Sounds.h"
#include "Sprites.h"
#include <QMediaPlayer>
#include <QKeyEvent>

using namespace PGG;


Button::Button(QRect pos, ButtonType bt) : QLabel(0)
{
	_buttonType = bt;
	connect(this, SIGNAL(clicked()), this, SLOT(slotLabelClicked()), Qt::QueuedConnection);
	Game::instance()->getCharacterHandler()->initButton(_buttonType, this);

	setGeometry(pos);
	setStyleSheet("background-color: transparent;");
	Game::instance()->world()->addWidget(this);
	
}


 void Button::slotLabelClicked()   
 {
	 Game::instance()->_gameSounds->get("button")->play();
	 Game::instance()->getCharacterHandler()->clickButton(_buttonType, this);
 }

 void Button::mousePressEvent(QMouseEvent* e) {
	 QLabel::mousePressEvent(e);
	 emit clicked();
 }
