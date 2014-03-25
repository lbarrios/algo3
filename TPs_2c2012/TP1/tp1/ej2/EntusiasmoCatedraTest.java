package uba.algo3.tp1.ej2;

import static org.junit.Assert.assertEquals;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import org.junit.Test;


public class EntusiasmoCatedraTest {

   @Test
   public void fileWritingRunTest() throws IOException {
      // Con este test se lee el archivo de entrada proporcioando por la cátedra 
      // y se genera la salida.
      BufferedReader is = new BufferedReader( new InputStreamReader( getClass().getResourceAsStream( "Tp1Ej2.in" ) ) );
      BufferedWriter os = new BufferedWriter( new FileWriter( getClass().getResource( "" ).getPath() + "Tp1Ej2.out" ) );
      
      String line;
      while ( ( line = is.readLine() ) != null ) {
         os.append( run( line, is.readLine() ) ).append( '\n' );
      }
      os.close();
      
   }

   @Test
   public void fileTestingRunTest() throws IOException {
      // Con este test se compara un archivo de entrada con el formato de la cátedra 
      // contra otro archivo con valores esperados.
      // Poner el nombre que se desee para generar el archivo de control.
      
      BufferedReader source  = new BufferedReader( new InputStreamReader( getClass().getResourceAsStream( "Tp1Ej2.in" ) ) );
      BufferedReader control = new BufferedReader( new InputStreamReader( getClass().getResourceAsStream( "Tp1Ej2_control.out" ) ) );
      
      String line;
      while ( ( line = source.readLine() ) != null ) {
         assertEquals( control.readLine(), run( line, source.readLine() ) );
      }
      
   }

   private String run( String line1, String line2 ) {
      
      StringTokenizer investigadores = new StringTokenizer(line1, " ");
      
      String inv1= investigadores.nextToken();
      String inv2= investigadores.nextToken();
      
      return String.valueOf( new Entusiasmo().obtenerEntusiasmo( inv1, inv2, parseArray(line2 ) ));
   }
   
   private ArrayList<String> parseArray( String line ) {
      
      ArrayList<String> amistades = new ArrayList<String>();
      StringTokenizer st = new StringTokenizer(line, ";");

      while(st.hasMoreTokens())
      {
         StringTokenizer s = new StringTokenizer(st.nextToken()," ");
         amistades.add(s.nextToken());
         amistades.add(s.nextToken());
      }
      return amistades;
      
   }
      
}
