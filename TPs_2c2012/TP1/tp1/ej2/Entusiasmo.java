package uba.algo3.tp1.ej2;
import java.util.ArrayList;
import java.util.HashMap;

public class Entusiasmo
{

   // Investigador "es" una lista con los amigos de la clave correspondiente. Es lo que antes llamabamos "amistades"
   private HashMap<String,Investigador> investigadores = new HashMap<String,Investigador>(); 
   private HashMap<String, Integer> pasosMinimos;//en esta estructura nos vamos guardando la cant minima de p a cada otro investigador

   int cantPasosMin = Integer.MAX_VALUE;
   
   public int obtenerEntusiasmo(String p, String q, ArrayList<String> amistadesLista)
   {
      cantPasosMin = Integer.MAX_VALUE;
      generarAmistades(toAmistades(amistadesLista)); //generarAmistades recibe ArrayList<Amistad>
      
      if (!investigadores.containsKey( p ))
      {
         return 0;
      }
    
      
      int ent = obtenerEntusiasmoAux(p, q, 1);
      
      if(ent == Integer.MAX_VALUE)
      {
         return 0;
      }
      else
      {
         return ent;
      }
  
   }
   
   private int obtenerEntusiasmoAux(String p, String q, int cantPasosRealizados)
   {  
      
      ArrayList<String> amigos = investigadores.get(p).GetAmigos();
          
      
      if(cantPasosRealizados == 1)
      {
         pasosMinimos = new HashMap<String, Integer>();
         
         
         for(String investigador : investigadores.keySet())
         {
            pasosMinimos.put(investigador, Integer.MAX_VALUE);
         }
         
         pasosMinimos.put(p, 0);
      }
      
      for(String amigo : amigos)
      {
         if(amigo.equals(q))
         {
            cantPasosMin = cantPasosRealizados;
            break;
         }
         else
         {
            if(cantPasosMin > cantPasosRealizados + 1)
            {
               if(pasosMinimos.get(amigo) > cantPasosRealizados)
               {
                  
                  pasosMinimos.put(amigo, cantPasosRealizados);
                  cantPasosMin = obtenerEntusiasmoAux(amigo,q,cantPasosRealizados + 1);
               }
            }
            else
            {
               break;
            }
         }
      }
      
      return cantPasosMin;
   }
   
   public void generarAmistades(ArrayList<Amistad> amistades)
   {
   
      for( Amistad amistad: amistades )
      {
         Investigador primero = dameAmigo(investigadores, amistad.GetPrimero() ); //amigos del primero de amistad
         Investigador segundo = dameAmigo(investigadores, amistad.GetSegundo() ); //amigos del segundo de amistad
         
         primero.GetAmigos().add( amistad.GetSegundo() );
         segundo.GetAmigos().add( amistad.GetPrimero() );
            
      }
   }
   
   public Investigador dameAmigo(HashMap investigadores, String amigo) //devuelve la "lista" de amigos de amigo
   { 
      if (!investigadores.containsKey( amigo)) 
      {
         Investigador nuevoInvestigador = new Investigador(amigo);
         
         investigadores.put(amigo, nuevoInvestigador);
      }
      
      
      return (Investigador)(investigadores.get(amigo));
            
   }
   
   public ArrayList<Amistad> toAmistades(ArrayList<String> amistadesLista){
   ArrayList<Amistad> res = new ArrayList<Amistad>();
   for(int i=0; i<amistadesLista.size(); i+=2){
      String prim = amistadesLista.get(i);
      String seg = amistadesLista.get(i+1);
      res.add(new Amistad(prim,seg));
   }
   return res;
}
   
   public HashMap<String,Investigador> GetInvestigadores()
   {
      return this.investigadores;
   }
   
}
