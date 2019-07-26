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

#include "card.h"

QString Card::getLabel()
{
    return getActiveTag()+"\n"+cite.author+" "+cite.date.toString("yy");
}

QString Card::getDisplayContent()
{
        // the overlay sanitizes the text, so don't encode it a second time
        return cite.getDisplayContent()+"<br>"+getActiveOverlay().generateHTML(text);
    
}

QString Card::sanitizeForHTML(QString plaintext)
{
    // TODO implementation
    return plaintext;
}

CardOverlay Card::getActiveOverlay()
{
    
}

QString Card::getActiveTag()
{
    return "Hello active tag";
}

