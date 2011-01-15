// Copyright 2008-2011 Zhang Yun Gui, rhcad@hotmail.com
// http://sourceforge.net/projects/x3c/

// author: Zhang Yun Gui
// v2: 2011.1.5, change to hash_multimap

#ifndef _X3_CORE_CHANGEMANAGER_H
#define _X3_CORE_CHANGEMANAGER_H

#include <Ix_ChangeManager.h>

#if _MSC_VER > 1200 // not VC6
    #include <hash_map>
    using stdext::hash_multimap;
#else
    #define hash_multimap std::multimap
#endif

class Cx_ChangeManager : public Ix_ChangeManager
{
protected:
    Cx_ChangeManager();
    virtual ~Cx_ChangeManager();

protected:
    virtual void RegisterObserver(const char* type, Ix_ChangeObserver* observer);
    virtual void UnRegisterObserver(const char* type, Ix_ChangeObserver* observer);
    virtual void ChangeNotify(const char* type, ChangeNotifyData* data);

private:
    typedef hash_multimap<std::string, Ix_ChangeObserver*> ObserverMap;
    typedef std::pair<std::string, Ix_ChangeObserver*> ObserverPair;
    typedef ObserverMap::iterator MAP_IT;
    ObserverMap     m_observers;
};

#endif // _X3_CORE_CHANGEMANAGER_H
