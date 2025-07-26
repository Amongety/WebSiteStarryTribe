#include "include/cw.h"

CatsWidget::CatsWidget() {
    background = addNew<Wt::WContainerWidget>();
    background->addStyleClass("main-background");
    
    title_text = addNew<Wt::WText>("Наши кошки");
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

    catsContainer = addNew<Wt::WContainerWidget>();
    catsContainer->addStyleClass("blocks-container");

    /* Добавлять/удалять фото */
    image = {{"/picture/cats/cat1/cat1.jpeg", "/picture/cats/cat1/cat2.jpeg", "/picture/cats/cat1/cat3.jpeg"}, \
    {"/picture/cats/cat2/cat1.jpeg", "/picture/cats/cat2/cat2.jpeg", "/picture/cats/cat2/cat3.jpeg"}, \
    {"/picture/cats/cat3/cat1.jpeg", "/picture/cats/cat3/cat2.jpeg", "/picture/cats/cat3/cat3.jpeg"}, \
    {"/picture/cats/cat4/cat1.jpeg", "/picture/cats/cat4/cat2.jpeg", "/picture/cats/cat4/cat3.jpeg"}};

    text_image = {"Kiki/b 21 32", "Fortuna/N 33 21", "Wally/n 32", "Selena/n 21 32"};

    for(int i = 0; i < image.size(); i++) {
        addCatsBlock(text_image[i], image[i]);
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

void CatsWidget::addCatsBlock(const std::string &name, const std::vector<std::string> imagePath) {
    Wt::WContainerWidget* catBlock = catsContainer->addNew<Wt::WContainerWidget>();
    catBlock->addStyleClass("single-block");
    
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

CatsWidget::~CatsWidget() {}