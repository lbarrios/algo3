package uba.algo3.tp1.ej1;

import static org.junit.Assert.assertEquals;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Vector;
import org.junit.Test;
import uba.algo3.Utils;

public class MejorNegocioCatedraTest
{
	   @Test
	   public void fileWritingRunTest() throws IOException {
	      // Con este test se lee el archivo de entrada proporcioando por la catedra 
	      // y se genera la salida.
	      
	      BufferedReader is = new BufferedReader( new InputStreamReader( getClass().getResourceAsStream( "Tp1Ej1.in" ) ) );
	      BufferedWriter os = new BufferedWriter( new FileWriter( getClass().getResource( "" ).getPath() + "Tp1Ej1.out" ) );

	      String line;
	      while ( ( line = is.readLine() ) != null ) {
	         os.append( run( line ) ).append( '\n' );
	      }
	      os.close();
	      
	   }

	   @Test
	   public void fileTestingRunTest() throws IOException {
	      // Con este test se compara un archivo de entrada con el formato de la catedra 
	      // contra otro archivo con valores esperados.
	      BufferedReader source  = new BufferedReader( new InputStreamReader( getClass().getResourceAsStream( "Tp1Ej1.in" ) ) );
	      BufferedReader control = new BufferedReader( new InputStreamReader( getClass().getResourceAsStream( "Tp1Ej1.out" ) ) );
	      
	      String line;
	      while ( ( line = source.readLine() ) != null ) {
	         assertEquals( control.readLine(), run( line ) );
	      }
	      
	   }

	   private String run( String a ) {
	      
	      Vector<Integer> in_vector = Utils.parseVector( a );
	      MejorNegocio m = new MejorNegocio();
	      ArrayList<Integer> parsed = new ArrayList<Integer>( in_vector );
	      int gananciaMax = m.obtenerMayorGanancia( parsed );
	      return String.valueOf(gananciaMax);
	   }
}
