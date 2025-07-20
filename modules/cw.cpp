#include "include/cw.h"

CatsWidget::CatsWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");
    
    title_text = addNew<Wt::WText>("Наши кошки");
    title_text->addStyleClass("all-title-text");

    cat1 = addNew<Wt::WContainerWidget>();
    cat1->addStyleClass("");

    cat2 = addNew<Wt::WContainerWidget>();
    cat2->addStyleClass("");

    cat3 = addNew<Wt::WContainerWidget>();
    cat3->addStyleClass("");

    cat4 = addNew<Wt::WContainerWidget>();
    cat4->addStyleClass("");
}

CatsWidget::~CatsWidget() {}