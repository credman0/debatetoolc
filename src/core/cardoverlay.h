/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2019  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CARDOVERLAY_H
#define CARDOVERLAY_H

#include <QtCore>

/**
 * @todo write docs
 */
class CardOverlay
{
public:
    static const uchar HIGHLIGHT = 0x1<<0;
    static const uchar UNDERLINE = 0x1<<1;

    QString generateHTML(QString plaintext);
    void setOverlay(quint32 start, quint32 end, uchar overlayType);
    CardOverlay operator+(const CardOverlay& other) const;
private:
    QString name;
    QList<quint16> overlayPositions;
    QList<uchar> overlayTypes;
    
    void splitOverlay(quint32 index, quint32 position);
    
    /** Add new content to the end of the overlay list */
    void addOverlay(quint16 length, uchar type);
    
    static const quint16 MAX_QUINT16;
};

#endif // CARDOVERLAY_H
