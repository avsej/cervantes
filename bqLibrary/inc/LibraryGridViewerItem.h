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

#ifndef LIBRARYGRIDVIEWERITEM_H
#define LIBRARYGRIDVIEWERITEM_H

#include "GestureWidget.h"
#include "Library.h"
// Predeclarations
class BookInfo;
class QFileInfo;

class LibraryGridViewerItem : public GestureWidget
{
    Q_OBJECT

private:
    enum ELibraryGridViewerItemType {
        ELGVIT_BOOK,
        ELGVIT_FILE,
        ELGVIT_ARROW,
        ELGVIT_COLLECTION
    };
public:
                                        LibraryGridViewerItem               ( QWidget* parent );
    virtual                             ~LibraryGridViewerItem              ();

    virtual void                        setBook                             ( const BookInfo* book, Library::ELibraryFilterMode filter) { m_iType = ELGVIT_BOOK; }
    virtual void                        setFile                             ( const QFileInfo* file ) { m_iType = ELGVIT_FILE; }
    virtual void                        setArrow                            ( const QString& path ) { m_iType = ELGVIT_ARROW; }
    virtual void                        setCollection                       ( const QString&, int) { m_iType = ELGVIT_COLLECTION; }

    virtual void                        select                              () = 0;
    virtual void                        unselect                            () = 0;

    const QString&                      getPath                             () const { return m_path; }

public slots:
    void                                processTap();
    void                                processLongpress();

signals:
    void                                itemClicked                         ( const QString& path );
    void                                itemLongPress                       ( const QString& path );
    void                                fileLongPressed                     ( const QString& path );

protected:
    QString                             m_path;
    ELibraryGridViewerItemType          m_iType;
};

#endif // LIBRARYGRIDVIEWERITEM_H
