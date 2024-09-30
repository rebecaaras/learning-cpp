#include <iostream>
#include <cstring>

class C {
public:
  C(const char *s = "", int i = 0, double d = 1){
    std::strncpy(dadosMembro1, s, sizeof(dadosMembro1) - 1);
    dadosMembro1[sizeof(dadosMembro1) - 1] = '\0';
    dadosMembro2 = i;
    dadosMembro3 = d;
  }
  void funcaoMembro1(){
    std::cout << dadosMembro1 << ' ' << dadosMembro2 << ' ' << dadosMembro3 << std::endl;
  }
  void funcaoMembro2(int i, const char *s = "desconhecido"){
    dadosMembro2 = i;
    std::cout << i << " recebido de " << s << std::endl;
  }
  protected:
    char dadosMembro1[20];
    int dadosMembro2;
    double dadosMembro3;
};

C objeto1("objeto1",100,2000), objeto2("objeto2"), objeto3;