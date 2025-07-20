#include "include/main.h"

MainApplication::MainApplication(const Wt::WEnvironment& env) : Wt::WApplication(env) {
  setTitle("StarryTribe");

  useStyleSheet("css_format/style.css");

  internalPathChanged().connect(this, &MainApplication::handleInternalPathChange);

  handleInternalPathChange();
}

void MainApplication::handleInternalPathChange() {
  std::string path = internalPath();

  if (path == "/") {
    root()->clear();
    root()->addNew<FirstWidget>();
  }
  else if (path == "/about_us") {
      root()->clear();
      root()->addNew<AboutWidget>();
  }
  else if (path == "/our_breeders") {
      root()->clear();
      root()->addNew<BreedersWidget>();
  }
  else if (path == "/cats") {
      root()->clear();
      root()->addNew<CatsWidget>();
  }
  else if (path == "/contact_info") {
      root()->clear();
      root()->addNew<ContactWidget>();
  }
  else {
      root()->clear();
      root()->addNew<FirstWidget>();
  }
}

int main(int argc, char **argv)
{
  return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
    return std::make_unique<MainApplication>(env);
  });
}