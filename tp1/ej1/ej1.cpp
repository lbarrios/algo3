#include "ej1.h"

int main( int argc, char** argv ){
  /*
    Parseo los parámetros con que fue llamado
    el ejecutable
  */
  ParserDeParametros parser( argc, argv );
  /*
    Esta clase representa un caso de prueba,
    y lo toma desde el input que le provee el parser
  */
  TestCaseEj1 testcase ( parser.dameInput() );
  /*
    Esta clase se encarga de medir el tiempo.
  */
  Timer timer ( parser.dameTime() );
  /*
    Itero sobre los distintos casos de prueba
    hasta obtener un testcase nulo
  */
  while( testcase.tomarDatos() != TestCase::TESTCASE_NULL ){
    // Mido el tiempo inicial
    timer.setInitialTime("todoElCiclo");

    // Obtengo los parámetros del testcase.
    const uint32_t &intervaloInspector = testcase.dameIntervaloInspector();
    const uint32_t &cantidadDeCamiones = testcase.dameCantidadDeCamiones();
    uint32_t* fechasCamiones = testcase.dameFechasCamiones();

    // Ordeno el listado de fechas de los camiones
    sort( fechasCamiones, fechasCamiones+cantidadDeCamiones );

    uint32_t p_inicio=0, p_fin=0, mejorDia = 0, mejorCantidadDeCamiones = 0;
    // Itero sobre las fechas con dos punteros p_inicio y p_fin
    while(p_fin<cantidadDeCamiones){
      /*
        Avanzo p_fin hasta la posición en que la distancia de fechas
        con p_inicio sea mayor al intervalo del inspector
      */
      while( p_fin<cantidadDeCamiones && 
      fechasCamiones[p_fin]-fechasCamiones[p_inicio]<intervaloInspector){
        p_fin++;
      }
      // Si la solución es mejor que la anterior, piso los valores
      if (p_fin-p_inicio > mejorCantidadDeCamiones) {
        mejorCantidadDeCamiones = p_fin-p_inicio;
        mejorDia = fechasCamiones[p_inicio];
      }
      /*
        Avanzo p_inicio hasta la que encuentre un día mayor
        al que estaba, siempre que no me pase del total.
      */
      uint32_t diaInicioAnterior = fechasCamiones[p_inicio];
      while( p_inicio<cantidadDeCamiones
      && diaInicioAnterior == fechasCamiones[p_inicio] ){
        p_inicio++;
      }
    }

    // Mido el tiempo final
    timer.setFinalTime("todoElCiclo");
    // Devuelvo el resultado con el formato solicitado
    #ifndef TIME
    parser.dameOutput() << mejorDia << " " << mejorCantidadDeCamiones << endl;
    #else
    timer.saveAllTimes();
    #endif
  }
}
