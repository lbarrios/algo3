package uba.algo3.tp1.ej3PD;

import java.util.Vector;

public class PD
{

	Cortes[][] m;//m es la matriz donde voy guardando los costos para cada secuencia de cortes consecutivos
	Vector<Integer> cortes_a_realizar;
	
	public Vector<Integer> hallarMinCortes(Vector<Integer> cortes_a_realizar_p, int longitud)
	{
		cortes_a_realizar = cortes_a_realizar_p;
		cortes_a_realizar.add(0, 0);
		cortes_a_realizar.add(cortes_a_realizar.size(), longitud);

		int n = cortes_a_realizar.size();
		m = new Cortes[n][n];
		int j = 1;
		Cortes min = new Cortes();
		Vector<Integer> cortes_realizados;
		
		for(int i = 0; j < n; i++)
		{
			m[i][j] = new Cortes();
			j++;
		}

		for(int i = 2; i < n; i++)//i es la cantidad de cortes consecutivos que voy a estar tomando, empiezo con secuencias de cortes de tamaño 2, y asi voy subiendo..
		{
			for(j = 0; (j+i) < n; j++)
			{
				min = minimo(j,j+i);
				min.setCosto(cortes_a_realizar.get(j+i) - cortes_a_realizar.get(j) + min.getCosto());
				m[j][j+i] =  min;
			}
		}
		
		return m[0][n-1].getCortes();
	}

	private Cortes minimo(int i, int j)
	{
		int min = Integer.MAX_VALUE;
		int temp, ktemp = -1;
		Cortes c = new Cortes();
		Vector<Integer> cortes_realizados;
		for(int k = i+1; k < j ; k++)
		{
			temp = m[i][k].getCosto() + m[k][j].getCosto();
			if(temp < min)
			{
				min = temp;
				ktemp = k;
			}
		}
		
		if(ktemp != -1)
		{
			c = new Cortes();
			c.setCosto(min);
			cortes_realizados = new Vector<Integer>();
			cortes_realizados.add(cortes_a_realizar.get(ktemp));
			cortes_realizados.addAll(m[i][ktemp].getCortes());
			cortes_realizados.addAll(m[ktemp][j].getCortes());
			c.setCortes(cortes_realizados);
		}
		
		return c;
	}
	
}
