package uba.algo3.tp1.ej3PD;

import static org.junit.Assert.assertEquals;

import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Vector;
import org.junit.Test;
import uba.algo3.tp1.ej3.Liston;
import uba.algo3.tp1.ej3.Procesamiento;

public class PDTest
{

	static PD pD = new PD();
	static Procesamiento p = new Procesamiento();
	static Vector<Integer> cortes_a_realizar;
	static int l;
	
	@Test
	public void testPDContraBacktrack()
	{
		int r;
		Vector<Integer> resPD, res;
		int longitud = 1001;
		Liston liston;
		liston = new Liston(longitud);
		cortes_a_realizar = new Vector<Integer>();
		
		for (int i = 1; i < 15; i ++)
		{
			r = new Double(Math.random() * 1000).intValue();
			cortes_a_realizar.add(r);

			Collections.sort(cortes_a_realizar);

			resPD = pD.hallarMinCortes((Vector<Integer>) cortes_a_realizar.clone(), longitud);

			res = p.hallarCortesMin((Vector<Integer>) cortes_a_realizar.clone(), liston);
			
			//chequear que los costos obtenidos son iguales con ambos algoritmos
			assertEquals(p.calcularCosto(resPD,longitud), p.calcularCosto(res,longitud));
			
		}
	}
	
	@Test
	public void testPDHallarCortesMin()
	{
		representData("48\n4 7 20");
		assertEquals(75, pD.hallarMinCortes(cortes_a_realizar, l));
		representData("10\n2 4 7");
		assertEquals(20, pD.hallarMinCortes(cortes_a_realizar, l));
		representData("100\n25 50 75");
		assertEquals(200, pD.hallarMinCortes(cortes_a_realizar, l));
		representData("10\n4 5 7 8");
		assertEquals(22, pD.hallarMinCortes(cortes_a_realizar, l));
	}

	private void representData(String string)
	{
		StringTokenizer st1 = new StringTokenizer(string, "\n");
		int longitud = Integer.parseInt(st1.nextToken());
		String cortes_str = st1.nextToken();
		StringTokenizer st = new StringTokenizer(cortes_str, " ");

		cortes_a_realizar = new Vector<Integer>();
		while(st.hasMoreTokens())
		{
			cortes_a_realizar.add( Integer.parseInt(st.nextToken().trim()) );
		}
		
		l = longitud;
		
	}
	
}
