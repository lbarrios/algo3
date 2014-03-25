package uba.algo3.tp1.ej2;
import java.util.ArrayList;

public class Investigador 
{
   ArrayList<String> amigos;
   String nombre;
   
   public Investigador(String nombre){
      this.nombre = nombre;
      this.amigos = new ArrayList<String>();
   }
   
   public ArrayList<String> GetAmigos()
   {
      return amigos;
   }
   
   public String GetNombre()
   {
      return nombre;
   }
   
   public String toString(){
      return nombre;
   }
   
}
