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
    void addBreedersBlock(const std::string &name, const std::vector<std::string> imagePath);
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
    Wt::WContainerWidget *breederContainer;
    std::vector<std::vector<std::string>> images;
    std::vector<std::string> text_image;
};

#endif