package uba.algo3.tp1.ej2;
import static org.junit.Assert.assertEquals;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;
import org.junit.Test;

public class EntusiasmoTest
{

	ArrayList<String> amistades;
	Entusiasmo e = new Entusiasmo();
	HashMap<String,Investigador> investigadores = new HashMap<String,Investigador>();
	
	@Test
	public void testEntusiasmoObtener()
	{

		e = new Entusiasmo();
		representData("esteban irene\nirene alejandro;alejandro paula;irene paula;paula emilio;esteban emilio;emilio marina;marina esteban;alejandro marina");
		int ent = e.obtenerEntusiasmo("esteban", "irene", amistades);
		assertEquals(3,ent);

		e = new Entusiasmo();
		representData("esteban irene\nirene alejandro;alejandro paula;irene paula;paula emilio;esteban emilio;emilio marina;marina esteban");
		ent = e.obtenerEntusiasmo("esteban", "irene", amistades);
		assertEquals(3,ent);
		
		e = new Entusiasmo();
		representData("esteban irene\nirene alejandro;irene paula;irene emilio;irene esteban");
		ent = e.obtenerEntusiasmo("esteban", "irene", amistades);
		assertEquals(1,ent);

		e = new Entusiasmo();
		representData("esteban irene\nirene alejandro;alejandro paula;alejandro esteban");
		ent = e.obtenerEntusiasmo("esteban", "irene", amistades);
		assertEquals(2,ent);	

		e = new Entusiasmo();
		representData("esteban irene\nirene alejandro;alejandro paula;marina esteban");
		ent = e.obtenerEntusiasmo("esteban", "irene",amistades);
		assertEquals(0,ent);
		
		e = new Entusiasmo();
      representData("esteban irene\nmarina alejandro;alejandro paula;marina esteban");
      ent = e.obtenerEntusiasmo("esteban", "irene",amistades);
      assertEquals(0,ent);
		
		e = new Entusiasmo();
      ent = e.obtenerEntusiasmo( "esteban", "irene", amistades);
      assertEquals(0,ent);
		
      e = new Entusiasmo();
      representData("esteban irene\nesteban alejandro;alejandro paula;alejandro irene;paula emilio;emilio alejandro");
      ent = e.obtenerEntusiasmo("esteban", "irene",amistades);
      assertEquals(2,ent);
      
	}
	
	
	@Test
	public void testToAmistades(){
		representData("esteban irene\nirene alejandro;alejandro paula;irene paula;paula emilio;esteban emilio;emilio marina;marina esteban;alejandro marina");
	    ArrayList<Amistad> ams = e.toAmistades(amistades);
	    assertEquals(ams.toString(),
	            "[(irene,alejandro), (alejandro,paula), (irene,paula), (paula,emilio), " +
	            "(esteban,emilio), (emilio,marina), (marina,esteban), (alejandro,marina)]"); 
	    representData("marina esteban\nemilio marina;alejandro emilio;alejandro marina");
	    ArrayList<Amistad> ams2 = e.toAmistades(amistades);
	    assertEquals(ams2.toString(),
	            "[(emilio,marina), (alejandro,emilio), (alejandro,marina)]"); 
	}
	
	
	@Test
	public void testGenerarAmistades(){
		representData("esteban irene\nirene alejandro;alejandro paula;irene paula;paula emilio;esteban emilio;emilio marina;marina esteban;alejandro marina");
		e.generarAmistades(e.toAmistades(amistades));
		Investigador es1 = e.GetInvestigadores().get("esteban");
		assertEquals(ArrayList2String(es1.GetAmigos()),"[emilio, marina]");
		Investigador m1 = e.GetInvestigadores().get("marina");
		assertEquals(ArrayList2String(m1.GetAmigos()),"[emilio, esteban, alejandro]");
		Investigador em1 = e.GetInvestigadores().get("emilio");
		assertEquals(ArrayList2String(em1.GetAmigos()),"[paula, esteban, marina]");
		
		e = new Entusiasmo();
		
		representData("esteban irene\nirene alejandro;irene paula;irene emilio;irene esteban");
		e.generarAmistades(e.toAmistades(amistades));
		Investigador i2 = e.GetInvestigadores().get("irene");
		assertEquals(ArrayList2String(i2.GetAmigos()),"[alejandro, paula, emilio, esteban]");
		Investigador a2 = e.GetInvestigadores().get("alejandro");
		assertEquals(ArrayList2String(a2.GetAmigos()),"[irene]");
		Investigador p2 = e.GetInvestigadores().get("paula");
		assertEquals(ArrayList2String(p2.GetAmigos()),"[irene]");
		Investigador em2 = e.GetInvestigadores().get("emilio");
		assertEquals(ArrayList2String(em2.GetAmigos()),"[irene]");
		Investigador es2 = e.GetInvestigadores().get("esteban");
		assertEquals(ArrayList2String(es2.GetAmigos()),"[irene]");

		e = new Entusiasmo();
		
		representData("esteban irene\nirene alejandro;alejandro paula;marina paula");
		e.generarAmistades(e.toAmistades(amistades));
		Investigador i3 = e.GetInvestigadores().get("irene");
		assertEquals(ArrayList2String(i3.GetAmigos()),"[alejandro]");
		Investigador p3 = e.GetInvestigadores().get("paula");
		assertEquals(ArrayList2String(p3.GetAmigos()),"[alejandro, marina]");
		assertEquals(e.GetInvestigadores().containsKey("esteban"),false);
	}
	 
	
	public String ArrayList2String(ArrayList<String> a){
		String res = "[";
		for(int i=0; i<a.size(); i++){
			res += a.get(i) ;
			if(i<a.size()-1){
				res += ", ";
			}
		}
		res += "]";
		return res;
	}
	  
	  
	@Test
    public void testDameAmigo(){
		Investigador inv = e.dameAmigo(investigadores, "irene");
        assertEquals("irene",inv.GetNombre());
        
        Investigador inv1 = new Investigador("paula");
        investigadores.put( "paula", inv1);
        
        inv1 = e.dameAmigo( investigadores, "paula" ); 
        assertEquals("paula",inv1.GetNombre());
     }
	  
	
	private void representData(String string)
	{
		amistades = new ArrayList<String>();
		StringTokenizer st1 = new StringTokenizer(string, "\n");
		String p_y_q = st1.nextToken();
		String amistades_str = st1.nextToken();
		StringTokenizer st = new StringTokenizer(amistades_str, ";");

		while(st.hasMoreTokens())
		{
			StringTokenizer s = new StringTokenizer(st.nextToken()," ");
			amistades.add(s.nextToken());
			amistades.add(s.nextToken());
		}
	}
	
	
}

	
	