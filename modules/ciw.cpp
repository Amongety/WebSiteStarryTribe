#include "include/ciw.h"

ContactWidget::ContactWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");
    
    title_text = addNew<Wt::WText>("Контактная информация");
    title_text->addStyleClass("all-title-text");
}

ContactWidget::~ContactWidget() {}