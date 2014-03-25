package uba.algo3.tp1.ej1;

import java.util.ArrayList;


public class MejorNegocio
{
	private int precio_diaDeCompra;
	private int cantOperaciones = 0;
	
	public int obtenerMayorGanancia(ArrayList<Integer> precios)
	{
		int ganancia = 0;
		precio_diaDeCompra = Integer.MAX_VALUE;
		cantOperaciones = 2;
		for(int i = 0; i < precios.size();i++)
		{
			int temp = precios.get(i);
			if(temp < precio_diaDeCompra)
			{
				precio_diaDeCompra = temp;
				cantOperaciones++;
			}
			else
			{
				if(ganancia < temp - precio_diaDeCompra)
				{
					ganancia = temp - precio_diaDeCompra;
					cantOperaciones+=2;//resta + asignacion
				}
				cantOperaciones+=2; //resta + comparacion
			}
			cantOperaciones+=3;//get + asignacion + comparacion if
		}
		
		return ganancia;
	}

	public int getCantOperaciones()
	{
		return cantOperaciones;
	}

	private void setCantOperaciones(int cantOperaciones)
	{
		this.cantOperaciones = cantOperaciones;
	}
}
