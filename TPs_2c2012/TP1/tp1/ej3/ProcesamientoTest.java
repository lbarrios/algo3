package uba.algo3.tp1.ej3;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import java.util.StringTokenizer;
import java.util.Vector;
import org.junit.Test;

@SuppressWarnings("boxing")
public class ProcesamientoTest
{
   static Procesamiento p;
   static Liston l;
   static Vector<Integer> cortes_a_realizar;
   static Vector<Integer> cortes_realizados;
      
   @Test
   public void HallarCortesMinimosFuncionInternaTest()
   {
      Cortes res;
      //Chequeo de datos inválidos.
      representData("10\n2 433 7");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(-1, res.getCosto());
      assertTrue("-1".equals( Procesamiento.pasarVectorAString(res.getCortes())));  
 
      representData("10\n2 -3 7");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(-1, res.getCosto());
      assertTrue("-1".equals( Procesamiento.pasarVectorAString(res.getCortes())));  
      
      representData("-10\n2 3 7");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(-1, res.getCosto());
      assertTrue("-1".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
      representData("10\n2 3 7");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, -34);
      assertEquals(-1, res.getCosto());
      assertTrue("-1".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
      representData("10\n2 3 7");
      Vector cortesMalos = new Vector<Integer>();
      cortesMalos.add( 2);
      cortesMalos.add(-5);
      res = p.hallarCortesMin(cortes_a_realizar, l, cortesMalos , 0);
      assertEquals(-1, res.getCosto());
      assertTrue("-1".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
      //Casos válidos.
      representData("100\n25 50 75");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(200, res.getCosto());
      assertTrue("50 25 75".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
      representData("10\n4 5 7 8");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(22, res.getCosto());
      assertTrue("4 7 5 8".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
      representData("22\n3 8 16 19");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(50, res.getCosto());
      assertTrue("8 3 16 19".equals( Procesamiento.pasarVectorAString(res.getCortes())));
                 
      representData("1000\n700 800 900");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(1500, res.getCosto());
      assertTrue("700 800 900".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
      representData("1000\n7 8 9");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(1011, res.getCosto());
      assertTrue("9 7 8".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
   }
   
   @Test//Test para chequear casos de borde.
   public void BordesTest()
   {
      Cortes res;
      //Secuencia de cortes vacia.
      representData("10\n ");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(0, res.getCosto());
      assertTrue("".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
      //Menor cantidad de cortes posibles.
      representData("10\n3");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(10, res.getCosto());
      assertTrue("3".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
      //Mayor cantidad de cortes posibles. Que al ser los cortes enteros, queda determinado por
      //la longitud del liston.
      representData("10\n1 2 3 4 5 6 7 8 9");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(34, res.getCosto());
      assertTrue("4 2 1 3 6 5 8 7 9".equals( Procesamiento.pasarVectorAString(res.getCortes())));
      
   }
  
   
   @Test//Test para chequear la correspondencia entre el costo indicado y el costo de la secuencia de cortes dada como resultada.
   public void testProcesamientoCorrespondencia()
   {
      representData("10\n2 4 7");
      Cortes res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(p.calcularCosto(res.getCortes(),10), res.getCosto());
      representData("100\n25 50 75");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(p.calcularCosto(res.getCortes(),100), res.getCosto());
      representData("10\n4 5 7 8");
      res = p.hallarCortesMin(cortes_a_realizar, l, cortes_realizados, 0);
      assertEquals(p.calcularCosto(res.getCortes(),10), res.getCosto());
   }

   
   private void representData(String string)
   {
      StringTokenizer st1 = new StringTokenizer(string, "\n");
      int longitud = Integer.parseInt(st1.nextToken());
      String cortes_str = st1.nextToken();
      StringTokenizer st = new StringTokenizer(cortes_str, " ");

      cortes_a_realizar = new Vector<Integer>();
      while(st.hasMoreTokens())
      {
         cortes_a_realizar.add( Integer.parseInt(st.nextToken().trim()) );
      }
      
      l = new Liston(longitud);
      
      cortes_realizados = new Vector<Integer>();
      p = new Procesamiento();
   }

}
