#include "include/ciw.h"

ContactWidget::ContactWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");
    
    title_text = addNew<Wt::WText>("Контактная информация");
    title_text->addStyleClass("all-title-text");

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