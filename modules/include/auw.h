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
};

#endif