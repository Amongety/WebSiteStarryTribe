#include "include/obw.h"

BreedersWidget::BreedersWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");
    
    title_text = addNew<Wt::WText>("Наш производитель");
    title_text->addStyleClass("all-title-text");

    breeder = addNew<Wt::WContainerWidget>();
    breeder->addStyleClass("preparation");
}

BreedersWidget::~BreedersWidget() {}