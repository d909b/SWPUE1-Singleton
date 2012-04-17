//
//  FeatureSingleton.cpp
//  SWPMusterUE1
//
//  Created by Patrick Schwab on 2/29/12.
//  Copyright (c) 2012 Patrick Schwab. All rights reserved.
//

#include "FeatureSingleton.h"

void
FeatureSingleton::addFeature(const Feature* feature)
{
    list_.push_back(feature);
}

void 
FeatureSingleton::saveFeaturesToFile()
{
    QFile saveFile(filepath_);
    
    saveFile.open(QIODevice::WriteOnly);
    
    /** Write each feature in its own line. */
    foreach(const Feature* feature, list_)
    {
        QString data(feature->date.toString() + QString("::") + feature->time.toString() + QString("::") + feature->user + QString("\n"));
        
        
        saveFile.write(data.toStdString().c_str(), data.toStdString().size());
    }
    
    saveFile.close();
}

void
FeatureSingleton::setFilePath(const QString filepath)
{
    filepath_ = filepath;
}