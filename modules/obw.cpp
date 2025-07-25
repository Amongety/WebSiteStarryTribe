#include "include/obw.h"

BreedersWidget::BreedersWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");
    
    title_text = addNew<Wt::WText>("Наш производитель");
    title_text->addStyleClass("all-title-text");

    breederContainer = addNew<Wt::WContainerWidget>();
    breederContainer->addStyleClass("blocks-container");

    /* Добавлять/удалять фото */
    images = {{"/picture/breeders/breeder1/breeder1.jpeg", "/picture/breeders/breeder1/breeder2.jpeg", "/picture/breeders/breeder1/breeder3.jpeg"}};

    text_image = {"Emelian/N 21 32"};

    for(int i = 0; i < images.size(); i++) {
        addBreedersBlock(text_image[i], images[i]);
    }
}

void BreedersWidget::addBreedersBlock(const std::string &name, const std::vector<std::string> imagePath) {
    Wt::WContainerWidget* breederBlock = breederContainer->addNew<Wt::WContainerWidget>();
    breederBlock->addStyleClass("single-block");
    
    Wt::WContainerWidget* textContainer = breederBlock->addNew<Wt::WContainerWidget>();
    textContainer->addStyleClass("image-text-above");
    
    Wt::WText* breederText = textContainer->addNew<Wt::WText>("<span>" + name + "</span>");
    breederText->setTextFormat(Wt::TextFormat::UnsafeXHTML);
    
    Wt::WContainerWidget* imageContainer = breederBlock->addNew<Wt::WContainerWidget>();
    imageContainer->addStyleClass("image-container");
    
    Wt::WImage* mainImage = imageContainer->addNew<Wt::WImage>(imagePath[0]);
    mainImage->addStyleClass("main-image");
    
    Wt::WContainerWidget* arrowsContainer = imageContainer->addNew<Wt::WContainerWidget>();
    arrowsContainer->addStyleClass("arrows-container");

    Wt::WPushButton* leftArrow = arrowsContainer->addNew<Wt::WPushButton>("←");
    leftArrow->addStyleClass("arrow-button");

    Wt::WPushButton* rightArrow = arrowsContainer->addNew<Wt::WPushButton>("→");
    rightArrow->addStyleClass("arrow-button");

    std::shared_ptr<long long int> currentIndex = std::make_shared<long long int>(0);

    auto updateImage = [mainImage, imagePath, currentIndex]() {
        mainImage->setImageLink(Wt::WLink(imagePath[*currentIndex]));
    };

    leftArrow->clicked().connect([currentIndex, imagePath, updateImage] {
        *currentIndex = (*currentIndex - 1 + imagePath.size()) % imagePath.size();
        updateImage();
    });
    
    rightArrow->clicked().connect([currentIndex, imagePath, updateImage] {
        *currentIndex = (*currentIndex + 1) % imagePath.size();
        updateImage();
    });
}

BreedersWidget::~BreedersWidget() {}