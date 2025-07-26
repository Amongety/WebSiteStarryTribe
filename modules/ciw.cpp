#include "include/ciw.h"

ContactWidget::ContactWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");
    
    title_text = addNew<Wt::WText>("Контактная информация");
    title_text->addStyleClass("all-title-text");

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

    photosContainer = addNew<Wt::WContainerWidget>();
    photosContainer->addStyleClass("social-container");

    /* Добавлять/удалять фото */
    photos = {
        {"/picture/social_media/telegram.jpeg", "https://web.telegram.org/k/#@StarryTribe"},
        {"/picture/social_media/group_telegram.jpeg", "https://t.me/+V50Zz_YmA8A1OWMy"},
        {"/picture/social_media/vk.jpeg", "https://vk.com/id17041415"},
        {"/picture/social_media/group_vk.jpeg", "https://vk.com/starrytribe"},
        {"/picture/social_media/instagram.jpeg", "https://www.instagram.com/starry_tribe_devonrex/?utm_source=qr#"},
        {"/picture/social_media/whatsapp.jpeg", "https://whatsapp.com/dl/"}};

    photo_text ={"Телеграм", "Группа телеграм", "Вк", "Группа вк", "Инстаграм", "Ватсап"};

    for(int i = 0; i < photo_text.size(); i++) {
        addInfoBlock(photos[i], photo_text[i]);
    }

    logo->clicked().connect([=] {
        Wt::WApplication::instance()->setInternalPath("/", true);
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

    this->doJavaScript(R"(
        const topTitle = document.querySelector('.top_title');
        const logo = document.querySelector('.logo');
        const buttons = document.querySelector('.top-buttons-container');
        const menuToggle = document.querySelector('.menu-toggle');

        let lastScrollTop = 0;

        window.addEventListener('scroll', () => {
        let scrollTop = window.pageYOffset || document.documentElement.scrollTop;

        if(scrollTop > lastScrollTop){
            topTitle.style.opacity = '0';
            topTitle.style.visibility = 'hidden';

            logo.style.opacity = '0';
            logo.style.visibility = 'hidden';

            buttons.style.opacity = '0';
            buttons.style.visibility = 'hidden';

            menuToggle.style.opacity = '0';
            menuToggle.style.visibility = 'hidden';

        } else {
            if(scrollTop >= 0 && scrollTop < 100){
            topTitle.style.visibility = 'visible';
            topTitle.style.opacity = '1';

            logo.style.visibility = 'visible';
            logo.style.opacity = '1';

            buttons.style.visibility = 'visible';
            buttons.style.opacity = '1';

            menuToggle.style.visibility = 'visible';
            menuToggle.style.opacity = '1';
        } else {
            topTitle.style.opacity = '0';
            topTitle.style.visibility = 'hidden';

            logo.style.opacity = '0';
            logo.style.visibility = 'hidden';

            buttons.style.opacity = '0';
            buttons.style.visibility = 'hidden';

            menuToggle.style.opacity = '0';
            menuToggle.style.visibility = 'hidden';
        }
    }
    lastScrollTop = scrollTop <= 0 ? 0 : scrollTop; }); )");
}

void ContactWidget::addInfoBlock(std::pair<std::string, std::string> bundle, std::string name) {
    Wt::WContainerWidget* photoBlock = photosContainer->addNew<Wt::WContainerWidget>();
    photoBlock->addStyleClass("social-photo-block");

    Wt::WText* photoText = photoBlock->addNew<Wt::WText>(name);
        photoText->addStyleClass("social-photo-text");

    Wt::WImage* photo = photoBlock->addNew<Wt::WImage>(bundle.first);
    photo->addStyleClass("social-photo");

    photo->clicked().connect([photo, bundle] {
        photo->doJavaScript("window.open('" + bundle.second + "', '_blank');");
    });
}

ContactWidget::~ContactWidget() {}