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
    
    linkContainer1 = addNew<Wt::WContainerWidget>();
    linkContainer1->addStyleClass("devon-block");
    
    textDRX1 = linkContainer1->addNew<Wt::WContainerWidget>();
    textDRX1->addStyleClass("devon-text");
    
    textDRX1->addNew<Wt::WText>("<h2>Девон-рекс</h2>")->addStyleClass("devon-header");
    
    textDRX1->addNew<Wt::WText>("Девон-рекс — питомец с необычной внешностью, преданный друг и жизнерадостный непоседа. "
        "Шерсть девон-рекса имеет характерную марсельскую волну, особенно на спине, где образуются "
        "мелкие барашки. Широкие скулы, большие уши и глаза придают этой кошке «инопланетный» вид, "
        "а по характеру она больше напоминает собаку — «рекс» всюду следует за человеком и тяжело переносит "
        "одиночество. Девон-рекс может быть любых окрасов и вариантов пятнистости.")->addStyleClass("devon-desc");
    
    imageDRX1 = linkContainer1->addNew<Wt::WImage>("/picture/cattery/cattery1.jpeg");
    imageDRX1->addStyleClass("devon-image");

    linkContainer2 = addNew<Wt::WContainerWidget>();
    linkContainer2->addStyleClass("devon-block");

    textDRX2 = linkContainer2->addNew<Wt::WContainerWidget>();
    textDRX2->addStyleClass("devon-text");
    
    textDRX2->addNew<Wt::WText>("<h2>Происхождение</h2>")->addStyleClass("devon-header");
    
    textDRX2->addNew<Wt::WText>("Кошки породы девон-рекс появились в результате естественной мутации. В 1960-х годах прародительница «кудрявых» питомцев попала в руки британки Берил Кокс и впоследствии дала потомство, среди которого был котенок Кирли со слегка волнистой шерстью.\n\n"
        "Хозяйка подумала, что в генах питомца течет кровь корниш-рексов — похожей «кудрявой» породы, которая набирала популярность в то время. После нескольких вязок выяснилось, что Кирли вовсе не корниш-рекс, так как его потомство не унаследовало «визитную карточку» породы. Дело в том, что у этих двух пород гены, отвечающие за волнистость шерсти, разные, и при скрещивании девон-рекса и корниш-рекса рождаются котята с прямой шерстью.\n\n"
        "Впоследствии Кирли стали скрещивать с однопометниками, чтобы закрепить породные признаки. Можно сказать, что этот питомец — «родитель» всех девон-рексов, существующих в наше время.\n\n"
        "Длительное время девон-рекс и корниш-рекс считались подвидами одной породы, и лишь в 1979 году они обрели «независимость». Сейчас заводчики продолжают работать над породой, а «кудрявые» кошки покоряют сердца не только внешностью, но и характером.")->addStyleClass("devon-desc");
    
    imageDRX2 = linkContainer2->addNew<Wt::WImage>("/picture/cattery/cattery2.jpeg");
    imageDRX2->addStyleClass("devon-image");

    linkContainer3 = addNew<Wt::WContainerWidget>();
    linkContainer3->addStyleClass("devon-block");

    textDRX3 = linkContainer3->addNew<Wt::WContainerWidget>();
    textDRX3->addStyleClass("devon-text");
    
    textDRX3->addNew<Wt::WText>("<h2>Характер и поведение</h2>")->addStyleClass("devon-header");
    
    textDRX3->addNew<Wt::WText>("Девон-рекс — неугомонный исследователь, который не оставит без внимания ни одного уголка квартиры."
        "«Смекалистый» кот может даже изучить содержимое всех шкафов — ему не составит труда научиться открывать дверцы и проникать в «запретные» зоны."
        "Пытливый ум девон-рекса можно направить в мирное русло — он довольно легко усвоит простые комады и трюки и будет радовать своими навыками домочадцев.")->addStyleClass("devon-desc");
    
    imageDRX3 = linkContainer3->addNew<Wt::WImage>("/picture/cattery/cattery3.jpeg");
    imageDRX3->addStyleClass("devon-image");

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
            if(scrollTop >= 0 && scrollTop < 550){
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

FirstWidget::~FirstWidget() {}