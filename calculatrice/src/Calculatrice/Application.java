package Calculatrice;

public class Application {
	public static void main(String[] args) {
		Addition d = new Addition();

		d.a = 5;
                d.b =3;
                
		System.out.println("R=" + d.calculer());
                InterfaceGraphic_Calculated IG = new InterfaceGraphic_Calculated();

	}
}
