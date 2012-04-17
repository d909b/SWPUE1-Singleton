//
//  FeatureSingleton.h
//  SWPMusterUE1
//
//  Created by Patrick Schwab on 2/29/12.
//  Copyright (c) 2012 Patrick Schwab. All rights reserved.
//

#pragma once

#include "Singleton.h"
#include <vector>
#include <string>
#include <QtCore/qstring.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qfile.h>

class Feature 
{
public:
    Feature() :
        user(""),
        date(QDate::currentDate()),
        time(QTime::currentTime())
    {;}
    
    QString user;
    QDate date;
    QTime time;
};

class FeatureSingleton : public Singleton<FeatureSingleton>
{
public:
    void addFeature(const Feature* feature);
    void saveFeaturesToFile();
    void setFilePath(const QString filepath);
private:
    std::vector<const Feature*> list_;
    QString filepath_;
};