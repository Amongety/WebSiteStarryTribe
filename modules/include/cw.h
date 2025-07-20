#ifndef __CW_H__
#define __CW_H__ 1

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>

class CatsWidget : public Wt::WContainerWidget
{
public:
    CatsWidget();
    virtual ~CatsWidget();
private:
    Wt::WContainerWidget *background;
    Wt::WText *title_text;
    Wt::WContainerWidget *cat1;
    Wt::WContainerWidget *cat2;
    Wt::WContainerWidget *cat3;
    Wt::WContainerWidget *cat4;
};

#endif