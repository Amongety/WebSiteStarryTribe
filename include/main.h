#ifndef __MAIN_H__
#define __MAIN_H__ 1

#include "../modules/include/toc.h"

class MainApplication : public Wt::WApplication
{
public:
    MainApplication(const Wt::WEnvironment& env);
private:
    void handleInternalPathChange();
};

#endif