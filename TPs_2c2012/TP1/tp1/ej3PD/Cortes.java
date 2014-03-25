package uba.algo3.tp1.ej3PD;

import java.util.Vector;

public class Cortes
{

	private int costo;
	private Vector<Integer> cortes;
	
	public Cortes()
	{
	   costo = 0;
	   cortes = new Vector<Integer>(); 
	}
	
	public int getCosto()
	{
		return costo;
	}
	
	public void setCosto(int costo)
	{
		this.costo = costo;
	}
	
	public Vector<Integer> getCortes()
	{
		return cortes;
	}
	
	public void setCortes(Vector<Integer> cortes)
	{
		this.cortes = cortes;
	}
	
	
}
