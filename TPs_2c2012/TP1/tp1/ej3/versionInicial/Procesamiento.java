package uba.algo3.tp1.ej3.versionInicial;

import java.util.Vector;
import uba.algo3.tp1.ej3.Cortes;
import uba.algo3.tp1.ej3.Liston;

public class Procesamiento
{
   
	public int costoMin = Integer.MAX_VALUE;
	
	public Cortes hallarCortesMin(Vector<Integer> cortes, Liston l)
	{	
		int minCosto = Integer.MAX_VALUE;//Variable utilizada para ir guardandonos el costo minimo obtenido hasta el momento
		Cortes corteTemp; //Variable utilizada para ir guardando cada secuencia de cortes que vamos evaluando 
		Cortes min = new Cortes();//Variable donde vamos guardando la secuencia de cortes que nos da el costo minimo
		
		for(int i = 0; i < cortes.size(); i++)
		{
			corteTemp = new Cortes();
			int temp = cortes.get(i);//Agarramos el siguiente en el vector de cortes
			int costoActual = l.cortarListon(temp);//Cortamos el liston y nos guardamos el costo
			cortes.remove(i);//Antes de llamar recursivamente, borramos el corte realizado de la lista de cortes
			Cortes subcortes = hallarCortesMin(cortes, l);//LLamamos recursivamente, pero sin el corte realizado anteriormente

			Vector cortesSec = subcortes.getCortes();//Obtenemos el vector con la secuencia de cortes obtenidos en la llamada recursiva

			int costoTotal = costoActual + subcortes.getCosto();

			if(costoTotal < minCosto)
			{
				minCosto = costoTotal;
				cortesSec.add(0, temp);
				corteTemp.setCortes(cortesSec);
				corteTemp.setCosto(costoTotal);
				min = corteTemp;
			}

			//Volvemos a dejar como estaba el Liston y los cortes a realizar sobre el Liston antes de realizar la siguiente iteracion empezando con el corte siguiente
			l.deshacerCorte(temp);
			cortes.add(i, temp);			
		}

		return min;
	}
	
	public int calcularCosto(Vector<Integer> secuencia_cortes, Liston l)
	{
		int costo = 0;
		for(int i = 0; i < secuencia_cortes.size();i++)
		{
			int siguienteCorte = secuencia_cortes.get(i);
			costo = costo + l.cortarListon(siguienteCorte);
		}
		
		return costo;
	}
	
}