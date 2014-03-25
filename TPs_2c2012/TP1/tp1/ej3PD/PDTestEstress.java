package uba.algo3.tp1.ej3PD;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.Vector;
import org.junit.Test;
import uba.algo3.tp1.ej3.Procesamiento;

public class PDTestEstress
{
	static PD pD = new PD();
	static Procesamiento p = new Procesamiento();
	static Vector<Integer> cortes_a_realizar;

	@Test
	public void RunTest()
	{
		int r, tiempo_promedio;
		int longitud = 10001;
		long l;
		Vector<Integer> v;
		cortes_a_realizar = new Vector<Integer>();
		FileWriter fstream;
		BufferedWriter out = null;
		
		try
		{
			fstream = new FileWriter("outPD.txt");
			out = new BufferedWriter(fstream);
		} catch (IOException e)
		{
			e.printStackTrace();
		}
		
		for (int i = 1; i <= 20; i++)
		{
			for(int j = 1; j <= 20; j++)
			{
				r = new Double(Math.random() * 1000).intValue();
				cortes_a_realizar.add(r);
			}
			
			Collections.sort(cortes_a_realizar);
			tiempo_promedio = 0;
			for(int k = 1; k<=10;k++)
			{
				v = (Vector<Integer>) cortes_a_realizar.clone();
				l = System.currentTimeMillis();
				pD.hallarMinCortes(v, longitud);
				tiempo_promedio += (int) (System.currentTimeMillis() - l);
			}
			
			try
			{
				out.write(i*20 + " " + tiempo_promedio/10 + "\n");
			} catch (IOException e)
			{
				e.printStackTrace();
			}
		}
		
		try
		{
			out.close();
		} catch (IOException e)
		{
			e.printStackTrace();
		}
	}
}
