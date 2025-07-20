#ifndef __CIW_H__
#define __CIW_H__ 1

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>

class ContactWidget : public Wt::WContainerWidget
{
public:
    ContactWidget();
    virtual ~ContactWidget();
private:
    Wt::WContainerWidget *background;
    Wt::WText *title_text;
};

#endif