package uba.algo3.tp1.ej3;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Vector;
import org.junit.Test;

/**
 * Clase que toma los tiempos del procesamiento.
 * 
 * @author gfsh
 * 
 */
public class ProcesamientoTestEstress
{

	static private Vector<Integer> cortes_a_realizar;
	static Procesamiento p = new Procesamiento();

	@Test
	public void just3RunTest()
	{

		p = new Procesamiento();
		int r;
		long tiempo = 0, suma = 0;
		cortes_a_realizar = new Vector<Integer>();
		FileWriter fstream;
		BufferedWriter out = null;
		
		try
		{
			fstream = new FileWriter("outEj3.txt");
			out = new BufferedWriter(fstream);
		} catch (IOException e)
		{
			e.printStackTrace();
		}

		for(int j = 1; j <= 13; j++)
		{

			r = new Double(Math.random() * 100).intValue();
			cortes_a_realizar.add(r);
			
			for(int i = 1; i <= 5; i++)
			{
			
				long antesDeCorrer = System.currentTimeMillis();

				p.hallarCortesMin(cortes_a_realizar, new Liston(101));
	
				tiempo = System.currentTimeMillis() - antesDeCorrer;
				suma = suma + tiempo;
			}
			
			try
			{
				out.write(j + " " + suma/5 + '\n');
			} catch (IOException e)
			{
				e.printStackTrace();
			}
		
		}

		System.out.println(suma / 10);
		
		try
		{
			out.close();
		} catch (IOException e)
		{
			e.printStackTrace();
		}

	}

}
