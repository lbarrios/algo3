package uba.algo3.tp1.ej3.versionInicial;

import java.util.LinkedList;
import java.util.ListIterator;

public class Liston
{
 //La longitud del liston va a estar en la ultima posicion de la lista.
	LinkedList<Integer> listoncitos;
	final int longitud;
	
	@SuppressWarnings("boxing")
   public Liston (int longitud)
	{
		listoncitos = new LinkedList<Integer>();
		this.longitud = longitud;
		listoncitos.addFirst(longitud);
	}

	@SuppressWarnings("boxing")
   public int cortarListon(int posDeCorte)
	{//Requiere que la posicion de Corte sea menor a la longitud del liston.
	   if (posDeCorte < 1 || posDeCorte >= longitud)
	      return -1;
	   
		ListIterator<Integer> it = listoncitos.listIterator();

		int i = 0;
		int costo;
		int anterior = 0;
		int actual = 0;

		while (it.hasNext() && posDeCorte > it.next())
		{
			i++;
		}

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

		listoncitos.add(i, posDeCorte);

		return costo;
	}

	@SuppressWarnings("boxing")
   public int deshacerCorte(int posDeCorte)
	{//Requiere que la posicion de corte sea un corte del liston
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
	
	public boolean equals( Object other ) {
      return getClass().isInstance( other ) && equals( other ); 
   }
   public boolean equals( Liston other ) {
      
      return listoncitos.equals(other.listoncitos); 
   }
/*   
   @SuppressWarnings("boxing")
   public boolean esValido(Liston l) 
   {
      for (ListIterator<Integer> it = listoncitos.listIterator(); it.hasNext();)
      {
         int corte = it.next();
         if (corte < 1)
            return false;
      }
      return true;
   }
  */ 
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