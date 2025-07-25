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
    void addInfoBlock(std::pair<std::string, std::string> bundle, std::string name);
    Wt::WContainerWidget *background;
    Wt::WText *title_text;
    Wt::WContainerWidget* photosContainer;
    std::vector<std::pair<std::string, std::string>> photos;
    std::vector<std::string> photo_text;
};

#endif