package uba.algo3.tp1.ej3;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Test;

public class ListonTest {
   
   @Test 
   public void equalTest() {
      assertTrue( new Liston(10).equals( new Liston(10)) );
      assertFalse( new Liston(10).equals( new Liston(20)) );
      assertFalse( new Liston(10).equals( "Liston(10)" ) );
      
      Liston uno = new Liston(10);
      Liston dos = new Liston(10);
      uno.cortarListon( 5 );
      uno.cortarListon( 7 );
      dos.cortarListon( 7 );
      dos.cortarListon( 5 );
      assertTrue( uno.equals( dos ) );
      dos.cortarListon( 8 );
      assertFalse( uno.equals( dos ) );
      dos.deshacerCorte( 8 );
      assertTrue( uno.equals( dos ) );
      uno.deshacerCorte( 5 );
      assertFalse( uno.equals( dos ) );
      assertFalse( new Liston(10).equals( new Liston(20)) );
   }  

}
