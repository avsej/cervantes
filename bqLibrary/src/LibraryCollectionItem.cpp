/*************************************************************************

bq Cervantes e-book reader application
Copyright (C) 2011-2016  Mundoreader, S.L

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

#include <QPainter>
#include <QDebug>
#include "GestureWidget.h"
#include "QBook.h"
#include "LibraryCollectionItem.h"

#define CHECKED "background: url(':/res/check-collection.png') no-repeat center right; border-bottom: 2px dotted #B0B0B0;"
#define UNCHECKED "background:none; border-bottom: 2px dotted #B0B0B0;"
#define HIDE_BORDER "background:none; border-bottom: 2px #FFF;"

LibraryCollectionItem::LibraryCollectionItem(QWidget *parent) : GestureWidget(parent)
  , m_itemText("")
  , m_id(-1)
{
        setupUi(this);
        connect(this,SIGNAL(tap()),this,SLOT(processTap()));
        collectionTitleLbl->setText("");
        m_checkWidth = 0;
        switch(QBook::getInstance()->getResolution())
        {
            case QBook::RES1072x1448:
                m_checkWidth = 56;
                break;
            case QBook::RES758x1024:
                m_checkWidth = 40;
                break;
            case QBook::RES600x800: default:
                m_checkWidth = 35;
                break;
        }
}

LibraryCollectionItem::~LibraryCollectionItem(){
    // do nothing
}

void LibraryCollectionItem::paintEvent (QPaintEvent *){
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
        QFontMetrics fontMetrics = p.fontMetrics();
        QString text = fontMetrics.elidedText(m_itemText, Qt::ElideRight, collectionTitleLbl->width()-m_checkWidth);
        p.drawText(10, collectionTitleLbl->y(), collectionTitleLbl->width() - (m_checkWidth-10), collectionTitleLbl->height(), Qt::AlignVCenter, text);
}

void LibraryCollectionItem::paintCollection(const QString &collectionName, const int id)
{
    qDebug() << Q_FUNC_INFO;
    m_itemText = collectionName;
    m_id = id;
}

void LibraryCollectionItem::processTap()
{
    qDebug() << Q_FUNC_INFO;
    if(m_itemText != "")
        emit tap(m_id);
}

void LibraryCollectionItem::setChecked(bool checked)
{
    if (checked && !m_itemText.isEmpty())
        collectionTitleLbl->setStyleSheet(CHECKED);
    else if (!checked && !m_itemText.isEmpty())
        collectionTitleLbl->setStyleSheet(UNCHECKED);
    else
        collectionTitleLbl->setStyleSheet(HIDE_BORDER);
}
