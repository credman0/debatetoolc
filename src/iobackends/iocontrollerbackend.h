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

#ifndef IOCONTROLLERBACKEND_H
#define IOCONTROLLERBACKEND_H

#include <QtCore>
#include "../core/speechcomponent.h"

/**
 * @todo write docs
 */
class IOControllerBackend
{
public:
    virtual QList<QSharedPointer<SpeechComponent>> fetchDir (QString path) = 0;
};

#endif // IOCONTROLLERBACKEND_H
