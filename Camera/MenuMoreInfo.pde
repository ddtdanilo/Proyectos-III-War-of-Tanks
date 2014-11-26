

// Team Text

void textLearnMoreOnScreen() {
  String a = textLearnMore();
  a = a.replaceAll("#", "\n");
  a += "- Presione algún botón del Mouse o alguna tecla para continuar -";
  textLeading(25);
  text(a, 9, 10);
}
//
void printLearnMore() {
  String a = textLearnMore();
  String[] list = split(a, '#');
  for (int i=0; i<list.length;i++) {
    println(list[i]);
  }
}
//
String textLearnMore() {
  // the sign # is used as line break here  
  String a=""; 
  a+="#"+"######      Laboratorio de Proyectos III. Sección 1. Sept-Dic 2014";
  a+="#"+"";
  a+="#"+"Elaborado por: ";
  a+="#"+"Grupo 3: \n Danilo Díaz Carnet 10-10211 \n Pedro Contreras Carnet 06-39387";
  a+="#"+"Grupo 8: \n Annybell Villarroel Carnet 10-10768 \n Jorge Pérez Carnet 10-10544";
  a+="#"+"#";
  return (a);
}
//

