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

#ifndef SPEECHCOMPONENTCONTAINER_H
#define SPEECHCOMPONENTCONTAINER_H

#include "speechcomponent.h"

/**
 * @todo write docs
 */
class SpeechComponentContainer : SpeechComponent
{
public:
    SpeechComponentContainer(bool isSpeech);
    
    ~SpeechComponentContainer();
    
    
    /**
     * Maps integers to an alphabetic representaion, ie 0 = a, 1 = b, ..., 26 = z, 27 = aa, 28 = ab,...
     * 
     * @return An alphabetic (string) representation of the integer
     */
    static QString toAlphabet(int i)
    {
        if (i<0){
            return QStringLiteral("");
        }else {
            return toAlphabet((i / 26) - 1) + (char)(65 + i % 26);
        }
    }
    
    bool operator==(const SpeechComponentContainer& other)
    {
        return components == other.components;
    }
    
    void operator+(SpeechComponent* component)
    {
        components.append(QSharedPointer<SpeechComponent>(component));
    }
    virtual QString getDisplayContent() = 0;
    virtual QString getLabel() = 0;
    
protected:
    QString getEnumeration(quint32 idx)
    {
        return idx +"";
    }
    
    QList<QSharedPointer<SpeechComponent>> components;
    QString name;
    
    
};

#endif // SPEECHCOMPONENTCONTAINER_H
