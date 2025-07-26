#ifndef __TOC_H__
#define __TOC_H__ 1

#include "auw.h"
#include "obw.h"
#include "cw.h"
#include "ciw.h"

class FirstWidget : public Wt::WContainerWidget
{
public:
    FirstWidget();
    virtual ~FirstWidget();
private:
    Wt::WContainerWidget *background;
    Wt::WContainerWidget *top_title;
    Wt::WImage *logo;
    Wt::WPushButton *menuToggle;
    Wt::WContainerWidget *bContainers;
    Wt::WPushButton *bAboutUs;
    Wt::WPushButton *bOurBreeders;
    Wt::WPushButton *bCats;
    Wt::WPushButton *contact_info;
    Wt::WContainerWidget *linkContainer1;
    Wt::WContainerWidget *textDRX1;
    Wt::WImage *imageDRX1;
    Wt::WContainerWidget *linkContainer2;
    Wt::WContainerWidget *textDRX2;
    Wt::WImage *imageDRX2;
    Wt::WContainerWidget *linkContainer3;
    Wt::WContainerWidget *textDRX3;
    Wt::WImage *imageDRX3;
    // Wt::WContainerWidget *lower_title;
};

#endif