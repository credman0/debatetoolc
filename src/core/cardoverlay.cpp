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

#include "cardoverlay.h"
#include <QStringBuilder>
#include <cstdint>
#include "card.h"

QString CardOverlay::generateHTML(QString plaintext)
{
    QString htmlBuilder;
    quint32 position = 0;
    for (quint32 i = 0; i < overlayPositions.size(); i++){
        uchar type = overlayTypes[i];
        bool highlight = (type&HIGHLIGHT)!=0;
        bool underline = (type&UNDERLINE)!=0;
        if (highlight){
            htmlBuilder= htmlBuilder % "<h>";
        }
        if (underline){
            htmlBuilder= htmlBuilder % ("<u>");
        }
        htmlBuilder.append(Card::sanitizeForHTML(plaintext.mid(position,position+overlayPositions[i])));
        if (underline){
            htmlBuilder= htmlBuilder %("</u>");
        }
        if (highlight){
            htmlBuilder= htmlBuilder %("</h>");
        }
        position+=overlayPositions[i];
    }
    htmlBuilder.append(Card::sanitizeForHTML(plaintext.mid(position)));
    return htmlBuilder;
}
const quint16 CardOverlay::MAX_QUINT16 = std::numeric_limits<quint16>::max();
void CardOverlay::setOverlay(quint32 start, quint32 end, uchar overlayType)
{
    quint32 position = 0;
    quint32 overlayIndex = 0;
    while (position<start){
        if (overlayIndex<overlayPositions.size()){
            position+=overlayPositions[overlayIndex];
            overlayIndex++;
        }else{
            if (start-position <= MAX_QUINT16){
                quint16 distance = (start-position);
                addOverlay(distance, 0);
                position+=distance;
            }else{
                quint16 distance = MAX_QUINT16;
                addOverlay(distance, 0);
                position+=distance;
            }
            overlayIndex++;
        }
    }
    if (position>start) {
        // in this case we have gone past the start, and we need to at least split the previous element
        
        // calculate the absolute starting position of the previous element
        quint32 splitPosition = position-overlayPositions[overlayIndex-1];
        
        // now subtract from where we want to start
        splitPosition = start - splitPosition;
        
        // the result is the relative distance from the start of the element where we want a split
        
        splitOverlay(overlayIndex-1, splitPosition);
        
        // now our overlayIndex points to our first element, as it should, but we need to correct the position
        position = start;
    }
    
    // at this point, we expect the overlayIndex to point to an element within our range, and position to be at
    // our range start point
    uchar oldType = 0x0;
    while (position<end){
        if (overlayIndex < overlayPositions.size()){
            position+=overlayPositions[overlayIndex];
            oldType = overlayTypes[overlayIndex];
            overlayTypes[overlayIndex] = (oldType|overlayType);
            overlayIndex++;
        }else{
            if (end-position <= MAX_QUINT16){
                quint16 distance = (end-position);
                addOverlay(distance,overlayType);
                position+=distance;
            }else {
                quint16 distance = MAX_QUINT16;
                addOverlay(distance,overlayType);
                position += distance;
                overlayIndex++;
            }
        }
    }
    
    // if we overshot, we need to split the end and revert the elements past our end to our old overlayType
    if (position>end){
        // calculate the absolute starting position of the previous element
        quint32 splitPosition = position-overlayPositions[overlayIndex-1];
        
        // now subtract from where we want to end
        splitPosition = end - splitPosition;
        
        // the result is the relative distance from the start of the element where we want a split
        
        splitOverlay(overlayIndex-1, splitPosition);
        
        overlayTypes[overlayIndex] = oldType;
    }
}

void CardOverlay::addOverlay(quint16 length, uchar type)
{
    overlayPositions.append(length);
    overlayTypes.append(type);
}

void CardOverlay::splitOverlay(quint32 index, quint32 position)
{
        quint32 originalElement = overlayPositions[index];
        quint32 firstElement = position;
        quint32 secondElement = originalElement-position;
        uchar type = overlayTypes[index];

        overlayPositions.replace(index, secondElement);
        overlayPositions.insert(index, firstElement);

        overlayTypes.insert(index, type);
}




