package uba.algo3.tp1.ej1;

import static org.junit.Assert.assertEquals;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;
import org.junit.Test;

public class MejorNegocioTest
{

	static MejorNegocio m = new MejorNegocio();

	@Test
	public void testMejorNegocioString()
	{
		assertEquals(0, runOn("9 8 7 6 5 4 3 2"));
		assertEquals(3, runOn("9 8 7 6 5 4 3 2 1 2 3 4"));
		assertEquals(3, runOn("9 8 7 6 5 4 3 2 1 2 3 4 2"));
		assertEquals(7, runOn("1 2 3 4 5 6 7 8"));
		assertEquals(3, runOn("1 2 3 4 1 2 3 4 2"));
		assertEquals(4, runOn("1 2 3 4 1 2 3 5 2"));
	}
	
	@Test
	public void testMejorNegocioCantOp()
	{
		ArrayList<Integer> preciosA = new ArrayList<Integer>();
		ArrayList<Integer> preciosD = new ArrayList<Integer>();
		ArrayList<Integer> preciosR = new ArrayList<Integer>();
		FileWriter fstreamA,fstreamD,fstreamR;
		BufferedWriter outA = null, outD = null, outR = null;
		int tempA, tempD, tempR, r;
		try
		{
			fstreamA = new FileWriter("ascendente_out.txt");
			fstreamD = new FileWriter("descendente_out.txt");
			fstreamR = new FileWriter("random_out.txt");
			outA = new BufferedWriter(fstreamA);
			outD = new BufferedWriter(fstreamD);
			outR = new BufferedWriter(fstreamR);
		} catch (IOException e1)
		{
			e1.printStackTrace();
		}

		for(int j = 1; j<= 50;j+=2)
		{
			preciosA.add(j);
			preciosD.add(51-j);
			r = new Double(Math.random() * 100).intValue();
			preciosR.add(r);
			m.obtenerMayorGanancia(preciosA);
			tempA = m.getCantOperaciones();
			m.obtenerMayorGanancia(preciosD);
			tempD = m.getCantOperaciones();
			m.obtenerMayorGanancia(preciosR);
			tempR = m.getCantOperaciones();
			try
			{
				outA.write(j + " " + tempA + '\n');
				outD.write(j + " " + tempD + '\n');
				outR.write(j + " " + tempR + '\n');
				
			} catch (IOException e)
			{
				e.printStackTrace();
			}
			
		}

		try
		{
			outA.close();
			outD.close();
			outR.close();
		} catch (IOException e)
		{
			e.printStackTrace();
		}
		
	}	

	private int runOn(String string)
	{
		StringTokenizer st = new StringTokenizer(string, " ");
		int i = 0;
		ArrayList<Integer> precios = new ArrayList<Integer>();
		while(st.hasMoreTokens())
		{
			precios.add( Integer.parseInt(st.nextToken().trim()) );
		}
		return m.obtenerMayorGanancia(precios);
	}

}
