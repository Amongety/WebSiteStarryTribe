#include "include/cw.h"

CatsWidget::CatsWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");
    
    title_text = addNew<Wt::WText>("Наши кошки");
    title_text->addStyleClass("all-title-text");

    catsContainer = addNew<Wt::WContainerWidget>();
    catsContainer->addStyleClass("cats-container");

    image = {{"/picture/cats/cat1/cat1.jpeg", "/picture/cats/cat1/cat2.jpeg", "/picture/cats/cat1/cat3.jpeg"}, \
    {"/picture/cats/cat2/cat1.jpeg", "/picture/cats/cat2/cat2.jpeg", "/picture/cats/cat2/cat3.jpeg"}, \
    {"/picture/cats/cat3/cat1.jpeg", "/picture/cats/cat3/cat2.jpeg", "/picture/cats/cat3/cat3.jpeg"}, \
    {"/picture/cats/cat4/cat1.jpeg", "/picture/cats/cat4/cat2.jpeg", "/picture/cats/cat4/cat3.jpeg"}};

    text_image = {"Kiki/b 21 32", "Fortuna/N 33 21", "Wally/n 32", "Selena/n 21 32"};

    for(int i = 0; i < image.size(); i++) {
        addCatsBlock(text_image[i], image[i]);
    }
}

void CatsWidget::addCatsBlock(const std::string &name, const std::vector<std::string> imagePath) {
    Wt::WContainerWidget* catBlock = catsContainer->addNew<Wt::WContainerWidget>();
    catBlock->addStyleClass("breeder-block");
    
    Wt::WContainerWidget* textContainer = catBlock->addNew<Wt::WContainerWidget>();
    textContainer->addStyleClass("image-text-above");
    
    Wt::WText* catText = textContainer->addNew<Wt::WText>("<span>" + name + "</span>");
    catText->setTextFormat(Wt::TextFormat::UnsafeXHTML);

    Wt::WContainerWidget* imageContainer = catBlock->addNew<Wt::WContainerWidget>();
    imageContainer->addStyleClass("image-container");
    
    Wt::WImage* mainImage = imageContainer->addNew<Wt::WImage>(imagePath[0]);
    mainImage->addStyleClass("main-image");
    
    Wt::WContainerWidget* arrowsContainer = imageContainer->addNew<Wt::WContainerWidget>();
    arrowsContainer->addStyleClass("arrows-container");

    Wt::WPushButton* leftArrow = arrowsContainer->addNew<Wt::WPushButton>("←");
    leftArrow->addStyleClass("arrow-button");

    Wt::WPushButton* rightArrow = arrowsContainer->addNew<Wt::WPushButton>("→");
    rightArrow->addStyleClass("arrow-button");

    std::shared_ptr<int> currentIndex = std::make_shared<int>(0);

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

CatsWidget::~CatsWidget() {}