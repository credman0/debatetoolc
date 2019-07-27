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

#include "cite.h"
#include <QFile>
#include <QtDebug>
#include <QtGlobal>
#include "card.h"

QDate Cite::parseDate(QString stringDate)
{
    QDate timeTest;
    for (const QString& dateFormat: dateFormats) {
       timeTest = QDate::fromString(stringDate, dateFormat); 
       if (timeTest.isValid()) {
           return timeTest;
       }
    }
    Q_ASSERT(!timeTest.isValid());
    return timeTest;
}

QList<QString> Cite::readDateFormats()
{
    QFile file("date_formats.txt");
    
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not read date formats";
        return QList<QString>();
    }
        
    QList<QString> retList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QString stringLine = QString::fromLatin1(line);
        retList.append(stringLine.trimmed());
    }
    qDebug() << retList;
    return retList;
    
}

QString Cite::getDisplayContent()
{
    return "<c>"+ Card::sanitizeForHTML(author + " " + date.toString("yy")) + "</c> ("+Card::sanitizeForHTML(otherInfo)+")";
}

const QList<QString> Cite::dateFormats = readDateFormats();
