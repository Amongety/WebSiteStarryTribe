#ifndef __AUW_H__
#define __AUW_H__ 1

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>

class AboutWidget : public Wt::WContainerWidget
{
public:
    AboutWidget();
    virtual ~AboutWidget();
private:
    Wt::WContainerWidget *background;
    Wt::WText *title_text;
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
};

#endif