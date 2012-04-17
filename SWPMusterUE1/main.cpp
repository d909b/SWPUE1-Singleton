//
//  main.cpp
//  SWPMusterUE1
//
//  Created by Patrick Schwab on 3/5/12.
//  Copyright (c) 2012 Patrick Schwab. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include "FeatureSingleton.h"

int main (int argc, const char * argv[])
{
    FeatureSingleton* instance = FeatureSingleton::getInstance();
    
    instance->setFilePath("/Users/patrick/Desktop/test");
    instance->addFeature(new Feature());
    instance->saveFeaturesToFile();
    
    return EXIT_SUCCESS;
}

