#include "include/auw.h"

AboutWidget::AboutWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");
    
    title_text = addNew<Wt::WText>("О нас");
    title_text->addStyleClass("all-title-text");

    
}

AboutWidget::~AboutWidget() {}