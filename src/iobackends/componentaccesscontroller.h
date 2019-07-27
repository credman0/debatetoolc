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

#ifndef COMPONENTACCESSCONTROLLER_H
#define COMPONENTACCESSCONTROLLER_H

#include <QtCore>
#include "../core/speechcomponent.h"
#include "filesystem/filesystemiocontrollerbackend.h"

/**
 * @todo write docs
 */
class ComponentAccessController
{
public:
    static QList<QSharedPointer<SpeechComponent>> fetchDir(QString path);
    ~ComponentAccessController();
private:
    QHash<uuid, QSharedPointer<SpeechComponent>> cache;
    IOControllerBackend* backend;
    static ComponentAccessController* instance()
    {
        static ComponentAccessController* me = nullptr;
        if (!me) {
            IOControllerBackend* backend = new FileSystemIOControllerBackend();
            me = new ComponentAccessController(backend);
        }
        return me;
    }
    ComponentAccessController(IOControllerBackend* backend);
    
};

#endif // COMPONENTACCESSCONTROLLER_H
