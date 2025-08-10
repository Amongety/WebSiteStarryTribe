#ifndef __CW_H__
#define __CW_H__ 1

#include <vector>
#include <string>
#include "../../local/wt/include/Wt/WApplication.h"
#include "../../local/wt/include/Wt/WContainerWidget.h"
#include "../../local/wt/include/Wt/WPushButton.h"

class CatsWidget : public Wt::WContainerWidget
{
public:
    CatsWidget();
    virtual ~CatsWidget();
private:
    void addCatsBlock(const std::string &name, const std::vector<std::string> imagePath);
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
    Wt::WContainerWidget *catsContainer;
    std::vector<std::vector<std::string>> image;
    std::vector<std::string> text_image;
};

#endif