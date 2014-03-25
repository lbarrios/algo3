package uba.algo3.tp1.ej3;

import java.util.ListIterator;
import java.util.Vector;

@SuppressWarnings("boxing")

public class Procesamiento {

   private int costoMin;
   private Cortes cortesmin;
   
   public Procesamiento()
   {
      costoMin = Integer.MAX_VALUE;
      cortesmin = new Cortes();
   }
   
   public Vector<Integer> hallarCortesMin(Vector<Integer> cortes_a_realizar, Liston l)
   {
      
      Vector<Integer> cortes_realizados= new Vector<Integer>();
      
      return hallarCortesMin( cortes_a_realizar, l, cortes_realizados, 0).getCortes();

   }
   
   protected Cortes hallarCortesMin(Vector<Integer> cortes_a_realizar, Liston l,
                                  Vector<Integer> cortes_realizados, int costo_parcial)
   {  
      //Si me pasaron la secuencia vacia, me cuesta 0, hacer 0 cortes
      //y devuelvo la secuencia vacia.
      if (cortes_a_realizar.size()==0)
         
         return new Cortes();
         
      
      //Si en algún momento la función recibe parametros inadecuados,
      //se detiene la ejecución y se devuelven volores que no son posibles ([-1] y -1)
      if(!PrecondicionesCumplidas(cortes_a_realizar, l, cortes_realizados, costo_parcial))
         return respuestaInvalida();
                  
     if(cortes_realizados.size() == 0)
     {//Quiere decir que entro por primera vez a la funcion, no estoy en ningun 
      //paso recursivo, por lo tanto "limpio" mis variables
        cortesmin = new Cortes();
        costoMin = Integer.MAX_VALUE;
     }

      for(int i = 0; i < cortes_a_realizar.size(); i++)
      {
         int posDeCorte = cortes_a_realizar.get(i);
         int costo = l.cortarListon(posDeCorte);
         int costoAcumulado = costo_parcial + costo;
         
         if(costoAcumulado < costoMin)
         {                        
            cortes_realizados.add(posDeCorte);
            cortes_a_realizar.remove(i);
            
            if(cortes_a_realizar.size() == 0)
            {
            //Si el costo acumulado es menor que el minimo que tenia y ademas ya 
            //no quedan mas cortes a relizar, entonces es un candidato a minimo
            costoMin = costoAcumulado;
            cortesmin.setCortes((Vector<Integer>) cortes_realizados.clone());
            cortesmin.setCosto(costoAcumulado);
            }
            else
            {
               hallarCortesMin(cortes_a_realizar,l,cortes_realizados,costoAcumulado);
            }
            
            //Volvemos a dejar todo como estaba..
            cortes_a_realizar.add(i, posDeCorte);
            if(cortes_realizados.size() > 0)
            {
               cortes_realizados.remove( cortes_realizados.size() - 1);
            }
         }
         
         l.deshacerCorte(posDeCorte);
      }
      
      return cortesmin;
       
   }
   
   public int calcularCosto(Vector<Integer> secuencia_cortes, int longitud)
   {
	Liston l = new Liston(longitud);
      int costo = 0;
      for(int i = 0; i < secuencia_cortes.size();i++)
      {
         int siguienteCorte = secuencia_cortes.get(i);
         costo = costo + l.cortarListon(siguienteCorte);
      }
      
      return costo;
   }
   
  private boolean PrecondicionesCumplidas(Vector<Integer> cortes_a_realizar, Liston l,
            Vector<Integer> cortes_realizados, int costo_parcial)
   {   
   boolean res= true;  
   if (!cortesValidos( cortes_a_realizar, l ))
   {
      mostrarErrorCortesPedidos();
      res = false;
   }  
   if (!cortesValidos( cortes_realizados, l ) )
   {
      mostrarErrorCortesRealizados();
      res = false;
   }
   
   if (costo_parcial < 0)
   {
      mostrarErrorCostos();
      res = false;
   }
   if (!l.esValido())
   {
      mostrarErrorListon();
      res = false;
   }   
   return res;
   }
   public boolean cortesValidos(Vector cortes, Liston l) 
   {
      //Chequeamos que no quieran hacer un corte fuera de rango. 
      for (ListIterator<Integer> it = cortes.listIterator(); it.hasNext();)
      {
         int corte = it.next();
         if (corte < 1 || corte >= l.obtenerLongitud())
            return false;
      }
      return true;
   }
   
   
   
   private void mostrarErrorCortesPedidos()
   {
      System.out.println("Alguno de los cortes pedidos es inválido");
   }
   
   private void mostrarErrorCortesRealizados()
   {
      System.out.println("Alguno de los cortes realizados es inválido");
   }
   
   private void mostrarErrorCostos() 
   {
      System.out.println("Uno o más costos obtenidos son inválidos");
   }
   
   private void mostrarErrorListon()
   {
      System.out.println("El liston que se quiere cortar es inválido");
   }   
   
   private Cortes respuestaInvalida()
   {
      Cortes res_invalida = new Cortes();
      Vector vec_inv= new Vector<Integer>();
      vec_inv.add( -1 );
      res_invalida.setCortes( vec_inv );
      res_invalida.setCosto( -1 );
      return res_invalida;
   }
   
   public static String pasarVectorAString(Vector<Integer> vec)
   {
      String stringAuxiliar;
      String stringAuxiliar2;
      String res;
      stringAuxiliar= vec.toString();
      //Saco los corchetes.
      stringAuxiliar2 = stringAuxiliar.substring( 1, stringAuxiliar.length()-1 );
      //Saco las comas.
      res = stringAuxiliar2.replace( ",", "" );
      
      return res;
   }
}
