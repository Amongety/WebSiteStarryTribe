#ifndef __OBW_H__
#define __OBW_H__ 1

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>

class BreedersWidget : public Wt::WContainerWidget
{
public:
    BreedersWidget();
    virtual ~BreedersWidget();
private:
    Wt::WContainerWidget *background;
    Wt::WText *title_text;
    Wt::WContainerWidget *breeder;
};

#endif