package uba.algo3.tp1.ej2;

import java.util.ArrayList;
import org.junit.Test;


public class EntusiasmoStressTest {
   
   static private ArrayList<String> amistades1;
   static private ArrayList<String> amistades2;
   static private ArrayList<String> amistades3;
   static private ArrayList<String> amistades4;
   int x;
   int y;
     
   
   @Test
   public void extremoOpuestoPeorCasoTest() 
   {
      
      Entusiasmo e = new Entusiasmo();
      int res;
      long lg = System.currentTimeMillis();
      long promedio = 0; 
      amistades2 = new ArrayList<String>();
      
      
      for(int num = 0; num <= 200; num++)
      {   
         promedio = 0;
         
         amistades2.add( "inv" + String.valueOf( num )); 
         amistades2.add( "inv" + String.valueOf( num + 1));
         
         for (int i = 0; i < 6; i++)
         {
            res = e.obtenerEntusiasmo( "inv1","inv" + String.valueOf( num ), amistades2 );
            
            promedio = promedio + System.currentTimeMillis()-lg;
            
         }
         
         System.out.println(num + " " + promedio/5 );
         
      }
   }
   
      
   @Test
   public void noEstaQPeorCasoTest() 
   {
      Entusiasmo e = new Entusiasmo();
      int res;
      long lg = System.currentTimeMillis();
      long promedio; 
      int m=1; 
      amistades3 = new ArrayList<String>();
      
      for(int num = 1; num < 11; num++)
      {
         for (int j = 1; j < 11; j++)
         { 
              if (j != num)
              {
                  amistades3.add( "inv" + String.valueOf( num )); 
                  amistades3.add( "inv" + String.valueOf( num + j));
                  
                  promedio = 0;
                  
                  for (int i = 0; i < 6; i++)
                  {
                     res = e.obtenerEntusiasmo( "inv1","noexiste", amistades3 );      
                     promedio = promedio + System.currentTimeMillis()-lg;
                  }
                  
                  System.out.println(num + " " + promedio/5);
              }
         }

      }

   }
   
   
   @Test
   public void casoAzarTest() 
   {
      Entusiasmo e = new Entusiasmo();
      int res;
      long lg = System.currentTimeMillis();
      long promedio; 
      int m=1; 
      amistades4 = new ArrayList<String>();
      

      for(int num = 1; num < 11; num++)
      {
         for (int j = 1; j < 11; j++)
         { 
              if (j != num)
              {
                  amistades4.add( "inv" + String.valueOf( num )); 
                  amistades4.add( "inv" + String.valueOf( num + j));
                  
                  promedio = 0;
                  
                  for (int i = 0; i < 6; i++)
                  {
                     x = new Double(Math.random() * 100).intValue();
                     y = new Double(Math.random() * 100).intValue();
                     
                     res = e.obtenerEntusiasmo( "inv"+ String.valueOf( x ),"inv"+String.valueOf( y ), amistades4 );      
                     promedio = promedio + System.currentTimeMillis()-lg;
                  }
                  
                  System.out.println(num + " " + promedio/5);
              }
         }

      }

   }
     

}
