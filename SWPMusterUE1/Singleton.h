//
//  Singleton.h
//  SWPMusterUE1
//
//  Created by Patrick Schwab on 2/29/12.
//  Copyright (c) 2012 Patrick Schwab. All rights reserved.
//

#pragma once

#include <QtCore/qmutex.h>

template<typename T>
class Singleton
{
public:
    static T* getInstance ()
    {
        mutex_.lock();
        if (instance_ == 0)
        {
            instance_ = new T();
        }
        mutex_.unlock();
        
        return instance_;
    }
    
    virtual ~Singleton ()
    {
        instance_ = 0;
    }
private:
    static T* instance_;
    static QMutex mutex_;
protected:
    Singleton () {;}
};
template<typename T> T* Singleton<T>::instance_ = 0;
template<typename T> QMutex Singleton<T>::mutex_;