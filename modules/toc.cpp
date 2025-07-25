#include "include/toc.h"

FirstWidget::FirstWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");

    top_title = addNew<Wt::WContainerWidget>();
    top_title->addStyleClass("top_title");

    logo = top_title->addNew<Wt::WImage>("/picture/special/inscriptionST.png");
    logo->addStyleClass("logo");

    menuToggle = addNew<Wt::WPushButton>("⋯");
    menuToggle->addStyleClass("menu-toggle");
    menuToggle->clicked().connect([=] {
        if (!bContainers->hasStyleClass("show")) {
            bContainers->addStyleClass("show");
        } else {
            bContainers->removeStyleClass("show");
        }
    });

    bContainers = addNew<Wt::WContainerWidget>();
    bContainers->addStyleClass("top-buttons-container");
    
    bAboutUs = bContainers->addNew<Wt::WPushButton>("О нас");
    bAboutUs->addStyleClass("b-button");

    bAboutUs->mouseWentOver().connect([=] {
        bAboutUs->addStyleClass("b-button");
    });
    bAboutUs->mouseWentOut().connect([=] {
        bAboutUs->addStyleClass("b-button");
    });

    bOurBreeders = bContainers->addNew<Wt::WPushButton>("Наш производитель");
    bOurBreeders->addStyleClass("b-button");
    bOurBreeders->mouseWentOver().connect([=] {
        bOurBreeders->addStyleClass("b-button");
    });
    bOurBreeders->mouseWentOut().connect([=] {
        bOurBreeders->addStyleClass("b-button");
    });

    bCats = bContainers->addNew<Wt::WPushButton>("Наши кошки");
    bCats->addStyleClass("b-button");
    bCats->mouseWentOver().connect([=] {
        bCats->addStyleClass("b-button");
    });
    bCats->mouseWentOut().connect([=] {
        bCats->addStyleClass("b-button");
    });

    contact_info = bContainers->addNew<Wt::WPushButton>("Контактная информация");
    contact_info->addStyleClass("b-button");
    contact_info->mouseWentOver().connect([=] {
        contact_info->addStyleClass("b-button");
    });
    contact_info->mouseWentOut().connect([=] {
        contact_info->addStyleClass("b-button");
    });

    bAboutUs->clicked().connect([this] {
        Wt::WApplication::instance()->setInternalPath("/about_us", true);
    });

    bOurBreeders->clicked().connect([this] {
        Wt::WApplication::instance()->setInternalPath("/our_breeders", true);
    });

    bCats->clicked().connect([this] {
        Wt::WApplication::instance()->setInternalPath("/cats", true);
    });

    contact_info->clicked().connect([this] {
        Wt::WApplication::instance()->setInternalPath("/contact_info", true);
    });
}

FirstWidget::~FirstWidget() {}