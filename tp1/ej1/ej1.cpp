#include "ej1.h"
#include "TestCaseEj1.h"

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
		Itero sobre los distintos casos de prueba
		hasta obtener un testcase nulo
	*/
	while( testcase.tomarDatos() != false ){
	    tomarTiempoInicial();

	    // Obtengo los parámetros del testcase.
	    int intervaloInspector = testcase.dameIntervaloInspector();
	    int cantidadDeCamiones = testcase.dameCantidadCamiones();
        int *fechasCamiones = testcase.dameFechasCamiones();

        // Ordeno el listado de fechas de los camiones
        sort( fechasCamiones, fechasCamiones+cantidadDeCamiones );

        int p_inicio=0, p_fin=0, mejorDia = 0, mejorCantidadDeCamiones = 0;
        // Itero sobre las fechas con dos punteros p_inicio y p_fin
        while(p_fin<cantidadDeCamiones){
            /*
                Avanzo p_fin hasta la posición en que la distancia de fechas
                con p_inicio sea mayor al intervalo del inspector
            */
            while ( (fechasCamiones[p_fin]-fechasCamiones[p_inicio]<intervaloInspector) && (p_fin<cantidadDeCamiones) ) {
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
            int diaInicioAnterior = fechasCamiones[p_inicio];
            while(diaInicioAnterior == fechasCamiones[p_inicio] && (p_inicio<cantidadDeCamiones)){
                p_inicio++;
            }
        }

        imprimirTiempoFinal();
        #ifndef TIME
        parser.dameOutput() << mejorDia << " " << mejorCantidadDeCamiones << endl;
        #endif
	}
}
