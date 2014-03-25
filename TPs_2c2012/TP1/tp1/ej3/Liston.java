package uba.algo3.tp1.ej3;

import java.util.LinkedList;
import java.util.ListIterator;

@SuppressWarnings("boxing")
public class Liston
{
 //La longitud del liston va a estar en la ultima posicion de la lista.
	private LinkedList<Integer> listoncitos;
	private final int longitud;
	
	
   public Liston (int longitud)
	{
	   // No se si impedir que se cree un liston con longitud negativa.... ???
//	   if (longitud < 2)
//	      return;
	   
		listoncitos = new LinkedList<Integer>();
		this.longitud = longitud;
		listoncitos.addFirst(longitud);
	}
	
   public int cortarListon(int posDeCorte)
	{//Requiere que la posicion de Corte sea menor a la longitud del liston.
	   if (posDeCorte < 1 || posDeCorte >= longitud)
	      return -1;
	   
		ListIterator<Integer> it = listoncitos.listIterator();

		int i = 0;
		int costo;
		int anterior = 0;
		int actual = 0;
		//Voy buscando en donde tengo que ubicar el corte que me pasaron.
		while (it.hasNext() && posDeCorte > it.next())
		{
			i++;
		}
		//Si tengo más de un corte.
		if (listoncitos.size() > 1)
		{
			actual = it.previous();
			if (it.hasPrevious())
			{
				anterior = it.previous();
			} else
			{
				anterior = 0;
			}
		}
		else
		{
			actual = it.previous();
		}

		costo = actual - anterior;
		//Agrego el corte al liston en la posicion correcta.
		listoncitos.add(i, posDeCorte);

		return costo;
	}

   public int deshacerCorte(int posDeCorte)
	{//Requiere que la posicion de corte sea un corte del liston
      if (posDeCorte < 1 || posDeCorte >= longitud)
         return -1;
      
		ListIterator<Integer> it = listoncitos.listIterator();

		while (it.hasNext() && posDeCorte != it.next())
		{

		}
		it.remove();

		int anterior = 0;
		int siguiente = it.next();
		it.previous();
		if(it.hasPrevious())
		{
			anterior = it.previous();
		}
		return siguiente - anterior;
	}

	public void mostrarListones()
	{
		System.out.println(listoncitos);
	}
	
	public boolean equals( Object other ) 
	{
      return getClass().isInstance( other ) && equals( other ); 
   }
	
   public boolean equals( Liston other )
   {      
      return listoncitos.equals(other.listoncitos); 
   }
   
   public boolean esValido() 
   {
      int corte;
      for (ListIterator<Integer> it = listoncitos.listIterator(); it.hasNext();)

      {
         corte = it.next();
         //Si hay algún corte negativo digo que no es válido.
         if (corte < 1)

            return false;
      }
      return true;
   }
   
   public int obtenerLongitud()
   {
      return longitud;
   }
   /**
    * Convierte un string en un Liston.
    * @param longitud String que representa la longitud del liston.
    * @return El listón generado.
    */
	public static Liston parseListon( String longitud ) 
   {      
      return new Liston(Integer.parseInt(longitud));
      
   }
}