package Calculatrice;

public class Division extends OperationBinaire {
	public double calculer() {
		try {
			if (b == 0) {
				throw new ArithmeticException("Division par zéro n'est pas autorisée.");
			}
			return a / b;
		} catch (ArithmeticException e) {
			System.err.println("Erreur : " + e.getMessage());
			return 0; // or another default value
		}
	}
}
