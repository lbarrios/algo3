package uba.algo3.tp1.ej2;
public class Amistad 
{
   String primero;
   String segundo;
   
   public Amistad(String primero, String segundo){
      this.primero = primero;
      this.segundo = segundo;
   }
   
   public String GetPrimero()
   {
      return primero;
   }
  
   public String GetSegundo()
   {
      return segundo;
   }
   
   public String toString(){
      return ("(" + primero + "," + segundo + ")");
   } 

}
