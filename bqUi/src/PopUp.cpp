/*************************************************************************

bq Cervantes e-book reader application
Copyright (C) 2011-2013  Mundoreader, S.L

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the source code.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/

#include "PopUp.h"
#include "QBook.h"
#include "Screen.h"
#include "QBookApp.h"
#include <QDebug>
#include <QWidget>
#include <QMouseEvent>


PopUp::PopUp(QWidget *parent) :
    QWidget(parent)
{
    qDebug() << "--->" << Q_FUNC_INFO;
}

PopUp::~PopUp()
{
    /// Do nothing
    qDebug() << "--->" << Q_FUNC_INFO;
}

void PopUp::mousePressEvent(QMouseEvent* event){
    qDebug() << "--->" << Q_FUNC_INFO;

    event->accept();
}

void PopUp::keyReleaseEvent(QKeyEvent* event)
{
    qDebug() << Q_FUNC_INFO << event;
    switch(event->key()){

    case QBook::QKEY_BACK:


        Screen::getInstance()->setMode(Screen::MODE_QUICK,false,Q_FUNC_INFO);
        emit hideMe();
        event->accept();
        break;
    default:
        QWidget::keyReleaseEvent(event);
        break;
    }
}
