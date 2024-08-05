#include <iostream>
#include "controle/aplicativo.h"

int main(int argc, char** argv) {
  Glib::RefPtr<Aplicativo> app = Aplicativo::create();
  return app->run();
}
