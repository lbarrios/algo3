package uba.algo3.tp1;


import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;
import uba.algo3.tp1.ej1.MejorNegocioCatedraTest;
import uba.algo3.tp1.ej1.MejorNegocioTest;
import uba.algo3.tp1.ej2.EntusiasmoCatedraTest;
import uba.algo3.tp1.ej2.EntusiasmoStressTest;
import uba.algo3.tp1.ej2.EntusiasmoTest;
import uba.algo3.tp1.ej3.ListonTest;
import uba.algo3.tp1.ej3.ProcesamientoCatedraTest;
import uba.algo3.tp1.ej3.ProcesamientoTest;
import uba.algo3.tp1.ej3.ProcesamientoTestEstress;

@SuiteClasses(value={
                     MejorNegocioTest.class,
                     MejorNegocioCatedraTest.class,
                     EntusiasmoTest.class,
                     EntusiasmoCatedraTest.class,
                     EntusiasmoStressTest.class,
                     ProcesamientoTest.class,
                     ProcesamientoCatedraTest.class,
                     ProcesamientoTestEstress.class,
                     ListonTest.class
})
@RunWith(Suite.class)
public class SuiteTp1 {

}
